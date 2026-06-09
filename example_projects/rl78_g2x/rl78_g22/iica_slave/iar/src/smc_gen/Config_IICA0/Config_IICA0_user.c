/***********************************************************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only intended for use with Renesas products.
* No other uses are authorized. This software is owned by Renesas Electronics Corporation and is protected under all
* applicable laws, including copyright laws. 
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING THIS SOFTWARE, WHETHER EXPRESS, IMPLIED
* OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
* NON-INFRINGEMENT.  ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY
* LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE FOR ANY DIRECT,
* INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR
* ITS AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software and to discontinue the availability 
* of this software. By using this software, you agree to the additional terms and conditions found by accessing the 
* following link:
* http://www.renesas.com/disclaimer
*
* Copyright (C) 2021, 2024 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
* File Name        : Config_IICA0_user.c
* Component Version: 1.4.1
* Device(s)        : R7F102GGExFB
* Description      : This file implements device driver for Config_IICA0.
***********************************************************************************************************************/
/***********************************************************************************************************************
Pragma directive
***********************************************************************************************************************/
/* Start user code for pragma. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_userdefine.h"
#include "Config_IICA0.h"
/* Start user code for include. Do not edit comment generated here */
#define USER_MODE
#define USER_MODE2

/********************************************************************************
 Important !! Important !! Important !! Important !! Important !! Important !!
 
    If copy actual program ,please copy from line 210 to line 510.

  Important !! Important !! Important !! Important !! Important !! Important !!
********************************************************************************/


#ifndef USER_MODE
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
extern volatile uint8_t   g_iica0_slave_status_flag;    /* iica0 slave flag */
extern volatile uint8_t * gp_iica0_rx_address;          /* iica0 receive buffer address */
extern uint16_t g_iica0_rx_len;                         /* iica0 receive data length */
extern volatile uint16_t  g_iica0_rx_cnt;               /* iica0 receive data count */
extern volatile uint8_t * gp_iica0_tx_address;          /* iica0 send buffer address */
extern volatile uint16_t  g_iica0_tx_cnt;               /* iica0 send data count */
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_Config_IICA0_Create_UserInit
* Description  : This function adds user code after initializing the IICA0.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_IICA0_Create_UserInit(void)
{
    /* Start user code for user init. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_Config_IICA0_callback_getstopcondition
* Description  : This function is a callback function when IICA0 gets a slave stop condition.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
static void r_Config_IICA0_callback_getstopcondition(void)
{
    /* Start user code for r_Config_IICA0_callback_getstopcondition. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_Config_IICA0_slave_handler
* Description  : This function is IICA0 slave handler
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
static void r_Config_IICA0_slave_handler(void)
{
    /* Control for stop condition */
    if (1U == SPD0)
    {
        /* Get stop condition */
        SPIE0 = 0U;
        r_Config_IICA0_callback_getstopcondition();
        g_iica0_slave_status_flag = 1U;
    }
    else
    {
        if (0U == (g_iica0_slave_status_flag & _80_IICA_ADDRESS_COMPLETE))
        {
            if (1U == COI0)
            {
                SPIE0 = 1U;
                g_iica0_slave_status_flag |= _80_IICA_ADDRESS_COMPLETE;
                if (1U == TRC0)
                {
                    WTIM0 = 1U;
                    if (g_iica0_tx_cnt > 0U)
                    {
                        IICA0 = *gp_iica0_tx_address;
                        gp_iica0_tx_address++;
                        g_iica0_tx_cnt--;
                    }
                    else
                    {
                        WREL0 = 1U;
                    }
                }
                else
                {
                    ACKE0 = 1U;
                    WTIM0 = 0U;
                    WREL0 = 1U;
                }
            }
        }
        else
        {
            if (1U == TRC0)
            {
                if (0U == ACKD0)
                {
                    WREL0 = 1U;
                }
                else
                {
                    if (0U == g_iica0_tx_cnt)
                    {
                        LREL0 = 1U;
                    }
                    else
                    {
                        IICA0 = *gp_iica0_tx_address;
                        gp_iica0_tx_address++;
                        g_iica0_tx_cnt--;
                    }
                }
            }
            else
            {
                if (g_iica0_rx_cnt < g_iica0_rx_len)
                {
                    *gp_iica0_rx_address = IICA0;
                    gp_iica0_rx_address++;
                    g_iica0_rx_cnt++;

                    if (g_iica0_rx_cnt == g_iica0_rx_len)
                    {
                        WTIM0 = 1U;
                        WREL0 = 1U;
                    }
                    else
                    {
                        WREL0 = 1U;
                    }
                }
                else
                {
                    ACKE0 = 0U;
                    WREL0 = 1U;
                }
            }
        }
    }
}

/***********************************************************************************************************************
* Function Name: r_Config_IICA0_interrupt
* Description  : This function is INTIICA0 interrupt service routine.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
#pragma vector = INTIICA0_vect
__interrupt static void r_Config_IICA0_interrupt(void)
{
    WUP0 = 0U;    /* disable wakeup */
    NOP();
    NOP();
    NOP();
    NOP();
    NOP();
    /* Start user code for r_Config_IICA0_interrupt. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
    if (0U == (IICS0 & _80_IICA_STATUS_MASTER))
    {
        r_Config_IICA0_slave_handler();
    }
}

/* Start user code for adding. Do not edit comment generated here */
/* above procedure is ignored   */
#endif


/*          copy from this line(line 210)                                      */

#ifdef USER_MODE
/********************************************************************************
*********************************************************************************
*                                                                               *
	The following area is actual program
*                                                                               *
*********************************************************************************
********************************************************************************/

#ifndef USER_MODE2
/********************************************************************************
Includes
********************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_userdefine.h"
#include "Config_IICA0.h"
#endif

/***********************************************************************************************************************
Pragma directive
***********************************************************************************************************************/
#pragma interrupt r_Config_IICA0_interrupt(vect=INTIICA0)

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
extern volatile uint8_t   g_iica0_slave_status_flag;    /* iica0 slave flag
    0x00 : ON_COMM  :on communication
    0x01 : DET_STOP :detect stop condition
    0x02 : TX_END   :compelte data transmit( transmit end )
    0x04 : TD_REG   :no data to transmit( request transmit data )
    0x08 : RX_END   :receive specified number of data( receive end )
    0x10 : DR_REQ   :receive more data ( request to read data from IICA0 )
    0x20 : AR_END   :address register complete flag
    0x80 : NOT_SEL  :not selected after restart nor extension code reception
    */
extern volatile uint8_t * gp_iica0_rx_address;          /* iica0 receive buffer address */
extern uint16_t g_iica0_rx_len;                         /* iica0 receive data length */
extern volatile uint16_t  g_iica0_rx_cnt;               /* iica0 receive data count */
extern volatile uint8_t * gp_iica0_tx_address;          /* iica0 send buffer address */
extern volatile uint16_t  g_iica0_tx_cnt;               /* iica0 send data count */

#ifdef REGADDR
volatile uint8_t    g_reg_flag;         /* address register byte number count   */
volatile uint8_t    g_reg_end_flag;     /* register address complete flag       */
 #if ( REGADDR >= 3 )
volatile uint32_t   g_reg_addr;
 #else
volatile uint16_t   g_reg_addr;         /* address register                     */
 #endif
#endif
static void r_IICA0_slave_handler(void);  /* INTIICA0 interrupt handling function */
/***********************************************************************************************************************
* Function Name: R_Config_IICA0_Create_UserInit
* Description  : This function adds user code after initializing the IICA0.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_IICA0_Create_UserInit(void)
{
	
}

/*******************************************************************************
* Function Name: r_Config_IICA0_interrupt
* Description  : This function is INTIICA0 interrupt service routine.
* Arguments    : None
* Return Value : None
********************************************************************************/
static void __near r_Config_IICA0_interrupt(void)
{
    WUP0 =  0U;                         /* Disable wake up      */
    NOP();                              /* Wait 5 clock         */
    NOP();
    NOP();
    NOP();
    NOP();

    if ((IICS0 & _80_IICA_STATUS_MASTER) == 0U)
    {
        r_IICA0_slave_handler();
    }
}

/********************************************************************************
* Function Name: r_IICA0_slave_handler
* Description  : This function is IICA0 slave handler.
* Arguments    : None
* Return Value : None
*********************************************************************************/
static void r_IICA0_slave_handler(void)
{

/* Control for stop condition detect case   */
    if (1U == SPD0)
    {   /* Detect stop condition    */
        LREL0 = 1U;                     /* exit from communication              */
        g_iica0_slave_status_flag = 1U; /* DET_STOP:set stop condition detect flag */
    }
    else
    {

/*==============================================================*/
/*          normal transfer end interrupt case                  */
/*==============================================================*/

        if (1U == STD0)                 /* check if slave address receive timing*/
        {

/*--------------------------------------------------------------*/
/*          complete slave address receive interrupt timing     */
/*--------------------------------------------------------------*/

            if (1U == COI0)             /* check selected as slave or not       */
            {

/*--------------------------------------------------------------*/
/*          selected by slave address                           */
/*--------------------------------------------------------------*/

                if (1U == TRC0)         /* check if transmit or not             */
                {

/*==============================================================*/
/*          data transmit timing                                */
/*==============================================================*/

                    WTIM0 = 1U;         /* set 9th clock wait mode              */
                    
                    if (g_iica0_tx_cnt > 0U)    /* check remaining transmit data*/
                    {

/*--------------------------------------------------------------*/
/*          start to transmit next data in buffer               */
/*--------------------------------------------------------------*/

                        IICA0 = *gp_iica0_tx_address;   /* set next data        */
                        gp_iica0_tx_address++;  /* mode pointer                 */
                        g_iica0_tx_cnt--;   /* count data number                */
                    }
                    else
                    {

/*--------------------------------------------------------------*/
/*          no data to transmit and request next data           */
/*--------------------------------------------------------------*/

                        g_iica0_slave_status_flag = 4U; /* TD_REQ:set data request flag*/
                    }
                }
                else
                {

/*==============================================================*/
/*          data receive start                                  */
/*==============================================================*/

#ifdef REGADDR

                    g_reg_flag = REGADDR;   /* set address register byte number */
                    g_reg_end_flag = 0; /* clear register address complete flag */
                    g_reg_addr = 0;     /* clear address register               */

#endif

                    ACKE0 = 1U;         /* enable ACK response for receive data */
                    WTIM0 = 0U;         /* set 8th clock wait mode              */
                    WREL0 = 1U;         /* start to receive                     */
                }
            }
            else
            {

/*--------------------------------------------------------------*/
/* not selected after restart nor extension code reception      */
/*--------------------------------------------------------------*/

                LREL0 = 1U;             /* exit from communication              */
                g_iica0_slave_status_flag = 0x80U; /* NOT_SEL:set not selected flag */
            }
        }
        else
        {

/*==============================================================*/
/*          data transfer timing                                */
/*==============================================================*/

            if (1U == TRC0)
            {

/*==============================================================*/
/*          data transmit timing                                */
/*==============================================================*/

                if (0U == ACKD0)
                {

/*--------------------------------------------------------------*/
/*          data transmit complete with NACK from master        */
/*--------------------------------------------------------------*/

                    LREL0 = 1U;         /* exit from communication              */
                    g_iica0_slave_status_flag = 0x02; /* TX_END:transmit complete flag */
                }
                else
                {
                    if (g_iica0_tx_cnt > 0U)
                    {

/*--------------------------------------------------------------*/
/*          continue to transmit                                */
/*--------------------------------------------------------------*/

                        IICA0 = *gp_iica0_tx_address;   /* set next data        */
                        gp_iica0_tx_address++;  /* move transmit data pointer   */
                        g_iica0_tx_cnt--;       /* count down data number       */
                    }
                    else
                    {

/*--------------------------------------------------------------*/
/*  No data to transmit. wait I2C bus and request next data     */
/*--------------------------------------------------------------*/

                        g_iica0_slave_status_flag = 0x04; /* TD_REG:set next data request*/
                    }
                }
            }
            else
            {

/*==============================================================*/
/*          data receive timing                                 */
/*==============================================================*/

#ifdef REGADDR

                if ( g_reg_flag > 0 )
                {
                    g_reg_addr = ( g_reg_addr << 8 );
                    g_reg_addr |= IICA0;        /* add new byte to reg address  */
                    g_reg_flag--;               /* count address register byte  */

                    if ( g_reg_flag == 0 )      /* check address register byte  */
                    {
                        g_reg_end_flag = 1;     /* set address register flag    */
                        g_iica0_slave_status_flag = 0x20;   /* AR_END:address register end */
                    }
                }

#endif


                if (g_iica0_rx_cnt < g_iica0_rx_len)    /* check data number    */
                {   /* there is more data to receive    */
                    *gp_iica0_rx_address = IICA0;   /* store received data      */
                    gp_iica0_rx_address++;      /* move data store pointer      */
                    g_iica0_rx_cnt++;
                    
                    if (g_iica0_rx_cnt == g_iica0_rx_len)
                    {

/*--------------------------------------------------------------*/
/*          specified data receive complete                     */
/*--------------------------------------------------------------*/

                        g_iica0_slave_status_flag |= 0x08; /* RX_END:receive complete */

#ifndef REGADDR                                 /* not check register address   */
                        WREL0 = 1U;             /* release I2C bus wait         */
#endif
                    }
                    else
                    {

/*--------------------------------------------------------------*/
/*          continue to receive next data                       */
/*--------------------------------------------------------------*/

                        WREL0 = 1U;             /* release I2C bus wait         */
                    }
                }
                else
                {

/*--------------------------------------------------------------------------*/
/* next data read request : set request flag and exit with wait I2C bus     */
/*--------------------------------------------------------------------------*/
                    if(g_iica0_slave_status_flag != 0x20)
		    {
                        g_iica0_slave_status_flag = 0x10; /* DR_REQ:set data request flag */
		    }
                }
            }
        }
    }
}
/*          copy to this line(line 510)                                          */

#endif
/* End user code. Do not edit comment generated here */

