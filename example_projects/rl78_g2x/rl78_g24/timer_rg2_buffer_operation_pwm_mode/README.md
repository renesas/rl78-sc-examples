# RL78/G24 Timer RG2 Buffer Operation in PWM Mode

日本語版は[こちら](./READMEJP.md)

## Overview
This application note explains how to generate a PWM waveform using the buffer operation of Timer RG2 in PWM mode on the RL78/G24. A PWM signal with a 100 μs period is output, and the duty cycle is sequentially varied. The duty is updated at each cycle using compare match interrupts. The document details hardware operation, duty change processing, and sample software configuration.

## Software/Tool Version
| Software/Tool | Version |
|----|----|
| CS+ (IDE) | V8.10.00 |
| e2 studio (IDE) | 2023-07 (23.7.0) |
| CC-RL (C compiler) | V1.12.01 |
| IAR Embedded Workbench | V4.21.1 |
| IAR Compiler | V4.21.1 |
| Smart Configurator | V.1.7.0 |
| BSP | V.1.60 |

## Hardware Configuration
- RL78/G24 Fast Prototyping Board (RTK7RLG240C00000BJ)

## Applicable Devices
- RL78/G24

## Link of APN
[RL78/G24 Timer RG2 Buffer Operation in PWM Mode](https://www.renesas.com/en/document/apn/rl78g24-timer-rg2-buffer-operation-pwm-mode-rev100)
