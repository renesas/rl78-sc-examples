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
* File Name        : r_cg_pgacomp.h
* Version          : 1.0.20
* Device(s)        : R7F101GLGxFB
* Description      : General header file for COMP peripheral.
***********************************************************************************************************************/

#ifndef PGACOMP_H
#define PGACOMP_H

/***********************************************************************************************************************
Macro definitions (Register bit)
***********************************************************************************************************************/
/*
    Peripheral Enable Register 1 (PER1)
 */
/* Control of PGA and comparator input clock (PGACMPEN) */
#define _00_PGACOMP_CLOCK_STOP                       (0x00U)    /* stops input clock supply */
#define _20_PGACOMP_CLOCK_SUPPLY                     (0x20U)    /* enables input clock supply */

/*
    Peripheral Reset Control Register 1 (PRR1)
*/
/* Control of PGA and comparator operation (PGACMPRES) */
#define _00_PGACOMP_CLOCK_RELEASE                    (0x00U)    /* release reset of comparator */
#define _20_PGACOMP_CLOCK_RESET                      (0x20U)    /* comparator is in reset state */

/*
    PGA Control Register (PGACTL)
*/
/* PGA operation selection (PGAEN) */
#define _00_PGA_OPERATION_STOP                       (0x00U)    /* PGA operation stopped */
#define _80_PGA_OPERATION_ENABLE                     (0x80U)    /* PGA operation enabled */
/* Control over output pin for voltage output by the programmable gain amplifier (PGAPOE) */
#define _00_PGA_OUTPUT_PGAO_DISABLE                  (0x00U)    /* the voltage is not output from the PGAO pin */
#define _40_PGA_OUTPUT_PGAO_ENABLE                   (0x40U)    /* the voltage is output from the PGAO pin */
/* Selection of the ground pin of the feedback resistor for the programmable gain amplifier (PVRVS) */
#define _00_PGA_VSS_SELECTED                         (0x00U)    /* selects VSS */
#define _08_PGA_PGAGND_SELECTED                      (0x08U)    /* selects PGAGND */
/* Selected PGA amplification (PGAVG1 - PGAVG0) */
#define _00_PGA_AMPLIFICATION_X4                     (0x00U)    /* x4 is selected as the gain */
#define _01_PGA_AMPLIFICATION_X8                     (0x01U)    /* x8 is selected as the gain */
#define _02_PGA_AMPLIFICATION_X16                    (0x02U)    /* x16 is selected as the gain */
#define _03_PGA_AMPLIFICATION_X32                    (0x03U)    /* x32 is selected as the gain */

/*
    PGA Input Channel Select Register (PGAINS)
*/
/* Analog input channel of the programmable gain amplifier (PGAINS2:PGAINS0) */
#define _00_PGA_PGAI0_PIN_SELECTED                   (0x00U)    /* the PGAI0 pin is selected */
#define _01_PGA_PGAI1_PIN_SELECTED                   (0x01U)    /* the PGAI1 pin is selected */
#define _02_PGA_PGAI2_PIN_SELECTED                   (0x02U)    /* the PGAI2 pin is selected */
#define _03_PGA_PGAI3_PIN_SELECTED                   (0x03U)    /* the PGAI3 pin is selected */
#define _04_PGA_PGAI4_PIN_SELECTED                   (0x04U)    /* the PGAI4 pin is selected */

/*
    Comparator Mode Setting Register 0 (COMPMDR0)
*/
/* Comparator 1 monitor flag (C1MON) */
#define _00_COMP1_FLAG_REFERENCE_0                   (0x00U)    /* IVCMP1 < comparator 1 reference voltage
                                                                   or comparator 1 is stopped */
#define _80_COMP1_FLAG_REFERENCE_1                   (0x80U)    /* IVCMP1 > comparator 1 reference voltage */
/* Enabling the VCOUT1 pin output (C1POE) */
#define _00_COMP1_OUTPUT_VCOUT1_DISABLED             (0x00U)    /* disable comparator 1 VCOUT1 pin */
#define _20_COMP1_OUTPUT_VCOUT1_ENABLED              (0x20U)    /* enable comparator 1 VCOUT1 pin */
/* Comparator 1 operation enable (C1ENB) */
#define _00_COMP1_OPERATION_DISABLED                 (0x00U)    /* disable comparator 1 operation */
#define _10_COMP1_OPERATION_ENABLED                  (0x10U)    /* enable comparator 1 operation */
/* Comparator 0 monitor flag (C0MON) */
#define _00_COMP0_FLAG_REFERENCE_0                   (0x00U)    /* IVCMP0 < comparator 0 reference voltage
                                                                   or comparator 0 is stopped */
#define _08_COMP0_FLAG_REFERENCE_1                   (0x08U)    /* IVCMP0 > comparator 0 reference voltage */
/* Enabling the VCOUT0 pin output (C0POE) */
#define _00_COMP0_OUTPUT_VCOUT0_DISABLED             (0x00U)    /* disable comparator 0 VCOUT0 pin */
#define _02_COMP0_OUTPUT_VCOUT0_ENABLED              (0x02U)    /* enable comparator 0 VCOUT0 pin */
/* Comparator 0 operation enable (C0ENB) */
#define _00_COMP0_OPERATION_DISABLED                 (0x00U)    /* disable comparator 0 operation */
#define _01_COMP0_OPERATION_ENABLED                  (0x01U)    /* enable comparator 0 operation */

/*
    Comparator Mode Setting Register 1 (COMPMDR1)
*/
/* Comparator 1 monitor flag (C1MON) */
#define _00_COMP3_FLAG_REFERENCE_0                   (0x00U)    /* IVCMP3 < comparator 3 reference voltage
                                                                   or comparator 3 is stopped */
#define _80_COMP3_FLAG_REFERENCE_1                   (0x80U)    /* IVCMP3 > comparator 3 reference voltage */
/* Enabling the VCOUT3 pin output (C3POE) */
#define _00_COMP3_OUTPUT_VCOUT3_DISABLED             (0x00U)    /* disable comparator 3 VCOUT3 pin */
#define _20_COMP3_OUTPUT_VCOUT3_ENABLED              (0x20U)    /* enable comparator 3 VCOUT3 pin */
/* Comparator 3 operation enable (C3ENB) */
#define _00_COMP3_OPERATION_DISABLED                 (0x00U)    /* disable comparator 3 operation */
#define _10_COMP3_OPERATION_ENABLED                  (0x10U)    /* enable comparator 3 operation */
/* Comparator 2 monitor flag (C2MON) */
#define _00_COMP2_FLAG_REFERENCE_0                   (0x00U)    /* IVCMP2 < comparator 2 reference voltage
                                                                   or comparator 2 is stopped */
#define _08_COMP2_FLAG_REFERENCE_1                   (0x08U)    /* IVCMP2 > comparator 2 reference voltage */
/* Enabling the VCOUT2 pin output (C2POE) */
#define _00_COMP2_OUTPUT_VCOUT2_DISABLED             (0x00U)    /* disable comparator 2 VCOUT2 pin */
#define _02_COMP2_OUTPUT_VCOUT2_ENABLED              (0x02U)    /* enable comparator 2 VCOUT2 pin */
/* Comparator 2 operation enable (C2ENB) */
#define _00_COMP2_OPERATION_DISABLED                 (0x00U)    /* disable comparator 2 operation */
#define _01_COMP2_OPERATION_ENABLED                  (0x01U)    /* enable comparator 2 operation */

/*
    Comparator Filter Control Register 0 (COMPFIR0)
*/
#define _F0_COMP0_COMPFIR_CLEAR                      (0xF0U)    /* clear comparator 0 */
#define _0F_COMP1_COMPFIR_CLEAR                      (0x0FU)    /* clear comparator 1 */
/* Comparator 1 edge detection selection (C1EDG) */
#define _00_COMP1_ONE_EDGE_INTERRUPT                 (0x00U)    /* interrupt request by
                                                                   comparator 1 one-edge detection */
#define _80_COMP1_BOTH_EDGES_INTERRUPT               (0x80U)    /* interrupt request by
                                                                   comparator 1 both-edge detection */
/* Comparator 1 edge polarity selection (C1EPO) */
#define _00_COMP1_RISING_INTERRUPT                   (0x00U)    /* interrupt request at
                                                                   comparator 1 rising edge */
#define _40_COMP1_FALLING_INTERRUPT                  (0x40U)    /* interrupt request at
                                                                   comparator 1 falling edge */
/* Comparator 1 filter selection (C1FCK1, C1FCK0) */
#define _00_COMP1_FILTER_NONE                        (0x00U)    /* disable filter */
#define _10_COMP1_FILTER_AT_CLOCK                    (0x10U)    /* sampling at fCLK, fPLL or fHOCO */
#define _20_COMP1_FILTER_AT_CLOCK_8                  (0x20U)    /* sampling at fCLK/8, fPLL/8 or fHOCO/8 */
#define _30_COMP1_FILTER_TO01_OUTPUT                 (0x30U)    /* sampling at TO01 output */
/* Comparator 0 edge detection selection (C0EDG) */
#define _00_COMP0_ONE_EDGE_INTERRUPT                 (0x00U)    /* interrupt request by
                                                                   comparator 0 one-edge detection */
#define _08_COMP0_BOTH_EDGES_INTERRUPT               (0x08U)    /* interrupt request by
                                                                   comparator 0 both-edge detection */
/* Comparator 0 edge polarity selection (C0EPO) */
#define _00_COMP0_RISING_INTERRUPT                   (0x00U)    /* interrupt request at
                                                                   comparator 0 rising edge */
#define _04_COMP0_FALLING_INTERRUPT                  (0x04U)    /* interrupt request at
                                                                   comparator 0 falling edge */
/* Comparator 0  filter selection (C0FCK1, C0FCK0) */
#define _00_COMP0_FILTER_NONE                        (0x00U)    /* disable filter */
#define _01_COMP0_FILTER_AT_CLOCK                    (0x01U)    /* sampling at fCLK, fPLL or fHOCO */
#define _02_COMP0_FILTER_AT_CLOCK_8                  (0x02U)    /* sampling at fCLK/8, fPLL/8 or fHOCO/8 */
#define _03_COMP0_FILTER_TO01_OUTPUT                 (0x03U)    /* sampling at TO01 output */

/*
    Comparator Filter Control Register 1 (COMPFIR1)
*/
#define _F0_COMP2_COMPFIR_CLEAR                      (0xF0U)    /* clear comparator 2 */
#define _0F_COMP3_COMPFIR_CLEAR                      (0x0FU)    /* clear comparator 3 */
/* Comparator 3 edge detection selection (C3EDG) */
#define _00_COMP3_ONE_EDGE_INTERRUPT                 (0x00U)    /* interrupt request by
                                                                   comparator 3 one-edge detection */
#define _80_COMP3_BOTH_EDGES_INTERRUPT               (0x80U)    /* interrupt request by
                                                                   comparator 3 both-edge detection */
/* Comparator 3 edge polarity selection (C3EPO) */
#define _00_COMP3_RISING_INTERRUPT                   (0x00U)    /* interrupt request at
                                                                   comparator 3 rising edge */
#define _40_COMP3_FALLING_INTERRUPT                  (0x40U)    /* interrupt request at
                                                                   comparator 3 falling edge */
/* Comparator 3 filter selection (C3FCK1, C3FCK0) */
#define _00_COMP3_FILTER_NONE                        (0x00U)    /* disable filter */
#define _10_COMP3_FILTER_AT_CLOCK                    (0x10U)    /* sampling at fCLK, fPLL or fHOCO */
#define _20_COMP3_FILTER_AT_CLOCK_8                  (0x20U)    /* sampling at fCLK/8, fPLL/8 or fHOCO/8 */
#define _30_COMP3_FILTER_TO01_OUTPUT                 (0x30U)    /* sampling at TO01 output */
/* Comparator 2 edge detection selection (C2EDG) */
#define _00_COMP2_ONE_EDGE_INTERRUPT                 (0x00U)    /* interrupt request by
                                                                   comparator 2 one-edge detection */
#define _08_COMP2_BOTH_EDGES_INTERRUPT               (0x08U)    /* interrupt request by
                                                                   comparator 2 both-edge detection */
/* Comparator 2 edge polarity selection (C2EPO) */
#define _00_COMP2_RISING_INTERRUPT                   (0x00U)    /* interrupt request at
                                                                   comparator 2 rising edge */
#define _04_COMP2_FALLING_INTERRUPT                  (0x04U)    /* interrupt request at
                                                                   comparator 2 falling edge */
/* Comparator 2  filter selection (C2FCK1, C2FCK0) */
#define _00_COMP2_FILTER_NONE                        (0x00U)    /* disable filter */
#define _01_COMP2_FILTER_AT_CLOCK                    (0x01U)    /* sampling at fCLK, fPLL or fHOCO */
#define _02_COMP2_FILTER_AT_CLOCK_8                  (0x02U)    /* sampling at fCLK/8, fPLL/8 or fHOCO/8 */
#define _03_COMP2_FILTER_TO01_OUTPUT                 (0x03U)    /* sampling at TO01 output */

/*
    Comparator Output Control Register 0 (COMPOCR0)
*/
#define _F0_COMP0_COMPOCR_CLEAR                      (0xF0U)    /* clear comparator 0 */
#define _0F_COMP1_COMPOCR_CLEAR                      (0x0FU)    /* clear comparator 1 */
/* Controlling timer window output mode for comparator 1 (C1OTWMD) */
#define _00_COMP1_TIMER_WINDOW_DISABLE               (0x00U)    /* normal output mode for comparator 1 */
#define _80_COMP1_TIMER_WINDOW_ENABLE                (0x80U)    /* timer window  output mode for comparator 1 */
/* VCOUT1 output polarity selection (C1OP) */
#define _00_COMP1_OUTPUT_NORMAL                      (0x00U)    /* VCOUT1 normal output */
#define _40_COMP1_OUTPUT_INVERTED                    (0x40U)    /* VCOUT1 inverted output */
/* VCOUT1 output selection (C1OE) */
#define _00_COMP1_OUTPUT_DISABLE                     (0x00U)    /* disable VCOUT1 output */
#define _20_COMP1_OUTPUT_ENABLE                      (0x20U)    /* enable VCOUT1 output */
/* Comparator 1 interrupt request enable (C1IE) */
#define _00_COMP1_INTERRUPT_DISABLE                  (0x00U)    /* disable interrupt request */
#define _10_COMP1_INTERRPUT_ENABLE                   (0x10U)    /* enable interrupt request */
/* Controlling timer window output mode for comparator 0 (C0OTWMD) */
#define _00_COMP0_TIMER_WINDOW_DISABLE               (0x00U)    /* normal output mode for comparator 0 */
#define _08_COMP0_TIMER_WINDOW_ENABLE                (0x08U)    /* timer window  output mode for comparator 0 */
/* VCOUT0 output polarity selection (C0OP) */
#define _00_COMP0_OUTPUT_NORMAL                      (0x00U)    /* VCOUT0 normal output */
#define _04_COMP0_OUTPUT_INVERTED                    (0x04U)    /* VCOUT0 inverted output */
/* VCOUT0 output selection (C0OE) */
#define _00_COMP0_OUTPUT_DISABLE                     (0x00U)    /* disable VCOUT0 output */
#define _02_COMP0_OUTPUT_ENABLE                      (0x02U)    /* enable VCOUT0 output */
/* Comparator 0 interrupt request enable (C0IE) */
#define _00_COMP0_INTERRUPT_DISABLE                  (0x00U)    /* disable interrupt request */
#define _01_COMP0_INTERRPUT_ENABLE                   (0x01U)    /* enable interrupt request */

/*
    Comparator Output Control Register 0 (COMPOCR1)
*/
#define _F0_COMP2_COMPOCR_CLEAR                      (0xF0U)    /* clear comparator 2 */
#define _0F_COMP3_COMPOCR_CLEAR                      (0x0FU)    /* clear comparator 3 */
/* VCOUT3 output polarity selection (C3OP) */
#define _00_COMP3_OUTPUT_NORMAL                      (0x00U)    /* VCOUT3 normal output */
#define _40_COMP3_OUTPUT_INVERTED                    (0x40U)    /* VCOUT3 inverted output */
/* VCOUT3 output selection (C3OE) */
#define _00_COMP3_OUTPUT_DISABLE                     (0x00U)    /* disable VCOUT3 output */
#define _20_COMP3_OUTPUT_ENABLE                      (0x20U)    /* enable VCOUT3 output */
/* Comparator 3 interrupt request enable (C3IE) */
#define _00_COMP3_INTERRUPT_DISABLE                  (0x00U)    /* disable interrupt request */
#define _10_COMP3_INTERRPUT_ENABLE                   (0x10U)    /* enable interrupt request */
/* Controlling timer window output mode for comparator 2 (C2OTWMD) */
#define _00_COMP2_TIMER_WINDOW_DISABLE               (0x00U)    /* normal output mode for comparator 2 */
#define _08_COMP2_TIMER_WINDOW_ENABLE                (0x08U)    /* timer window  output mode for comparator 2 */
/* VCOUT2 output polarity selection (C2OP) */
#define _00_COMP2_OUTPUT_NORMAL                      (0x00U)    /* VCOUT2 normal output */
#define _04_COMP2_OUTPUT_INVERTED                    (0x04U)    /* VCOUT2 inverted output */
/* VCOUT2 output selection (C2OE) */
#define _00_COMP2_OUTPUT_DISABLE                     (0x00U)    /* disable VCOUT2 output */
#define _02_COMP2_OUTPUT_ENABLE                      (0x02U)    /* enable VCOUT2 output */
/* Comparator 2 interrupt request enable (C2IE) */
#define _00_COMP2_INTERRUPT_DISABLE                  (0x00U)    /* disable interrupt request */
#define _01_COMP2_INTERRPUT_ENABLE                   (0x01U)    /* enable interrupt request */

/*
    Comparator 0 Input Signal Selection Control Register (CMP0SEL)
*/
/* Selecting the input signal on the negative side of comparator 0 (C0REFS1, C0REFS0) */
#define _00_COMP0_REFERENCE_VOLTAGE_DA_OUTPUT0       (0x00U)    /* the output of D/A converter 0 is selected */
#define _01_COMP0_REFERENCE_VOLTAGE_IVREF0           (0x01U)    /* external reference voltage (IVREF0) selected */

/*
    Comparator 1 Input Signal Selection Control Register (CMP1SEL)
*/
/* Selecting the input signal on the negative side of comparator 1 (C1REFS1, C1REFS0) */
#define _00_COMP1_REFERENCE_VOLTAGE_DA_OUTPUT0       (0x00U)    /* the output of D/A converter 0 is selected */
#define _01_COMP1_REFERENCE_VOLTAGE_DA_OUTPUT1       (0x01U)    /* the output of D/A converter 1 is selected */
#define _02_COMP1_REFERENCE_VOLTAGE_IVREF0           (0x02U)    /* external reference voltage (IVREF0) selected */

/*
    Comparator 2 Input Signal Selection Control Register (CMP2SEL)
*/
/* Selecting the input signal on the negative side of comparator 2 (C2REFS1, C2REFS0) */
#define _00_COMP2_REFERENCE_VOLTAGE_DA_OUTPUT0       (0x00U)    /* the output of D/A converter 0 is selected */
#define _01_COMP2_REFERENCE_VOLTAGE_DA_OUTPUT2       (0x01U)    /* the output of D/A converter 2 is selected */
#define _02_COMP2_REFERENCE_VOLTAGE_IVREF0           (0x02U)    /* external reference voltage (IVREF0) selected */
#define _03_COMP2_REFERENCE_VOLTAGE_IVREF1           (0x03U)    /* external reference voltage (IVREF1) selected */

/*
    Comparator 3 Input Signal Selection Control Register (CMP3SEL)
*/
/* Selecting the input signal on the positive side of comparator 3 (C3INS) */
#define _00_COMP3_INPUT_IVCMP3                       (0x00U)    /* an external pin (IVCMP3) is selected. */
#define _80_COMP3_INPUT_PGAO                         (0x80U)    /* PGAO (PGA output) is selected */
/* Selecting the input signal on the negative side of comparator 3 (C3REFS1, C3REFS0) */
#define _00_COMP3_REFERENCE_VOLTAGE_DA_OUTPUT0       (0x00U)    /* the output of D/A converter 0 is selected */
#define _01_COMP3_REFERENCE_VOLTAGE_DA_OUTPUT1       (0x01U)    /* the output of D/A converter 2 is selected */
#define _02_COMP3_REFERENCE_VOLTAGE_IVREF0           (0x02U)    /* external reference voltage (IVREF0) selected */
#define _03_COMP3_REFERENCE_VOLTAGE_IVREF1           (0x03U)    /* external reference voltage (IVREF1) selected */

/*
    Comparator Output Control Register 2 (COMPOCR2)
*/
/* Selecting the trigger signal output from a comparator for use with timer RX (TRXTRIG1, TRXTRIG0) */
#define _00_COMP0_OUTPUT_FOR_RX                      (0x00U)    /* interrupt output signal from comparator 0 */
#define _01_COMP1_OUTPUT_FOR_RX                      (0x01U)    /* interrupt output signal from comparator 1 */
#define _02_COMP2_OUTPUT_FOR_RX                      (0x02U)    /* interrupt output signal from comparator 2 */
#define _03_COMP3_OUTPUT_FOR_RX                      (0x03U)    /* interrupt output signal from comparator 3 */

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

