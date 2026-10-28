/*
* Copyright (c) 2021 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
* File Name        : r_cg_ad_common.c
* Version          : 1.0.200
* Device(s)        : R7F100GSNxFB
* Description      : None
***********************************************************************************************************************/
/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_userdefine.h"
#include "r_cg_ad_common.h"
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
* Function Name: R_ADC_Set_PowerOn
* Description  : This function starts the clock supply for AD converter.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_ADC_Set_PowerOn(void)
{
    ADCEN = 1U;    /* start AD clock */
}

/***********************************************************************************************************************
* Function Name: R_ADC_Set_PowerOff
* Description  : This function stops the clock supply for AD converter.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_ADC_Set_PowerOff(void)
{
    ADCEN = 0U;    /* stop AD clock */
}

/***********************************************************************************************************************
* Function Name: R_ADC_Set_Reset
* Description  : This function sets AD converter module in reset state.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_ADC_Set_Reset(void)
{
    ADCRES = 1U;    /* reset AD converter */
}

/***********************************************************************************************************************
* Function Name: R_ADC_Release_Reset
* Description  : This function releases AD converter module from reset state.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_ADC_Release_Reset(void)
{
    ADCRES = 0U;    /* release AD converter */
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
