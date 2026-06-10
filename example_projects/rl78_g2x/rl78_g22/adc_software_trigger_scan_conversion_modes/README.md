# RL78/G22 A/D Converter (Software Trigger and Scan Conversion Modes)

日本語版は[こちら](./READMEJP.md)

## Overview
This application note describes how to use the A/D converter of RL78/G22 with software trigger, scan mode, and sequential conversion mode. It demonstrates converting analog voltages from multiple input pins into digital values. The converted data is processed and stored in internal RAM. The sample code uses HALT mode to wait for conversion completion. It also illustrates channel switching and interrupt-driven processing.

## Software/Tool Version
| Software/Tool | Version |
|----|----|
| CS+ (IDE) | 9.11.04 |
| e2 studio (IDE) | V2024-01 (24.1.0) |
| CC-RL (C compiler) | V1.13.00 |
| IAR Embedded Workbench | V5.10.3 |
| IAR Compiler | V5.10.3 |
| Smart Configurator | V1.10.0 |
| BSP | V1.62 |

## Hardware Configuration
- RL78/G22 Fast Prototyping Board
- External analog signal source

## Applicable Devices
- RL78/G22

## Link of APN
[RL78/G22 A/D Converter (Software Trigger and Scan Conversion Modes)](https://www.renesas.com/en/document/apn/rl78g22-ad-converter-software-trigger-and-scan-conversion-modes-rev110)
