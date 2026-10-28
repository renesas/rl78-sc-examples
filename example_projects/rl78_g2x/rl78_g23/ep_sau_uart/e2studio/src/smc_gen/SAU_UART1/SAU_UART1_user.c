/*
* Copyright (c) 2021 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
* File Name        : SAU_UART1_user.c
* Component Version: 1.12.0
* Device(s)        : R7F100GSNxFB
* Description      : This file implements device driver for SAU_UART1.
***********************************************************************************************************************/
/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_userdefine.h"
#include "SAU_UART1.h"
/* Start user code for include. Do not edit comment generated here */
#include "sau_uart_ep.h"
/* Prototypes (implemented in sau_uart_ep.c) */
void sau_uart1_tx_callback(void);
void sau_uart1_rx_callback(uint8_t data);
void sau_uart1_err_callback(uint8_t err_type);
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Pragma directive
***********************************************************************************************************************/
#pragma interrupt r_SAU_UART1_interrupt_send(vect=INTST1)
#pragma interrupt r_SAU_UART1_interrupt_receive(vect=INTSR1)
#pragma interrupt r_SAU_UART1_interrupt_error(vect=INTSRE1)
/* Start user code for pragma. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
extern volatile uint8_t * gp_uart1_tx_address;    /* uart1 transmit buffer address */
extern volatile uint16_t g_uart1_tx_count;        /* uart1 transmit data number */
extern volatile uint8_t * gp_uart1_rx_address;    /* uart1 receive buffer address */
extern volatile uint16_t g_uart1_rx_count;        /* uart1 receive data number */
extern uint16_t g_uart1_rx_length;                /* uart1 receive data length */
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_SAU_UART1_Create_UserInit
* Description  : This function adds user code after initializing UART1.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_SAU_UART1_Create_UserInit(void)
{
    /* Start user code for user init. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_SAU_UART1_callback_sendend
* Description  : This function is a callback function when UART1 finishes transmission.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
static void r_SAU_UART1_callback_sendend(void)
{
    /* Start user code for r_SAU_UART1_callback_sendend. Do not edit comment generated here */
    sau_uart1_tx_callback();
    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_SAU_UART1_callback_receiveend
* Description  : This function is a callback function when UART1 finishes reception.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
static void r_SAU_UART1_callback_receiveend(void)
{
    /* Start user code for r_SAU_UART1_callback_receiveend. Do not edit comment generated here */
    uint8_t data = *(gp_uart1_rx_address - 1U);
    sau_uart1_rx_callback(data);
    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_SAU_UART1_callback_error
* Description  : This function is a callback function when UART1 reception error occurs.
* Arguments    : err_type -
*                    error type info
* Return Value : None
***********************************************************************************************************************/
static void r_SAU_UART1_callback_error(uint8_t err_type)
{
    /* Start user code for r_SAU_UART1_callback_error. Do not edit comment generated here */
    sau_uart1_err_callback(err_type);
    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_SAU_UART1_callback_softwareoverrun
* Description  : This function is a callback when UART1 receives an overflow data.
* Arguments    : rx_data -
*                    receive data
* Return Value : None
***********************************************************************************************************************/
static void r_SAU_UART1_callback_softwareoverrun(uint16_t rx_data)
{
    /* Start user code for r_SAU_UART1_callback_softwareoverrun. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_SAU_UART1_interrupt_send
* Description  : This function is UART1 send interrupt service routine.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
static void __near r_SAU_UART1_interrupt_send(void)
{
    if (g_uart1_tx_count > 0U)
    {
        TXD1 = *gp_uart1_tx_address;
        gp_uart1_tx_address++;
        g_uart1_tx_count--;
    }
    else
    {
        if (0U == (SSR02 & _0040_SAU_UNDER_EXECUTE))
        {
            r_SAU_UART1_callback_sendend();
        }
        else
        {
            SMR02 &= (uint16_t)~_0001_SAU_BUFFER_EMPTY;
        }
    }
}

/***********************************************************************************************************************
* Function Name: r_SAU_UART1_interrupt_receive
* Description  : This function is UART1 receive interrupt service routine.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
static void __near r_SAU_UART1_interrupt_receive(void)
{
    uint8_t rx_data;

    rx_data = RXD1;

    if (g_uart1_rx_length > g_uart1_rx_count)
    {
        *gp_uart1_rx_address = rx_data;
        gp_uart1_rx_address++;
        g_uart1_rx_count++;

        if (g_uart1_rx_length == g_uart1_rx_count)
        {
            r_SAU_UART1_callback_receiveend();
        }
    }
    else
    {
        r_SAU_UART1_callback_softwareoverrun(rx_data);
    }
}

/***********************************************************************************************************************
* Function Name: r_SAU_UART1_interrupt_error
* Description  : This function is UART1 error interrupt service routine.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
static void __near r_SAU_UART1_interrupt_error(void)
{
    uint8_t err_type;

    *gp_uart1_rx_address = RXD1;
    err_type = (uint8_t)(SSR03 & 0x0007U);
    SIR03L = err_type;
    r_SAU_UART1_callback_error(err_type);
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
