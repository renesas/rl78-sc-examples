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
* File Name        : r_cg_comp.h
* Version          : 1.0.20
* Device(s)        : R7F100GLGxFB
* Description      : General header file for COMP peripheral.
***********************************************************************************************************************/

#ifndef COMP_H
#define COMP_H

/***********************************************************************************************************************
Macro definitions (Register bit)
***********************************************************************************************************************/
/*
    Peripheral Enable Register 1 (PER1)
*/
/* Control of comparator input clock (CMPEN) */
#define _00_COMP_CLOCK_STOP                                   (0x00U)    /* stops supply of input clock */
#define _20_COMP_CLOCK_SUPPLY                                 (0x20U)    /* supplies input clock */

/*
    Peripheral Reset Control Register 1 (PRR1)
*/
/* Comparator reset control (CMPRES) */
#define _00_COMP_CLOCK_RELEASE                                (0x00U)    /* release reset of comparator */
#define _20_COMP_CLOCK_RESET                                  (0x20U)    /* comparator is in reset state */

/*
    Comparator Mode Setting Register (COMPMDR)
*/
#define _F0_COMP0_COMPMDR_CLEAR                               (0xF0U)    /* clear comparator 0 COMPMDR register */
#define _0F_COMP1_COMPMDR_CLEAR                               (0x0FU)    /* clear comparator 1 COMPMDR register */
/* Comparator 1 monitor flag (C1MON) */
#define _00_COMP1_FLAG_REFERENCE_0                            (0x00U)    /* IVCMP1 < comparator 1 reference voltage
                                                                            (IVREF1 or D/A converter output 0) */
#define _80_COMP1_FLAG_REFERENCE_1                            (0x80U)    /* IVCMP1 > comparator 1 reference voltage
                                                                            (IVREF1 or D/A converter output 0) */
/* Comparator 1 reference voltage selection (C1VRF) */
#define _00_COMP1_REFERENCE_VOLTAGE_IVREF1                    (0x00U)    /* supplied through the IVREF1 pin */
#define _40_COMP1_REFERENCE_VOLTAGE_DA_OUTPUT0                (0x40U)    /* supplied through D/A converter output 0 */
/* Comparator 1 reference voltage range selection (C1LVL) */
#define _00_COMP1_0_TO_VDD_14                                 (0x00U)    /* 0 to VDD-1.4V */
#define _20_COMP1_14_TO_VDD                                   (0x20U)    /* 1.4V to VDD   */
/* Comparator 1 operation enable (C1ENB) */
#define _00_COMP1_OPERATION_DISABLED                          (0x00U)    /* disable comparator 1 operation */
#define _10_COMP1_OPERATION_ENABLED                           (0x10U)    /* enable comparator 1 operation */
/* Comparator 0 monitor flag (C0MON) */
#define _00_COMP0_FLAG_REFERENCE_0                            (0x00U)    /* IVCMP0 < comparator 0 reference voltage
                                                                          (IVREF0 or internal reference voltage) */
#define _08_COMP0_FLAG_REFERENCE_1                            (0x08U)    /* IVCMP0 > comparator 0 reference voltage
                                                                          (IVREF0 or internal reference voltage) */
/* Comparator 0 reference voltage selection (C0VRF) */
#define _00_COMP0_REFERENCE_VOLTAGE_IVREF0                    (0x00U)    /* supplied through the IVREF0 pin */
#define _04_COMP0_REFERENCE_VOLTAGE_INTERNAL                  (0x04U)    /* supplied through internal reference voltage */
/* Comparator 0 reference voltage range selection (C0LVL) */
#define _00_COMP0_0_TO_VDD_14                                 (0x00U)    /* 0 to VDD-1.4V */
#define _02_COMP0_14_TO_VDD                                   (0x02U)    /* 1.4V to VDD   */
/* Comparator 0 operation enable (C0ENB) */
#define _00_COMP0_OPERATION_DISABLED                          (0x00U)    /* disable comparator 0 operation */
#define _01_COMP0_OPERATION_ENABLED                           (0x01U)    /* enable comparator 0 operation */

/*
    Comparator Filter Control Register (COMPFIR)
*/
#define _F0_COMP0_COMPFIR_CLEAR                               (0xF0U)    /* clear comparator 0 COMPFIR register */
#define _0F_COMP1_COMPFIR_CLEAR                               (0x0FU)    /* clear comparator 1 COMPFIR register */
/* Comparator 1 edge detection selection (C1EDG) */
#define _00_COMP1_ONE_EDGE_INTERRUPT                          (0x00U)    /* interrupt request by comparator 1 one-edge detection */
#define _80_COMP1_BOTH_EDGES_INTERRUPT                        (0x80U)    /* interrupt request by comparator 1 both-edge detection */
/* Comparator 1 edge polarity selection (C1EPO) */
#define _00_COMP1_RISING_INTERRUPT                            (0x00U)    /* interrupt request at comparator 1 rising edge */
#define _40_COMP1_FALLING_INTERRUPT                           (0x40U)    /* interrupt request at comparator 1 falling edge */
/* Comparator 1 filter selection (C1FCK1, C1FCK0) */
#define _00_COMP1_FILTER_NONE                                 (0x00U)    /* disable filter */
#define _10_COMP1_FILTER_FCLK                                 (0x10U)    /* sampling at fCLK */
#define _20_COMP1_FILTER_FCLK_8                               (0x20U)    /* sampling at fCLK/2^3 */
#define _30_COMP1_FILTER_FCLK_32                              (0x30U)    /* sampling at fCLK/2^5 */
/* Comparator 0 edge detection selection (C0EDG) */
#define _00_COMP0_ONE_EDGE_INTERRUPT                          (0x00U)    /* interrupt request by comparator 0 one-edge detection */
#define _08_COMP0_BOTH_EDGES_INTERRUPT                        (0x08U)    /* interrupt request by comparator 0 both-edge detection */
/* Comparator 0 edge polarity selection (C0EPO) */
#define _00_COMP0_RISING_INTERRUPT                            (0x00U)    /* interrupt request at comparator 0 rising edge */
#define _04_COMP0_FALLING_INTERRUPT                           (0x04U)    /* interrupt request at comparator 0 falling edge */
/* Comparator 0 filter selection (C0FCK1, C0FCK0) */
#define _00_COMP0_FILTER_NONE                                 (0x00U)    /* disable filter */
#define _01_COMP0_FILTER_FCLK                                 (0x01U)    /* sampling at fCLK */
#define _02_COMP0_FILTER_FCLK_8                               (0x02U)    /* sampling at fCLK/2^3 */
#define _03_COMP0_FILTER_FCLK_32                              (0x03U)    /* sampling at fCLK/2^5 */

/*
    Comparator Output Control Register (COMPOCR)
*/
#define _78_COMP0_COMPOCR_CLEAR                               (0x78U)    /* clear COMPOCR register for Comparator 0 */
#define _0F_COMP1_COMPOCR_CLEAR                               (0x0FU)    /* clear COMPOCR register for Comparator 1 */
/* Comparator speed selection (SPDMD) */
#define _00_COMP_SPEED_LOW                                    (0x00U)    /* low-speed mode */
#define _80_COMP_SPEED_HIGH                                   (0x80U)    /* high-speed mode */
/* VCOUT1 output polarity selection (C1OP) */
#define _00_COMP1_OUTPUT_NORMAL                               (0x00U)    /* VCOUT1 normal output */
#define _40_COMP1_OUTPUT_INVERTED                             (0x40U)    /* VCOUT1 inverted output */
/* VCOUT1 output selection (C1OE) */
#define _00_COMP1_OUTPUT_DISABLE                              (0x00U)    /* disable VCOUT1 output */
#define _20_COMP1_OUTPUT_ENABLE                               (0x20U)    /* enable VCOUT1 output */
/* Comparator 1 interrupt request enable (C1IE) */
#define _00_COMP1_INTERRUPT_DISABLE                           (0x00U)    /* disable interrupt request */
#define _10_COMP1_INTERRPUT_ENABLE                            (0x10U)    /* enable interrupt request */
/* VCOUT0 output polarity selection (C0OP) */
#define _00_COMP0_OUTPUT_NORMAL                               (0x00U)    /* VCOUT0 normal output */
#define _04_COMP0_OUTPUT_INVERTED                             (0x04U)    /* VCOUT0 inverted output */
/* VCOUT0 output selection (C0OE) */
#define _00_COMP0_OUTPUT_DISABLE                              (0x00U)    /* disable VCOUT0 output */
#define _02_COMP0_OUTPUT_ENABLE                               (0x02U)    /* enable VCOUT0 output */
/* Comparator 0 interrupt request enable (C0IE) */
#define _00_COMP0_INTERRUPT_DISABLE                           (0x00U)    /* disable interrupt request */
#define _01_COMP0_INTERRPUT_ENABLE                            (0x01U)    /* enable interrupt request */

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
