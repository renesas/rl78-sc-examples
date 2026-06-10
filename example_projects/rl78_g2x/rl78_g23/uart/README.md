# RL78/G23 Serial Array Unit (UART Communication)

日本語版は[こちら](./READMEJP.md)

## Overview
This application note describes how to use UART communication via the serial array unit (SAU) on the RL78/G23. It demonstrates receiving ASCII data from a counterpart device and generating appropriate response messages. The sample code handles normal data as well as error conditions such as parity, framing, and overrun. It also shows interrupt-based transmit and receive processing using SAU channels.

## Software/Tool Version
| Software/Tool | Version |
|----|----|
| CS+ (IDE) | V8.09.00 |
| e2 studio (IDE) | V2023-01 (23.1.0) |
| CC-RL (C compiler) | V1.12.00 |
| IAR Embedded Workbench | V4.21.2 |
| IAR Compiler | V4.21.2.2420 |
| Smart Configurator | V1.4.0 |
| BSP | V1.30 |

## Hardware Configuration
- RL78/G23 Fast Prototyping Board (RTK7RLG230CLG000BJ)

## Applicable Devices
- RL78/G23

## Link of APN
[RL78/G23 Serial Array Unit (UART Communication)](https://www.renesas.com/en/document/apn/rl78g23-serial-array-unit-uart-communication-rev110)
