# RL78/G23 Operation State Switching

日本語版は[こちら](./READMEJP.md)

## Overview
The application note shows the register setting sequence for the switch of RL78/G23 operation state, using the Operation State Control. After reset, it operates in the HS mode. The flash operation mode is switched one by one by the button pressing (HS mode → LS mode → LP mode → HS mode, repetition at the following).

## Software/Tool Version
| Software/Tool | Version |
|----|----|
| CS+ (IDE) | E8.09.00 |
| e2 studio (IDE) | V2023-04 (23.4.0) |
| CC-RL (C compiler) | V1.12.00 |
| IAR Embedded Workbench | V4.21.2 |
| IAR Compiler | V4.21.2.2420 |
| Smart Configurator | V1.6.0 |
| BSP | V1.60 |

## Hardware Configuration
- RL78/G23-64p Fast Prototyping Board (RTK7RLG230CLG000BJ)
- LED1
- LED2
- Switch

## Applicable Devices
- RL78/G23

## Link of APN
[RL78/G23 Operation State Switching](https://www.renesas.com/en/document/apn/rl78g23-operation-state-switching)
