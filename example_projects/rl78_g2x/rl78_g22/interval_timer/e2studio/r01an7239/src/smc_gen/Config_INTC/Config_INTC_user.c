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
* File Name        : Config_INTC_user.c
* Component Version: 1.4.0
* Device(s)        : R7F102GGExFB
* Description      : This file implements device driver for Config_INTC.
***********************************************************************************************************************/
/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_userdefine.h"
#include "Config_INTC.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Pragma directive
***********************************************************************************************************************/
#pragma interrupt r_Config_INTC_intp0_interrupt(vect=INTP0)
/* Start user code for pragma. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_Config_INTC_Create_UserInit
* Description  : This function adds user code after initializing the INTC module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_INTC_Create_UserInit(void)
{
    /* Start user code for user init. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_Config_INTC_intp0_interrupt
* Description  : This function is INTP0 interrupt service routine
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
static void __near r_Config_INTC_intp0_interrupt(void)
{
    /* Start user code for r_Config_INTC_intp0_interrupt. Do not edit comment generated here */
	uint8_t ucchat;                /* 8 bit variable for noise rejection */

	/* Waiting about 10ms for noise rejection */
	for (ucchat = g_10ms_count[g_sw_counter]; ucchat > 0U; ucchat-- )
	{
	    while (0U == TMIF00)
	    {
	        HALT();                /* Waiting of TM00 interrupt request */
	    }

	    TMIF00 = 0U;               /* INTTM00 interrupt request clear */
	    r_invert_led();            /* Set new timer interval & LED output */
    }

	/* After 10ms or more from when the SW is turned ON */
	/*                 check the status of the SW again */

    if (0U == P13_bit.no7)         /* Is SW really ON ? */
	{
	    /* Updating SW input count */
	    g_sw_counter = (g_sw_counter + 1U) & 0x03;

	    /* Updating interval time */
	    g_tdr00_work = g_tdr00_data[g_sw_counter];
    }

    PIF0 =    0U;                  /* INTP0 interrupt request clear */
    /* End user code. Do not edit comment generated here */
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
