# RL78/G23 A/D Converter (Scan mode)

日本語版は[こちら](./READMEJP.md)

## Overview
This application note explains how to use the A/D converter in scan mode on the RL78/G23. It demonstrates converting analog input signals from multiple channels (ANI2 to ANI5) into digital values. The converted results are then processed and stored in on-chip RAM. The example also shows how to configure the A/D converter and manage conversion completion using interrupts.

## Software/Tool Version
| Software/Tool | Version |
|----|----|
| CS+ (IDE) | V8.10.00 |
| e2 studio (IDE) | V2023-10 (23.10.0) |
| CC-RL (C compiler) | V1.12.01 |
| IAR Embedded Workbench | V5.10.1 |
| IAR Compiler | V5.10.1 |
| Smart Configurator | V1.8.0 |
| BSP | V1.00 |

## Hardware Configuration
- RL78/G23-64p Fast Prototyping Board (RTK7RLG230CLG000BJ)
- External analog signal source

## Applicable Devices
- RL78/G23

## Link of APN
[RL78/G23 A/D Converter (Scan mode)](https://www.renesas.com/en/document/apn/rl78g23-ad-converter-scan-mode)
