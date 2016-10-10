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
* FILE NAME: projectvectors.h                                             
*                                                                           
* PURPOSE: header file which includes all Dx128 (L40K) interrupt handler prototypes
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

#ifndef PROJECTVECTORS_H        /*prevent duplicated includes*/
#define PROJECTVECTORS_H

/*Include Files*/

/*Local Prototypes*/
void software_trap(void);


#pragma CODE_SEG NON_BANKED        
void unused_isr(void);
#pragma CODE_SEG DEFAULT

#pragma CODE_SEG NON_BANKED
void pwm_shutdown_isr(void);
#pragma CODE_SEG DEFAULT

#pragma CODE_SEG NON_BANKED
void portp_isr(void);
#pragma CODE_SEG DEFAULT

#pragma CODE_SEG NON_BANKED
void mscan4_tx_isr(void);
#pragma CODE_SEG DEFAULT

#pragma CODE_SEG NON_BANKED
void mscan4_rx_isr(void);
#pragma CODE_SEG DEFAULT

#pragma CODE_SEG NON_BANKED
void mscan4_error_isr(void);
#pragma CODE_SEG DEFAULT

#pragma CODE_SEG NON_BANKED
void mscan4_wakeup_isr(void);
#pragma CODE_SEG DEFAULT

#pragma CODE_SEG NON_BANKED
void mscan1_tx_isr(void);
#pragma CODE_SEG DEFAULT

#pragma CODE_SEG NON_BANKED
void mscan1_rx_isr(void);
#pragma CODE_SEG DEFAULT

#pragma CODE_SEG NON_BANKED
void mscan1_error_isr(void);
#pragma CODE_SEG DEFAULT

#pragma CODE_SEG NON_BANKED
void mscan1_wakeup_isr(void);
#pragma CODE_SEG DEFAULT

#pragma CODE_SEG NON_BANKED
void mscan0_tx_isr(void);
#pragma CODE_SEG DEFAULT

#pragma CODE_SEG NON_BANKED
void mscan0_rx_isr(void);
#pragma CODE_SEG DEFAULT

#pragma CODE_SEG NON_BANKED
void mscan0_error_isr(void);
#pragma CODE_SEG DEFAULT

#pragma CODE_SEG NON_BANKED
void mscan0_wakeup_isr(void);
#pragma CODE_SEG DEFAULT

#pragma CODE_SEG NON_BANKED
void flash_isr(void);
#pragma CODE_SEG DEFAULT

#pragma CODE_SEG NON_BANKED
void eeprom_isr(void);
#pragma CODE_SEG DEFAULT

#pragma CODE_SEG NON_BANKED
void spi1_isr(void);
#pragma CODE_SEG DEFAULT

#pragma CODE_SEG NON_BANKED
void iic_isr(void);
#pragma CODE_SEG DEFAULT

#pragma CODE_SEG NON_BANKED
void bdlc_isr(void);
#pragma CODE_SEG DEFAULT

#pragma CODE_SEG NON_BANKED
void crg_scm_isr(void);
#pragma CODE_SEG DEFAULT

#pragma CODE_SEG NON_BANKED
void crg_pll_lock_isr(void);
#pragma CODE_SEG DEFAULT

#pragma CODE_SEG NON_BANKED
void pa_b_overflow_isr(void);
#pragma CODE_SEG DEFAULT

#pragma CODE_SEG NON_BANKED
void ect_mdc_isr(void);
#pragma CODE_SEG DEFAULT

#pragma CODE_SEG NON_BANKED
void porth_isr(void);
#pragma CODE_SEG DEFAULT

#pragma CODE_SEG NON_BANKED
void portj_isr(void);
#pragma CODE_SEG DEFAULT

#pragma CODE_SEG NON_BANKED
void atd1_isr(void);
#pragma CODE_SEG DEFAULT

#pragma CODE_SEG NON_BANKED
void atd0_isr(void);
#pragma CODE_SEG DEFAULT

#pragma CODE_SEG NON_BANKED
void sci1_isr(void);
#pragma CODE_SEG DEFAULT

#pragma CODE_SEG NON_BANKED
void sci0_isr(void);
#pragma CODE_SEG DEFAULT

#pragma CODE_SEG NON_BANKED
void spi0_isr(void);
#pragma CODE_SEG DEFAULT

#pragma CODE_SEG NON_BANKED
void pa_a_edge_isr(void);
#pragma CODE_SEG DEFAULT

#pragma CODE_SEG NON_BANKED
void pa_a_overflow_isr(void);
#pragma CODE_SEG DEFAULT

#pragma CODE_SEG NON_BANKED
void ect_overflow_isr(void);
#pragma CODE_SEG DEFAULT

#pragma CODE_SEG NON_BANKED
void ect_ch7_isr(void);
#pragma CODE_SEG DEFAULT

#pragma CODE_SEG NON_BANKED
void ect_ch6_isr(void);
#pragma CODE_SEG DEFAULT

#pragma CODE_SEG NON_BANKED
void ect_ch5_isr(void);
#pragma CODE_SEG DEFAULT

#pragma CODE_SEG NON_BANKED
void ect_ch4_isr(void);
#pragma CODE_SEG DEFAULT

#pragma CODE_SEG NON_BANKED
void ect_ch3_isr(void);
#pragma CODE_SEG DEFAULT

#pragma CODE_SEG NON_BANKED
void ect_ch2_isr(void);
#pragma CODE_SEG DEFAULT

#pragma CODE_SEG NON_BANKED
void ect_ch1_isr(void);
#pragma CODE_SEG DEFAULT

#pragma CODE_SEG NON_BANKED
void ect_ch0_isr(void);
#pragma CODE_SEG DEFAULT

#pragma CODE_SEG NON_BANKED
void rti_isr(void);
#pragma CODE_SEG DEFAULT

#pragma CODE_SEG NON_BANKED
void irq_isr(void);
#pragma CODE_SEG DEFAULT

#pragma CODE_SEG NON_BANKED
void xirq_isr(void);
#pragma CODE_SEG DEFAULT

#pragma CODE_SEG NON_BANKED
void swi_isr(void);
#pragma CODE_SEG DEFAULT

#pragma CODE_SEG NON_BANKED
void trap_isr(void);
#pragma CODE_SEG DEFAULT

#pragma CODE_SEG NON_BANKED
void cop_isr(void);
#pragma CODE_SEG DEFAULT

#pragma CODE_SEG NON_BANKED
void clockmonitor_isr(void);
#pragma CODE_SEG DEFAULT

#pragma CODE_SEG NON_BANKED        
void bf_rx_fifo_isr(void);
#pragma CODE_SEG DEFAULT

#pragma CODE_SEG NON_BANKED        
void bf_rx_isr(void);
#pragma CODE_SEG DEFAULT

#pragma CODE_SEG NON_BANKED        
void bf_sync_isr(void);
#pragma CODE_SEG DEFAULT

#pragma CODE_SEG NON_BANKED        
void bf_general_isr(void);
#pragma CODE_SEG DEFAULT

#endif /*PROJECTVECTORS_H*/










 












 






