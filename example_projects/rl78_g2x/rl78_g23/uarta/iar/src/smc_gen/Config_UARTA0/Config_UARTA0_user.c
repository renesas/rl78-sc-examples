/***********************************************************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only intended for use with Renesas products.
* No other uses are authorized. This software is owned by Renesas Electronics Corporation and is protected under all
* applicable laws, including copyright laws. 
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING THIS SOFTWARE, WHETHER EXPRESS, IMPLIED
* OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
* NON-INFRINGEMENT.  ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY
* LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE FOR ANY DIRECT,
* INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR
* ITS AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software and to discontinue the availability 
* of this software. By using this software, you agree to the additional terms and conditions found by accessing the 
* following link:
* http://www.renesas.com/disclaimer
*
* Copyright (C) 2020 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
* File Name    : Config_UARTA0_user.c
* Version      : 1.0.0
* Device(s)    : R7F100GLGxFB
* Description  : This file implements device driver for Config_UARTA0.
* Creation Date: 2021-05-18
***********************************************************************************************************************/
/***********************************************************************************************************************
Pragma directive
***********************************************************************************************************************/
/* Start user code for pragma. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_userdefine.h"
#include "Config_UARTA0.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
extern volatile uint16_t g_uarta0_rx_total_num;
extern volatile uint8_t * gp_uarta0_rx_address;
extern volatile uint16_t g_uarta0_rx_num;
extern volatile uint8_t * gp_uarta0_tx_address;
extern volatile uint16_t g_uarta0_tx_count;
/* Start user code for global. Do not edit comment generated here */
extern uint8_t g_uarta0_rx_error;
extern MD_STATUS g_uarta0_tx_end;
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_Config_UARTA0_Create_UserInit
* Description  : This function adds user code after initializing UARTA0.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_UARTA0_Create_UserInit(void)
{
    /* Start user code for user init. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_Config_UARTA0_callback_sendend
* Description  : This function is a callback function when UARTA0 finishes transmission.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
static void r_Config_UARTA0_callback_sendend(void)
{
    /* Start user code for r_Config_UARTA0_callback_sendend. Do not edit comment generated here */
    g_uarta0_tx_end = 1U;
    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_Config_UARTA0_callback_receiveend
* Description  : This function is a callback function when UARTA0 finishes reception.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
static void r_Config_UARTA0_callback_receiveend(void)
{
    /* Start user code for r_Config_UARTA0_callback_receiveend. Do not edit comment generated here */
	g_uarta0_rx_error = 0U; /* Clear error flag */
    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_Config_UARTA0_callback_error
* Description  : This function is a callback function when UARTA0 reception error occurs.
* Arguments    : err_type -
*                     error type value
* Return Value : None
***********************************************************************************************************************/
static void r_Config_UARTA0_callback_error(uint8_t err_type)
{
    /* Start user code for r_Config_UARTA0_callback_error. Do not edit comment generated here */
	g_uarta0_rx_error = err_type;  /* Get error type */
    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_Config_UARTA0_interrupt_send
* Description  : This function is UARTA0 send interrupt service routine.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
#pragma vector = INTUT0_vect
__interrupt static void r_Config_UARTA0_interrupt_send(void)
{
    R_Config_UARTA0_Send_Polling();
}

/***********************************************************************************************************************
* Function Name: r_Config_UARTA0_interrupt_receive
* Description  : This function is UARTA0 receive interrupt service routine.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
#pragma vector = INTUR0_vect
__interrupt static void r_Config_UARTA0_interrupt_receive(void)
{
    uint16_t temp;
    
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
        r_Config_UARTA0_callback_receiveend();
    }
}

/***********************************************************************************************************************
* Function Name: r_Config_UARTA0_interrupt_error
* Description  : This function is UARTA0 error interrupt service routine.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
#pragma vector = INTURE0_vect
__interrupt static void r_Config_UARTA0_interrupt_error(void)
{
    uint8_t err_type;

    err_type = (ASISA0 & (_04_UARTA_PARITY_ERROR_DETECTED | _02_UARTA_FRAME_ERROR_DETECTED | 
               _01_UARTA_OVERRUN_ERROR_DETECTED));
    ASCTA0 |= (_04_UARTA_PARITY_FLAG_CLEAR | _02_UARTA_FRAME_FLAG_CLEAR | _01_UARTA_OVERRUN_FLAG_CLEAR);
    r_Config_UARTA0_callback_error(err_type);
}

/***********************************************************************************************************************
* Function Name: r_Config_UARTA0_send_1byte
* Description  : This function sends UARTA0 1 byte data.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
static void r_Config_UARTA0_send_1byte(void)
{
    if (0U < g_uarta0_tx_count)
    {
        while (0U != (ASISA0 & _20_UARTA_DATA_EXIST_IN_TXBA))
        {
            ;
        }

        TXBA0 = *gp_uarta0_tx_address;
        g_uarta0_tx_count--;
        gp_uarta0_tx_address++;
    }
}

/***********************************************************************************************************************
* Function Name: R_Config_UARTA0_Send_Polling
* Description  : This function sends UARTA0 data by polling.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_UARTA0_Send_Polling(void)
{
    if (0U == g_uarta0_tx_count)
    {
        if (0U == (ASISA0 & _10_UARTA_HAVE_NEXT_TRANSFER))
        {
            r_Config_UARTA0_callback_sendend();
        }
    }
    else
    {
        /* Enable UARTA{n0} interrupt operation */
        UTMK0 = 0U;
         
        if (1U < g_uarta0_tx_count)
        {
            if (0U == (ASISA0 & _10_UARTA_HAVE_NEXT_TRANSFER))
            {
                r_Config_UARTA0_send_1byte();
                r_Config_UARTA0_send_1byte();
            }
        }
        else
        {
            r_Config_UARTA0_send_1byte();

            while (0U != (ASISA0 & _20_UARTA_DATA_EXIST_IN_TXBA))
            {
                ;
            }
        }
    }
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

