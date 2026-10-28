/*
* Copyright (c) 2021 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
* File Name        : r_cg_uarta_common.c
* Version          : 1.0.200
* Device(s)        : R7F103GLJxFB
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
* Description  : This function enables UARTAn input clock supply and initializes UARTAn module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_UARTA_Create(void)
{
    /* Set UARTAn settings */
    R_UARTA0_Create();
}

/***********************************************************************************************************************
* Function Name: R_UARTA0_Set_PowerOn
* Description  : This function starts the clock supply for UARTA0.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_UARTA0_Set_PowerOn(void)
{
    UTAEN = 1U;    /* supply UARTA0 clock */
}

/***********************************************************************************************************************
* Function Name: R_UARTA0_Set_PowerOff
* Description  : This function stops the clock supply for UARTA0.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_UARTA0_Set_PowerOff(void)
{
    UTAEN = 0U;    /* stop UARTA0 clock */
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
