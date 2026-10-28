/*
* Copyright (c) 2021 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
* File Name        : r_cg_systeminit.c
* Version          : 1.0.200
* Device(s)        : R7F100GSNxFB
* Description      : This file implements system initializing function.
***********************************************************************************************************************/
/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_userdefine.h"
#include "Config_PORT.h"
#include "ADC.h"
#include "INTC.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Pragma directive
***********************************************************************************************************************/
/* Start user code for pragma. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_Systeminit
* Description  : This function initializes every macro
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Systeminit(void)
{
    PRR0 = 0x7FU;    /* reset IICA, ADC, TAU and SAU module */
    PRR1 = 0xF3U;    /* reset DAC, SMS, COMP, ITL, REMC, CTSU module */
    PRR0 = 0x00U;    /* release IICA, ADC, TAU and SAU module */
    PRR1 = 0x00U;    /* release DAC, SMS, COMP, ITL, REMC, CTSU module */
    /* Set peripheral settings */
    R_Config_PORT_Create();
    R_ADC_Create();
    R_INTC_Create();
}
