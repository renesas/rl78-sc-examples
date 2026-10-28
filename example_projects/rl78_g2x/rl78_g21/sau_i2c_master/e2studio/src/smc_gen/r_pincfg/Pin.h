/*
* Copyright (c) 2021 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
* File Name        : Pin.h
* Version          : 1.0.0
* Device(s)        : R7F103GLJxFB
* Description      : This file implements SMC pin code generation.
***********************************************************************************************************************/

#ifndef PIN_H
#define PIN_H

/***********************************************************************************************************************
Macro definitions (Register bit)
***********************************************************************************************************************/

/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/

/* User's guide for symbolic name.
 * The generated symbolic names can be used in the user application as follows: 
 *
 * Example: Toggle LED1 at Pin P54.
 *  There are 2 ways to toggle LED1
 *   1) Using symbolic name macro
 *    Assuming the symbolic name for P54 is "LED1", the generated macro definition will be:
 *         #define LED1    5,4
 *
 *    To use this macro definition to toggle the LED1, call the symbolic name APIs:
 *         PIN_WRITE(LED1) = ~PIN_READ(LED1)
 *
 *   2) Not using symbolic name macro
 *    Call the symbolic name APIs directly
 *         PIN_WRITE(5,4) = ~PIN_READ(5,4)
 */

/* Symbolic name */
#define COM_TxD0        1,2
#define COM_RxD0        1,1
#define LED2        3,4
#define SW        13,7
#define LED1        3,3

/* User's guide for pin function assignment macros
 * The generated macro definitions can be used in the user application as follows: 
 *
 * Example: Set SCLA0 port to 1U.
 *  PIN_WRITE(SMC_PIN_TO02) = 1;
 *  Xxx = PIN_READ(R_xxx_TI00_Pin);
 */

/* PIOR pin function assignments */
#define SMC_PIN_SDA10        0,3
#define SMC_PIN_SCL10        0,4

/* Pin write helper */
#define PIN_WRITE_HELPER(x,y)                    ((P##x##_bit.no##y))
/* Pin read helper */
#define PIN_READ_HELPER(x,y)                     ((P##x##_bit.no##y))

/* Pin write API */
#define PIN_WRITE(...)                           (PIN_WRITE_HELPER(__VA_ARGS__))
/* Pin read API */
#define PIN_READ(...)                            (PIN_READ_HELPER(__VA_ARGS__))

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Global functions
***********************************************************************************************************************/
void R_Pins_Create(void);
/* Start user code for function. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#endif
