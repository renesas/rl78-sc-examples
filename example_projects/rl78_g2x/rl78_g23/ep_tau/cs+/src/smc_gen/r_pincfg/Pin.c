/*
* Copyright (c) 2021 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
* File Name        : Pin.c
* Version          : 1.0.0
* Device(s)        : R7F100GSNxFB
* Description      : This file implements SMC pin code generation.
***********************************************************************************************************************/
/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_userdefine.h"
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
* Function Name: R_Pins_Create
* Description  : This function initializes Smart Configurator pins
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Pins_Create(void)
{
    /* Set TI00 pin */
    PMCT0 &= 0xFEU;
    PM0 |= 0x01U;

    /* Set TO00 pin */
    PMCT0 &= 0xFDU;
    PMCE0 &= 0xFDU;
    PFOE0 |= 0x01U;
    P0 &= 0xFDU;
    PM0 &= 0xFDU;

    /* Set TO01 pin */
    PMCE1 &= 0xBFU;
    PFOE0 |= 0x02U;
    CCDE &= 0xFEU;
    P1 &= 0xBFU;
    PM1 &= 0xBFU;

    /* Set XT1 pin */
    /* No register setting has been required for pin */

    /* Set XT2 pin */
    /* No register setting has been required for pin */

}

