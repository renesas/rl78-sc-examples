/***********************************************************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only intended for use with Renesas products.
* No other uses are authorized. This software is owned by Renesas Electronics Corporation and is protected under all
* applicable laws, including copyright laws. 
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING THIS SOFTWARE, WHETHER EXPRESS, IMPLIED
* OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
* NON-INFRINGEMENT.  ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY
* LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE FOR ANY DIRECT,
* INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR
* ITS AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software and to discontinue the availability 
* of this software. By using this software, you agree to the additional terms and conditions found by accessing the 
* following link:
* http://www.renesas.com/disclaimer
*
* Copyright (C) 2021, 2023 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
* File Name        : Config_TAU0_0.c
* Component Version: 1.4.0
* Device(s)        : R7F101GLGxFB
* Description      : This file implements device driver for Config_TAU0_0.
***********************************************************************************************************************/
/***********************************************************************************************************************
Pragma directive
***********************************************************************************************************************/
/* Start user code for pragma. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_userdefine.h"
#include "Config_TAU0_0.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_Config_TAU0_0_Create
* Description  : This function initializes the TAU0 channel0 module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_TAU0_0_Create(void)
{
    TPS0 &= _FFF0_TAU_CKM0_CLEAR;
    TPS0 |= _0000_TAU_CKM0_FCLK_0;
    TT0 |= (_0004_TAU_CH2_STOP_TRG_ON | _0001_TAU_CH0_STOP_TRG_ON);
    TMMK00 = 1U;    /* disable INTTM00 interrupt */
    TMIF00 = 0U;    /* clear INTTM00 interrupt flag */
    TMMK02 = 1U;    /* disable INTTM02 interrupt */
    TMIF02 = 0U;    /* clear INTTM02 interrupt flag */
    /* Channel 0 is used as master channel for oneshot output function */
    TIOS0 &= (uint8_t)~_0F_TAU_CH0_INPUT_CLEAR;
    TIOS0 |= _20_TAU_CH0_INPUT_TRDIOB0;
    TMR00 = _0000_TAU_CLOCK_SELECT_CKM0 | _0000_TAU_CLOCK_MODE_CKS | _0100_TAU_TRIGGER_TIMN_VALID | 
            _0040_TAU_TIMN_EDGE_RISING | _0008_TAU_MODE_ONESHOT;
    /* Channel 2 is used as slave channel for oneshot output function */
    TMR02 = _0000_TAU_CLOCK_SELECT_CKM0 | _0000_TAU_CLOCK_MODE_CKS | _0000_TAU_COMBINATION_SLAVE | 
            _0400_TAU_TRIGGER_MASTER_INT | _0008_TAU_MODE_ONESHOT;
    TDR00 = _01DE_TAU_TDR00_VALUE;
    TDR02 = _12C0_TAU_TDR02_VALUE;
    TO0 &= (uint16_t)~_0001_TAU_CH0_OUTPUT_VALUE_1;
    TOE0 &= (uint16_t)~_0001_TAU_CH0_OUTPUT_ENABLE;
    /* Set slave channel */
    TOM0 |= _0004_TAU_CH2_SLAVE_OUTPUT;
    TIOS0 &= (uint8_t)~_08_TAU_CH2_OUTPUT_DISABLE;
    TOL0 &= (uint16_t)~_0004_TAU_CH2_OUTPUT_LEVEL_L;
    TO0 &= (uint16_t)~_0004_TAU_CH2_OUTPUT_VALUE_1;
    TOE0 |= _0004_TAU_CH2_OUTPUT_ENABLE;
    /* Set TO02 pin */
    POM1 &= 0x7FU;
    PMCA1 &= 0x7FU;
    CCDE &= 0xFDU;
    P1 &= 0x7FU;
    PM1 &= 0x7FU;

    R_Config_TAU0_0_Create_UserInit();
}

/***********************************************************************************************************************
* Function Name: R_Config_TAU0_0_Start
* Description  : This function starts the TAU0 channel0 counter.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_TAU0_0_Start(void)
{
    TOE0 |= _0004_TAU_CH2_OUTPUT_ENABLE;
    TS0 |= (_0004_TAU_CH2_START_TRG_ON | _0001_TAU_CH0_START_TRG_ON);
}

/***********************************************************************************************************************
* Function Name: R_Config_TAU0_0_Stop
* Description  : This function stops the TAU0 channel0 counter.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_TAU0_0_Stop(void)
{
    TT0 |= (_0004_TAU_CH2_STOP_TRG_ON | _0001_TAU_CH0_STOP_TRG_ON);
    TOE0 &= (uint16_t)~_0004_TAU_CH2_OUTPUT_ENABLE;
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

