/*
* Copyright (c) 2021 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
* File Name        : SAU_UART_user.c
* Component Version: 1.12.0
* Device(s)        : R7F100GSNxFB
* Description      : This file implements device driver for SAU_UART.
***********************************************************************************************************************/
/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_userdefine.h"
#include "SAU_UART.h"
/* Start user code for include. Do not edit comment generated here */
#include "SERIAL_TERM/serial.h"
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Pragma directive
***********************************************************************************************************************/
#pragma interrupt r_SAU_UART_interrupt_send(vect=INTST0)
#pragma interrupt r_SAU_UART_interrupt_receive(vect=INTSR0)
#pragma interrupt r_SAU_UART_interrupt_error(vect=INTSRE0)
/* Start user code for pragma. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
extern volatile uint8_t * gp_uart0_tx_address;    /* uart0 transmit buffer address */
extern volatile uint16_t g_uart0_tx_count;        /* uart0 transmit data number */
extern volatile uint8_t * gp_uart0_rx_address;    /* uart0 receive buffer address */
extern volatile uint16_t g_uart0_rx_count;        /* uart0 receive data number */
extern uint16_t g_uart0_rx_length;                /* uart0 receive data length */
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_SAU_UART_Create_UserInit
* Description  : This function adds user code after initializing UART0.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_SAU_UART_Create_UserInit(void)
{
    /* Start user code for user init. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_SAU_UART_callback_sendend
* Description  : This function is a callback function when UART0 finishes transmission.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
static void r_SAU_UART_callback_sendend(void)
{
    /* Start user code for r_SAU_UART_callback_sendend. Do not edit comment generated here */
    serial_callback(UART_EVENT_TX_COMPLETE);
    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_SAU_UART_callback_receiveend
* Description  : This function is a callback function when UART0 finishes reception.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
static void r_SAU_UART_callback_receiveend(void)
{
    /* Start user code for r_SAU_UART_callback_receiveend. Do not edit comment generated here */
    serial_callback(UART_EVENT_RX_COMPLETE);
    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_SAU_UART_callback_error
* Description  : This function is a callback function when UART0 reception error occurs.
* Arguments    : err_type -
*                    error type info
* Return Value : None
***********************************************************************************************************************/
static void r_SAU_UART_callback_error(uint8_t err_type)
{
    /* Start user code for r_SAU_UART_callback_error. Do not edit comment generated here */
    if (0x00U != (err_type & 0x01U)) {
        serial_callback(UART_EVENT_ERR_OVERFLOW);
    }
    if (0x00U != (err_type & 0x02U)) {
        serial_callback(UART_EVENT_ERR_PARITY);
    }
    if (0x00U != (err_type & 0x04U)) {
        serial_callback(UART_EVENT_ERR_FRAMING);
    }
    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_SAU_UART_callback_softwareoverrun
* Description  : This function is a callback when UART0 receives an overflow data.
* Arguments    : rx_data -
*                    receive data
* Return Value : None
***********************************************************************************************************************/
static void r_SAU_UART_callback_softwareoverrun(uint16_t rx_data)
{
    /* Start user code for r_SAU_UART_callback_softwareoverrun. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_SAU_UART_interrupt_send
* Description  : This function is UART0 send interrupt service routine.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
static void __near r_SAU_UART_interrupt_send(void)
{
    if (g_uart0_tx_count > 0U)
    {
        TXD0 = *gp_uart0_tx_address;
        gp_uart0_tx_address++;
        g_uart0_tx_count--;
    }
    else
    {
        r_SAU_UART_callback_sendend();
    }
}

/***********************************************************************************************************************
* Function Name: r_SAU_UART_interrupt_receive
* Description  : This function is UART0 receive interrupt service routine.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
static void __near r_SAU_UART_interrupt_receive(void)
{
    uint8_t rx_data;

    rx_data = RXD0;

    if (g_uart0_rx_length > g_uart0_rx_count)
    {
        *gp_uart0_rx_address = rx_data;
        gp_uart0_rx_address++;
        g_uart0_rx_count++;

        if (g_uart0_rx_length == g_uart0_rx_count)
        {
            r_SAU_UART_callback_receiveend();
        }
    }
    else
    {
        r_SAU_UART_callback_softwareoverrun(rx_data);
    }
}

/***********************************************************************************************************************
* Function Name: r_SAU_UART_interrupt_error
* Description  : This function is UART0 error interrupt service routine.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
static void __near r_SAU_UART_interrupt_error(void)
{
    uint8_t err_type;

    *gp_uart0_rx_address = RXD0;
    err_type = (uint8_t)(SSR01 & 0x0007U);
    SIR01L = err_type;
    r_SAU_UART_callback_error(err_type);
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
