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
* Component Version: 1.5.1
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
#include "Config_TAU0_1.h"

#define USER_MODE
#define USER_MODE2

/********************************************************************************
 Important !! Important !! Important !! Important !! Important !! Important !!

    If copy actual program ,please copy from line 180 to line 810.

  Important !! Important !! Important !! Important !! Important !! Important !!
********************************************************************************/

#ifndef USER_MODE
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
extern volatile uint8_t g_iica0_master_status_flag;      /* iica0 master flag */
extern volatile uint8_t * gp_iica0_rx_address;           /* iica0 receive buffer address */
extern uint16_t g_iica0_rx_len;                          /* iica0 receive data length */
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
        /* Control for sended address */
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
#pragma vector = INTIICA0_vect
__interrupt static void r_Config_IICA0_interrupt(void)
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




/*          copy from this line(line 180)                                      */
#ifdef USER_MODE
/********************************************************************************
*********************************************************************************
*                                                                               *
	The following area is actual program
*                                                                               *
*********************************************************************************
********************************************************************************/

#ifndef USER_MODE2
/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_userdefine.h"
#include "Config_IICA0.h"
#include "Config_TAU0_2.h"
#endif

/***********************************************************************************************************************
Pragma directive
***********************************************************************************************************************/
#pragma interrupt r_Config_IICA0_interrupt(vect=INTIICA0)

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
volatile uint8_t   g_iica0_status;                      /* iica0 master operationflag   */
/*  
    0x00 : success(IIC_SUCCESS)
    0x01 : transmit operating(IIC_USING) same as ON_COMMU
    0x84 : no ACK from slave for data(NO_ACK)
    0x88 : no ACK for slave address(NO_SLAVE)
    0x8C : I2C BUS busy(BUS_BUSY)
*/

extern volatile uint8_t g_iica0_master_status_flag;     /* iica0 master flag            */
extern volatile uint8_t * gp_iica0_rx_address;          /* iica0 receive buffer address */
extern uint16_t g_iica0_rx_len;                         /* iica0 receive data length    */
extern volatile uint16_t g_iica0_rx_cnt;                /* iica0 receive data count     */
extern volatile uint8_t * gp_iica0_tx_address;          /* iica0 send buffer address    */
extern volatile uint16_t g_iica0_tx_cnt;                /* iica0 send data count        */

volatile uint8_t    g_write_data[MAX_DATA+1];           /* transmit data buffer         */

/*******************************************************************************
Local functions
*******************************************************************************/
uint8_t R_IICA0_bus_check(void);        /* check I2C bus status         */
static void r_IICA0_master_handler(void); /* IICA0 interrupt handler    */

/*******************************************************************************
* Function Name: R_Config_IICA0_Create_UserInit
* Description  : This function adds user code after initializing the IICA0.
* Arguments    : None
* Return Value : None
********************************************************************************/
void R_Config_IICA0_Create_UserInit(void)
{
	
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
        r_IICA0_master_handler();
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
    if ( TRUTH == MSTS0 )               /* check slave mode operation ? */
    {

/*==============================================================*/
/*      master mode interrupt operation start                   */
/*==============================================================*/

        if ( TRUTH == STD0 )            /* slave address transmit end   */
        {
            if ( TRUTH == ACKD0 )
            {

/*--------------------------------------------------------------*/
/*      ACK response and start data transfe                     */
/*--------------------------------------------------------------*/

                if ( TRUTH == TRC0 )

/*==============================================================*/
/*	    data transmit mode operation	                        */
/*==============================================================*/

                {
                    if ( g_iica0_tx_cnt > 0 )
                    {

/*--------------------------------------------------------------*/
/*      there is more data to transmit then transmit it         */
/*--------------------------------------------------------------*/

                        IICA0 = *gp_iica0_tx_address;   /* set transmit data        */
                        gp_iica0_tx_address++;          /* move pointer to next data*/
                        g_iica0_tx_cnt--;               /* count down data number   */
                    }
                    else
                    {

/*--------------------------------------------------------------*/
/*      whole data has been transmitted                         */
/*--------------------------------------------------------------*/

                        g_iica0_status = IIC_SUCCESS;   /* set data transfer end    */
                    }
                }
                else
                {

/*==============================================================*/
/*	    data receive mode operation	                            */
/*==============================================================*/

                    WTIM0 = FALSE;              /* set 8bit wait mode           */
                    ACKE0 = TRUTH;
                    
                    IICA0 = DUMMY_DATA;         /* canceling wait and start Rx  */
                }
            }
            else
            {

/*--------------------------------------------------------------*/
/*      there is no slave that respond ACK for slave address    */
/*--------------------------------------------------------------*/

                g_iica0_status = NO_SLAVE;      /* set communication error flag */
            }

        }
        else
        {

/*==============================================================*/
/*      data transfer stage                                     */
/*==============================================================*/

            if ( TRUTH == TRC0 )
            {

/*==============================================================*/
/*      transmit operation mode                                 */
/*==============================================================*/

                if ( TRUTH == ACKD0 )
                {

/*--------------------------------------------------------------*/
/*      success data transmit and check remaining data          */
/*--------------------------------------------------------------*/

                    if ( g_iica0_tx_cnt > 0 )   /* check transmit data number   */
                    {

/*--------------------------------------------------------------*/
/*      change prepare to index next transmit data              */
/*--------------------------------------------------------------*/

                        IICA0 = *gp_iica0_tx_address;   /* transmit data            */
                        gp_iica0_tx_address++;          /* move pointer to next data*/
                        g_iica0_tx_cnt--;               /* count down data number   */
                    }
                    else
                    {

/*--------------------------------------------------------------*/
/*      data transmit complete, set end flag and exit           */
/*--------------------------------------------------------------*/

                        g_iica0_status = IIC_SUCCESS;   /* set data transfer end    */

                    }
                }
                else
                {

/*--------------------------------------------------------------*/
/*      NACK error                                              */
/*--------------------------------------------------------------*/

                    g_iica0_status = NO_ACK;            /* set communication error flag */
                }
            }
            else
            {

/*==============================================================*/
/*      receive operation mode                                  */
/*==============================================================*/

                if ( g_iica0_rx_cnt < g_iica0_rx_len )
                {

/*--------------------------------------------------------------*/
/*      store recieved data                                     */
/*--------------------------------------------------------------*/

                    *gp_iica0_rx_address = IICA0;   /* store received data  */
                    gp_iica0_rx_address++;          /* move store pointer   */
                    g_iica0_rx_cnt++;               /* countup data number  */
                    if ( g_iica0_rx_cnt == g_iica0_rx_len )
                    {

/*--------------------------------------------------------------*/
/*      receive last data operation (send NACK and change to    */
/*      9 clock wait mode                                       */
/*--------------------------------------------------------------*/

                        ACKE0 = FALSE;              /* NACK for last data   */
                        WTIM0 = TRUTH;              /* change to 9clock wait*/
                        WREL0 = TRUTH;              /* canceling wait to end*/
                    }
                    else
                    {
                        WREL0 = TRUTH;              /* start next reception */
                    }
                }
                else
                {

/*--------------------------------------------------------------*/
/*      receive operation complete at 9th clock                 */
/*--------------------------------------------------------------*/

                    g_iica0_status = IIC_SUCCESS;   /* set data receive end */


                }

            }

        }

/*==============================================================*/
/*      master transfer operation end                           */
/*==============================================================*/

    }
}

/*******************************************************************************
* Function Name: r_IICA0_put_data
* Description  : This function transmit data to specified slave
* Arguments    : slave address, register address, data buffer address, data numer
* Return Value : 00:successs
*                not 00:error
********************************************************************************/
uint8_t r_IICA0_put_data( uint8_t s_addr, uint8_t r_addr, uint8_t __far * const buffer, uint8_t tx_num )
{
    uint8_t cnt;
    uint8_t cnt2;
    uint8_t __far * ptr;                /* input data pointer           */
    uint8_t status;
/*  
    0x00 : success(IIC_SUCCESS)
    0x01 : transmit operating(IIC_USING)
    0x84 : no ACK from slave for data(NO_ACK)
    0x88 : no ACK for slave address(NO_SLAVE)
    0x8C : I2C BUS busy(BUS_BUSY)
*/
    uint8_t retry_count;                /* error retry counter          */

/*--------------------------------------------------------------*/
/*      copy communication parameters                           */
/*--------------------------------------------------------------*/

    cnt = tx_num;                       /* set transmit data number     */
    g_write_data[0] = r_addr;           /* set register address         */
    ptr = buffer;                       /* set data pointer             */

    for ( cnt2 = 0 ; cnt2 < cnt ; cnt2++ )
    {

/*--------------------------------------------------------------*/
/*      copy transmit data to transmit buffer                   */
/*--------------------------------------------------------------*/

        g_write_data[cnt2+1] = *ptr;    /* copy transmit data           */
        ptr++;                          /* move data pointer            */
    }

/*--------------------------------------------------------------*/
/*      start transmission                                      */
/*--------------------------------------------------------------*/

    for ( retry_count = RETRY ; retry_count > 0 ; )
    {

        status = R_IICA0_Master_Send(s_addr, (uint8_t *__near)g_write_data, cnt+1);

        if( IIC_SUCCESS == status )     /* check start successfully     */
        {

/*--------------------------------------------------------------*/
/*      transmit start and wait for transmission end            */
/*--------------------------------------------------------------*/

            do
            {                           /* wait for transmission end    */

                status = R_IICA0_check_comstate(); /* get IIC status      */

            }while( IIC_USING == ( status & STS_MASK ) );
        
        }
        else
        {
            /* do nothing */
        }

/*--------------------------------------------------------------*/
/*      transmission end and check result of communication      */
/*--------------------------------------------------------------*/

        if( NO_SLAVE == status )
        {                                 /* no ACK for slave address     */
            R_IICA0_StopCondition();      /* issue stop condition         */
            delay_us(10);               /* wait for retry timing        */
            retry_count--;
        }
        else
        {
            retry_count = 0;
        }
    }
/*
    release IIC  bus
*/
    if( NO_SLAVE != status )
    {
        R_IICA0_StopCondition();          /* issue stop condition         */
    }
    else
    {
            /* do nothing */
    }

    return (status);
}

/*******************************************************************************
* Function Name: r_IICA0_get_data
* Description  : This function transmit data to specified slave
* Arguments    : slave address, register address, data buffer address, data numer
* Return Value : 00:successs
*                not 00:error
********************************************************************************/
uint8_t r_IICA0_get_data( uint8_t s_addr, uint8_t r_addr, uint8_t * const buffer, uint8_t rx_num )
{
    uint8_t status;
    uint8_t retry_count;                /* error retry counter          */

    g_write_data[0] = r_addr;           /* set register address         */

/*==============================================================*/
/*      start i2c communication                                 */
/*==============================================================*/

    for ( retry_count = RETRY ; retry_count > 0 ; )
    {

/*--------------------------------------------------------------*/
/*      transmit register address                               */
/*--------------------------------------------------------------*/

        status = R_IICA0_Master_Send(s_addr, (uint8_t *__near)g_write_data, 1);

        if( IIC_SUCCESS == status )     /* check start successfully     */
        {

/*--------------------------------------------------------------*/
/*      transmission start and wait for transmission end        */
/*--------------------------------------------------------------*/

            do
            {

                status = R_IICA0_check_comstate(); /* get IIC status      */

            }while( IIC_USING == ( status & STS_MASK ) );

        }
        else
        {
                /* do nothing */
        }

/*--------------------------------------------------------------*/
/*      transmission end and check result                       */
/*--------------------------------------------------------------*/

        if( NO_SLAVE == status )
        {                               /* no ACK for slave address     */
            R_IICA0_StopCondition();      /* issue stop condition         */
            delay_us(10);               /* wait for retry timing        */
            retry_count--;
        }
        else
        {
            break;
        }
    }

/*--------------------------------------------------------------*/
/*      transmission end                                        */
/*--------------------------------------------------------------*/

    if ( IIC_SUCCESS == status )        /* check result         */
    {

/*--------------------------------------------------------------*/
/*      start IIC receiving                                     */
/*--------------------------------------------------------------*/

        status = R_IICA0_Master_Receive(s_addr, (uint8_t *__near)buffer, rx_num);

        if( IIC_SUCCESS == status )     /* check start successfully     */
        {

/*--------------------------------------------------------------*/
/*      wait for receive end                                    */
/*--------------------------------------------------------------*/

            do
            {
                status = R_IICA0_check_comstate();

            }while( IIC_USING == ( status & STS_MASK ) );
        }
        else
        {
            /* do nothing */
        }

    }
    else
    {
        /* do nothing */
    }

    if( NO_SLAVE != status )
    {
        R_IICA0_StopCondition();          /* issue stop condition     */
    }
    else
    {
            /* do nothing */
    }

    return (status);
}

/*******************************************************************************
* Function Name: R_IICA0_Master_Send
* Description  : This function starts iica0 in transmision mode.
* Arguments    : adr -
*                    slave address
*                tx_buf -
*                    transfer data pointer
*                tx_num -
*                    transmit data number
* Return Value : none
*                    IIC_SUCCESS: get I2C bus and transmit slave address
*                    BUS_BUSY: I2C bus is busy
********************************************************************************/
uint8_t R_IICA0_Master_Send(uint8_t adr, uint8_t * const tx_buf, uint16_t tx_num)
{
    uint8_t status;

    status = R_IICA0_bus_check();       /* check I2C bus status         */

    if ( IIC_SUCCESS == status )
    {
/*--------------------------------------------------------------*/
/*      get I2C bus and start to access I2C bus                 */
/*--------------------------------------------------------------*/

        g_iica0_tx_cnt = tx_num;        /* set data number to transmit  */
        gp_iica0_tx_address = tx_buf;   /* set data pointer             */

/*--------------------------------------------------------------*/
/*      get I2C bus and start to access I2C bus                 */
/*--------------------------------------------------------------*/

        IICA0 = adr & 0xFE;             /* transmit slave address       */

    }
    else
    {
        /*  do nothing  */
    }

    return (status);
}

/*******************************************************************************
* Function Name: R_IICA0_Master_Receive
* Description  : This function starts iica0 in receive mode.
* Arguments    : adr -
*                    slave address
*                rx_buf -
*                    received data buffer pointer
*                rx_num -
*                    receive data size+1
* Return Value : status -
*                    IIC_SUCCESS: get I2C bus and transmit slave address
*                    BUS_BUSY: I2C bus is busy
********************************************************************************/
uint8_t R_IICA0_Master_Receive(uint8_t adr, uint8_t * const rx_buf, uint16_t rx_num)
{
    MD_STATUS status;

    status = R_IICA0_bus_check();       /* check I2C bus status         */

    if ( IIC_SUCCESS == status )
    {

/*--------------------------------------------------------------*/
/*      get I2C bus and set access parameters                   */
/*--------------------------------------------------------------*/

        g_iica0_rx_len = rx_num;        /* set data number to transmit  */
        g_iica0_rx_cnt = 0U;
        gp_iica0_rx_address = rx_buf;   /* set data pointer             */

/*--------------------------------------------------------------*/
/*      start to access I2C bus                                 */
/*--------------------------------------------------------------*/

        IICA0 = adr | 0x01;             /* transmit slave address       */

    }

    return (status);
}

/*******************************************************************************
* Function Name: R_IICA0_check_comstate
* Description  : This function get communication status
* Arguments    : none
* Return Value : result status
                0x00 : success(IIC_SUCCESS)
                0x01 : transmit operating(IIC_USING)
                0x82 : BUS busy
                0x84 : no ACK from slave for data(NO_ACK)
                0x8C : no ACK for slave address(NO_SLAVE)
********************************************************************************/
uint8_t R_IICA0_check_comstate(void)
{
    return( g_iica0_status );
}

/*******************************************************************************
* Function Name: R_IICA0_wait_comend
* Description  : This function wait for communication end
* Arguments    : none
* Return Value : result status
                0x00 : success
                other : error and issue STOP conditiopn
********************************************************************************/
uint8_t R_IICA0_wait_comend(void)
{
    uint8_t status;

/*--------------------------------------------------------------*/
/*      wait for communication end by checking g_iica0_status   */
/*--------------------------------------------------------------*/

    while( IIC_USING == ( g_iica0_status & STS_MASK ) )
    {
        HALT();                         /* wait for communication end   */
    }

    status = g_iica0_status;            /* set result status            */

    if ( IIC_SUCCESS != status )
    {

/*--------------------------------------------------------------*/
/*      communication error then issue STOP conditiopn          */
/*--------------------------------------------------------------*/

        R_IICA0_StopCondition();          /* issue STOP conditiopn        */
        delay_us(60);                   /* wait for 60us                */
    }

    return( status );
}

/*******************************************************************************
* Function Name: R_IICA0_bus_check
* Description  : This function check I2C bus and issue start condition
* Arguments    : none
* Return Value : status -
*                 IIC_SUCCESS: successfuly issue start condition and get I2C bus
*                 BUS_BUSY: I2C bus is busy
********************************************************************************/
uint8_t R_IICA0_bus_check(void)
{
    uint8_t status;
    uint16_t wait;

/*--------------------------------------------------------------*/
/*      Check I2C bus is used or in waiting state               */
/*--------------------------------------------------------------*/

    status = BUS_BUSY;                  /* set dummy error flag          */

    if ( ( FALSE == IICBSY0 ) || ( TRUTH == MSTS0 ))    /* Check I2C bus */
    {

/*--------------------------------------------------------------*/
/*      I2C bus is usable, then issue start condition           */
/*--------------------------------------------------------------*/

        STT0 = TRUTH;                   /* issue IICA0 start condition   */

/*--------------------------------------------------------------*/
/*      Wait for start condition is detected                    */
/*--------------------------------------------------------------*/

        for( wait = WAITTIME ; ( wait > 0 )&&( FALSE == STD0 ) ; wait--)
        {
            NOP();
        }

        if ( ( TRUTH == MSTS0 ) && ( TRUTH == STD0 ))
        {
/*--------------------------------------------------------------*/
/*      success to get I2C bus                                  */
/*--------------------------------------------------------------*/

            status = IIC_SUCCESS;       /* set status OK                 */
            g_iica0_status = ON_COMMU;  /* set communication flag        */
        }
    }
    
    return (status);
}



/*          copy to this line(line 810)                                  */

#endif
/* End user code. Do not edit comment generated here */

