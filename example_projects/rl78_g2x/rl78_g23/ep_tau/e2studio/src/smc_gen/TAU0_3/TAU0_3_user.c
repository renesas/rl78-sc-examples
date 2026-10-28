/*
* Copyright (c) 2021 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
* File Name        : TAU0_3_user.c
* Component Version: 1.9.0
* Device(s)        : R7F100GSNxFB
* Description      : This file implements device driver for TAU0_3.
***********************************************************************************************************************/
/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_userdefine.h"
#include "TAU0_3.h"
/* Start user code for include. Do not edit comment generated here */
#include "../tau.h"
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Pragma directive
***********************************************************************************************************************/
#pragma interrupt r_TAU0_3_interrupt(vect=INTTM03)
/* Start user code for pragma. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_TAU0_3_Create_UserInit
* Description  : This function adds user code after initializing the TAU0 channel3.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TAU0_3_Create_UserInit(void)
{
    /* Start user code for user init. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_TAU0_3_interrupt
* Description  : This function is INTTM03 interrupt service routine.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
static void __near r_TAU0_3_interrupt(void)
{
    /* Start user code for r_TAU0_3_interrupt. Do not edit comment generated here */
	tau_delay_timer_callback(TIMER_EVENT_CYCLE_END);
    /* End user code. Do not edit comment generated here */
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
