/*
* Copyright (c) 2021 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
* File Name        : INTC_user.c
* Component Version: 1.8.0
* Device(s)        : R7F103GLJxFB
* Description      : This file implements device driver for INTC.
***********************************************************************************************************************/
/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_userdefine.h"
#include "INTC.h"
/* Start user code for include. Do not edit comment generated here */
#include "ADC.h"
#include "Pin.h"
#include "adc_fpb_rl78g21_ep.h"
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Pragma directive
***********************************************************************************************************************/
#pragma interrupt r_INTC_intp0_interrupt(vect=INTP0)
/* Start user code for pragma. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_INTC_Create_UserInit
* Description  : This function adds user code after initializing the INTC module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_INTC_Create_UserInit(void)
{
    /* Start user code for user init. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_INTC_intp0_interrupt
* Description  : This function is INTP0 interrupt service routine
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
static void __near r_INTC_intp0_interrupt(void)
{
    /* Start user code for r_INTC_intp0_interrupt. Do not edit comment generated here */
    g_sw1_request = SW1_REQUEST_SET;
    /* End user code. Do not edit comment generated here */
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
