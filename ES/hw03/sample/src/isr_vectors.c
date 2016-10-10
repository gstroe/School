/*
** Originally downloaded from http://www.mecheng.adelaide.edu.au/robotics/wpage.php?wpage_id=56
** Sample Programs, Simple timer (TOC7), "myTimer.zip"
**
** 22-Apr-2012    Benjamin Sweet
** * Added vector for RTI_ISR.
**
** 21-Jul-2007    Ben Sweet
** Modified for mc9s12dg128 derivative.
**   Re: 9S12DT128DGV2.pdf, Table 5-1 Interrupt Vector Locations
** * Add IC5_ISR
*/

/*
**  #include header files for component access:
*/
#include "drv\drv_MC9S12DG128\rti\rti.h"

 /* not currently used: TOC7_ISR, IC5_ISR */

extern void near _Startup(void);       /* Startup routine */

#pragma CODE_SEG __NEAR_SEG NON_BANKED /* Interrupt section for this module. Placement will be in NON_BANKED area. */
__interrupt void UnimplementedISR(void)
{
   /* Unimplemented ISRs trap.*/
   asm BGND;
}

typedef void (*near tIsrFunc)(void);
const tIsrFunc _vect[] @0xFF80 = {     /* Interrupt table */
        UnimplementedISR,                 /* vector 0x40 */
        UnimplementedISR,                 /* vector 0x3F */
        UnimplementedISR,                 /* vector 0x3E */
        UnimplementedISR,                 /* vector 0x3D */
        UnimplementedISR,                 /* vector 0x3C */
        UnimplementedISR,                 /* vector 0x3B */
        UnimplementedISR,                 /* vector 0x3A */
        UnimplementedISR,                 /* vector 0x39 */
        UnimplementedISR,                 /* vector 0x38 */
        UnimplementedISR,                 /* vector 0x37 */
        UnimplementedISR,                 /* vector 0x36 (PWM Emergency Shutdown) */
        UnimplementedISR,                 /* vector 0x35 (Port P Interrupt) */
        UnimplementedISR,                 /* vector 0x34 (CAN4 Transmit) */
        UnimplementedISR,                 /* vector 0x33 (CAN4 Receive)  */
        UnimplementedISR,                 /* vector 0x32 (CAN4 Errors)   */
        UnimplementedISR,                 /* vector 0x31 (CAN4 Wake-Up)  */
        UnimplementedISR,                 /* vector 0x30 (Reserved) */
        UnimplementedISR,                 /* vector 0x2F (BF General)         */
        UnimplementedISR,                 /* vector 0x2E (BF Synchronization) */
        UnimplementedISR,                 /* vector 0x2D (BF Receive)         */
        UnimplementedISR,                 /* vector 0x2C (BF Receive FIFO Not Empty) */
        UnimplementedISR,                 /* vector 0x2B (CAN1 Transmit) */
        UnimplementedISR,                 /* vector 0x2A (CAN1 Receive)  */
        UnimplementedISR,                 /* vector 0x29 (CAN1 Errors)   */
        UnimplementedISR,                 /* vector 0x28 (CAN1 Wake-Up)  */
        UnimplementedISR,                 /* vector 0x27 (CAN0 Transmit) */
        UnimplementedISR,                 /* vector 0x26 (CAN0 Receive)  */
        UnimplementedISR,                 /* vector 0x25 (CAN0 Errors)   */
        UnimplementedISR,                 /* vector 0x24 (CAN0 Wake-Up)  */
        UnimplementedISR,                 /* vector 0x23 (FLASH) */
        UnimplementedISR,                 /* vector 0x22 (EEPROM) */
        UnimplementedISR,                 /* vector 0x21 (Reserved) */
        UnimplementedISR,                 /* vector 0x20 (SPI1) */
        UnimplementedISR,                 /* vector 0x1F (IIC Bus) */
        UnimplementedISR,                 /* vector 0x1D (BDLC) */
        UnimplementedISR,                 /* vector 0x1C (CRG PLL Lock) */
        UnimplementedISR,                 /* vector 0x1B (Pulse Accumulator B Overflow) */
        UnimplementedISR,                 /* vector 0x1A (Modulus Down Counter Underflow) */
        UnimplementedISR,                 /* vector 0x19 (PORT H) */
        UnimplementedISR,                 /* vector 0x18 (PORT J) */
        UnimplementedISR,                 /* vector 0x17 (ATD1) */
        UnimplementedISR,                 /* vector 0x16 (ATD0) */
        UnimplementedISR,                 /* vector 0x15 (SCI1) */
        UnimplementedISR,                 /* vector 0x14 (SCI0) */
        UnimplementedISR,                 /* vector 0x13 (SPI0) */
        UnimplementedISR,                 /* vector 0x12 (Pulse Accumulator Input Edge)  */
        UnimplementedISR,                 /* vector 0x11 (Pulse Accumulator A Overflow)  */
        UnimplementedISR,                 /* vector 0x10 (TOF, timer overflow interrupt) */
        UnimplementedISR,                 /* vector 0x0F (C7I, timer interrupt channel 7)  */
        UnimplementedISR,                 /* vector 0x0E (C6I, timer interrupt channel 6)  */
        UnimplementedISR,                 /* vector 0x0D (C5I, timer interrupt channel 5)  */
        UnimplementedISR,                 /* vector 0x0C (C4I, timer interrupt channel 4)  */
        UnimplementedISR,                 /* vector 0x0B (C3I, timer interrupt channel 3)  */
        UnimplementedISR,                 /* vector 0x0A (C2I, timer interrupt channel 2)  */
        UnimplementedISR,                 /* vector 0x09 (C1I, timer interrupt channel 1)  */
        UnimplementedISR,                 /* vector 0x08 (C0I, timer interrupt channel 0)  */
        RTI_Isr,                          /* vector 0x07 (RTIE - Real-Time Interrupt) */
        UnimplementedISR,                 /* vector 0x06 (IRQ)  */
        UnimplementedISR,                 /* vector 0x05 (XIRQ - External Interrupt) */
        UnimplementedISR,                 /* vector 0x04 (SWI - Software Interrupt)  */
        UnimplementedISR,                 /* vector 0x03 (Unimplemented Opcode Trap) */
        UnimplementedISR,                 /* vector 0x02 (COP Watchdog Reset)        */
        UnimplementedISR,                 /* vector 0x01 (Clock Monitor Reset)       */
        _Startup                          /* vector 0x00 (Power-On/Staru-Up RESET)   */
   };

