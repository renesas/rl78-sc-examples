# RL78/G23 Timer Array Unit (PWM output)

日本語版は[こちら](./READMEJP.md)

## Overview
This application note explains how to use the PWM output function of the Timer Array Unit (TAU) on RL78/G23. The PWM is generated using master and slave channel cooperation and outputs pulses to control LED brightness. The system changes the PWM duty cycle periodically based on timer interrupts. Additionally, another LED output is inverted at fixed 500 ms intervals to indicate timing changes.

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
- LED1
- LED2

## Applicable Devices
- RL78/G23

## Link of APN
[RL78/G23 Timer Array Unit (PWM output)](https://www.renesas.com/en/document/apn/rl78g23-timer-array-unit-pwm-output)
