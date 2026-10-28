/*
* Copyright (c) 2021 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
* File Name        : r_cg_uarta_common.c
* Version          : 1.0.200
* Device(s)        : R7F100GSNxFB
* Description      : None
***********************************************************************************************************************/
/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_userdefine.h"
#include "UARTA0.h"
#include "r_cg_uarta_common.h"
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
* Function Name: R_UARTA_Create
* Description  : This function enables UARTA0/UARTA1 input clock supply and initializes UARTA0/UARTA1 module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_UARTA_Create(void)
{
    UTAEN = 1U;    /* supply UARTA0/UARTA1 clock */
    /* Set UARTA0/UARTA1 settings */
    R_UARTA0_Create();
}

/***********************************************************************************************************************
* Function Name: R_UARTA_Set_PowerOn
* Description  : This function starts the clock supply for UARTA0/UARTA1.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_UARTA_Set_PowerOn(void)
{
    UTAEN = 1U;    /* supply UARTA0,UARTA1 clock */
}

/***********************************************************************************************************************
* Function Name: R_UARTA_Set_PowerOff
* Description  : This function stops the clock supply for UARTA0/UARTA1.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_UARTA_Set_PowerOff(void)
{
    UTAEN = 0U;    /* stop UARTA0,UARTA1 clock */
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

