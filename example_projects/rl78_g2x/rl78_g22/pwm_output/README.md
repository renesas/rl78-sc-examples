# RL78/G22 Serial Interface IICA (for Slave Transmission/Reception)

日本語版は[こちら](./READMEJP.md)

## Overview
This application note describes how to implement slave transmission and reception using the IICA serial interface on RL78/G22. It explains operation in a single-master I2C system including address reception and data communication. The document provides detailed timing charts, command control for serial RAM, and sequential read/write operations. Sample code and implementation details are also provided for practical use.

## Software/Tool Version
| Software/Tool | Version |
|----|----|
| CS+ (IDE) | V8.11.00 |
| e2studio (IDE) | V2024-04 |
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
[RL78/G22 Serial Interface IICA (for Slave Transmission/Reception)](https://www.renesas.com/en/document/apn/rl78g22-timer-array-unit-pwm-output-rev101)
