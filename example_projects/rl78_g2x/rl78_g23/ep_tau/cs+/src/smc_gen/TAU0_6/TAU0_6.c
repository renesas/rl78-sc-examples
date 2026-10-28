/*
* Copyright (c) 2021 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
* File Name        : TAU0_6.c
* Component Version: 1.9.0
* Device(s)        : R7F100GSNxFB
* Description      : This file implements device driver for TAU0_6.
***********************************************************************************************************************/
/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_userdefine.h"
#include "TAU0_6.h"
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
* Function Name: R_TAU0_6_Create
* Description  : This function initializes the TAU0 channel6 module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TAU0_6_Create(void)
{
    uint16_t temp = TPS0;

    temp &= _FFF0_TAU_CKM0_CLEAR;
    temp |= _0008_TAU_CKM0_FCLK_8;
    TPS0 = temp;
    /* Stop channel 6 */
    TT0L_bit.no6 = 1U;    /* the count operation is stopped */
    /* Mask channel 6 interrupt */
    TMMK06 = 1U;    /* disable INTTM06 interrupt */
    TMIF06 = 0U;    /* clear INTTM06 interrupt flag */
    /* Set INTTM06 low priority */
    TMPR106 = 1U;
    TMPR006 = 1U;
    /* TAU06 used as square output function */
    TMR06 = _0000_TAU_CLOCK_SELECT_CKM0 | _0000_TAU_CLOCK_MODE_CKS | _0000_TAU_COMBINATION_SLAVE | 
            _0000_TAU_TRIGGER_SOFTWARE | _0000_TAU_MODE_INTERVAL_TIMER | _0000_TAU_START_INT_UNUSED;
    TDR06 = _04E1_TAU_TDR06_VALUE;
    TOM0L &= (uint8_t)~_40_TAU_CH6_SLAVE_OUTPUT;
    TOL0L &= (uint8_t)~_40_TAU_CH6_OUTPUT_LEVEL_L;
    TO0L &= (uint8_t)~_40_TAU_CH6_OUTPUT_VALUE_1;
    TOE0L_bit.no6 = 1U;    /* enables timer output */
    /* Set TO06 pin */
    PFOE0 |= 0x40U;
    P10 &= 0xFBU;
    PM10 &= 0xFBU;
    
    R_TAU0_6_Create_UserInit();
}

/***********************************************************************************************************************
* Function Name: R_TAU0_6_Start
* Description  : This function starts the TAU0 channel6 counter.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TAU0_6_Start(void)
{
    TMIF06 = 0U;    /* clear INTTM06 interrupt flag */
    TMMK06 = 0U;    /* enable INTTM06 interrupt */
    TOE0L_bit.no6 = 1U;    /* enables timer output */
    TS0L_bit.no6 = 1U;    /* the count operation becomes enabled */
}

/***********************************************************************************************************************
* Function Name: R_TAU0_6_Stop
* Description  : This function stops the TAU0 channel6 counter.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TAU0_6_Stop(void)
{
    TT0L_bit.no6 = 1U;    /* the count operation is stopped */
    TOE0L_bit.no6 = 0U;    /* disables timer output */
    /* Mask channel 6 interrupt */
    TMMK06 = 1U;    /* disable INTTM06 interrupt */
    TMIF06 = 0U;    /* clear INTTM06 interrupt flag */
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
