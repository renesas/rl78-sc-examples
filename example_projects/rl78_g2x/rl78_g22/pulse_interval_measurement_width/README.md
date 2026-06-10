# RL78/G22 Timer Array Unit (Pulse Interval Measurement: Width)

日本語版は[こちら](./READMEJP.md)

## Overview
This application note describes how to measure pulse width using the Timer Array Unit (TAU) of the RL78/G22. The TAU detects both rising and falling edges of an input pulse on the TI00 pin. It captures timer count values at each valid edge to calculate high-level and low-level pulse widths. The measured values are classified based on edge detection and stored in on-chip RAM. The document also provides sample code and operational flow for implementation.

## Software/Tool Version
| Software/Tool | Version |
|----|----|
| CS+ (IDE) | V8.10.00 |
| e2 studio (IDE) | V2023-10 (23.10.0) |
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
[RL78/G22 Timer Array Unit (Pulse Interval Measurement: Width)](https://www.renesas.com/en/document/apn/rl78g22-timer-array-unit-pulse-interval-measurementwidth-rev102)
