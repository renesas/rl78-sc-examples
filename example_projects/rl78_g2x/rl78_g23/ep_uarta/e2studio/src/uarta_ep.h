/***********************************************************************************************************************
 * File Name    : uarta_ep.h
 * Description  : Contains data structures and functions used in uarta_ep.c
 **********************************************************************************************************************/
/***********************************************************************************************************************
* Copyright (c) 2024 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
***********************************************************************************************************************/

#ifndef UARTA_EP_H_
#define UARTA_EP_H_

#include <stdint.h>

/* Example Project information */
#define EP_VERSION      "1.0"
#define MODULE_NAME     "uarta"

#define BANNER_INFO     "\r\n******************************************************************"\
                        "\r\n*   Renesas RL78 Example Project for "MODULE_NAME" Module                *"\
                        "\r\n*   Example Project Version %s                                  *"\
                        "\r\n******************************************************************"\
                        "\r\nRefer to readme.txt file for more details on Example Project and" \
                        "\r\nRL78 User's Manual for more information about "MODULE_NAME" driver\r\n"

#define EP_INFO         "\r\nThe Example Project demonstrates the basic functionality of the UARTA driver on"\
                        "\r\nRenesas RL78 MCUs. Upon successfully initializing the UARTA module,"\
                        "\r\nEP information and configuration instructions will be displayed on UART0 (USB Type-C)."\
                        "\r\nThe user can enter an ASCII string (less than 256 characters) on UARTA (PmodUSBUART)"\
                        "\r\nand press the enter-key to send it to the RL78 board."\
                        "\r\nThe RL78 board will echo the received string back to UARTA and also print the received"\
                        "\r\nstring log on UART0.\r\n"

#define EP_MESSAGE      "\r\nPlease open two Tera Term applications on the PC and set up the serial connections to:"\
                        "\r\n1) UARTA (PmodUSBUART): user input / echo back"\
                        "\r\n2) UART0 (USB Type-C): EP information / received string log"\
                        "\r\nBoth ports: 115200 bps, 8 data bits, no parity, 1 stop bit, no flow control.\r\n\r\n"

/* Macro for UARTA receive */
#define NULL_CHAR                   ('\0')
#define CR_ASCII                    (0x0D)
#define LF_ASCII                    (0x0A)
#define BUFFER_LEN                  (256U)

/* Macro for UARTA transmit */
#define TIME_OUT_FOR_ONE_BYTE       (1000)
#define TIME_OUT_VALUE              (1U)
#define TIME_OUT_UNIT               (BSP_DELAY_MICROSECS)

/* Public function declarations */
void uarta_ep_entry(void);

#endif /* UARTA_EP_H_ */
