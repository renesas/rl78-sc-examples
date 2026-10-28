/*
* Copyright (c) 2024 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * File Name    : uarta_ep.c
 * Description  : Contains data structures and functions
 **********************************************************************************************************************/
/***********************************************************************************************************************
* Copyright (c) 2024 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
***********************************************************************************************************************/

#include "common_utils.h"
#include "uarta_ep.h"

#include "r_cg_macrodriver.h"
#include "UARTA0.h"

/* Private Variables */
static uint8_t g_rx_buffer [BUFFER_LEN] = {RESET_VALUE};
static uint8_t g_tx_buffer [BUFFER_LEN] = {RESET_VALUE};
static volatile uint16_t g_rx_len = RESET_VALUE;
static volatile uart_event_t g_uarta_event = (uart_event_t)RESET_VALUE;
static volatile bool g_rx_flag = false;

/* [ADD] RX error flag/type (propagate RX error to handle_error via uarta_operation) */
static volatile bool    g_uarta_err_flag = false;
static volatile uint8_t g_uarta_err_type = 0U;

/* Private function declarations */
static fsp_err_t uarta_init(void);
static fsp_err_t uarta_send(uint8_t * p_data);
static fsp_err_t uarta_operation(void);
static void uarta_deinit(void);
static void handle_error (fsp_err_t err,  const char * err_str);

/*******************************************************************************************************************//**
 *  @brief       This function is used to initialize the related module and start the UARTA example operation.
 *  @param[in]   None
 *  @retval      None
 **********************************************************************************************************************/
void uarta_ep_entry (void)
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

    /* Initializes the UARTA module (UARTA0) */
    err = uarta_init();
    handle_error (err, "uarta_init failed\r\n");

    while (true)
    {
        /* Perform the UARTA operation */
        err = uarta_operation();
        handle_error (err, "uarta_operation failed\r\n");
    }
}

/*******************************************************************************************************************//**
 *  @brief       This function initializes the UARTA module.
 *  @param[in]   None
 *  @retval      FSP_SUCCESS    Upon successful operation
 *  @retval      Any Other Error code apart from FSP_SUCCESS
 **********************************************************************************************************************/
static fsp_err_t uarta_init(void)
{
    /* Create/Start UARTA0 driver */
    R_UARTA0_Create();
    R_UARTA0_Start();

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 *  @brief       This function sends data via UARTA0.
 *  @param[in]   p_data         pointer to data buffer
 *  @retval      FSP_SUCCESS    Upon successful operation
 *  @retval      Any Other Error code apart from FSP_SUCCESS
 **********************************************************************************************************************/
static fsp_err_t uarta_send(uint8_t * p_data)
{
    MD_STATUS md_status = MD_OK;
    uint32_t timeout = RESET_VALUE;
    uint16_t length  = (uint16_t) strlen((char *) p_data);

    /* Set a timeout value according to the length of the input data */
    timeout = (uint32_t) length * TIME_OUT_FOR_ONE_BYTE;

    /* Reset UARTA callback event */
    g_uarta_event = (uart_event_t)RESET_VALUE;

    /* Perform UARTA write operation */
    md_status = R_UARTA0_Send((uint8_t *) p_data, length);
    APP_ERR_RET0(MD_OK != md_status, (fsp_err_t) md_status, "R_UARTA0_Send API failed\r\n");

    /* Wait for UART_EVENT_TX_COMPLETE event */
    while (UART_EVENT_TX_COMPLETE != g_uarta_event)
    {
        /* Check time elapsed to avoid infinite loop */
        if(RESET_VALUE == timeout)
        {
            APP_ERR_RET0(true, FSP_ERR_TIMEOUT, "No UARTA callback events received\r\n");
        }

        /* Decrease timeout value then software delay */
        timeout --;
        R_BSP_SoftwareDelay(TIME_OUT_VALUE, TIME_OUT_UNIT);
    }

    return FSP_SUCCESS;
}

/*******************************************************************************************************************//**
 *  @brief       This is the UARTA operation function.
 *  @param[in]   None
 *  @retval      FSP_SUCCESS    Upon successful operation
 *  @retval      Any Other Error code apart from FSP_SUCCESS
 **********************************************************************************************************************/
static fsp_err_t uarta_operation(void)
{
    /* [ADD] RX error check (propagate to handle_error) */
    if (true == g_uarta_err_flag)
    {
        g_uarta_err_flag = false;
        return FSP_ERR_ABORTED;
    }

    fsp_err_t err = FSP_SUCCESS;

    if (true == g_rx_flag)
    {
        /* Clear the UARTA receive flag to detect new frames */
        g_rx_flag = false;

        /* Copy the received data frame to transmit buffer */
        memcpy (g_tx_buffer, g_rx_buffer, g_rx_len);

        /* Clean the receive buffer */
        memset (g_rx_buffer, NULL_CHAR, sizeof(g_rx_buffer));

        /* Print the received data to Terminal App 0 */
        APP_PRINT("Received a string: %s\r\n", (char *)g_tx_buffer);

        /* Add a newline character for the transmit buffer */
        strcat((char*)g_tx_buffer, "\r\n");

        /* Send received data back */
        err = uarta_send(g_tx_buffer);
        APP_ERR_RET0(FSP_SUCCESS != err, err, "uarta_send failed\r\n");

        /* Clean the UARTA transmit buffer */
        memset (g_tx_buffer, NULL_CHAR, sizeof(g_tx_buffer));
    }

    return err;
}

/*******************************************************************************************************************//**
 *  @brief       This function de-initializes the UARTA module.
 *  @param[in]   None
 *  @retval      None
 **********************************************************************************************************************/
static void uarta_deinit(void)
{
    R_UARTA0_Stop();
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

        /* De-initializes the UARTA module */
        uarta_deinit();

        /* Trap the error */
        APP_ERR_TRAP(err);
    }
}

/***********************************************************************************************************************
 * UARTA Callbacks (called from UARTA0_user.c)
 **********************************************************************************************************************/
void uarta0_tx_callback(void)
{
    g_uarta_event = UART_EVENT_TX_COMPLETE;
}

void uarta0_rx_callback(uint8_t data)
{
    static volatile uint16_t rx_count = RESET_VALUE;

    /* Set event */
    g_uarta_event = UART_EVENT_RX_CHAR;

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
}

void uarta0_err_callback(uint8_t err_type)
{
    /* [ADD] Save RX error info and notify main loop */
    g_uarta_err_type = err_type;
    g_uarta_err_flag = true;
}
