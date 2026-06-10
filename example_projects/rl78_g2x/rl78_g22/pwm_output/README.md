# RL78/G22 Timer Array Unit (PWM output)

日本語版は[こちら](./READMEJP.md)

## Overview
This application note describes how to use the PWM output function of the timer array unit (TAU) on RL78/G22. PWM is generated using coordinated operation of TAU channels, and LED brightness is controlled via duty cycle adjustment. The duty cycle is periodically updated based on timer interrupts, and LED indication is inverted at fixed intervals. Sample code and operation flow for practical implementation are also provided.

## Software/Tool Version
| Software/Tool | Version |
|----|----|
| CS+ (IDE) | 8.10.00 |
| e2 studio (IDE) | V2023-10 (23.10.0) |
| CC-RL (C compiler) | V1.12.01 |
| IAR Embedded Workbench | V5.10.1 |
| IAR Compiler | V5.10.1 |
| Smart Configurator | V1.7.0 |
| BSP | V1.60 |

## Hardware Configuration
- RL78/G22 Fast Prototyping Board
- External LED
- LED

## Applicable Devices
- RL78/G22

## Link of APN
[RL78/G22 Timer Array Unit (PWM output)](https://www.renesas.com/en/document/apn/rl78g22-timer-array-unit-pwm-output-rev101)
