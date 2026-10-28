/*
* Copyright (c) 2021 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
* File Name        : r_cg_tau_common.c
* Version          : 1.0.200
* Device(s)        : R7F103GLJxFB
* Description      : None
***********************************************************************************************************************/
/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_userdefine.h"
#include "TAU0_0.h"
#include "TAU0_1.h"
#include "TAU0_2.h"
#include "TAU0_3.h"
#include "TAU0_4.h"
#include "TAU0_5.h"
#include "TAU0_6.h"
#include "TAU0_7.h"
#include "r_cg_tau_common.h"
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
* Function Name: R_TAU0_Create
* Description  : This function enables TAU0 input clock supply and initializes TAU0 module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TAU0_Create(void)
{
    TAU0EN = 1U;    /* start TAU0 clock */
    /* Set TAU0 settings */
    R_TAU0_0_Create();
    R_TAU0_1_Create();
    R_TAU0_2_Create();
    R_TAU0_3_Create();
    R_TAU0_4_Create();
    R_TAU0_5_Create();
    R_TAU0_6_Create();
    R_TAU0_7_Create();
}

/***********************************************************************************************************************
* Function Name: R_TAU0_Set_PowerOn
* Description  : This function starts the clock supply for TAU0.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TAU0_Set_PowerOn(void)
{
    TAU0EN = 1U;    /* start TAU0 clock */
}

/***********************************************************************************************************************
* Function Name: R_TAU0_Set_PowerOff
* Description  : This function stops the clock supply for TAU0.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TAU0_Set_PowerOff(void)
{
    TAU0EN = 0U;    /* stop TAU0 clock */
}

/***********************************************************************************************************************
* Function Name: R_TAU0_Set_Reset
* Description  : This function sets TAU0 module in reset state.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TAU0_Set_Reset(void)
{
    TAU0RES = 1U;    /* reset TAU0 */
}

/***********************************************************************************************************************
* Function Name: R_TAU0_Release_Reset
* Description  : This function releases TAU0 module from reset state.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TAU0_Release_Reset(void)
{
    TAU0RES = 0U;    /* release TAU0 */
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

