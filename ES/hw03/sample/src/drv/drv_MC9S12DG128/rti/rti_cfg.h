#ifndef RTI_CFG_H
#define RTI_CFG_H
/**************************************************************************
**
** Module Name:   Rti_cfg.h
**
** Module Description:  General Real-Time Interrupt configuration file.
**
***************************************************************************
**
**  Author:      Benjamin Sweet
**  Revision:    1.0
**  Date:        22-Apr-2012
**
***************************************************************************
**
** Re: S12ATD10B8CV2.pdf, Freescale
**     ATD_10B8C Block User Guide — V02.12
**
***************************************************************************
** Revision History:
**
** Revision: 1.0    22-Apr-2012   Benjamin Sweet
** * Original version based on existing methods in general use, and specific
**   work by Justin Michrina and Richard Slindee.
** * Re: S12CRGV4 - CRG Block User Guide
**       AN2882 - Using Real-Time Interrupt on HCS12 Microcontrollers
**
**************************************************************************/

/*
** RTI Configuration Masks and Values:
*/

/*
** Based on sample code in AN2882 - Using Real-Time Interrupt on HCS12 Microcontrollers:
**
** RTICTL: Setup of the RTI interrupt frequency, adjusted to get
**  1.024 ms with 8 MHz crystal oscillator
**
** RTI frequency = 8 MHz/(8x2^10) = 976.5625 Hz
** Period of time between interrupts = 1/976.5625 Hz = 1.024 ms
*/
#define RTICTL_INIT_MASK_MODULUS   ((uint8_t)0x07)  /* 0b00000111           */
/*                                                       |||||||0\  RTR0    = 1 \ RTR[3:0] — Real Time Interrupt Modulus Counter Select Bits:
**                                                       ||||||1 / RTR1     = 1 |  These bits select the modulus counter target value to provide additional granularity.
**                                                       |||||2 / RTR2      = 1 |   0111 -> 8*2^x  RTI Interrupt Modulus Counter 
**                                                       ||||3_/ RTR3       = 0 /     [Modulus = RTR[3:0] value + 1 ]
*/
#define RTICTL_INIT_MASK_PRESCALE  ((uint8_t)0x10)  /* 0b00010000           */
/*                                                       |||4\  RTR4        = 1 \ RTR[6:4] — Real Time Interrupt Prescale Rate Select Bits:
**                                                       ||5 / RTR5         = 0 |  These bits select the prescale rate for the RTI.
**                                                       |6_/ RTR6          = 0 /   001 -> 2^10  RTI Interrupt Prescale rate  [Prescale := 2^(9+RTR[6:4] value) if value > 0, else off]
**                                                       7 =                = 0 - reserved
*/

#endif /* RTI_CFG_H */
