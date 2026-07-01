# RL78/G22 A/D Converter (Software Trigger and Sequential Conversion Modes)

日本語版は[こちら](./READMEJP.md)

## Overview
This application note explains how to use the RL78/G22 A/D converter with software trigger and sequential conversion modes. It demonstrates converting analog voltage input from a single channel into digital values. The conversion results are processed and stored in on-chip RAM. The sample program uses HALT mode to wait for completion of A/D conversion and then handles the result via interrupt processing.

## Software/Tool Version
| Software/Tool | Version |
|----|----|
| CS+ (IDE) | E8.10.00 |
| e2 studio (IDE) | V2023-01 (23.1.0) |
| CC-RL (C compiler) | V1.12.01 |
| IAR Embedded Workbench | V5.10.1 |
| IAR Compiler | V5.10.1.2673 |
| Smart Configurator | V1.5.0 |
| BSP | V1.40 |

## Hardware Configuration
- RL78/G22-48p Fast Prototyping Board
- External analog signal source

## Applicable Devices
- RL78/G22

## Link of APN
[RL78/G22 A/D Converter (Software Trigger and Sequential Conversion Modes)](https://www.renesas.com/en/document/apn/rl78g22-ad-converter-software-trigger-and-sequential-conversion-modes-rev102)
