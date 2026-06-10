/**********************************************************************************************************************
 * DISCLAIMER
 * This software is supplied by Renesas Electronics Corporation and is only intended for use with Renesas products. No
 * other uses are authorized. This software is owned by Renesas Electronics Corporation and is protected under all
 * applicable laws, including copyright laws.
 * THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING
 * THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED. TO THE MAXIMUM
 * EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES
 * SHALL BE LIABLE FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY REASON RELATED TO
 * THIS SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
 * Renesas reserves the right, without notice, to make changes to this software and to discontinue the availability of
 * this software. By using this software, you agree to the additional terms and conditions found by accessing the
 * following link:
 * http://www.renesas.com/disclaimer
 *
 * Copyright (C) 2020 Renesas Electronics Corporation. All rights reserved.
 *********************************************************************************************************************/
/***********************************************************************/
/*                                                                     */
/*  FILE        :Main.c                                                */
/*  DATE        :                                                      */
/*  DESCRIPTION :Main Program                                          */
/*  CPU TYPE    :                                                      */
/*                                                                     */
/*  NOTE: Timer Array Unit (Pulse Interval Measurement) APN            */
/*                                                                     */
/***********************************************************************/

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_smc_entry.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
__saddr uint32_t g_pulse_width[8];    /* Store pulse width */
uint8_t g_times;                      /* Measurement times counter */

void main (void);

/***********************************************************************************************************************
* Function Name: main
* Description  : This function implements main function.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void main(void)
{
    R_Config_TAU0_0_Start();    /* Start timer counter */

    while (!TMIF00)
    {
        HALT();     /* Wait first edge detection */
    }
    TMIF00 = 0U;    /* Clear interrupt flag */

    g_times = 8U;   /* Set number of measurement */

    EI();           /* Enable interrupt */

    /* Wait for the measurement to finish */
    while (0U != g_times)
    {
        HALT();
    }

    /* Do nothing after measurement */
    while (1U)
    {
        HALT();    
    }
}
/**********************************************************************************************************************
 End of function main
 *********************************************************************************************************************/

