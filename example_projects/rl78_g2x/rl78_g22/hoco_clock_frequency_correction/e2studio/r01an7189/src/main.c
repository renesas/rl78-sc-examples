/**********************************************************************************************************************
 * DISCLAIMER
 * This software is supplied by Renesas Electronics Corporation and is only intended for use with Renesas products. No
 * other uses are authorized. This software is owned by Renesas Electronics Corporation and is protected under all
 * applicable laws, including copyright laws.
 * THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING
 * THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED. TO THE MAXIMUM
 * EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES
 * SHALL BE LIABLE FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY REASON RELATED TO
 * THIS SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
 * Renesas reserves the right, without notice, to make changes to this software and to discontinue the availability of
 * this software. By using this software, you agree to the additional terms and conditions found by accessing the
 * following link:
 * http://www.renesas.com/disclaimer
 *
 * Copyright (C) 2020 Renesas Electronics Corporation. All rights reserved.
 *********************************************************************************************************************/
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

#include "r_smc_entry.h"

/* Start user code for global. Do not edit comment generated here */
uint8_t     calibration_count;          /* Calibration counter */
uint8_t     calibrate_history;          /* HIOTRM setting history (increment or decrement) */
uint16_t    count_value;                /* Counter value */
uint16_t    max;                        /* Counter value trimming range max */
uint16_t    min;                        /* Counter value trimming range min */

void R_Main_UseXT1(void);               /* Calibration main process use XT1 oscillation */
void R_Main_ExternalClock(void);        /* Calibration main process use external input clock */
uint8_t R_Trimming_OCO(uint16_t count); /* Set HIOTRM and judge whether to calibration continue */
void R_MAIN_UserInit(void);

/* End user code. Do not edit comment generated here */
void main(void);

void main(void) {

    R_MAIN_UserInit();
    {
        R_Config_PCLBUZ0_Start();
        while (1U) {

            // wait for calibration start key pressed
           R_Config_INTC_INTP0_Start();

            while (!PIF0)
            {
                HALT();         /* Set HALT (wait for external interrupt signal generation) */
            }
            
            R_Config_INTC_INTP0_Stop();     /* Disables INTP0 interrupt */

            /* Wait 10ms for countermeasure for chattering on INTP0 port */
	    TMIF00 = 0;
            R_Config_TAU0_0_Start();    		/* Start TAU0 */
            while (!TMIF00)         /* Wait 10ms have elapsed */
            {
		   ;
            }
	    TMIF00 = 0;
	    
            R_Config_TAU0_0_Stop();     /* Stop TAU0 */

            if (0U == P13_bit.no7)      /* No chattering action on INTP0 ? */
            {   /* Yes */
                /*--------------------------------------*/
                /*  Start calibration                   */
                /*--------------------------------------*/
                P6_bit.no2 = 1U;        /* Calibration finish LED OFF */

                if (0U == P1_bit.no7)   /* Select calibration way */
                {
                    /* Calibration main process use XT1 oscillation */
                    R_Main_UseXT1();
                }
                else
                {
                    /* Calibration main process use external input clock */
                    R_Main_ExternalClock();
                }
                P6_bit.no2 = 0U;        /* Calibration finish LED ON */
            }

            /*--------------------------------------*/
            /*  Various main processes              */
            /*--------------------------------------*/
            /* If another main process exists, please call it here. */
        }
    }
    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
 * Function Name: R_MAIN_UserInit
 * Description  : This function adds user code before implementing main function.
 * Arguments    : None
 * Return Value : None
 ***********************************************************************************************************************/
void R_MAIN_UserInit(void)
{
    /* Start user code. Do not edit comment generated here */
    DI();
    /* End user code. Do not edit comment generated here */
}

/* Start user code for adding. Do not edit comment generated here */
/******************************************************************************
 * Function Name: R_Main_UseXT1
 * Description  : Calibration main process use XT1 oscillation
 * Arguments    : none
 * Return Value : none
 ******************************************************************************/
void R_Main_UseXT1(void)
{
    uint8_t capture_count = 0U;     /* Capture counter */
    uint8_t calibrate_continue = 1U;/* Calibration continue or not */
    /*---------------------------------------------------------------
      Initialize variables
      -----------------------------------------------------------------*/
    calibration_count = 0U;         /* Calibration counter clear */
    calibrate_history = 0U;         /* HIOTRM setting history */
    
    max = CCNT_XT1_MAX;             /* Set trimming range max */
    min = CCNT_XT1_MIN;             /* Set trimming range min */

    ITLCC0 &= _FC_ITL_CAPTURE_TRIGGER_CLEAR;
    ITLCC0 |= _02_ITL_CAPTURE_TRIGGER_FSXP;
      
    
    while (1U == calibrate_continue)
    {
        /*---------------------------------------------------------------
          Calibration start
          -----------------------------------------------------------------*/
        count_value = 0U;		/* Counter value clear */
        ITLS0 &= 0xEF;			/* Clear ITF0C */
        R_Config_ITL000_ITL001_Start(); 
        /* TM05 count start from 0000H, at the same time as setting TS0L.5 = 1.
           To capture operate as high accuracy as possible,
           regard the count until the first interrupt is
           generated as invalid */
        while (!(ITLCC0 & 0x20))             /* Wait for ITF0C counter reset */
        {
        }
	CAPF0CR = 1;
        ITLS0 &= 0xEF;			/* Clear ITF0C */
	ITLIF = 0;

        /*---------------------------------------------------------------
          Wait for capture is done 4 times
          -----------------------------------------------------------------*/
        for (capture_count = 0U; capture_count < 4U; capture_count++)
        {
            while (!(ITLCC0 & 0x20))             /* Wait for end of timer capture */
            {
            }
            count_value += (ITLCAP00 + 1U);/* Get counter value */
            /* + 1 : Adjust an error equivalent to one operation clock */
            CAPF0CR = 1;
	    ITLS0 &= 0xEF;			/* Clear ITF0C */
	    ITLIF = 0;
        }
       R_Config_ITL000_ITL001_Stop();
     
        calibration_count++;            /* Increment calibration counter */

        /*---------------------------------------------------------------
          Set HIOTRM and judgment
          -----------------------------------------------------------------*/
        calibrate_continue = R_Trimming_OCO(count_value);
    }

}
   
/******************************************************************************
  End of function R_Main_UseXT1
 ******************************************************************************/

/******************************************************************************
 * Function Name: R_Main_ExternalClock
 * Description  : Calibration main process use external input clock
 * Arguments    : none
 * Return Value : none
 ******************************************************************************/
void R_Main_ExternalClock(void)
{
    uint8_t calibrate_continue = 1U;    /* Calibration continue or not */


    /*---------------------------------------------------------------
      Initialize variables
      -----------------------------------------------------------------*/
    calibration_count = 0U;             /* Calibration counter clear */
    count_value = 0U;                   /* Counter value clear */
    calibrate_history = 0U;             /* HIOTRM setting history */

    max = CCNT_EXT_MAX;                 /* Set trimming range max */
    min = CCNT_EXT_MIN;                 /* Set trimming range min */
    
    ITLCC0 &= _FC_ITL_CAPTURE_TRIGGER_CLEAR;
    ITLCC0 |= 0x03;                     /* Set Caputre triger ELC */
    R_Config_INTC_INTP1_Start();
    
    while (1U == calibrate_continue)
    {
        /*---------------------------------------------------------------
          Calibration start
          -----------------------------------------------------------------*/
	count_value = 0U;		/* Counter value clear */
        ITLS0 &= 0xEF;			/* Clear ITF0C */
        R_Config_ITL000_ITL001_Start(); 
	
	/* TM05 count start from 0000H, at the same time as setting TS0L.5 = 1.
           To capture operate as high accuracy as possible,
           regard the count until the first interrupt is
           generated as invalid */
        while (!(ITLCC0 & 0x20))             /* Wait for ITF0C counter reset */
        {
        }
	CAPF0CR = 1;
	ITLS0 &= 0xEF;			/* Clear ITF0C */
	ITLIF = 0;
        /*---------------------------------------------------------------
          Wait 1.953125ms have elapsed
          -----------------------------------------------------------------*/
         while (!(ITLCC0 & 0x20))             /* Wait for ITF0C counter reset */
        {
        }
	R_Config_ITL000_ITL001_Stop();
	
	count_value = (ITLCAP00 + 1U);/* Get counter value */
        /* + 1 : Adjust an error equivalent to one operation clock */

        calibration_count++;            /* Increment calibration counter */

        /*---------------------------------------------------------------
          Set HIOTRM and judgment
          -----------------------------------------------------------------*/
        calibrate_continue = R_Trimming_OCO(count_value);
    }
}
/******************************************************************************
  End of function R_Main_ExternalClock
 ******************************************************************************/

/******************************************************************************
 * Function Name: R_Trimming_OCO
 * Description  : Set HIOTRM and judge whether to calibration continue
 * Arguments    : uint16_t count : Capture count
 * Return Value : Calibration continue or not (0:finished, 1:continue)
 ******************************************************************************/
uint8_t R_Trimming_OCO(uint16_t count)
{
    uint8_t ret_continue = 0U;          /* Calibration finished */

    /*---------------------------------------------------------------
      Initialize variables
      -----------------------------------------------------------------*/
    if (count <= min)
    {   /* Out of ideal range (slower than ideal oscillation speed) */
        /* -> make to faster */
        if (HIOTRM < HIOTRM_MAX)        /* Maximum speed ? */
        {   /* No */
            /* Set HIOTRM that fIH becomes faster */
            HIOTRM ++;

            /* Set calibration history */
            calibrate_history = (calibrate_history << 1U) | 0b00000001;

            if (calibration_count > 3U) /* The first or
                                           the second time around */
            {
                ret_continue = 1U;      /* Calibration continue */
            }
            else
            {
                /* Calibration history is [+1 -> -1 -> +1] ? */
                if ((calibrate_history & 0b00000111) != 0b00000101)
                {
                    ret_continue = 1U;  /* Yes *//* Calibration continue */
                }
            }
        }
    }
    else if (count >= max)
    {   /* Out of ideal range (faster than ideal oscillation speed) */
        /* -> make to slower */
        if (HIOTRM > HIOTRM_MIN)    /* Minimum speed ? */
        {   /* No */
            /* Set HIOTRM that fIH becomes slower */
            HIOTRM --;

            /* Set calibration history */
            calibrate_history = (calibrate_history << 1U) & 0b11111110;

            if (calibration_count < 3U) /* The first or */
                /* the second time around */
            {
                ret_continue = 1U;      /* Calibration continue */
            }
            else
            {
                /* Calibration history is [-1 -> +1 -> -1] ? */
                if ((calibrate_history & 0b00000111) != 0b00000010)
                {
                    ret_continue = 1U;  /* Yes *//* Calibration continue */
                }
            }
        }
    }

    return ret_continue;
}
