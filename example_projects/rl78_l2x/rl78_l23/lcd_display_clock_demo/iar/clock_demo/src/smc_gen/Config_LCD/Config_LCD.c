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
* File Name        : Config_LCD.c
* Component Version: 1.1.0
* Device(s)        : R7F100LPLxFB
* Description      : This file implements device driver for Config_LCD.
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
#include "Config_LCD.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_Config_LCD_Create
* Description  : This function initializes the LCD module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_LCD_Create(void)
{
    LCDON = 0U;    /* display off (all segment outputs are deselected) */
    LCDVLM = 1U;    /* VDD voltage is 4.2 V or less */
    LCDM0 = (_00_LCD_DISPLAY_WAVEFORM_A | _0C_LCD_TIMESLICE_4 | _01_LCD_BIAS_MODE_3);
    LCDM0 |= _80_LCD_VOLTAGE_MODE_CAPACITOR;
    VLCD = _00_LCD_CAPACITOR_REFER_VDD;

    /* Set SEG0, SEG1, SEG2, SEG3, SEG4, SEG5, SEG6, SEG7 pin */
    PFSEG1 |= 0xFFU;
    POM9 &= 0x0FU;
    POM5 &= 0xF2U;
    PMCT9 &= 0x0FU;
    PMCT5 &= 0xF0U;
    P9 &= 0x0FU;
    P5 &= 0xF0U;
    PM9 &= 0x0FU;
    PM5 &= 0xF0U;

    /* Set SEG8, SEG12, SEG13, SEG14, SEG15 pin */
    PFSEG2 |= 0xF1U;
    POM5 &= 0xEFU;
    PMCT5 &= 0xEFU;
    PMCT7 &= 0xF0U;
    P5 &= 0xEFU;
    P7 &= 0xF0U;
    PM5 &= 0xEFU;
    PM7 &= 0xF0U;

    /* Set SEG16, SEG17, SEG20, SEG21 pin */
    PFSEG3 |= 0x33U;
    POM7 &= 0xDFU;
    PMCT7 &= 0xCFU;
    PMCT3 &= 0xFCU;
    CCDE &= 0xFBU;
    P7 &= 0xCFU;
    P3 &= 0xFCU;
    PM7 &= 0xCFU;
    PM3 &= 0xFCU;

    /* Set SEG28 pin */
    PFSEG4 |= 0x10U;
    POM13 &= 0xFEU;
    P13 &= 0xFEU;

    /* Set SEG35, SEG36, SEG37, SEG38, SEG39 pin */
    PFSEG5 |= 0xF8U;
    POM1 &= 0xFCU;
    PMCA1 &= 0xE0U;
    P1 &= 0xE0U;
    PM1 &= 0xE0U;

    /* Set SEG47 pin */
    PFSEG6 |= 0x80U;
    POM0 &= 0xEFU;
    PMCT0 &= 0xEFU;
    P0 &= 0xEFU;
    PM0 &= 0xEFU;

    /* Set SEG48, SEG49, SEG50, SEG51, SEG52, SEG53, SEG54, SEG55 pin */
    PFSEG7 |= 0xFFU;
    POM0 &= 0x1FU;
    POM14 &= 0xC7U;
    PMCT0 &= 0x1FU;
    PMCE0 &= 0xDFU;
    P0 &= 0x1FU;
    P14 &= 0xC1U;
    PM0 &= 0x1FU;
    PM14 &= 0xC1U;

    /* Set COM0, COM1, COM2, COM3 pin */
    PFSEG0 |= 0x0FU;
    POM9 &= 0xF7U;
    PMCT9 &= 0xF0U;
    P9 &= 0xF0U;
    PM9 &= 0xF0U;

    /* Set VL1, VL2, VL4 pin */
    ISCLCD &= 0xE9U;
    PM8 |= 0xE0U;

    /* Set CAPH pin */
    ISCLCD &= 0xFEU;
    PMCT12 &= 0x7FU;
    PM12 |= 0x80U;

    /* Set CAPL pin */
    ISCLCD &= 0xFEU;
    PMCT12 &= 0xBFU;
    PM12 |= 0x40U;

    BLON = 0U;    /* displaying an A-pattern area data */
    LCDSEL = 0U;
    LCDC0 = _06_LCD_CLOCK_FSXR_FIL_7;

    R_Config_LCD_Create_UserInit();
}

/***********************************************************************************************************************
* Function Name: R_Config_LCD_Start
* Description  : This function enables the LCD display.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_LCD_Start(void)
{
    LCDON = 1U;    /* display on */
}

/***********************************************************************************************************************
* Function Name: R_Config_LCD_Stop
* Description  : This function disables the LCD display.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_LCD_Stop(void)
{
    LCDON = 0U;    /* display off (all segment outputs are deselected) */
}

/***********************************************************************************************************************
* Function Name: R_Config_LCD_Voltage_On
* Description  : This function enables voltage boost circuit or capacitor split circuit.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_LCD_Voltage_On(void)
{
    volatile uint32_t wt_count;

    VLCON = 1U;    /* enables voltage boost and capacitor split operation */

    /* Change the waiting time according to the system */
    /* WAIT_LOOP */
    for (wt_count = 0U; wt_count <= _000411AA_LCD_CPCITOR_WAITTIME; wt_count++ )
    {
        NOP();
    }

    SCOC = 1U;    /* select common and segment pins output */
}

/***********************************************************************************************************************
* Function Name: R_Config_LCD_Voltage_Off
* Description  : This function disables voltage boost circuit or capacitor split circuit.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_LCD_Voltage_Off(void)
{
    SCOC = 0U;    /* output ground level to segment/common pin */
    VLCON = 0U;    /* stops voltage boost and capacitor split operation */
    /* Set external resistance division method */
    LCDM0 &= (uint8_t)~_C0_LCD_VOLTAGE_MODE_INITALVALUE;
    VLCD &= (uint8_t)~_80_LCD_DRIVER_VOLTAGE_CLEAR;
}

/***********************************************************************************************************************
* Function Name: R_Config_LCD_Set_DisplayData
* Description  : This function sets the data to be displayed on the LCD.
* Arguments    : index -
*                    Specify index of LCD Display Data Register n (SEGn) (n = 0 to 55)
*                data -
*                    data to be displayed
* Return Value : status -
*                    MD_OK or MD_ARGERROR
***********************************************************************************************************************/
MD_STATUS R_Config_LCD_Set_DisplayData(uint8_t index, uint8_t data)
{
    volatile uint8_t * p_lcdc_segn_address;
    MD_STATUS status = MD_OK;

    if (index <= 55U)
    {
        p_lcdc_segn_address = (uint8_t *) &SEG0 + index;
        *p_lcdc_segn_address = data;
    }
    else
    {
        status = MD_ARGERROR;
    }

    return (status);
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */


