/*
* Copyright (c) 2021 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
* File Name        : UARTA0_user.c
* Component Version: 1.12.0
* Device(s)        : R7F103GLJxFB
* Description      : This file implements device driver for UARTA0.
***********************************************************************************************************************/
/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_userdefine.h"
#include "UARTA0.h"
/* Start user code for include. Do not edit comment generated here */
#include "uarta_ep.h"
/* Prototypes (implemented in sau_uart_ep.c) */
void uarta0_tx_callback(void);
void uarta0_rx_callback(uint8_t data);
void uarta0_err_callback(uint8_t err_type);
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Pragma directive
***********************************************************************************************************************/
#pragma interrupt r_UARTA0_interrupt_receive(vect=INTUR0)
/* Start user code for pragma. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
extern volatile uint16_t g_uarta0_rx_total_num;
extern volatile uint8_t * gp_uarta0_rx_address;
extern volatile uint16_t g_uarta0_rx_num;
/* Start user code for global. Do not edit comment generated here */
static uint8_t g_uarta_rx_byte = 0U;
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_UARTA0_Create_UserInit
* Description  : This function adds user code after initializing UARTA0.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_UARTA0_Create_UserInit(void)
{
    /* Start user code for user init. Do not edit comment generated here */
    (void) R_UARTA0_Receive(&g_uarta_rx_byte, 1U);
    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: R_UARTA0_PollingEnd_UserCode
* Description  : This function is a callback function when UARTA0 finishes polling transmission.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_UARTA0_PollingEnd_UserCode(void)
{
    /* Start user code for R_UARTA0_PollingEnd_UserCode. Do not edit comment generated here */
    uarta0_tx_callback();
    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_UARTA0_callback_receiveend
* Description  : This function is a callback function when UARTA0 finishes reception.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
static void r_UARTA0_callback_receiveend(void)
{
    /* Start user code for r_UARTA0_callback_receiveend. Do not edit comment generated here */
    uarta0_rx_callback(g_uarta_rx_byte);
    (void) R_UARTA0_Receive(&g_uarta_rx_byte, 1U);
    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_UARTA0_callback_error
* Description  : This function is a callback function when UARTA0 reception error occurs.
* Arguments    : err_type -
*                     error type value
* Return Value : None
***********************************************************************************************************************/
static void r_UARTA0_callback_error(uint8_t err_type)
{
    /* Start user code for r_UARTA0_callback_error. Do not edit comment generated here */
    uarta0_err_callback(err_type);
    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_UARTA0_interrupt_receive
* Description  : This function is UARTA0 receive interrupt service routine.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
static void __near r_UARTA0_interrupt_receive(void)
{
    uint16_t temp;
    uint8_t err_type;

    err_type = (ASISA0 & (_04_UARTA_PARITY_ERROR_DETECTED | _02_UARTA_FRAME_ERROR_DETECTED | 
               _01_UARTA_OVERRUN_ERROR_DETECTED));
    if (err_type != 0U)
    {
        *gp_uarta0_rx_address = RXBA0;
        ASCTA0 |= (_04_UARTA_PARITY_FLAG_CLEAR | _02_UARTA_FRAME_FLAG_CLEAR | _01_UARTA_OVERRUN_FLAG_CLEAR);
        r_UARTA0_callback_error(err_type);
    }
    else
    {
        temp = g_uarta0_rx_total_num;

        if (temp > g_uarta0_rx_num)
        {
            *gp_uarta0_rx_address = RXBA0;
            gp_uarta0_rx_address++;
            g_uarta0_rx_num++;
        }

        temp = g_uarta0_rx_total_num;

        if (temp == g_uarta0_rx_num)
        {
            r_UARTA0_callback_receiveend();
        }
    }
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
