# RL78/G22 High-speed On-chip Oscillator (HOCO) Clock Frequency Correction

日本語版は[こちら](./READMEJP.md)

## Overview
This application note explains how to correct the oscillation clock frequency of the HOCO using the HIOTRM register on RL78/G22. The frequency error is detected using a subsystem clock or external input signal. The HIOTRM value is adjusted to bring the HOCO clock close to 32 MHz. Two calibration methods are provided and demonstrated with sample code.

## Software/Tool Version
| Software/Tool | Version |
|----|----|
| CS+ (IDE) | V9.11.04 |
| e2 studio (IDE) | V2024-01 (21.4.0) |
| CC-RL (C compiler) | V1.13.00 |
| IAR Embedded Workbench | V5.10.3 |
| IAR Compiler | V5.10.3 |
| Smart Configurator | V1.10.0 |
| BSP | V1.62 |

## Hardware Configuration
- RL78/G22 Fast Prototyping Board (RTK7RLG220CL000BJ)
- Start switch
- Parameter switch
- LED
- 32.768 kHz crystal oscillator
- Resistors (10 kΩ)
- Capacitor (0.47 to 1 µF)
- External input signal source (512 Hz)

## Applicable Devices
- RL78/G22

## Link of APN
[RL78/G22 High-speed On-chip Oscillator (HOCO) Clock Frequency Correction](https://www.renesas.com/en/document/apn/rl78g22-high-speed-chip-oscillator-hoco-clock-frequency-correction-rev100)
