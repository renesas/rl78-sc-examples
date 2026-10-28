# RL78/G23 Example Projects
日本語版は[こちら](./READMEJP.md)<br>

This directory provides example projects for the RL78/G23.<br>
For details on how to use each project and the required software and hardware, please refer to the APN or the README in each project folder.
 <br>

-------------------------------------------------------------------------------------------------------------
Note: <br>
When migrating this sample code to an R7F104G product, after changing the target device, check the pin, clock, and peripheral function settings in Smart Configurator, and be sure to regenerate the code.

Regenerating the code generates the required configuration code for the port-related registers whose initial settings need to be changed for R7F104G products.

For instructions on how to change the target device and use Smart Configurator, refer to the following documents.
-	[Change the microcontroller | V8.05.00](https://tool-support.renesas.com/autoupdate/support/onlinehelp/csp/V8.05.00/CS+.chm/po-ProjectOperation.chm/Output/po_function_pset_micon-nav-3.html)
- [e² studio Tips - How to change the device in the project | Renesas](https://www.renesas.com/en/video/e-studio-tips-how-change-device-project)
- [RL78 Smart Configurator User's Guide: CS+](https://www.renesas.com/en/document/man/rl78-smart-configurator-users-guide-cs)
- [RL78 Smart Configurator User's Guide: e² studio](https://www.renesas.com/en/document/man/rl78-smart-configurator-users-guide-e-studio)
-------------------------------------------------------------------------------------------------------------

## Mapping Table
| Content | App Note Number |
|--------|--------|
| 32-bit Interval Timer (8-bit Counter Mode) | r01an5564 |
| AD Converter (Scan Mode) | r01an5523 |
| AD Converter (Software Trigger Wait Mode) | r01an5631 | 
| Interval Timer | r01an5870 |
| Pulse Interval Measurement (Period) | r01an5908 |
| Pulse Interval Measurement (Width) | r01an5919 |
| PWM Output | r01an5874 |
| Realtime Clock | r01an5618 |
| UART Communication | r01an6645 |
| Serial Interface UARTA | r01an5598 |
| UART Reception in STOP Mode Using the UARTA Function | r01an6646 |
| Setting the Window Comparator | r01an5648 |
| I2C Supporting Multiple Slave Address (Master) | r01an5825 |
| I2C Supporting Multiple Master Address (Master) | r01an5670 |
| How to Use the Output Current Control Ports | r01an5625 |
| Handshake-based SPI Slave Transmission/Reception | r01an5890 |
| Handshake-based SPI Master Transmission/Reception | r01an5889 |
| 40mA Port Output | r01an5627 |
| Voltage Detector | r01an5604 |
| Using VBAT Pin | r01an5560 |
| LOCO Clock Frequency Correction | r01an5557 |
| MOCO Clock Frequency Correction | r01an5556 |
| HOCO Clock Frequency Correction | r01an5555 |
| CPU Clock Changing and Standby Settings | r01an5546 |
| Operation State Switching | r01an5537 |
| EP Quick Start | r01an8400* |
| EP ADC | r01an8401* |
| EP TAU | r01an8407* |
| EP I2C | r01an8404* |
| EP SPI | r01an8405* |
| EP UART | r01an8406* |
| EP Serial Interface UARTA | r01an8408* |
| EP Serial Interface IICA Master | r01an8402* |

*: No application note is available for these projects. The applicable APN numbers are provided for reference.

## Links
- RL78/G23: https://www.renesas.com/en/products/rl78-g23
- RL78/G23 User's Manual: https://www.renesas.com/en/document/man/rl78g23-users-manual-hardware
- FPB RL78/G23 64pin: https://www.renesas.com/en/design-resources/boards-kits/fpb-rl78g23-64p
- FPB RL78/G23 128pin: https://www.renesas.com/en/design-resources/boards-kits/fpb-rl78g23-128p
