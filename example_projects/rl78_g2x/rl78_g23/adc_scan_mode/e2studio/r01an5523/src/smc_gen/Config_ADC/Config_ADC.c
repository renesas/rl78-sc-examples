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
* Component Version: 1.4.1
* Device(s)        : R7F100GLGxFB
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
    ADMK = 1U;    /* disable INTAD interrupt */
    ADIF = 0U;    /* clear INTAD interrupt flag */
    /* Set INTAD priority */
    ADPR1 = 1U;
    ADPR0 = 1U;
    /* Set ANI2, ANI3, ANI4, ANI5 pin */
    PMCA2 |= 0x3CU;
    PM2 |= 0x3CU;
    ADM0 = _40_AD_OPERMODE_SCAN | _28_AD_CONVERSION_CLOCK_1 | _00_AD_TIME_MODE_NORMAL_1;
    ADM1 = _00_AD_TRIGGER_SOFTWARE | _00_AD_FCLK_BETWEEN_4_32 | _00_AD_CONVMODE_CONSELECT;
    ADM2 = _00_AD_NEGATIVE_VSS | _00_AD_AREA_MODE_1 | _02_AD_RESOLUTION_12BIT;
    ADUL = _FF_AD_ADUL_VALUE;
    ADLL = _00_AD_ADLL_VALUE;
    ADS = _02_AD_INPUT_CHANNEL_2_5;
    ADM2 &= _3F_AD_POSITIVE_CLEAR;    /* clear ADREFP1 and ADREFP0 */
    ADM2 |= _00_AD_POSITIVE_VDD;    /* set the reference voltage */

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
    ADIF = 0U;    /* clear INTAD interrupt flag */
    ADMK = 0U;    /* enable INTAD interrupt */
    ADCS = 1U;    /* enables conversion operation */
}

/***********************************************************************************************************************
* Function Name: R_Config_ADC_Stop
* Description  : This function stops the AD converter.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_ADC_Stop(void)
{
    ADCS = 0U;    /* stops conversion operation */
    ADMK = 1U;    /* disables INTAD interrupt */
    ADIF = 0U;    /* clear INTAD interrupt flag */
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
    for (w_count = 0U; w_count < AD_WAITTIME_B; w_count++)
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
* Function Name: R_Config_ADC_Set_SnoozeOn
* Description  : This function enables AD wakeup function.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_ADC_Set_SnoozeOn(void)
{
    AWC = 1U;    /* use wakeup function */
}

/***********************************************************************************************************************
* Function Name: R_Config_ADC_Set_SnoozeOff
* Description  : This function disables AD wakeup function.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_ADC_Set_SnoozeOff(void)
{
    AWC = 0U;    /* stop wakeup function */
}

/***********************************************************************************************************************
* Function Name: R_Config_ADC_Get_Result_12bit
* Description  : This function returns the low 12 bits conversion result in the buffer.
* Arguments    : buffer -
*                    the address where to write the conversion result
* Return Value : None
***********************************************************************************************************************/
void R_Config_ADC_Get_Result_12bit(uint16_t * const buffer)
{
    buffer[0] = ADCR0 & 0x0FFFU;
    buffer[1] = ADCR1 & 0x0FFFU;
    buffer[2] = ADCR2 & 0x0FFFU;
    buffer[3] = ADCR3 & 0x0FFFU;
}

/***********************************************************************************************************************
* Function Name: R_Config_ADC_Set_ADChannel
* Description  : This function selects analog input channel.
* Arguments    : channel -
*                    analog input channel
* Return Value : status -
*                    MD_OK or MD_ARGERROR
***********************************************************************************************************************/
MD_STATUS R_Config_ADC_Set_ADChannel(e_ad_channel_t channel)
{
    MD_STATUS status = MD_OK;

    if (((channel > ADCHANNEL7) && (channel < ADCHANNEL16)) || ((channel > ADCHANNEL19) && (channel != ADTSCAP)
        && (channel < ADTEMPERSENSOR0)) || (channel > ADINTERREFVOLT))
    {
        status = MD_ARGERROR;
    }
    else
    {
        ADS = (uint8_t)channel;
    }

    return (status);
}

/***********************************************************************************************************************
* Function Name: R_Config_ADC_Set_TestChannel
* Description  : This function sets test function.
* Arguments    : channel -
*                    sets test channel
* Return Value : status -
*                    MD_OK or MD_ARGERROR
***********************************************************************************************************************/
MD_STATUS R_Config_ADC_Set_TestChannel(e_test_channel_t channel)
{
    MD_STATUS status = MD_OK;

    if ((1U == channel) || (4U <= channel))
    {
        status = MD_ARGERROR;
    }
    else
    {
        ADTES = (uint8_t)channel;
    }

    return (status);
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
