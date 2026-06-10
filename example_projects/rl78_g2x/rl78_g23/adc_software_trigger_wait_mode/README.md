# RL78/G23 A/D Converter (Software trigger wait mode)

日本語版は[こちら](./READMEJP.md)

## Overview
This application note explains how to use the A/D converter in software trigger wait mode on the RL78/G23. It demonstrates converting analog voltage input from the ANI2 pin into digital values. The CPU waits in HALT mode until conversion completes via interrupt. The conversion results are then stored in internal RAM. The example also covers initialization, trigger control, and interrupt-based data handling.

## Software/Tool Version
| Software/Tool | Version |
|----|----|
| CS+ (IDE) | E8.09.00 |
| e2 studio (IDE) | V2023-04 (23.4.0) |
| CC-RL (C compiler) | V1.12.00 |
| IAR Embedded Workbench | V4.21.2 |
| IAR Compiler | V4.21.2.2420 |
| Smart Configurator | V1.6.0 |
| BSP | V1.60 |

## Hardware Configuration
- RL78/G23-64p Fast Prototyping Board (RTK7RLG230CLG000BJ)
- External analog signal source

## Applicable Devices
- RL78/G23

## Link of APN
[RL78/G23 A/D Converter (Software trigger wait mode)](https://www.renesas.com/en/document/apn/rl78g23-ad-converter-software-trigger-wait-mode)
