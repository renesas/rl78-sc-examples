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
* Copyright (C) 2021, 2025 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
* File Name        : Pin.c
* Version          : 1.0.0
* Device(s)        : R7F100LPLxFA
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
    /* Set COM0 pin */
    POM9 &= 0xFEU;
    PMCT9 &= 0xFEU;
    P9 &= 0xFEU;
    PM9 &= 0xFEU;

    /* Set COM1 pin */
    POM9 &= 0xFDU;
    PMCT9 &= 0xFDU;
    P9 &= 0xFDU;
    PM9 &= 0xFDU;

    /* Set COM2 pin */
    POM9 &= 0xFBU;
    PMCT9 &= 0xFBU;
    P9 &= 0xFBU;
    PM9 &= 0xFBU;

    /* Set COM3 pin */
    POM9 &= 0xF7U;
    PMCT9 &= 0xF7U;
    P9 &= 0xF7U;
    PM9 &= 0xF7U;

    /* Set SEG0 pin */
    POM9 &= 0xEFU;
    PMCT9 &= 0xEFU;
    P9 &= 0xEFU;
    PM9 &= 0xEFU;

    /* Set SEG1 pin */
    POM9 &= 0xDFU;
    PMCT9 &= 0xDFU;
    P9 &= 0xDFU;
    PM9 &= 0xDFU;

    /* Set SEG2 pin */
    POM9 &= 0xBFU;
    PMCT9 &= 0xBFU;
    P9 &= 0xBFU;
    PM9 &= 0xBFU;

    /* Set SEG3 pin */
    POM9 &= 0x7FU;
    PMCT9 &= 0x7FU;
    P9 &= 0x7FU;
    PM9 &= 0x7FU;

    /* Set SEG4 pin */
    POM5 &= 0xFEU;
    PMCT5 &= 0xFEU;
    P5 &= 0xFEU;
    PM5 &= 0xFEU;

    /* Set SEG5 pin */
    POM5 &= 0xFDU;
    PMCT5 &= 0xFDU;
    P5 &= 0xFDU;
    PM5 &= 0xFDU;

    /* Set SEG6 pin */
    POM5 &= 0xFBU;
    PMCT5 &= 0xFBU;
    P5 &= 0xFBU;
    PM5 &= 0xFBU;

    /* Set SEG7 pin */
    POM5 &= 0xF7U;
    PMCT5 &= 0xF7U;
    P5 &= 0xF7U;
    PM5 &= 0xF7U;

    /* Set SEG8 pin */
    POM5 &= 0xEFU;
    PMCT5 &= 0xEFU;
    P5 &= 0xEFU;
    PM5 &= 0xEFU;

    /* Set SEG12 pin */
    POM7 &= 0xFEU;
    PMCT7 &= 0xFEU;
    P7 &= 0xFEU;
    PM7 &= 0xFEU;

    /* Set SEG13 pin */
    POM7 &= 0xFDU;
    PMCT7 &= 0xFDU;
    P7 &= 0xFDU;
    PM7 &= 0xFDU;

    /* Set SEG14 pin */
    POM7 &= 0xFBU;
    PMCT7 &= 0xFBU;
    P7 &= 0xFBU;
    PM7 &= 0xFBU;

    /* Set SEG15 pin */
    POM7 &= 0xF7U;
    PMCT7 &= 0xF7U;
    P7 &= 0xF7U;
    PM7 &= 0xF7U;

    /* Set SEG16 pin */
    POM7 &= 0xEFU;
    PMCT7 &= 0xEFU;
    CCDE &= 0xF7U;
    P7 &= 0xEFU;
    PM7 &= 0xEFU;

    /* Set SEG17 pin */
    POM7 &= 0xDFU;
    PMCT7 &= 0xDFU;
    CCDE &= 0xFBU;
    P7 &= 0xDFU;
    PM7 &= 0xDFU;

    /* Set SEG20 pin */
    POM3 &= 0xFEU;
    PMCT3 &= 0xFEU;
    P3 &= 0xFEU;
    PM3 &= 0xFEU;

    /* Set SEG21 pin */
    POM3 &= 0xFDU;
    PMCT3 &= 0xFDU;
    P3 &= 0xFDU;
    PM3 &= 0xFDU;

    /* Set SEG28 pin */
    POM13 &= 0xFEU;
    P13 &= 0xFEU;

    /* Set SEG35 pin */
    POM1 &= 0xFEU;
    PMCA1 &= 0xFEU;
    P1 &= 0xFEU;
    PM1 &= 0xFEU;

    /* Set SEG36 pin */
    POM1 &= 0xFDU;
    PMCA1 &= 0xFDU;
    P1 &= 0xFDU;
    PM1 &= 0xFDU;

    /* Set SEG37 pin */
    POM1 &= 0xFBU;
    PMCA1 &= 0xFBU;
    P1 &= 0xFBU;
    PM1 &= 0xFBU;

    /* Set SEG38 pin */
    POM1 &= 0xF7U;
    PMCA1 &= 0xF7U;
    P1 &= 0xF7U;
    PM1 &= 0xF7U;

    /* Set SEG39 pin */
    POM1 &= 0xEFU;
    PMCA1 &= 0xEFU;
    P1 &= 0xEFU;
    PM1 &= 0xEFU;

    /* Set SEG47 pin */
    POM0 &= 0xEFU;
    PMCT0 &= 0xEFU;
    P0 &= 0xEFU;
    PM0 &= 0xEFU;

    /* Set SEG48 pin */
    POM0 &= 0xDFU;
    PMCT0 &= 0xDFU;
    PMCE0 &= 0xDFU;
    P0 &= 0xDFU;
    PM0 &= 0xDFU;

    /* Set SEG49 pin */
    POM0 &= 0xBFU;
    PMCT0 &= 0xBFU;
    P0 &= 0xBFU;
    PM0 &= 0xBFU;

    /* Set SEG50 pin */
    POM0 &= 0x7FU;
    PMCT0 &= 0x7FU;
    P0 &= 0x7FU;
    PM0 &= 0x7FU;

    /* Set SEG51 pin */
    POM14 &= 0xFDU;
    P14 &= 0xFDU;
    PM14 &= 0xFDU;

    /* Set SEG52 pin */
    POM14 &= 0xFBU;
    P14 &= 0xFBU;
    PM14 &= 0xFBU;

    /* Set SEG53 pin */
    POM14 &= 0xF7U;
    P14 &= 0xF7U;
    PM14 &= 0xF7U;

    /* Set SEG54 pin */
    POM14 &= 0xEFU;
    P14 &= 0xEFU;
    PM14 &= 0xEFU;

    /* Set SEG55 pin */
    POM14 &= 0xDFU;
    P14 &= 0xDFU;
    PM14 &= 0xDFU;

    /* Set VL1 pin */
    PM8 |= 0x80U;

    /* Set VL2 pin */
    PM8 |= 0x40U;

    /* Set VL4 pin */
    PM8 |= 0x20U;

    /* Set XT1 pin */
    /* No register setting has been required for pin */

    /* Set XT2 pin */
    /* No register setting has been required for pin */

}

