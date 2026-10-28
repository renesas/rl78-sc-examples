/*
* Copyright (c) 2021 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
* File Name        : ADC.c
* Component Version: 1.10.0
* Device(s)        : R7F100GSNxFB
* Description      : This file implements device driver for ADC.
***********************************************************************************************************************/
/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_userdefine.h"
#include "ADC.h"
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
* Function Name: R_ADC_Create
* Description  : This function initializes the ADC module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_ADC_Create(void)
{
    uint8_t temp;

    ADCEN = 1U;    /* supply AD clock */
    ADMK = 1U;    /* disable INTAD interrupt */
    ADIF = 0U;    /* clear INTAD interrupt flag */
    /* Set INTAD priority */
    ADPR1 = 0U;
    ADPR0 = 0U;
    /* Set ANI2 pin */
    PMCA2 |= 0x04U;
    PMCT2 &= 0xFBU;
    PM2 |= 0x04U;
    ADM0 = _00_AD_OPERMODE_SELECT | _08_AD_CONVERSION_CLOCK_16 | _04_AD_TIME_MODE_LOWVOLTAGE_1;
    ADM1 = _00_AD_TRIGGER_SOFTWARE | _00_AD_FCLK_BETWEEN_4_32 | _20_AD_CONVMODE_ONESELECT;
    ADM2 = _00_AD_NEGATIVE_VSS | _08_AD_AREA_MODE_2_3 | _02_AD_RESOLUTION_12BIT;
    ADUL = _32_AD_ADUL_VALUE;
    ADLL = _0A_AD_ADLL_VALUE;
    ADS = _02_AD_INPUT_CHANNEL_2;
    temp = ADM2;
    temp &= _3F_AD_POSITIVE_CLEAR;    /* clear ADREFP1 and ADREFP0 */
    temp |= _00_AD_POSITIVE_VDD;    /* set the reference voltage */
    ADM2 = temp;

    R_ADC_Create_UserInit();
}

/***********************************************************************************************************************
* Function Name: R_ADC_Start
* Description  : This function starts the AD converter.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_ADC_Start(void)
{
    ADIF = 0U;    /* clear INTAD interrupt flag */
    ADMK = 0U;    /* enable INTAD interrupt */
    ADCS = 1U;    /* enables conversion operation */
}

/***********************************************************************************************************************
* Function Name: R_ADC_Stop
* Description  : This function stops the AD converter.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_ADC_Stop(void)
{
    ADCS = 0U;    /* stops conversion operation */
    ADMK = 1U;    /* disables INTAD interrupt */
    ADIF = 0U;    /* clear INTAD interrupt flag */
}

/***********************************************************************************************************************
* Function Name: R_ADC_Set_OperationOn
* Description  : This function enables AD voltage comparator operation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_ADC_Set_OperationOn(void)
{
    volatile uint16_t w_count;

    ADCE = 1U;    /* enable AD comparator */

    /* Reference voltage stability wait time (B) 1us + 2 cycles fAD */
    for (w_count = 0U; w_count < AD_WAITTIME_B; w_count++)
    {
        NOP();
    }
}

/***********************************************************************************************************************
* Function Name: R_ADC_Set_OperationOff
* Description  : This function disables AD voltage comparator operation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_ADC_Set_OperationOff(void)
{
    ADCE = 0U;    /* disable AD comparator */
}

/***********************************************************************************************************************
* Function Name: R_ADC_Set_SnoozeOn
* Description  : This function enables AD wakeup function.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_ADC_Set_SnoozeOn(void)
{
    AWC = 1U;    /* use wakeup function */
}

/***********************************************************************************************************************
* Function Name: R_ADC_Set_SnoozeOff
* Description  : This function disables AD wakeup function.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_ADC_Set_SnoozeOff(void)
{
    AWC = 0U;    /* stop wakeup function */
}

/***********************************************************************************************************************
* Function Name: R_ADC_Get_Result_12bit
* Description  : This function returns the low 12 bits conversion result in the buffer.
* Arguments    : buffer -
*                    the address where to write the conversion result
* Return Value : None
***********************************************************************************************************************/
void R_ADC_Get_Result_12bit(uint16_t * const buffer)
{
    *buffer = ADCR0 & 0x0FFFU;
}

/***********************************************************************************************************************
* Function Name: R_ADC_Set_ADChannel
* Description  : This function selects analog input channel.
* Arguments    : channel -
*                    analog input channel
* Return Value : status -
*                    MD_OK or MD_ARGERROR
***********************************************************************************************************************/
MD_STATUS R_ADC_Set_ADChannel(e_ad_channel_t channel)
{
    MD_STATUS status = MD_OK;

    if (((channel > ADCHANNEL14) && (channel < ADCHANNEL16)) || ((channel > ADCHANNEL26) && (channel != ADTSCAP)
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
* Function Name: R_ADC_Set_TestChannel
* Description  : This function sets test function.
* Arguments    : channel -
*                    sets test channel
* Return Value : status -
*                    MD_OK or MD_ARGERROR
***********************************************************************************************************************/
MD_STATUS R_ADC_Set_TestChannel(e_test_channel_t channel)
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
