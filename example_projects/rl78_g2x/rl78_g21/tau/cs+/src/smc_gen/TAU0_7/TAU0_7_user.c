/*
* Copyright (c) 2021 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
* File Name        : TAU0_7_user.c
* Component Version: 1.10.0
* Device(s)        : R7F103GLJxFB
* Description      : This file implements device driver for TAU0_7.
***********************************************************************************************************************/
/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_userdefine.h"
#include "TAU0_7.h"
/* Start user code for include. Do not edit comment generated here */
#include "../tau.h"
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Pragma directive
***********************************************************************************************************************/
#pragma interrupt r_TAU0_7_interrupt(vect=INTTM07)
/* Start user code for pragma. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* For TAU0_ch7 pulse measurement */
volatile uint32_t g_tau0_ch7_width = 0UL;
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_TAU0_7_Create_UserInit
* Description  : This function adds user code after initializing the TAU0 channel7.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TAU0_7_Create_UserInit(void)
{
    /* Start user code for user init. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_TAU0_7_interrupt
* Description  : This function is INTTM07 interrupt service routine.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
static void __near r_TAU0_7_interrupt(void)
{
    if (1U == (TSR07 & _0001_TAU_OVERFLOW_OCCURS))    /* overflow occurs */
    {
        g_tau0_ch7_width = (uint32_t)(TDR07 + 1UL) + 0x10000UL;
    }
    else
    {
        g_tau0_ch7_width = (uint32_t)(TDR07 + 1UL);
    }
    /* Start user code for r_TAU0_7_interrupt. Do not edit comment generated here */
    tau_measure_low_level_pulse_width_timer_callback(TIMER_EVENT_CAPTURE_EDGE);
    /* End user code. Do not edit comment generated here */
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
