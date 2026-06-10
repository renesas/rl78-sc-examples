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
* File Name        : Config_ADC_user.c
* Component Version: 1.4.0
* Device(s)        : R7F101GLGxFB
* Description      : This file implements device driver for Config_ADC.
***********************************************************************************************************************/
/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_userdefine.h"
#include "Config_ADC.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Pragma directive
***********************************************************************************************************************/
#pragma interrupt r_Config_ADC_ad0_interrupt(vect=INTAD0)
#pragma interrupt r_Config_ADC_ad1_interrupt(vect=INTAD1)
#pragma interrupt r_Config_ADC_ad2_interrupt(vect=INTAD2)
#pragma interrupt r_Config_ADC_ad3_interrupt(vect=INTAD3)
/* Start user code for pragma. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
uint16_t g_result_buffer0 = 0U;    /* AD converter result buffer0 */
uint16_t g_result_buffer1 = 0U;    /* AD converter result buffer1 */
uint16_t g_result_buffer2 = 0U;    /* AD converter result buffer2 */
uint16_t g_result_buffer3 = 0U;    /* AD converter result buffer3 */

/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_Config_ADC_Create_UserInit
* Description  : This function adds user code after initializing the AD converter.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_ADC_Create_UserInit(void)
{
    /* Start user code for user init. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_Config_ADC_ad0_interrupt
* Description  : This function is INTAD0 interrupt service routine.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
static void __near r_Config_ADC_ad0_interrupt(void)
{
    ADIF0 = 0U;    /* clear INTAD0 interrupt flag */
    ADINTST &= (uint8_t)~_02_AD_ADV_ADS0_CONV_COMPLETE;
    /* Start user code for r_Config_ADC_ad0_interrupt. Do not edit comment generated here */
    R_Config_ADC_ADS0_Get_Result_12bit(&g_result_buffer0);    /* Get result */
    ADINTST &= (~0x01U);    /* Clear ADINTST0F */

    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_Config_ADC_ad1_interrupt
* Description  : This function is INTAD1 interrupt service routine.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
static void __near r_Config_ADC_ad1_interrupt(void)
{
    ADIF1 = 0U;    /* clear INTAD1 interrupt flag */
    ADINTST &= (uint8_t)~_08_AD_ADV_ADS1_CONV_COMPLETE;
    /* Start user code for r_Config_ADC_ad1_interrupt. Do not edit comment generated here */
    R_Config_ADC_ADS1_Get_Result_12bit(&g_result_buffer1);    /* Get result */
    ADINTST &= (~0x04U);    /* Clear ADINTST1F */

    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_Config_ADC_ad2_interrupt
* Description  : This function is INTAD2 interrupt service routine.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
static void __near r_Config_ADC_ad2_interrupt(void)
{
    ADIF2 = 0U;    /* clear INTAD2 interrupt flag */
    ADINTST &= (uint8_t)~_20_AD_ADV_ADS2_CONV_COMPLETE;
    /* Start user code for r_Config_ADC_ad2_interrupt. Do not edit comment generated here */
    R_Config_ADC_ADS2_Get_Result_12bit(&g_result_buffer2);    /* Get result */
    ADINTST       &= (~0x10U);    /* Clear ADINTST2F */
    g_sampling_flg = 0U;

    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_Config_ADC_ad3_interrupt
* Description  : This function is INTAD3 interrupt service routine.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
static void __near r_Config_ADC_ad3_interrupt(void)
{
    ADIF3 = 0U;    /* clear INTAD3 interrupt flag */
    ADINTST &= (uint8_t)~_80_AD_ADV_ADS3_CONV_COMPLETE;
    /* Start user code for r_Config_ADC_ad3_interrupt. Do not edit comment generated here */
    R_Config_ADC_ADS3_Get_Result_12bit(&g_result_buffer3);    /* Get result */
    ADINTST &= (~0x40U);    /* Clear ADINTST3F */

    /* End user code. Do not edit comment generated here */
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

