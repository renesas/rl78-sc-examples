/**********************************************************************************************************************
* File Name    : readme.txt
* Description  : Contains general information about Example Project and detailed instructions
**********************************************************************************************************************/

1. Project Overview:
	This Example Project demonstrates the basic usage of SAU SPI driver in master configuration on Renesas RL78 MCUs.
	The project writes commands to the slave digital thermometer module, and reads the temperature values using SAU SPI
	bus configured as master. The temperature values are continuously printed on terminal. Status information and error
	messages will be printed on terminal during the execution of the project.

2. Hardware Requirements:
	Supported RL78 Boards: FPB-RL78G23-128p
	1 x Renesas RL78 board.
	1 x Micro-B USB cable.
	1 x Digital thermometer module (PMOD MAX31723PMB1)
		Link Product: https://www.mouser.com/ProductDetail/Analog-Devices-Maxim-Integrated/MAX31723PMB1?qs=UmMSjoC1xtH8e742i4OoUA%3D%3D
		Manufacturer Product Number: MAX31723PMB1#
	1 x Host PC.

3. Hardware Connections:
	PMOD MAX31723PMB1:
	---------
	Select SPI communication protocol on the PMOD by configuring the following jumper configurations on JP1:
	Connect JP1-3 to JP1-5
	Connect JP1-4 to JP1-6
	Connect JP1-9 to JP1-10

	FPB-RL78G23-128p:
	---------
	Connect the PC to the RL78 board using a Micro-B USB cable.
	Connect PMOD MAX31723PMB1 (J1) to the RL78 board via the PMOD1 Port.
	Please carefully align pin 1 on the temperature sensor with pin 1 on the PMOD1 Port.

4. Software Requirements:
	Smart Configurator for RL78: Version 1.18.00
	e2 studio: Version 2026-07
	CS+ for CC: V8.16.00
	CC-RL: Version 1.16.00
	Terminal Console Application: Tera Term or a similar application

Note:
1. For the Serial Terminal application:
	1.1 Enable echo in Tera Term: Setup → Terminal... → check Local echo.
	1.2 Serial port settings:
		- COM port: Board USB-to-Serial
		- Baud rate: 115200 bps
		- Data length: 8 bits
		- Parity: None
		- Stop bit: 1

2. For detailed instructions:
	1. Connect the temperature sensor module (MAX31723PMB1) to the board. Ensure that pin 1 of the module is aligned with pin 1 of the PMOD connector.
	2. Connect the PC to the board using a USB cable.
	3. Build the sample code.
	4. Select the debugger for this project from the Debug Configurations, select "COM Port" for the Debug hardware, and start debugging. 
	5. After disconnecting the target debugger, open the serial terminal application (Tera Term).
	6. Configure the following two settings for Tera Term:
		a. Select [Setup] > [Terminal...], and check [Local echo] to enable it.
		b. Configure the serial port settings as follows:
			- COM Port: USB-to-Serial (COM port) of the board
			- Baud Rate: 115200 bps
			- Data bits: 8-bit
			- Parity: None
			- Stop bits: 1
	7. Verify that the results from the temperature sensor module are displayed on the screen.

3. 	An error regarding the UART terminal may appear on the Smart Configurator screen; 
	however,there is no problem with the operation because the connection to Tera Term is established after the program download is completed in this sample project.

4. 	Since the COM port is used for both debugger communication and display on Tera Term, they cannot be used simultaneously. 
	When debugging again, please ensure to disconnect Tera Term before connecting the debugger.

5.	In case debugging cannot be performed even without a Tera Term connection, reset the USB-to-serial converter (by turning SW3 on and then back off) 
	while pressing the reset switch, wait about 3 seconds until the host PC recognizes the USB-to-serial converter as the COM port, and release the reset switch.