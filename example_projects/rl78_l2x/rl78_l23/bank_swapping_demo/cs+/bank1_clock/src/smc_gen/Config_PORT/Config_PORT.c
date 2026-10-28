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
* File Name        : Config_PORT.c
* Component Version: 1.8.0
* Device(s)        : R7F100LPLxFB
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
    volatile uint16_t w_count;

    PFSEG3 = _00_PFSEG23_PORT | _00_PFSEG22_PORT | _20_PFSEG21_SEG | _10_PFSEG20_SEG | _00_PFSEG19_PORT | 
             _00_PFSEG18_PORT | _02_PFSEG17_SEG | _01_PFSEG16_SEG;
    PFSEG4 = _00_PFSEG31_PORT | _00_PFSEG30_PORT | _00_PFSEG29_PORT | _10_PFSEG28_SEG | _00_PFSEG27_PORT | 
             _00_PFSEG26_PORT | _00_PFSEG25_PORT | _00_PFSEG24_PORT;
    PFSEG5 = _80_PFSEG39_SEG | _40_PFSEG38_SEG | _20_PFSEG37_SEG | _10_PFSEG36_SEG | _08_PFSEG35_SEG | 
             _00_PFSEG34_PORT | _00_PFSEG33_PORT | _00_PFSEG32_PORT;
    PFSEG6 = _80_PFSEG47_SEG | _00_PFSEG46_PORT | _00_PFSEG45_PORT | _00_PFSEG44_PORT | _08_PFSEG43_SEG | 
             _04_PFSEG42_SEG | _00_PFSEG41_PORT | _00_PFSEG40_PORT;
    ISCLCD = _00_VL4_BUFFER_INVALID | _08_VL3_BUFFER_VALID | _00_VL2_BUFFER_INVALID | _00_VL1_BUFFER_INVALID | 
             _00_CAPLH_BUFFER_INVALID;
    CCDE = _00_P63_OUTPUT_CURRENT_OFF | _00_P62_OUTPUT_CURRENT_OFF | _00_P61_OUTPUT_CURRENT_OFF | 
           _00_P60_OUTPUT_CURRENT_OFF | _00_P74_OUTPUT_CURRENT_OFF | _00_P75_OUTPUT_CURRENT_OFF | 
           _00_P76_OUTPUT_CURRENT_OFF | _00_P77_OUTPUT_CURRENT_OFF;

    /* Wait for stable time (10us) */
    for (w_count = 0U; w_count < PORT_STABLE_WAITTIME; w_count++ )
    {
        NOP();
    }
 
    /* Set PORT0 registers */
    P0 = _00_Pn7_OUTPUT_0 | _00_Pn6_OUTPUT_0 | _00_Pn5_OUTPUT_0 | _00_Pn4_OUTPUT_0 | _00_Pn3_OUTPUT_0 | 
         _00_Pn2_OUTPUT_0 | _00_Pn1_OUTPUT_0 | _00_Pn0_OUTPUT_0;
    PDIDIS0 = _00_PDIDISn7_INPUT_BUFFER_ON | _00_PDIDISn6_INPUT_BUFFER_ON | _00_PDIDISn5_INPUT_BUFFER_ON | 
              _00_PDIDISn4_INPUT_BUFFER_ON | _00_PDIDISn3_INPUT_BUFFER_ON | _00_PDIDISn2_INPUT_BUFFER_ON | 
              _00_PDIDISn1_INPUT_BUFFER_ON | _00_PDIDISn0_INPUT_BUFFER_ON;
    POM0 = _00_POMn7_NCH_OFF | _00_POMn6_NCH_OFF | _00_POMn5_NCH_OFF | _00_POMn4_NCH_OFF | _00_POMn3_NCH_OFF | 
           _00_POMn2_NCH_OFF | _00_POMn1_NCH_OFF | _00_POMn0_NCH_OFF;
    PMCT0 = _00_PMCTn7_NOT_USE | _00_PMCTn6_NOT_USE | _00_PMCTn5_NOT_USE | _00_PMCTn4_NOT_USE;
    PMCE0 = _00_PMCEn5_NOT_USE | _00_PMCEn0_NOT_USE;
    PM0 = _80_PMn7_NOT_USE | _40_PMn6_NOT_USE | _20_PMn5_NOT_USE | _10_PMn4_NOT_USE | _00_PMn3_MODE_OUTPUT | 
          _00_PMn2_MODE_OUTPUT | _00_PMn1_MODE_OUTPUT | _01_PMn0_NOT_USE;
    /* Set PORT1 registers */
    P1 = _00_Pn7_OUTPUT_0 | _00_Pn6_OUTPUT_0 | _00_Pn5_OUTPUT_0 | _00_Pn4_OUTPUT_0 | _00_Pn3_OUTPUT_0 | 
         _00_Pn2_OUTPUT_0 | _00_Pn1_OUTPUT_0 | _00_Pn0_OUTPUT_0;
    PDIDIS1 = _00_PDIDISn7_INPUT_BUFFER_ON | _00_PDIDISn6_INPUT_BUFFER_ON | _00_PDIDISn1_INPUT_BUFFER_ON | 
              _00_PDIDISn0_INPUT_BUFFER_ON;
    POM1 = _00_POMn7_NCH_OFF | _00_POMn6_NCH_OFF | _00_POMn1_NCH_OFF | _00_POMn0_NCH_OFF;
    PMCA1 = _E0_PMCA1_DEFAULT | _10_PMCAn4_NOT_USE | _08_PMCAn3_NOT_USE | _04_PMCAn2_NOT_USE | _02_PMCAn1_NOT_USE | 
            _01_PMCAn0_NOT_USE;
    PMCE1 = _00_PMCEn7_NOT_USE;
    PM1 = _80_PMn7_NOT_USE | _00_PMn6_MODE_OUTPUT | _00_PMn5_MODE_OUTPUT | _10_PMn4_NOT_USE | _08_PMn3_NOT_USE | 
          _04_PMn2_NOT_USE | _02_PMn1_NOT_USE | _01_PMn0_NOT_USE;
    /* Set PORT2 registers */
    P2 = _00_Pn7_OUTPUT_0 | _00_Pn6_OUTPUT_0 | _00_Pn5_OUTPUT_0 | _00_Pn4_OUTPUT_0 | _00_Pn3_OUTPUT_0 | 
         _00_Pn2_OUTPUT_0 | _00_Pn1_OUTPUT_0 | _00_Pn0_OUTPUT_0;
    PDIDIS2 = _00_PDIDISn7_INPUT_BUFFER_ON | _00_PDIDISn6_INPUT_BUFFER_ON | _00_PDIDISn2_INPUT_BUFFER_ON;
    POM2 = _00_POMn7_NCH_OFF | _00_POMn6_NCH_OFF | _00_POMn2_NCH_OFF;
    PMCA2 = _00_PMCAn7_DIGITAL_ON | _00_PMCAn6_DIGITAL_ON | _00_PMCAn5_DIGITAL_ON | _00_PMCAn4_DIGITAL_ON | 
            _00_PMCAn3_DIGITAL_ON | _00_PMCAn2_DIGITAL_ON | _00_PMCAn1_DIGITAL_ON | _00_PMCAn0_DIGITAL_ON;
    PM2 = _00_PMn7_MODE_OUTPUT | _00_PMn6_MODE_OUTPUT | _00_PMn5_MODE_OUTPUT | _00_PMn4_MODE_OUTPUT | 
          _00_PMn3_MODE_OUTPUT | _00_PMn2_MODE_OUTPUT | _00_PMn1_MODE_OUTPUT | _00_PMn0_MODE_OUTPUT;
    /* Set PORT3 registers */
    P3 = _00_Pn5_OUTPUT_0 | _00_Pn4_OUTPUT_0 | _00_Pn3_OUTPUT_0 | _00_Pn2_OUTPUT_0 | _00_Pn1_OUTPUT_0 | 
         _00_Pn0_OUTPUT_0;
    PDIDIS3 = _00_PDIDISn5_INPUT_BUFFER_ON | _00_PDIDISn4_INPUT_BUFFER_ON | _00_PDIDISn3_INPUT_BUFFER_ON;
    POM3 = _00_POMn5_NCH_OFF | _00_POMn4_NCH_OFF | _00_POMn3_NCH_OFF;
    PMCT3 = _00_PMCTn5_DIGITAL_ON | _00_PMCTn4_DIGITAL_ON | _00_PMCTn3_DIGITAL_ON | _00_PMCTn2_DIGITAL_ON | 
            _00_PMCTn1_NOT_USE | _00_PMCTn0_NOT_USE;
    PM3 = _C0_PM3_DEFAULT | _00_PMn5_MODE_OUTPUT | _00_PMn4_MODE_OUTPUT | _00_PMn3_MODE_OUTPUT | 
          _00_PMn2_MODE_OUTPUT | _02_PMn1_NOT_USE | _01_PMn0_NOT_USE;
    /* Set PORT4 registers */
    P4 = _00_Pn7_OUTPUT_0 | _00_Pn6_OUTPUT_0 | _00_Pn5_OUTPUT_0 | _00_Pn4_OUTPUT_0 | _00_Pn3_OUTPUT_0 | 
         _00_Pn2_OUTPUT_0 | _00_Pn1_OUTPUT_0 | _00_Pn0_OUTPUT_0;
    PU4 = _00_PUn7_PULLUP_OFF | _00_PUn6_PULLUP_OFF | _00_PUn5_PULLUP_OFF | _00_PUn4_PULLUP_OFF | 
          _00_PUn3_PULLUP_OFF | _00_PUn2_PULLUP_OFF | _00_PUn1_PULLUP_OFF | _00_PUn0_PULLUP_OFF;
    PDIDIS4 = _00_PDIDISn7_INPUT_BUFFER_ON | _00_PDIDISn6_INPUT_BUFFER_ON | _00_PDIDISn5_INPUT_BUFFER_ON | 
              _00_PDIDISn4_INPUT_BUFFER_ON | _00_PDIDISn3_INPUT_BUFFER_ON | _00_PDIDISn2_INPUT_BUFFER_ON | 
              _00_PDIDISn1_INPUT_BUFFER_ON | _00_PDIDISn0_INPUT_BUFFER_ON;
    POM4 = _00_POMn7_NCH_OFF | _00_POMn6_NCH_OFF | _00_POMn5_NCH_OFF | _00_POMn4_NCH_OFF | _00_POMn3_NCH_OFF | 
           _00_POMn2_NCH_OFF | _00_POMn1_NCH_OFF | _00_POMn0_NCH_OFF;
    PMCA4 = _C3_PMCA4_DEFAULT | _00_PMCAn5_DIGITAL_ON | _00_PMCAn4_DIGITAL_ON | _00_PMCAn3_DIGITAL_ON | 
            _00_PMCAn2_DIGITAL_ON;
    PM4 = _00_PMn7_MODE_OUTPUT | _00_PMn6_MODE_OUTPUT | _00_PMn5_MODE_OUTPUT | _00_PMn4_MODE_OUTPUT | 
          _00_PMn3_MODE_OUTPUT | _00_PMn2_MODE_OUTPUT | _00_PMn1_MODE_OUTPUT | _01_PMn0_NOT_USE;
    /* Set PORT6 registers */
    P6 = _00_Pn7_OUTPUT_0 | _00_Pn6_OUTPUT_0 | _20_Pn5_OUTPUT_1 | _10_Pn4_OUTPUT_1 | _00_Pn3_OUTPUT_0 | 
         _00_Pn2_OUTPUT_0 | _00_Pn1_OUTPUT_0 | _00_Pn0_OUTPUT_0;
    PDIDIS6 = _00_PDIDISn6_INPUT_BUFFER_ON | _00_PDIDISn5_INPUT_BUFFER_ON | _00_PDIDISn4_INPUT_BUFFER_ON;
    POM6 = _00_POMn6_NCH_OFF | _00_POMn5_NCH_OFF | _00_POMn4_NCH_OFF;
    PMCE6 = _00_PMCEn1_DIGITAL_ON | _00_PMCEn0_DIGITAL_ON;
    PM6 = _00_PMn7_MODE_OUTPUT | _00_PMn6_MODE_OUTPUT | _00_PMn5_MODE_OUTPUT | _00_PMn4_MODE_OUTPUT | 
          _00_PMn3_MODE_OUTPUT | _00_PMn2_MODE_OUTPUT | _00_PMn1_MODE_OUTPUT | _00_PMn0_MODE_OUTPUT;
    /* Set PORT7 registers */
    P7 = _00_Pn7_OUTPUT_0 | _00_Pn6_OUTPUT_0 | _00_Pn5_OUTPUT_0 | _00_Pn4_OUTPUT_0 | _00_Pn3_OUTPUT_0 | 
         _00_Pn2_OUTPUT_0 | _00_Pn1_OUTPUT_0 | _00_Pn0_OUTPUT_0;
    PDIDIS7 = _00_PDIDISn7_INPUT_BUFFER_ON | _00_PDIDISn6_INPUT_BUFFER_ON | _00_PDIDISn5_INPUT_BUFFER_ON;
    POM7 = _00_POMn7_NCH_OFF | _00_POMn6_NCH_OFF | _00_POMn5_NCH_OFF;
    PMCT7 = _00_PMCTn7_DIGITAL_ON | _00_PMCTn6_DIGITAL_ON | _00_PMCTn5_NOT_USE | _00_PMCTn4_NOT_USE | 
            _00_PMCTn3_NOT_USE | _00_PMCTn2_NOT_USE | _00_PMCTn1_NOT_USE | _00_PMCTn0_NOT_USE;
    PMCE7 = _00_PMCEn7_DIGITAL_ON | _00_PMCEn6_DIGITAL_ON;
    PM7 = _00_PMn7_MODE_OUTPUT | _00_PMn6_MODE_OUTPUT | _20_PMn5_NOT_USE | _10_PMn4_NOT_USE | _08_PMn3_NOT_USE | 
          _04_PMn2_NOT_USE | _02_PMn1_NOT_USE | _01_PMn0_NOT_USE;
    /* Set PORT8 registers */
    P8 = _00_Pn7_OUTPUT_0 | _00_Pn6_OUTPUT_0 | _00_Pn5_OUTPUT_0 | _00_Pn4_OUTPUT_0 | _00_Pn3_OUTPUT_0 | 
         _00_Pn2_OUTPUT_0 | _00_Pn1_OUTPUT_0 | _00_Pn0_OUTPUT_0;
    PDIDIS8 = _00_PDIDISn7_INPUT_BUFFER_ON | _00_PDIDISn6_INPUT_BUFFER_ON | _00_PDIDISn5_INPUT_BUFFER_ON | 
              _00_PDIDISn4_INPUT_BUFFER_ON | _00_PDIDISn3_INPUT_BUFFER_ON | _00_PDIDISn2_INPUT_BUFFER_ON | 
              _00_PDIDISn1_INPUT_BUFFER_ON | _00_PDIDISn0_INPUT_BUFFER_ON;
    POM8 = _00_POMn7_NCH_OFF | _00_POMn6_NCH_OFF | _00_POMn5_NCH_OFF | _00_POMn4_NCH_OFF | _00_POMn3_NCH_OFF | 
           _00_POMn2_NCH_OFF | _00_POMn1_NCH_OFF | _00_POMn0_NCH_OFF;
    PM8 = _80_PMn7_NOT_USE | _40_PMn6_NOT_USE | _20_PMn5_NOT_USE | _00_PMn4_MODE_OUTPUT | _00_PMn3_MODE_OUTPUT | 
          _00_PMn2_MODE_OUTPUT | _00_PMn1_MODE_OUTPUT | _00_PMn0_MODE_OUTPUT;
    /* Set PORT12 registers */
    P12 = _00_Pn7_OUTPUT_0 | _00_Pn6_OUTPUT_0 | _00_Pn5_OUTPUT_0 | _00_Pn2_OUTPUT_0 | _00_Pn1_OUTPUT_0;
    PDIDIS12 = _00_PDIDISn5_INPUT_BUFFER_ON;
    POM12 = _00_POMn5_NCH_OFF;
    PMCT12 = _00_PMCTn7_NOT_USE | _00_PMCTn6_NOT_USE | _00_PMCTn5_DIGITAL_ON;
    PM12 = _19_PM12_DEFAULT | _80_PMn7_NOT_USE | _40_PMn6_NOT_USE | _00_PMn5_MODE_OUTPUT | _10_PMn4_NOT_USE | 
           _08_PMn3_NOT_USE | _00_PMn2_MODE_OUTPUT | _00_PMn1_MODE_OUTPUT;
    /* Set PORT14 registers */
    P14 = _00_Pn7_OUTPUT_0 | _00_Pn6_OUTPUT_0 | _00_Pn5_OUTPUT_0 | _00_Pn4_OUTPUT_0 | _00_Pn3_OUTPUT_0 | 
          _00_Pn2_OUTPUT_0 | _00_Pn1_OUTPUT_0 | _00_Pn0_OUTPUT_0;
    PDIDIS14 = _00_PDIDISn7_INPUT_BUFFER_ON | _00_PDIDISn6_INPUT_BUFFER_ON | _00_PDIDISn5_INPUT_BUFFER_ON | 
               _00_PDIDISn4_INPUT_BUFFER_ON | _00_PDIDISn3_INPUT_BUFFER_ON | _00_PDIDISn0_INPUT_BUFFER_ON;
    POM14 = _00_POMn7_NCH_OFF | _00_POMn6_NCH_OFF | _00_POMn5_NCH_OFF | _00_POMn4_NCH_OFF | _00_POMn3_NCH_OFF | 
            _00_POMn0_NCH_OFF;
    PM14 = _00_PMn7_MODE_OUTPUT | _00_PMn6_MODE_OUTPUT | _20_PMn5_NOT_USE | _10_PMn4_NOT_USE | _08_PMn3_NOT_USE | 
           _04_PMn2_NOT_USE | _02_PMn1_NOT_USE | _00_PMn0_MODE_OUTPUT;
    PTDC = _00_P27_OUTPUT_MAX_CURRENT_20mA;

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

