/*
* Copyright (c) 2021 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
* File Name        : TAU0_4.c
* Component Version: 1.9.0
* Device(s)        : R7F100GSNxFB
* Description      : This file implements device driver for TAU0_4.
***********************************************************************************************************************/
/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_userdefine.h"
#include "TAU0_4.h"
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
/* For TAU0_ch4 pulse measurement */
extern volatile uint32_t g_tau0_ch4_width;
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_TAU0_4_Create
* Description  : This function initializes the TAU0 channel4 module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TAU0_4_Create(void)
{
    uint16_t temp = TPS0;

    temp &= _FFF0_TAU_CKM0_CLEAR;
    temp |= _0008_TAU_CKM0_FCLK_8;
    TPS0 = temp;
    /* Stop channel 4 */
    TT0L_bit.no4 = 1U;    /* the count operation is stopped */
    /* Mask channel 4 interrupt */
    TMMK04 = 1U;    /* disable INTTM04 interrupt */
    TMIF04 = 0U;    /* clear INTTM04 interrupt flag */
    /* Set INTTM04 low priority */
    TMPR104 = 1U;
    TMPR004 = 1U;
    /* TAU04 is used to measure input pulse interval */
    NFEN1_bit.no4 = 0U;    /* turns the noise filter off */
    TMR04 = _0000_TAU_CLOCK_SELECT_CKM0 | _0000_TAU_CLOCK_MODE_CKS | _0000_TAU_COMBINATION_SLAVE | 
            _0100_TAU_TRIGGER_TIMN_VALID | _0000_TAU_TIMN_EDGE_FALLING | _0004_TAU_MODE_CAPTURE | 
            _0000_TAU_START_INT_UNUSED;
    TOM0L &= (uint8_t)~_10_TAU_CH4_SLAVE_OUTPUT;
    TOL0L &= (uint8_t)~_10_TAU_CH4_OUTPUT_LEVEL_L;
    TO0L &= (uint8_t)~_10_TAU_CH4_OUTPUT_VALUE_1;
    TOE0L_bit.no4 = 0U;    /* disables timer output */
    /* Set TI04 pin */
    PM4 |= 0x04U;

    R_TAU0_4_Create_UserInit();
}

/***********************************************************************************************************************
* Function Name: R_TAU0_4_Start
* Description  : This function starts the TAU0 channel4 counter.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TAU0_4_Start(void)
{
    TMIF04 = 0U;    /* clear INTTM04 interrupt flag */
    TMMK04 = 0U;    /* enable INTTM04 interrupt */
    TS0L_bit.no4 = 1U;    /* the count operation becomes enabled */
}

/***********************************************************************************************************************
* Function Name: R_TAU0_4_Stop
* Description  : This function stops the TAU0 channel4 counter.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TAU0_4_Stop(void)
{
    TT0L_bit.no4 = 1U;    /* the count operation is stopped */
    /* Mask channel 4 interrupt */
    TMMK04 = 1U;    /* disable INTTM04 interrupt */
    TMIF04 = 0U;    /* clear INTTM04 interrupt flag */
}

/***********************************************************************************************************************
* Function Name: R_TAU0_4_Get_PulseWidth
* Description  : This function measures TAU0 channel 4 input pulse width.
* Arguments    : width -
*                    the address where to write the input pulse width
* Return Value : None
***********************************************************************************************************************/
void R_TAU0_4_Get_PulseWidth(uint32_t * const width)
{
    /* For channel 4 pulse measurement */
    *width = g_tau0_ch4_width;
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
