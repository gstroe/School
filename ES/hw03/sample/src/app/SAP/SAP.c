/**************************************************************************
**
** Module Name:   SAP.c
**
** Module Description:
**  Simple Application (SAP) to demonstrate basic abstraction.
**
** SAP_Init():
**  Initializes the SAP attributes.
**
** SAP_Task():
**  Periodic Task invoked by the System.
**
** Set_ApplicationOutput():
**  Sets the ApplicationOutput to the specified value.
**
** Get_ApplicationOutput():
**  Returns the current value of ApplicationOutput.
**
***************************************************************************
**
** Author:          Benjamin D. Sweet
** Revision:        1.2
** Creation Date:   15-Jan-2012
** Edit Date:       26-Oct-2012
**
***************************************************************************
**
** Revision History:
**
** Revision: 1.2    26-Oct-2012   B.Sweet
** * Use tempUserInput in preparation of newApplicationOutput.
**
** Revision: 1.1    16-Oct-2012   B.Sweet
** * Revise for boolean values.
** * Revise to work with DemoProj architecture.
**
** Revision: 1.0    15-Jan-2012   B.Sweet
** * Original version.
**  
**************************************************************************/

/*
** Include files:
*/
   /* Project Configuration */
   #include "..\..\project_cfg.h"
   /* Type Definitions */
   #include "..\..\Types.h"

   /* Component Configuration */
   #include "SAP_cfg.h"

   /* Access to published signal accessors: */
   #include "..\..\svc\io_mgr\io_mgr.h"

/*
** Local Function Prototypes:
*/
  /* Methods: */
  void      SAP_Init(void);
  void      SAP_Task(void);
  
  /* Accessors: */
  void      Set_ApplicationOutput1(uint8_t SetValue);
  void      Set_ApplicationOutput2(uint8_t SetValue);
  uint8_t   Get_ApplicationOutput1(void);
  uint8_t   Get_ApplicationOutput2(void);

/*
** File-Scope Global Variables:
*/

  /*
  ** Define interface signal variables:
  */
  /* Inputs: */
  
  /* Outputs: */
  uint8_t   ApplicationOutput1   = APPLICATION_OUTPUT_INIT;  /* Current value of Application Output */
  uint8_t   ApplicationOutput2   = APPLICATION_OUTPUT_INIT;  /* Current value of Application Output */


#ifdef DEBUG
   /*
   ** Global Variables for DEBUG:  (Otherwise these are Local variables.)
   */
    uint8_t  tempUserInput1; 	        /* Temporary variable for reading UserInput1             */
    uint8_t  tempUserInput2; 	        /* Temporary variable for reading UserInput2             */
    uint8_t  newApplicationOutput1;      /* Temporary variable for gerenating ApplicationOutput1  */
    uint8_t  newApplicationOutput2;      /* Temporary variable for gerenating ApplicationOutput2  */

#endif /* DEBUG */

/*
**  Module code begins:
*/

/**************************************************************************
**
** Function Name:   SAP_Init()
**
** Function Description:
**  - Initializes the value of SAP (Simple Application) attributes.
**
** Inputs:
**   (none)
**
** Return:
**   (none)
**
** Usage:
**   Call to this function from should be in the format of
**    SAP_Init();
**
***************************************************************************
** System Interface:
** -  . 
**
**************************************************************************/
void SAP_Init(void)
{
   /* Published Signals: */
   Set_ApplicationOutput1(APPLICATION_OUTPUT_INIT);
   Set_ApplicationOutput2(APPLICATION_OUTPUT_INIT);

   return;
}  /* End: SAP_Init() */


/**************************************************************************
**
** Function Name:   SAP_Task()
**
** Function Description:
**  - Periodic Task invoked by the System. r
**
** Inputs:
**   (none)
**
** Return:
**   (none)
**
** Usage:
**   Call to this function from should be in the format of
**    SAP_Task();
**
***************************************************************************
** System Interface:
** - Invoked by System.
**
**************************************************************************/
void SAP_Task(void)
{
   /*
   ** Local variables:
   */
#ifndef DEBUG    /* Variables defined as Global for DEBUG: */
    uint8_t  tempUserInput1; 	        /* Temporary variable for reading UserInput1             */
    uint8_t  tempUserInput2; 	        /* Temporary variable for reading UserInput2             */
    uint8_t  newApplicationOutput1;      /* Temporary variable for gerenating ApplicationOutput1  */
    uint8_t  newApplicationOutput2;      /* Temporary variable for gerenating ApplicationOutput2  */
#endif

   /*
   ** Determine new AplicationOutput1 based on UserInput1:
   */
   tempUserInput1 = Get_UserInput1();
   tempUserInput2 = Get_UserInput2();

   /*
   ** XOR the input
   */   
   newApplicationOutput1 = tempUserInput1 ^ tempUserInput2;

   /* Publish Output signal: */
   Set_ApplicationOutput1(newApplicationOutput1);
   
   
   /*
   ** AND the input
   */   
   newApplicationOutput2 = tempUserInput1 & tempUserInput2;

   /* Publish Output signal: */
   Set_ApplicationOutput2(newApplicationOutput2);

   return;
}  /* End: SAP_Task() */


/**************************************************************************
**
** Function Name:   Set_ApplicationOutputX()
**
** Function Description:
**  - Sets the ApplicationOutput of X to the specified value.
**
** Inputs:
**   uint8_t: SetValue
**
** Return:
**   (none)
**
** Usage:
**   Call to this function from should be in the format of
**    Set_ApplicationOutputX(SetValue);
**
***************************************************************************
** System Interface:
** - . 
**
**************************************************************************/
void Set_ApplicationOutput1(uint8_t SetValue)
{
   ApplicationOutput1 = SetValue;

   return;
} /* End: Set_ApplicationOutput1() */


void Set_ApplicationOutput2(uint8_t SetValue)
{
   ApplicationOutput2 = SetValue;

   return;
} /* End: Set_ApplicationOutput2() */


/**************************************************************************
**
** Function Name:   Get_ApplicationOutput()
**
** Function Description:
**  - Returns the current value of ApplicationOutput.
**
** Inputs:
**   (none)
**
** Output:
**   uint8_t: ApplicationOutput
**
** Usage:
**   Call to this function from should be in the format of
**    Get_ApplicationOutput();
**
***************************************************************************
** System Interface:
** - . 
**
**************************************************************************/
uint8_t Get_ApplicationOutput1(void)
{
   /* Return the current ApplicationOutput */
   return ApplicationOutput1;

} /* End: Get_ApplicationOutput() */
uint8_t Get_ApplicationOutput2(void)
{
   /* Return the current ApplicationOutput */
   return ApplicationOutput2;

} /* End: Get_ApplicationOutput() */
