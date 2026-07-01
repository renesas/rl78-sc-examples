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
* Creation Date: 2021-05-12
***********************************************************************************************************************/
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
 
    If copy actual program ,please copy from line 180 to line 1010.

  Important !! Important !! Important !! Important !! Important !! Important !!
********************************************************************************/


#ifndef USER_MODE
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Pragma directive
***********************************************************************************************************************/
#pragma interrupt r_Config_IICA0_interrupt(vect=INTIICA0)
/* Start user code for pragma. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
extern volatile uint8_t g_iica0_master_status_flag;      /* iica0 master flag */
extern volatile uint8_t * gp_iica0_rx_address;           /* iica0 receive buffer address */
extern volatile uint16_t g_iica0_rx_len;                 /* iica0 receive data length */
extern volatile uint16_t g_iica0_rx_cnt;                 /* iica0 receive data count */
extern volatile uint8_t * gp_iica0_tx_address;           /* iica0 send buffer address */
extern volatile uint16_t g_iica0_tx_cnt;                 /* iica0 send data count */
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
* Function Name: r_Config_IICA0_master_handler
* Description  : This function is IICA0 master handler
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
static void r_Config_IICA0_master_handler(void)
{
    if (!((0U == IICBSY0) && (0U != g_iica0_tx_cnt)))
    {
        if (0U == (g_iica0_master_status_flag & _80_IICA_ADDRESS_COMPLETE))
        {
            if (1U == ACKD0)
            {
                g_iica0_master_status_flag |= _80_IICA_ADDRESS_COMPLETE;
                
                if (1U == TRC0)
                {
                    WTIM0 = 1U;
                    
                    if (g_iica0_tx_cnt > 0U)
                    {
                        IICA0 = *gp_iica0_tx_address;
                        gp_iica0_tx_address++;
                        g_iica0_tx_cnt--;
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
            /* Master send control */
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
                }
            }
            /* Master receive control */
            else
            {
                if (g_iica0_rx_cnt < g_iica0_rx_len)
                {
                    *gp_iica0_rx_address = IICA0;
                    gp_iica0_rx_address++;
                    g_iica0_rx_cnt++;
                    
                    if (g_iica0_rx_cnt == g_iica0_rx_len)
                    {
                        ACKE0 = 0U;
                        WTIM0 = 1U;
                        WREL0 = 1U;
                    }
                    else
                    {
                        WREL0 = 1U;
                    }
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
static void __near r_Config_IICA0_interrupt(void)
{
    /* Start user code for r_Config_IICA0_interrupt. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
    if (0x80U == (IICS0 & _80_IICA_STATUS_MASTER))
    {
        r_Config_IICA0_master_handler();
    }
}

/* Start user code for adding. Do not edit comment generated here */

/* above procedure is ignored   */
#endif


#ifdef USER_MODE


/*          copy from this line(line 180)                                      */


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
Pragma directive
********************************************************************************/
#pragma interrupt r_Config_IICA0_interrupt(vect=INTIICA0, bank=RB3)


/*******************************************************************************
Global variables and functions
********************************************************************************/

volatile uint8_t   g_status;            /* iica0 master operationflag   */
/*
    0x00(BUS_FREE)  : bus is free
    0x20(OP_END)    : operation end without error
    0x20(BUS_HOLD)  : IICA0 hold I2C bus
    0x22(TX_END)    : transmit operation complete and hold I2C bus
    0x24(RX_END)    : receive operation complete and hold I2C bus
    0x12(TX_MODE)   : data transmit mode
    0x14(RX_MODE)   : data receive mode
    0x16(TX_ADDR_REG): transmit address register
    0x18(TX_SADDR)  : slave address transmit
    0x0F(BUS_BUSY)  : bus is busy
    0x8F(BUS_ERROR) : operation error (BUS or IICA0 is BUSY)
    0x80(NO_SLAVE)  : NACK for slave address
    0xC0(NO_ACK)    : NACK for data
*/

volatile uint8_t * gp_rx_address;       /* iica0 receive buffer address */
volatile uint16_t  g_rx_len;            /* iica0 receive data length    */
volatile uint16_t  g_rx_cnt;            /* iica0 receive data count     */
volatile uint8_t * gp_tx_address;       /* iica0 send buffer address    */
volatile uint16_t  g_tx_cnt;            /* iica0 send data count        */

volatile uint8_t   g_sl_addr;           /* slave address(8bit)          */
volatile uint8_t   g_adr_reg;           /* address register(8bit)       */
volatile uint8_t   g_adr_flag;          /* address register enable flag */
/*
    0x00 : not use address register(for conventional API)
    0x01 : use address register for write mode(only send addres register)
    0x10 : use address register for read mode(restart is needed)
*/

/*******************************************************************************
Local functions
********************************************************************************/

uint8_t R_IICA0_bus_check(void);        /* check IIC bus status         */
uint8_t R_IICA0_StartCondition(void);   /* issue start condition        */

static void r_IICA0_master_handler(void); /* IICA0 interrupt handler    */
void wait_time(void);                   /* wait for 50us                */

/*******************************************************************************
* Function Name: R_Config_IICA0_Create_UserInit
* Description  : This function adds user code after initializing the IICA0.
* Arguments    : None
* Return Value : None
********************************************************************************/
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
    if ( 0x80 == ( IICS0 & 0x80 ) )     /* check master mode            */
    {                                   /* master mode interrupt        */
        r_IICA0_master_handler();
    }
    else
    {                                   /* slave mode interrupt         */
        /* do nothing   */
    }

}

/********************************************************************************
* Function Name: r_IICA0_master_handler
* Description  : This function is IICA0 master handler
* Arguments    : None
* Return Value : None
*********************************************************************************/
static void r_IICA0_master_handler(void)
{
/* master mode operation    */

    uint8_t status;

    if ( 1 == STD0 )                        /* slave address transmit end   */
    {

/*----------------------------------------------
  slave address transmission end
----------------------------------------------*/

        if ( 1 == ACKD0 )
        {

/*======================================================

  ACK response for slave address and start data transfer

======================================================*/

            if ( 1 == TRC0 )
            {

/*----------------------------------------------

  data transmit mode operation

----------------------------------------------*/

                if ( 0x00 == g_adr_flag )  /* check send address register  */
                {

/*----------------------------------------------
    not address register but data transmit
----------------------------------------------*/

                    g_status = TX_MODE;     /* set data transmit mode       */
                    if ( g_tx_cnt > 0 )
                    {

/*----------------------------------------------
    more data to transmit
----------------------------------------------*/

                        IICA0 = *gp_tx_address; /* set transmit data        */
                        ++gp_tx_address;    /* move pointer to next data    */
                        --g_tx_cnt;         /* count down data number       */
                    }
                    else
                    {
/*----------------------------------------------
    no more data to transmit
----------------------------------------------*/

                        g_status = TX_END;  /* set data transfer end        */
                    }

                }   /* end of data transmit */
                else
                {

/*----------------------------------------------
    address register transmit
----------------------------------------------*/

                    IICA0 = g_adr_reg;      /* send address register        */
                    g_status = TX_ADDR_REG; /* set status                   */

                }   /* end of address register transmit */

            }   /* end of data transmit */
            else
            {

/*----------------------------------------------

    data receive mode operation

----------------------------------------------*/

                WTIM0 = 0;                  /* set 8bit wait mode           */
                ACKE0 = 1;
                
                IICA0 = DUMMY_DATA;         /* canceling wait and start Rx  */
                g_status = RX_MODE;         /* set receive mode flag        */

            }

        }   /* end of ACK for slave address */
        else
        {

/*----------------------------------------------
    NAK response for slave address
----------------------------------------------*/

            SPT0 = 1;                       /* issue stop condition         */
            g_status = NO_SLAVE;            /* set communication error flag */

        }   /* end of no slave exist    */

    }   /* end of slave address transmit operation  */
    else
    {


/*======================================================

    data transfer stage(STD0 is 0)

======================================================*/

        if ( 1 == TRC0 )                    /* check transmit or receive    */
        {

/*----------------------------------------------

    transmit operation mode

----------------------------------------------*/

            if ( 1 == ACKD0 )               /* check slave state            */
            {                               /* slave is ready for next data */

/*----------------------------------------------
  success data transfer
----------------------------------------------*/

                if ( ( TX_ADDR_REG == g_status ) && ( 0x10 == g_adr_flag ) )
                {

/*----------------------------------------------
  end of transmit address register for RAM read mode
  and restart to read mode
----------------------------------------------*/

                    status = R_IICA0_StartCondition();

                    if ( SUCCESS == status )
                    {
                        IICA0 = ( g_sl_addr | 0x01 );
                        g_status = RX_MODE;     /* set receive mode             */
                    }
                    else
                    {
                        LREL0 = 1;
                        g_status = BUS_ERROR;
                    }

                }
                else
                {
/*----------------------------------------------
  success data transfer and check remaining data
----------------------------------------------*/

                    g_status = TX_MODE;         /* set transmit mode flag       */

                    if ( g_tx_cnt > 0 )         /* check transmit data number   */
                    {

/*----------------------------------------------
  prepare next transmit data
----------------------------------------------*/

                        IICA0 = *gp_tx_address; /* transmit data                */
                        ++gp_tx_address;        /* move pointer to next data    */
                        --g_tx_cnt;             /* count down data number       */

                    }   /* end of one data transmit */
                    else
                    {

/*----------------------------------------------
  data transmit complete, set end flag and exit
----------------------------------------------*/

                        g_status = TX_END;      /* set data transfer end        */

                    }   /* end of transmit all data */
                }

            }   /* end by ACK response  */
            else
            {

/*----------------------------------------------
    NACK error
----------------------------------------------*/

                g_status = NO_ACK;          /* set communication error flag */

            }   /* end by NACK response */

        }   /* end of data transmit */
        else
        {

/*----------------------------------------------

    receive operation mode

----------------------------------------------*/

            if ( g_rx_cnt < g_rx_len )
            {

/*----------------------------------------------
store recieved data
----------------------------------------------*/

                *gp_rx_address = IICA0;     /* store received data      */
                ++gp_rx_address;            /* move store pointer       */
                ++g_rx_cnt;                 /* countup data number      */
                if ( g_rx_cnt == g_rx_len )
                {

/*----------------------------------------------
receive last data operation (send NACK and change to 9 clock wait)
----------------------------------------------*/

                    ACKE0 = 0;              /* NACK for last data       */
                    WTIM0 = 1;              /* change to 9clock wait    */
                    WREL0 = 1;              /* canceling wait to end    */
                }
                else
                {
                    WREL0 = 1;              /* start next reception     */
                }

            }   /* end of receive continue  */
            else
            {

/*----------------------------------------------
receive operation complete at 9th clock
----------------------------------------------*/

                g_status = RX_END;          /* set data receive end     */

            }   /* end of data number check of receive  */

        }   /* end of data receive  */

    }   /* end of data transfer */

/* master transfer operation end    */

}   /* end of r_IICA0_master_handler    */


/*******************************************************************************
* Function Name: R_IICA0_Master_Send
* Description  : This function starts IICA0 in transmision mode.
* Arguments    : sladr8 -
*                    slave address(8bit)
*                tx_buf -
*                    transfer data pointer
*                tx_num -
*                    transmit data number
* Return Value : 
*                0x00(SUCCESS)  : get IIC bus and transmit slave address
*                0x8F(BUS_ERROR): I2C bus or IICA0 is busy
********************************************************************************/
uint8_t R_IICA0_Master_Send(uint8_t sladr8, uint8_t * const tx_buf, uint16_t tx_num)
{

    uint8_t status;

    g_adr_flag = 0x00;                  /* disable address register     */
    status = R_IICA0_bus_check();       /* check I2C bus status         */

    if ( SUCCESS == status )
    {

        g_tx_cnt = tx_num;              /* set data number to transmit  */
        gp_tx_address = tx_buf;         /* set data pointer             */
        g_status = TX_SADDR;            /* set operation mode flag      */

    /* get IIC bus and start to access IIC bus  */

        IICA0 = ( sladr8 & 0xFE );      /* transmit slave address       */

    }

    return (status);

}   /* end of R_IICA0_Master_Send   */

/*******************************************************************************
* Function Name: R_IICA0_Master_Receive
* Description  : This function starts iica0 in receive mode.
* Arguments    : sladr8 -
*                    slave address
*                rx_buf -
*                    received data buffer pointer
*                rx_num -
*                    receive data size
* Return Value : status -
*                0x00(SUCCESS)  : get IIC bus and transmit slave address
*                0x8F(BUS_ERROR): I2C bus or IICA0 is busy
*                0xFF(COM_ERROR): command parameter error(receive null data)
********************************************************************************/
uint8_t R_IICA0_Master_Receive(uint8_t sladr8, uint8_t * const rx_buf, uint16_t rx_num)
{

    uint8_t status;

    status = COM_ERROR;                 /* set command parameter error  */
    if ( 0x00 == rx_num ) return ( status );

    g_adr_flag = 0x00;                  /* disable address register     */
    status = R_IICA0_bus_check();       /* check IIC bus status         */

    if ( SUCCESS == status )
    {

    /* get IIC bus and set access parameters    */

        g_rx_len = rx_num;              /* set data number to transmit  */
        g_rx_cnt = 0U;
        gp_rx_address = rx_buf;         /* set data pointer             */
        g_status = TX_SADDR;            /* set operation mode flag      */

    /* start to access IIC bus  */

        IICA0 = ( sladr8 | 0x01 );      /* transmit slave address       */

    }

    return (status);

}   /* end of R_IICA0_Master_Receive    */


/*******************************************************************************
* Function Name: R_IICA0_check_comstate
* Description  : This function get communication status
* Arguments    : none
* Return Value : result status
                0x00(BUS_FREE)  : I2C bus is free(SUCCESS)
                0x18(TX_SADDR)  : transmit slave address
                0x16(TX_ADDR_REG): transmit address register
                0x14(RX_MODE)   : receive operation mode
                0x12(TX_MODE)   : transmit operation mode
                0x20(OP_END)    : operation end and hold I2C bus
                0x22(TX_END)    : transmit end and hold I2C bus
                0x24(RX_END)    : receive and and hold I2C bus
                0x8F(BUS_ERROR) : bus or IICA0 is busy error
                0x80(NO_SLAVE)  : NACK for slave address
                0xC0(NO_ACK)    : NACK for transmit data
********************************************************************************/
uint8_t R_IICA0_check_comstate(void)
{

    return( g_status );

}   /* end of R_IICA0_check_comstate*/


/*******************************************************************************
* Function Name: R_IICA0_poll
* Description  : This function check communication end
* Arguments    : none
* Return Value : result status
                0x00(SUCCESS)   : success(operation complete)
                0x01(ON_COMMU)  : on communication( not complete )

                0x8F(BUS_ERROR) : bus or IICA0 is busy error
                0x80(NO_SLAVE)  : NACK for slave address
                0xC0(NO_ACK)    : NACK for transmit data
********************************************************************************/
uint8_t R_IICA0_poll(void)
{
    uint8_t status;

    status = g_status;                  /* get communication status     */

    if ( 0x30 > status )                /* check status is error or not */
    {                                   /* there is no error status     */

        if ( OP_END <= status )         /* check operation end or not   */
        {
            status = SUCCESS;           /* set operation success flag   */
        }
        else
        {                               /* continue communication       */
            status = ON_COMMU;
        }

    }

    return (status);                    /* return with status           */

}   /* end of R_IICA0_poll  */


/*******************************************************************************
* Function Name: R_IICA0_wait_comend
* Description  : This function wait for communication end
* Arguments    : after operation issue stopcondition or not
                0x00 : if success,not issue stopcondition
                0x01 : when finish issue stopcondition
* Return Value : result status
                0x00(SUCCESS)   : success(operation complete)

                0x8F(BUS_ERROR) : bus or IICA0 is busy error
                0x80(NO_SLAVE)  : NACK for slave address
                0xC0(NO_ACK)    : NACK for transmit data
********************************************************************************/
uint8_t R_IICA0_wait_comend(uint8_t stop)
{
    uint8_t status = ON_COMMU;


    while( ON_COMMU == status )
   {
        status = R_IICA0_poll();        /* check new status             */
        NOP();                          /* wait for communication end   */
    }

    if ( ( SUCCESS !=  status ) || ( 0x00 != stop ) )
    {   /* communication error or argument  */
        R_IICA0_StopCondition();        /* issue STOP conditiopn        */
        wait_time();                    /* wait for 50us                */
    }

    return( status );

}   /* end of R_IICA_wait_comend    */


/*******************************************************************************
* Function Name: R_IICA0_Tx
* Description  : This function transmit data.
* Arguments    : sladr7 -
*                    slave address(7 bit address)
*                adr -
*                    address register data
*                tx_buf -
*                    transfer data pointer
*                tx_num -
*                    transmit data number
* Return Value : 
*                0x00(SUCCESS)  : get IIC bus and transmit slave address
*                0x8F(BUS_ERROR): I2C bus or IICA0 is busy
********************************************************************************/
uint8_t R_IICA0_Tx(uint8_t sladr7, uint8_t adr, uint8_t * const tx_buf, uint16_t tx_num)
{

    uint8_t status;

    status = R_IICA0_bus_check();       /* check I2C bus status         */

    if ( SUCCESS == status )
    {

/*----------------------------------------------
    I2C bus is usable and prepare for transmission
----------------------------------------------*/

        g_adr_flag = 0x01;              /* enable address register      */
        g_adr_reg = adr;                /* set address register data    */
        g_sl_addr = ( sladr7 << 1 );    /* set 8bit slave address       */
        g_tx_cnt = tx_num;              /* set data number to transmit  */
        gp_tx_address = tx_buf;         /* set data pointer             */
        g_status = TX_SADDR;            /* set operation mode flag      */

/* get IIC bus and start to access IIC bus  */

        IICA0 = g_sl_addr;              /* transmit slave address       */

/*----------------------------------------------
    send slave address and wait for complete transmission
----------------------------------------------*/

        do{
            wait_time();                /* check interval is 50us       */
            status = R_IICA0_poll();    /* check new status             */
        }
        while ( ON_COMMU == status );   /* wait for transmission end    */

        if ( SUCCESS !=  status )
        {   /* communication error  */
            R_IICA0_StopCondition();    /* issue STOP conditiopn        */
            wait_time();                /* wait for 50us                */
        }

    }

    return (status);

}   /* end of R_IICA0_Tx    */


/*******************************************************************************
* Function Name: R_IICA0_Rx
* Description  : This function receive data.
* Arguments    : sladr7 -
*                    slave address(7 bit address)
*                adr -
*                    address register data
*                rx_buf -
*                    received data pointer
*                rx_num -
*                    receive data number
* Return Value : 
*                0x00(SUCCESS)  : get IIC bus and transmit slave address
*                0x8F(BUS_ERROR): I2C bus or IICA0 is busy
*                0xFF(COM_ERROR): command parameter error(receive null data)
********************************************************************************/
uint8_t R_IICA0_Rx(uint8_t sladr7, uint8_t adr, uint8_t * const rx_buf, uint16_t rx_num)
{

    uint8_t status;

    if ( 0x00 == rx_num )
    {
        status = COM_ERROR;             /* set command parameter error  */
        return( status );
    }

    status = R_IICA0_bus_check();       /* check I2C bus status         */

/*------------------------------------------------------
    I2C bus is usable and prepare for receiving
------------------------------------------------------*/

    if ( SUCCESS == status )
    {
        g_adr_flag = 0x10;              /* enable address register      */
        g_adr_reg = adr;                /* set address register data    */
        g_sl_addr = ( sladr7 << 1 );    /* set 8bit slave address       */

        g_rx_len = rx_num;              /* set data number to transmit  */
        g_rx_cnt = 0U;
        gp_rx_address = rx_buf;         /* set data pointer             */
        g_status = TX_SADDR;            /* set operation mode flag      */

    /* get I2C bus and start to access I2C bus  */

        IICA0 = g_sl_addr;              /* transmit slave address       */

/*------------------------------------------------------
    send slave address and wait for complete transmission
------------------------------------------------------*/

        do{
            wait_time();                /* check interval is 50us       */
            status = R_IICA0_poll();    /* check new status             */
        }
        while ( ON_COMMU == status );   /* wait for transmission end    */

        if ( SUCCESS !=  status )
        {   /* communication error  */
            R_IICA0_StopCondition();    /* issue STOP conditiopn        */
            wait_time();                /* wait for 50us                */
        }

    }

    return (status);

}   /* end of R_IICA0_Rx    */

/*******************************************************************************
* Function Name: wait_time
* Description  : This function wait 50us
* Arguments    : none
* Return Value : none
********************************************************************************/
void wait_time(void)
{
    TMIF01 = 0;
    TMMK01 = 1U;                        /* disable INTTM01 interrupt    */

    TS0 = 0x0002;                       /* start TM01 50us timer        */
    while ( 0 == TMIF01 )               /* wait for 50us                */
    {
        NOP();
    }
    TMIF01 = 0;
    TT0 = 0x0002;                       /* stop TM01(50us interval)     */

}   /* end of wait_time */


/*******************************************************************************
* Function Name: R_IICA0_StartCondition
* Description  : This function issue start condition
* Arguments    : none
* Return Value : result
                0x00(SUCCESS)   : success
                0x8F(BUS_ERROR) : error
********************************************************************************/
uint8_t R_IICA0_StartCondition(void)
{

    uint8_t status;
    uint16_t wait;

    status = BUS_ERROR;                 /* set dummy status "error"     */

    STT0 = 1;                           /* issue IICA0 start condition  */

/*------------------------------------------------------
    Wait for start condition is detected
------------------------------------------------------*/

    for( wait = WAITTIME ; wait > 0 ; --wait)
    {
        if ( 1 == STD0 )
        {
            break;                      /* exit with start condition    */
        }
    }

/*------------------------------------------------------
    detecte start condition or timeout
------------------------------------------------------*/

    if ( ( 1 == MSTS0 ) && ( 1 == STD0 ) )  /* check bus status         */
    {

/*------------------------------------------------------
    get bus and success to issue start condition
------------------------------------------------------*/

        status = SUCCESS;               /* set good result              */
        g_status = BUS_HOLD;            /* set new status               */
    }

    return (status);

}   /* end of R_IICA0_StartCondition*/


/*******************************************************************************
* Function Name: R_IICA0_StopCondition
* Description  : This function issue stop condition
* Arguments    : none
* Return Value : result
*               0x00(SUCCESS)   : success
*               0x8F(BUS_ERROR) : error
********************************************************************************/
uint8_t R_IICA0_StopCondition(void)
{

    uint8_t status;
    uint16_t wait;

    status = SUCCESS;                   /* set dummy status "success"   */

    SPT0 = 1;                           /* issue stop condition to stop */

    for( wait = WAITTIME ; wait > 0 ; wait-- )
    {                                   /* wait for detection           */
        if ( 1 == SPD0 );
        {                               /* detect stop condition        */
            g_status = BUS_FREE;        /* set bus is free              */
            break;
        }
    }

    if ( 0 == SPD0 )
    {             
       status = BUS_ERROR;              /* not detect stop condition    */
    }

    return (status);

}   /* end of R_IICA0_StopCondition */


/*******************************************************************************
* Function Name: R_IICA0_bus_check
* Description  : This function check I2C bus and issue start condition if possible
* Arguments    : none
* Return Value : status -
*               0x00(SUCCESS)  : get I2C bus (success to get bus)
*               0x8F(BUS_ERROR): I2C bus or IICA0 is busy
********************************************************************************/
uint8_t R_IICA0_bus_check(void)
{
    uint8_t status;

    /* Check I2C bus is used or in waiting state    */

    status = BUS_ERROR;                     /* set dummy error flag         */
    if ( 0x00 == ( g_status & 0x10) )       /* check if operating or not    */
    {

/*------------------------------------------------------
    IICA0 is not operating
------------------------------------------------------*/

        if ( ( 1 == MSTS0 ) || ( 0 == IICBSY0 )  )  /* check if I2C is busy */
        {

/*------------------------------------------------------
    I2C bus is usable
------------------------------------------------------*/

            status = R_IICA0_StartCondition();  /* issue start condition    */
            if ( SUCCESS == status )
            {
                g_status = BUS_HOLD;
            }

        }

    }

    return (status);

}   /* end of R_IICA0_bus_check */



/*          copy to this line(line 1010)                                    */

#endif
/* End user code. Do not edit comment generated here */
