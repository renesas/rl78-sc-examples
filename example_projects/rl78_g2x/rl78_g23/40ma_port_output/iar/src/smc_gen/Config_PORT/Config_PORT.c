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
* File Name    : Config_PORT.c
* Version      : 1.0.0
* Device(s)    : R7F100GBGxFP
* Description  : This file implements device driver for Config_PORT.
* Creation Date: 2021-10-25
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
#include "Config_PORT.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_Config_PORT_Create
* Description  : This function initializes the port I/O.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_PORT_Create(void)
{
    volatile uint16_t w_count;

    CCDE = _00_P17_OUTPUT_CURRENT_OFF | _00_P16_OUTPUT_CURRENT_OFF;

    /* Wait for stable time (10us) */
    for (w_count = 0U; w_count < PORT_STABLE_WAITTIME; w_count++)
    {
        NOP();
    }
 
    /* Set PORT1 registers */
    P1 = _80_Pn7_OUTPUT_1 | _00_Pn6_OUTPUT_0 | _00_Pn5_OUTPUT_0 | _00_Pn4_OUTPUT_0 | _00_Pn3_OUTPUT_0 | 
         _00_Pn2_OUTPUT_0 | _00_Pn1_OUTPUT_0 | _00_Pn0_OUTPUT_0;
    POM1 = _00_POMn7_NCH_OFF | _00_POMn5_NCH_OFF | _00_POMn4_NCH_OFF | _00_POMn3_NCH_OFF | _00_POMn2_NCH_OFF | 
           _00_POMn1_NCH_OFF | _00_POMn0_NCH_OFF;
    PMCA1 = _F7_PMCA1_DEFAULT | _08_PMCAn3_NOT_USE;
    PMCE1 = _00_PMCEn7_DIGITAL_ON | _00_PMCEn6_NOT_USE | _00_PMCEn5_NOT_USE | _00_PMCEn4_NOT_USE | 
            _00_PMCEn3_NOT_USE | _00_PMCEn2_NOT_USE | _00_PMCEn1_NOT_USE | _00_PMCEn0_NOT_USE;
    PM1 = _00_PMn7_MODE_OUTPUT | _40_PMn6_NOT_USE | _20_PMn5_NOT_USE | _10_PMn4_NOT_USE | _08_PMn3_NOT_USE | 
          _04_PMn2_NOT_USE | _02_PMn1_NOT_USE | _01_PMn0_NOT_USE;
    /* Set PORT13 registers */
    PDIDIS13 = _00_PDIDISn7_INPUT_BUFFER_ON;

    R_Config_PORT_Create_UserInit();
}

/***********************************************************************************************************************
* Function Name: R_Config_PORT_ReadDigitalOutputLevel
* Description  : This function specifies the output level on a port pin is read when the pin is in output mode.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_PORT_ReadDigitalOutputLevel(void)
{
    PMS = _01_DIGITAL_OUTPUT_LEVEL;
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
