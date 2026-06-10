# RL78/G23 32-Bit Interval Timer (8-bit counter mode)

日本語版は[こちら](./READMEJP.md)

## Overview
This application note explains how to use the 32-bit interval timer in 8-bit counter mode on the RL78/G23. The application uses timer interrupts and external interrupt input (INTP0) to control LED behavior. LED indications are reversed according to compare match detection flags when timer interrupts occur. Additionally, the timer interrupt interval is modified based on the number of switch presses. The example demonstrates dynamic control of timer frequency division ratios using external input.

## Software/Tool Version
| Software/Tool | Version |
|----|----|
| CS+ (IDE) | E8.09.00 |
| e2 studio (IDE) | V2023-04 (23.4.0) |
| CC-RL (C compiler) | V1.12.00 |
| IAR Embedded Workbench | V4.21.2 |
| IAR Compiler | V4.21.2.2420 |
| Smart Configurator | V1.6.0 |
| BSP | V1.60 |

## Hardware Configuration
- RL78/G23-64p Fast Prototyping Board (RTK7RLG230CLG000BJ)
- LEDs (LED1 to LED4)
- Switch (SW)

## Applicable Devices
- RL78/G23

## Link of APN
[RL78/G23 32-Bit Interval Timer (8-bit counter mode)](https://www.renesas.com/en/document/apn/rl78g23-32-bit-interval-timer-8-bit-counter-mode)
