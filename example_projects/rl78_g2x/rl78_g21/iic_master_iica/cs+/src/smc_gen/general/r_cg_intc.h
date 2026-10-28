/*
* Copyright (c) 2021 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
* File Name        : r_cg_intc.h
* Version          : 1.0.200
* Device(s)        : R7F103GLJxFB
* Description      : General header file for INTC peripheral.
***********************************************************************************************************************/

#ifndef INTC_H
#define INTC_H

/***********************************************************************************************************************
Macro definitions (Register bit)
***********************************************************************************************************************/
/*
    External Interrupt Rising Edge Enable Register 0 (EGP0)
*/
/* INTPn pin valid edge selection (EGPn) */
#define _00_INTP7_EDGE_RISING_UNSEL        (0x00U)    /* rising edge not selected for INTP7 pin */
#define _80_INTP7_EDGE_RISING_SEL          (0x80U)    /* rising edge selected for INTP7 pin */
#define _00_INTP6_EDGE_RISING_UNSEL        (0x00U)    /* rising edge not selected for INTP6 pin */
#define _40_INTP6_EDGE_RISING_SEL          (0x40U)    /* rising edge selected for INTP6 pin */
#define _00_INTP5_EDGE_RISING_UNSEL        (0x00U)    /* rising edge not selected for INTP5 pin */
#define _20_INTP5_EDGE_RISING_SEL          (0x20U)    /* rising edge selected for INTP5 pin */
#define _00_INTP4_EDGE_RISING_UNSEL        (0x00U)    /* rising edge not selected for INTP4 pin */
#define _10_INTP4_EDGE_RISING_SEL          (0x10U)    /* rising edge selected for INTP4 pin */
#define _00_INTP3_EDGE_RISING_UNSEL        (0x00U)    /* rising edge not selected for INTP3 pin */
#define _08_INTP3_EDGE_RISING_SEL          (0x08U)    /* rising edge selected for INTP3 pin */
#define _00_INTP2_EDGE_RISING_UNSEL        (0x00U)    /* rising edge not selected for INTP2 pin */
#define _04_INTP2_EDGE_RISING_SEL          (0x04U)    /* rising edge selected for INTP2 pin */
#define _00_INTP1_EDGE_RISING_UNSEL        (0x00U)    /* rising edge not selected for INTP1 pin*/
#define _02_INTP1_EDGE_RISING_SEL          (0x02U)    /* rising edge selected for INTP1 pin */
#define _00_INTP0_EDGE_RISING_UNSEL        (0x00U)    /* rising edge not selected for INTP0 pin */
#define _01_INTP0_EDGE_RISING_SEL          (0x01U)    /* rising edge selected for INTP0 pin */

/*
    External Interrupt Falling Edge Enable Register 0 (EGN0)
*/
/* INTPn pin valid edge selection (EGNn) */
#define _00_INTP7_EDGE_FALLING_UNSEL       (0x00U)    /* falling edge not selected for INTP7 pin */
#define _80_INTP7_EDGE_FALLING_SEL         (0x80U)    /* falling edge selected for INTP7 pin */
#define _00_INTP6_EDGE_FALLING_UNSEL       (0x00U)    /* falling edge not selected for INTP6 pin */
#define _40_INTP6_EDGE_FALLING_SEL         (0x40U)    /* falling edge selected for INTP6 pin */
#define _00_INTP5_EDGE_FALLING_UNSEL       (0x00U)    /* falling edge not selected for INTP5 pin */
#define _20_INTP5_EDGE_FALLING_SEL         (0x20U)    /* falling edge selected for INTP5 pin */
#define _00_INTP4_EDGE_FALLING_UNSEL       (0x00U)    /* falling edge not selected for INTP4 pin */
#define _10_INTP4_EDGE_FALLING_SEL         (0x10U)    /* falling edge selected for INTP4 pin */
#define _00_INTP3_EDGE_FALLING_UNSEL       (0x00U)    /* falling edge not selected for INTP3 pin */
#define _08_INTP3_EDGE_FALLING_SEL         (0x08U)    /* falling edge selected for INTP3 pin */
#define _00_INTP2_EDGE_FALLING_UNSEL       (0x00U)    /* falling edge not selected for INTP2 pin */
#define _04_INTP2_EDGE_FALLING_SEL         (0x04U)    /* falling edge selected for INTP2 pin */
#define _00_INTP1_EDGE_FALLING_UNSEL       (0x00U)    /* falling edge not selected for INTP1 pin */
#define _02_INTP1_EDGE_FALLING_SEL         (0x02U)    /* falling edge selected for INTP1 pin */
#define _00_INTP0_EDGE_FALLING_UNSEL       (0x00U)    /* falling edge not selected for INTP0 pin */
#define _01_INTP0_EDGE_FALLING_SEL         (0x01U)    /* falling edge selected for INTP0 pin */

/*
    External Interrupt Rising Edge Enable Register 1 (EGP1)
*/
/* INTPn pin valid edge selection (EGPn) */
#define _00_INTP11_EDGE_RISING_UNSEL       (0x00U)    /* rising edge not selected for INTP11 pin*/
#define _08_INTP11_EDGE_RISING_SEL         (0x08U)    /* rising edge selected for INTP11 pin */
#define _00_INTP10_EDGE_RISING_UNSEL       (0x00U)    /* rising edge not selected for INTP10 pin */
#define _04_INTP10_EDGE_RISING_SEL         (0x04U)    /* rising edge selected for INTP10 pin */
#define _00_INTP9_EDGE_RISING_UNSEL        (0x00U)    /* rising edge not selected for INTP9 pin*/
#define _02_INTP9_EDGE_RISING_SEL          (0x02U)    /* rising edge selected for INTP9 pin */
#define _00_INTP8_EDGE_RISING_UNSEL        (0x00U)    /* rising edge not selected for INTP8 pin */
#define _01_INTP8_EDGE_RISING_SEL          (0x01U)    /* rising edge selected for INTP8 pin */

/*
    External Interrupt Falling Edge Enable Register 1 (EGN1)
*/
/* INTPn pin valid edge selection (EGNn) */
#define _00_INTP11_EDGE_FALLING_UNSEL      (0x00U)    /* falling edge not selected for INTP11 pin */
#define _08_INTP11_EDGE_FALLING_SEL        (0x08U)    /* falling edge selected for INTP11 pin */
#define _00_INTP10_EDGE_FALLING_UNSEL      (0x00U)    /* falling edge not selected for INTP10 pin */
#define _04_INTP10_EDGE_FALLING_SEL        (0x04U)    /* falling edge selected for INTP10 pin */
#define _00_INTP9_EDGE_FALLING_UNSEL       (0x00U)    /* falling edge not selected for INTP9 pin */
#define _02_INTP9_EDGE_FALLING_SEL         (0x02U)    /* falling edge selected for INTP9 pin */
#define _00_INTP8_EDGE_FALLING_UNSEL       (0x00U)    /* falling edge not selected for INTP8 pin */
#define _01_INTP8_EDGE_FALLING_SEL         (0x01U)    /* falling edge selected for INTP8 pin */

/*
    Program Status Word (PSW)
*/
/* Interrupt request acknowledgment enable/disable (IE) */
#define _00_INTP_REQUEST_ACK_DISABLED      (0x00U)    /* disabled */
#define _80_INTP_REQUEST_ACK_ENABLED       (0x80U)    /* enabled */
/* Priority of interrupt currently being serviced (ISP1 - ISP0) */
#define _06_INTP_PRIORITY_LEVEL_ALL        (0x06U)    /* enables all interrupts */
#define _04_INTP_PRIORITY_LEVEL_0_2        (0x04U)    /* enables interrupt of level 0 to 2 */
#define _02_INTP_PRIORITY_LEVEL_0_1        (0x02U)    /* enables interrupt of level 0 and 1 */
#define _00_INTP_PRIORITY_LEVEL_0          (0x00U)    /* enables interrupt of level 0 */
#define _F9_INTP_PRIORITY_LEVEL_CLEAR      (0xF9U)    /* bits of ISP1 - ISP0 clear */

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
