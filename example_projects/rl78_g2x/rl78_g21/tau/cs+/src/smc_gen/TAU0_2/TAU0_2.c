/*
* Copyright (c) 2021 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
* File Name        : TAU0_2.c
* Component Version: 1.10.0
* Device(s)        : R7F103GLJxFB
* Description      : This file implements device driver for TAU0_2.
***********************************************************************************************************************/
/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_userdefine.h"
#include "TAU0_2.h"
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
* Function Name: R_TAU0_2_Create
* Description  : This function initializes the TAU0 channel 2 module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TAU0_2_Create(void)
{
    uint16_t temp = TPS0;

    temp &= _FFF0_TAU_CKM0_CLEAR;
    temp |= _0008_TAU_CKM0_FCLK_8;
    TPS0 = temp;
    /* Stop channel 2 */
    TT0L_bit.no2 = 1U;    /* the count operation is stopped */
    /* Mask channel 2 interrupt */
    TMMK02 = 1U;    /* disable INTTM02 interrupt */
    TMIF02 = 0U;    /* clear INTTM02 interrupt flag */
    /* Set INTTM02 low priority */
    TMPR102 = 1U;
    TMPR002 = 1U;
    /* TAU02 used as interval timer */
    TMR02 = _0000_TAU_CLOCK_SELECT_CKM0 | _0000_TAU_CLOCK_MODE_CKS | _0000_TAU_COMBINATION_SLAVE | 
            _0000_TAU_TRIGGER_SOFTWARE | _0000_TAU_MODE_INTERVAL_TIMER | _0000_TAU_START_INT_UNUSED;
    TDR02 = _F423_TAU_TDR02_VALUE;
    TOM0L &= (uint8_t)~_04_TAU_CH2_SLAVE_OUTPUT;
    TOL0L &= (uint8_t)~_04_TAU_CH2_OUTPUT_LEVEL_L;
    TO0L &= (uint8_t)~_04_TAU_CH2_OUTPUT_VALUE_1;
    TOE0L_bit.no2 = 0U;    /* disables timer output */

    R_TAU0_2_Create_UserInit();
}

/***********************************************************************************************************************
* Function Name: R_TAU0_2_Start
* Description  : This function starts the TAU0 channel 2 counter.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TAU0_2_Start(void)
{
    TMIF02 = 0U;    /* clear INTTM02 interrupt flag */
    TMMK02 = 0U;    /* enable INTTM02 interrupt */
    TS0L_bit.no2 = 1U;    /* the count operation becomes enabled */
}

/***********************************************************************************************************************
* Function Name: R_TAU0_2_Stop
* Description  : This function stops the TAU0 channel 2 counter.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TAU0_2_Stop(void)
{
    TT0L_bit.no2 = 1U;    /* the count operation is stopped */
    /* Mask channel 2 interrupt */
    TMMK02 = 1U;    /* disable INTTM02 interrupt */
    TMIF02 = 0U;    /* clear INTTM02 interrupt flag */
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
