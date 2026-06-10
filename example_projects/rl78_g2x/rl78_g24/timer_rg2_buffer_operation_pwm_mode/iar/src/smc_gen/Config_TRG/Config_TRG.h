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
* File Name        : Config_TRG.h
* Component Version: 1.5.0
* Device(s)        : R7F101GLGxFB
* Description      : This file implements device driver for Config_TRG.
***********************************************************************************************************************/

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_trg.h"

#ifndef CFG_Config_TRG_H
#define CFG_Config_TRG_H

/***********************************************************************************************************************
Macro definitions (Register bit)
***********************************************************************************************************************/

/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/
#define _12BF_TRG_TRGGRA_VALUE                             (0x12BFU)    /* TRG register TRGGRA */
#define _01DF_TRG_TRGGRB_VALUE                             (0x01DFU)    /* TRG register TRGGRB */
#define _01DF_TRG_TRGGRD_VALUE                             (0x01DFU)    /* TRG register TRGGRD */

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Global functions
***********************************************************************************************************************/
void R_Config_TRG_Create (void);
void R_Config_TRG_Start (void);
void R_Config_TRG_Stop (void);
void R_Config_TRG_Create_UserInit (void);
/* Start user code for function. Do not edit comment generated here */

#define DUTY_DEC                (0U)                            /* Duty decrease mode */
#define DUTY_INC                (11U)                           /* Duty increase mode from Duty 0% */
#define DUTY_INC_END            (18U)                           /* Duty increase mode end */

#define PWM_CYCLE               (_12BF_TRG_TRGGRA_VALUE + 1)    /* Value of PWM cycle */
#define PWM_CYCLE_10_STEP       (PWM_CYCLE / 10)                /* 10 steps value of PWM cycle */

#define DUTY_90                 ((PWM_CYCLE_10_STEP * 1) - 1)   /* Duty  90% */
#define DUTY_80                 ((PWM_CYCLE_10_STEP * 2) - 1)   /* Duty  80% */
#define DUTY_70                 ((PWM_CYCLE_10_STEP * 3) - 1)   /* Duty  70% */
#define DUTY_60                 ((PWM_CYCLE_10_STEP * 4) - 1)   /* Duty  60% */
#define DUTY_50                 ((PWM_CYCLE_10_STEP * 5) - 1)   /* Duty  50% */
#define DUTY_40                 ((PWM_CYCLE_10_STEP * 6) - 1)   /* Duty  40% */
#define DUTY_30                 ((PWM_CYCLE_10_STEP * 7) - 1)   /* Duty  30% */
#define DUTY_20                 ((PWM_CYCLE_10_STEP * 8) - 1)   /* Duty  20% */
#define DUTY_10                 ((PWM_CYCLE_10_STEP * 9) - 1)   /* Duty  10% */
#define DUTY_0                  (0xFFFF)                        /* Duty   0% */

/* End user code. Do not edit comment generated here */
#endif


