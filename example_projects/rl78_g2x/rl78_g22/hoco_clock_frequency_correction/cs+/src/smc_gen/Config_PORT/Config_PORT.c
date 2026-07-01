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
* File Name        : Config_PORT.c
* Component Version: 1.4.0
* Device(s)        : R7F102GGExFB
* Description      : This file implements device driver for Config_PORT.
***********************************************************************************************************************/
/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_userdefine.h"
#include "Config_PORT.h"
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
* Function Name: R_Config_PORT_Create
* Description  : This function initializes the port I/O.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_PORT_Create(void)
{
    /* Set PORT1 registers */
    PU1 = _80_PUn7_PULLUP_ON | _00_PUn6_PULLUP_OFF | _00_PUn5_PULLUP_OFF | _00_PUn4_PULLUP_OFF | _00_PUn3_PULLUP_OFF | 
          _00_PUn2_PULLUP_OFF | _00_PUn1_PULLUP_OFF | _00_PUn0_PULLUP_OFF;
    PIM1 = _00_PIMn7_TTL_OFF | _00_PIMn6_TTL_OFF | _00_PIMn5_TTL_OFF | _00_PIMn4_TTL_OFF | _00_PIMn3_TTL_OFF | 
           _00_PIMn1_TTL_OFF | _00_PIMn0_TTL_OFF;
    PDIDIS1 = _00_PDIDISn7_INPUT_BUFFER_ON | _00_PDIDISn5_INPUT_BUFFER_ON | _00_PDIDISn4_INPUT_BUFFER_ON | 
              _00_PDIDISn3_INPUT_BUFFER_ON | _00_PDIDISn2_INPUT_BUFFER_ON | _00_PDIDISn1_INPUT_BUFFER_ON | 
              _00_PDIDISn0_INPUT_BUFFER_ON;
    PMCT1 = _00_PMCTn7_DIGITAL_ON | _00_PMCTn6_NOT_USE | _00_PMCTn5_NOT_USE | _00_PMCTn4_NOT_USE | 
            _00_PMCTn3_NOT_USE | _00_PMCTn2_NOT_USE | _00_PMCTn1_NOT_USE | _00_PMCTn0_NOT_USE;
    PM1 = _80_PMn7_MODE_INPUT | _40_PMn6_NOT_USE | _20_PMn5_NOT_USE | _10_PMn4_NOT_USE | _08_PMn3_NOT_USE | 
          _04_PMn2_NOT_USE | _02_PMn1_NOT_USE | _01_PMn0_NOT_USE;
    /* Set PORT6 registers */
    P6 = _00_Pn3_OUTPUT_0 | _04_Pn2_OUTPUT_1 | _00_Pn1_OUTPUT_0 | _00_Pn0_OUTPUT_0;
    PM6 = _F0_PM6_DEFAULT | _08_PMn3_NOT_USE | _00_PMn2_MODE_OUTPUT | _02_PMn1_NOT_USE | _01_PMn0_NOT_USE;

    R_Config_PORT_Create_UserInit();
}

/***********************************************************************************************************************
* Function Name: R_Config_PORT_ReadPmnValues
* Description  : This function specifies the value in the output latch for a port is read when the pin is in output
                 mode.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_PORT_ReadPmnValues(void)
{
    PMS = _00_PMN_VALUES;
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

