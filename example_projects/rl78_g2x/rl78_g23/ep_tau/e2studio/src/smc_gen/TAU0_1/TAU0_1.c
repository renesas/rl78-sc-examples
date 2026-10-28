/*
* Copyright (c) 2021 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
* File Name        : TAU0_1.c
* Component Version: 1.9.0
* Device(s)        : R7F100GSNxFB
* Description      : This file implements device driver for TAU0_1.
***********************************************************************************************************************/
/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_userdefine.h"
#include "TAU0_1.h"
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
* Function Name: R_TAU0_1_Create
* Description  : This function initializes the TAU0 channel1 module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TAU0_1_Create(void)
{
    uint16_t temp = TPS0;

    temp &= _FFF0_TAU_CKM0_CLEAR;
    temp |= _0008_TAU_CKM0_FCLK_8;
    TPS0 = temp;
    /* Stop channel 1 */
    TT0L_bit.no1 = 1U;    /* the count operation is stopped */
    /* Mask channel 1 interrupt */
    TMMK01 = 1U;    /* disable INTTM01 interrupt */
    TMIF01 = 0U;    /* clear INTTM01 interrupt flag */
    /* Set INTTM01 low priority */
    TMPR101 = 1U;
    TMPR001 = 1U;
    /* TAU01 used as square output function */
    TMR01 = _0000_TAU_CLOCK_SELECT_CKM0 | _0000_TAU_CLOCK_MODE_CKS | _0000_TAU_16BITS_MODE | 
            _0000_TAU_TRIGGER_SOFTWARE | _0000_TAU_MODE_INTERVAL_TIMER | _0000_TAU_START_INT_UNUSED;
    TDR01 = _04E1_TAU_TDR01_VALUE;
    TOM0L &= (uint8_t)~_02_TAU_CH1_SLAVE_OUTPUT;
    TOL0L &= (uint8_t)~_02_TAU_CH1_OUTPUT_LEVEL_L;
    TO0L &= (uint8_t)~_02_TAU_CH1_OUTPUT_VALUE_1;
    TOE0L_bit.no1 = 1U;    /* enables timer output */
    /* Set TO01 pin */
    PMCE1 &= 0xBFU;
    PFOE0 |= 0x02U;
    CCDE &= 0xFEU;
    P1 &= 0xBFU;
    PM1 &= 0xBFU;
    
    R_TAU0_1_Create_UserInit();
}

/***********************************************************************************************************************
* Function Name: R_TAU0_1_Start
* Description  : This function starts the TAU0 channel1 counter.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TAU0_1_Start(void)
{
    TMIF01 = 0U;    /* clear INTTM01 interrupt flag */
    TMMK01 = 0U;    /* enable INTTM01 interrupt */
    TOE0L_bit.no1 = 1U;    /* enables timer output */
    TS0L_bit.no1 = 1U;    /* the count operation becomes enabled */
}

/***********************************************************************************************************************
* Function Name: R_TAU0_1_Stop
* Description  : This function stops the TAU0 channel1 counter.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TAU0_1_Stop(void)
{
    TT0L_bit.no1 = 1U;    /* the count operation is stopped */
    TOE0L_bit.no1 = 0U;    /* disables timer output */
    /* Mask channel 1 interrupt */
    TMMK01 = 1U;    /* disable INTTM01 interrupt */
    TMIF01 = 0U;    /* clear INTTM01 interrupt flag */
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
