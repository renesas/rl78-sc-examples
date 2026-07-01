/***********************************************************************/
/*                                                                     */
/*  FILE        :Main.c                                                */
/*  DATE        :                                                      */
/*  DESCRIPTION :Main Program                                          */
/*  CPU TYPE    :                                                      */
/*                                                                     */
/*  NOTE:THIS IS A TYPICAL EXAMPLE.                                    */
/*                                                                     */
/***********************************************************************/

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_userdefine.h"
#include "Config_DAC0.h"
#include "Config_COMP0.h"
#include "Config_COMP1.h"


/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
void main(void);

/***********************************************************************************************************************
* Function Name: main
* Description  : This function implements main function.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void main(void)
{
    uint16_t w_count;

#ifdef COMP_HIGHSPEED_MODE
    COMPOCR |= _80_COMP_SPEED_HIGH;    /* set high speed mode */
	P5_bit.no3 = LED_ON;
#endif

	R_Config_DAC0_Start();
    for (w_count = 0U; w_count < WAITCOUNT_3US; w_count++)
    {
        NOP();
    }

	R_Config_COMP0_Start();
	R_Config_COMP1_Start();
	EI();

	while (1U)
    {
        HALT();
    }

}

