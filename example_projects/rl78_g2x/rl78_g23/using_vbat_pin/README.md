# RL78/G23 Using VBAT Pin

日本語版は[こちら](./READMEJP.md)

## Overview
This application note describes how to use the VBAT pin (battery backup power) of RL78/G23. While power is supplied from VDD, clock time is displayed on the LCD using fixed-cycle interrupts of the realtime clock. If power is not supplied from VDD and is supplied from the VBAT pin, clock time is not displayed on the LCD though the realtime clock continues operating. The voltage detector (LVD0) can determine whether power is supplied from VDD.

## Software/Tool Version
| Software/Tool | Version |
|----|----|
| CS+ (IDE) | V8.07.00 |
| e2 studio (IDE) | V2022-04 (22.4.0) |
| CC-RL (C compiler) | V1.11.00 |
| IAR Embedded Workbench | V4.21.2 |
| IAR Compiler | V4.21.2.2420 |
| Smart Configurator | N/A |
| BSP | N/A |

## Hardware Configuration
- RL78/G23-64p Fast Prototyping Board (RTK7RLG230CLG000BJ)
- LCD module ACM1602NI-FLW-FBW-M01
- Battery backup power supply

## Applicable Devices
- RL78/G23

## Link of APN
[RL78/G23 Using VBAT Pin](https://www.renesas.com/en/document/apn/rl78g23-using-vbat-pin)
