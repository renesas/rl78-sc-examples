# RL78/G23 Middle-speed On-chip Oscillator (MOCO) Clock Frequency Correction

日本語版は[こちら](./READMEJP.md)

## Overview
This application note explains how to correct the oscillation clock frequency of the middle-speed on-chip oscillator (MOCO) by using the middle-speed on-chip oscillator trimming register (MIOTRM) incorporated in RL78/G23. An error in the oscillation frequency of the middle-speed on-chip oscillator (MOCO) is detected using a hi-speed on-chip oscillator (HOCO) and the middle-speed on-chip oscillator trimming register (MIOTRM) is adjusted to set the oscillation frequency of the MOCO close to 4 MHz.

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
[RL78/G23 Middle-speed On-chip Oscillator (MOCO) Clock Frequency Correction](https://www.renesas.com/en/document/apn/rl78g23-middle-speed-chip-oscillator-moco-clock-frequency-correction)
