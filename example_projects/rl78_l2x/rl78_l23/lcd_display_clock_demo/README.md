# RL78/L23 LCD display (Clock demo)

日本語版は[こちら](./READMEJP.md)

## Overview
This document describes how to control the LCD panel using the RL78/L23 LCD controller/driver and how the sample code works. The sample code uses the RL78/L23 LCD controller/driver to display a clock in 24-hour mode. The sample code stores the time measured by the real-time clock (RTC) in the LCD display data memory area and changes the time each time an RTC constant-period interrupt occurs (once a second). Additionally, by pressing the user switch, the time can be adjusted. By touch detection of the touch buttons, the adjusted time is displayed on the LCD.

## Software/Tool Version
| Software/Tool | Version |
|----|----|
| CS+ (IDE) | V8.14.00 |
| e2 studio (IDE) | Version 2025-07 |
| CC-RL (C compiler) | V1.15.01 |
| IAR Embedded Workbench | V5.20.1 |
| IAR Compiler | V5.20.1 |
| Smart Configurator | V1.14.0 |
| BSP | V1.91 |

## Hardware Configuration
- RL78/L23 Fast Prototyping Board (RTK7RLL230S00001BJ)
- Varitronix VIM-878-DP-FC-S-LV
- Touch button1
- Touch button2
- User switch
- LED1
- LED2

## Applicable Devices
- RL78/L23

## Link of APN
[RL78/L23 LCD display (Clock demo)](https://www.renesas.com/en/document/apn/rl78l23-lcd-display-clock-demo-rev110)
