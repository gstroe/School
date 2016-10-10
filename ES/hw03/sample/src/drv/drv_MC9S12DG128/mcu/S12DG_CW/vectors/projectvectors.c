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
 
/******************************************************************************
*                                                
* FILE NAME: projectvectors.c                                             
*                                                                           
* PURPOSE: source file which includes all Dx128 (L40K) interrupt handlers
*		     							 
*                                                                           
* DESCRIPTION:  project vectors (interrupt handlers)        
*                                                                           
* NOTE: Interrupt vectors must point to fixed paged address. From the fixed
* 		routine a call can redirect to paged memory. 
*                                                                           
* AUTHOR: r9aabe    LOCATION: Austin,TX     LAST EDIT DATE: 05/12/03
*                                                                                             
******************************************************************************/

/*Include files */

#include "projectvectors.h"
#include "projectdefines.h"
#include "projectglobals.h"  // All global variables


/*Warning Disable*/

#pragma MESSAGE DISABLE C12004		//Warning: Far Keyword ignored for Function

/*Local Prototypes*/

void software_trap(void);

//************************************************************************
// SOFTWARE TRAP FUNCTION
// DESCRIPTION:
// Function that traps  all unexpected interrupts.  Used for debugging 
// software to find runaway code.
//
        
void software_trap(void){ for(;;); }

//************************************************************************
// UNUSED ISR
// DESCRIPTION:
// Takes place of undefined vectors. 
// Used for reserved vector spaces
//
#pragma CODE_SEG NON_BANKED        
interrupt void unused_isr(void){ (void) software_trap(); }
#pragma CODE_SEG DEFAULT

//************************************************************************
// PWM SHUTDOWN ISR
// DESCRIPTION:
// Interrupt asserted at the beginning of emergency shutdown initiated 
// on PWM7. PWM pin state will default and interrupt taken.
//
#pragma CODE_SEG NON_BANKED        
interrupt void pwm_shutdown_isr(void){ (void) software_trap(); }
#pragma CODE_SEG DEFAULT

//************************************************************************
// PORTP ISR
// DESCRIPTION:
// Interrupt asserted on a PORTP per pin basis, rising or falling edge. 
// Triggered by input transistion and stored as a flag.
//
#pragma CODE_SEG NON_BANKED 
interrupt void portp_isr(void){ (void) software_trap(); }
#pragma CODE_SEG DEFAULT

//************************************************************************
// MSCAN4 TRANSMIT ISR
// DESCRIPTION:
// Interrupt asserted when at least one of three transmit buffers empty. 
// 
//
#pragma CODE_SEG NON_BANKED 
interrupt void mscan4_tx_isr(void){ (void) software_trap(); }
#pragma CODE_SEG DEFAULT

//************************************************************************
// MSCAN4 RECEIVE ISR
// DESCRIPTION:
// Interrupt asserted when a message has been received and shifted into 
// the forground buffer of the receiver FIFO.
//
#pragma CODE_SEG NON_BANKED 
interrupt void mscan4_rx_isr(void){ (void) software_trap(); }
#pragma CODE_SEG DEFAULT

//************************************************************************
// MSCAN4 ERROR ISR
// DESCRIPTION:
// Interrupt asserted when overrun, error or warning on the receive buffer. 
// 
//
#pragma CODE_SEG NON_BANKED 
interrupt void mscan4_error_isr(void){ (void) software_trap(); }
#pragma CODE_SEG DEFAULT

//************************************************************************
// MSCAN4 WAKEUP ISR
// DESCRIPTION:
// Interrupt asserted with CAN activity during MSCAN internal sleep. 
// 
//
#pragma CODE_SEG NON_BANKED 
interrupt void mscan4_wakeup_isr(void){ (void) software_trap(); }
#pragma CODE_SEG DEFAULT

//************************************************************************
// MSCAN1 TRANSMIT ISR
// DESCRIPTION:
// Interrupt asserted when at least one of three transmit buffers empty.
//
#pragma CODE_SEG NON_BANKED
interrupt void mscan1_tx_isr(void){ (void) software_trap(); }
#pragma CODE_SEG DEFAULT

//************************************************************************
// MSCAN1 RECEIVE ISR
// DESCRIPTION:
// Interrupt asserted when a message has been received and shifted into 
// the forground buffer of the receiver FIFO.
//
#pragma CODE_SEG NON_BANKED
interrupt void mscan1_rx_isr(void){ (void) software_trap(); }
#pragma CODE_SEG DEFAULT

//************************************************************************
// MSCAN1 ERROR ISR
// DESCRIPTION:
// Interrupt asserted when overrun, error or warning on the receive buffer.
//
#pragma CODE_SEG NON_BANKED
interrupt void mscan1_error_isr(void){ (void) software_trap(); }
#pragma CODE_SEG DEFAULT

//************************************************************************
// MSCAN1 WAKEUP ISR
// DESCRIPTION:
// Interrupt asserted with CAN activity during MSCAN internal sleep.
//
#pragma CODE_SEG NON_BANKED
interrupt void mscan1_wakeup_isr(void){ (void) software_trap(); }
#pragma CODE_SEG DEFAULT

//************************************************************************
// MSCAN0 TRANSMIT ISR
// DESCRIPTION:
// Interrupt asserted when at least one of three transmit buffers empty.
//
#pragma CODE_SEG NON_BANKED
interrupt void mscan0_tx_isr(void){ (void) software_trap(); }
#pragma CODE_SEG DEFAULT

//************************************************************************
// MSCAN0 RECEIVE ISR
// DESCRIPTION:
// Interrupt asserted when a message has been received and shifted into 
// the forground buffer of the receiver FIFO.
//
#pragma CODE_SEG NON_BANKED
interrupt void mscan0_rx_isr(void){ (void) software_trap(); }
#pragma CODE_SEG DEFAULT

//************************************************************************
// MSCAN0 ERROR ISR
// DESCRIPTION:
// Interrupt asserted when overrun, error or warning on the receive buffer.
//
#pragma CODE_SEG NON_BANKED
interrupt void mscan0_error_isr(void){ (void) software_trap(); }
#pragma CODE_SEG DEFAULT

//************************************************************************
// MSCAN0 WAKEUP ISR
// DESCRIPTION:
// Interrupt asserted with CAN activity during MSCAN internal sleep.
//
#pragma CODE_SEG NON_BANKED
interrupt void mscan0_wakeup_isr(void){ (void) software_trap(); }
#pragma CODE_SEG DEFAULT

//************************************************************************
// FLASH ISR
// DESCRIPTION:
// Interrupt asserted upon command completion or the address, data or  
// command buffers are empty.
//
#pragma CODE_SEG NON_BANKED
interrupt void flash_isr(void){ (void) software_trap(); }
#pragma CODE_SEG DEFAULT

//************************************************************************
// EEPROM ISR
// DESCRIPTION:
// Interrupt asserted upon command completion or the command buffers 
// are empty.
//
#pragma CODE_SEG NON_BANKED
interrupt void eeprom_isr(void){ (void) software_trap(); }
#pragma CODE_SEG DEFAULT

//************************************************************************
// SPI1 ISR
// DESCRIPTION:
// Interrupt asserted when SPIF or MODF flags set.
//
#pragma CODE_SEG NON_BANKED
interrupt void spi1_isr(void){ (void) software_trap(); }
#pragma CODE_SEG DEFAULT

//************************************************************************
// IIC ISR
// DESCRIPTION:
// Interrupt asserted when arbitration lost, byte transfer, or address detect. 
// 
//
#pragma CODE_SEG NON_BANKED
interrupt void iic_isr(void){ (void) software_trap(); }
#pragma CODE_SEG DEFAULT

//************************************************************************
// BDLC ISR
// DESCRIPTION:
// Interrupt asserted by general BDLC interrupt including wakeup. Source
// resolved by register(s) flags.
//
#pragma CODE_SEG NON_BANKED
interrupt void bdlc_isr(void){ (void) software_trap(); }
#pragma CODE_SEG DEFAULT

//************************************************************************
// CRG SELF CLOCK MODE ISR
// DESCRIPTION:
// Interrupt asserted when self clock mode engaged. 
// 
//
#pragma CODE_SEG NON_BANKED
interrupt void crg_scm_isr(void){ (void) software_trap(); }
#pragma CODE_SEG DEFAULT

//************************************************************************
// CRG PLL LOCK CONDITION CHANGED ISR
// DESCRIPTION:
// Interrupt asserted when lock condition of the PLL has changed.
// 
//
#pragma CODE_SEG NON_BANKED
interrupt void crg_pll_lock_isr(void){ (void) software_trap(); }
#pragma CODE_SEG DEFAULT

//************************************************************************
// ECT PULSE ACCUMATATOR B OVERFLOW ISR
// DESCRIPTION:
// Interrupt asserted when pulse accumulator B overflows. 
// 
//
#pragma CODE_SEG NON_BANKED
interrupt void pa_b_overflow_isr(void){ (void) software_trap(); }
#pragma CODE_SEG DEFAULT

//************************************************************************
// ECT MODULUS DOWN COUNTER UNDERFLOW ISR
// DESCRIPTION:
// Interrupt asserted when modulus down counter underflows. 
// 
//
#pragma CODE_SEG NON_BANKED
interrupt void ect_mdc_isr(void){ (void) software_trap(); }
#pragma CODE_SEG DEFAULT

//************************************************************************
// PORTH ISR
// DESCRIPTION:
// Interrupt asserted on PORTH pin edge, saved as a flag. 
// All port pins serviced by one vector.
//
#pragma CODE_SEG NON_BANKED
interrupt void porth_isr(void){ (void) software_trap(); }
#pragma CODE_SEG DEFAULT

//************************************************************************
// PORTJ ISR
// DESCRIPTION:
// Interrupt asserted on PORTJ pin edge, saved as a flag. 
// All port pins serviced by one vector.
//
#pragma CODE_SEG NON_BANKED
interrupt void portj_isr(void){ (void) software_trap(); }
#pragma CODE_SEG DEFAULT

//************************************************************************
// ATD1 SEQUENCE COMPLETE ISR
// DESCRIPTION:
// Interrupt asserted upon completion of ATD1 sequence. 
// 
//
#pragma CODE_SEG NON_BANKED
interrupt void atd1_isr(void){ (void) software_trap(); }
#pragma CODE_SEG DEFAULT

//************************************************************************
// ATD0 SEQUENCE COMPLETE ISR
// DESCRIPTION:
// Interrupt asserted upon completion of ATD0 sequence. 
// 
//
#pragma CODE_SEG NON_BANKED
interrupt void atd0_isr(void){ (void) software_trap(); }
#pragma CODE_SEG DEFAULT

//************************************************************************
// SCI1 ISR
// DESCRIPTION:
// Interrupt asserted from one of five sources. Two transmit and one receive.
// 
//
#pragma CODE_SEG NON_BANKED
interrupt void sci1_isr(void){ (void) software_trap(); }
#pragma CODE_SEG DEFAULT

//************************************************************************
// SCI0 ISR
// DESCRIPTION:
// Interrupt asserted from one of five sources. Two transmit and one receive. 
// 
//
#pragma CODE_SEG NON_BANKED
interrupt void sci0_isr(void){ (void) software_trap(); }
#pragma CODE_SEG DEFAULT

//************************************************************************
// SPI0 ISR
// DESCRIPTION:
// Interrupt asserted from one of three sources. 
// 
//
#pragma CODE_SEG NON_BANKED
interrupt void spi0_isr(void){ (void) software_trap(); }
#pragma CODE_SEG DEFAULT

//************************************************************************
// PULSE ACCUMULATOR A EDGE ISR
// DESCRIPTION:
// Interrupt asserted when edge received on Pulse Accumulator A. 
// 
//
#pragma CODE_SEG NON_BANKED
interrupt void pa_a_edge_isr(void){ (void) software_trap(); }
#pragma CODE_SEG DEFAULT

//************************************************************************
// PULSE ACCUMULATOR A OVERFLOW ISR
// DESCRIPTION:
// Interrupt asserted upon Pulse Accumulator A overflow. 
// 
//
#pragma CODE_SEG NON_BANKED
interrupt void pa_a_overflow_isr(void){ (void) software_trap(); }
#pragma CODE_SEG DEFAULT

//************************************************************************
// ECT OVERFLOW ISR
// DESCRIPTION:
// Interrupt asserted upon ECT main timer overflow. 
// 
//
#pragma CODE_SEG NON_BANKED
interrupt void ect_overflow_isr(void){ (void) software_trap(); }
#pragma CODE_SEG DEFAULT

//************************************************************************
// ECT CH7 ISR
// DESCRIPTION:
// Interrupt asserted upon channel 7 event. 
// 
//
#pragma CODE_SEG NON_BANKED
interrupt void ect_ch7_isr(void){ (void) software_trap(); }
#pragma CODE_SEG DEFAULT

//************************************************************************
// ECT CH6 ISR
// DESCRIPTION:
// Interrupt asserted upon channel 6 event.
// 
//
#pragma CODE_SEG NON_BANKED
interrupt void ect_ch6_isr(void){ (void) software_trap(); }
#pragma CODE_SEG DEFAULT

//************************************************************************
// ECT CH5 ISR
// DESCRIPTION:
// Interrupt asserted upon channel 5 event.
//
//
#pragma CODE_SEG NON_BANKED
interrupt void ect_ch5_isr(void){ (void) software_trap(); }
#pragma CODE_SEG DEFAULT

//************************************************************************
// ECT CH4 ISR
// DESCRIPTION:
// Interrupt asserted upon channel 4 event.
// 
//
#pragma CODE_SEG NON_BANKED
interrupt void ect_ch4_isr(void){ (void) software_trap(); }
#pragma CODE_SEG DEFAULT

//************************************************************************
// ECT CH3 ISR
// DESCRIPTION:
// Interrupt asserted upon channel 3 event.
//
#pragma CODE_SEG NON_BANKED
interrupt void ect_ch3_isr(void){ (void) software_trap(); }
#pragma CODE_SEG DEFAULT

//************************************************************************
// ECT CH2 ISR
// DESCRIPTION:
// Interrupt asserted upon channel 2 event.
// 
//
#pragma CODE_SEG NON_BANKED
interrupt void ect_ch2_isr(void){ (void) software_trap(); }
#pragma CODE_SEG DEFAULT

//************************************************************************
// ECT CH1 ISR
// DESCRIPTION:
// Interrupt asserted upon channel 1 event.
// 
//
#pragma CODE_SEG NON_BANKED
interrupt void ect_ch1_isr(void){ (void) software_trap(); }
#pragma CODE_SEG DEFAULT

//************************************************************************
// ECT CH0 ISR
// DESCRIPTION:
// Interrupt asserted upon channel 0 event.
//
//
#pragma CODE_SEG NON_BANKED
interrupt void ect_ch0_isr(void){ (void) software_trap(); }
#pragma CODE_SEG DEFAULT

//************************************************************************
// REAL TIME ISR
// DESCRIPTION:
// Interrupt asserted when REAL-TIME interrupt period elapses. Operates 
// from OSCCLK.
// 
//
#pragma CODE_SEG NON_BANKED
interrupt void rti_isr(void) /* Interrupt every 24.576ms */
{

/*

This is the main real-time OS interrupt routine. It provides timing control 
and switch debouncing.

*/


/* Software State machine */

switch (ucCST) { 

		case 0: /* Startup idle state toggle LEDs */
	
	  if (rti_blink_on_cnt == 0x08) 
  	{
  //	  Regs.porta.byte = 0xAA;   /* Port A = AA */ 
      if (Regs.porta.byte < 0x80) 
      {
        Regs.porta.byte = Regs.porta.byte << 1;
      }
      else
      {
        Regs.porta.byte = 0x01;
      }
        

  // 	  rti_blink_on_cnt++;       /* Increment count */
   	  rti_blink_on_cnt = 0;       /* Reset count */
  	} 
  	
  //	else if (rti_blink_on_cnt >= 0x0F)
  //	{
  //	  Regs.porta.byte = 0x55;   /* Port A = 55 */
  // 	  rti_blink_on_cnt = 0x00;  /* Clear count */ 	
  // 	}
  	 
  	else
  	{
  	
  	  rti_blink_on_cnt++; /* Increment count */
  	
  	}

    /* SW5 pressed */

    if (Regs.porte.bit.pte0 == FALSE) ucCST = 1;
		
		break;
		
	case 1:  /* SW5 release */
		
		if (Regs.porte.bit.pte0 == FALSE) ucCST = 1;
		
		else 
		{
		  rti_blink_on_cnt = 0x00; /* Clear blink count */
	    Pwm.pwme.byte = 0x88; // Channel 7 an 3 active

		  ucCST = 2;
		}
		
		break;
	
  case 2:  /* LED and Piezo toggle test */ 	
	
	  if (rti_blink_on_cnt == 0x08) 
  	{
  	  Regs.porta.byte = 0xAA;   /* Port A = AA */ 
 	    Pwm.pwmprclk.byte = 0x60; /* Clock B = bus */

  	  rti_blink_on_cnt++;       /* Increment count */
  	} 
  	
  	else if (rti_blink_on_cnt >= 0x0F)
  	{
  	  Regs.porta.byte = 0x55;   /* Port A = 55 */
 	    Pwm.pwmprclk.byte = 0x50; /* Clock B = bus */
 
  	  rti_blink_on_cnt = 0x00;  /* Clear count */ 	
  	}
  	 
  	else
  	{
  	
  	  rti_blink_on_cnt++; /* Increment count */
  	
  	}
  	
    /* SW5 pressed */

    if (Regs.porte.bit.pte0 == FALSE) ucCST = 3;
		
		break;
		
	case 3:  /* SW5 release */
		
		if (Regs.porte.bit.pte0 == FALSE) ucCST = 3;
		
		else ucCST = 4;
		
		break;
	
	case 4:  /* Port A and Port B test */
		
 	  Pwm.pwme.byte = 0x00;      /* PWMs OFF */
 	  ucTEMP1 = Regs.portb.byte; /* Read Port B */  	  
 	  Regs.porta.byte = ucTEMP1; /* Write Port A */
 	  
	  /* SW5 pressed */
			
    if (Regs.porte.bit.pte0 == FALSE) ucCST = 5;
	
		break;
			
	case 5:  /* SW5 release */	 
		
    if (Regs.porte.bit.pte0 == FALSE) ucCST = 5;
    
 		else ucCST = 6;
	
		break;
			
	case 6:	 /* Mode switch test */
		
		ucTEMP1 = Atd0.portad.byte;
 	  Regs.porta.byte = ucTEMP1; /* Write Port A */ 
 	  
	  /* SW5 pressed */
		
    if (Regs.porte.bit.pte0 == FALSE) ucCST = 7;
	
		break;
		
	case 7:  /* SW5 release */	 

		/* Setup for next test */
		
 	  Regs.porta.byte = 0x00;    /* Port A off */
    Pwm.pwmdty[3].byte = 0x00; /* Off */
 	  Pwm.pwme.byte = 0x08;      /* PWM 3 ON */

    if (Regs.porte.bit.pte0 == FALSE) ucCST = 7;
    
 		else ucCST = 8;
	
		break;
			
	case 8:	 /* Pot 1 test */ 

 	  Regs.porta.byte = 0xAF; /* Port A test 3 */

    Atd1.atdctl5.byte = 0x90;                    /* Full scan sequence start scan */
    while (Atd1.atdstat0.bit.scf == FALSE) { }   /* Wait for conversion completion */
    ucTEMP1 = Atd1.atddr[0].d8.datal;            /* Get 8 bit ATD result */
    Pwm.pwmdty[3].byte = ucTEMP1;                /* Duty set to ATD counts */
    
    /* SW5 pressed */

    if (Regs.porte.bit.pte0 == FALSE) ucCST = 9;
		
		break;
					
	case 9:	 

		/* Setup for next test */
		
 	  Regs.porta.byte = 0x00;    /* Port A off */
    Pwm.pwmdty[3].byte = 0x00; /* Off */
 	  Pwm.pwme.byte = 0x08;      /* PWM 3 ON */

    if (Regs.porte.bit.pte0 == FALSE) ucCST = 9;
    
 		else ucCST = 10;
	
		break;
			
	case 10:  /* Pot 2 test */ 

 	  Regs.porta.byte = 0xE6; /* Port A test 4 */
 	  
    Atd1.atdctl5.byte = 0x90;                    /* Full scan sequence start scan */
    while (Atd1.atdstat0.bit.scf == FALSE) { }   /* Wait for conversion completion */
    ucTEMP1 = Atd1.atddr[1].d8.datal;            /* Get 8 bit ATD result */
    Pwm.pwmdty[3].byte = ucTEMP1;                /* Duty set to ATD counts */
    
    if (Regs.porte.bit.pte0 == FALSE) ucCST = 11;
		
		break;
					
	case 11:	 

		/* Setup for next test */
		
 	  Regs.porta.byte = 0x00;    /* Port A off */
    Pwm.pwmdty[3].byte = 0x00; /* Off */
 	  Pwm.pwme.byte = 0x00;      /* PWM 3 OFF */
 	  ucFLAG1 = 0x00;
 	  ucFLAG2 = 0x00;
 	  ucSPI_MSB = 0x00;
    ucSPI_LSB = 0x80;
    Pim.pth.bit.pth3 = TRUE;   /* Enable MC33879 */


    if (Regs.porte.bit.pte0 == FALSE) ucCST =11;
    
 		else ucCST = 12;
	
		break;
			
	case 12:  /* SW6 and SPI Test */

 	  Regs.porta.byte = 0xED;

    if (Regs.porte.bit.pte0 == FALSE) ucCST = 13;

 	  if (ucFLAG1 == 0x00) 
 	  {
 	    
      if ((Pim.ptt.bit.ptt4 == FALSE) && (ucFLAG2 == 0x00))  
      {
        ucFLAG2 = 0x01;
      	ucFLAG1 = 0x00;
      	break;
      } 
    
      else if ((ucFLAG2 == 0x01) && (Pim.ptt.bit.ptt4 == TRUE))
      { 
      	ucFLAG1 = 0x01;
      	ucFLAG2 = 0x00; /* Reset ucFLAG2 */
        break;      
      } 
      
      else 
      {      
        break;      
      }
    
 	  }  /* End of ucFLAG1 = 0x00 */
 	  
 	  else /* ucFLAG1 = 1	 SW6 debounced */
 	  {
 	  	ucFLAG1 = 0x00; /* Reset ucFLAG1 for next debounce cycle */
 	  		 
 	  	if (ucSPI_LSB == 0x80)
 	  	{
 	  		 
 	  	  Pim.pth.bit.pth5 = FALSE;                     /* CS low MC33879 */
 	  	  asm NOP; asm NOP; asm NOP; asm NOP; asm NOP;  /* Small delay */
 	  	  Spi0.spidr.byte = ucSPI_MSB;                  /* Send MSB first */
 	  	  while (Spi0.spisr.bit.spif == FALSE) { }      /* Wait for spif goto 1 */
 	  	  ucTEMP1 = Spi0.spidr.byte;                    /* Read data byte */ 	  	  
 	  	  while (Spi0.spisr.bit.sptef == FALSE) { }     /* Wait for sptef */
 	  	  
 	  	  
 	  	  Spi0.spidr.byte = ucSPI_LSB;                  /* Send LSB next */
 	  	  while (Spi0.spisr.bit.spif == FALSE) { }      /* Wait for spif goto 1 */
 	  	  ucTEMP1 = Spi0.spidr.byte;                    /* Read data byte */
 	  	  while (Spi0.spisr.bit.sptef == FALSE) { }     /* Wait for sptef */
 	  	  asm NOP; asm NOP; asm NOP; asm NOP; asm NOP;  /* Small delay */
 	  	  Pim.pth.bit.pth5 = TRUE;                      /* CS low MC33879 */
 	  	  
 	  	  ucSPI_LSB = 0x00; 
 	  		 
 	  	} 
 	  		
 	  	else
 	  	{

 	  	  Pim.pth.bit.pth5 = FALSE;                     /* CS low MC33879 */
 	  	  asm NOP; asm NOP; asm NOP; asm NOP; asm NOP;  /* Small delay */
 	  	  Spi0.spidr.byte = ucSPI_MSB;                  /* Send MSB first */
 	  	  while (Spi0.spisr.bit.spif == FALSE) { }      /* Wait for spif goto 1 */
 	  	  ucTEMP1 = Spi0.spidr.byte;                    /* Read data byte */
 	  	  while (Spi0.spisr.bit.sptef == FALSE) { }     /* Wait for sptef */
 	  	  
 	  	  
 	  	  Spi0.spidr.byte = ucSPI_LSB;                  /* Send LSB next */
 	  	  while (Spi0.spisr.bit.spif == FALSE) { }      /* Wait for spif goto 1 */
 	  	  ucTEMP1 = Spi0.spidr.byte;                    /* Read data byte */
 	  	  while (Spi0.spisr.bit.sptef == FALSE) { }     /* Wait for sptef */
 	  	  asm NOP; asm NOP; asm NOP; asm NOP; asm NOP;  /* Small delay */
 	  	  Pim.pth.bit.pth5 = TRUE;                      /* CS low MC33879 */
 	  	  
 	  	  ucSPI_LSB = 0x80; 	  		 
 	  		 
 	  	}
 	  	
 	  
 	  } /* End else ucFLAG1 = 0x01 */
 	  		
		break;
					
	case 13:	 

		/* Setup for next test */
		
 	  Regs.porta.byte = 0x00;    /* Port A off */
    Pwm.pwmdty[3].byte = 0x00; /* Off */
 	  Pwm.pwme.byte = 0x00;      /* PWM 3 OFF */
 	  ucFLAG1 = 0x00;
 	  ucFLAG2 = 0x00;
 	  ucSPI_MSB = 0x00;
    ucSPI_LSB = 0x00;
    Pim.pth.bit.pth3 = TRUE;   /* Enable MC33879 */

		/* Turn off LED3 */
    
 	  Pim.pth.bit.pth5 = FALSE;                     /* CS low MC33879 */
 	  asm NOP; asm NOP; asm NOP; asm NOP; asm NOP;  /* Small delay */
 	  Spi0.spidr.byte = ucSPI_MSB;                  /* Send MSB first */
 	  while (Spi0.spisr.bit.spif == FALSE) { }      /* Wait for spif goto 1 */
 	  ucTEMP1 = Spi0.spidr.byte;                    /* Read data byte */
 	  while (Spi0.spisr.bit.sptef == FALSE) { }     /* Wait for sptef */
 	  	  
 	  	  
 	  Spi0.spidr.byte = ucSPI_LSB;                  /* Send LSB next */
 	  while (Spi0.spisr.bit.spif == FALSE) { }      /* Wait for spif goto 1 */
 	  ucTEMP1 = Spi0.spidr.byte;                    /* Read data byte */
 	  while (Spi0.spisr.bit.sptef == FALSE) { }     /* Wait for sptef */
 	  asm NOP; asm NOP; asm NOP; asm NOP; asm NOP;  /* Small delay */
 	  Pim.pth.bit.pth5 = TRUE;                      /* CS low MC33879 */
 	  	  
 	  ucSPI_LSB = 0x02; 	  		 
    
    if (Regs.porte.bit.pte0 == FALSE) ucCST = 13;
    
 		else ucCST = 14;
	
		break;
			
	case 14:	 /* SW7 and SPI LED4 Test */

 	  Regs.porta.byte = 0x7D; /* SW7 SPI LED4 test 6 */

    if (Regs.porte.bit.pte0 == FALSE) ucCST = 15;

 	  if (ucFLAG1 == 0x00) 
 	  {
 	    
      if ((Pim.ptt.bit.ptt6 == FALSE) && (ucFLAG2 == 0x00))  
      {
        ucFLAG2 = 0x01;
      	ucFLAG1 = 0x00;
      	break;
      } 
    
      else if ((ucFLAG2 == 0x01) && (Pim.ptt.bit.ptt6 == TRUE))
      { 
      	ucFLAG1 = 0x01;
      	ucFLAG2 = 0x00; /* Reset ucFLAG2 */
        break;      
      } 
      
      else 
      {      
        break;      
      }
    
 	  }  /* End of ucFLAG1 = 0x00 */
 	  
 	  else /* ucFLAG1 = 1	 SW6 debounced */
 	  {
 	  	ucFLAG1 = 0x00; /* Reset ucFLAG1 for next debounce cycle */
 	  		 
 	  	if (ucSPI_LSB == 0x02)
 	  	{
 	  		 
 	  	  Pim.pth.bit.pth5 = FALSE;                     /* CS low MC33879 */
 	  	  asm NOP; asm NOP; asm NOP; asm NOP; asm NOP;  /* Small delay */
 	  	  Spi0.spidr.byte = ucSPI_MSB;                  /* Send MSB first */
 	  	  while (Spi0.spisr.bit.spif == FALSE) { }      /* Wait for spif goto 1 */
 	  	  ucTEMP1 = Spi0.spidr.byte;                    /* Read data byte */
 	  	  while (Spi0.spisr.bit.sptef == FALSE) { }     /* Wait for sptef */
 	  	  
 	  	  
 	  	  Spi0.spidr.byte = ucSPI_LSB;                  /* Send LSB next */
 	  	  while (Spi0.spisr.bit.spif == FALSE) { }      /* Wait for spif goto 1 */
 	  	  ucTEMP1 = Spi0.spidr.byte;                    /* Read data byte */
 	  	  while (Spi0.spisr.bit.sptef == FALSE) { }     /* Wait for sptef */
 	  	  asm NOP; asm NOP; asm NOP; asm NOP; asm NOP;  /* Small delay */
 	  	  Pim.pth.bit.pth5 = TRUE;                      /* CS low MC33879 */
 	  	  
 	  	  ucSPI_LSB = 0x00; 
 	  		 
 	  	} 
 	  		
 	  	else
 	  	{

 	  	  Pim.pth.bit.pth5 = FALSE;                     /* CS low MC33879 */
 	  	  asm NOP; asm NOP; asm NOP; asm NOP; asm NOP;  /* Small delay */
 	  	  Spi0.spidr.byte = ucSPI_MSB;                  /* Send MSB first */
 	  	  while (Spi0.spisr.bit.spif == FALSE) { }      /* Wait for spif goto 1 */
 	  	  ucTEMP1 = Spi0.spidr.byte;                    /* Read data byte */
 	  	  while (Spi0.spisr.bit.sptef == FALSE) { }     /* Wait for sptef */
 	  	  
 	  	  
 	  	  Spi0.spidr.byte = ucSPI_LSB;                  /* Send LSB next */
 	  	  while (Spi0.spisr.bit.spif == FALSE) { }      /* Wait for spif goto 1 */
 	  	  ucTEMP1 = Spi0.spidr.byte;                    /* Read data byte */
 	  	  while (Spi0.spisr.bit.sptef == FALSE) { }     /* Wait for sptef */
 	  	  asm NOP; asm NOP; asm NOP; asm NOP; asm NOP;  /* Small delay */
 	  	  Pim.pth.bit.pth5 = TRUE;                      /* CS low MC33879 */
 	  	  
 	  	  ucSPI_LSB = 0x02; 	  		 
 	  		 
 	  	}
 	  	
 	  
 	  } /* End else ucFLAG1 = 0x01 */
 	  
	
		break;
					
	case 15:	 

		/* Setup for next test */
		
 	  Regs.porta.byte = 0x00;    /* Port A off */
    Pwm.pwmdty[3].byte = 0x00; /* Off */
 	  Pwm.pwme.byte = 0x08;      /* PWM 3 ON */
 	  
 	  ucSPI_MSB = 0x00;
    ucSPI_LSB = 0x00;
 	  ucFLAG1 = 0x00;
    
    Pim.pth.bit.pth3 = TRUE;   /* Enable MC33879 */

		/* Turn off LED4 */
    
 	  Pim.pth.bit.pth5 = FALSE;                     /* CS low MC33879 */
 	  asm NOP; asm NOP; asm NOP; asm NOP; asm NOP;  /* Small delay */
 	  Spi0.spidr.byte = ucSPI_MSB;                  /* Send MSB first */
 	  while (Spi0.spisr.bit.spif == FALSE) { }      /* Wait for spif goto 1 */
 	  ucTEMP1 = Spi0.spidr.byte;                    /* Read data byte */
 	  while (Spi0.spisr.bit.sptef == FALSE) { }     /* Wait for sptef */
 	  	  
 	  	  
 	  Spi0.spidr.byte = ucSPI_LSB;                  /* Send LSB next */
 	  while (Spi0.spisr.bit.spif == FALSE) { }      /* Wait for spif goto 1 */
 	  ucTEMP1 = Spi0.spidr.byte;                    /* Read data byte */
 	  while (Spi0.spisr.bit.sptef == FALSE) { }     /* Wait for sptef */
 	  asm NOP; asm NOP; asm NOP; asm NOP; asm NOP;  /* Small delay */
 	  Pim.pth.bit.pth5 = TRUE;                      /* CS low MC33879 */
 	  	      
    if (Regs.porte.bit.pte0 == FALSE) ucCST = 15;
    
 		else ucCST = 16;
	
		break;
			
	case 16:	 /* SCI0 test 7 */

 	  Regs.porta.byte = 0x87;
 	  
 	  if (ucFLAG1 == 0x00)
 	  {
 	    ucFLAG1 = 0x01; /* Toggle flag */
      Pwm.pwmdty[3].byte = 0xFF; 
			Sci0.scidrl.byte = 0x55;
 	    
 	  }
 	   
 	  else
 	  {
 	  
 	    ucFLAG1 = 0x00; /* Toggle flag */
      Pwm.pwmdty[3].byte = 0x00;
      ucTEMP1 = Sci0.scisr1.byte; /* Read status register */
 	  
 	  }

    if (Regs.porte.bit.pte0 == FALSE) ucCST = 17;
		
		break;  
					
	case 17:	 

		/* Setup for next test */
		
 	  Regs.porta.byte = 0x00;    /* Port A off */
    Pwm.pwmdty[3].byte = 0x00; /* Off */
 	  Pwm.pwme.byte = 0x08;      /* PWM 3 ON */
 	  
 	  ucFLAG1 = 0x00;
    
    Pim.pth.bit.pth3 = FALSE; /* Disable MC33879 */

    if (Regs.porte.bit.pte0 == FALSE) ucCST = 17;
    
 		else ucCST = 18;
	
		break;
			
	case 18:	 /* SCI1 test 8 */

 	  Regs.porta.byte = 0xFF;
 	  
 	  if (ucFLAG1 == 0x00)
 	  {
 	    ucFLAG1 = 0x01; /* Toggle flag */
      Pwm.pwmdty[3].byte = 0xFF; 
			Sci1.scidrl.byte = 0x55; 	    
 	  }
 	   
 	  else
 	  {
 	    ucFLAG1 = 0x00; /* Toggle flag */
      Pwm.pwmdty[3].byte = 0x00;
      ucTEMP1 = Sci1.scisr1.byte; /* Read status register */
 	  }

 		ucCST = 18;
		
		break;  
					
	default:
	
		ucCST = 0x00;			/* Default CST = 0 */
		
    Regs.porta.byte = 0x01;    /* Set-up first bit for shift register - BDS */

		break;

} /* END Switch */


  	Crg.crgflg.bit.rtif = 1;  /* Clear interrupt bit, prepare for next RTI */
  	

} /* END rti_isr */

#pragma CODE_SEG DEFAULT

//************************************************************************
// INTERRUPT REQUEST PIN ISR
// DESCRIPTION:
// Interrupt asserted at IRQ PIN event. The event can be edge or level
// triggered. For edge, the interrupt is lateched internally. Internal 
// latch cleared when ISR taken.
// 
#pragma CODE_SEG NON_BANKED
interrupt void irq_isr(void){ (void) software_trap(); }
#pragma CODE_SEG DEFAULT

//************************************************************************
// EXTERNAL INTERRUPT REQUEST PIN ISR
// DESCRIPTION:
// Interrupt asserted on XIRQ low level event. ISR routine should handshake 
// with interrupt source to release the pin. XIRQ is enabled by clearing the
// X-bit. After enabled, disabled only after POR. 
//
#pragma CODE_SEG NON_BANKED
interrupt void xirq_isr(void){ (void) software_trap(); }
#pragma CODE_SEG DEFAULT

//************************************************************************
// SOFTWARE INTERRUPT INSTRUCTION ISR
// DESCRIPTION:
// Interrupt asserted when SWI instruction executed. This acts as a hook 
// into on-board monitors and development instructions.
//
#pragma CODE_SEG NON_BANKED
interrupt void swi_isr(void){ (void) software_trap(); }
#pragma CODE_SEG DEFAULT

//************************************************************************
// UNIMPLIMENTED INSTRUCTION (OPCODE) TRAP ISR
// DESCRIPTION:
// Interrupt asserted when unimplimented opcode encountered. The stacked 
// address can be used to determine te source of the opcode.
//
#pragma CODE_SEG NON_BANKED
interrupt void trap_isr(void){ (void) software_trap(); }
#pragma CODE_SEG DEFAULT

//************************************************************************
// COMPUTER OPERATING PROPERLY (WATCHDOG) TIMER ISR
// DESCRIPTION:
// Interrupt asserted upon COP timeout. Operates from OSCCLK.
// To kick the dog write 55h then AAh to ARMCOP. Window COP bit extends
// basic operation by having a valid write during a percentage of the COP 
// window.
//
#pragma CODE_SEG NON_BANKED
interrupt void cop_isr(void){ (void) software_trap(); }
#pragma CODE_SEG DEFAULT

//************************************************************************
// SELF CLOCK-MODE ISR
// DESCRIPTION:
// Interrupt asserted when either entry or exit from Self-Clock Mode (SCM). 
// Clock Quality Checker is used to determine entery into SCM. The Clock
// Quality Checker provides a better clock check beyond the Clock Moitor. 
// A period of 50,000 PLL clocks is called a check-window. 4096 OSC clock 
// edges within a check-window means OSC OK. After 50 window tries IC will 
// enter PLL Self Clock (1Mz to 5MHz).
//
#pragma CODE_SEG NON_BANKED
interrupt void clockmonitor_isr(void){ (void) software_trap(); }
#pragma CODE_SEG DEFAULT      

//************************************************************************
// Byte Flight receive fifo not empty ISR
// DESCRIPTION:
// 
//
#pragma CODE_SEG NON_BANKED        
interrupt void bf_rx_fifo_isr(void){ (void) software_trap(); }
#pragma CODE_SEG DEFAULT

//************************************************************************
// Byte Flight receive ISR
// DESCRIPTION:
// 
//
#pragma CODE_SEG NON_BANKED        
interrupt void bf_rx_isr(void){ (void) software_trap(); }
#pragma CODE_SEG DEFAULT

//************************************************************************
// Byte Flight synchronization ISR
// DESCRIPTION:
// 
//
#pragma CODE_SEG NON_BANKED        
interrupt void bf_sync_isr(void){ (void) software_trap(); }
#pragma CODE_SEG DEFAULT

//************************************************************************
// Byte Flight general ISR
// DESCRIPTION:
// 
//
#pragma CODE_SEG NON_BANKED        
interrupt void bf_general_isr(void){ (void) software_trap(); }
#pragma CODE_SEG DEFAULT


/*Warning Enable*/

#pragma MESSAGE WARNING C12004		//Warning: Far Keyword ignored for Function       


