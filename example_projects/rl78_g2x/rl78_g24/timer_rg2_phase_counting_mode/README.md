# RL78/G24 Timer RG2 in Phase Counting Mode

日本語版は[こちら](./READMEJP.md)

## Overview
This application note explains how to use Timer RG2 in phase counting mode on the RL78/G24. It detects the phase difference between external signals on TRGCLKA and TRGCLKB pins and performs up/down counting. The TRG counter is cleared by detecting a valid edge on the TRGIDZ pin, generating an interrupt. This interrupt is used to toggle an output port, demonstrating phase detection and interrupt handling.

## Software/Tool Version
| Software/Tool | Version |
|----|----|
| CS+ (IDE) | V8.10.00 |
| e2 studio (IDE) | 2023-07 (23.7.0) |
| CC-RL (C compiler) | V1.12.01 |
| IAR Embedded Workbench | V4.21.1 |
| IAR Compiler | V4.21.1 |
| Smart Configurator | V.1.7.0 |
| BSP | V.1.60 |

## Hardware Configuration
- RL78/G24 Fast Prototyping Board (RTK7RLG240C00000BJ)

## Applicable Devices
- RL78/G24

## Link of APN
[RL78/G24 Timer RG2 in Phase Counting Mode](https://www.renesas.com/en/document/apn/rl78g24-timer-rg2-phase-counting-mode-rev100)
