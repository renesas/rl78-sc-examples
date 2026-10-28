/**********************************************************************************************************************
* File Name    : readme.txt
* Description  : Contains general information about Example Project and detailed instructions
**********************************************************************************************************************/

1. Project Overview:
	This Example Project demonstrates the basic usage of TAU driver on Renesas RL78 MCUs based on Renesas Smart Configurator. 
	It consists of 7 independent operations coordinated together to create 3 modes. They include setting the period
	for LED on and off times, counting external events, and measuring low-level pulse width. 
	The EP information and error messages will be printed to the Host PC.
	To enter the operating mode, enter the numbers 1, 2, and 3 and press Enter from terminal of the host PC.
	
2. Hardware Requirements:

	Supported RL78 Boards: FPB-RL78G21

	1 x Renesas RL78 board.
	1 x Type-C USB cable.
	5 x Jumper cable (both ends male).
	1 x Host PC.
	
3. Hardware connections:

    FPB-RL78G21:     
	---------
	1. Connect the USB Debug port on the RL78 board to the host PC via a USB type C cable.
	2. Pin connection:
		P33-LED1 (J1-Pin 20)   <--------> P31-TI03 (J1-Pin 21)
		P16-TO01 (J2-Pin 8)    <--------> P00-TI00 (J2-Pin 30)
		P01-TO00 (J2-Pin 29)   <--------> P42-TI04 (J1-Pin 3)
		P34-LED2 (J1-Pin 19)   <--------> P05-TI05 (J1-Pin 31)
		P06-TO06 (J1-Pin 30)   <--------> P41-TI07 (J1-Pin 4)

Note:
1.	For using the Serial Terminal (UART):
      1) To echo back what was typed in Tera Term, the user needs to enable it through [Setup] -> [Terminal...] -> Check [Local echo].
      2) The serial terminal setting parameters are as follows:
      	Baud rate: 115200 bps
      	Data length: 8-bits  
      	Parity: none
      	Stop bit: 1-bit
      	Flow control: none

2.	An error regarding the UART terminal may appear on the Smart Configurator screen; 
	however,there is no problem with the operation because the connection to Tera Term is established after the program download is completed in this sample project.

3.	Since the COM port is used for both debugger communication and display on Tera Term, they cannot be used simultaneously. 
	When debugging again, please ensure to disconnect Tera Term before connecting the debugger.

4.	In case debugging cannot be performed even without a Tera Term connection, reset the USB-to-serial converter (by turning SW3 on and then back off) 
	while pressing the reset switch, wait about 3 seconds until the host PC recognizes the USB-to-serial converter as the COM port, and release the reset switch.
	For details, please refer to "6.5 Note on Using P12/TxD0" in the RL78/G21 Fast Prototyping Board User’s Manual (R20UT5750).