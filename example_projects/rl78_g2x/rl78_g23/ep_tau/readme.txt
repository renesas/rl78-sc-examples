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

	Supported RL78 Boards: FPB-RL78G23-128p

	1 x Renesas RL78 board.
	1 x Micro-B USB cable.
	5 x Jumper cable (both ends male).
	1 x Host PC.
	
3. Hardware connections:

    FPB-RL78G23-128p:     
	---------
	1. Connect the USB Debug port on the RL78 board to the host PC via a USB Micro-B cable.
	2. Pin connection:
		P050-LED1 (J1-Pin 12)   <--------> P031-TI03 (J10-Pin 2)
		P016-TO01 (Pmod2-Pin 1) <--------> P000-TI00 (Pmod1-Pin 8)
		P001-TO00 (J4-Pin 13)   <--------> P042-TI04 (J10-Pin 1)
		P051-LED2 (J1-Pin 13)   <--------> P046-TI05 (J9-Pin 8)
		P102-TO06 (J2-Pin 12)   <--------> P145-TI07 (J9-Pin 3)

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
