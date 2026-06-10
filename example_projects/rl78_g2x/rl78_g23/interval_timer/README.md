# RL78/G23 Timer Array Unit (Interval timer)

日本語版は[こちら](./READMEJP.md)

## Overview
This application note describes how to use the interval timer function of the Timer Array Unit (TAU) on RL78/G23. It demonstrates generating periodic timer interrupts and toggling an LED output at defined intervals. The timer cycle is dynamically adjusted based on the number of switch presses. The example also includes external interrupt handling and timer-based event counting.

## Software/Tool Version
| Software/Tool | Version |
|----|----|
| CS+ (IDE) | V8.05.00 |
| e2 studio (IDE) | V2021-04 (21.4.0) |
| CC-RL (C compiler) | V1.10.00 |
| IAR Embedded Workbench | V4.21.1 |
| IAR Compiler | V4.21.1 |
| Smart Configurator | V1.0.1 |
| BSP | V1.00 |

## Hardware Configuration
- RL78/G23 Fast Prototyping Board (RTK7RLG230CLG000BJ)
- LED
- Switch

## Applicable Devices
- RL78/G23

## Link of APN
[RL78/G23 Timer Array Unit (Interval timer)](https://www.renesas.com/en/document/apn/rl78g23-timer-array-unit-interval-timer)
