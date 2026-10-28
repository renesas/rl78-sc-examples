/**********************************************************************************************************************
* File Name    : readme.txt
* Description  : Contains general information about Example Project and detailed instructions
**********************************************************************************************************************/

1. Project Overview:
		The example project demonstrates the typical use of the SAU_I2C master driver APIs.
		The project initializes SAU_I2C master module with standard rate and interfaces with GY 291 ADXL345.
		On power-up, after initializing the SAU_I2C master module and configuring the ADXL345 sensor,
		the RL78 MCU will read the axis acceleration data from the sensor.
		When SW1 is pressed, new data is retrieved.
		The X, Y, and Z-axis data is displayed in the debugger's variable window.

2. Hardware Settings:
	Hardware Connection
		Connect the USB Debug port on the RL78 board to the host PC via a USB type C cable.
		*******************

		FPB-RL78G21
		--------
		SDA10/P03	----> SDA
		SCL10/P04	----> SCL
		VCC pin		----> VCC
		GND pin		----> GND

