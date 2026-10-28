/* Generated configuration header file - do not edit */
/*
* Copyright (c) 2021 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/
/***********************************************************************************************************************
* File Name    : r_bsp_config_reference.h
* H/W Platform : GENERIC_RL78_G23
* Description  : 
***********************************************************************************************************************/
/***********************************************************************************************************************
* History : DD.MM.YYYY Version  Description
*         : 08.03.2021 1.00     First Release
*         : 22.04.2021 1.10     Modified comment for added support of 
*                               Security ID Codes for On-Chip Debugging (When using IAR).
*                               Added the following macro definitions.
*                                - BSP_CFG_SECUID0_VALUE
*                                - BSP_CFG_SECUID1_VALUE
*                                - BSP_CFG_SECUID2_VALUE
*                                - BSP_CFG_SECUID3_VALUE
*                                - BSP_CFG_SECUID4_VALUE
*                                - BSP_CFG_SECUID5_VALUE
*                                - BSP_CFG_SECUID6_VALUE
*                                - BSP_CFG_SECUID7_VALUE
*                                - BSP_CFG_SECUID8_VALUE
*                                - BSP_CFG_SECUID9_VALUE
*                               Modified comment for added support of Renesas RTOS (RI78V4).
*                               Added the following macro definition.
*                                - BSP_CFG_RTOS_USED
*         : 25.05.2021 1.11     Renamed following macro definitions.
*                               - BSP_CFG_OPTBYTE0_VALUE
*                               - BSP_CFG_OPTBYTE1_VALUE
*                               - BSP_CFG_OPTBYTE2_VALUE
*                               - BSP_CFG_OPTBYTE3_VALUE
*                               - BSP_CFG_SUBWAITTIME
*                               - BSP_CFG_FIHWAITTIME
*                               - BSP_CFG_FIMWAITTIME
*                               - BSP_CFG_FILWAITTIME
*                               Modified the comment of oscillation stabilization time.
*         : 04.08.2021 1.12     Modified the comment of oscillation stabilization time.
*                               Added include guard.
*         : 29.10.2021 1.13     Added the following macro definition.
*                                - BSP_CFG_CONFIGURATOR_VERSION
*         : 28.02.2022 1.20     Added the following macro definition.
*                                - BSP_CFG_CHANGE_CLOCK_SETTING_API_FUNCTIONS_DISABLE
*                                - BSP_CFG_GET_FREQ_API_FUNCTIONS_DISABLE
*                                - BSP_CFG_SET_CLOCK_SOURCE_API_FUNCTIONS_DISABLE
*                                - BSP_CFG_CLOCK_OPERATION_API_FUNCTIONS_DISABLE
*                               Removed the following macro definition.
*                                - BSP_CFG_API_FUNCTIONS_DISABLE
*                               Added a comment about macro definition BSP_CFG_CONFIGURATOR_VERSION.
*         : 31.05.2022 1.30     Added the following macro definition.
*                                - BSP_CFG_SOFTWARE_DELAY_API_FUNCTIONS_DISABLE
*         : 11.11.2022 1.40     Changed the initial values of the following macro definitions from 0 to 1.
*                                - BSP_CFG_CLOCK_OPERATION_API_FUNCTIONS_DISABLE
*                                - BSP_CFG_SET_CLOCK_SOURCE_API_FUNCTIONS_DISABLE
*                                - BSP_CFG_CHANGE_CLOCK_SETTING_API_FUNCTIONS_DISABLE
*                                - BSP_CFG_SOFTWARE_DELAY_API_FUNCTIONS_DISABLE
*         : 31.01.2023 1.50     Fixed typo in history.
*         : 28.02.2023 1.60     Added the version number of Smart Configurator.
*                               Modified the comment related to the version number of Smart Configurator.
*         : 30.11.2023 1.62     Adjusted indentation of macro definitions.
*         : 06.02.2025 1.90     Added notes to the following macro definitions.
*                               - BSP_CFG_SUBWAITTIME
*                               - BSP_CFG_FIHWAITTIME
*                               - BSP_CFG_FIMWAITTIME
*                               - BSP_CFG_FILWAITTIME
*         : 05.08.2025 1.92     Changed the disclaimer.
*                               Reviewed the initial values of macro definitions.
*                               Reviewed the comments of macro definitions.
*                               Added macro definitions for waiting process.
*         : 09.01.2026 2.00     Added notes to prevent omissions in macro definitions setting when using an RTOS.
*                               Added the following macro definition.
*                                - BSP_CFG_MCU_PART_G23_GROUP
*                               Added a description about 104G to the comments in the following macro definitions.
*                                - BSP_CFG_PIOR0
*                                - BSP_CFG_PIOR1
*                                - BSP_CFG_PIOR2
*                                - BSP_CFG_PIOR3
*                                - BSP_CFG_PIOR4
*                                - BSP_CFG_PIOR5
***********************************************************************************************************************/

#ifndef R_BSP_CONFIG_REF_HEADER_FILE
#define R_BSP_CONFIG_REF_HEADER_FILE
/*************************************************
 * MCU information
 *************************************************/
/*
 R 7 F 100G L J 3 xxx C FB #AA0
 | | |  |   | | |  |  |  |  |__not used                    Packaging specification
 | | |  |   | | |  |  |  |_____not used                    Package type
 | | |  |   | | |  |  |________not used                    Fields of application
 | | |  |   | | |  |___________not used                    ROM number(Omitted for blank products)
 | | |  |   | | |______________not used                    Ambient operating temperature range
 | | |  |   | |________________BSP_CFG_MCU_PART_ROM_SIZE   ROM capacity
 | | |  |   |__________________BSP_CFG_MCU_PART_PIN_NUM    Pin count
 | | |  |______________________BSP_CFG_MCU_PART_G23_GROUP  RL78/G23 group
 | | |_________________________BSP_CFG_MCU_PART_ROM_TYPE   Device type
 | |___________________________not used                    Renesas MCU
 |_____________________________not used                    Renesas semiconductor product
*/

/* ROM capacity
 F = 96(KB) : 0x0
 G = 128    : 0x1
 H = 192    : 0x2
 J = 256    : 0x3
 K = 384    : 0x4
 L = 512    : 0x5
 N = 768    : 0x6
*/
#define BSP_CFG_MCU_PART_ROM_SIZE (0x6) /* Generated value. Do not edit this manually */

/* Pin count
 A = 30-pin  : 0x0
 B = 32-pin  : 0x1
 C = 36-pin  : 0x2
 E = 40-pin  : 0x3
 F = 44-pin  : 0x4
 G = 48-pin  : 0x5
 J = 52-pin  : 0x6
 L = 64-pin  : 0x7
 M = 80-pin  : 0x8
 P = 100-pin : 0x9
 S = 128-pin : 0xA
*/
#define BSP_CFG_MCU_PART_PIN_NUM (0xA) /* Generated value. Do not edit this manually */

/* RL78/G23 group
  100G = RL78/G23                         : 0x0
  104G = RL78/G23(CTSU channel extension) : 0x1
*/
#define BSP_CFG_MCU_PART_G23_GROUP (0x0) /* Generated value. Do not edit this manually */

/* group
 100G = RL78/G23                         : (true)
 104G = RL78/G23(CTSU channel extension) : (true)
*/
#define BSP_CFG_MCU_PART_HAS_DATA_FLASH (true)

/* Device type
 F = Flash memory : 0
*/
#define BSP_CFG_MCU_PART_ROM_TYPE (0)

#if defined(__ICCRL78__)
/* Option byte setting(When using IAR) */
#define BSP_CFG_OPTBYTE0_VALUE (0xEFU) /* Generated value. Do not edit this manually */
#define BSP_CFG_OPTBYTE1_VALUE (0xFEU) /* Generated value. Do not edit this manually */
#define BSP_CFG_OPTBYTE2_VALUE (0xE8U) /* Generated value. Do not edit this manually */
#define BSP_CFG_OPTBYTE3_VALUE (0x84U) /* Generated value. Do not edit this manually */
/* Security ID Codes for On-Chip Debugging setting(When using IAR) */
#define BSP_CFG_SECUID0_VALUE (0x00U) /* Generated value. Do not edit this manually */
#define BSP_CFG_SECUID1_VALUE (0x00U) /* Generated value. Do not edit this manually */
#define BSP_CFG_SECUID2_VALUE (0x00U) /* Generated value. Do not edit this manually */
#define BSP_CFG_SECUID3_VALUE (0x00U) /* Generated value. Do not edit this manually */
#define BSP_CFG_SECUID4_VALUE (0x00U) /* Generated value. Do not edit this manually */
#define BSP_CFG_SECUID5_VALUE (0x00U) /* Generated value. Do not edit this manually */
#define BSP_CFG_SECUID6_VALUE (0x00U) /* Generated value. Do not edit this manually */
#define BSP_CFG_SECUID7_VALUE (0x00U) /* Generated value. Do not edit this manually */
#define BSP_CFG_SECUID8_VALUE (0x00U) /* Generated value. Do not edit this manually */
#define BSP_CFG_SECUID9_VALUE (0x00U) /* Generated value. Do not edit this manually */
#endif

/*************************************************
 * Pin assignment setting
 *************************************************/
/* Peripheral I/O redirection register(PIOR-PIOR0)
 (RL78/G23 group=100G)
   40/36/32/30-pin
 0 : TI02/TO02 - P17
     TI03/TO03 - P31
     TI04/TO04 - These functions are not available for use.
     TI05/TO05 - These functions are not available for use.
     TI06/TO06 - These functions are not available for use.
     TI07/TO07 - These functions are not available for use.
 1 : TI02/TO02 - P15
     TI03/TO03 - P14
     TI04/TO04 - P13
     TI05/TO05 - P12
     TI06/TO06 - P11
     TI07/TO07 - P10

   52/48/44-pin
 0 : TI02/TO02 - P17
     TI03/TO03 - P31
     TI04/TO04 - These functions are not available for use.
     TI05/TO05 - These functions are not available for use.
     TI06/TO06 - These functions are not available for use.
     TI07/TO07 - P41
 1 : TI02/TO02 - P15
     TI03/TO03 - P14
     TI04/TO04 - P13
     TI05/TO05 - P12
     TI06/TO06 - P11
     TI07/TO07 - P10

   80/64-pin
 0 : TI02/TO02 - P17
     TI03/TO03 - P31
     TI04/TO04 - P42
     TI05/TO05 - P05
     TI06/TO06 - P06
     TI07/TO07 - P41
 1 : TI02/TO02 - P15
     TI03/TO03 - P14
     TI04/TO04 - P13
     TI05/TO05 - P12
     TI06/TO06 - P11
     TI07/TO07 - P10

   128/100-pin
 0 : TI02/TO02 - P17
     TI03/TO03 - P31
     TI04/TO04 - P42
     TI05/TO05 - P46
     TI06/TO06 - P102
     TI07/TO07 - P145
 1 : TI02/TO02 - P15
     TI03/TO03 - P14
     TI04/TO04 - P13
     TI05/TO05 - P12
     TI06/TO06 - P11
     TI07/TO07 - P10

 (RL78/G23 group=104G)
   32-pin
 0 : TI02/TO02 - P17
     TI03/TO03 - P31
     TI04/TO04 - -
     TI05/TO05 - P05
     TI06/TO06 - P06
     TI07/TO07 - -
 1 : TI02/TO02 - -
     TI03/TO03 - -
     TI04/TO04 - -
     TI05/TO05 - P12
     TI06/TO06 - P11
     TI07/TO07 - P10

   44-pin
 0 : TI02/TO02 - P17
     TI03/TO03 - P31
     TI04/TO04 - -
     TI05/TO05 - P05
     TI06/TO06 - P06
     TI07/TO07 - -
 1 : TI02/TO02 - -
     TI03/TO03 - -
     TI04/TO04 - P13
     TI05/TO05 - P12
     TI06/TO06 - P11
     TI07/TO07 - P10

   48-pin
 0 : TI02/TO02 - P17
     TI03/TO03 - P31
     TI04/TO04 - -
     TI05/TO05 - P05
     TI06/TO06 - P06
     TI07/TO07 - P41
 1 : TI02/TO02 - -
     TI03/TO03 - P14
     TI04/TO04 - P13
     TI05/TO05 - P12
     TI06/TO06 - P11
     TI07/TO07 - P10
*/
#define BSP_CFG_PIOR0 (0) /* Generated value. Do not edit this manually */

/* Peripheral I/O redirection register(PIOR-PIOR1)
 (RL78/G23 group=100G)
   48/44/40/36/32/30-pin
 0 : INTP10 - These functions are not available for use.
     INTP11 - These functions are not available for use.
     TxD2   - P13
     RxD2   - P14
     SCL20  - P15
     SDA20  - P14
     SI20   - P14
     SO20   - P13
     SCK20  - P15
     TxD0   - P12
     RxD0   - P11
     SCL00  - P10
     SDA00  - P11
     SI00   - P11
     SO00   - P12
     SCK00  - P10
 1 : INTP10 - These functions are not available for use.
     INTP11 - These functions are not available for use.
     TxD2   - These functions are not available for use.
     RxD2   - These functions are not available for use.
     SCL20  - These functions are not available for use.
     SDA20  - These functions are not available for use.
     SI20   - These functions are not available for use.
     SO20   - These functions are not available for use.
     SCK20  - These functions are not available for use.
     TxD0   - P17
     RxD0   - P16
     SCL00  - These functions are not available for use.
     SDA00  - These functions are not available for use.
     SI00   - These functions are not available for use.
     SO00   - These functions are not available for use.
     SCK00  - These functions are not available for use.

   52-pin
 0 : INTP10 - P76
     INTP11 - P77
     TxD2   - P13
     RxD2   - P14
     SCL20  - P15
     SDA20  - P14
     SI20   - P14
     SO20   - P13
     SCK20  - P15
     TxD0   - P12
     RxD0   - P11
     SCL00  - P10
     SDA00  - P11
     SI00   - P11
     SO00   - P12
     SCK00  - P10
 1 : INTP10 - These functions are not available for use.
     INTP11 - These functions are not available for use.
     TxD2   - P77
     RxD2   - P76
     SCL20  - These functions are not available for use.
     SDA20  - These functions are not available for use.
     SI20   - These functions are not available for use.
     SO20   - These functions are not available for use.
     SCK20  - These functions are not available for use.
     TxD0   - P17
     RxD0   - P16
     SCL00  - These functions are not available for use.
     SDA00  - These functions are not available for use.
     SI00   - These functions are not available for use.
     SO00   - These functions are not available for use.
     SCK00  - These functions are not available for use.

   64-pin
 0 : INTP10 - P76
     INTP11 - P77
     TxD2   - P13
     RxD2   - P14
     SCL20  - P15
     SDA20  - P14
     SI20   - P14
     SO20   - P13
     SCK20  - P15
     TxD0   - P12
     RxD0   - P11
     SCL00  - P10
     SDA00  - P11
     SI00   - P11
     SO00   - P12
     SCK00  - P10
 1 : INTP10 - P52
     INTP11 - P53
     TxD2   - P77
     RxD2   - P76
     SCL20  - These functions are not available for use.
     SDA20  - These functions are not available for use.
     SI20   - These functions are not available for use.
     SO20   - These functions are not available for use.
     SCK20  - These functions are not available for use.
     TxD0   - P17
     RxD0   - P16
     SCL00  - These functions are not available for use.
     SDA00  - These functions are not available for use.
     SI00   - P16
     SO00   - P17
     SCK00  - P55

   128/100/80-pin
 0 : INTP10 - P76
     INTP11 - P77
     TxD2   - P13
     RxD2   - P14
     SCL20  - P15
     SDA20  - P14
     SI20   - P14
     SO20   - P13
     SCK20  - P15
     TxD0   - P12
     RxD0   - P11
     SCL00  - P10
     SDA00  - P11
     SI00   - P11
     SO00   - P12
     SCK00  - P10
 1 : INTP10 - P110
     INTP11 - P111
     TxD2   - P77
     RxD2   - P76
     SCL20  - These functions are not available for use.
     SDA20  - These functions are not available for use.
     SI20   - These functions are not available for use.
     SO20   - These functions are not available for use.
     SCK20  - These functions are not available for use.
     TxD0   - P17
     RxD0   - P16
     SCL00  - These functions are not available for use.
     SDA00  - These functions are not available for use.
     SI00   - P16
     SO00   - P17
     SCK00  - P55

 (RL78/G23 group=104G)
   32-pin
 0 : INTP10 - P76
     INTP11 - P77
     TxD2   - -
     RxD2   - -
     SCL20  - -
     SDA20  - -
     SI20   - -
     SO20   - -
     SCK20  - -
     TxD0   - P12
     RxD0   - P11
     SCL00  - P10
     SDA00  - P11
     SI00   - P11
     SO00   - P12
     SCK00  - P10
 1 : INTP10 - -
     INTP11 - -
     TxD2   - P77
     RxD2   - P76
     SCL20  - -
     SDA20  - -
     SI20   - -
     SO20   - -
     SCK20  - -
     TxD0   - P17
     RxD0   - P16
     SCL00  - -
     SDA00  - -
     SI00   - -
     SO00   - -
     SCK00  - -

   44-pin
 0 : INTP10 - P76
     INTP11 - P77
     TxD2   - P13
     RxD2   - -
     SCL20  - -
     SDA20  - -
     SI20   - -
     SO20   - -
     SCK20  - -
     TxD0   - P12
     RxD0   - P11
     SCL00  - P10
     SDA00  - P11
     SI00   - P11
     SO00   - P12
     SCK00  - P10
 1 : INTP10 - -
     INTP11 - -
     TxD2   - P77
     RxD2   - P76
     SCL20  - -
     SDA20  - -
     SI20   - -
     SO20   - -
     SCK20  - -
     TxD0   - P17
     RxD0   - P16
     SCL00  - -
     SDA00  - -
     SI00   - -
     SO00   - -
     SCK00  - -

   48-pin
 0 : INTP10 - P76
     INTP11 - P77
     TxD2   - P13
     RxD2   - P14
     SCL20  - -
     SDA20  - -
     SI20   - -
     SO20   - -
     SCK20  - -
     TxD0   - P12
     RxD0   - P11
     SCL00  - P10
     SDA00  - P11
     SI00   - P11
     SO00   - P12
     SCK00  - P10
 1 : INTP10 - -
     INTP11 - -
     TxD2   - P77
     RxD2   - P76
     SCL20  - -
     SDA20  - -
     SI20   - -
     SO20   - -
     SCK20  - -
     TxD0   - P17
     RxD0   - P16
     SCL00  - -
     SDA00  - -
     SI00   - -
     SO00   - -
     SCK00  - -
*/
#define BSP_CFG_PIOR1 (0) /* Generated value. Do not edit this manually */

/* Peripheral I/O redirection register(PIOR-PIOR2)
 (RL78/G23 group=100G)
   128/100/80/64/52/48/44/40/36/32/30-pin
 0 : SCLA0 - P60
     SDAA0 - P61
 1 : SCLA0 - P14
     SDAA0 - P13

 (RL78/G23 group=104G)
   44/32-pin
 0 : SCLA0 - -
     SDAA0 - -
 1 : SCLA0 - -
     SDAA0 - -

   48-pin
 0 : SCLA0 - -
     SDAA0 - -
 1 : SCLA0 - P14
     SDAA0 - P13
*/
#define BSP_CFG_PIOR2 (0) /* Generated value. Do not edit this manually */

/* Peripheral I/O redirection register(PIOR-PIOR3)
 (RL78/G23 group=100G)
   44/40/36/32/30-pin
 0 : PCLBUZ0 - These functions are not available for use. Set this bit to 0(default value).
 1 : PCLBUZ0 - These functions are not available for use. Set this bit to 0(default value).

   128/100/80/64/52/48-pin
 0 : PCLBUZ0 - P140
 1 : PCLBUZ0 - P31

 (RL78/G23 group=104G)
   48/44/32-pin
 0 : PCLBUZ0 - -
 1 : PCLBUZ0 - P31
*/
#define BSP_CFG_PIOR3 (0) /* Generated value. Do not edit this manually */

/* Peripheral I/O redirection register(PIOR-PIOR4)
 (RL78/G23 group=100G)
   52/48/44/40/36/32/30-pin
 0 : PCLBUZ1 - These functions are not available for use. Set this bit to 0(default value).
     INTP5   - These functions are not available for use. Set this bit to 0(default value).
 1 : PCLBUZ1 - These functions are not available for use. Set this bit to 0(default value).
     INTP5   - These functions are not available for use. Set this bit to 0(default value).

   128/100/80/64-pin
 0 : PCLBUZ1 - P141
     INTP5   - P16
 1 : PCLBUZ1 - P55
     INTP5   - P12

 (RL78/G23 group=104G)
   48/44/32-pin
 0 : PCLBUZ1 - -
     INTP5   - P16
 1 : PCLBUZ1 - -
     INTP5   - P12
*/
#define BSP_CFG_PIOR4 (0) /* Generated value. Do not edit this manually */

/* Peripheral I/O redirection register(PIOR-PIOR5)
 (RL78/G23 group=100G)
   80/64/52/48/44/40/36/32/30-pin
 0 : INTP1 - These functions are not available for use. Set this bit to 0(default value).
     INTP3 - These functions are not available for use. Set this bit to 0(default value).
     INTP4 - These functions are not available for use. Set this bit to 0(default value).
     INTP6 - These functions are not available for use. Set this bit to 0(default value).
     INTP7 - These functions are not available for use. Set this bit to 0(default value).
     INTP8 - These functions are not available for use. Set this bit to 0(default value).
     INTP9 - These functions are not available for use. Set this bit to 0(default value).
     TxD1  - These functions are not available for use. Set this bit to 0(default value).
     RxD1  - These functions are not available for use. Set this bit to 0(default value).
     SCL10 - These functions are not available for use. Set this bit to 0(default value).
     SDA10 - These functions are not available for use. Set this bit to 0(default value).
     SI10  - These functions are not available for use. Set this bit to 0(default value).
     SO10  - These functions are not available for use. Set this bit to 0(default value).
     SCK10 - These functions are not available for use. Set this bit to 0(default value).
 1 : INTP1 - These functions are not available for use. Set this bit to 0(default value).
     INTP3 - These functions are not available for use. Set this bit to 0(default value).
     INTP4 - These functions are not available for use. Set this bit to 0(default value).
     INTP6 - These functions are not available for use. Set this bit to 0(default value).
     INTP7 - These functions are not available for use. Set this bit to 0(default value).
     INTP8 - These functions are not available for use. Set this bit to 0(default value).
     INTP9 - These functions are not available for use. Set this bit to 0(default value).
     TxD1  - These functions are not available for use. Set this bit to 0(default value).
     RxD1  - These functions are not available for use. Set this bit to 0(default value).
     SCL10 - These functions are not available for use. Set this bit to 0(default value).
     SDA10 - These functions are not available for use. Set this bit to 0(default value).
     SI10  - These functions are not available for use. Set this bit to 0(default value).
     SO10  - These functions are not available for use. Set this bit to 0(default value).
     SCK10 - These functions are not available for use. Set this bit to 0(default value).

   128/100-pin
 0 : INTP1 - P46
     INTP3 - P30
     INTP4 - P31
     INTP6 - P140
     INTP7 - P141
     INTP8 - P74
     INTP9 - P75
     TxD1  - P02
     RxD1  - P03
     SCL10 - P04
     SDA10 - P03
     SI10  - P03
     SO10  - P02
     SCK10 - P04
 1 : INTP1 - P56
     INTP3 - P57
     INTP4 - P146
     INTP6 - P84
     INTP7 - P85
     INTP8 - P86
     INTP9 - P87
     TxD1  - P82
     RxD1  - P81
     SCL10 - P80
     SDA10 - P81
     SI10  - P81
     SO10  - P82
     SCK10 - P80

 (RL78/G23 group=104G)
   48/44/32-pin
 0 : INTP1 - These functions are not available for use. Set this bit to 0(default value).
     INTP3 - These functions are not available for use. Set this bit to 0(default value).
     INTP4 - These functions are not available for use. Set this bit to 0(default value).
     INTP6 - These functions are not available for use. Set this bit to 0(default value).
     INTP7 - These functions are not available for use. Set this bit to 0(default value).
     INTP8 - These functions are not available for use. Set this bit to 0(default value).
     INTP9 - These functions are not available for use. Set this bit to 0(default value).
     TxD1  - These functions are not available for use. Set this bit to 0(default value).
     RxD1  - These functions are not available for use. Set this bit to 0(default value).
     SCL10 - These functions are not available for use. Set this bit to 0(default value).
     SDA10 - These functions are not available for use. Set this bit to 0(default value).
     SI10  - These functions are not available for use. Set this bit to 0(default value).
     SO10  - These functions are not available for use. Set this bit to 0(default value).
     SCK10 - These functions are not available for use. Set this bit to 0(default value).
 1 : INTP1 - These functions are not available for use. Set this bit to 0(default value).
     INTP3 - These functions are not available for use. Set this bit to 0(default value).
     INTP4 - These functions are not available for use. Set this bit to 0(default value).
     INTP6 - These functions are not available for use. Set this bit to 0(default value).
     INTP7 - These functions are not available for use. Set this bit to 0(default value).
     INTP8 - These functions are not available for use. Set this bit to 0(default value).
     INTP9 - These functions are not available for use. Set this bit to 0(default value).
     TxD1  - These functions are not available for use. Set this bit to 0(default value).
     RxD1  - These functions are not available for use. Set this bit to 0(default value).
     SCL10 - These functions are not available for use. Set this bit to 0(default value).
     SDA10 - These functions are not available for use. Set this bit to 0(default value).
     SI10  - These functions are not available for use. Set this bit to 0(default value).
     SO10  - These functions are not available for use. Set this bit to 0(default value).
     SCK10 - These functions are not available for use. Set this bit to 0(default value).
*/
#define BSP_CFG_PIOR5 (0) /* Generated value. Do not edit this manually */

/***********************************************************
 * Invalid memory access detection control register (IAWCTL)
 ***********************************************************/
/* Control of illicit memory access detection(IAWEN)
 0 : Disables the detection of illicit memory accesses.
 1 : Enables the detection of illicit memory accesses.
*/
#define BSP_CFG_INVALID_MEMORY_ACCESS_DETECTION_ENABLE (0)

/* Protected area in the RAM(GRAM0-1)
 0 : Disabled. Writing to the RAM is allowed.
 1 : 128 bytes from the base address of the RAM.
 2 : 256 bytes from the base address of the RAM.
 3 : 512 bytes from the base address of the RAM.
*/
#define BSP_CFG_RAM_GUARD_FUNC (0)

/* Protection of the port control registers(GPORT)
 0 : Disabled. Reading from and writing to the port control registers are allowed.
 1 : Enabled. Writing to the port control registers is not allowed. Reading from them is allowed.
 [Protected SFRs] PMxx, PUxx, PIMxx, POMxx, PMCAxx, PMCTxx, PMCExx, PFOEx, PDIDISxx, CCDE, CCSm, PTDC
 Note:The port registers (Pxx) are not protected.
*/
#define BSP_CFG_PORT_FUNCTION_GUARD (0)

/* Protection of the interrupt control registers(GINT)
 0 : Disabled. Reading from and writing to the interrupt control registers are allowed.
 1 : Enabled. Writing to the interrupt control registers is not allowed. Reading from them is allowed.
 [Protected SFRs] IFxx, MKxx, PRxx, EGPx, EGNx
*/
#define BSP_CFG_INT_FUNCTION_GUARD (0)

/* Protection of the clock, voltage detector, and RAM parity error detection control registers(GCSC)
 0 : Disabled. Reading from and writing to the clock, voltage detector, and RAM parity error
     detection control registers are allowed.
 1 : Enabled. Writing to the clock, voltage detector, and RAM parity error detection control
     registers is not allowed. Reading from them is allowed.
 [Protected SFRs] CMC, CSC, OSTS, CKC, PERx, OSMC, LVIM, LVIS, RPECTL, CKSEL,
 PRRx, MOCODIV, WKUPMD, PSMCR
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
#define BSP_CFG_CONFIGURATOR_SELECT (1)

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
#define BSP_CFG_CONFIGURATOR_VERSION    (1180) /* Generated value. Do not edit this manually */

/* API function disable(R_BSP_StartClock, R_BSP_StopClock)
 0 : Enable API functions
 1 : Disable API functions
*/
#define BSP_CFG_CLOCK_OPERATION_API_FUNCTIONS_DISABLE (1)

/* API function disable(R_BSP_GetFclkFreqHz)
 0 : Enable API functions
 1 : Disable API functions
*/
#define BSP_CFG_GET_FREQ_API_FUNCTIONS_DISABLE (0)

/* API function disable(R_BSP_SetClockSource)
 0 : Enable API functions
 1 : Disable API functions
*/
#define BSP_CFG_SET_CLOCK_SOURCE_API_FUNCTIONS_DISABLE (1)

/* API function disable(R_BSP_ChangeClockSetting)
 0 : Enable API functions
 1 : Disable API functions
*/
#define BSP_CFG_CHANGE_CLOCK_SETTING_API_FUNCTIONS_DISABLE (1)

/* API function disable(R_BSP_SoftwareDelay)
 0 : Enable API functions
 1 : Disable API functions
*/
#define BSP_CFG_SOFTWARE_DELAY_API_FUNCTIONS_DISABLE (0)

/* Parameter check enable
 0 : Disable parameter check.
 1 : Enable parameter check.
*/
#define BSP_CFG_PARAM_CHECKING_ENABLE (1)

/*************************************************
 * Clock settings
 *************************************************/
/* High-speed system clock pin operation mode
   Clock operation mode control register(CMC)
   (Products with 30 to 36 pins)
    XTSEL/EXCLK/OSCSEL
   (Products with 40 to 128 pins)
    EXCLK/OSCSEL
 0 : Port mode
 1 : X1 oscillation mode
 2 : External clock input mode
*/
#define BSP_CFG_HISYSCLK_SOURCE (0) /* Generated value. Do not edit this manually */

/* High-speed system clock operation control
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
#define BSP_CFG_HISYSCLK_OPERATION (1) /* Generated value. Do not edit this manually */

/* Subsystem clock pin operation mode
   Clock operation mode control register(CMC)
   (Products with 30 to 36 pins)
    XTSEL/EXCLKS/OSCSELS
   (Products with 40 to 128 pins)
    EXCLKS/OSCSELS
 0 : Input port mode
 1 : XT1 oscillation mode
 2 : External clock input mode
*/
#define BSP_CFG_SUBCLK_SOURCE (1) /* Generated value. Do not edit this manually */

/* Subsystem clock operation control
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
#define BSP_CFG_SUBCLK_OPERATION (0) /* Generated value. Do not edit this manually */

/* Middle-speed on-chip oscillator clock operation control
   Clock operation status control register(CSC)
   MIOEN
 0 : The middle-speed on-chip oscillator is stopped.
 1 : The middle-speed on-chip oscillator runs.
*/
#define BSP_CFG_MOCO_SOURCE (0) /* Generated value. Do not edit this manually */

/* Main on-chip oscillator clock(fOCO) operation control
   System clock control register(CKC)
   MCM1
 0 : High-speed on-chip oscillator clock
 1 : Middle-speed on-chip oscillator clock
*/
#define BSP_CFG_OCOCLK_SOURCE (0) /* Generated value. Do not edit this manually */

/* Main system clock(fMAIN) operation control
   System clock control register(CKC)
   MCM0
 0 : Selects the main on-chip oscillator clock(fOCO) as the main system clock(fMAIN)
 1 : Selects the high-speed system clock(fMX) as the main system clock(fMAIN)
*/
#define BSP_CFG_MAINCLK_SOURCE (0) /* Generated value. Do not edit this manually */

/* Selection of the subsystem clock X or low-speed on-chip oscillator clock
   Subsystem clock select register(CKSEL)
   SELLOSC
 0 : Subsystem clock X
 1 : Low-speed on-chip oscillator clock
*/
#define BSP_CFG_SUBSYSCLK_SOURCE (0) /* Generated value. Do not edit this manually */

/* Selection of the CPU/peripheral hardware clock(fCLK)
   System clock control register(CKC)
   CSS
 0 : Main system clock(fMAIN)
 1 : Subsystem clock(fSUB)
*/
#define BSP_CFG_FCLK_SOURCE (0) /* Generated value. Do not edit this manually */

/* Selection of the oscillation mode of the XT1 oscillator
   Clock operation mode control register(CMC)
   AMPHS1, AMPHS0
 0 : Low power consumption oscillation 1(default)
 1 : Normal oscillation
 2 : Low power consumption oscillation 2
 3 : Low power consumption oscillation 3
*/
#define BSP_CFG_XT1_OSCMODE (0) /* Generated value. Do not edit this manually */

/* Input clock frequency in Hz(High-speed system clock(X1))
*/
#define BSP_CFG_FMX_HZ (5000000) /* Generated value. Do not edit this manually */

/* Control of X1 clock oscillation frequency
   Clock operation mode control register(CMC)
   AMPH
 0 : 1 MHz <= fX <= 10 MHz
 1 : 10 MHz < fX <= 20 MHz
 Set the value corresponding to the setting of BSP_CFG_FMX_HZ
*/

/* CPU/peripheral hardware clock frequency in Hz
   (The frequency set when code generation is executed)
*/
#define BSP_CFG_FCLK_HZ (32000000) /* Generated value. Do not edit this manually */

/* Selection of the oscillation stabilization time
   Oscillation stabilization time select register(OSTS)
   OSTS2, OSTS1, OSTS0
 0 : 2^8/fX(fX = 10MHz : 25.6us, fX = 20MHz : 12.8us)
 1 : 2^9/fX(fX = 10MHz : 51.2us, fX = 20MHz : 25.6us)
 2 : 2^10/fX(fX = 10MHz : 102us, fX = 20MHz : 51.2us)
 3 : 2^11/fX(fX = 10MHz : 204us, fX = 20MHz : 102us)
 4 : 2^13/fX(fX = 10MHz : 819us, fX = 20MHz : 409us)
 5 : 2^15/fX(fX = 10MHz : 3.27ms, fX = 20MHz : 1.63ms)
 6 : 2^17/fX(fX = 10MHz : 13.1ms, fX = 20MHz : 6.55ms)
 7 : 2^18/fX(fX = 10MHz : 26.2ms, fX = 20MHz : 13.1ms)
*/
#define BSP_CFG_X1_WAIT_TIME_SEL (7) /* Generated value. Do not edit this manually */

/* Setting in STOP mode or in HALT mode while the CPU is opeating with subsystem clock X.
   Subsystem clock supply mode control register(OSMC)
   RTCLPC
 0 : Enables supply of subsystem clock X to peripheral functions.
 1 : Stops supply of the subsystem clock to peripheral functions other than the realtime clock.
*/
#define BSP_CFG_ALLOW_FSUB_IN_STOPHALT (0) /* Generated value. Do not edit this manually */

/* Selection of the operating clock for the realtime clock, 32-bit interval timer,
   serial interfaces UARTA0 and UARTA1, remote control signal receiver,
   and clock output/buzzer output controller
   Subsystem clock supply mode control register(OSMC)
   WUTMMCK0
 0 : Subsystem clock X
 1 : Low-speed on-chip oscillator clock
*/
#define BSP_CFG_RTC_OUT_CLK_SOURCE (0) /* Generated value. Do not edit this manually */

/* Selection of the high-speed on-chip oscillator clock frequency
   High-speed on-chip oscillator frequency select register(HOCODIV)
   HOCODIV2, HOCODIV1, HOCODIV0
 (FRQSEL3 = 0)
 0                : fIH = 24MHz
 1                : fIH = 12MHz
 2                : fIH = 6MHz
 3                : fIH = 3MHz
 Other than above : Setting prohibited
 (FRQSEL3 = 1)
 0                : fIH = 32MHz
 1                : fIH = 16MHz
 2                : fIH = 8MHz
 3                : fIH = 4MHz
 4                : fIH = 2MHz
 5                : fIH = 1MHz
 Other than above : Setting prohibited
*/
#define BSP_CFG_HOCO_DIVIDE (0) /* Generated value. Do not edit this manually */

/* Setting for starting the high-speed on-chip oscillator at the times of release from STOP mode
   and of transitions to SNOOZE mode
   Standby mode release setting register(WKUPMD)
   FWKUP
 0 : Starting of the high-speed on-chip oscillator is at normal speed.
 1 : Starting of the high-speed on-chip oscillator is at high speed.
*/
#define BSP_CFG_WAKEUP_MODE (0) /* Generated value. Do not edit this manually */

/* Selected division ratio for the high-speed system clock
   High-speed system clock division register(MOSCDIV)
   MOSCDIV2, MOSCDIV1, MOSCDIV0
 0                : fMX(fMX = 20MHz : 20MHz)
 1                : fMX/2(fMX = 20MHz : 10MHz)
 2                : fMX/4(fMX = 20MHz : 5MHz)
 3                : fMX/8(fMX = 20MHz : 2.5MHz)
 4                : fMX/16(fMX = 20MHz : 1.25MHz)
 Other than above : Setting prohibited
*/
#define BSP_CFG_MOSC_DIVIDE (0) /* Generated value. Do not edit this manually */

/* Selection of the middle-speed on-chip oscillator clock frequency
   Middle-speed on-chip oscillator frequency select register(MOCODIV)
   MOCODIV1, MOCODIV0
 0                : 4MHz
 1                : 2MHz
 2                : 1MHz
 Other than above : Setting prohibited
*/
#define BSP_CFG_MOCO_DIVIDE (0) /* Generated value. Do not edit this manually */

/* Operation setting at initial setting */
/* Starts the high-speed on-chip oscillator at initialization
 0 : Stops the high-speed on-chip oscillator at initialization
 1 : Starts the high-speed on-chip oscillator at initialization
*/
#define BSP_CFG_FIH_START_ON_STARTUP (1) /* Generated value. Do not edit this manually */

/* This macro lets other modules no if a RTOS is being used.
 0 = RTOS is not used.
 1 = FreeRTOS is used.
 2 = embOS is used.(This is not available.)
 3 = MicroC_OS is used.(This is not available.)
 4 = Renesas ITRON is used.
 (Note)
   Set the same value to BSP_CFG_ASM_RTOS_USED in r_bsp_config.inc.
*/
#define BSP_CFG_RTOS_USED               (0)

/* Loop count using the main system clock. */
/* The loop count refers to a loop consisting of a "for" statement that executes a single NOP instruction.
   The loop count values are just example.
   Since the actual number of cycles will differ according to factors such as the optimization option,
   you will need to specify a setting that matches your environment. */

/* Subsystem clock oscillation stabilization time.
   If the main system clock is 32 MHz, 805000 means 301.78 ms. */
#define BSP_CFG_SUBWAITTIME              (805000U)

/* High-speed on-chip oscillator clock stabilization time.
   If the main system clock is 32 MHz, 30 means 5.64 us.
    Required wait time : 5 us.
    Referenced Users Manual version : Rev.1.30 */
#define BSP_CFG_FIHWAITTIME              (30U)

/* Middle-speed on-chip oscillator clock stabilization time.
   If the main system clock is 32 MHz, 6 means 1.15us.
    Required wait time : 1 us.
    Referenced Users Manual version : Rev.1.30 */
#define BSP_CFG_FIMWAITTIME              (6U)

/* Low-speed on-chip oscillator clock stabilization time.
   If the main system clock is 32 MHz, 450 means 84.36us.
    Required wait time : 80 us.
    Referenced Users Manual version : Rev.1.30 */
#define BSP_CFG_FILWAITTIME              (450U)

/* If the user would like to determine if a warm start reset has occurred, then they may enable one or more of the
   following callback definitions AND provide a call back function name for the respective callback
   function (to be defined by the user). Setting BSP_CFG_USER_WARM_START_CALLBACK_PRE_INITC_ENABLED = 1 will result
   in a callback to the user defined my_sw_warmstart_prec_function just prior to the initialization of the C
   runtime environment by bsp_init_system.
   Setting BSP_CFG_USER_WARM_START_CALLBACK_POST_INITC_ENABLED = 1 will result in a callback to the user defined
   my_sw_warmstart_postc_function just after the initialization of the C runtime environment by bsp_init_hardware.
*/
#define BSP_CFG_USER_WARM_START_CALLBACK_PRE_INITC_ENABLED    (0)
#define BSP_CFG_USER_WARM_START_PRE_C_FUNCTION                my_sw_warmstart_prec_function

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

