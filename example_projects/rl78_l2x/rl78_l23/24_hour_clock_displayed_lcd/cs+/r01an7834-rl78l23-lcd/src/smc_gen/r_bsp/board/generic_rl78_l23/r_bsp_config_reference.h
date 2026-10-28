/***********************************************************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only intended for use with Renesas products. No 
* other uses are authorized. This software is owned by Renesas Electronics Corporation and is protected under all 
* applicable laws, including copyright laws. 
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING
* THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, 
* FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED. TO THE MAXIMUM 
* EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES 
* SHALL BE LIABLE FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY REASON RELATED TO THIS 
* SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software and to discontinue the availability of 
* this software. By using this software, you agree to the additional terms and conditions found by accessing the 
* following link:
* http://www.renesas.com/disclaimer
*
* Copyright (C) 2025 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/
/***********************************************************************************************************************
* File Name    : r_bsp_config_reference.h
* H/W Platform : GENERIC_RL78_L23
* Description  : 
***********************************************************************************************************************/
/***********************************************************************************************************************
* History : DD.MM.YYYY Version  Description
*         : 21.02.2025 1.90     First Release
***********************************************************************************************************************/

#ifndef R_BSP_CONFIG_REF_HEADER_FILE
#define R_BSP_CONFIG_REF_HEADER_FILE
/*************************************************
 * MCU information
 *************************************************/
/*
 R 7 F 100L P L 3 xxx C FB #BA0
 | | |  |   | | |  |  |  |  |__not used                   Packaging specification
 | | |  |   | | |  |  |  |_____not used                   Package type
 | | |  |   | | |  |  |________not used                   Fields of application
 | | |  |   | | |  |___________not used                   ROM number(omitted with blank products)
 | | |  |   | | |______________not used                   Ambient operating temperature range
 | | |  |   | |________________BSP_CFG_MCU_PART_ROM_SIZE  ROM capacity
 | | |  |   |__________________BSP_CFG_MCU_PART_PIN_NUM   Pin count
 | | |  |______________________not used                   RL78/L23
 | | |_________________________BSP_CFG_MCU_PART_ROM_TYPE  Device type
 | |___________________________not used                   Renesas MCU
 |_____________________________not used                   Renesas semiconductor product
*/

/* ROM capacity
 E = 64(KB) : 0x0
 G = 128    : 0x1
 J = 256    : 0x2
 L = 512    : 0x3
*/
#define BSP_CFG_MCU_PART_ROM_SIZE (0x3)

/* Pin count
 F = 44-pin  : 0x0
 G = 48-pin  : 0x1
 J = 52-pin  : 0x2
 L = 64-pin  : 0x3
 M = 80-pin  : 0x4
 P = 100-pin : 0x5
*/
#define BSP_CFG_MCU_PART_PIN_NUM (0x5)

/* group
 100L = RL78/L23 : (true)
*/
#define BSP_CFG_MCU_PART_HAS_DATA_FLASH (true)

/* Device type
 F = Flash memory : 0
*/
#define BSP_CFG_MCU_PART_ROM_TYPE (0)

#if defined(__ICCRL78__)
/* Option byte setting(When using IAR) */
#define BSP_CFG_OPTBYTE0_VALUE (0xFFU)
#define BSP_CFG_OPTBYTE1_VALUE (0xFFU)
#define BSP_CFG_OPTBYTE2_VALUE (0xE8U)
#define BSP_CFG_OPTBYTE3_VALUE (0x04U)
/* Security ID Codes for On-Chip Debugging setting(When using IAR) */
#define BSP_CFG_SECUID0_VALUE (0xFFU)
#define BSP_CFG_SECUID1_VALUE (0xFFU)
#define BSP_CFG_SECUID2_VALUE (0xFFU)
#define BSP_CFG_SECUID3_VALUE (0xFFU)
#define BSP_CFG_SECUID4_VALUE (0xFFU)
#define BSP_CFG_SECUID5_VALUE (0xFFU)
#define BSP_CFG_SECUID6_VALUE (0xFFU)
#define BSP_CFG_SECUID7_VALUE (0xFFU)
#define BSP_CFG_SECUID8_VALUE (0xFFU)
#define BSP_CFG_SECUID9_VALUE (0xFFU)
#endif

/*************************************************
 * Pin assignment setting
 *************************************************/
/* Peripheral I/O redirection register 0(PIOR0-PIOR01/PIOR00)
   44/48/52-pin
 00 : -
 01 : TI00 - P20
      TO00 - P21
 10 : TI00 - P40
      TO00 - P40
 11 : TI00 - P90
      TO00 - P90

   64/100-pin
 00 : TI00 - P52
      TO00 - P52
 01 : TI00 - P20
      TO00 - P21
 10 : TI00 - P40
      TO00 - P40
 11 : TI00 - P90
      TO00 - P90
*/
#define BSP_CFG_PIOR01 (0)
#define BSP_CFG_PIOR00 (0)

/* Peripheral I/O redirection register 0(PIOR0-PIOR04/PIOR03/PIOR02)
   44/48/52-pin
 000 : -
 001 : -
 010 : -
 011 : -
 100 : TI01/TO01 - P60
 101 : TI01/TO01 - P92
 110 : -
 111 : -

   64-pin
 000 : -
 001 : TI01/TO01 - P31
 010 : -
 011 : -
 100 : TI01/TO01 - P60
 101 : TI01/TO01 - P92
 110 : -
 111 : -

   80-pin
 000 : -
 001 : TI01/TO01 - P31
 010 : -
 011 : TI01/TO01 - P34
 100 : TI01/TO01 - P60
 101 : TI01/TO01 - P92
 110 : -
 111 : -

   100-pin
 000 : TI01/TO01 - P32
 001 : TI01/TO01 - P31
 010 : TI01/TO01 - P33
 011 : TI01/TO01 - P34
 100 : TI01/TO01 - P60
 101 : TI01/TO01 - P92
 110 : TI01/TO01 - P67
 111 : -
*/
#define BSP_CFG_PIOR04 (0)
#define BSP_CFG_PIOR03 (0)
#define BSP_CFG_PIOR02 (0)

/* Peripheral I/O redirection register 0(PIOR0-PIOR06/PIOR05)
   44-pin
 00 : -
 01 : -
 10 : TI02/TO02 - P61
 11 : TI02/TO02 - P95

   48/52/64-pin
 00 : TI02/TO02 - P54
 01 : -
 10 : TI02/TO02 - P61
 11 : TI02/TO02 - P95

   80/100-pin
 00 : TI02/TO02 - P54
 01 : TI02/TO02 - P55
 10 : TI02/TO02 - P61
 11 : TI02/TO02 - P95
*/
#define BSP_CFG_PIOR06 (0)
#define BSP_CFG_PIOR05 (0)

/* Peripheral I/O redirection register 1(PIOR1-PIOR12/PIOR11/PIOR10)
   44-pin
 000 : -
 001 : -
 010 : TI03/TO03/REMOOUT - P57
 011 : -
 100 : -
 101 : -
 110 : TI03/TO03/REMOOUT - P127
 111 : -

   48/52-pin
 000 : -
 001 : -
 010 : TI03/TO03/REMOOUT - P57
 011 : -
 100 : -
 101 : TI03/TO03/REMOOUT - P75
 110 : TI03/TO03/REMOOUT - P127
 111 : -

   64/80-pin
 000 : TI03/TO03/REMOOUT - P30
 001 : -
 010 : TI03/TO03/REMOOUT - P57
 011 : TI03/TO03/REMOOUT - P62
 100 : -
 101 : TI03/TO03/REMOOUT - P75
 110 : TI03/TO03/REMOOUT - P127
 111 : -

   100-pin
 000 : TI03/TO03/REMOOUT - P30
 001 : TI03/TO03/REMOOUT - P32
 010 : TI03/TO03/REMOOUT - P57
 011 : TI03/TO03/REMOOUT - P62
 100 : TI03/TO03/REMOOUT - P64
 101 : TI03/TO03/REMOOUT - P75
 110 : TI03/TO03/REMOOUT - P127
 111 : -
*/
#define BSP_CFG_PIOR12 (0)
#define BSP_CFG_PIOR11 (0)
#define BSP_CFG_PIOR10 (0)

/* Peripheral I/O redirection register 1(PIOR1-PIOR14/PIOR13)
   44/48-pin
 00 : -
 01 : TI04/TO04 - P44
 10 : -
 11 : TI04/TO04 - P126

   52-pin
 00 : TI04/TO04 - P14
 01 : TI04/TO04 - P44
 10 : -
 11 : TI04/TO04 - P126

   64/80/100-pin
 00 : TI04/TO04 - P14
 01 : TI04/TO04 - P44
 10 : TI04/TO04 - P63
 11 : TI04/TO04 - P126
*/
#define BSP_CFG_PIOR14 (0)
#define BSP_CFG_PIOR13 (0)

/* Peripheral I/O redirection register 1(PIOR1-PIOR17/PIOR16/PIOR15)
   44/48-pin
 000 : -
 001 : -
 010 : -
 011 : -
 100 : TI05/TO05 - P97
 101 : -
 110 : -
 111 : -

   52-pin
 000 : -
 001 : -
 010 : TI05/TO05 - P43
 011 : -
 100 : TI05/TO05 - P97
 101 : -
 110 : -
 111 : -

   64/80-pin
 000 : TI05/TO05 - P42
 001 : TI05/TO05 - P01
 010 : TI05/TO05 - P43
 011 : -
 100 : TI05/TO05 - P97
 101 : -
 110 : -
 111 : -

   100-pin
 000 : TI05/TO05 - P42
 001 : TI05/TO05 - P01
 010 : TI05/TO05 - P43
 011 : TI05/TO05 - P66
 100 : TI05/TO05 - P97
 101 : TI05/TO05 - P65
 110 : -
 111 : -
*/
#define BSP_CFG_PIOR17 (0)
#define BSP_CFG_PIOR16 (0)
#define BSP_CFG_PIOR15 (0)

/* Peripheral I/O redirection register 2(PIOR2-PIOR21/PIOR20)
   44/48/52/64-pin
 00 : -
 01 : TI06/TO06 - P86
 10 : TI06/TO06 - P125
 11 : TI06/TO06 - P94

   80/100-pin
 00 : TI06/TO06 - P56
 01 : TI06/TO06 - P86
 10 : TI06/TO06 - P125
 11 : TI06/TO06 - P94
*/
#define BSP_CFG_PIOR21 (0)
#define BSP_CFG_PIOR20 (0)

/* Peripheral I/O redirection register 2(PIOR2-PIOR23/PIOR22)
   44/48-pin
 00 : -
 01 : -
 10 : -
 11 : TI07/TO07 - P77

   52-pin
 00 : -
 01 : -
 10 : TI07/TO07 - P53
 11 : TI07/TO07 - P77

   64-pin
 00 : TI07/TO07 - P15
 01 : -
 10 : TI07/TO07 - P53
 11 : TI07/TO07 - P77

   80/100-pin
 00 : TI07/TO07 - P15
 01 : TI07/TO07 - P41
 10 : TI07/TO07 - P53
 11 : TI07/TO07 - P77
*/
#define BSP_CFG_PIOR23 (0)
#define BSP_CFG_PIOR22 (0)

/* Peripheral I/O redirection register 3(PIOR3-PIOR32/PIOR31/PIOR30)
   44-pin
 000 : TKBO01 - P77
       TKBO00 - P76
 001 : TKBO01 - -
       TKBO00 - P76
 010 : TKBO01 - -
       TKBO00 - P76
 011 : TKBO01 - P17
       TKBO00 - P12
 100 : TKBO01 - P16
       TKBO00 - P12
 101 : TKBO01 - P00
       TKBO00 - P12
 110 : -
 111 : -

   48-pin
 000 : TKBO01 - P77
       TKBO00 - P76
 001 : TKBO01 - P75
       TKBO00 - P76
 010 : TKBO01 - -
       TKBO00 - P76
 011 : TKBO01 - P17
       TKBO00 - P12
 100 : TKBO01 - P16
       TKBO00 - P12
 101 : TKBO01 - P00
       TKBO00 - P12
 110 : -
 111 : -

   52/64/80/100-pin
 000 : TKBO01 - P77
       TKBO00 - P76
 001 : TKBO01 - P75
       TKBO00 - P76
 010 : TKBO01 - P74
       TKBO00 - P76
 011 : TKBO01 - P17
       TKBO00 - P12
 100 : TKBO01 - P16
       TKBO00 - P12
 101 : TKBO01 - P00
       TKBO00 - P12
 110 : -
 111 : -
*/
#define BSP_CFG_PIOR32 (0)
#define BSP_CFG_PIOR31 (0)
#define BSP_CFG_PIOR30 (0)

/* Peripheral I/O redirection register 3(PIOR3-PIOR34/PIOR33)
 (flash memory 64 or 128 KB)
   80/100-pin
 00 : TKBO11 - P74
      TKBO10 - P73
 01 : TKBO11 - P75
      TKBO10 - P73
 10 : TKBO11 - P11
      TKBO10 - P10
 11 : TKBO11 - P01
      TKBO10 - P10

 (flash memory 256 or 512 KB)
   44-pin
 00 : -
 01 : -
 10 : TKBO11 - P11
      TKBO10 - P10
 11 : TKBO11 - -
      TKBO10 - P10

   48-pin
 00 : -
 01 : TKBO11 - P75
      TKBO10 - -
 10 : TKBO11 - P11
      TKBO10 - P10
 11 : TKBO11 - -
      TKBO10 - P10

   52-pin
 00 : TKBO11 - P74
      TKBO10 - -
 01 : TKBO11 - P75
      TKBO10 - -
 10 : TKBO11 - P11
      TKBO10 - P10
 11 : TKBO11 - -
      TKBO10 - P10

   64-pin
 00 : TKBO11 - P74
      TKBO10 - -
 01 : TKBO11 - P75
      TKBO10 - -
 10 : TKBO11 - P11
      TKBO10 - P10
 11 : TKBO11 - P01
      TKBO10 - P10

   80/100-pin
 00 : TKBO11 - P74
      TKBO10 - P73
 01 : TKBO11 - P75
      TKBO10 - P73
 10 : TKBO11 - P11
      TKBO10 - P10
 11 : TKBO11 - P01
      TKBO10 - P10
*/
#define BSP_CFG_PIOR34 (0)
#define BSP_CFG_PIOR33 (0)

/* Peripheral I/O redirection register 3(PIOR3-PIOR36/PIOR35)
 (flash memory 64 or 128 KB)
   80/100-pin
 00 : TKBO21 - P72
      TKBO20 - P70
 01 : TKBO21 - P77
      TKBO20 - P70
 10 : TKBO21 - P02
      TKBO20 - P26
 11 : TKBO21 - P27
      TKBO20 - P26

 (flash memory 256 or 512 KB)
   44/48/52-pin
 00 : -
 01 : TKBO21 - P77
      TKBO20 - -
 10 : TKBO21 - -
      TKBO20 - P26
 11 : TKBO21 - P27
      TKBO20 - P26

   64-pin
 00 : TKBO21 - -
      TKBO20 - P70
 01 : TKBO21 - P77
      TKBO20 - P70
 10 : TKBO21 - P02
      TKBO20 - P26
 11 : TKBO21 - P27
      TKBO20 - P26

   80/100-pin
 00 : TKBO21 - P72
      TKBO20 - P70
 01 : TKBO21 - P77
      TKBO20 - P70
 10 : TKBO21 - P02
      TKBO20 - P26
 11 : TKBO21 - P27
      TKBO20 - P26
*/
#define BSP_CFG_PIOR36 (0)
#define BSP_CFG_PIOR35 (0)

/* Peripheral I/O redirection register 4(PIOR4-PIOR40)
   44/48/52-pin
 0 : -
 1 : TRJO0 - P00
     TRJIO0 - P17

   64/80/100-pin
 0 : TRJO0 - P42
     TRJIO0 - P03
 1 : TRJO0 - P00
     TRJIO0 - P17
 */
#define BSP_CFG_PIOR40 (0)

/* Peripheral I/O redirection register 4(PIOR4-PIOR41)
 (flash memory 64 or 128 KB)
   80/100-pin
 0 : TRJO1  - P130
     TRJIO1 - P23
 1 : TRJO1  - P12
     TRJIO1 - P11

 (flash memory 256 or 512 KB)
   44/48/52/64-pin
 0 : -
 1 : TRJO1  - P12
     TRJIO1 - P11

   80/100-pin
 0 : TRJO1  - P130
     TRJIO1 - P23
 1 : TRJO1  - P12
     TRJIO1 - P11
*/
#define BSP_CFG_PIOR41 (0)

/* Peripheral I/O redirection register 4(PIOR4-PIOR46)
   44/48/52/64/80/100-pin
 0 : EXSDO1 - P44
     EXSDO0 - P45
 1 : EXSDO1 - P76
     EXSDO0 - P77
 */
#define BSP_CFG_PIOR46 (0)

/* Peripheral I/O redirection register 4(PIOR4-PIOR47)
   44/48/52/64/80/100-pin
 0 : EXSDI1 - P17
     EXSDI0 - P00
 1 : EXSDI1 - P27
     EXSDI0 - P26
 */
#define BSP_CFG_PIOR47 (0)

/* Peripheral I/O redirection register 5(PIOR5-PIOR52/PIOR51/PIOR50)
   44-pin
 000 : PCLBUZ1 - -
       PCLBUZ0 - P02
 001 : PCLBUZ1 - P12
       PCLBUZ0 - -
 010 : PCLBUZ1 - P20
       PCLBUZ0 - P07
 011 : PCLBUZ1 - -
       PCLBUZ0 - P21
 100 : PCLBUZ1 - P86
       PCLBUZ0 - -
 101 : PCLBUZ1 - P125
       PCLBUZ0 - -
 110 : -
 111 : PCLBUZ1 - P06
       PCLBUZ0 - P96

   48-pin
 000 : PCLBUZ1 - -
       PCLBUZ0 - P02
 001 : PCLBUZ1 - P12
       PCLBUZ0 - -
 010 : PCLBUZ1 - P20
       PCLBUZ0 - P07
 011 : PCLBUZ1 - -
       PCLBUZ0 - P21
 100 : PCLBUZ1 - P86
       PCLBUZ0 - -
 101 : PCLBUZ1 - P125
       PCLBUZ0 - P54
 110 : -
 111 : PCLBUZ1 - P06
       PCLBUZ0 - P96

   52-pin
 000 : PCLBUZ1 - -
       PCLBUZ0 - P02
 001 : PCLBUZ1 - P12
       PCLBUZ0 - -
 010 : PCLBUZ1 - P20
       PCLBUZ0 - P07
 011 : PCLBUZ1 - -
       PCLBUZ0 - P21
 100 : PCLBUZ1 - P86
       PCLBUZ0 - P53
 101 : PCLBUZ1 - P125
       PCLBUZ0 - P54
 110 : -
 111 : PCLBUZ1 - P06
       PCLBUZ0 - P96

   64/80-pin
 000 : PCLBUZ1 - P01
       PCLBUZ0 - P02
 001 : PCLBUZ1 - P12
       PCLBUZ0 - P04
 010 : PCLBUZ1 - P20
       PCLBUZ0 - P07
 011 : PCLBUZ1 - P42
       PCLBUZ0 - P21
 100 : PCLBUZ1 - P86
       PCLBUZ0 - P53
 101 : PCLBUZ1 - P125
       PCLBUZ0 - P54
 110 : PCLBUZ1 - P52
       PCLBUZ0 - -
 111 : PCLBUZ1 - P06
       PCLBUZ0 - P96

   100-pin
 000 : PCLBUZ1 - P01
       PCLBUZ0 - P02
 001 : PCLBUZ1 - P12
       PCLBUZ0 - P04
 010 : PCLBUZ1 - P20
       PCLBUZ0 - P07
 011 : PCLBUZ1 - P42
       PCLBUZ0 - P21
 100 : PCLBUZ1 - P86
       PCLBUZ0 - P53
 101 : PCLBUZ1 - P125
       PCLBUZ0 - P54
 110 : PCLBUZ1 - P52
       PCLBUZ0 - P82
 111 : PCLBUZ1 - P06
       PCLBUZ0 - P96
*/
#define BSP_CFG_PIOR52 (0)
#define BSP_CFG_PIOR51 (0)
#define BSP_CFG_PIOR50 (0)

/* Peripheral I/O redirection register 5(PIOR5-PIOR54/PIOR53)
   44/48/52-pin
 00 : -
 01 : VCOUT1 - P12
      VCOUT0 - P16
 10 : -
 11 : VCOUT1 - P125
      VCOUT0 - P85

   64-pin
 00 : VCOUT1 - P04
      VCOUT0 - P03
 01 : VCOUT1 - P12
      VCOUT0 - P16
 10 : -
 11 : VCOUT1 - P125
      VCOUT0 - P85

   80-pin
 00 : VCOUT1 - P04
      VCOUT0 - P03
 01 : VCOUT1 - P12
      VCOUT0 - P16
 10 : VCOUT1 - -
      VCOUT0 - P35
 11 : VCOUT1 - P125
      VCOUT0 - P85

   100-pin
 00 : VCOUT1 - P04
      VCOUT0 - P03
 01 : VCOUT1 - P12
      VCOUT0 - P16
 10 : VCOUT1 - P146
      VCOUT0 - P35
 11 : VCOUT1 - P125
      VCOUT0 - P85
*/
#define BSP_CFG_PIOR54 (0)
#define BSP_CFG_PIOR53 (0)

/* Peripheral I/O redirection register 5(PIOR5-PIOR57/PIOR56/PIOR55)
   44/48/52-pin
 000 : -
 001 : -
 010 : -
 011 : -
 100 : RTC1HZ - P16
 101 : RTC1HZ - P76
 110 : -
 111 : -

   64/80-pin
 000 : RTC1HZ - P31
 001 : RTC1HZ - R30
 010 : -
 011 : -
 100 : RTC1HZ - P16
 101 : RTC1HZ - P76
 110 : -
 111 : -

   100-pin
 000 : RTC1HZ - P31
 001 : RTC1HZ - R30
 010 : RTC1HZ - P32
 011 : RTC1HZ - P33
 100 : RTC1HZ - P16
 101 : RTC1HZ - P76
 110 : -
 111 : -
*/
#define BSP_CFG_PIOR57 (0)
#define BSP_CFG_PIOR56 (0)
#define BSP_CFG_PIOR55 (0)

/* Peripheral I/O redirection register 6(PIOR6-PIOR62/PIOR61/PIOR60)
   44-pin
 000 : INTP0 - P137
 001 : INTP0 - P10
 010 : -
 011 : -
 100 : -
 101 : -
 110 : -
 111 : -

   48/52/64-pin
 000 : INTP0 - P137
 001 : INTP0 - P10
 010 : -
 011 : INTP0 - P54
 100 : -
 101 : -
 110 : INTP0 - P75
 111 : -

   80-pin
 000 : INTP0 - P137
 001 : INTP0 - P10
 010 : INTP0 - P34
 011 : INTP0 - P54
 100 : -
 101 : -
 110 : INTP0 - P75
 111 : -

   100-pin
 000 : INTP0 - P137
 001 : INTP0 - P10
 010 : INTP0 - P34
 011 : INTP0 - P54
 100 : INTP0 - P65
 101 : INTP0 - P84
 110 : INTP0 - P75
 111 : -
*/
#define BSP_CFG_PIOR62 (0)
#define BSP_CFG_PIOR61 (0)
#define BSP_CFG_PIOR60 (0)

/* Peripheral I/O redirection register 6(PIOR6-PIOR65/PIOR64/PIOR63)
   44/48/52-pin
 000 : -
 001 : -
 010 : INTP1 - P77
 011 : -
 100 : INTP1 - P90
 101 : INTP1 - P95
 110 : -
 111 : INTP1 - P11

   64-pin
 000 : INTP1 - P52
 001 : -
 010 : INTP1 - P77
 011 : -
 100 : INTP1 - P90
 101 : INTP1 - P95
 110 : -
 111 : INTP1 - P11

   80-pin
 000 : INTP1 - P52
 001 : -
 010 : INTP1 - P77
 011 : -
 100 : INTP1 - P90
 101 : INTP1 - P95
 110 : INTP1 - P47
 111 : INTP1 - P11

   100-pin
 000 : INTP1 - P52
 001 : INTP1 - P66
 010 : INTP1 - P77
 011 : INTP1 - P83
 100 : INTP1 - P90
 101 : INTP1 - P95
 110 : INTP1 - P47
 111 : INTP1 - P11
*/
#define BSP_CFG_PIOR65 (0)
#define BSP_CFG_PIOR64 (0)
#define BSP_CFG_PIOR63 (0)

/* Peripheral I/O redirection register 7(PIOR7-PIOR72/PIOR71/PIOR70)
   44/48-pin
 000 : -
 001 : -
 010 : INTP2 - P76
 011 : INTP2 - P91
 100 : INTP3 - P94
 101 : -
 110 : -
 111 : -

   52/64/80-pin
 000 : INTP2 - P53
 001 : -
 010 : INTP2 - P76
 011 : INTP2 - P91
 100 : INTP3 - P94
 101 : -
 110 : -
 111 : -

   100-pin
 000 : INTP2 - P53
 001 : INTP2 - P67
 010 : INTP2 - P76
 011 : INTP2 - P91
 100 : INTP3 - P94
 101 : INTP2 - P147
 110 : INTP2 - P80
 111 : -
*/
#define BSP_CFG_PIOR72 (0)
#define BSP_CFG_PIOR71 (0)
#define BSP_CFG_PIOR70 (0)

/* Peripheral I/O redirection register 7(PIOR7-PIOR75/PIOR74/PIOR73)
   44/48/52-pin
 000 : -
 001 : -
 010 : -
 011 : INTP3 - P60
 100 : INTP3 - P86
 101 : -
 110 : INTP3 - P93
 111 : -

   64/80-pin
 000 : INTP3 - P31
 001 : INTP3 - P30
 010 : -
 011 : INTP3 - P60
 100 : INTP3 - P86
 101 : -
 110 : INTP3 - P93
 111 : -

   100-pin
 000 : INTP3 - P31
 001 : INTP3 - P30
 010 : INTP3 - P32
 011 : INTP3 - P60
 100 : INTP3 - P86
 101 : INTP3 - P145
 110 : INTP3 - P93
 111 : -
*/
#define BSP_CFG_PIOR75 (0)
#define BSP_CFG_PIOR74 (0)
#define BSP_CFG_PIOR73 (0)

/* Peripheral I/O redirection register 8(PIOR8-PIOR82/PIOR81/PIOR80)
   44/48-pin
 000 : -
 001 : INTP4 - P27
 010 : -
 011 : INTP4 - P61
 100 : INTP4 - P85
 101 : -
 110 : INTP4 - P126
 111 : -

   52/64-pin
 000 : -
 001 : INTP4 - P27
 010 : -
 011 : INTP4 - P61
 100 : INTP4 - P85
 101 : -
 110 : INTP4 - P126
 111 : INTP4 - P43

   80-pin
 000 : -
 001 : INTP4 - P27
 010 : INTP4 - P35
 011 : INTP4 - P61
 100 : INTP4 - P85
 101 : -
 110 : INTP4 - P126
 111 : INTP4 - P43

   100-pin
 000 : INTP4 - P33
 001 : INTP4 - P27
 010 : INTP4 - P35
 011 : INTP4 - P61
 100 : INTP4 - P85
 101 : INTP4 - P144
 110 : INTP4 - P126
 111 : INTP4 - P43
*/
#define BSP_CFG_PIOR82 (0)
#define BSP_CFG_PIOR81 (0)
#define BSP_CFG_PIOR80 (0)

/* Peripheral I/O redirection register 8(PIOR8-PIOR85/PIOR84/PIOR83)
   44/48/52-pin
 000 : -
 001 : -
 010 : INTP5 - P26
 011 : -
 100 : -
 101 : INTP5 - P96
 110 : -
 111 : -

   64-pin
 000 : -
 001 : INTP5 - P01
 010 : INTP5 - P26
 011 : INTP5 - P62
 100 : -
 101 : INTP5 - P96
 110 : -
 111 : -

   80-pin
 000 : INTP5 - P55
 001 : INTP5 - P01
 010 : INTP5 - P26
 011 : INTP5 - P62
 100 : -
 101 : INTP5 - P96
 110 : -
 111 : -

   100-pin
 000 : INTP5 - P55
 001 : INTP5 - P01
 010 : INTP5 - P26
 011 : INTP5 - P62
 100 : INTP5 - P64
 101 : INTP5 - P96
 110 : INTP5 - P143
 111 : -
*/
#define BSP_CFG_PIOR85 (0)
#define BSP_CFG_PIOR84 (0)
#define BSP_CFG_PIOR83 (0)

/* Peripheral I/O redirection register 9(PIOR9-PIOR92/PIOR91/PIOR90)
   44/48/52-pin
 000 : INTP6 - P57
 001 : -
 010 : INTP6 - P21
 011 : -
 100 : -
 101 : -
 110 : -
 111 : -

   64-pin
 000 : INTP6 - P57
 001 : INTP6 - P04
 010 : INTP6 - P21
 011 : -
 100 : INTP6 - P63
 101 : -
 110 : -
 111 : -

   80-pin
 000 : INTP6 - P57
 001 : INTP6 - P04
 010 : INTP6 - P21
 011 : INTP6 - P41
 100 : INTP6 - P63
 101 : -
 110 : INTP6 - P51
 111 : -

   100-pin
 000 : INTP6 - P57
 001 : INTP6 - P04
 010 : INTP6 - P21
 011 : INTP6 - P41
 100 : INTP6 - P63
 101 : INTP6 - P141
 110 : INTP6 - P51
 111 : -
*/
#define BSP_CFG_PIOR92 (0)
#define BSP_CFG_PIOR91 (0)
#define BSP_CFG_PIOR90 (0)

/* Peripheral I/O redirection register 9(PIOR9-PIOR95/PIOR94/PIOR93)
   44/48/52-pin
 000 : -
 001 : INTP7 - P20
 010 : INTP7 - P22
 011 : -
 100 : INTP7 - P44
 101 : INTP7 - P125
 110 : -
 111 : -

   64/80-pin
 000 : INTP7 - P02
 001 : INTP7 - P20
 010 : INTP7 - P22
 011 : INTP7 - P42
 100 : INTP7 - P44
 101 : INTP7 - P125
 110 : -
 111 : -

   100-pin
 000 : INTP7 - P02
 001 : INTP7 - P20
 010 : INTP7 - P22
 011 : INTP7 - P42
 100 : INTP7 - P44
 101 : INTP7 - P125
 110 : INTP7 - P142
 111 : INTP7 - P146
*/
#define BSP_CFG_PIOR95 (0)
#define BSP_CFG_PIOR94 (0)
#define BSP_CFG_PIOR93 (0)

/* Peripheral I/O redirection register 10(PIOR10-PIOR101/PIOR100)
   44/48/52-pin
 00 : SCK00 - P16
      SCL00 - P16
      SI00  - P17
      RxD0  - P17
      SDA00 - P17
      SO00  - P00
      TxD0  - P00
 01 : SCK00 - P22
      SCL00 - P22
      SI00  - P26
      RxD0  - P26
      SDA00 - P26
      SO00  - P27
      TxD0  - P27
 10 : -
 11 : -

   64-pin
 00 : SCK00 - P16
      SCL00 - P16
      SI00  - P17
      RxD0  - P17
      SDA00 - P17
      SO00  - P00
      TxD0  - P00
 01 : SCK00 - P22
      SCL00 - P22
      SI00  - P26
      RxD0  - P26
      SDA00 - P26
      SO00  - P27
      TxD0  - P27
 10 : SCK00 - -
      SCL00 - P40
      SI00  - -
      RxD0  - -
      SDA00 - P42
      SO00  - -
      TxD0  - -
 11 : -

   80/100-pin
 00 : SCK00 - P16
      SCL00 - P16
      SI00  - P17
      RxD0  - P17
      SDA00 - P17
      SO00  - P00
      TxD0  - P00
 01 : SCK00 - P22
      SCL00 - P22
      SI00  - P26
      RxD0  - P26
      SDA00 - P26
      SO00  - P27
      TxD0  - P27
 10 : SCK00 - P40
      SCL00 - P40
      SI00  - P42
      RxD0  - P42
      SDA00 - P42
      SO00  - P41
      TxD0  - P41
 11 : -
*/
#define BSP_CFG_PIOR101 (0)
#define BSP_CFG_PIOR100 (0)

/* Peripheral I/O redirection register 10(PIOR10-PIOR103/PIOR102)
   44/48-pin
 00 : -
 01 : -
 10 : SCK01 - P93
      SCL01 - P93
      SI01  - P94
      SDA01 - P94
      SO01  - P95
 11 : SCK01 - P97
      SCL01 - P97
      SI01  - P96
      SDA01 - P96
      SO01  - P95

   52-pin
 00 : SCK01 - -
      SCL01 - P54
      SI01  - -
      SDA01 - P53
      SO01  - -
 01 : -
 10 : SCK01 - P93
      SCL01 - P93
      SI01  - P94
      SDA01 - P94
      SO01  - P95
 11 : SCK01 - P97
      SCL01 - P97
      SI01  - P96
      SDA01 - P96
      SO01  - P95

   64-pin
 00 : SCK01 - P54
      SCL01 - P54
      SI01  - P53
      SDA01 - P53
      SO01  - P52
 01 : -
 10 : SCK01 - P93
      SCL01 - P93
      SI01  - P94
      SDA01 - P94
      SO01  - P95
 11 : SCK01 - P97
      SCL01 - P97
      SI01  - P96
      SDA01 - P96
      SO01  - P95

   80/100-pin
 00 : SCK01 - P54
      SCL01 - P54
      SI01  - P53
      SDA01 - P53
      SO01  - P52
 01 : SCK01 - P46
      SCL01 - P46
      SI01  - P47
      SDA01 - P47
      SO01  - P130
 10 : SCK01 - P93
      SCL01 - P93
      SI01  - P94
      SDA01 - P94
      SO01  - P95
 11 : SCK01 - P97
      SCL01 - P97
      SI01  - P96
      SDA01 - P96
      SO01  - P95
*/
#define BSP_CFG_PIOR103 (0)
#define BSP_CFG_PIOR102 (0)

/* Peripheral I/O redirection register 10(PIOR10-PIOR105/PIOR104)
   44/48/52/64-pin
 00 : SCK10 - P05
      SCL10 - P05
      SI10  - P06
      RxD1  - P06
      SDA10 - P06
      SO10  - P07
      TxD1  - P07
 01 : -
 10 : -
 11 : SCK10 - P85
      SCL10 - P85
      SI10  - P86
      RxD1  - P86
      SDA10 - P86
      SO10  - P87
      TxD1  - P87

   80-pin
 00 : SCK10 - P05
      SCL10 - P05
      SI10  - P06
      RxD1  - P06
      SDA10 - P06
      SO10  - P07
      TxD1  - P07
 01 : SCK10 - -
      SCL10 - -
      SI10  - -
      RxD1  - P41
      SDA10 - -
      SO10  - -
      TxD1  - P42
 10 : -
 11 : SCK10 - P85
      SCL10 - P85
      SI10  - P86
      RxD1  - P86
      SDA10 - P86
      SO10  - P87
      TxD1  - P87

   100-pin
 00 : SCK10 - P05
      SCL10 - P05
      SI10  - P06
      RxD1  - P06
      SDA10 - P06
      SO10  - P07
      TxD1  - P07
 01 : SCK10 - P66
      SCL10 - P66
      SI10  - P41
      RxD1  - P41
      SDA10 - P41
      SO10  - P42
      TxD1  - P42
 10 : SCK10 - P82
      SCL10 - P82
      SI10  - P81
      RxD1  - P81
      SDA10 - P81
      SO10  - P07
      TxD1  - P07
 11 : SCK10 - P85
      SCL10 - P85
      SI10  - P86
      RxD1  - P86
      SDA10 - P86
      SO10  - P87
      TxD1  - P87
*/
#define BSP_CFG_PIOR105 (0)
#define BSP_CFG_PIOR104 (0)

/* Peripheral I/O redirection register 10(PIOR10-PIOR107/PIOR106)
   44/48-pin
 00 : SCK11 - P10
      SCL11 - P10
      SI11  - P11
      SDA11 - P11
      SO11  - P12
 01 : -
 10 : -
 11 : -

   52-pin
 00 : SCK11 - P10
      SCL11 - P10
      SI11  - P11
      SDA11 - P11
      SO11  - P12
 01 : SCK11 - -
      SCL11 - P44
      SI11  - -
      SDA11 - P43
      SO11  - -
 10 : -
 11 : -

   64/80/100-pin
 00 : SCK11 - P10
      SCL11 - P10
      SI11  - P11
      SDA11 - P11
      SO11  - P12
 01 : SCK11 - P44
      SCL11 - P44
      SI11  - P43
      SDA11 - P43
      SO11  - P42
 10 : -
 11 : -
*/
#define BSP_CFG_PIOR107 (0)
#define BSP_CFG_PIOR106 (0)

/* Peripheral I/O redirection register 11(PIOR11-PIOR111/PIOR110)
   44-pin
 00 : SCK20 - -
      SCL20 - -
      SI20  - -
      RxD2  - P76
      SDA20 - -
      SO20  - -
      TxD2  - P77
 01 : -
 10 : -
 11 : -

   48/52-pin
 00 : SCK20 - P75
      SCL20 - P75
      SI20  - P76
      RxD2  - P76
      SDA20 - P76
      SO20  - P77
      TxD2  - P77
 01 : -
 10 : -
 11 : -

   64/80-pin
 00 : SCK20 - P75
      SCL20 - P75
      SI20  - P76
      RxD2  - P76
      SDA20 - P76
      SO20  - P77
      TxD2  - P77
 01 : -
 10 : SCK20 - P02
      SCL20 - P02
      SI20  - P03
      RxD2  - P03
      SDA20 - P03
      SO20  - P04
      TxD2  - P04
 11 : -

   100-pin
 00 : SCK20 - P75
      SCL20 - P75
      SI20  - P76
      RxD2  - P76
      SDA20 - P76
      SO20  - P77
      TxD2  - P77
 01 : SCK20 - P80
      SCL20 - P80
      SI20  - P147
      RxD2  - P147
      SDA20 - P147
      SO20  - P146
      TxD2  - P146
 10 : SCK20 - P02
      SCL20 - P02
      SI20  - P03
      RxD2  - P03
      SDA20 - P03
      SO20  - P04
      TxD2  - P04
 11 : -
*/
#define BSP_CFG_PIOR110 (0)
#define BSP_CFG_PIOR111 (0)

/* Peripheral I/O redirection register 11(PIOR11-PIOR113/PIOR112)
   44/48/52/64-pin
 00 : SCK21 - P22
      SCL21 - P22
      SI21  - P26
      SDA21 - P26
      SO21  - P27
 01 : -
 10 : -
 11 : -

   80/100-pin
 00 : SCK21 - P22
      SCL21 - P22
      SI21  - P26
      SDA21 - P26
      SO21  - P27
 01 : SCK21 - P46
      SCL21 - P46
      SI21  - P47
      SDA21 - P47
      SO21  - P130
 10 : -
 11 : -
*/
#define BSP_CFG_PIOR113 (0)
#define BSP_CFG_PIOR112 (0)

/* Peripheral I/O redirection register 11(PIOR11-PIOR115/PIOR114)
   44-pin
 00 : -
 01 : SCK30 - -
      SCL30 - P85
      SI30  - -
      RxD3  - -
      SDA30 - P125
      SO30  - -
      TxD3  - -
 10 : -
 11 : -

   48-pin
 00 : SCK30 - -
      SCL30 - P45
      SI30  - -
      RxD3  - -
      SDA30 - P44
      SO30  - -
      TxD3  - -
 01 : SCK30 - -
      SCL30 - P85
      SI30  - -
      RxD3  - -
      SDA30 - P125
      SO30  - -
      TxD3  - -
 10 : -
 11 : -

   52/64-pin
 00 : SCK30 - P45
      SCL30 - P45
      SI30  - P44
      RxD3  - P44
      SDA30 - P44
      SO30  - P43
      TxD3  - P43
 01 : SCK30 - -
      SCL30 - P85
      SI30  - -
      RxD3  - -
      SDA30 - P125
      SO30  - -
      TxD3  - -
 10 : -
 11 : -

   80-pin
 00 : SCK30 - P45
      SCL30 - P45
      SI30  - P44
      RxD3  - P44
      SDA30 - P44
      SO30  - P43
      TxD3  - P43
 01 : SCK30 - P85
      SCL30 - P85
      SI30  - P125
      RxD3  - P125
      SDA30 - P125
      SO30  - P35
      TxD3  - P35
10 : SCK30  - -
      SCL30 - -
      SI30  - -
      RxD3  - P34
      SDA30 - -
      SO30  - -
      TxD3  - P35
 11 : -

   100-pin
 00 : SCK30 - P45
      SCL30 - P45
      SI30  - P44
      RxD3  - P44
      SDA30 - P44
      SO30  - P43
      TxD3  - P43
 01 : SCK30 - P85
      SCL30 - P85
      SI30  - P125
      RxD3  - P125
      SDA30 - P125
      SO30  - P35
      TxD3  - P35
10 : SCK30  - P33
      SCL30 - P33
      SI30  - P34
      RxD3  - P34
      SDA30 - P34
      SO30  - P35
      TxD3  - P35
 11 : -
*/
#define BSP_CFG_PIOR115 (0)
#define BSP_CFG_PIOR114 (0)

/* Peripheral I/O redirection register 11(PIOR11-PIOR117/PIOR116)
   64/80-pin
 00 : -
 01 : SCK31 - -
      SCL31 - P02
      SI31  - -
      SDA31 - P03
      SO31  - -
 10 : SCK31 - P02
      SCL31 - P02
      SI31  - P03
      SDA31 - P03
      SO31  - P01
 11 : -

   100-pin
 00 : SCK31 - P140
      SCL31 - P140
      SI31  - P46
      SDA31 - P46
      SO31  - P47
 01 : SCK31 - P02
      SCL31 - P02
      SI31  - P03
      SDA31 - P03
      SO31  - P146
 10 : SCK31 - P02
      SCL31 - P02
      SI31  - P03
      SDA31 - P03
      SO31  - P01
 11 : -
*/
#define BSP_CFG_PIOR117 (0)
#define BSP_CFG_PIOR116 (0)

/* Peripheral I/O redirection register 12(PIOR12-PIOR121/PIOR120)
   44/48/52/64-pin
 00 : SCLA0 - P60
      SDAA0 - P61
 01 : -
 10 : -
11 : -

   80-pin
 00 : SCLA0 - P60
      SDAA0 - P61
 01 : SCLA0 - P42
      SDAA0 - P41
 10 : -
11 : -

   100-pin
 00 : SCLA0 - P60
      SDAA0 - P61
 01 : SCLA0 - P42
      SDAA0 - P41
 10 : SCLA0 - P144
      SDAA0 - P145
11 : -
*/
#define BSP_CFG_PIOR121 (0)
#define BSP_CFG_PIOR120 (0)

/* Peripheral I/O redirection register 12(PIOR12-PIOR123/PIOR122)
   44/48/52-pin
 00 : -
 01 : -
 10 : SCLA1 - P97
      SDAA1 - P96
11 : -

   64/80-pin
 00 : SCLA1 - P62
      SDAA1 - P63
 01 : -
 10 : SCLA1 - P97
      SDAA1 - P96
11 : -

   100-pin
 00 : SCLA1 - P62
      SDAA1 - P63
 01 : SCLA1 - P65
      SDAA1 - P64
 10 : SCLA1 - P97
      SDAA1 - P96
11 : SCLA1  - P84
      SDAA1 - P83
*/
#define BSP_CFG_PIOR123 (0)
#define BSP_CFG_PIOR122 (0)

/* Peripheral I/O redirection register 13(PIOR3-PIOR131/PIOR130)
   44/48/52/64-pin
 00 : RxDA0 - P11
      TxDA0 - P10
 01 : -
 10 : -
 11 : -

   80-pin
 00 : RxDA0 - P11
      TxDA0 - P10
 01 : -
 10 : RxDA0 - P47
      TxDA0 - P130
 11 : -

   100-pin
 00 : RxDA0 - P11
      TxDA0 - P10
 01 : RxDA0 - P83
      TxDA0 - P84
 10 : RxDA0 - P47
      TxDA0 - P130
 11 : -
*/
#define BSP_CFG_PIOR131 (0)
#define BSP_CFG_PIOR130 (0)

/* Peripheral I/O redirection register 13(PIOR3-PIOR133/PIOR132)
   44/48/52-pin
 00 : RxDA1 - P27
      TxDA1 - P26
 01 : -
 10 : -
 11 : -

   64/80-pin
 00 : RxDA1 - P27
      TxDA1 - P26
 01 : RxDA1 - P43
      TxDA1 - P42
 10 : -
 11 : -

   100-pin
 00 : RxDA1 - P27
      TxDA1 - P26
 01 : RxDA1 - P43
      TxDA1 - P42
 10 : RxDA1 - P144
      TxDA1 - P145
 11 : -
*/
#define BSP_CFG_PIOR133 (0)
#define BSP_CFG_PIOR132 (0)

/* Peripheral I/O redirection register 13(PIOR3-PIOR135/PIOR134)
 (flash memory 64 or 128 KB)
   80-pin
 00 : RxDA2 - P44
      TxDA2 - P45
 01 : -
 10 : -
 11 : -

   100-pin
 00 : RxDA2 - P44
      TxDA2 - P45
 01 : RxDA2 - P146
      TxDA2 - P03
 10 : RxDA2 - P142
      TxDA2 - P143
 11 : -

 (flash memory 256 or 512 KB)
   48/52/64/80-pin
 00 : RxDA2 - P44
      TxDA2 - P45
 01 : -
 10 : -
 11 : -

   100-pin
 00 : RxDA2 - P44
      TxDA2 - P45
 01 : RxDA2 - P146
      TxDA2 - P03
 10 : RxDA2 - P142
      TxDA2 - P143
 11 : -
*/
#define BSP_CFG_PIOR135 (0)
#define BSP_CFG_PIOR134 (0)

/* Peripheral I/O redirection register 13(PIOR13-PIOR137/PIOR136)
   80-pin
 00 : RxDA3 - P51
      TxDA3 - P50
 01 : -
 10 : -
 11 : -

   100-pin
 00 : RxDA3 - P51
      TxDA3 - P50
 01 : RxDA3 - P41
      TxDA3 - P66
 10 : RxDA3 - P141
      TxDA3 - P147
 11 : -
*/
#define BSP_CFG_PIOR137 (0)
#define BSP_CFG_PIOR136 (0)

/***********************************************************
 * Invalid memory access detection control register (IAWCTL)
 ***********************************************************/
/* Control of illicit memory access detection(IAWEN)
 0 : Disables the detection of illicit memory accesses.
 1 : Enables the detection of illicit memory accesses.
*/
#define BSP_CFG_INVALID_MEMORY_ACCESS_DETECTION_ENABLE (0)

/* Protected area in the RAM(GRAM1-0)
 0 : Disabled. Writing to the RAM is allowed.
 1 : 128 bytes from the base address of the RAM
 2 : 256 bytes from the base address of the RAM
 3 : 512 bytes from the base address of the RAM
*/
#define BSP_CFG_RAM_GUARD_FUNC (0)

/* Protection of the port control registers(GPORT)
 0 : Disabled. Reading from and writing to the port control registers are allowed.
 1 : Enabled. Writing to the port control registers is not allowed. Reading from them is allowed.
 [Protected SFRs] PMxx, PUxx, PIMxx, POMxx, PMCAxx, PMCTxx, PMCExx, PFOEx,
                  PDIDISxx, CCDE, CCSm, PTDC, PFSEGx, ISCLCD)
 Note : The port registers(Pxx) are not protected.
*/
#define BSP_CFG_PORT_FUNCTION_GUARD (0)

/* Protection of the interrupt control registers(GINT)
 0 : Disabled. Reading from and writing to the interrupt control registers are allowed.
 1 : Enabled. Writing to the interrupt control registers is not allowed. Reading from them is allowed.
 [Protected SFRs] IFxx, MKxx, PRxx, EGPx, EGNx
*/
#define BSP_CFG_INT_FUNCTION_GUARD (0)

/* Protection of the clock, voltage detector, 
   and RAM parity error detection control registers(GCSC)
 0 : Disabled. Reading from and writing to the clock, voltage detector,
     and RAM parity error detection control registers are allowed.
 1 : Enabled. Writing to the clock, voltage detector,
    and RAM parity error detection control registers is not allowed. Reading from them is allowed.
 [Protected SFRs] CMC, CSC, OSTS, CKC, PERx, OSMC, LVIM, LVIS, RPECTL,
                  CKSEL, PRRx, MOCODIV, WKUPMD, PSMCR, MODRV, SOMRG
*/
#define BSP_CFG_CHIP_STATE_CTRL_GUARD (0)

/*************************************************
 * Data flash
 *************************************************/
/* Data flash memory area access control(DFLEN)
 0 : Access to the data flash memory area is disabled.
 1 : Access to the data flash memory area is enabled.
*/
#define BSP_CFG_DATA_FLASH_ACCESS_ENABLE (0)

/*************************************************
 * Definition for switching functions
 *************************************************/

/* Start up select
 0 : Enable BSP startup program.
 1 : Disable BSP startup program.(e.g. Using user startup program.)
*/
#define BSP_CFG_STARTUP_DISABLE (0)

/* Initialization of peripheral functions by Code Generator/Smart Configurator
 0 : Disable initialization of peripheral functions by Code Generator/Smart Configurator.
 1 : Enable initialization of peripheral functions by Code Generator/Smart Configurator.
*/
#define BSP_CFG_CONFIGURATOR_SELECT (0)

/* Version number of Smart Configurator.
   This macro definitions is updated by Smart Configurator.
   If you are using e2studio, set the following values.
   2021-04 : 1001
   2021-07 : 1010
   2021-10 : 1010
   2022-01 : 1030
   2023-04 : 1060
   If you are using the standalone version of Smart Configurator,
   set the following values.
   v1.0.1  : 1001
   v1.1.0  : 1010
   v1.3.0  : 1030
   v1.6.0  : 1060
*/
#define BSP_CFG_CONFIGURATOR_VERSION    (1001)

/* API functions disable(R_BSP_StartClock, R_BSP_StopClock)
 0 : Enable API functions
 1 : Disable API functions
*/
#define BSP_CFG_CLOCK_OPERATION_API_FUNCTIONS_DISABLE (1)

/* API function disable(R_BSP_GetFclkFreqHz)
 0 : Enable API function
 1 : Disable API function
*/
#define BSP_CFG_GET_FREQ_API_FUNCTIONS_DISABLE (0)

/* API function disable(R_BSP_SetClockSource)
 0 : Enable API function
 1 : Disable API function
*/
#define BSP_CFG_SET_CLOCK_SOURCE_API_FUNCTIONS_DISABLE (1)

/* API function disable(R_BSP_ChangeClockSetting)
 0 : Enable API function
 1 : Disable API function
*/
#define BSP_CFG_CHANGE_CLOCK_SETTING_API_FUNCTIONS_DISABLE (1)

/* API function disable(R_BSP_SoftwareDelay)
 0 : Enable API function
 1 : Disable API function
*/
#define BSP_CFG_SOFTWARE_DELAY_API_FUNCTIONS_DISABLE (1)

/* Parameter check enable
 0 : Disable parameter check.
 1 : Enable parameter check.
*/
#define BSP_CFG_PARAM_CHECKING_ENABLE (1)

/*************************************************
 * Clock settings
 *************************************************/
/* High-speed system clock frequency(fMX)
   High-speed system clock pin operation mode
   Clock operation mode control register(CMC)
    EXCLK/OSCSEL
 0 : Port mode
 1 : X1 oscillation mode(Crystal/ceramic resonator connection)
 2 : External clock input mode(External clock input)
*/
#define BSP_CFG_HISYSCLK_SOURCE (0)

/* High-speed system clock frequency(fMX)
   High-speed system clock operation control
   Clock operation status control register(CSC)
    MSTOP
 (X1 oscillation mode)
  0 : The X1 oscillator runs.
  1 : The X1 oscillator is stopped.
 (External clock input mode)
  0 : An external clock signal on the EXCLK pin is effective.
  1 : An external clock signal on the EXCLK pin is ineffective.
 (Port mode)
  0 : I/O port
  1 : I/O port
*/
#define BSP_CFG_HISYSCLK_OPERATION (1)

/* Subsystem clock oscillator clock frequency(fSX)
   Subsystem clock pin operation mode
   Clock operation mode control register(CMC)
    EXCLKS/OSCSELS
 0 : Input port mode
 1 : XT1 oscillation mode(Crystal resonator connection)
 2 : External clock input mode(External clock input)
*/
#define BSP_CFG_SUBCLK_SOURCE (0)

/* Subsystem clock oscillator clock frequency(fSX)
   Subsystem clock operation control
   Clock operation status control register(CSC)
    XTSTOP
 (XT1 oscillation mode)
  0 : The XT1 oscillator runs.
  1 : The XT1 oscillator is stopped.
 (External clock input mode)
  0 : An external clock signal on the EXCLKS pin is effective.
  1 : An external clock signal on the EXCLKS pin is ineffective.
 (Port mode)
  0 : Input port
  1 : Input port
*/
#define BSP_CFG_SUBCLK_OPERATION (1)

/* Middle-speed on-chip oscillator clock frequency(fIM)
   Middle-speed on-chip oscillator clock operation control
   Clock operation status control register(CSC)
    MIOEN
 0 : The middle-speed on-chip oscillator is stopped.
 1 : The middle-speed on-chip oscillator runs.
*/
#define BSP_CFG_MOCO_OPERATION (0)

/* Main on-chip oscillator clock(fOCO) operation control
   System clock control register(CKC)
    MCM1
 0 : High-speed on-chip oscillator clock
 1 : Middle-speed on-chip oscillator clock
*/
#define BSP_CFG_OCOCLK_SOURCE (0)

/* Main system clock(fMAIN) operation control
   System clock control register(CKC)
    MCM0
 0 : Selects the main on-chip oscillator clock(fOCO) as the main system clock(fMAIN)
 1 : Selects the high-speed system clock(fMX) as the main system clock(fMAIN)
*/
#define BSP_CFG_MAINCLK_SOURCE (0)

/* Selection of the subsystem clock X or low-speed on-chip oscillator clock
   Subsystem clock select register(CKSEL)
    SELLOSC
 0 : Subsystem clock X
 1 : Low-speed on-chip oscillator clock
*/
#define BSP_CFG_SUBSYSCLK_SOURCE (1)

/* Selection of the CPU/peripheral hardware clock(fCLK)
   System clock control register(CKC)
    CSS
 0 : Main system clock(fMAIN)
 1 : Subsystem clock(fSUB)
*/
#define BSP_CFG_FCLK_SOURCE (0)

/* Selection of the oscillation mode of the XT1 oscillator
   Clock operation mode control register(CMC)
   AMPHS1, AMPHS0
 0 : Low power consumption oscillation 1(default)
 1 : Normal oscillation
 2 : Low power consumption oscillation 2
 3 : Low power consumption oscillation 3
*/
#define BSP_CFG_XT1_OSCMODE (0)

/* Input clock frequency in Hz(High-speed system clock(X1))
*/
#define BSP_CFG_FMX_HZ (20000000)

/* Control of the X1 clock oscillation frequency
   Clock Operation Mode Control Register(CMC)
    AMPH
   Main oscillator oscillation mode selection register(MODRV)
   AMPH1
 0 : 5 MHz < fX <= 10 MHz
 1 : 1 MHz <= fX <= 5 MHz(T.B.D)
 2 : 10 MHz < fX <= 20 MHz
 Set the value corresponding to the setting of BSP_CFG_FMX_HZ
*/

/* Selection of the oscillation stabilization time
   Oscillation stabilization time select register(OSTS)
    OSTS2, OSTS1, OSTS0
 0 :  2^8/fX(fX = 10MHz : 25.6us, fX = 20MHz : 12.8us)
 1 :  2^9/fX(fX = 10MHz : 51.2us, fX = 20MHz : 25.6us)
 2 : 2^10/fX(fX = 10MHz : 102us,  fX = 20MHz : 51.2us)
 3 : 2^11/fX(fX = 10MHz : 204us,  fX = 20MHz : 102us)
 4 : 2^13/fX(fX = 10MHz : 819us,  fX = 20MHz : 409us)
 5 : 2^15/fX(fX = 10MHz : 3.27ms, fX = 20MHz : 1.63ms)
 6 : 2^17/fX(fX = 10MHz : 13.1ms, fX = 20MHz : 6.55ms)
 7 : 2^18/fX(fX = 10MHz : 26.2ms, fX = 20MHz : 13.1ms)
*/
#define BSP_CFG_X1_WAIT_TIME_SEL (0)

/* Setting in STOP mode or in HALT mode while the CPU is opeating with subsystem clock X
   Subsystem clock supply mode control register(OSMC)
    RTCLPC
 0 : Enables supply of subsystem clock X to peripheral functions.
 1 : Stops supply of the subsystem clock to peripheral functions other than the realtime clock,
     clock output/buzzer output function, LCD controller/driver.
*/
#define BSP_CFG_ALLOW_FSUB_IN_STOPHALT (1)

/* Selection of the operating clock for the realtime clock, serial interface UARTA,
   clock output/buzzer output controller, LCD controller/driver, 32-bit interval timer,
   serial interfaces UARTA0 and UARTA1, remote control signal receiver,
   8-bit interval timer, and external signal sampler.
   Subsystem clock supply mode control register(OSMC)
    WUTMMCK0
 0 : Subsystem clock X
 1 : Low-speed on-chip oscillator clock
*/
#define BSP_CFG_RTC_OUT_CLK_SOURCE (1)

/* Selection of high-speed on-chip oscillator clock frequency
   High-speed on-chip oscillator frequency select register(HOCODIV)
    HOCODIV2, HOCODIV1, HOCODIV0
 (FRQSEL4 = 0, FRQSEL3 = 0)
  0 : fIH = 24 MHz
  1 : fIH = 12 MHz
  2 : fIH =  6 MHz
  3 : fIH =  3 MHz
  Other than above : Setting prohibited

 (FRQSEL4 = 0, FRQSEL3 = 1)
  0 : fIH = 32 MHz
  1 : fIH = 16 MHz
  2 : fIH =  8 MHz
  3 : fIH =  4 MHz
  4 : fIH =  2 MHz
  5 : fIH =  1 MHz
  Other than above : Setting prohibited

 (FRQSEL4 = 1, FRQSEL3 = 0)
  0 : fIH = 24 MHz, fHOCO = 48 MHz
  1 : fIH = 12 MHz, fHOCO = 24 MHz
  2 : fIH =  6 MHz, fHOCO = 12 MHz
  3 : fIH =  3 MHz, fHOCO =  6 MHz
  Other than above : Setting prohibited

 (FRQSEL4 = 1, FRQSEL3 = 1)
  0 : fIH = 32 MHz, fHOCO = 64 MHz
  1 : fIH = 16 MHz, fHOCO = 32 MHz
  2 : fIH =  8 MHz, fHOCO = 16 MHz
  3 : fIH =  4 MHz, fHOCO =  8 MHz
  4 : fIH =  2 MHz, fHOCO =  4 MHz
  5 : fIH =  1 MHz, fHOCO =  2 MHz
  Other than above : Setting prohibited
*/
#define BSP_CFG_HOCO_DIVIDE (0)

/* Setting for starting the high-speed on-chip oscillator at the times of release from STOP mode
   and of transitions to SNOOZE mode
   Standby mode release setting register(WKUPMD)
    FWKUP
 0 : Starting of the high-speed on-chip oscillator is at normal speed.
 1 : Starting of the high-speed on-chip oscillator is at high speed.
*/
#define BSP_CFG_WAKEUP_MODE (1)

/* Selected division ratio for the high-speed system clock
   High-speed system clock division register(MOSCDIV)
    MOSCDIV2, MOSCDIV1, MOSCDIV0
 0 : fMX   (fMX = 20MHz : 20MHz)
 1 : fMX/2 (fMX = 20MHz : 10MHz)
 2 : fMX/4 (fMX = 20MHz : 5MHz)
 3 : fMX/8 (fMX = 20MHz : 2.5MHz)
 4 : fMX/16(fMX = 20MHz : 1.25MHz)
 Other than above : Setting prohibited
*/
#define BSP_CFG_MOSC_DIVIDE (0)

/* Selection of the middle-speed on-chip oscillator clock frequency
   Middle-speed on-chip oscillator frequency select register(MOCODIV)
    MOCODIV1, MOCODIV0
 0 : 4MHz
 1 : 2MHz
 2 : 1MHz
 Other than above : Setting prohibited
*/
#define BSP_CFG_MOCO_DIVIDE (0)

/* Setting for checking a margin of the XT1 oscillator
   XT1 oscillator margin checking control register(SOMRG)
    SOSCMRG1, SOSCMRG0
 0 : Normal oscillation state
 1 : The lower-limit margin of oscillation by the XT1 oscillator is checked.
 2 : The upper-limit margin of oscillation by the XT1 oscillator is checked.
 Other than above : Setting prohibited.
*/
#define BSP_CFG_XT1_MARGIN_CHECK (0)

/* Operation setting at initial setting */
/* Starts the high-speed on-chip oscillator at initialization
 0 : Stops the high-speed on-chip oscillator at initialization
 1 : Starts the high-speed on-chip oscillator at initialization
*/
#define BSP_CFG_FIH_START_ON_STARTUP (1)

/* This macro lets other modules no if a RTOS is being used.
  0 = RTOS is not used.
  1 = FreeRTOS is used.(This is not available.)
  2 = embOS is used.(This is not available.)
  3 = MicroC_OS is used.(This is not available.)
  4 = Renesas ITRON is used.
*/
#define BSP_CFG_RTOS_USED (0)

/* Loop count using the main system clock. */
/* The loop count refers to a loop consisting of a "for" statement that executes a single NOP instruction.
   The loop count values are just example.
   Since the actual number of cycles will differ according to factors such as the optimization option,
   you will need to specify a setting that matches your environment. */

/* Subsystem clock oscillation stabilization time.
   If the main system clock is 32 MHz, 800000 means 300 ms. */
#define BSP_CFG_SUBWAITTIME              (800000U)

/* High-speed on-chip oscillator clock stabilization time.
   If the main system clock is 32 MHz, 30 means 5.86 us. */
#define BSP_CFG_FIHWAITTIME              (30U)

/* Middle-speed on-chip oscillator clock stabilization time.
   If the main system clock is 32 MHz, 5 means 1.16 us. */
#define BSP_CFG_FIMWAITTIME              (5U)

/* Low-speed on-chip oscillator clock stabilization time.
   If the main system clock is 32 MHz, 450 means 84.8 us. */
#define BSP_CFG_FILWAITTIME              (450U)

/* Wait time for the setup to finish when the data flash access is enabled.
   If the main system clock is 32 MHz, 2 means 400 ns. */
#define BSP_CFG_SETUP_WAITTIME           (2U)

/* If the user would like to determine if a warm start reset has occurred, then they may enable one or more of the
   following callback definitions AND provide a call back function name for the respective callback
   function (to be defined by the user). Setting BSP_CFG_USER_WARM_START_CALLBACK_PRE_INITC_ENABLED = 1 will result
   in a callback to the user defined my_sw_warmstart_prec_function just prior to the initialization of the C
   runtime environment by bsp_init_system.
   Setting BSP_CFG_USER_WARM_START_CALLBACK_POST_INITC_ENABLED = 1 will result in a callback to the user defined
   my_sw_warmstart_postc_function just after the initialization of the C runtime environment by bsp_init_hardware.
*/
#define BSP_CFG_USER_WARM_START_CALLBACK_PRE_INITC_ENABLED     (0)
#define BSP_CFG_USER_WARM_START_PRE_C_FUNCTION                 my_sw_warmstart_prec_function

#define BSP_CFG_USER_WARM_START_CALLBACK_POST_INITC_ENABLED    (0)
#define BSP_CFG_USER_WARM_START_POST_C_FUNCTION                my_sw_warmstart_postc_function

/* If the user sets the window open period of watchdog timer to 50%,
   set the following macro definition(BSP_CFG_WDT_REFRESH_ENABLE) to 2
   and specify the callback function name for each callback function(to be defined by the user).
   Setting BSP_CFG_WDT_REFRESH_ENABLE == 2 will result in a callback to the user defined
   my_sw_wdt_refresh_init_function just prior to the clock is set by bsp_init_system.
   In addition, a callback to the user defined my_sw_wdt_refresh_setting_function occurs
   during the oscillation stabilization wait time of the subsystem clock.
*/
#define BSP_CFG_WDT_REFRESH_ENABLE                   (0)
#define BSP_CFG_USER_WDT_REFRESH_INIT_FUNCTION       my_sw_wdt_refresh_init_function
#define BSP_CFG_USER_WDT_REFRESH_SETTING_FUNCTION    my_sw_wdt_refresh_setting_function

#endif /* R_BSP_CONFIG_REF_HEADER_FILE */
