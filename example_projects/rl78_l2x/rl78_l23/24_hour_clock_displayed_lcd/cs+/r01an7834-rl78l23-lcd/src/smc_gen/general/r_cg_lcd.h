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
* File Name        : r_cg_lcd.h
* Version          : 1.0.41
* Device(s)        : R7F100LPLxFA
* Description      : General header file for LCD peripheral.
***********************************************************************************************************************/

#ifndef LCD_H
#define LCD_H

/***********************************************************************************************************************
Macro definitions (Register bit)
***********************************************************************************************************************/
/*
    LCD Mode Register 0 (LCDM0)
*/
/* LCD drive voltage generator selection (MDSET1 - MDSET0) */
#define _00_LCD_VOLTAGE_MODE_EXTERNAL                (0x00U)    /* external resistance division method */
#define _40_LCD_VOLTAGE_MODE_INTERNAL                (0x40U)    /* internal voltage boosting method */
#define _80_LCD_VOLTAGE_MODE_CAPACITOR               (0x80U)    /* capacitor split method */
#define _C0_LCD_VOLTAGE_MODE_INITALVALUE             (0xC0U)    /* drive voltage generator inital value */
/* LCD display waveform selection (LWAVE) */
#define _00_LCD_DISPLAY_WAVEFORM_A                   (0x00U)    /* waveform A */
#define _20_LCD_DISPLAY_WAVEFORM_B                   (0x20U)    /* waveform B */
/* LCD display time slice selection (LDTY2 - LDTY0) */
#define _00_LCD_TIMESLICE_STATIC                     (0x00U)    /* static */
#define _04_LCD_TIMESLICE_2                          (0x04U)    /* 2-time slice */
#define _08_LCD_TIMESLICE_3                          (0x08U)    /* 3-time slice */
#define _0C_LCD_TIMESLICE_4                          (0x0CU)    /* 4-time slice */
#define _10_LCD_TIMESLICE_6                          (0x10U)    /* 6-time slice */
#define _14_LCD_TIMESLICE_8                          (0x14U)    /* 8-time slice */
/* LCD display bias mode selection (LBAS1- LBAS0) */
#define _00_LCD_BIAS_MODE_2                          (0x00U)    /* 1/2 bias method */
#define _01_LCD_BIAS_MODE_3                          (0x01U)    /* 1/3 bias method */
#define _02_LCD_BIAS_MODE_4                          (0x02U)    /* 1/4 bias method */

/*
    LCD Mode Register 1 (LCDM1)
*/
/* LCD display enable/disable (LCDON - SCOC) */
#define _00_LCD_DISPLAY_GROUND                       (0x00U)    /* output ground level to the segment or common pin */
#define _80_LCD_DISPLAY_GROUND                       (0x80U)    /* output ground level to the segment or common pin */
#define _40_LCD_DISPLAY_OFF                          (0x40U)    /* display off (all segment outputs are deselected) */
#define _C0_LCD_DISPLAY_ON                           (0xC0U)    /* display on */
/* Voltage boost circuit or capacitor split circuit operation enable/disable (VLCON) */
#define _00_LCD_BOOST_CAPACITOR_DISABLE              (0x00U)    /* stops the operation of the voltage boost circuit
                                                                    or capacitor split circuit */
#define _20_LCD_BOOST_CAPACITOR_ENABLE               (0x20U)    /* enables the operation of the voltage boost circuit
                                                                    or capacitor split circuit */
/* Display data area control (BLON - LCDSEL) */
#define _00_LCD_DISPLAY_PATTERN_A                    (0x00U)    /* displaying an A-pattern area data */
#define _08_LCD_DISPLAY_PATTERN_B                    (0x08U)    /* displaying a B-pattern area data */
#define _10_LCD_DISPLAY_PATTERN_AB                   (0x10U)    /* display alternately A-pattern
                                                                    and B-pattern area data */
#define _18_LCD_DISPLAY_PATTERN_AB                   (0x18U)    /* display alternately A-pattern
                                                                    and B-pattern area data */
/* Control of default value of voltage boosting pin (LCDVLM) */
#define _00_LCD_VDD_27V_HIGHER                       (0x00U)    /* set when VDD ≥ 2.7 V */
#define _01_LCD_VDD_42V_LOWER                        (0x01U)    /* set when VDD ≤ 4.2 V */

/*
     LCD Mode Register 2 (LCDM2)
*/
/* Time selection for switching in alternation of LCD display (LCDSEL2 - LCDSEL1) */
#define _00_LCD_DISPLAY_ALTERNATION_INTRTC           (0x00U)    /* alternation in response to INTRTC */
#define _02_LCD_DISPLAY_ALTERNATION_HALF_SECOND      (0x02U)    /* alternation at the interval of 0.5 seconds */
#define _03_LCD_DISPLAY_ALTERNATION_ELCITL2          (0x03U)    /* alternation in response to ELCITL2 */

/*
    LCD Clock Control Register 0 (LCDC0)
*/
/* LCD clock setting (LCDC05 - LCDC00) */
#define _01_LCD_CLOCK_FSXR_FIL_2                     (0x01U)    /* fSXR/2^2 or fIL/2^2 */
#define _02_LCD_CLOCK_FSXR_FIL_3                     (0x02U)    /* fSXR/2^3 or fIL/2^3 */
#define _03_LCD_CLOCK_FSXR_FIL_4                     (0x03U)    /* fSXR/2^4 or fIL/2^4 */
#define _04_LCD_CLOCK_FSXR_FIL_5                     (0x04U)    /* fSXR/2^5 or fIL/2^5 */
#define _05_LCD_CLOCK_FSXR_FIL_6                     (0x05U)    /* fSXR/2^6 or fIL/2^6 */
#define _06_LCD_CLOCK_FSXR_FIL_7                     (0x06U)    /* fSXR/2^7 or fIL/2^7 */
#define _07_LCD_CLOCK_FSXR_FIL_8                     (0x07U)    /* fSXR/2^8 or fIL/2^8 */
#define _08_LCD_CLOCK_FSXR_FIL_9                     (0x08U)    /* fSXR/2^9 or fIL/2^9 */
#define _09_LCD_CLOCK_FSXR_FIL_10                    (0x09U)    /* fSXR/2^10 or fIL/2^10 */
#define _11_LCD_CLOCK_FMAIN_8                        (0x11U)    /* fMAIN/2^8 */
#define _12_LCD_CLOCK_FMAIN_9                        (0x12U)    /* fMAIN/2^9 */
#define _13_LCD_CLOCK_FMAIN_10                       (0x13U)    /* fMAIN/2^10 */
#define _14_LCD_CLOCK_FMAIN_11                       (0x14U)    /* fMAIN/2^11 */
#define _15_LCD_CLOCK_FMAIN_12                       (0x15U)    /* fMAIN/2^12 */
#define _16_LCD_CLOCK_FMAIN_13                       (0x16U)    /* fMAIN/2^13 */
#define _17_LCD_CLOCK_FMAIN_14                       (0x17U)    /* fMAIN/2^14 */
#define _18_LCD_CLOCK_FMAIN_15                       (0x18U)    /* fMAIN/2^15 */
#define _19_LCD_CLOCK_FMAIN_16                       (0x19U)    /* fMAIN/2^16 */
#define _1A_LCD_CLOCK_FMAIN_17                       (0x1AU)    /* fMAIN/2^17 */
#define _1B_LCD_CLOCK_FMAIN_18                       (0x1BU)    /* fMAIN/2^18 */
#define _2B_LCD_CLOCK_FMAIN_19                       (0x2BU)    /* fMAIN/2^19 */

/*
    LCD Boost Level Control Register (VLCD)
*/
/* LCD drive voltage generator selection (MDSET2) */
#define _00_LCD_EXTERNAL_RESISTANCE                  (0x00U)    /* external resistance division method */
#define _00_LCD_INTERNAL_REFER_VL1                   (0x00U)    /* internal voltage boosting method
                                                                    on the VL1 reference */
#define _80_LCD_INTERNAL_REFER_VL2                   (0x80U)    /* internal voltage boosting method
                                                                    on the VL2 reference */
#define _00_LCD_CAPACITOR_REFER_VDD                  (0x00U)    /* capacitor split method for the VDD reference */
#define _80_LCD_CAPACITOR_REFER_VL4                  (0x80U)    /* capacitor split method for the VL4 reference */
#define _80_LCD_DRIVER_VOLTAGE_CLEAR                 (0x80U)    /* driver voltage generator clear */
/* Reference voltage (contrast adjustment) selection (VLCD4 - VLCD0) */
#define _04_LCD_BOOST_VL1_101V                       (0x04U)    /* 1.01 V (1/3 bias: 3.03 V; 1/4 bias: 4.04 V) */
#define _05_LCD_BOOST_VL1_104V                       (0x05U)    /* 1.04 V (1/3 bias: 3.12 V; 1/4 bias: 4.16 V) */
#define _06_LCD_BOOST_VL1_107V                       (0x06U)    /* 1.07 V (1/3 bias: 3.21 V; 1/4 bias: 4.28 V) */
#define _07_LCD_BOOST_VL1_111V                       (0x07U)    /* 1.11 V (1/3 bias: 3.33 V; 1/4 bias: 4.44 V) */
#define _08_LCD_BOOST_VL1_114V                       (0x08U)    /* 1.14 V (1/3 bias: 3.42 V; 1/4 bias: 4.56 V) */
#define _09_LCD_BOOST_VL1_117V                       (0x09U)    /* 1.17 V (1/3 bias: 3.51 V; 1/4 bias: 4.68 V) */
#define _0A_LCD_BOOST_VL1_121V                       (0x0AU)    /* 1.21 V (1/3 bias: 3.63 V; 1/4 bias: 4.84 V) */
#define _0B_LCD_BOOST_VL1_124V                       (0x0BU)    /* 1.24 V (1/3 bias: 3.72 V; 1/4 bias: 4.96 V) */
#define _0C_LCD_BOOST_VL1_127V                       (0x0CU)    /* 1.27 V (1/3 bias: 3.81 V; 1/4 bias: 5.01 V) */
#define _0D_LCD_BOOST_VL1_131V                       (0x0DU)    /* 1.31 V (1/3 bias: 3.93 V; 1/4 bias: 5.24 V) */
#define _0E_LCD_BOOST_VL1_134V                       (0x0EU)    /* 1.34 V (1/3 bias: 4.02 V) */
#define _0F_LCD_BOOST_VL1_137V                       (0x0FU)    /* 1.37 V (1/3 bias: 4.11 V) */
#define _10_LCD_BOOST_VL1_140V                       (0x10U)    /* 1.40 V (1/3 bias: 4.20 V) */
#define _11_LCD_BOOST_VL1_144V                       (0x11U)    /* 1.44 V (1/3 bias: 4.32 V) */
#define _12_LCD_BOOST_VL1_147V                       (0x12U)    /* 1.47 V (1/3 bias: 4.41 V) */
#define _13_LCD_BOOST_VL1_150V                       (0x13U)    /* 1.50 V (1/3 bias: 4.50 V) */
#define _14_LCD_BOOST_VL1_154V                       (0x14U)    /* 1.54 V (1/3 bias: 4.62 V) */
#define _15_LCD_BOOST_VL1_157V                       (0x15U)    /* 1.57 V (1/3 bias: 4.71 V) */
#define _16_LCD_BOOST_VL1_160V                       (0x16U)    /* 1.60 V (1/3 bias: 4.80 V) */
#define _17_LCD_BOOST_VL1_164V                       (0x17U)    /* 1.64 V (1/3 bias: 4.92 V) */
#define _18_LCD_BOOST_VL1_167V                       (0x18U)    /* 1.67 V (1/3 bias: 5.01 V) */
#define _19_LCD_BOOST_VL1_170V                       (0x19U)    /* 1.70 V (1/3 bias: 5.10 V) */
#define _1A_LCD_BOOST_VL1_174V                       (0x1AU)    /* 1.74 V (1/3 bias: 5.22 V) */
#define _04_LCD_BOOST_VL2_202V                       (0x04U)    /* 2.02 V (1/3 bias: 3.03 V) */
#define _05_LCD_BOOST_VL2_209V                       (0x05U)    /* 2.09 V (1/3 bias: 3.14 V) */
#define _06_LCD_BOOST_VL2_216V                       (0x06U)    /* 2.16 V (1/3 bias: 3.24 V) */
#define _07_LCD_BOOST_VL2_222V                       (0x07U)    /* 2.22 V (1/3 bias: 3.33 V) */
#define _08_LCD_BOOST_VL2_229V                       (0x08U)    /* 2.29 V (1/3 bias: 3.44 V) */
#define _09_LCD_BOOST_VL2_236V                       (0x09U)    /* 2.36 V (1/3 bias: 3.54 V) */
#define _0A_LCD_BOOST_VL2_242V                       (0x0AU)    /* 2.42 V (1/3 bias: 3.63 V) */
#define _0B_LCD_BOOST_VL2_249V                       (0x0BU)    /* 2.49 V (1/3 bias: 3.74 V) */
#define _0C_LCD_BOOST_VL2_256V                       (0x0CU)    /* 2.56 V (1/3 bias: 3.84 V) */
#define _0D_LCD_BOOST_VL2_262V                       (0x0DU)    /* 2.62 V (1/3 bias: 3.93 V) */
#define _0E_LCD_BOOST_VL2_269V                       (0x0EU)    /* 2.69 V (1/3 bias: 4.07 V) */
#define _0F_LCD_BOOST_VL2_276V                       (0x0FU)    /* 2.76 V (1/3 bias: 4.14 V) */
#define _10_LCD_BOOST_VL2_282V                       (0x10U)    /* 2.82 V (1/3 bias: 4.23 V) */
#define _11_LCD_BOOST_VL2_289V                       (0x11U)    /* 2.89 V (1/3 bias: 4.34 V) */
#define _12_LCD_BOOST_VL2_296V                       (0x12U)    /* 2.96 V (1/3 bias: 4.44 V) */
#define _13_LCD_BOOST_VL2_302V                       (0x13U)    /* 3.02 V (1/3 bias: 4.53 V) */
#define _14_LCD_BOOST_VL2_309V                       (0x14U)    /* 3.09 V (1/3 bias: 4.64 V) */
#define _15_LCD_BOOST_VL2_315V                       (0x15U)    /* 3.15 V (1/3 bias: 4.73 V) */
#define _16_LCD_BOOST_VL2_322V                       (0x16U)    /* 3.22 V (1/3 bias: 4.83 V) */
#define _17_LCD_BOOST_VL2_329V                       (0x17U)    /* 3.29 V (1/3 bias: 4.94 V) */
#define _18_LCD_BOOST_VL2_335V                       (0x18U)    /* 3.35 V (1/3 bias: 5.03 V) */
#define _19_LCD_BOOST_VL2_342V                       (0x19U)    /* 3.42 V (1/3 bias: 5.13 V) */
#define _1A_LCD_BOOST_VL2_349V                       (0x1AU)    /* 3.49 V (1/3 bias: 5.24 V) */
#define _E0_LCD_BOOST_CLEAR                          (0xE0U)    /* clear VLCD4 - VLCD0 bits */

/*
    LCD Input Switch Control Register (ISCLCD)
*/
/* Control of Schmitt trigger buffer of VL4/P85 pin (ISCVL4) */
#define _00_LCD_VL4_BUFFER_DISABLED                  (0x00U)    /* Input disabled. */
#define _10_LCD_VL4_BUFFER_ENABLED                   (0x10U)    /* Input enabled */
/* Control of Schmitt trigger buffer of VL3/P125 pin (ISCVL3) */
#define _00_LCD_VL3_BUFFER_DISABLED                  (0x00U)    /* Input disabled. */
#define _08_LCD_VL3_BUFFER_ENABLED                   (0x08U)    /* Input enabled */
/* Control of Schmitt trigger buffer of VL2/P86 pin (ISCVL2) */
#define _00_LCD_VL2_BUFFER_DISABLED                  (0x00U)    /* Input disabled. */
#define _04_LCD_VL2_BUFFER_ENABLED                   (0x04U)    /* Input enabled */
/* Control of Schmitt trigger buffer of VL1/P87 pin (ISCVL1) */
#define _00_LCD_VL1_BUFFER_DISABLED                  (0x00U)    /* Input disabled. */
#define _02_LCD_VL1_BUFFER_ENABLED                   (0x02U)    /* Input enabled */
/* Control of Schmitt trigger buffer of CAPL/P126 and CAPH/P127 pins (ISCCAP) */
#define _00_LCD_CAPL_CAPH_BUFFER_DISABLED            (0x00U)    /* Input disabled. */
#define _01_LCD_CAPL_CAPH_BUFFER_ENABLED             (0x01U)    /* Input enabled */

/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Global functions
***********************************************************************************************************************/
/* Start user code for function. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#endif
