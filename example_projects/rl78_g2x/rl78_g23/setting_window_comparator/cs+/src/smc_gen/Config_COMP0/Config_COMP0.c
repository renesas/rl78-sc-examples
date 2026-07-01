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
* Copyright (C) 2020 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
* File Name    : Config_COMP0.c
* Version      : 1.0.0
* Device(s)    : R7F100GLGxFA
* Description  : This file implements device driver for Config_COMP0.
* Creation Date: 2021-06-01
***********************************************************************************************************************/
/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_userdefine.h"
#include "Config_COMP0.h"
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
* Function Name: R_Config_COMP0_Create
* Description  : This function initializes the comparator 0 module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_COMP0_Create(void)
{
    C0ENB = 0U;    /* disable comparator channel 0 operation */
    /* Set IVCMP0 pin */
    PMCA14 |= 0x80U;
    PM14 |= 0x80U;
    COMPOCR &= _78_COMP0_COMPOCR_CLEAR;
    COMPOCR |= _00_COMP_SPEED_LOW;    /* set low speed mode */
    COMPMDR &= _F0_COMP0_COMPMDR_CLEAR;
    COMPMDR |= (_04_COMP0_REFERENCE_VOLTAGE_INTERNAL | _02_COMP0_14_TO_VDD);
    COMPFIR &= _F0_COMP0_COMPFIR_CLEAR;
    COMPFIR |= (_08_COMP0_BOTH_EDGES_INTERRUPT | _03_COMP0_FILTER_FCLK_32);
    COMPOCR |= (_00_COMP0_OUTPUT_NORMAL | _02_COMP0_OUTPUT_ENABLE);
    /* Set VCOUT0 pin */
    PMCT3 &= 0xFEU;
    P3 &= 0xFEU;
    PM3 &= 0xFEU;

    R_Config_COMP0_Create_UserInit();
}

/***********************************************************************************************************************
* Function Name: R_Config_COMP0_Start
* Description  : This function starts the comparator 0.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_COMP0_Start(void)
{
    volatile uint16_t w_count;

    C0ENB = 1U;    /* enable comparator 0 operation */

    /* Change the waiting time according to the system */
    for(w_count = 0U; w_count < COMP_WAIT_TIME; w_count++)
    {
        NOP();
    }
}

/***********************************************************************************************************************
* Function Name: R_Config_COMP0_Stop
* Description  : This function stops the comparator 0.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_COMP0_Stop(void)
{
    C0ENB = 0U;     /* disable comparator 0 operation */
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
