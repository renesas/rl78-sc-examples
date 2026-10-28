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
* Copyright (C) 2021, 2025 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
* File Name        : Config_IT01.c
* Component Version: 1.7.0
* Device(s)        : R7F100LPLxFA
* Description      : This file implements device driver for Config_IT01.
***********************************************************************************************************************/
/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_userdefine.h"
#include "Config_IT01.h"
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
* Function Name: R_Config_IT01_Create
* Description  : This function initializes the IT0 channel 1 module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_IT01_Create(void)
{
    /* Stop the IT0 channel 1 */
    TSTART01 = 0U;
    /* Mask channel 1 interrupt */
    ITMK01 = 1U;    /* disable INTIT01 interrupt */
    ITIF01 = 0U;    /* clear INTIT01 interrupt flag */
    /* Set INTIT01 low priority */
    ITPR101 = 1U;
    ITPR001 = 1U;
    TRTCR0 &= (uint8_t)~_80_IT8BIT_16BIT_COUNT_MODE;
    TRTMD0 &= (uint8_t)~_70_IT8BIT_CLOCK1_CLEAR;
    TRTMD0 |= _50_IT8BIT_CLOCK1_32;
    TRTCMP01 = _FF_IT8BIT_TRTCMP01_VALUE;
    
    R_Config_IT01_Create_UserInit();
}

/***********************************************************************************************************************
* Function Name: R_Config_IT01_Start
* Description  : This function starts the IT0 channel 1 counter.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_IT01_Start(void)
{
    ITIF01 = 0U;    /* clear INTIT01 interrupt flag */
    ITMK01 = 0U;    /* enable INTIT01 interrupt */
    TSTART01 = 1U;
}

/***********************************************************************************************************************
* Function Name: R_Config_IT01_Stop
* Description  : This function stops the IT0 channel 1 counter.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_IT01_Stop(void)
{
    TSTART01 = 0U;
    /* Mask channel 1 interrupt */
    ITMK01 = 1U;    /* disable INTIT01 interrupt */
    ITIF01 = 0U;    /* clear INTIT01 interrupt flag */
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
