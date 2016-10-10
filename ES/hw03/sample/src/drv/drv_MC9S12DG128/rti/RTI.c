/**************************************************************************
**
** Module Name:   RTI.c
**
** Module Description:  Real-Time Interrupt support functions.
**  Define functions for Real-Time Interrupt operation.
**
**************************************************************
** RTI_Init():
**  Configures RTI control registers for desired operation.
**
** RTI_DeInit():
**  Power-down the RTI.
**
** RTI_ISR():
**  Real-Time Interrupt Service Routine.
**
***************************************************************************
**
**  Revised by:  Ben Sweet
**  Revision:    1.0
**  Date:        22-Apr-2012
**
***************************************************************************
**
** Revision History:
**
**
** Revision: 1.0    22-Apr-2012   Benjamin Sweet
** * Original version based on existing methods in general use, and specific
**   work by Justin Michrina and Richard Slindee.
**
**************************************************************************/

/*
** Include Files
*/
   /* Target Specific Definitions */
 #ifndef MXVDEV                 /* Normal application configuration */
   #include <mc9s12dg128.h>     /* derivative information */
 #endif

   /* Type Definitions */
   #include "Types.h"

   /* Configuration */
   #include "RTI_cfg.h"    /* Definitions for configuration constants */

   /*
   ** Access to System components:
   */
   #include "..\..\..\svc\tmr\Timer.h"


/*
** Function Prototypes
*/
void RTI_Init(void);    /* Initialize the real time interrupt clock */

#pragma CODE_SEG __NEAR_SEG NON_BANKED
__interrupt void RTI_Isr(void);

#pragma CODE_SEG DEFAULT

/*
** Local Variables:
*/


/*
**  Module code begins:
*/

/**************************************************************************
**
** Function Name:   RTI_Init()
**
** Function Description:
**  - Configures RTI registers for desired operation.
**
** Inputs:
**   (none)
**
** Output:
**   (none)
**
** Usage:
**   Call to this function from should be in the format of
**    RTI_Init();
**
***************************************************************************
** System Interface:
** -  The constant values for register configuration are defined in RTI_cfg.h.
** -  COPCTL - 
** -  CLKSEL - 
** -  RTICTL - 
** -  CRGFLG - 
** -  CRGINT - 
**
**************************************************************************/
void RTI_Init(void)
{
    /*
    ** Configuration of Real-Time Interrupt registers:
    **  Configuration constant values defined in RTI_cfg.h.
    **  Masks and Registers defined in mc9s12dg128.h.
    */
    COPCTL |= COPCTL_RSBCK_MASK;    /* RTI and COP stopped in active BDM. */
    CLKSEL |= CLKSEL_RTIWAI_MASK;   /* RTI stops and initializes the RTI dividers whenever the part goes into Wait Mode */
    RTICTL  = ( (RTICTL_INIT_MASK_PRESCALE | RTICTL_INIT_MASK_MODULUS) & RTICTL_RTR_MASK);  /* Set RTI timing */
    CRGFLG |= CRGFLG_RTIF_MASK;     /* Clear the Real-Time Interrupt flag   */
    CRGINT |= CRGINT_RTIE_MASK;     /* Enable the Real-Time Interrupt       */
 
    return;
}  /* ADC_Init() */


/**************************************************************************
**
** Function Name:   RTI_DeInit()
**
** Function Description:
**  - De-Initializes ("turns off") RTI Clock.
**  - Deactivates the RTI Interrupt.
**
** Inputs:
**   (none)
**
** Output:
**   (none)
**
** Usage:
**   Call to this function from should be in the format of
**    RTI_DeInit();
**
***************************************************************************
** System Interface:
** -  COPCTL - 
** -  CLKSEL - 
** -  RTICTL - 
** -  CRGFLG - 
** -  CRGINT - 
**
**************************************************************************/
void RTI_DeInit(void)
{
    RTICTL  = 0u;                   /* Disable RTI timing */
    CRGINT &= ~(CRGINT_RTIE_MASK);  /* Disable the Real-Time Interrupt      */
    CRGFLG |= CRGFLG_RTIF_MASK;     /* Clear the Real-Time Interrupt flag   */

}  /* RTI_DeInit() */


#pragma CODE_SEG __NEAR_SEG NON_BANKED
/******** RTI_ISR *************** 
** Clear the RTI_ISR flag and service the system periodic timer
*/
__interrupt void RTI_Isr(void) 
{ 
    Timer_Task();                   /* Periodic task to increment main timer accumulator. */
    CRGFLG |= CRGFLG_RTIF_MASK;     /* Clear the Real-Time Interrupt flag   */
}  /* RTI_ISR() */

#pragma CODE_SEG DEFAULT

