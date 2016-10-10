/*************************************************************************
 * Copyright (C) 2006 by Freescale Semiconductor Inc. All rights reserved*
 *************************************************************************
 *                                                                       *
 *   Freescale reserves the right to make changes without further notice *
 *   to any product herein to improve reliability, function or design.   *
 *   Freescale does not assume any liability arising out of the          *
 *   application or use of any product, circuit, or software described   *
 *   herein; neither does it convey any license under its patent rights  *
 *   nor the rights of others.                                           *
 *                                                                       *
 *   Freescale products are not designed, intended, or authorized for    *
 *   use as components in systems intended for surgical implant into     *
 *   the body, or other applications intended to support life, or for    *
 *   any other application in which the failure of the Motorola product  *
 *   could create a situation where personal injury or death may occur.  *
 *                                                                       *
 *   Should Buyer purchase or use Freescale products for any such        *
 *   unintended or unauthorized application, Buyer shall indemnify and   *
 *   hold Freescale and its officers, employees, subsidiaries,           *
 *   affiliates, and distributors harmless against all claims costs,     *
 *   damages, and expenses, and reasonable attorney fees arising out     *
 *   of, directly or indirectly, any claim of personal injury or death   *
 *   associated with such unintended or unauthorized use, even if such   *
 *   claim alleges that Freescale was negligent regarding the design     *
 *   or manufacture of the part.                                         *
 *                                                                       *
 *   Freescale and the Freescale logo* are registered trademarks of      *
 *   Freescale Inc.                                                      *
 *                                                                       *
 *************************************************************************/

/*************************************************************************
 *                                                                       *
 *                  Freescale S12UB Stand Alone                          *
 *                 Target Circuitry Test Software                        *
 *                                                                       *
 *************************************************************************/
 
 /************************** HARDWARE  CHANGES ***************************
 VERSION: O (Original) RELEASE DATE: January 06, 2006 Design Engineer: BB
 RELEASE NOTES:
 
 Original version. 
 
 O version is prototype build release.                                 
  
 *************************************************************************/

 /************************** SOFTWARE  CHANGES ***************************
 VERSION: 1.0.0	       RELEASE DATE: January 06, 2006         Author: BB
 RELEASE NOTES:
 
 Initial Version. 
 
 This program was written to test the S12UB Target circuitry before
 release to customer. Also this program can be used as a C programming
 example when using the Codewarrior tool suite.                                 
  
 VERSION: 1.0.1	       RELEASE DATE: July 10, 2006            Author: BB
 RELEASE NOTES:
 
 Modify operating mode out of reset. 
 
 Initial Version immediately started LED blink and Piezo sound. This is
 potentially distracting upon first powerup. Operation modified to remain
 idle until SW5 depressed. After SW5 pressed first test is entered.             
  
 *************************************************************************/

#pragma CODE_SEG DEFAULT	//Always reset to DEFAULT segment


#include "main.h"
#include "projectdefines.h"    // Microcontroller register access
#include "projectglobals.h"  // All global variables

void main ()
{

  int_disable();		// Disable interrupts
  xirq_disabled();  // Disable XIRQ interrupt
  
  init_VARS();      // Init variables
  
  init_CPU();				// Init CPU Registers (Core control)
  
  init_PWM();       // Init PWM channels
  
  init_ATD0();      // Init ATD0
  
  init_ATD1();      // Init ATD0

  init_PORTH();			// Init Port H
  
  init_PORTT();			// Init Port T
  
  init_SPI0();      // Init SPI0
  
  init_SCI0();      // Init SCI0
  
  init_SCI1();      // Init SCI1  
  
  init_CRG();       // Initialize CRG as last init for first RTI (OS int)
  
  int_enable();     // Enable interrupts
	
	for (;;);         // Spin forever
}

//************************************************************************

void init_CRG(void)  // Initialize CRG
{

	Crg.copctl.byte = 0x40;   // COP disabled. RTI off in active BDM.
	Crg.crgflg.bit.rtif = 1;  // Clear interrupt bit 
	Crg.crgint.byte = 0x80;		// Enable RTI interrupt
	Crg.rtictl.byte = 0x5B;   // RTI every 24.576ms, Start counter.
	  

} // END init_CRG

//************************************************************************

void init_CPU(void)  // Initialize MEBI
{

  //Regs.porta.byte = 0x00; // Write zeros before enabling the port
  Regs.porta.byte = 0x01; // Write zeros before enabling the port
  Regs.ddra.byte = 0xFF;  // Port A is output port
  Regs.ddrb.byte = 0x00;  // Port B is input port 
  Regs.ddre.byte = 0x00;  // Port E is input port
  
  Page.ddrk.byte = 0x00;  // Port K is input port make input before setting pucr
   
  Regs.pucr.byte = 0x80;  // Port K pullups enabled
  Regs.rdriv.byte = 0x00; // No reduced drive
  Regs.irqcr.byte = 0x00; // No IRQ
  
} // END init_CPU

//************************************************************************

void init_ATD0(void)  // Initialize ATD0 Mode input port 
{

  Atd0.atdctl4.byte = 0xE1;  // Set A/D prescaler clock
  Atd0.atdctl2.byte = 0x80;  // Power up ATD0
  Atd0.atddien0.byte = 0xFF; // Enable digital input port on ATD0
  
} // END init_ATD0

//************************************************************************

void init_ATD1(void)  // Initialize ATD1 Analog inputs
{

  Atd1.atdctl4.byte = 0xE1;  // Set A/D prescaler clock 8 bit convertions
  Atd1.atdctl2.byte = 0x80;  // Power up ATD1
  Atd1.atdctl3.byte = 0x43;  // Full scan sequence
  Atd1.atdctl5.byte = 0x90;  // Full scan sequence
  
  
} // END init_ATD1

//************************************************************************

void init_PORTH(void)  // Initialize port H 
{

  Pim.pth.byte = 0x36; // Init output value
  Pim.ddrh.byte = 0xFF; // PortH output port
  
} // END init_PORTH

//************************************************************************

void init_PORTT(void)  // Initialize port T 
{

  Pim.ddrt.byte = 0x00; // PortH input port
  
} // END init_PORTT

//************************************************************************

void init_SPI0(void)  // Initialize SPI0
{

  Spi0.spibr.byte = 0x01; // 1 MHz SPI bus
  Spi0.spicr2.byte = 0x00;
  Spi0.spicr1.byte = 0x54; 
  
  
} // END init_SPI0

//************************************************************************

void init_SCI0(void)  // Initialize SCI0
{

  Sci0.scibd.byte.msb.byte = 0x00; // 9600 Baud
  Sci0.scibd.byte.lsb.byte = 0x1A;
  Sci0.scicr1.byte = 0x00;
  Sci0.scicr2.byte = 0x0C;
  
} // END init_SCI0

//************************************************************************

void init_SCI1(void)  // Initialize SCI1
{

  Sci1.scibd.byte.msb.byte = 0x00; // 9600 Baud
  Sci1.scibd.byte.lsb.byte = 0x1A;
  Sci1.scicr1.byte = 0x00;
  Sci1.scicr2.byte = 0x0C;
  
} // END init_SCI1

//************************************************************************

void init_VARS(void)  // Initialize Variables
{

  rti_blink_off_cnt = 0x00; // Init count to zero
  rti_blink_on_cnt = 0x00;  // Init count to zero
  
  ucCST = 0x00;             // Init control state
  ucFLAG1 = 0x00;
  ucFLAG2 = 0x00;
  

} // END init_VARS

//************************************************************************

void init_PWM(void) // Initialize PWM
{

  Pwm.pwmprclk.byte = 0x50; // Clock B = bus/
  Pwm.pwmpol.byte = 0xFF; // High polarity at beginning
  Pwm.pwmdty[7].byte = 0x7F; // 50% Duty Cycle 
  Pwm.pwmdty[3].byte = 0x7F; // 50% Duty Cycle 
  Pwm.pwme.byte = 0x00; // Channel 7 an 3 inactive

} // END init_PWM

//************************************************************************

