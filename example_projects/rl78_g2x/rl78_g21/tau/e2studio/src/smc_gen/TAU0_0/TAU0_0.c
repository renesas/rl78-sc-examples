/*
* Copyright (c) 2021 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
* File Name        : TAU0_0.c
* Component Version: 1.9.0
* Device(s)        : R7F103GLJxFB
* Description      : This file implements device driver for TAU0_0.
***********************************************************************************************************************/
/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_userdefine.h"
#include "TAU0_0.h"
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
* Function Name: R_TAU0_0_Create
* Description  : This function initializes the TAU0 channel0 module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TAU0_0_Create(void)
{
    uint16_t temp = TPS0;

    temp &= _FFF0_TAU_CKM0_CLEAR;
    temp |= _0008_TAU_CKM0_FCLK_8;
    TPS0 = temp;
    /* Disable channel 0 counter operation */
    TT0L_bit.no0 = 1U;    /* the count operation is stopped */
    /* Mask channel 0 interrupt */
    TMMK00 = 1U;    /* disable INTTM00 interrupt */
    TMIF00 = 0U;    /* clear INTTM00 interrupt flag */
    /* Set INTTM00 low priority */
    TMPR100 = 1U;
    TMPR000 = 1U;
    NFEN1_bit.no0 = 0U;    /* disable using noise filter of TI00 pin input signal */
    /* Channel 0 used */
    TMR00 = _0000_TAU_CLOCK_SELECT_CKM0 | _1000_TAU_CLOCK_MODE_TIMN | _0000_TAU_TRIGGER_SOFTWARE |
            _0000_TAU_TIMN_EDGE_FALLING | _0000_TAU_MODE_INTERVAL_TIMER | _0000_TAU_START_INT_UNUSED;
    TDR00 = _0031_TAU_TDR00_VALUE;
    TO0L &= (~_01_TAU_CH0_OUTPUT_VALUE_1);
    TOE0L_bit.no0 = 1U;    /* enables timer output */
    /* Set TI00 pin */
    PM0 |= 0x01U;
    /* Set TO00 pin */
    P0 &= 0xFDU;
    PM0 &= 0xFDU;

    R_TAU0_0_Create_UserInit();
}

/***********************************************************************************************************************
* Function Name: R_TAU0_0_Start
* Description  : This function starts the TAU0 channel0 counter.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TAU0_0_Start(void)
{
    TMIF00 = 0U;    /* clear INTTM00 interrupt flag */
    TMMK00 = 0U;    /* enable INTTM00 interrupt */
    /* Enable channel0 counter operation */
    TOE0L_bit.no0 = 1U;    /* enables timer output */
    TS0L_bit.no0 = 1U;    /* the count operation becomes enabled */
}

/***********************************************************************************************************************
* Function Name: R_TAU0_0_Stop
* Description  : This function stops the TAU0 channel0 counter.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TAU0_0_Stop(void)
{
    TT0L_bit.no0 = 1U;    /* the count operation is stopped */
    TOE0L_bit.no0 = 0U;    /* disables timer output */
    /* Mask channel 0 interrupt */
    TMMK00 = 1U;    /* disable INTTM00 interrupt */
    TMIF00 = 0U;    /* clear INTTM00 interrupt flag */
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
