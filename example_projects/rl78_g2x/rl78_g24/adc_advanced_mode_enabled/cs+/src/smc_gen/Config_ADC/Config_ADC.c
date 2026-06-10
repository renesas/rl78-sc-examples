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
* File Name        : Config_ADC.c
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
/* Start user code for pragma. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_Config_ADC_Create
* Description  : This function initializes the ADC module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_ADC_Create(void)
{
    ADCEN = 1U;    /* supply AD clock */
    ADMK0 = 1U;    /* disable INTAD0 interrupt */
    ADIF0 = 0U;    /* clear INTAD0 interrupt flag */
    ADMK1 = 1U;    /* disable INTAD1 interrupt */
    ADIF1 = 0U;    /* clear INTAD1 interrupt flag */
    ADMK2 = 1U;    /* disable INTAD2 interrupt */
    ADIF2 = 0U;    /* clear INTAD2 interrupt flag */
    ADMK3 = 1U;    /* disable INTAD3 interrupt */
    ADIF3 = 0U;    /* clear INTAD3 interrupt flag */
    /* Set INTAD0 priority */
    ADPR10 = 1U;
    ADPR00 = 1U;
    /* Set INTAD1 priority */
    ADPR11 = 1U;
    ADPR01 = 1U;
    /* Set INTAD2 priority */
    ADPR12 = 1U;
    ADPR02 = 1U;
    /* Set INTAD3 priority */
    ADPR13 = 1U;
    ADPR03 = 1U;
    /* Set ANI2, ANI3, ANI4, ANI5 pin */
    PMCA2 |= 0x3CU;
    PM2 |= 0x3CU;
    /* Set AVREFP pin */
    PMCA2 |= 0x01U;
    PM2 |= 0x01U;
    /* Set AVREFM pin */
    PMCA2 |= 0x02U;
    PM2 |= 0x02U;
    ADVMOD = 1U;
    ADM0 = _20_AD_CONVERSION_CLOCK_2 | _00_AD_TIME_MODE_NORMAL_1;
    ADM1 = _20_AD_CONVMODE_ONESELECT | _00_AD_FCLK_BETWEEN_4_48;
    ADSPMOD = _01_AD_ADV_SAMPLING_MODE_20;
    ADM2 = _00_AD_AREA_MODE_1 | _02_AD_RESOLUTION_12BIT;
    ADUL = _FF_AD_ADUL_VALUE;
    ADLL = _00_AD_ADLL_VALUE;
    ADS0 = _40_AD_ADV_USE_1ST_SH_CIRCUIT | _04_AD_ADV_INPUT_ANI4;
    ADS1 = _80_AD_ADV_USE_2ND_SH_CIRCUIT;
    ADS2 = _C0_AD_ADV_USE_3RD_SH_CIRCUIT;
    ADS3 = _05_AD_ADV_INPUT_ANI5;
    ADSCTL = _80_AD_ADV_ADS3_ENABLE | _40_AD_ADV_ADS2_ENABLE | _20_AD_ADV_ADS1_ENABLE | _10_AD_ADV_ADS0_ENABLE | 
             _00_AD_ADV_ADS3_PRIOR_LOW | _00_AD_ADV_ADS2_PRIOR_LOW | _00_AD_ADV_ADS1_PRIOR_LOW | 
             _00_AD_ADV_ADS0_PRIOR_LOW;
    ADTR0 = _0B_AD_ADV_TRIGGER_TRD2_AD0;
    ADTR1 = _0B_AD_ADV_TRIGGER_TRD2_AD0;
    ADTR2 = _0B_AD_ADV_TRIGGER_TRD2_AD0;
    ADTR3 = _0F_AD_ADV_TRIGGER_SW;
    ADINTCTL = _80_AD_ADV_INTAD3_ENABLE | _00_AD_ADV_ADS3_FAIL_STORE_DISABLE | _20_AD_ADV_INTAD2_ENABLE | 
               _00_AD_ADV_ADS2_FAIL_STORE_DISABLE | _08_AD_ADV_INTAD1_ENABLE | _00_AD_ADV_ADS1_FAIL_STORE_DISABLE | 
               _02_AD_ADV_INTAD0_ENABLE | _00_AD_ADV_ADS0_FAIL_STORE_DISABLE;
    ADCE = 0U;
    ADM2 |= _20_AD_NEGATIVE_AVREFM;    /* set the (-) side reference voltage */
    ADM2 &= _3F_AD_POSITIVE_CLEAR;    /* clear ADREFP1 and ADREFP0 */
    ADM2 |= _40_AD_POSITIVE_AVREFP;    /* set the (+) side reference voltage */

    R_Config_ADC_Create_UserInit();
}

/***********************************************************************************************************************
* Function Name: R_Config_ADC_Start
* Description  : This function starts the AD converter.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_ADC_Start(void)
{
    ADIF0 = 0U;    /* clear INTAD0 interrupt flag */
    ADMK0 = 0U;    /* enable INTAD0 interrupt */
    ADIF1 = 0U;    /* clear INTAD1 interrupt flag */
    ADMK1 = 0U;    /* enable INTAD1 interrupt */
    ADIF2 = 0U;    /* clear INTAD2 interrupt flag */
    ADMK2 = 0U;    /* enable INTAD2 interrupt */
    ADIF3 = 0U;    /* clear INTAD3 interrupt flag */
    ADMK3 = 0U;    /* enable INTAD3 interrupt */
    ADCS = 1U;    /* enable conversion operation */
}

/***********************************************************************************************************************
* Function Name: R_Config_ADC_Stop
* Description  : This function stops the AD converter.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_ADC_Stop(void)
{
    ADCS = 0U;    /* stop conversion operation */
    ADMK0 = 1U;    /* disable INTAD0 interrupt */
    ADIF0 = 0U;    /* clear INTAD0 interrupt flag */
    ADMK1 = 1U;    /* disable INTAD1 interrupt */
    ADIF1 = 0U;    /* clear INTAD1 interrupt flag */
    ADMK2 = 1U;    /* disable INTAD2 interrupt */
    ADIF2 = 0U;    /* clear INTAD2 interrupt flag */
    ADMK3 = 1U;    /* disable INTAD3 interrupt */
    ADIF3 = 0U;    /* clear INTAD3 interrupt flag */
}

/***********************************************************************************************************************
* Function Name: R_Config_ADC_Set_OperationOn
* Description  : This function enables AD voltage comparator operation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_ADC_Set_OperationOn(void)
{
    volatile uint16_t w_count;

    ADCE = 1U;    /* enable AD comparator */

    /* Reference voltage stability wait time (B) 1us */
    for (w_count = 0U; w_count < AD_WAITTIME_B; w_count++ )
    {
        NOP();
    }
}

/***********************************************************************************************************************
* Function Name: R_Config_ADC_Set_OperationOff
* Description  : This function disables AD voltage comparator operation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_ADC_Set_OperationOff(void)
{
    ADCE = 0U;    /* disable AD comparator */
}

/***********************************************************************************************************************
* Function Name: R_Config_ADC_Set_SoftwareTriggerOn
* Description  : This function generates software trigger.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_ADC_Set_SoftwareTriggerOn(void)
{
    ADTRSWT = 1U;    /* generate software trigger */
}

/***********************************************************************************************************************
* Function Name: R_Config_ADC_ADS0_Get_Result_12bit
* Description  : This function returns the low 12 bits conversion result in the buffer.
* Arguments    : buffer -
*                    the address where to write the conversion result
* Return Value : None
***********************************************************************************************************************/
void R_Config_ADC_ADS0_Get_Result_12bit(uint16_t * const buffer)
{
    *buffer = ADCR0 & 0x0FFFU;
}

/***********************************************************************************************************************
* Function Name: R_Config_ADC_ADS1_Get_Result_12bit
* Description  : This function returns the low 12 bits conversion result in the buffer.
* Arguments    : buffer -
*                    the address where to write the conversion result
* Return Value : None
***********************************************************************************************************************/
void R_Config_ADC_ADS1_Get_Result_12bit(uint16_t * const buffer)
{
    *buffer = ADCR1 & 0x0FFFU;
}

/***********************************************************************************************************************
* Function Name: R_Config_ADC_ADS2_Get_Result_12bit
* Description  : This function returns the low 12 bits conversion result in the buffer.
* Arguments    : buffer -
*                    the address where to write the conversion result
* Return Value : None
***********************************************************************************************************************/
void R_Config_ADC_ADS2_Get_Result_12bit(uint16_t * const buffer)
{
    *buffer = ADCR2 & 0x0FFFU;
}

/***********************************************************************************************************************
* Function Name: R_Config_ADC_ADS3_Get_Result_12bit
* Description  : This function returns the low 12 bits conversion result in the buffer.
* Arguments    : buffer -
*                    the address where to write the conversion result
* Return Value : None
***********************************************************************************************************************/
void R_Config_ADC_ADS3_Get_Result_12bit(uint16_t * const buffer)
{
    *buffer = ADCR3 & 0x0FFFU;
}

/***********************************************************************************************************************
* Function Name: R_Config_ADC_ADS0_Set_ADChannel
* Description  : This function selects analog input channel.
* Arguments    : channel -
*                    analog input channel
* Return Value : status -
*                    MD_OK or MD_ARGERROR
***********************************************************************************************************************/
MD_STATUS R_Config_ADC_ADS0_Set_ADChannel(e_ad_channel_t channel)
{
    MD_STATUS status = MD_OK;

    if (((channel > ADCHANNEL7) && (channel < ADCHANNEL16)) || (channel > ADINTERREFVOLT))
    {
        status = MD_ARGERROR;
    }
    else
    {
        ADS0 &= _C0_AD_ADV_INPUT_CLEAR;
        ADS0 |= (uint8_t)channel;
    }

    return (status);
}

/***********************************************************************************************************************
* Function Name: R_Config_ADC_ADS3_Set_ADChannel
* Description  : This function selects analog input channel.
* Arguments    : channel -
*                    analog input channel
* Return Value : status -
*                    MD_OK or MD_ARGERROR
***********************************************************************************************************************/
MD_STATUS R_Config_ADC_ADS3_Set_ADChannel(e_ad_channel_t channel)
{
    MD_STATUS status = MD_OK;

    if (((channel > ADCHANNEL7) && (channel < ADCHANNEL16)) || (channel > ADINTERREFVOLT))
    {
        status = MD_ARGERROR;
    }
    else
    {
        ADS3 &= _C0_AD_ADV_INPUT_CLEAR;
        ADS3 |= (uint8_t)channel;
    }

    return (status);
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

