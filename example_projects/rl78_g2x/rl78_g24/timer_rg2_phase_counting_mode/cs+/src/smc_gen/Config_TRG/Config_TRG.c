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
* File Name        : Config_TRG.c
* Component Version: 1.0.0
* Device(s)        : R7F101GLGxFB
* Description      : This file implements device driver for Config_TRG.
***********************************************************************************************************************/
/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_userdefine.h"
#include "Config_TRG.h"
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
* Function Name: R_Config_TRG_Create
* Description  : This function initializes the TRG module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_TRG_Create(void)
{
    TRGEN = 1U;     /* enables input clock supply */
    TRGMR0 &= (uint8_t)~_80_TRG_START_COUNT;
    TRGSTR = _02_TRG_COUNT_CONTINUE_ON_MATCH;
    /* Mask TRG clear detection interrupt */
    GCRMK = 1U;    /* disable INTGCR interrupt */
    GCRIF = 0U;    /* clear INTGCR interrupt flag */
    /* Set INTGCR level3 (low) priority */
    GCRPR1 = 1U;
    GCRPR0 = 1U;
    TRGCR = _00_TRG_COUNTER_CLEAR_PROHIBITED;
    TRG = _0000_TRG_VALUE;
    TRGMR0 = _02_TRG_COUNT_TRGCLK_PHASE;
    TRGCNTC = _01_TRG_COUNT_0_ENABLE | _02_TRG_COUNT_1_ENABLE | _04_TRG_COUNT_2_ENABLE | _08_TRG_COUNT_3_ENABLE | 
              _10_TRG_COUNT_4_ENABLE | _20_TRG_COUNT_5_ENABLE | _40_TRG_COUNT_6_ENABLE | _80_TRG_COUNT_7_ENABLE;
    TRGCTL0 = _00_TRG_COUNT_CLEAR_ON_EFFECTIVE_EDGE | _01_TRG_TRGIDZ_INPUT_RISING_EDGE;
    TRGCTL1 = _00_TRG_NOT_CLEAR_ON_TRGGRC_MATCH | _00_TRG_NOT_CLEAR_ON_TRGGRD_MATCH | _00_TRG_TRGPMC_COUNT_STOP;
    TRGIER0 = _00_TRG_OVERFLOW_INT_DISABLE | _00_TRG_UNDERFLOW_INT_DISABLE;
    TRGIER1 = _01_TRG_CLEAR_INT_Z_PHASE_ENABLE;
    /* Set TRGCLKA pin */
    PMCA0 &= 0xFEU;
    PM0 |= 0x01U;
    /* Set TRGCLKB pin */
    PMCA0 &= 0xFDU;
    PM0 |= 0x02U;
    /* Set TRGIDZ pin */
    PMCA12 &= 0xFEU;
    PM12 |= 0x01U;

    R_Config_TRG_Create_UserInit();
}

/***********************************************************************************************************************
* Function Name: R_Config_TRG_Start
* Description  : This function starts the TRG counter.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_TRG_Start(void)
{
    volatile uint8_t trgsr0_dummy;
    volatile uint8_t trgsr1_dummy;

    GCRIF = 0U;    /* clear INTGCR interrupt flag */
    trgsr0_dummy = TRGSR0;    /* read TRGSR0 before write 0 */
    trgsr1_dummy = TRGSR1;    /* read TRGSR1 before write 0 */
    TRGSR0 = 0x00U;
    TRGSR1 = 0x00U;
    GCRMK = 0U;    /* enable INTGCR interrupt */
    TRGMR0 |= _80_TRG_START_COUNT;
}

/***********************************************************************************************************************
* Function Name: R_Config_TRG_Stop
* Description  : This function stops the TRG counter.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_TRG_Stop(void)
{
    volatile uint8_t trgsr0_dummy;
    volatile uint8_t trgsr1_dummy;

    TRGMR0 &= (uint8_t)~_80_TRG_START_COUNT;
    GCRMK = 1U;    /* disable INTGCR interrupt */
    GCRIF = 0U;    /* clear INTGCR interrupt flag */
    trgsr0_dummy = TRGSR0;    /* read TRGSR0 before write 0 */
    trgsr1_dummy = TRGSR1;    /* read TRGSR1 before write 0 */
    TRGSR0 = 0x00U;
    TRGSR1 = 0x00U;
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
