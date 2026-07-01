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
* File Name        : Config_ITL000_ITL001_ITL012_ITL013_user.c
* Component Version: 1.4.0
* Device(s)        : R7F100GLGxFA
* Description      : This file implements device driver for Config_ITL000_ITL001_ITL012_ITL013.
***********************************************************************************************************************/
/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_userdefine.h"
#include "Config_ITL000_ITL001_ITL012_ITL013.h"
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
* Function Name: R_Config_ITL000_ITL001_ITL012_ITL013_Create_UserInit
* Description  : This function adds user code after initializing the ITL000_ITL001_ITL012_ITL013 channel.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_ITL000_ITL001_ITL012_ITL013_Create_UserInit(void)
{
    /* Start user code for user init. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: R_Config_ITL000_ITL001_ITL012_ITL013_Callback_Shared_Interrupt
* Description  : This function handles the ITL000_ITL001_ITL012_ITL013 shared interrupt.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_ITL000_ITL001_ITL012_ITL013_Callback_Shared_Interrupt(void)
{
    /* Start user code for R_Config_ITL000_ITL001_ITL012_ITL013_Callback_Shared_Interrupt. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}

/* Start user code for adding. Do not edit comment generated here */
/**********************************************************************************************************************
 * Function Name: r_ITL000_ITL001_ITL012_ITL013_set_compare_value
 ******************************************************************************************************************//**
 * @brief Set a 32 bit compare value.
 * @param [in] count  A compare value.
 * @return none
 */
void r_ITL000_ITL001_ITL012_ITL013_set_compare_value(uint32_t count)
{
    ITLCMP00 = count & 0xFFFFU;
    ITLCMP01 = (count >> 16U) & 0xFFFFU;
}
/**********************************************************************************************************************
 * Function Name: r_ITL000_ITL001_ITL012_ITL013_wait_interval_timer
 ******************************************************************************************************************//**
 * @brief Wait for INTITL
 * @param [in] msec  A waiting time in milli second.
 * @return none
 */
void r_ITL000_ITL001_ITL012_ITL013_wait_interval_timer(uint32_t msec)
{
    R_Config_ITL000_ITL001_ITL012_ITL013_Set_OperationMode();
    r_ITL000_ITL001_ITL012_ITL013_set_compare_value(msec * R_MSEC_PER_COUNT);
    ITLMK = 0U;
    R_Config_ITL000_ITL001_ITL012_ITL013_Start();

    /* Wait for INTITL */
    while (!(0x1 & ITLS0))
    {
        NOP();
    }

    R_Config_ITL000_ITL001_ITL012_ITL013_Stop();
}
/* End user code. Do not edit comment generated here */
