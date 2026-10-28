/**********************************************************************************************************************
* File Name    : readme.txt
* Description  : Contains general information about Example Project and detailed instructions
**********************************************************************************************************************/

1. Project Overview:
	The example project demonstrates the typical use of the ADC driver APIs.
	User provide ADC channel input voltage from 0V to 3.3V with a voltage supply unit 
	at the ADC channel voltage input pin. Once ADC scan is initialized, Window Compare Mode is enabled and compares the	
	ADC channel input voltage with the upper and lower limits. The upper limit and lower limit are configured in RL78 
	Configurator. If the ADC channel input voltage is above the upper limit or below the lower limit, it triggers an event 
	and LED1 turns on. Result is displayed on the g_adc_result.Please check the value of `g_adc_result` in the debugger.

2. Hardware settings for the project
	Hardware requirements:
		- FPB-RL78G21 board: 1x
		- Type-C USB cable: 1x
		- External Variable DC Power supply: 1x
		- Jumper wires to connect External Variable DC Power supply with FPB-RL78G21 board.

	Hardware Connections:
		Connect the USB Debug port on the RL78 board to the host PC via a USB type C cable.

		ADC Channel Voltage Input Pin: ANI2(P22)

