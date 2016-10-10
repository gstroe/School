/**************************************************************************
**
** Module Name:   Mcu.c
**
** Module Description:  General Microcontroller functions.
**  Define functions for General Overall Microcontroller configuration and operation.
**
** Mcu_Init():
** * Configures Overall microprocessor for desired operation.
**
** Mcu_InterruptInhibit():
** * Inhibits (Maskable) interrupts, storing prior status of interrupt enable.
**
** Mcu_InterruptRestore():
** * Restores interrupt enable status to previously stored state.
**
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
** Include Files
*/

   /* Type Definitions */
   #include "..\..\..\Types.h"


/*
** Function Prototypes:
*/
   #include "Mcu.h"             /* Function Prototypes & Definitions for configuration constants */
   #include "..\port\port.h"    /* Access to Port_Init()  */
   #include "..\rti\rti.h"      /* Access to RTI_Init()   */



/*
** Global Variables:
*/


/*
** Local Variables:
*/

/*
**  Module code begins:
*/

/**************************************************************************
**
** Function Name:   Mcu_Init()
**
** Function Description:
**  - Configures Overall microprocessor for desired operation.
**
**    NOTE: The constant values are defined in mcu_cfg.h.
**
** Inputs:
**   (none)
**
** Output:
**   (none)
**
** Usage:
**   Call to this function from should be in the format of
**    Mcu_Init();
**
***************************************************************************
** System Interface:
** - Port_Init() - Configures Overall System Input/Output ports for desired operation.
** - RTI_Init()  - Configures the Real-Time Interrupt for desired operation.
** - Mcu_InterruptEnable() - Enables microcontroller interrupts. 
**
**************************************************************************/
void Mcu_Init(void)
{
    /*
    ** Configures Microcontroller System for desired operation:
    */
    Port_Init();                /* Configures Overall System Input/Output ports for desired operation */
    RTI_Init();                 /* Initialize the Real-Time Interrupt.        */
    Mcu_InterruptEnable();      /* Enable microcontroller interrupt services. */

}



/**************************************************************************
**
** Function Name:   Mcu_InterruptInhibit()
**
** Function Description:
**  - Inhibits (Maskable) interrupts, storing prior status of interrupt enable.
**
** Inputs:
**   (none)
**
** Output:
**   (none)
**
** Usage:
**   Call to this function from should be in the format of
**    Mcu_InterruptInhibit(&interruptStatusLocalStore);
**
***************************************************************************
** System Interface:
** - CCR - Value of Condition Code Register.
**
**************************************************************************/
void Mcu_InterruptInhibit(uint8_t * interruptStatusLocalStore)
{
   /* Store current Interrupt Enable state: */
   asm
   {
       TFR   D,X     ; Move the Destination Pointer (A:B), passed parameter, to Index Register
       TPA           ; Transfer CCR to A , (CCR) => A
       STAA  0,X     ; Store contents of CCR at Destination Pointer location
   }
    
   /* Unconditionally Disable interrupts: */
   Mcu_InterruptDisable();

   return;
}


/**************************************************************************
**
** Function Name:   Mcu_InterruptRestore()
**
** Function Description:
**  - Restores (Maskable) interrupt enable status to previously stored state.
**
** Inputs:
**   (none)
**
** Output:
**   (none)
**
** Usage:
**   Call to this function from should be in the format of
**    Mcu_InterruptRestore(&interruptStatusLocalStore);
**
***************************************************************************
** System Interface:
** - CCR - Value of Condition Code Register.
**
**************************************************************************/

void Mcu_InterruptRestore(uint8_t * interruptStatusLocalStore)
{
   /* Restore stored Interrupt Enable state: */
   asm
   {
       TFR   D,X          ; Move the Destination Pointer (A:B), passed parameter, to Index Register
       LDAA  0,X          ; Retrieve previous contents of CCR from Destination Pointer location
       ANDA  #CCR_MASK_I  ; Mask-off "I" bit
       BEQ   Clear        ; If the previous value of "I" was Zero, Branch to Clear the "I" bit
Set:                      ; Else,
       SEI                ;  Set the "I" bit
       BRA   Continue     ;  Continue
Clear:
       CLI                ;  Clear the "I" bit
Continue:

   }

   return;
}

#if(0) /* Implemented as Macros in mcu_cfg.h */
 void     Mcu_InterruptEnable(void){}        /* Unconditionally Enables  Maskable interrupts */
 void     Mcu_InterruptDisable(void){}       /* Unconditionally Disables Maskable interrupts */
#endif
