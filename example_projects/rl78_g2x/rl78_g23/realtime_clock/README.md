# RL78/G23 Realtime Clock

日本語版は[こちら](./READMEJP.md)

## Overview
This application note explains how to use the realtime clock (RTC) on the RL78/G23, focusing on fixed-cycle interrupt and alarm interrupt functions. The fixed-cycle interrupt toggles output ports and updates the current time display on an LCD. The alarm interrupt generates an interrupt event five seconds after a preset time. The sample also demonstrates maintaining RTC operation even during reset periods while monitoring via LCD.

## Software/Tool Version
| Software/Tool | Version |
|----|----|
| CS+ (IDE) | V8.11.00 |
| e2 studio (IDE) | V2024-04 (24.4.0) |
| CC-RL (C compiler) | V1.13.00 |
| IAR Embedded Workbench | V5.10.3 |
| IAR Compiler | V5.10.3.2716 |
| Smart Configurator | V1.6.0 |
| BSP | V1.60 |

## Hardware Configuration
- RL78/G23-64p Fast Prototyping Board (RTK7RLG230CLG000BJ)
- LCD module (ACM1602NI-FLW-FBW-M01)
- LED

## Applicable Devices
- RL78/G23

## Link of APN
[RL78/G23 Realtime Clock](https://www.renesas.com/en/document/apn/rl78g23-realtime-clock)
