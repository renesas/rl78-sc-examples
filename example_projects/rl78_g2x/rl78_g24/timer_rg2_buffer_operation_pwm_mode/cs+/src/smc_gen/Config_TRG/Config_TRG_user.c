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
* File Name        : Config_TRG_user.c
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
#pragma interrupt r_Config_TRG_interrupt(vect=INTTRG)
/* Start user code for pragma. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
uint8_t        g_duty_mode     = 2U;
uint8_t        g_trgsr0_dummy  = 0x00;
const uint16_t g_trggrd_tbl[]  =
{
        DUTY_90,                                 /* Duty  90% */
        DUTY_80,                                 /* Duty  80% */
        DUTY_70,                                 /* Duty  70% */
        DUTY_60,                                 /* Duty  60% */
        DUTY_50,                                 /* Duty  50% */
        DUTY_40,                                 /* Duty  40% */
        DUTY_30,                                 /* Duty  30% */
        DUTY_20,                                 /* Duty  20% */
        DUTY_10,                                 /* Duty  10% */
        DUTY_0,                                  /* Duty   0% */
        DUTY_10,                                 /* Duty  10% */
        DUTY_20,                                 /* Duty  20% */
        DUTY_30,                                 /* Duty  30% */
        DUTY_40,                                 /* Duty  40% */
        DUTY_50,                                 /* Duty  50% */
        DUTY_60,                                 /* Duty  60% */
        DUTY_70,                                 /* Duty  70% */
        DUTY_80                                  /* Duty  80% */
};

/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_Config_TRG_Create_UserInit
* Description  : This function adds user code after initializing the TRG.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_TRG_Create_UserInit(void)
{
/* Start user code for user init. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_Config_TRG_interrupt
* Description  : This function is INTTRG interrupt service routine.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
static void __near r_Config_TRG_interrupt(void)
{
/* Start user code for r_Config_TRG_interrupt. Do not edit comment generated here */

    g_trgsr0_dummy  = TRGSR0;                   /* Read TRGSR0 resister */
    TRGSR0         &= (~0x01);                  /* Clear TRGIMFA */

    if (DUTY_INC == g_duty_mode)                /* Return from duty 0% ? */
    {
        TRGGRB = g_trggrd_tbl[g_duty_mode - 1]; /* TRGGRB value setting */
    }
    if (DUTY_INC_END == g_duty_mode)            /* Reach the end of g_trggrd_tbl array ? */
    {
        g_duty_mode = DUTY_DEC;                 /* Set 0 to g_duty_mode */
    }
    TRGGRD = g_trggrd_tbl[g_duty_mode];         /* The value of TRGGRD is changed */

    g_duty_mode++;                              /* Duty mode Increment */

/* End user code. Do not edit comment generated here */
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

