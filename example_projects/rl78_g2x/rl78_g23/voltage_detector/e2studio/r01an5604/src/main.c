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
/*  NOTE:THIS IS A TYPICAL EXAMPLE.                                    */
/*                                                                     */
/***********************************************************************/

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_userdefine.h"
#include "Config_LVD1.h"
#include "Config_INTC.h"
#include "r_cg_lvd_common.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
uint8_t g_SwCount;          /* Counter for KEY pushed */

const uint8_t aLedNumberTable[4][3] =
{
/*    LED1	    LED2	  LED3 */
	{ LED_OFF , LED_OFF , LED_OFF },         /* "0" */
	{ LED_ON  , LED_OFF , LED_OFF },         /* "1" */
	{ LED_OFF , LED_ON  , LED_OFF },         /* "2" */
	{ LED_OFF , LED_OFF , LED_ON  }          /* "3" */
};

void main(void);

/***********************************************************************************************************************
* Function Name: main
* Description  : This function implements main function.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void main(void)
{
	uint8_t led_pattern = 0U;       /* Work area for LED on/off pattern */

	RPERDIS = 1;

    /* ---- In case RESET REQUESTED by LVD circuit. ---- */
    if (!(RESF & 0b00000001))
    {
        /* Initialize counter for KEY input times. */
        g_SwCount = 0U;             /* All LEDs are turned off. */
    }
    /* ---- In case RESET has been occurred by except LVD. ---- */
    else
    {
        /* Keep LED outputs */
    }

    R_Config_INTC_INTP0_Start();
	R_Config_LVD1_Start();
	R_LVD_Start_Interrupt();
    EI();

	while (1U)
    {
		led_pattern ^= 1U;
		P0_bit.no3 = aLedNumberTable[g_SwCount][0] & led_pattern;
		P0_bit.no2 = aLedNumberTable[g_SwCount][1] & led_pattern;
		P4_bit.no3 = aLedNumberTable[g_SwCount][2] & led_pattern;

		for(uint16_t i = 0; i < 1000; i++)
		{
		    NOP();
		}
    }
}
