# RL78/G23 UART Reception in STOP Mode Using the UARTA Function

日本語版は[こちら](./READMEJP.md)

## Overview
This application node describes how to receive data through UART in STOP mode by using the RL78/G23 serial interface UARTA function and key interrupt function. When data is sent from the device on the opposite side, the RL78/G23 detects the falling edge of the start bit by using the key interrupt function, and then releases the STOP mode. When the STOP mode is released, the UARTA function starts reception of data following the start bit through UART. Note that the time required for releasing the STOP mode causes a delay in starting the UARTA operation.

## Software/Tool Version
| Software/Tool | Version |
|----|----|
| CS+ (IDE) | V8.09.00 |
| e2 studio (IDE) | V2023-01 (23.1.0) |
| CC-RL (C compiler) | V1.12.00 |
| IAR Embedded Workbench | V4.21.2 |
| IAR Compiler | V4.21.2.2420 |
| Smart Configurator | V.1.4.0 |
| BSP | V.1.30 |

## Hardware Configuration
- RL78/G23 Fast Prototyping Board (RTK7RLG230CLG000BJ)

## Applicable Devices
- RL78/G23

## Link of APN
[RL78/G23 UART Reception in STOP Mode Using the UARTA Function](https://www.renesas.com/en/document/apn/rl78g23-uart-reception-stop-mode-using-uarta-function-rev110)
