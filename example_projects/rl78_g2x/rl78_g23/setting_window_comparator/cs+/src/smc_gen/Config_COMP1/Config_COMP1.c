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
* File Name    : Config_COMP1.c
* Version      : 1.0.0
* Device(s)    : R7F100GLGxFA
* Description  : This file implements device driver for Config_COMP1.
* Creation Date: 2021-06-01
***********************************************************************************************************************/
/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_userdefine.h"
#include "Config_COMP1.h"
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
* Function Name: R_Config_COMP1_Create
* Description  : This function initializes the comparator 1 module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_COMP1_Create(void)
{
    C1ENB = 0U;    /* disable comparator channel 1 operation */
    /* Set IVCMP1 pin */
    PMCA12 |= 0x01U;
    PM12 |= 0x01U;
    COMPOCR &= _0F_COMP1_COMPOCR_CLEAR;
    COMPOCR |= _00_COMP_SPEED_LOW;    /* set low speed mode */
    COMPMDR &= _0F_COMP1_COMPMDR_CLEAR;
    COMPMDR |= (_40_COMP1_REFERENCE_VOLTAGE_DA_OUTPUT0 | _20_COMP1_14_TO_VDD);
    COMPFIR &= _0F_COMP1_COMPFIR_CLEAR;
    COMPFIR |= (_80_COMP1_BOTH_EDGES_INTERRUPT | _30_COMP1_FILTER_FCLK_32);
    COMPOCR |= (_10_COMP1_INTERRPUT_ENABLE);
    /* Set INTCMP1 low priority */
    CMPPR11 = 1U;
    CMPPR01 = 1U;
    CMPMK1 = 1U;    /* disable INTCMP1 interrupt */
    CMPIF1 = 0U;    /* clear INTCMP1 interrupt flag */

    R_Config_COMP1_Create_UserInit();
}

/***********************************************************************************************************************
* Function Name: R_Config_COMP1_Start
* Description  : This function starts the comparator 1.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_COMP1_Start(void)
{
    volatile uint16_t w_count;

    C1ENB = 1U;    /* enable comparator 1 operation */

    /* Change the waiting time according to the system */
    for(w_count = 0U; w_count < COMP_WAIT_TIME; w_count++)
    {
        NOP();
    }
    CMPIF1 = 0U;    /* clear INTCMP1 interrupt flag */
    CMPMK1 = 0U;    /* enable INTCMP1 interrupt */
}

/***********************************************************************************************************************
* Function Name: R_Config_COMP1_Stop
* Description  : This function stops the comparator 1.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_COMP1_Stop(void)
{
    C1ENB = 0U;     /* disable comparator 1 operation */
    CMPMK1 = 1U;    /* disable INTCMP1 interrupt */
    CMPIF1 = 0U;    /* clear INTCMP1 interrupt flag */
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
