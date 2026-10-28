/*
* Copyright (c) 2021 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
* File Name        : TAU0_3.c
* Component Version: 1.9.0
* Device(s)        : R7F103GLJxFB
* Description      : This file implements device driver for TAU0_3.
***********************************************************************************************************************/
/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_userdefine.h"
#include "TAU0_3.h"
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
* Function Name: R_TAU0_3_Create
* Description  : This function initializes the TAU0 channel3 module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TAU0_3_Create(void)
{
    uint16_t temp = TPS0;

    temp &= _FFF0_TAU_CKM0_CLEAR;
    temp |= _0008_TAU_CKM0_FCLK_8;
    TPS0 = temp;
    /* Stop channel 3 */
    TT0L_bit.no3 = 1U;    /* the count operation is stopped */
    /* Mask channel 3 interrupt */
    TMMK03 = 1U;    /* disable INTTM03 interrupt */
    TMIF03 = 0U;    /* clear INTTM03 interrupt flag */
    /* Set INTTM03 low priority */
    TMPR103 = 1U;
    TMPR003 = 1U;
    /* TAU03 is used as delay count function */
    NFEN1_bit.no3 = 0U;    /* turns the noise filter off */
    TMR03 = _0000_TAU_CLOCK_SELECT_CKM0 | _0000_TAU_CLOCK_MODE_CKS | _0000_TAU_16BITS_MODE | 
            _0100_TAU_TRIGGER_TIMN_VALID | _0000_TAU_TIMN_EDGE_FALLING | _0008_TAU_MODE_ONE_COUNT | 
            _0000_TAU_START_INT_UNUSED;
    TDR03 = _30D3_TAU_TDR03_VALUE;
    TOM0L &= (uint8_t)~_08_TAU_CH3_SLAVE_OUTPUT;
    TOL0L &= (uint8_t)~_08_TAU_CH3_OUTPUT_LEVEL_L;
    TO0L &= (uint8_t)~_08_TAU_CH3_OUTPUT_VALUE_1;
    TOE0L_bit.no3 = 0U;    /* disables timer output */
    /* Set TI03 pin */
    PM3 |= 0x02U;

    R_TAU0_3_Create_UserInit();
}

/***********************************************************************************************************************
* Function Name: R_TAU0_3_Start
* Description  : This function starts the TAU0 channel3 counter.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TAU0_3_Start(void)
{
    TMIF03 = 0U;    /* clear INTTM03 interrupt flag */
    TMMK03 = 0U;    /* enable INTTM03 interrupt */
    TS0L_bit.no3 = 1U;    /* the count operation becomes enabled */
}

/***********************************************************************************************************************
* Function Name: R_TAU0_3_Stop
* Description  : This function stops the TAU0 channel3 counter.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TAU0_3_Stop(void)
{
    TT0L_bit.no3 = 1U;    /* the count operation is stopped */
    /* Mask channel 3 interrupt */
    TMMK03 = 1U;    /* disable INTTM03 interrupt */
    TMIF03 = 0U;    /* clear INTTM03 interrupt flag */
}

/***********************************************************************************************************************
* Function Name: R_TAU0_3_Set_SoftwareTriggerOn
* Description  : This function generates software trigger.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TAU0_3_Set_SoftwareTriggerOn(void)
{
    TS0L_bit.no3 = 1U;    /* the count operation becomes enabled */
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
