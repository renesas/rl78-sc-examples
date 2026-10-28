/*
* Copyright (c) 2024 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * File Name    : sau_uart_ep.c
 * Description  : Contains data structures and functions
 ***********************************************************************************************************************/
/***********************************************************************************************************************
* Copyright (c) 2024 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
***********************************************************************************************************************/

#include "common_utils.h"
#include "sau_uart_ep.h"

#include "r_cg_macrodriver.h"
#include "SAU_UART1.h"

/* Private Variables */
static uint8_t g_rx_buffer [BUFFER_LEN] = {RESET_VALUE};
static uint8_t g_tx_buffer [BUFFER_LEN] = {RESET_VALUE};
static volatile uint16_t g_rx_len = RESET_VALUE;
static volatile uart_event_t g_sau_uart_event = (uart_event_t)RESET_VALUE;
static volatile bool g_rx_flag = false;

/* [ADD] RX error flag/type (propagate RX error to handle_error via sau_uart_operation) */
static volatile bool    g_sau_uart_err_flag = false;
static volatile uint8_t g_sau_uart_err_type = 0U;

/* UART1 (Pmod) RX byte buffer (receive 1 byte each time) */
static volatile uint8_t g_uart1_rx_byte = 0U;

/* Private function declarations */
static fsp_err_t sau_uart_init(void);
static fsp_err_t sau_uart_send(uint8_t * p_data);
static fsp_err_t sau_uart_operation(void);
static void sau_uart_deinit(void);
static void handle_error (fsp_err_t err,  const char * err_str);

/*****************************************************************************************************************
 *  @brief      Start UART1 receive (1 byte).
 *  @param[in]  None
 *  @retval     MD_STATUS
 ****************************************************************************************************************/
static MD_STATUS uart1_start_rx_1byte(void)
{
    return R_SAU_UART1_Receive((uint8_t *) &g_uart1_rx_byte, 1U);
}

/*******************************************************************************************************************//**
 *  @brief       This function is used to initialize the related module and start the SAU UART example operation.
 *  @param[in]   None
 *  @retval      None
 **********************************************************************************************************************/

void sau_uart_ep_entry (void)
{
    fsp_err_t err = FSP_SUCCESS;

    /* Initialize UART0 (Type-C) terminal */
    err = (fsp_err_t) TERM_INIT();
    if (FSP_SUCCESS != err)
    {
        ERROR_TRAP;
    }

    /* Print the EP banner/info/message on Terminal App 0 */
    APP_PRINT(BANNER_INFO, EP_VERSION);
    APP_PRINT0(EP_INFO);
    APP_PRINT0(EP_MESSAGE);

    /* Initializes the SAU UART module (UART1) */
    err = sau_uart_init();
    handle_error (err, "sau_uart_init failed\r\n");

    while (true)
    {
        /* Perform the SAU UART operation */
        err = sau_uart_operation();
        handle_error (err, "sau_uart_operation failed\r\n");
    }
}


/*******************************************************************************************************************//**
 *  @brief       This function initializes the SAU UART module
 *  @param[in]   None
 *  @retval      FSP_SUCCESS    Upon successful operation
 *  @retval      Any Other Error code apart from FSP_SUCCESS
 **********************************************************************************************************************/
static fsp_err_t sau_uart_init(void)
{
    MD_STATUS md_status = MD_OK;

    R_SAU_UART1_Start();

    md_status = uart1_start_rx_1byte();
    APP_ERR_RET0(MD_OK != md_status, (fsp_err_t) md_status, "R_SAU_UART1_Receive API failed\r\n");

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 *  @brief       This function writes data to the terminal application on the host PC
 *  @param[in]   p_data         pointer to data buffer
 *  @retval      FSP_SUCCESS    Upon successful operation
 *  @retval      Any Other Error code apart from FSP_SUCCESS
 **********************************************************************************************************************/
static fsp_err_t sau_uart_send(uint8_t * p_data)
{
    MD_STATUS md_status = MD_OK;
    uint32_t timeout = RESET_VALUE;
    uint16_t length  = (uint16_t) strlen((char *) p_data);

    /* Set a timeout value according to the length of the input data */
    timeout = (uint32_t) length * TIME_OUT_FOR_ONE_BYTE;

    /* Reset SAU UART callback event */
    g_sau_uart_event = (uart_event_t)RESET_VALUE;

    /* Perform SAU UART write operation */
    md_status = R_SAU_UART1_Send((uint8_t *) p_data, length);
    APP_ERR_RET0(MD_OK != md_status, (fsp_err_t) md_status, "R_SAU_UART1_Send API failed\r\n");

    /* Wait for UART_EVENT_TX_COMPLETE event */
    while (UART_EVENT_TX_COMPLETE != g_sau_uart_event)
    {
        /* Check time elapsed to avoid infinite loop */
        if(RESET_VALUE == timeout)
        {
            APP_ERR_RET0(true, FSP_ERR_TIMEOUT, "No SAU UART callback events received\r\n");
        }

        /* Decrease timeout value then software delay */
        timeout --;
        R_BSP_SoftwareDelay(TIME_OUT_VALUE, TIME_OUT_UNIT);
    }

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 *  @brief       This is the SAU UART operation function
 *  @param[in]   None
 *  @retval      FSP_SUCCESS    Upon successful operation
 *  @retval      Any Other Error code apart from FSP_SUCCESS
 **********************************************************************************************************************/
static fsp_err_t sau_uart_operation(void)
{
    /* [ADD] RX error check (propagate to handle_error) */
    if (true == g_sau_uart_err_flag)
    {
        g_sau_uart_err_flag = false;
        return FSP_ERR_ABORTED;
    }

    fsp_err_t err = FSP_SUCCESS;

    if (true == g_rx_flag)
    {
        /* Clear the SAU UART receive flag to detect new frames */
        g_rx_flag = false;

        /* Copy the received data frame to transmit buffer */
        memcpy (g_tx_buffer, g_rx_buffer, g_rx_len);

        /* Clean the receive buffer */
        memset (g_rx_buffer, NULL_CHAR, sizeof(g_rx_buffer));

        /* Print the received data to Terminal App 0 */
        APP_PRINT("Received a string: %s\r\n", (char *)g_tx_buffer);

        /* Add a newline character for the transmit buffer */
        strcat((char*)g_tx_buffer, "\r\n");

        /* Send received data back to the host PC */
        err = sau_uart_send(g_tx_buffer);
        APP_ERR_RET0(FSP_SUCCESS != err, err, "sau_uart_send failed\r\n");

        /* Clean the SAU UART transmit buffer */
        memset (g_tx_buffer, NULL_CHAR, sizeof(g_tx_buffer));
    }

    return err;
}

/*******************************************************************************************************************//**
 *  @brief       This function de-initializes the SAU UART module.
 *  @param[in]   None
 *  @retval      None
 **********************************************************************************************************************/
static void sau_uart_deinit(void)
{
    R_SAU_UART1_Stop();
}

/*******************************************************************************************************************//**
 *  @brief       If an error occurred, this function handles the error, closes all opened modules, print and traps error
 *  @param[in]   err        error value
 *  @param[in]   err_str    error string
 *  @retval      None
 **********************************************************************************************************************/
static void handle_error (fsp_err_t err,  const char * err_str)
{
    if(FSP_SUCCESS != err)
    {
        /* Print the error */
        APP_PRINT0((char *) err_str);

        /* De-initializes the SAU UART module */
        sau_uart_deinit();

        /* Trap the error */
        APP_ERR_TRAP(err);
    }
}

/***********************************************************************************************************************
 * UART1 Callbacks (called from SAU_UART1_user.c)
 **********************************************************************************************************************/
void sau_uart1_tx_callback(void)
{
    g_sau_uart_event = UART_EVENT_TX_COMPLETE;
}

void sau_uart1_rx_callback(uint8_t data)
{
    static volatile uint16_t rx_count = RESET_VALUE;
    MD_STATUS md_status = MD_OK;

    /* Set event (same usage as RA version) */
    g_sau_uart_event = UART_EVENT_RX_CHAR;

    switch (data)
    {
        /* If Enter is pressed by user, set flag to process the data */
        case CR_ASCII:
            /* Set flag if at least one character has been received */
            if (RESET_VALUE != rx_count)
            {
                g_rx_len  = rx_count;
                g_rx_flag = true;
                rx_count  = RESET_VALUE;
            }
            break;

        /* Read all data provided by user until enter button is pressed */
        default:
            /* Check the number of characters received to ensure there is no buffer overflow */
            if (BUFFER_LEN > rx_count)
            {
                g_rx_buffer[rx_count++] = data;
            }
            break;
    }

    /* Start next 1 byte receive */
    md_status = uart1_start_rx_1byte();
    if (MD_OK != md_status)
    {
        APP_ERR_TRAP((fsp_err_t) md_status);
    }
}

void sau_uart1_err_callback(uint8_t err_type)
{
    /* [ADD] Save RX error info and notify main loop */
    g_sau_uart_err_type = err_type;
    g_sau_uart_err_flag = true;
}
