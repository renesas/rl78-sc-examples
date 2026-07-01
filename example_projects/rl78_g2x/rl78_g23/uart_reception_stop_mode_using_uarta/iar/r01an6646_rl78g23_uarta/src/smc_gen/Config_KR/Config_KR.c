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
* Copyright (C) 2021, 2022 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
* File Name        : Config_KR.c
* Component Version: 1.1.1
* Device(s)        : R7F100GLGxFA
* Description      : This file implements device driver for Config_KR.
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
#include "Config_KR.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_Config_KR_Create
* Description  : This function initializes the key interrupt module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_KR_Create(void)
{
    volatile uint8_t w_count;

    KRMK = 1U;    /* disable INTKR operation */
    KRIF = 0U;    /* clear INTKR interrupt flag */
    /* Set INTKR Low priority */
    KRPR1 = 1U;
    KRPR0 = 1U;
    /* Set Key return mode register 0 (KRM0) */
    KRM0 = _00_KR0_SIGNAL_DETECT_OFF | _02_KR1_SIGNAL_DETECT_ON | _00_KR2_SIGNAL_DETECT_OFF | 
           _00_KR3_SIGNAL_DETECT_OFF | _00_KR4_SIGNAL_DETECT_OFF | _00_KR5_SIGNAL_DETECT_OFF | 
           _00_KR6_SIGNAL_DETECT_OFF | _00_KR7_SIGNAL_DETECT_OFF;
    /* Set Key return control register (KRCTL) */
    KRCTL = _00_KR_KRCTL_RETURN_UNUSED | _00_KR_KRCTL_EDGE_FALLING;
    /* Change the waiting time according to the system */
    for (w_count = 0U; w_count < KEY_WAITTIME; w_count++)
    {
        NOP();
    }
    /* Set KR1 pin */
    PMCT7 &= 0xFDU;
    PM7 |= 0x02U;

    R_Config_KR_Create_UserInit();
}

/***********************************************************************************************************************
* Function Name: R_Config_KR_Start
* Description  : This function clears INTKR interrupt flag and enables interrupt.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_KR_Start(void)
{
    KRIF = 0U;    /* clear INTKR interrupt flag */
    KRMK = 0U;    /* enable INTKR operation */
}

/***********************************************************************************************************************
* Function Name: R_Config_KR_Stop
* Description  : This function disables INTKR interrupt and clears interrupt flag.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_KR_Stop(void)
{
    KRMK = 1U;    /* disable INTKR operation */
    KRIF = 0U;    /* clear INTKR interrupt flag */
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
