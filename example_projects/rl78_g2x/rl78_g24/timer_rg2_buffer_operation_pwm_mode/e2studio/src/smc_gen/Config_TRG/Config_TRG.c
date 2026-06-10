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
* Component Version: 1.5.0
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
    TRGEN = 1U;
    TRGSTR |= _02_TRG_COUNT_CONTINUE_ON_MATCH;
    TRGMR0 &= (uint8_t)~_80_TRG_START_COUNT;    /* disable TRG operation */
    TRGMK = 1U;    /* disable TRG interrupt */
    TRGIF = 0U;    /* clear TRG interrupt flag */
    /* Set INTTRG low priority */
    TRGPR1 = 1U;
    TRGPR0 = 1U;
    TRGCR = _20_TRG_COUNTER_CLEAR_TRGGRA | _00_TRG_COUNT_SOURCE_FCLK;
    TRGIER0 = _01_TRG_CAPTURE_COMPARE_A_INT_ENABLE | _00_TRG_CAPTURE_COMPARE_B_INT_DISABLE | 
              _00_TRG_OVERFLOW_INT_DISABLE;
    TRGIOR = _80_TRG_TRGGRD_BUFFER | _00_TRG_TRGGRC_GENERAL;
    TRGGRA = _12BF_TRG_TRGGRA_VALUE;
    TRGGRB = _01DF_TRG_TRGGRB_VALUE;
    TRGGRD = _01DF_TRG_TRGGRD_VALUE;
    TRGMR0 = _00_TRG_STOP_COUNT | _01_TRG_PWM_MODE;
    /* Set TRGIOA pin */
    POM1 &= 0x7FU;
    PMCA1 &= 0x7FU;
    CCDE &= 0xFDU;
    P1 &= 0x7FU;
    PM1 &= 0x7FU;

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
    volatile uint8_t trgsr_dummy;

    TRGIF = 0U;    /* clear TRG interrupt flag */
    trgsr_dummy = TRGSR0;    /* read TRGSR0 before write 0 */
    TRGSR0 = 0x00U;    /* clear TRG each interrupt request */
    TRGMK = 0U;    /* enable TRG interrupt */
    TRGSTR |= _02_TRG_COUNT_CONTINUE_ON_MATCH;
    TRGMR0 |= _80_TRG_START_COUNT;    /* start TRG counter */
}

/***********************************************************************************************************************
* Function Name: R_Config_TRG_Stop
* Description  : This function stops the TRG counter.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_TRG_Stop(void)
{
    volatile uint8_t trgsr_dummy;

    TRGSTR |= _02_TRG_COUNT_CONTINUE_ON_MATCH;
    TRGMR0 &= (uint8_t)~_80_TRG_START_COUNT;    /* stop TRG counter */
    TRGMK = 1U;    /* disable TRG interrupt */
    TRGIF = 0U;    /* clear TRG interrupt flag */
    trgsr_dummy = TRGSR0;    /* read TRGSR0 before write 0 */
    TRGSR0 = 0x00U;    /* clear TRG each interrupt request */
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

