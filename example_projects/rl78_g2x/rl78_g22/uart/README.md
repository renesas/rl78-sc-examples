# RL78/G22 Serial Array Unit (UART Communication)

日本語版は[こちら](./READMEJP.md)

## Overview
This application note explains how to use UART communication through the serial array unit (SAU) on the RL78/G22. The system receives ASCII characters from a counterpart device and analyzes them to generate responses. The sample program demonstrates transmission and reception using UART0 with interrupt handling. It also shows how to manage errors such as parity, framing, and overrun by responding with specific messages.

## Software/Tool Version
| Software/Tool | Version |
|----|----|
| CS+ (IDE) | V8.11.00 |
| e2 studio (IDE) | V2024-04 |
| CC-RL (C compiler) | V1.13.01 |
| IAR Embedded Workbench | V5.10.1 |
| IAR Compiler | V5.10.1 |
| Smart Configurator | V1.10.0 |
| BSP | V1.6.2 |

## Hardware Configuration
- RL78/G22-48p Fast Prototyping Board

## Applicable Devices
- RL78/G22

## Link of APN
[RL78/G22 Serial Array Unit (UART Communication)](https://www.renesas.com/en/document/apn/rl78g22-serial-array-unit-uart-communication-rev100)
