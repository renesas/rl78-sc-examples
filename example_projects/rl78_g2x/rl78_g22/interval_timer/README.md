# RL78/G22 Timer Array Unit (Interval timer)

日本語版は[こちら](./READMEJP.md)

## Overview
This application note explains how to use the interval timer function of the Timer Array Unit (TAU) on RL78/G22. The timer generates periodic interrupts, and the LED output is toggled each time an interrupt occurs. In addition, the interrupt cycle can be dynamically changed based on how many times a switch is pressed. The document provides configuration steps, operation flow, and sample code for practical implementation.

## Software/Tool Version
| Software/Tool | Version |
|----|----|
| CS+ (IDE) | V8.10.00 |
| e2 studio (IDE) | V2023-10 (23.10.0) |
| CC-RL (C compiler) | V1.12.01 |
| IAR Embedded Workbench | V5.10.1 |
| IAR Compiler | V5.10.1 |
| Smart Configurator | V1.7.0 |
| BSP | V1.60 |

## Hardware Configuration
- RL78/G22 Fast Prototyping Board
- LED
- Switch

## Applicable Devices
- RL78/G22

## Link of APN
[RL78/G22 Timer Array Unit (Interval timer)](https://www.renesas.com/en/document/apn/rl78g22-timer-array-unit-interval-timer-rev101)
