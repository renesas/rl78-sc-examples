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
* Copyright (C) 2020 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
* File Name    : Config_IICA0_user.c
* Version      : 1.0.0
* Device(s)    : R7F100GLGxFB
* Description  : This file implements device driver for Config_IICA0.
* Creation Date: 2021-02-04
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
 
    If copy actual program ,please copy from line 210 to line 620.

  Important !! Important !! Important !! Important !! Important !! Important !!
********************************************************************************/


#ifndef USER_MODE
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
extern volatile uint8_t   g_iica0_slave_status_flag;    /* iica0 slave flag */
extern volatile uint8_t * gp_iica0_rx_address;          /* iica0 receive buffer address */
extern volatile uint16_t  g_iica0_rx_len;               /* iica0 receive data length */
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
                if (!((0U == ACKD0) && (0U != g_iica0_tx_cnt)))
                {
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
    /* Start user code for r_Config_IICA0_interrupt. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
    if (0U == (IICS0 & _80_IICA_STATUS_MASTER))
    {
        r_Config_IICA0_slave_handler();
    }
}

/* Start user code for adding. Do not edit comment generated here */
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

/*******************************************************************************
Global variables and functions
********************************************************************************/

#define     RAM1            ( 0x10 )       /* 7bit slave address of part1  */
#define     RAM2            ( 0x24 )       /* 7bit slave address of part2  */
#define     RAM3            ( 0x5A )       /* 7bit slave address of part3  */
#define     RAM4            ( 0x6B )       /* 7bit slave address of part4  */
#define     PAGE_SIZE       ( 256 )             /* data number of each RAM area */


volatile uint8_t    g_ram[4][256];       	/* RAM is 4 of 256bytes RAM     */
volatile uint8_t    gp_ram[4];                  /* address register of RAM1-4   */

volatile uint8_t    __saddr g_prev_status;      /* old communicationcomm flag   */
volatile uint8_t    static __saddr g_status;    /* IICA0 status flag
            0x00 : complete commuication and wait for next communication
            0x01 : register address request phase
            0x02 : data transmit mode
            0x03 : deta receive mode( next of 0x1)

         */

volatile uint8_t    __saddr g_prev_saddr;       /* old slave address            */
volatile uint8_t    static  g_sl_addr;          /* received slave address(8bit) */
volatile uint8_t    static  g_selRAM;           /* selected RAM code            */

static void r_ram_data_send(void);              /* transmit RAM data to master  */
static void r_IICA0_slave_handler(void);        /* IICA0 handler for slave      */

/*******************************************************************************
* Function Name: R_Config_IICA0_Create_UserInit
* Description  : This function adds user code after initializing the IICA0.
* Arguments    : None
* Return Value : None
********************************************************************************/
void R_Config_IICA0_Create_UserInit(void)
{
	
    SVADIS0 = 1;						/* disable slave address check	*/
    
}


/***********************************************************************
* Function Name: R_IICA0_Init
* Description  : This function is IICA0 data initialize routine.
* Arguments    : None
* Return Value : None
************************************************************************/
void R_IICA0_Init(void)
{
  uint16_t i;


/*------------------------------------------
    initialize buffer RAM data
--------------------------------------------*/

  for( i = 0 ; i < PAGE_SIZE ; i++ )
  {
    g_ram[0][i]= 0;                     /* initialize RAM1 data            */
    g_ram[1][i]= 1;                     /* initialize RAM2 data            */
    g_ram[2][i]= 2;                     /* initialize RAM3 data            */
    g_ram[3][i]= 3;                     /* initialize RAM3 data            */

  }


/*------------------------------------------
    initialize data index for buffer
--------------------------------------------*/

  gp_ram[0] = 0x00;                     /* initialize RAM1 pointer          */
  gp_ram[1] = 0x00;                     /* initialize RAM2 pointer          */
  gp_ram[2] = 0x00;                     /* initialize RAM3 pointer          */
  gp_ram[3] = 0x00;                     /* initialize RAM4 pointer          */

  g_prev_status = 0x00;                 /* clear previous staus flag        */

  g_sl_addr = 0x00;                     /* initialize slave address         */

  g_status = 0x00;                      /* clear communication staus flag   */

}/* End of function R_IICA0_Init() */


/***********************************************************************
* Function Name: r_sl_addr_get
* Description  : This function is slave address read routine.
* Arguments    : None
* Return Value : slave address
************************************************************************/
uint8_t r_sl_addr_get(void)
{

    return(g_sl_addr);                  /* return with slave address        */

}/* End of function r_sl_addr_get() */


/***********************************************************************
* Function Name: r_status_chk
* Description  : This function is IICA0 status read routine.
* Arguments    : None
* Return Value : status
************************************************************************/
uint8_t r_status_chk(void)
{

    uint8_t work;

    IICAMK0 = 1;                        /* for exclusive control            */
    work = g_prev_status;               /* read IICA0 communication status  */
    g_prev_status = 0x00;               /* clear status                     */
    IICAMK0 = 0;                        /* end of exclusive control         */
    return(work);                       /* return with slave status         */

}/* End of function r_status_chk() */


/*******************************************************************************
* Function Name: r_Config_IICA0_interrupt
* Description  : This function is INTIICA0 interrupt service routine.
* Arguments    : None
* Return Value : None
********************************************************************************/
#pragma vector = INTIICA0_vect
__interrupt static void r_Config_IICA0_interrupt(void)
{
    if (0U == (IICS0 & 0x80))
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

  uint8_t selec;                            /* selected slave code              */
  uint8_t s_addr;                           /* received slave address(7bit)     */


/*------------------------------------------
    Control for stop condition
------------------------------------------*/

  if ( 1 == SPD0 )
  {  /* detect stop condition       */
    g_prev_status = g_status;               /* set previous communication flag  */
    g_status = 0x00;                        /* set status to commuication end   */
  }
  else
  {

/*------------------------------------------
    Control for normal communication
------------------------------------------*/

    if ( 1 == STD0 )
    { /* detect start condition     */

/********************************************************
*                                                       *
*       receive slave address timing(STD0=1)            *
*                                                       *
*********************************************************/

      if ( 0 == ACKD0 )                     /* check if 8clock interrupt        */
      {
        g_sl_addr = IICA0;                  /* get received slave address(8bit) */
      }

      selec = IICS0 & 0x30;                 /* get EXC0 and COI0 bit from IICS0 */

      switch( selec )
      {
        case 0x30:

/*==============================================
    RL78/G23 detects slave address
================================================*/

            s_addr = ( g_sl_addr >> 1 );    /* get 7bit address                 */

            switch( s_addr )                /* check 7bit slave address         */
            {
              case RAM1:                    /* RAM1 is selected                 */
                   g_selRAM = 0x00;         /* set RAM1 pointer                 */
                   break;

              case RAM2:                    /* RAM2 is selected                 */
                   g_selRAM = 0x01;         /* set RAM2 pointer                 */
                   break;

              case RAM3:                    /* RAM3 is selected                 */
                   g_selRAM = 0x02;         /* set RAM3 pointer                 */
                   break;

              case RAM4:                    /* RAM4 is selected                 */
                   g_selRAM = 0x03;         /* set RAM4 pointer                 */
                   break;

              default:                      /* slave address is not match       */
/*============================================== 
    slave address is not match
================================================*/
                   g_selRAM = 0xFF;         /* set dummy pointer                */
                   LREL0 = 1;               /* exit from communication (NACK)   */
                   break;

            } /* end of "switch( s_addr )" */

            if ( 0xFF != g_selRAM )         /* check if selected or not         */
            {

/*==============================================
    selected by slave address( address is match )
================================================*/
              g_prev_status = 0x00;         /* clear previous flag              */

              if ( 0 == TRC0 )              /* check receive or not             */
              {

/*------------------------------------------
    receive RAM address start
--------------------------------------------*/

                g_status = 0x01;            /* set register address mode        */
                WREL0 = 1;                  /* release I2C bus wait             */

              }
              else
              {

/*==============================================
    first data transmit timing 
================================================*/

                g_status = 0x02;            /* data request from master         */

                r_ram_data_send();          /* set RAM data to IICA0 & go next  */
 
              } /* end of first data transmit timing      */

            } /* end of slave address receive */

            break;

        case 0x20:                          /* receive Reserved addresses       */
        case 0x10:                          /* selected by one address          */
            LREL0 = 1;                      /* exit from communication          */
            break;

        default:                            /* not selected (improbable)        */
            LREL0 = 1;                      /* exit from communication          */
            break;

      } /* end of "switch( selec )" */

    } /* end of "detect start condition" */
    else
    {

/********************************************************
*                                                       *
*       data transfer timing( STD0=0 )                  *
*                                                       *
*********************************************************/


      if (1 == TRC0)                        /* check transmit or receive        */
      {
          ++gp_ram[g_selRAM];               /* change address                   */

/*==============================================
    data transmit mode
  ( lowwer 4bit of g_status is 2 )
================================================*/

        if (0 == ACKD0)                     /* check ACK from master            */
        {

/*------------------------------------------
    NACK from master
  (commuication is complete)
--------------------------------------------*/
          LREL0 = 1;                        /* exit from I2C bus communication  */
          g_prev_status = g_status;         /* set old status to g_prev_status  */
          g_status = 0x00;                  /* clear communication flag         */

        } /* end of NACK from master for transmit data */
        else
        {

/*==============================================
    ACK from master
  (continue to transmit )
================================================*/

/*------------------------------------------
    RAM function is selected
--------------------------------------------*/

          g_status = 0x02;                  /* set data transmit mode           */
          r_ram_data_send();                /* transmit RAM data                */


        } /* end of ACK from master for transmit data */

      } /* end of transmission  */
      else
      {
/*==============================================
    data receive mode 
  (g_status is 1 or 3 )
================================================*/

        if ( 0x01 == g_status )             /* check register address timing    */
        {
/*==============================================
    receive register address 
  ( g_status is 0x01 )
================================================*/

          g_status = 0x03;                  /* change to receive mode(0x3)      */

/*------------------------------------------
    RAM function is selected
--------------------------------------------*/

          gp_ram[g_selRAM] = IICA0;         /* get RAM address                  */

          WREL0 = 1U;                       /* release wait                     */

        } /* end of register address set  */
        else
        {
/*==============================================
    data receive
  ( g_status is 0x03 )
================================================*/

/*------------------------------------------
    RAM data write function is selected
--------------------------------------------*/

          g_ram[g_selRAM][gp_ram[g_selRAM]] = IICA0; /* write data to  RAM2     */
          ++gp_ram[g_selRAM];               /* change address                   */

          WREL0 = 1U;                       /* release wait                     */

        } /* end of data receive  */

      } /* end of data receive mode */

    } /* end of data transfer timing  */

  } /* end of IICA communication  */
    
} /* end of iica0_slave_handler */


/*******************************************************************************
* Function Name: r_ram_data_send
* Description  : This function set RAM data for transmission.
* Arguments    : None
* Return Value : None
********************************************************************************/
static void r_ram_data_send(void)
{

  IICA0 = g_ram[g_selRAM][gp_ram[g_selRAM]];/* transmit RAM data               */
                                  
} /* End of function r_ram_data_send() */




/*          copy to this line(line 620)                                          */


#endif
/* End user code. Do not edit comment generated here */








