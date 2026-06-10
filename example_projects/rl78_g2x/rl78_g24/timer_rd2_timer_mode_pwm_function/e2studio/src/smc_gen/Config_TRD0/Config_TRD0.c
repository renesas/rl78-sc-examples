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
* File Name        : Config_TRD0.c
* Component Version: 1.5.0
* Device(s)        : R7F101GLGxFB
* Description      : This file implements device driver for Config_TRD0.
***********************************************************************************************************************/
/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_userdefine.h"
#include "Config_TRD0.h"
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
* Function Name: R_Config_TRD0_Create
* Description  : This function initializes the TRD0 module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_TRD0_Create(void)
{
    TRDSTR |= _04_TRD_TRD0_COUNT_CONTINUES;
    TRDSTR &= (uint8_t)~_01_TRD_TRD0_COUNT_START;
    TRDMK0 = 1U;    /* disable TRD0 interrupt */
    TRDIF0 = 0U;    /* clear TRD0 interrupt flag */
    /* Set INTTRD0 low priority */
    TRDPR10 = 1U;
    TRDPR00 = 1U;
    TRDELC &= ~_02_TRD_ELC0_CUTOFF_ENABLE;
    TRDMR &= ~_10_TRD_TRDGRC0_BUFFER;
    TRDMR &= ~_20_TRD_TRDGRD0_BUFFER;
    TRDPMR |= _01_TRD_TRDIOB0_PWM_MODE;
    TRDPMR |= _02_TRD_TRDIOC0_PWM_MODE;
    TRDPMR |= _04_TRD_TRDIOD0_PWM_MODE;
    TRDOER1 &= _F0_TRD_TRD0_OUTPUT_CLEAR;
    TRDOER1 |= (_01_TRD_TRDIOA0_OUTPUT_DISABLE | _00_TRD_TRDIOB0_OUTPUT_ENABLE | _00_TRD_TRDIOC0_OUTPUT_ENABLE | 
               _00_TRD_TRDIOD0_OUTPUT_ENABLE);
    TRDOER2 &= ~_80_TRD_INTP0_CUTOFF_ENABLE;
    TRDOCR &= ~_02_TRD_TRDIOB0_ACTIVE_LEVEL;
    TRDOCR &= ~_04_TRD_TRDIOC0_ACTIVE_LEVEL;
    TRDOCR &= ~_08_TRD_TRDIOD0_ACTIVE_LEVEL;
    TRDCR0 = _00_TRD_INTERNAL_CLOCK_FTRD1 | _20_TRD_COUNTER_CLEAR_TRDGRA;
    TRDIER0 = _01_TRD_IMIA_ENABLE | _00_TRD_IMIB_DISABLE | _00_TRD_IMIC_DISABLE | _00_TRD_IMID_DISABLE | 
              _00_TRD_OVIE_DISABLE;
    TRDPOCR0 = _01_TRD_TRDIOB_OUTPUT_ACTIVE_H | _02_TRD_TRDIOC_OUTPUT_ACTIVE_H | _04_TRD_TRDIOD_OUTPUT_ACTIVE_H;
    TRDGRA0 = _257F_TMRD_TRDGRA0_VALUE;
    TRDGRB0 = _095F_TMRD_TRDGRB0_VALUE;
    TRDGRC0 = _12BF_TMRD_TRDGRC0_VALUE;
    TRDGRD0 = _1C1F_TMRD_TRDGRD0_VALUE;
    /* Set TRDIOB0 pin */
    POM1 &= 0xDFU;
    PMCA1 &= 0xDFU;
    P1 &= 0xDFU;
    PM1 &= 0xDFU;
    /* Set TRDIOC0 pin */
    PMCA1 &= 0xBFU;
    CCDE &= 0xFEU;
    P1 &= 0xBFU;
    PM1 &= 0xBFU;
    /* Set TRDIOD0 pin */
    POM1 &= 0xEFU;
    PMCA1 &= 0xEFU;
    P1 &= 0xEFU;
    PM1 &= 0xEFU;

    R_Config_TRD0_Create_UserInit();
}

/***********************************************************************************************************************
* Function Name: R_Config_TRD0_Start
* Description  : This function starts the TRD0 counter.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_TRD0_Start(void)
{
    volatile uint8_t trdsr_dummy;
    TRDIF0 = 0U;    /* clear TMRD0 interrupt flag */
    trdsr_dummy = TRDSR0; /* read TRDSR0 before write 0 */
    TRDSR0 = 0x00U; /* clear TRD0 each interrupt request */
    TRDMK0 = 0U;    /* enable TMRD0 interrupt */
    TRDSTR |= _04_TRD_TRD0_COUNT_CONTINUES;
    TRDSTR |= _01_TRD_TRD0_COUNT_START;    /* start TMRD counter */
}

/***********************************************************************************************************************
* Function Name: R_Config_TRD0_Stop
* Description  : This function stops the TRD0 counter.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_TRD0_Stop(void)
{
    volatile uint8_t trdsr_dummy;
    TRDSTR |= _04_TRD_TRD0_COUNT_CONTINUES;
    TRDSTR &= (uint8_t)~_01_TRD_TRD0_COUNT_START;    /* stop TMRD0 counter */
    TRDMK0 = 1U;    /* disable TMRD0 interrupt */
    TRDIF0 = 0U;    /* clear TMRD0 interrupt flag */
    trdsr_dummy = TRDSR0; /* read TRDSR0 before write 0 */
    TRDSR0  = 0x00U; /* clear TRD0 each interrupt request */
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
