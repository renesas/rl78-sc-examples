# RL78/G23 Low-speed On-chip Oscillator (LOCO) Clock Frequency Correction

日本語版は[こちら](./READMEJP.md)

## Overview
This application note explains how to correct the oscillation clock frequency of the low-speed on-chip oscillator (LOCO) by using the low-speed on-chip oscillator trimming register (LIOTRM) incorporated in RL78/G23. An error in the oscillation frequency of the low-speed on-chip oscillator (LOCO) is detected using a hi-speed on-chip oscillator and the low-speed on-chip oscillator trimming register (LIOTRM) is adjusted to set the oscillation frequency of the LOCO close to 32.768 kHz.

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
- Start switch
- Correction completion LED

## Applicable Devices
- RL78/G23

## Link of APN
[RL78/G23 Low-speed On-chip Oscillator (LOCO) Clock Frequency Correction](https://www.renesas.com/en/document/apn/rl78g23-low-speed-chip-oscillator-loco-clock-frequency-correction)
