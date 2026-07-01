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
* File Name        : Config_DAC1.c
* Component Version: 1.3.0
* Device(s)        : R7F101GLGxFB
* Description      : This file implements device driver for Config_DAC1.
***********************************************************************************************************************/
/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_userdefine.h"
#include "Config_DAC1.h"
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
* Function Name: R_Config_DAC1_Create
* Description  : This function initializes the DAC1 module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_DAC1_Create(void)
{
    DAM0 &= _FD_DA1_CONVERSION_MODE_CLEAR;
    DAM0 |= _00_DA1_CONVERSION_MODE_NORMAL;
    DAM2 = _00_DA_10BITS_MODE;
    DAM1 &= _FD_DA1_ANO1_CLEAR;
    DAM1 |= _00_DA1_ANO1_DISABLE;
    /* Initialize DAC1 configuration */
    DACS1 = _0200_DA1_CONVERSION_VALUE;

    R_Config_DAC1_Create_UserInit();
}

/***********************************************************************************************************************
* Function Name: R_Config_DAC1_Start
* Description  : This function starts the DAC1 module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_DAC1_Start(void)
{
    DACE1 = 1U;  /* start DAC1 conversion */
}

/***********************************************************************************************************************
* Function Name: R_Config_DAC1_Stop
* Description  : This function stops the DAC1 module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_DAC1_Stop(void)
{
    DACE1 = 0U;  /* stop DAC1 conversion */
}

/***********************************************************************************************************************
* Function Name: R_Config_DAC1_Set_ConversionValue_10bit
* Description  : This function sets the 10 bits DAC1 value.
* Arguments    : reg_value -
*                    value of conversion
* Return Value : None
***********************************************************************************************************************/
void R_Config_DAC1_Set_ConversionValue_10bit(uint16_t reg_value)
{
    DACS1 = reg_value & 0x03FF;
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
