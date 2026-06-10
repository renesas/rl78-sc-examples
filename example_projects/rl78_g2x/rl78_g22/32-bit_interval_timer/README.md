# RL78/G22 32-Bit Interval Timer (8-bit counter mode)

日本語版は[こちら](./READMEJP.md)

## Overview
This application note explains how to use the 32-bit interval timer channels in 8-bit counter mode. The application toggles LED outputs based on compare match detection flags when timer interrupts occur. It demonstrates changing interrupt intervals dynamically based on the number of switch presses. External interrupts and timer interrupts are combined to control LED behavior. The sample code illustrates practical implementation on RL78/G22 devices.

## Software/Tool Version
| Software/Tool | Version |
|----|----|
| CS+ (IDE) | E8.11.00 |
| e2 studio (IDE) | V2023-07 |
| CC-RL (C compiler) | V1.13.00 |
| IAR Embedded Workbench | V5.10.3 |
| IAR Compiler | V5.10.3.2716 |
| Smart Configurator | V1.11.0 |
| BSP | V1.62 |

## Hardware Configuration
- RL78/G22-64p Fast Prototyping Board
- LEDs (LED1 to LED4)
- Switch

## Applicable Devices
- RL78/G22

## Link of APN
[RL78/G22 32-Bit Interval Timer (8-bit counter mode)](https://www.renesas.com/en/document/apn/rl78g22-32-bit-interval-timer-8-bit-counter-mode-rev100)
