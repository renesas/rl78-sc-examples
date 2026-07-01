# RL78/G23 Handshake-based SPI Master Transmission/Reception

日本語版は[こちら](./READMEJP.md)

## Overview
This application note describes how the serial array unit (SAU) performs master transmission/reception by the simple SPI (CSI). The SAU uses the chip select (CS) signal to select a slave device and perform single transmission/reception. The SAU also performs handshake processing using the BUSY signal.

## Software/Tool Version
| Software/Tool | Version |
|----|----|
| CS+ (IDE) | V8.10.00 |
| e2 studio (IDE) | V2023-10 (23.10.0) |
| CC-RL (C compiler) | V1.12.01 |
| IAR Embedded Workbench | V5.10.1 |
| IAR Compiler | V5.10.1 |
| Smart Configurator | V1.8.0 |
| BSP | V1.30 |

## Hardware Configuration
- RL78/G23 Fast Prototyping Board (RTK7RLG230CLG000BJ)

## Applicable Devices
- RL78/G23

## Link of APN
[RL78/G23 Handshake-based SPI Master Transmission/Reception](https://www.renesas.com/en/document/apn/rl78g23-handshake-based-spi-master-transmissionreception-rev101)
