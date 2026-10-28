/*
* Copyright (c) 2021 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
* File Name        : TAU0_5.c
* Component Version: 1.9.0
* Device(s)        : R7F103GLJxFB
* Description      : This file implements device driver for TAU0_5.
***********************************************************************************************************************/
/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_userdefine.h"
#include "TAU0_5.h"
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
* Function Name: R_TAU0_5_Create
* Description  : This function initializes the TAU0 channel5 module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TAU0_5_Create(void)
{
    uint16_t temp = TPS0;

    temp &= _FFF0_TAU_CKM0_CLEAR;
    temp |= _0008_TAU_CKM0_FCLK_8;
    TPS0 = temp;
    /* Stop channel 5 */
    TT0L_bit.no5 = 1U;    /* the count operation is stopped */
    /* Mask channel 5 interrupt */
    TMMK05 = 1U;    /* disable INTTM05 interrupt */
    TMIF05 = 0U;    /* clear INTTM05 interrupt flag */
    /* Set INTTM05 low priority */
    TMPR105 = 1U;
    TMPR005 = 1U;
    /* TAU05 used as external event counter function */
    TIS0 = _00_TAU_CH5_INPUT_TI05;
    NFEN1_bit.no5 = 0U;    /* turns the noise filter off */
    TMR05 = _0000_TAU_CLOCK_SELECT_CKM0 | _1000_TAU_CLOCK_MODE_TIMN | _0000_TAU_TRIGGER_SOFTWARE | 
            _0000_TAU_TIMN_EDGE_FALLING | _0006_TAU_MODE_EVENT_COUNT;
    TDR05 = _0004_TAU_TDR05_VALUE;
    TOM0L &= (uint8_t)~_20_TAU_CH5_SLAVE_OUTPUT;
    TOL0L &= (uint8_t)~_20_TAU_CH5_OUTPUT_LEVEL_L;
    TO0L &= (uint8_t)~_20_TAU_CH5_OUTPUT_VALUE_1;
    TOE0L_bit.no5 = 0U;    /* disables timer output */
    /* Set TI05 pin */
    PM0 |= 0x20U;

    R_TAU0_5_Create_UserInit();
}

/***********************************************************************************************************************
* Function Name: R_TAU0_5_Start
* Description  : This function starts the TAU0 channel5 counter.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TAU0_5_Start(void)
{
    TMIF05 = 0U;    /* clear INTTM05 interrupt flag */
    TMMK05 = 0U;    /* enable INTTM05 interrupt */
    TS0L_bit.no5 = 1U;    /* the count operation becomes enabled */
}

/***********************************************************************************************************************
* Function Name: R_TAU0_5_Stop
* Description  : This function stops the TAU0 channel5 counter.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TAU0_5_Stop(void)
{
    TT0L_bit.no5 = 1U;    /* the count operation is stopped */
    /* Mask channel 5 interrupt */
    TMMK05 = 1U;    /* disable INTTM05 interrupt */
    TMIF05 = 0U;    /* clear INTTM05 interrupt flag */
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
