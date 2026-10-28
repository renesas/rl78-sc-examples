/*
* Copyright (c) 2021 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
* File Name        : TAU0_7.c
* Component Version: 1.10.0
* Device(s)        : R7F100GSNxFB
* Description      : This file implements device driver for TAU0_7.
***********************************************************************************************************************/
/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_userdefine.h"
#include "TAU0_7.h"
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
/* For TAU0_ch7 pulse measurement */
extern volatile uint32_t g_tau0_ch7_width;
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_TAU0_7_Create
* Description  : This function initializes the TAU0 channel7 module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TAU0_7_Create(void)
{
    uint16_t temp = TPS0;

    temp &= _FFF0_TAU_CKM0_CLEAR;
    temp |= _0008_TAU_CKM0_FCLK_8;
    TPS0 = temp;
    /* Stop channel 7 */
    TT0L_bit.no7 = 1U;    /* the count operation is stopped */
    /* Mask channel 7 interrupt */
    TMMK07 = 1U;    /* disable INTTM07 interrupt */
    TMIF07 = 0U;    /* clear INTTM07 interrupt flag */
    /* Set INTTM07 low priority */
    TMPR107 = 1U;
    TMPR007 = 1U;
    /* TAU07 is used to measure input pulse low-/high-width */
    ISC_bit.no1 = 0U;    /* use TImn pin as a timer input */
    NFEN1_bit.no7 = 0U;    /* turns the noise filter off */
    TMR07 = _0000_TAU_CLOCK_SELECT_CKM0 | _0000_TAU_CLOCK_MODE_CKS | _0200_TAU_TRIGGER_TIMN_BOTH | 
            _0080_TAU_TIMN_EDGE_BOTH_LOW | _000C_TAU_MODE_HIGHLOW_MEASURE;
    TOM0L &= (uint8_t)~_80_TAU_CH7_SLAVE_OUTPUT;
    TOL0L &= (uint8_t)~_80_TAU_CH7_OUTPUT_LEVEL_L;
    TO0L &= (uint8_t)~_80_TAU_CH7_OUTPUT_VALUE_1;
    TOE0L_bit.no7 = 0U;    /* disables timer output */
    /* Set TI07 pin */
    PM14 |= 0x20U;
    
    R_TAU0_7_Create_UserInit();
}

/***********************************************************************************************************************
* Function Name: R_TAU0_7_Start
* Description  : This function starts the TAU0 channel7 counter.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TAU0_7_Start(void)
{
    TMIF07 = 0U;    /* clear INTTM07 interrupt flag */
    TMMK07 = 0U;    /* enable INTTM07 interrupt */
    TS0L_bit.no7 = 1U;    /* the count operation becomes enabled */
}

/***********************************************************************************************************************
* Function Name: R_TAU0_7_Stop
* Description  : This function stops the TAU0 channel7 counter.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TAU0_7_Stop(void)
{
    TT0L_bit.no7 = 1U;    /* the count operation is stopped */
    /* Mask channel 7 interrupt */
    TMMK07 = 1U;    /* disable INTTM07 interrupt */
    TMIF07 = 0U;    /* clear INTTM07 interrupt flag */
}

/***********************************************************************************************************************
* Function Name: R_TAU0_7_Get_PulseWidth
* Description  : This function measures TAU0 channel 7 input pulse width.
* Arguments    : width -
*                    the address where to write the input pulse width
* Return Value : None
***********************************************************************************************************************/
void R_TAU0_7_Get_PulseWidth(uint32_t * const width)
{
    /* For channel 7 pulse measurement */
    *width = g_tau0_ch7_width;
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
