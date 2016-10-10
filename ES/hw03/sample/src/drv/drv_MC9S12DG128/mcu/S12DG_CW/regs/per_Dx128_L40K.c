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
* FILE NAME: per_Dx128_L40K.c                                           
*                                                                           
* PURPOSE: declaration of peripheral variables for an MC9S12Dx128
*		   Mask Set: L40K							 
*                                                                           
* DESCRIPTION:  declarations of control register blocks for on-chip peripherals.        
*                                                                           
*                                                                           
* AUTHOR: r9aabe   LOCATION: Austin,TX      LAST EDIT DATE: 02/27/03  
*                                                                           
******************************************************************************/
/******************************************************************************
* Peripheral Versions for MCS12Dx128 - Mask Set: L40K
* 
* Peripheral	Peripheral UG	    Version	Doc. Order #		  Header File
* ----------	---------------   -------	---------------		---------------
* CORE			  HCS12 V1.5 Core   V1.2		S12CPU15UG/D		  S12CPU15V1_2.h
* CRG			    CRG  			        V04		  S12CRGV4/D			  S12CRGV4.h
* TIMER			  ECT_16B8C		      V01		  S12ECT16B8CV1/D		S12ECT16B8CV1.h
* ATD			    ATD_10B8C		      V02		  S12ATD10B8CV2/D		S12ATD10B8CV2.h
* IIC			    IIC				        V02		  S12IICV2/D			  S12IICV2.h
* SCI			    SCI				        V02		  S12SCIV2/D			  S12SCIV2.h
* SPI			    SPI	  			      V02		  S12SPIV2/D			  S12SPIV2.h
* PWM			    PWM_8B8C		      V01		  S12PWM8B8CV1/D		S12PWM8B8CV1.h
* FLASH			  FTS128K			      V02		  S12FTS128KV2/D		S12FTS128KV2.h
* EEPROM		  EETS2K			      V01		  S12EETS2KV1/D		  S12EETS2KV1.h
* BDLC			  BDLC			        V01		  S12BDLCV1/D			  S12BDLCV1.h
* MSCAN			  MSCAN			        V02		  S12MSCANV2/D		  S12MSCANV2.h
* VREG			  VREG			        V01		  S12REGV1/D			  --
* PIM			    PIM_9DT128	   	  V02		  S12DT128PIMV2/D		S12DT128PIMV2.h
* BF			    BF				        V01		  S12BFV1/D			    S12BFV1.h
*
******************************************************************************/ 				

#ifndef REG_BASE
#define REG_BASE			0x0000
#endif

#include "S12ATD10B8CV2.h"		//ATD
#include "S12BDLCV1.h" 				//BDLC
#include "S12BFV1.h"				  //BF
#include "S12CPU15V1_2.h"			//CORE(PAGE/REG)
#include "S12CRGV4.h"				  //CRG
#include "S12EETS2KV1.h"			//EEPROM
#include "S12FTS128KV2.h"			//FLASH
#include "S12IICV2.h"				  //IIC
#include "MOTTYPES.h"				  //TYPE DEFS
#include "S12MSCANV2.h"				//MSCAN
#include "S12DT128PIMV2.h"		//PIM
#include "S12PWM8B8CV1.h"			//PWM
#include "S12SCIV2.h"				  //SCI
#include "S12SPIV2.h"				  //SPI
#include "S12ECT16B8CV1.h"		//TIMER



tREGISTER Regs 	 @ (0x0000 + REG_BASE);
tPAGE     Page   @ (0x0030 + REG_BASE);
tCRG	    Crg  	 @ (0x0034 + REG_BASE);
tTIMER	  Tim0	 @ (0x0040 + REG_BASE);
tATD	    Atd0   @ (0x0080 + REG_BASE);
tPWM	    Pwm	   @ (0x00A0 + REG_BASE);
tSCI      Sci0   @ (0x00C8 + REG_BASE);
tSCI      Sci1   @ (0x00D0 + REG_BASE);
tSPI      Spi0   @ (0x00D8 + REG_BASE);
tIIC	    Iic	   @ (0x00E0 + REG_BASE);
tBDLC	    Bdlc   @ (0x00E8 + REG_BASE);
tSPI      Spi1   @ (0x00F0 + REG_BASE);
tFLASH    Flash  @ (0x0100 + REG_BASE);
tEEPROM   Eeprom @ (0x0110 + REG_BASE);
tATD      Atd1   @ (0x0120 + REG_BASE);
tMSCAN	  Can0   @ (0x0140 + REG_BASE);
tMSCAN	  Can1	 @ (0x0180 + REG_BASE);
tPIM	    Pim	   @ (0x0240 + REG_BASE);
tMSCAN	  Can4	 @ (0x0280 + REG_BASE);
tBF		    Bf	   @ (0x0300 + REG_BASE);



 






