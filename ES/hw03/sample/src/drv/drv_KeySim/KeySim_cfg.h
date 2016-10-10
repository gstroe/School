#ifndef KEYSIM_CFG_H
#define KEYSIM_CFG_H
/**************************************************************************
**
** Module Name:   KeySim_cfg.h
**
** Module Description:  KeySim component configuration file.
**  Define constants and macros for KeySim configuration and Access.
**
***************************************************************************
**
**  Author:      Benjamin Sweet
**  Revision:    1.1
**  Date:        30-Jun-2012
**
***************************************************************************
**
** Revision History:
**
** Revision: 1.1   30-Jun-2012    B. Sweet
** * Correct data type for extern'd registers (should be UN-signed.)
**
** Revision: 1.0   29-May-2012    B. Sweet
** * Original version based on existing methods in general use.
**
**************************************************************************/

/*
** Signal Definitions:
*/
#define USER_INPUT      (1)

#if(0)  // Examples...
#define ANOTHER_INPUT   (2)
#define YET_ANOTHER_IN  (3)
#endif

/*
** KeySim simulated microcontroller registers:
**  Defined in KeySim_cfg.c
*/

/*
** Digital Input & Output (DIO) Ports:
**  General Purpose Input/Output (GPIO)
*/
    extern volatile uint8_t      GPIO_Port_00_Data;      /* General Purpose Input/Output Port: 0x00 - Data Register              */
    extern volatile uint8_t      GPIO_Port_00_Dir;       /* General Purpose Input/Output Port: 0x00 - Data Direction Register    */

    extern volatile uint8_t      GPIO_Port_01_Data;      /* General Purpose Input/Output Port: 0x01 - Data Register              */
    extern volatile uint8_t      GPIO_Port_01_Dir;       /* General Purpose Input/Output Port: 0x01 - Data Direction Register    */

    extern volatile uint8_t      GPIO_Port_02_Data;      /* General Purpose Input/Output Port: 0x02 - Data Register              */
    extern volatile uint8_t      GPIO_Port_02_Dir;       /* General Purpose Input/Output Port: 0x02 - Data Direction Register    */

    extern volatile uint8_t      GPIO_Port_03_Data;      /* General Purpose Input/Output Port: 0x03 - Data Register              */
    extern volatile uint8_t      GPIO_Port_03_Dir;       /* General Purpose Input/Output Port: 0x03 - Data Direction Register    */

/*
** Analog to Digital (ADC) Input Channels:
*/
    extern volatile uint16_t     ADC_Channel_00;         /* Analog to Digital Conversion Input Channel: 0x00 - Result Register   */
    extern volatile uint16_t     ADC_Channel_01;         /* Analog to Digital Conversion Input Channel: 0x01 - Result Register   */
    extern volatile uint16_t     ADC_Channel_02;         /* Analog to Digital Conversion Input Channel: 0x02 - Result Register   */
    extern volatile uint16_t     ADC_Channel_03;         /* Analog to Digital Conversion Input Channel: 0x03 - Result Register   */
    extern volatile uint16_t     ADC_Channel_04;         /* Analog to Digital Conversion Input Channel: 0x04 - Result Register   */
    extern volatile uint16_t     ADC_Channel_05;         /* Analog to Digital Conversion Input Channel: 0x05 - Result Register   */
    extern volatile uint16_t     ADC_Channel_06;         /* Analog to Digital Conversion Input Channel: 0x06 - Result Register   */
    extern volatile uint16_t     ADC_Channel_07;         /* Analog to Digital Conversion Input Channel: 0x07 - Result Register   */

#endif /* KEYSIM_CFG_H */
