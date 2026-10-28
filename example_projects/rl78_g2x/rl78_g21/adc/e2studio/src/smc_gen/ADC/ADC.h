/*
* Copyright (c) 2021 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
* File Name        : ADC.h
* Component Version: 1.10.0
* Device(s)        : R7F103GLJxFB
* Description      : This file implements device driver for ADC.
***********************************************************************************************************************/

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_ad.h"

#ifndef CFG_ADC_H
#define CFG_ADC_H

/***********************************************************************************************************************
Macro definitions (Register bit)
***********************************************************************************************************************/

/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/
/* Upper bound (ADUL) value */
#define _32_AD_ADUL_VALUE               (0x32U)
/* Lower bound (ADLL) value */
#define _0A_AD_ADLL_VALUE               (0x0AU)
#define AD_WAITTIME_B                   (2U)    /* wait for 1us as default,
                                                   please change the waiting time value according to the system */

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/
typedef enum
{
    ADCHANNEL0, ADCHANNEL1, ADCHANNEL2, ADCHANNEL3, ADCHANNEL4, ADCHANNEL5, ADCHANNEL6, ADCHANNEL7,
    ADCHANNEL16 = 16U, ADCHANNEL17, ADCHANNEL18, ADCHANNEL19, ADTEMPERSENSOR0 = 128U, ADINTERREFVOLT
} e_ad_channel_t;
typedef enum
{
    ADNORMALINPUT,
    ADAVREFM = 2U,
    ADAVREFP
} e_test_channel_t;

/***********************************************************************************************************************
Global functions
***********************************************************************************************************************/
void R_ADC_Create (void);
void R_ADC_Start (void);
void R_ADC_Stop (void);
void R_ADC_Set_OperationOn (void);
void R_ADC_Set_OperationOff (void);
void R_ADC_Set_SnoozeOn (void);
void R_ADC_Set_SnoozeOff (void);
void R_ADC_Get_Result_10bit (uint16_t * const buffer);
MD_STATUS R_ADC_Set_ADChannel (e_ad_channel_t channel);
MD_STATUS R_ADC_Set_TestChannel (e_test_channel_t channel);
void R_ADC_Create_UserInit (void);
/* Start user code for function. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#endif
