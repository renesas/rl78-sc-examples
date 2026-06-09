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
* Copyright (C) 2021, 2024 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
* File Name        : Config_TAU0_0_user.c
* Component Version: 1.4.3
* Device(s)        : R7F102GGExFB
* Description      : This file implements device driver for Config_TAU0_0.
***********************************************************************************************************************/
/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_userdefine.h"
#include "Config_TAU0_0.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Pragma directive
***********************************************************************************************************************/
#pragma interrupt r_Config_TAU0_0_interrupt(vect=INTTM00)
/* Start user code for pragma. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* For TAU0_ch0 pulse measurement */
volatile uint32_t g_tau0_ch0_width = 0UL;
/* Start user code for global. Do not edit comment generated here */
volatile uint8_t g_edge_flag = 0xFFU;           /* Edge flag */ 
uint8_t g_port_data[2] = {0U, 0U};              /* Store P00 level */
uint32_t g_width_low[4] = {0U, 0U, 0U, 0U};     /* Store low level width */
uint32_t g_width_high[4] = {0U, 0U, 0U, 0U};    /* Store high level width */
uint8_t g_times_invalid = 0x00U;                /* Invalid edge counter */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_Config_TAU0_0_Create_UserInit
* Description  : This function adds user code after initializing the TAU0 channel0.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_TAU0_0_Create_UserInit(void)
{
    /* Start user code for user init. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_Config_TAU0_0_interrupt
* Description  : This function is INTTM00 interrupt service routine.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
static void __near r_Config_TAU0_0_interrupt(void)
{
    if (1U == (TSR00 & _0001_TAU_OVERFLOW_OCCURS))    /* overflow occurs */
    {
        g_tau0_ch0_width = (uint32_t)(TDR00 + 1UL) + 0x10000UL;
    }
    else
    {
        g_tau0_ch0_width = (uint32_t)(TDR00 + 1UL);
    }
    /* Start user code for r_Config_TAU0_0_interrupt. Do not edit comment generated here */
    g_port_data[0] = P0;
    NOP();
    NOP();
    NOP();
    NOP();
    g_port_data[1] = P0;

    if ((0U == TMIF00) && ((0x01U & g_port_data[0]) == (0x01U & g_port_data[1])))
    {
        g_edge_flag = (g_port_data[0] & 0x01U);    /* Set edge flag */

        if (0U == g_edge_flag)    /* Store high level width */
        {
            if (0U < g_times_high)    /* 4 times measurement finished ? */
            {
                g_width_high[g_count - g_times_high] = g_tau0_ch0_width;    /* Store capture value */
                g_times_high--;
            }
            else
            {
                ;
            }
        }
        else    /* Store low level width */
        {
            if (0U < g_times_low)     /* 4 times measurement finished ? */
            {
                g_width_low[g_count-g_times_low] = g_tau0_ch0_width;    /* Store capture value */
                g_times_low--;
            }
            else
            {
                ;
            }
         }
    }
    else     /* Interrupt request is generated */
    {
        g_times_invalid++;      /* Increment counter of invalid edge */
        TMIF00 = 0U;            /* Clear interrupt request */
    }
    /* End user code. Do not edit comment generated here */
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
