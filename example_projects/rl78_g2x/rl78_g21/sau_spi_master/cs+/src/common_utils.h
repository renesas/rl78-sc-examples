/***********************************************************************************************************************
 * File Name    : common_utils.h
 * Description  : Contains macros, data structures, and functions commonly used in the EP.
 **********************************************************************************************************************/
/***********************************************************************************************************************
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
***********************************************************************************************************************/

#ifndef COMMON_UTILS_H_
#define COMMON_UTILS_H_

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "SAU_SPI.h"
#include "SERIAL_TERM/serial.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/
/* Macros for the terminal interface */

/* Terminal receive buffer size. */
#define TERM_BUFFER_SIZE              (SERIAL_RX_MAX_SIZE)

/* Initialize the terminal interface. */
#define TERM_INIT()                   (serial_init())

/* Print to the terminal (single argument). */
#define TERM_PRINTF0(fmt)             (serial_printf((fmt)))

/* Print to the terminal (variadic). */
#define TERM_PRINTF(fmt, ...)         (serial_printf((fmt), __VA_ARGS__))

/* Read data from the terminal. */
#define TERM_READ(buf, len)           (serial_read((buf), (len)))

/* Check whether received data is available. */
#define TERM_HAS_DATA()               (serial_has_data())

/* Check whether a key input is available. */
#define TERM_HAS_KEY()                (serial_has_key())

/* Deinitialize the terminal interface. */
#define TERM_DEINIT()                 (serial_deinit())

/* Macros commonly used */

/* Error log enable flag. */
#define LVL_ERR                       (1U)

/* Default reset value. */
#define RESET_VALUE                   (0x00)

/* Null character constant. */
#define NULL_CHAR                     ('\0')

/* Module close state constant. */
#define MODULE_CLOSE                  (0U)

/* Application print macro (single argument). */
#define APP_PRINT0(fn_)               (TERM_PRINTF0((fn_)))

/* Application print macro (variadic). */
#define APP_PRINT(fn_, ...)           (TERM_PRINTF((fn_), __VA_ARGS__))

#if (LVL_ERR)

/* Application error print macro (single argument). */
#define APP_ERR_PRINT0(fn_)           (TERM_PRINTF("\r\n[ERR] In Function: %s(), %s", __func__, (fn_)))

/* Application error print macro (variadic). */
#define APP_ERR_PRINT(fn_, ...)       (TERM_PRINTF("\r\n[ERR] In Function: %s(), %s", __func__, (fn_), __VA_ARGS__))

#else

/* No-op when error logging is disabled (single argument). */
#define APP_ERR_PRINT0(fn_)           ((void)0)

/* No-op when error logging is disabled (variadic). */
#define APP_ERR_PRINT(fn_, ...)       ((void)0)

#endif /* LVL_ERR */

/* If condition is true, print an error message and return the specified error code. */
#define APP_ERR_RET0(con, err, fn_)     do {                  \
                                        if ((con))            \
                                        {                     \
                                            APP_ERR_PRINT0((fn_)); \
                                            return (err);     \
                                        }                     \
                                      } while(0)

/* Execute a break instruction. */
#define ERROR_TRAP                      do { __brk(); } while(0)

/* If err is nonzero, print the error code and trap. */
#define APP_ERR_TRAP(err)               do {                  \
                                        if ((err))            \
                                        {                     \
                                            APP_PRINT("\r\nReturned Error Code: 0x%x  \r\n", (err)); \
                                            TERM_DEINIT();    \
                                            /* Trap upon the error */ \
                                            ERROR_TRAP;        \
                                        }                     \
                                      } while(0)

/* Read application input from the terminal. */
#define APP_READ(buf, len)              (TERM_READ((buf), (len)))

/* Check whether application input data is available. */
#define APP_CHECK_DATA                  (TERM_HAS_DATA())

/* Check whether an application key input is available. */
#define APP_CHECK_KEY                   (TERM_HAS_KEY())

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Public function prototypes
 **********************************************************************************************************************/

#endif /* COMMON_UTILS_H_ */
