# RL78/G23 Voltage Detector

日本語版は[こちら](./READMEJP.md)

## Overview
This application note describes how to use the two voltage detectors (LVD) mounted on the RL78/G23 to detect two voltage values. Set voltage detector 0 (LVD0) to reset mode and voltage detector 1 (LVD1) to interrupt mode. When the power supply voltage becomes lower than the voltage detected by voltage detector 1 (LVD1), the clock frequency for the CPU and peripheral hardware changes to the frequency of the subsystem clock to reduce power consumption.

## Software/Tool Version
| Software/Tool | Version |
|----|----|
| CS+ (IDE) | V8.10.00 |
| e2 studio (IDE) | V2023-10 (23.10.0) |
| CC-RL (C compiler) | V1.12.01 |
| IAR Embedded Workbench | V5.10.1 |
| IAR Compiler | V5.10.1 |
| Smart Configurator | V1.8.0 |
| BSP | V1.00 |

## Hardware Configuration
- RL78/G23-64p Fast Prototyping Board (RTK7RLG230CLG000BJ)
- LEDs
- Switch
- XT1 32.768 kHz crystal

## Applicable Devices
- RL78/G23

## Link of APN
[RL78/G23 Voltage Detector](https://www.renesas.com/en/document/apn/rl78g23-voltage-detector)
