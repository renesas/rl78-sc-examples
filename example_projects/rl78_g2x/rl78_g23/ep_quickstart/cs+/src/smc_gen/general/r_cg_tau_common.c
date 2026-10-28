/*
* Copyright (c) 2021 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
* File Name        : r_cg_tau_common.c
* Version          : 1.0.200
* Device(s)        : R7F100GSNxFB
* Description      : None
***********************************************************************************************************************/
/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_userdefine.h"
#include "Config_TAU0_0.h"
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
    R_Config_TAU0_0_Create();
}

/***********************************************************************************************************************
* Function Name: R_TAU1_Create
* Description  : This function enables TAU1 input clock supply and initializes TAU1 module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TAU1_Create(void)
{
    TAU1EN = 1U;    /* start TAU1 clock */
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

/***********************************************************************************************************************
* Function Name: R_TAU1_Set_PowerOn
* Description  : This function starts the clock supply for TAU1.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TAU1_Set_PowerOn(void)
{
    TAU1EN = 1U;    /* start TAU1 clock */
}

/***********************************************************************************************************************
* Function Name: R_TAU1_Set_PowerOff
* Description  : This function stops the clock supply for TAU1.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TAU1_Set_PowerOff(void)
{
    TAU1EN = 0U;    /* stop TAU1 clock */
}

/***********************************************************************************************************************
* Function Name: R_TAU1_Set_Reset
* Description  : This function sets TAU1 module in reset state.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TAU1_Set_Reset(void)
{
    TAU1RES = 1U;    /* reset TAU1 */
}

/***********************************************************************************************************************
* Function Name: R_TAU1_Release_Reset
* Description  : This function releases TAU1 module from reset state.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TAU1_Release_Reset(void)
{
    TAU1RES = 0U;    /* release TAU1 */
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
