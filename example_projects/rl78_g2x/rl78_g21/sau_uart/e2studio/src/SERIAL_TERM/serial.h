/***********************************************************************************************************************
* File Name    : serial.h
* Description  : Contains macros, data structures, and common functions used for serial.c
***********************************************************************************************************************/
/***********************************************************************************************************************
* Copyright (c) 2024 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
***********************************************************************************************************************/

#ifndef SERIAL_H_
#define SERIAL_H_

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include <stdint.h>
#include "common_utils.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/
/* Macros for the UART baud rate configuration */
#define SERIAL_BAUD_RATE                    (115200U)
#define SERIAL_ERR_X1000                    (4000U)
#define SERIAL_MODULATION                   (0U)

/* Macros for time-out operation */
#define SAFETY_FACTOR                       (2U)
#define SERIAL_BIT_FRAME                    (10U)
#define SECOND_TO_MICROSECOND               (1000000U)
#define SERIAL_TIME_US                      (SECOND_TO_MICROSECOND / (SERIAL_BAUD_RATE / SERIAL_BIT_FRAME))

/* Macros for the UART software configuration */
#define SERIAL_TX_MAX_SIZE                  (2048U)
#define SERIAL_RX_MAX_SIZE                  (256U)

/* Macros for special character definitions */
#define SERIAL_CHAR_BS                      (0x08)
#define SERIAL_CHAR_LF                      (0x0A)
#define SERIAL_CHAR_CR                      (0x0D)

/* Macros for special values */
#define SERIAL_TRUE                         (1U)
#define SERIAL_FALSE                        (0U)
#define SERIAL_DATA_ZERO                    (0x00)
#define SERIAL_DATA_ONE                     (0x01)

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/
/** UART Event codes */
typedef enum e_sf_event
{
    UART_EVENT_RX_COMPLETE   = (1UL << 0), ///< Receive complete event
    UART_EVENT_TX_COMPLETE   = (1UL << 1), ///< Transmit complete event
    UART_EVENT_RX_CHAR       = (1UL << 2), ///< Character received
    UART_EVENT_ERR_PARITY    = (1UL << 3), ///< Parity error event
    UART_EVENT_ERR_FRAMING   = (1UL << 4), ///< Mode fault error event
    UART_EVENT_ERR_OVERFLOW  = (1UL << 5), ///< FIFO Overflow error event
    UART_EVENT_BREAK_DETECT  = (1UL << 6), ///< Break detect error event
    UART_EVENT_TX_DATA_EMPTY = (1UL << 7), ///< Last byte is transmitting, ready for more data
} uart_event_t;

/***********************************************************************************************************************
 * Public function prototypes
 **********************************************************************************************************************/
void serial_callback(uart_event_t event);
uint32_t serial_init(void);
void serial_deinit(void);
uint32_t serial_printf(char * p_format, ...);
uint32_t serial_read(void * const p_buffer, uint32_t buffer_size);
uint32_t serial_has_data(void);
uint32_t serial_has_key(void);

#endif /* SERIAL_H_ */
