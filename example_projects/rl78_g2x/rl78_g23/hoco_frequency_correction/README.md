# RL78/G23 High-speed On-chip Oscillator (HOCO) Clock Frequency Correction

日本語版は[こちら](./READMEJP.md)

## Overview
This application note explains how to correct the oscillation clock frequency of the high-speed on-chip oscillator (HOCO) by using the high-speed on-chip oscillator trimming register (HIOTRM) incorporated in RL78/G23. An error in the oscillation frequency of the high-speed on-chip oscillator (HOCO) is detected using a subsystem clock or an external input signal and the high-speed on-chip oscillator trimming register (HIOTRM) is adjusted to set the oscillation frequency of the HOCO close to 32 MHz.

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
- Parameter switch
- Correction completion LED
- 32.768-kHz crystal oscillator
- External input signal (512 Hz, 50% duty)

## Applicable Devices
- RL78/G23

## Link of APN
[RL78/G23 High-speed On-chip Oscillator (HOCO) Clock Frequency Correction](https://www.renesas.com/en/document/apn/rl78g23-high-speed-chip-oscillator-hoco-clock-frequency-correction)
