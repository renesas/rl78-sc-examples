# RL78/G24 A/D Converter (Advanced Mode Disabled)

日本語版は[こちら](./READMEJP.md)

## Overview
This application note describes the operations of the RL78/G24 A/D converter with advanced mode disabled. Two usage examples are provided: a software-triggered no-wait mode using internal reference voltage and a hardware-triggered scan mode using RTC interrupts. The note explains configuration, operation flow, and sample code structure. It also covers how conversion results are stored in internal RAM.

## Software/Tool Version
| Software/Tool | Version |
|----|----|
| CS+ (IDE) | V8.12.00 |
| e2 studio (IDE) | 2024-10 (24.10.0) |
| CC-RL (C compiler) | V1.14.00 |
| IAR Embedded Workbench | V5.10.3 |
| IAR Compiler | V5.10.3 |
| Smart Configurator | V.1.11.0 |
| BSP | V.1.70 |

## Hardware Configuration
- RL78/G24 Fast Prototyping Board (RTK7RLG240C00000BJ)
- External analog signal source

## Applicable Devices
- RL78/G24

## Link of APN
[RL78/G24 A/D Converter (Advanced Mode Disabled)](https://www.renesas.com/en/document/apn/rl78g24-ad-converter-advanced-mode-disabled-rev100)
