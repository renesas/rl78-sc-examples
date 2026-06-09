# RL78/G22 Serial Interface IICA (for Master Transmission/Reception)

日本語版は[こちら](./READMEJP.md)

## Overview
This application note describes how to implement master transmission and reception using the serial interface IICA. It explains a single-master system that performs address transmission, data transmission, and data reception. The master selects a slave device via address specification and then exchanges data. The document also includes sample code and operation conditions for verification.

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
- Status LED
- Error LED
- Switch

## Applicable Devices
- RL78/G22

## Link of APN
[RL78/G22 Serial Interface IICA (for Master Transmission/Reception)](https://www.renesas.com/en/document/apn/rl78g22-timer-array-unit-pulse-interval-measurementwidth-rev102)
