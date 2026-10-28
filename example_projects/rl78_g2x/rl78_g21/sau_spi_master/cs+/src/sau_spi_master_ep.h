/***********************************************************************************************************************
 * File Name    : sau_spi_master_ep.h
 * Description  : Contains data structures and functions used in sau_spi_master_ep.c
 **********************************************************************************************************************/
/***********************************************************************************************************************
* Copyright (c) 2024 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
***********************************************************************************************************************/

#ifndef SAU_SPI_MASTER_EP_H_
#define SAU_SPI_MASTER_EP_H_

#include "Pin.h"

/* Example Project version string. */
#define EP_VERSION              ("1.0")

/* Module name string used in banner text. */
#define MODULE_NAME             "sau_spi_master"

/* Banner text printed at start-up. */
#define BANNER_INFO             "\r\n******************************************************************"\
                                "\r\n*   Renesas RL78 Example Project for "MODULE_NAME" Module       *"\
                                "\r\n*   Example Project Version %s                                  *"\
                                "\r\n******************************************************************"\
                                "\r\nRefer to readme.txt file for more details on Example Project\r\n"

/* Macro for example project information */
#define EP_INFO                 "\r\nThis Example Project demonstrates the basic usage of SAU SPI driver in"\
                                "\r\nmaster configuration on Renesas RL78 MCUs. The project writes commands"\
                                "\r\nto the slave digital thermometer module, and reads the temperature"\
                                "\r\nvalues using SAU SPI bus configured as master. The temperature values"\
                                "\r\nare continuously printed on terminal. Status information and error"\
                                "\r\nmessages will be printed on terminal during the execution of the project.\r\n\r\n"

/* PMOD MAX31723PMB1 register address: write address. */
#define CFG_WRITE_ADDR              (0x80)

/* PMOD MAX31723PMB1 register address: read address. */
#define CFG_READ_ADDR               (0x00)

/* PMOD MAX31723PMB1 register address: data read address. */
#define DATA_READ_ADDR              (0x01)

/* PMOD MAX31723PMB1 configuration value for resolution setting. */
#define SENSOR_RES_CFG              (0x06)

/* Conversion time value. */
#define CONVERSION_TIME             (200U)

/* Conversion time unit. */
#define CONVERSION_TIME_UNIT        (BSP_DELAY_MILLISECS)

/* SPI data frame size (bytes). */
#define DATA_FRAME_SIZE             (3U)

/* SPI timeout unit. */
#define SPI_TIMEOUT_UNIT            (BSP_DELAY_MILLISECS)

/* SPI timeout divisor. */
#define SPI_TIMEOUT_DIV             (1U)

/* Temperature conversion: reset value. */
#define SENSOR_RESET_VALUE          (0.0F)

/* Temperature conversion: integer part digits. */
#define INTEGER_PART                (2U)

/* Temperature conversion: fractional part digits. */
#define FRACTIONAL_PART             (1U)

/* Temperature conversion: divisor for LSB scaling. */
#define FLOAT_DIVISOR               (16.0F)

/* Temperature conversion: shift bits. */
#define SHIFT_FOUR_BITS             (4U)

/* Degree symbol string. */
#define DEGREE_SYMBOL               ("\xC2\xB0")

/* Print buffer size. */
#define BUFF_SIZE                   (30U)

/* Print delay (seconds). */
#define PRINT_DELAY                 (2U)

/* Slave Select pin location (port,pin). */
#define SS_PIN                      7,7

/* De-assert Slave Select (set SS inactive). */
#define SS_DE_ASSERT(x)             (PIN_WRITE(x) = 0)

/* Assert Slave Select (set SS active). */
#define SS_ASSERT(x)                (PIN_WRITE(x) = 1)

/** SPI events */
typedef enum e_spi_event
{
    SPI_EVENT_TRANSFER_COMPLETE = 1,   ///< The data transfer was completed
    SPI_EVENT_TRANSFER_ABORTED,        ///< The data transfer was aborted
    SPI_EVENT_ERR_MODE_FAULT,          ///< Mode fault error
    SPI_EVENT_ERR_READ_OVERFLOW,       ///< Read overflow error
    SPI_EVENT_ERR_PARITY,              ///< Parity error
    SPI_EVENT_ERR_OVERRUN,             ///< Overrun error
    SPI_EVENT_ERR_FRAMING,             ///< Framing error
    SPI_EVENT_ERR_MODE_UNDERRUN        ///< Underrun error
} spi_event_t;

/* Public function declaration */
void sau_spi_master_entry(void);
void sau_spi_callback(spi_event_t args);

#endif /* SAU_SPI_MASTER_EP_H_ */
