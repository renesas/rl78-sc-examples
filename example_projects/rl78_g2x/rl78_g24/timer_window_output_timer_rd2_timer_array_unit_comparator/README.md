# RL78/G24 TIMER WINDOW Output using Timer RD2, Timer Array Unit and Comparator

日本語版は[こちら](./READMEJP.md)

## Overview
This application note explains the TIMER WINDOW output function based on the combined use of the RL78/G24 timer RD2, timer array unit (TAU), and comparator (CMP). TIMER WINDOW output is a function that sets CMP output to a low level when TAU output (TO02) is at a low level. This means that the TIMER WINDOW output enables voltage detection by the CMP only when TAU output (TO02) is at a high level. The RL78/G24 allows users to set the valid edge (rising, falling, or both edges) of timer RD2 output as the TAU0 channel 0 start trigger.

## Software/Tool Version
| Software/Tool | Version |
|----|----|
| CS+ (IDE) | V8.10.00 |
| e2 studio (IDE) | 2023-07 (23.7.0) |
| CC-RL (C compiler) | V1.12.01 |
| IAR Embedded Workbench | V4.21.1 |
| IAR Compiler | V4.21.1 |
| Smart Configurator | V1.7.0 |
| BSP | V1.60 |

## Hardware Configuration
- RL78/G24 Fast Prototyping Board (RTK7RLG240C00000BJ)

## Applicable Devices
- RL78/G24

## Link of APN
[RL78/G24 TIMER WINDOW Output using Timer RD2, Timer Array Unit and Comparator](https://www.renesas.com/en/document/apn/rl78g24-timer-window-output-using-timer-rd2-timer-array-unit-and-comparato-rev100)
