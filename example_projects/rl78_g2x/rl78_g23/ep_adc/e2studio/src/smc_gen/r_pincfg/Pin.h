/*
* Copyright (c) 2021 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
* File Name        : Pin.h
* Version          : 1.0.0
* Device(s)        : R7F100GSNxFB
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
#define LED1        5,0
#define LED2        5,1

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
