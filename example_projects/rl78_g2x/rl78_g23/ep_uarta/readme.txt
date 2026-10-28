/**********************************************************************************************************************
* File Name    : readme.txt
* Description  : Contains general information about Example Project and detailed instructions
**********************************************************************************************************************/

1. Project Overview:
	The example project demonstrates the typical use of the UARTA driver APIs. The project initializes the UARTA module
	with 115200 bps baud rate, 8-bits data length, no parity check, and one-bit stop.
	
	After the program starts running, after initializing the UARTA module, a message requesting the user to open the Tera Term application on the PC along 
	with the configuration parameters for the Tera Term application will be displayed on Terminal App 0 (USB Micro-B).
	The configuration parameters are as follows:
	The COM port is facilitated by the PmodUSBUART (Terminal App 1) and by the on-board USB-to-UART interface (Terminal App 0), operating at a baud rate of 115200 bps,
	with a data length of 8 bits, no parity check, one-bit stop, and without any flow control.
	After opening and configuring the Tera Term application, the user can enter any ASCII character string with a length less than 256 characters into 
	the Tera Term application connected to Terminal App 1 (PmodUSBUART), then press enter-key to send it to the RL78 board.
	The RL78 board will echo any data received back to the Tera Term application on the host PC (Terminal App 1).
	In addition, the RL78 board will print the received string log on Terminal App 0 (USB Micro-B).

	The PmodUSBUART facilitates the conversion of UART signals to USB signals and vice versa, enabling communication between the RL78 board and the Tera Term application.

2. Software Requirements:
	CS+ for CC: V8.16.00
	e2 studio: Version 2026-07
	Smart Configurator for RL78: Version 1.18.00
	CC-RL: Version 1.16.00
	Terminal Console Application: Tera Term or a similar application

3. Hardware Requirements:
	Supported RL78 Boards: FPB-RL78G23-128p
	1 x Renesas RL78 board.
	1 x Micro-B USB cable.
	1 x PmodUSBUART(Part number: 410-212) module for converting data from the USB interface to the UART interface and vice versa.
	1 x Micro USB cable for connecting the PmodUSBUART to the host PC.
	2 x Jumper wires (P84(TxDA0)->PmodUSBUART RX, P83(RxDA0)->PmodUSBUART TX).

4. Hardware Connections:
	Insert the PmodUSBUART into a breadboard and connect it to the host PC via a micro USB cable.
	Connect UARTA pins (P83/P84) on the FPB-RL78G23-128p board to the breadboard by jumper wires, and connect them to the PmodUSBUART UART pins.
	Example wiring: P84 (TxDA0) -> PmodUSBUART RX, P83 (RxDA0) -> PmodUSBUART TX.
	Connect the USB Debug port on the RL78 board to the host PC via a Micro-B USB cable.

Note:
1. 	An error regarding the UART terminal may appear on the Smart Configurator screen; 
	however,there is no problem with the operation because the connection to Tera Term is established after the program download is completed in this sample project.

2. 	Since the COM port is used for both debugger communication and display on Tera Term, they cannot be used simultaneously. 
	When debugging again, please ensure to disconnect Tera Term before connecting the debugger.

3.	In case debugging cannot be performed even without a Tera Term connection, reset the USB-to-serial converter (by turning SW3 on and then back off) 
	while pressing the reset switch, wait about 3 seconds until the host PC recognizes the USB-to-serial converter as the COM port, and release the reset switch.