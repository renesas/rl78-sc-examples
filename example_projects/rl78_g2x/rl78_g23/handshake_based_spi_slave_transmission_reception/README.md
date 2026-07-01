# RL78/G23 Handshake-based SPI Slave Transmission/Reception

日本語版は[こちら](./READMEJP.md)

## Overview
This application note describes how the serial array unit (SAU) performs slave transmission/reception by the simple SPI (CSI). The slave selected by the chip select (CS) signal performs single transmission/reception, single transmission, or single reception according to the processing. The SAU also performs handshake processing using the BUSY signal.

## Software/Tool Version
| Software/Tool | Version |
|----|----|
| CS+ (IDE) | V8.08.00 |
| e2 studio (IDE) | V2022-07 (22.7.0) |
| CC-RL (C compiler) | V1.11.00 |
| IAR Embedded Workbench | V4.21.2 |
| IAR Compiler | V4.21.2.2420 |
| Smart Configurator | V1.4.0 |
| BSP | V1.30 |

## Hardware Configuration
- RL78/G23 Fast Prototyping Board (RTK7RLG230CLG000BJ)

## Applicable Devices
- RL78/G23

## Link of APN
[RL78/G23 Handshake-based SPI Slave Transmission/Reception](https://www.renesas.com/en/document/apn/rl78g23-handshake-based-spi-slave-transmissionreception-rev100)
