# RL78/G22 Timer Array Unit (Pulse Interval Measurement: Period)

日本語版は[こちら](./READMEJP.md)

## Overview
This application note explains how to measure pulse intervals using the Timer Array Unit (TAU) on RL78/G22. The TAU detects valid edges on the timer input pin and captures timer count values to calculate pulse intervals. The measured results are stored in on-chip RAM. The document provides operation details, timing behavior, and sample code for implementation.

## Software/Tool Version
| Software/Tool | Version |
|----|----|
| CS+ (IDE) | V8.10.00 |
| e2studio (IDE) | V2023-10 (23.10.0) |
| CC-RL (C compiler) | V1.12.01 |
| IAR Embedded Workbench | V5.10.1 |
| IAR Compiler | V5.10.1 |
| Smart Configurator | V1.7.0 |
| BSP | V1.60 |

## Hardware Configuration
- RL78/G22 Fast Prototyping Board
- External pulse signal source

## Applicable Devices
- RL78/G22

## Link of APN
[RL78/G22 Timer Array Unit (Pulse Interval Measurement: Period)](https://www.renesas.com/en/document/apn/rl78g22-32-bit-interval-timer-8-bit-counter-mode-rev100)
