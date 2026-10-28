/*
* Copyright (c) 2021 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
* File Name        : r_cg_sau_common.c
* Version          : 1.0.200
* Device(s)        : R7F103GLJxFB
* Description      : None
***********************************************************************************************************************/
/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_userdefine.h"
#include "SAU_UART0.h"
#include "r_cg_sau_common.h"
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
* Function Name: R_SAU0_Create
* Description  : This function enables SAU0 input clock supply and initializes SAU0 module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_SAU0_Create(void)
{
    SAU0EN = 1U;    /* supplies input clock */
    R_SAU_UART0_Create();
}

/***********************************************************************************************************************
* Function Name: R_SAU1_Create
* Description  : This function enables SAU1 input clock supply and initializes SAU1 module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_SAU1_Create(void)
{
    SAU1EN = 1U;    /* supplies input clock */
}

/***********************************************************************************************************************
* Function Name: R_SAU0_Set_PowerOn
* Description  : This function starts the clock supply for SAU0.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_SAU0_Set_PowerOn(void)
{
    SAU0EN = 1U;    /* supplies input clock */
}

/***********************************************************************************************************************
* Function Name: R_SAU0_Set_PowerOff
* Description  : This function stops the clock supply for SAU0.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_SAU0_Set_PowerOff(void)
{
    SAU0EN = 0U;    /* stops input clock supply */
}

/***********************************************************************************************************************
* Function Name: R_SAU1_Set_PowerOn
* Description  : This function starts the clock supply for SAU1.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_SAU1_Set_PowerOn(void)
{
    SAU1EN = 1U;    /* supplies input clock */
}

/***********************************************************************************************************************
* Function Name: R_SAU1_Set_PowerOff
* Description  : This function stops the clock supply for SAU1.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_SAU1_Set_PowerOff(void)
{
    SAU1EN = 0U;    /* stops input clock supply  */
}

/***********************************************************************************************************************
* Function Name: R_SAU0_Set_Reset
* Description  : This function sets SAU0 module in reset state.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_SAU0_Set_Reset(void)
{
    SAU0RES = 1U;    /* reset serial array unit */
}

/***********************************************************************************************************************
* Function Name: R_SAU0_Release_Reset
* Description  : This function releases SAU0 module from reset state.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_SAU0_Release_Reset(void)
{
    SAU0RES = 0U;    /* reset release of serial array unit */
}

/***********************************************************************************************************************
* Function Name: R_SAU1_Set_Reset
* Description  : This function sets SAU1 module in reset state.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_SAU1_Set_Reset(void)
{
    SAU1RES = 1U;    /* reset serial array unit */
}

/***********************************************************************************************************************
* Function Name: R_SAU1_Release_Reset
* Description  : This function releases SAU1 module from reset state.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_SAU1_Release_Reset(void)
{
    SAU1RES = 0U;    /* reset release of serial array unit */
}

/***********************************************************************************************************************
* Function Name: R_SAU0_Set_SnoozeOn
* Description  : This function enables SAU0 wakeup function.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_SAU0_Set_SnoozeOn(void)
{
    SSC0L |= _01_SAU_CH0_SNOOZE_ON;
}

/***********************************************************************************************************************
* Function Name: R_SAU0_Set_SnoozeOff
* Description  : This function disables SAU0 wakeup function.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_SAU0_Set_SnoozeOff(void)
{
    SSC0L &= (uint8_t)~_01_SAU_CH0_SNOOZE_ON;
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
