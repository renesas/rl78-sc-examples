# RL78/G23 Timer Array Unit (Pulse Interval Measurement: Period)

日本語版は[こちら](./READMEJP.md)

## Overview
This application note describes how to measure pulse intervals using the Timer Array Unit (TAU) on the RL78/G23. The system detects valid edges on the timer input pin and captures the timer count value to determine the interval between pulses. Measured values are stored in on-chip RAM for further processing. The example demonstrates interrupt-driven capture and repeated measurement of pulse intervals.

## Software/Tool Version
| Software/Tool | Version |
|----|----|
| CS+ (IDE) | V8.06.00 |
| e2 studio (IDE) | V2021-07 (21.7.0) |
| CC-RL (C compiler) | V1.10.00 |
| IAR Embedded Workbench | V4.21.1 |
| IAR Compiler | V4.21.1 |
| Smart Configurator | V1.1.0 |
| BSP | V1.11 |

## Hardware Configuration
- RL78/G23 Fast Prototyping Board (RTK7RLG230CLG000BJ)
- External pulse signal source

## Applicable Devices
- RL78/G23

## Link of APN
[RL78/G23 Timer Array Unit (Pulse Interval Measurement: Period)](https://www.renesas.com/en/document/apn/rl78g23-timer-array-unit-pulse-interval-measurement-period-rev100)
