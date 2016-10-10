#ifndef MCU_CFG_H
#define MCU_CFG_H
/**************************************************************************
**
** Module Name:   Mcu_cfg.h
**
** Module Description:  General Microcontroller configuration file.
**  Define constants and macros for Overall Microcontroller configuration and Access.
**
***************************************************************************
**
**  Author:      Ben Sweet
**  Revision:    1.0
**  Date:        06-Jun-2012
**
***************************************************************************
**
** Revision History:
**
** Revision: 1.0   06-Jun-2012    Ben Sweet
** * Original version based on existing methods in general use.
**
**************************************************************************/

/*
** Values for MCU configuration:  
*/
#define CCR_MASK_I  (0x10)
/*                          0b00010000
**                            |||||||0 = C   = Carry/Borrow status bit
**                            ||||||1 = V    = Two’s complement overflow status bit
**                            |||||2 = Z     = Zero status bit
**                            ||||3 = N      = Negative status bit
**                            |||4 = I       = Maskable interrupt control bit
**                            ||5 = H        = Half-carry status bit 
**                            |6 = X         = Non-maskable interrupt control bit
**                            7 = S          = STOP instruction control bit
*/


/*
** Macro Definitions:
*/
#define Mcu_InterruptEnable()   {_asm("cli")}   /* Unconditionally Clear the I-bit in CCR to Enable  interrupts. */
#define Mcu_InterruptDisable()  {_asm("sei")}   /* Unconditionally Set   the I-bit in CCR to Disable interrupts. */



#endif /* MCU_CFG_H */
