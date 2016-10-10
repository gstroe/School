/**************************************************************************
**
** Module Name:   Dio.c
**
** Module Description:  Digital Input/Output Port functions.
**  Define functions for Digital I/O Port operation.
**
** Port_Init():
**  Configures general purpose Input/Output ports for desired operation.
**
** Port Accessors:
**
** Dio_ReadChannel():
**  Returns the level of the specified DIO channel.
**
** Dio_WriteChannel():
**  Sets the level of the specified DIO channel.
**
** Dio_ReadPort():
**  Returns the level of all channels of the specified port.
**
** Dio_WritePort():
**  Set the level of all channels of the specified port.
**
** Dio_ReadChannelGroup():
**  Reads a subset of the adjoining channels of a port.
**
** Dio_WriteChannelGroup():
**  Set a subset of the adjoining channels of a port to the specified levels.
**
** Dio_FlipChannel():
**  Flip (change from 1 to 0 or from 0 to 1) the level of a channel and return the level of the channel after flip.
**
Deprecated:
** GetPortA():       \ Reads data from specified Input Port.
** GetPortB():       /
**
** TestBitPortA():   \ Returns state (TRUE,FALSE) of specified bit in specified Input Port.
** TestBitPortB():   /
**
** SetPortA():       \ Writes specified value on specified Output Port.
** SetPortB():       /
**
** SetMaskPortA():   \ Sets specified Mask on specified Output Port.
** SetMaskPortB():   /
**
** ClearMaskPortA(): \ Clears specified Mask on specified Output Port.
** ClearMaskPortB(): /
**
** SetBitPortA():    \ Sets specified bit in specified Output Port.
** SetBitPortB():    /
**
** ClearBitPortA():  \ Clears specified bit in specified Output Port.
** ClearBitPortB():  /
**
***************************************************************************
**
**  Author:      Ben Sweet
**  Revision:    2.4
**  Date:        22-May-2013
**
***************************************************************************
**
** Revision History:
**
** Revision: 2.4   22-May-2013    Ben Sweet
** * Add Dio_InitGPIO().
** * Correct various errors related to splitting DIO_PortPtrTable[] into
**    DIO_DataPortPtrTable[] and DIO_DdrPortPtrTable[].
**
** Revision: 2.3   17-May-2013    Ben Sweet, Gabriel Moreno, Leonardo Bueno
** * Split DIO_PortPtrTable[] into two tables:
**   + DIO_DataPortPtrTable[] for Data port registers
**   + DIO_DdrPortPtrTable[]  for Data Direction registers
** * Rename DIO_ChannelGroup[] to DIO_ChannelGroupTable[].
** * Corrected code of Dio_WriteChannelGroup and Dio_ReadChannelGroup.
**   Both these functions were not using the Dio_Groups table to obtain the
**   group information. They were using a Dio_GroupType pointer there were returning
**   the wrong information.
**   The OutputClearMask was also done wrong, and now is corrected. They way it was
**   before the ClearMask was clearing the same bit set in SetMask.
**
** Revision: 2.2   26-Oct-2012    Ben Sweet, Gabriel Moreno, Leonardo Bueno
** * Correction in Dio_ReadChannelGroup(): Shift FIRST, THEN Mask.
**   (Mask is relative to LSBit.)
**
** Revision: 2.2   16-Oct-2012    Ben Sweet
** * In Dio_Init(), added "simple abstraction" initialization for Port K and Port T.
**
** Revision: 2.1   02-Jun-2012    Ben Sweet
** * Added accessors Dio_SetChannel(), Dio_SetPort().
**   These are similar to Dio_WriteChannel() and Dio_WritePort(), except that they
**   unconditionally write the Channel or Port regardless of whether it is configured
**   as an Input or Output.
**   This may be used for register configuration (DDR registers.)
**
** Revision: 2.0   26-May-2012    Ben Sweet
** * Extracted from Port component.
** * Deprecated Get/Set Port/Mask accessors:
**   GetPortX, SetPortX, SetMaskPortX, ClearMaskPortX, SetBitPortX, ClearBitPortX, TestBitPortX.
** * Added Autosar-like accessors based on DIO Driver naming convention:
**   Dio_Init(), Dio_ReadChannel(), Dio_WriteChannel(), Dio_ReadPort(), Dio_WritePort(), 
**   Dio_ReadChannelGroup(), Dio_WriteChannelGroup(), Dio_FlipChannel()
**
**   Re: "Specification of DIO Driver", V2.5.0, R4.0 Rev3
**       http://autosar.org/download/R4.0/AUTOSAR_SWS_DIODriver.pdf
**
** Revision: 1.1   06-Jun-2008    Ben Sweet
** * Added Port Accessor macros (defined in Port_cfg.h):
**   GetPortX, SetPortX, SetMaskPortX, ClearMaskPortX, SetBitPortX, ClearBitPortX, TestBitPortX.
**
**   Re: "An architecture for designing reusable embedded systems software, Part 2", Dinu Madau
**        http://embedded.com/design/opensource/207403738?pgno=2
**
** Revision: 1.0   04-Jun-2008    Ben Sweet
** * Original version based on existing methods in general use.
**  
**************************************************************************/

/*
** Include Files
*/

   /*
   ** Function Prototypes:
   */
   #include "Dio.h"  /* Standard Type Definitions, Function Prototypes, and Definitions for configuration constants */

   /*
   ** NON-standard Accessors - NOT to be Externed in Dio.h:
   */
   void Dio_SetChannel( Dio_ChannelType ChannelId, Dio_LevelType Level );
   void Dio_SetPort( Dio_PortType PortId, Dio_PortLevelType Level );


/*
** Global Variables:
*/
   extern Dio_ChannelStructType DIO_Channel[];
   extern uint8_t * DIO_DataPortPtrTable[];  /* For Data port registers      */
   extern uint8_t * DIO_DdrPortPtrTable[];   /* For Data Direction registers */
   extern Dio_ChannelGroupType DIO_ChannelGroupTable[];

#if defined(MXVDEV)
  /* 
  ** For MxVDev simulation environments:
  ** + Define Input Output registers 
  */
  uint8_t DigIN;
  uint8_t DigOUT;
#endif


/*
** Local Variables:
*/

/*
**  Module code begins:
*/

/**************************************************************************
**
** Function Name:   Dio_Init()
**
** Function Description:
**  - Configures general purpose Digital Input/Output ports for desired operation.
**
**    NOTE: The constant values are defined in dio_cfg.h.
**
** Inputs:
**   (none)
**
** Output:
**   (none)
**
** Usage:
**   Call to this function from should be in the format of
**    Dio_Init();
**
***************************************************************************
** System Interface:
** -  PORTA - 
** -  DDRA - 
** -  PORTB - 
** -  DDRB - 
** -  PORTK - 
** -  DDRK - 
** -  PPT - 
** -  DDRT - 
**
**************************************************************************/
void Dio_Init(void)
{
#ifndef MXVDEV
    /*
    ** Configuration of general purpose Digital Input/Output port registers:
    **  Configuration values defined in Dio_cfg.h.
    */
  #if(1)  /* Simple Abstraction: */
    PORTA   = PORTA_CFG_INIT;  /* Port A Data           */
    DDRA    = DDRA_CFG_INIT;   /* Port A Data Direction */

    PORTB   = PORTB_CFG_INIT;  /* Port B Data           */
    DDRB    = DDRB_CFG_INIT;   /* Port B Data Direction */
    
    PORTK   = PORTK_CFG_INIT;  /* Port K Data           */
    DDRK    = DDRK_CFG_INIT;   /* Port K Data Direction */
    
    PTT     = PORTT_CFG_INIT;  /* Port T Data           */
    DDRT    = DDRT_CFG_INIT;   /* Port T Data Direction */

  #else   /* AUTOSAR Driver: */
    Dio_SetPort ( DIO_PortA , (Dio_PortLevelType)PORTA_CFG_INIT );
    Dio_SetPort ( DIO_DDRA  , (Dio_PortLevelType)DDRA_CFG_INIT  );

    Dio_SetPort ( DIO_PortB , (Dio_PortLevelType)PORTB_CFG_INIT );
    Dio_SetPort ( DIO_DDRB  , (Dio_PortLevelType)DDRB_CFG_INIT  );

    Dio_SetPort ( DIO_PortK , (Dio_PortLevelType)PORTK_CFG_INIT );
    Dio_SetPort ( DIO_DDRK  , (Dio_PortLevelType)DDRK_CFG_INIT  );

    Dio_SetPort ( DIO_PortT , (Dio_PortLevelType)PORTT_CFG_INIT );
    Dio_SetPort ( DIO_DDRT  , (Dio_PortLevelType)DDRT_CFG_INIT  );
  #endif

#endif
}




/* [DIO133]
** Service Name: Dio_ReadChannel
** Syntax: Dio_LevelType Dio_ReadChannel( Dio_ChannelType ChannelId )
** Service ID[hex]: 0x00
** Parameters:    ChannelId - ID of DIO Channel
** Return Value:  Dio_LevelType - STD_HIGH if the physical level of the corresponding Pin is STD_HIGH.
**                                STD_LOW  if the physical level of the corresponding Pin is STD_LOW.
**
** Description: Returns the level of the specified DIO channel.
**
**  [DIO027] The Dio_ReadChannel function shall return the value of the specified DIO channel.
**  Furthermore, the requirements DIO005, DIO118 and DIO026 are applicable to the Dio_ReadChannel function.
*/
Dio_LevelType Dio_ReadChannel( Dio_ChannelType ChannelId )
{
   Dio_LevelType Level = STD_LOW; /* Return Value: Level of the specified Input Channel. */

   uint8_t       channelBit;     /* Bit position of Channel in the Port. */
   uint8_t       channelMask;    /* Mask for Channel Bit position in the Port. */
   Dio_PortType  portTableIndex; /* Index into DIO_PortPtrTable[]. */
   uint8_t *     portPtr;        /* Pointer to the Port in which the Input Channel is defined. */

   /* Verify specified Channel is valid: */
   if (ChannelId >= DIO_MAX_CHANNELS)
   {  /* Error Condition: specified DIO Channel out of range: */
      ;
   }
   else
   {
      portTableIndex = DIO_Channel[ChannelId].port;

      /* Verify specified Port is valid: */
      if (portTableIndex >= DIO_MAX_PORTS)
      {  /* Error Condition: specified DIO Port out of range: */
         ;
      }
      else
      {
         portPtr = DIO_DataPortPtrTable[portTableIndex];  /* Get pointer to specified Port */
         channelBit = DIO_Channel[ChannelId].bit;         /* Get Channel Bit Postion in Port. */
         /* Generate Bit Mask, assuring that specified bit number fits in Port size. */
         channelMask = (1u<<((uint8_t)0x07u & channelBit));

         if ( ((*portPtr) & channelMask) != 0u )
         {
            Level = STD_HIGH;
         }
      }
   }
   
   return Level;
}

/* [DIO134]
** Service Name: Dio_WriteChannel
** Syntax: void Dio_WriteChannel( Dio_ChannelType ChannelId, Dio_LevelType Level )
** Service ID[hex]: 0x01
** Parameters:    ChannelId - ID of DIO Channel
**                Level     - Value to be written
** Return Value:  None
**
** Description: Sets the level of the specified DIO channel.
**
**  [DIO028] If the specified channel is configured as an output channel, the Dio_WriteChannel function
**            shall set the specified Level for the specified channel.
**  [DIO029] If the specified channel is configured as an input channel, the Dio_WriteChannel function
**            shall have no influence on the physical output.
**  [DIO079] If the specified channel is configured as an input channel, the Dio_WriteChannel function
**            shall have no influence on the result of the next Read-Service.
**  Furthermore, the requirements DIO005, DIO119 and DIO026 are applicable to the Dio_WriteChannel function.
*/
void Dio_WriteChannel( Dio_ChannelType ChannelId, Dio_LevelType Level )
{
   uint8_t       channelBit;     /* Bit position of Channel in the Port. */
   uint8_t       channelMask;    /* Mask for Channel Bit position in the Port. */
   uint8_t       dataDirectionValue; /* Value of Channel Data Direction */
   Dio_PortType  portTableIndex; /* Index into DIO_DataPortPtrTable[] and DIO_DdrPortPtrTable[]. */
   uint8_t *     portPtr;        /* Pointer to the Port in which the Input Channel is defined. */
   uint8_t *     ddrPtr;         /* Pointer to the Port Data Direction Register. */

   /* Verify specified Channel is valid: */
   if (ChannelId >= DIO_MAX_CHANNELS)
   {  /* Error Condition: specified DIO Channel out of range: */
      ;
   }
   else
   {
      portTableIndex = DIO_Channel[ChannelId].port;

      /* Verify specified Port is valid: */
      if (portTableIndex >= DIO_MAX_PORTS)
      {  /* Error Condition: specified DIO Port out of range: */
         ;
      }
      else
      {
         portPtr = DIO_DataPortPtrTable[portTableIndex];    /* Get pointer to specified Port. */
         ddrPtr  = DIO_DdrPortPtrTable[portTableIndex];     /* Get pointer to specified Port's Data Direction Register. */
         channelBit = DIO_Channel[ChannelId].bit & (uint8_t)0x07u;  /* Get Channel Bit Postion in Port, assuring that specified bit number fits in Port size. */

         /* Get the Data Direction for the specified Channel: */
         dataDirectionValue   = (*ddrPtr);      /* Get Port Data Direction. */
         dataDirectionValue >>= channelBit;     /* Shift Data Direction for selected Channel to LSBit. */
         dataDirectionValue  &= (uint8_t)1u;    /* Mask-off the individual Channel Data Direction. */

         /* Only write the Channel if it is configured as an Output: */
         if ( dataDirectionValue == (uint8_t)DIO_DATA_DIRECTION_CHANNEL_OUTPUT )
         {
            /* Generate Bit Mask: */
            channelMask = (1u << channelBit);

            /* Clear the Channel if specified Level is LOW: */
            if (Level == STD_LOW)
            {
               (*portPtr) &= ~channelMask;
            }
            /* Otherwise Set the Channel to HIGH: */
            else
            {
               (*portPtr) |= channelMask;
            }
         }
      }
   }

   return;
}

/* [DIO135]
** Service Name: Dio_ReadPort
** Syntax: Dio_PortLevelType Dio_ReadPort( Dio_PortType PortId )
** Service ID[hex]: 0x02
** Parameters:    PortId            - ID of DIO Port
** Return Value:  Dio_PortLevelType - Level of all channels of that port
**
** Description: Returns the level of all channels of the specified port.
**
**  [DIO031] The Dio_ReadPort function shall return the level of all channels of that port.
**  [DIO104] When reading a port which is smaller than the Dio_PortType using the Dio_ReadPort function
**           (see [DIO103]), the function shall set the bits corresponding to undefined port pins to 0.
**  Furthermore, the requirements DIO005, DIO118 and DIO026 are applicable to the Dio_ReadPort function.
*/
Dio_PortLevelType Dio_ReadPort( Dio_PortType PortId )
{
   Dio_PortLevelType Level = (Dio_PortLevelType)0u;     /* Return Value: Level of all channels of the specified port. */

   uint8_t *     portPtr;                               /* Pointer to the specified Port. */

   /* Verify specified Port is valid: */
   if (PortId >= DIO_MAX_PORTS)
   {  /* Error Condition: specified DIO Port out of range: */
      ;
   }
   else
   {
      portPtr = DIO_DataPortPtrTable[PortId];   /* Get pointer to specified Port  */
      Level = (Dio_PortLevelType)(*portPtr);    /* Get contents of specified Port */
   }

   return Level;
}

/* [DIO136]
** Service Name: Dio_WritePort
** Syntax: void Dio_WritePort( Dio_PortType PortId, Dio_PortLevelType Level )
** Service ID[hex]: 0x03
** Parameters:    PortId    - ID of DIO Port
**                Level     - Value to be written
** Return Value:  None
**
** Description: Set the level of all channels of the specified port.
**
**  [DIO034] The Dio_WritePort function shall set the specified value for the specified port.
**  [DIO035] When the Dio_WritePort function is called, DIO Channels that are configured as input shall remain unchanged.
**  [DIO105] When writing a port which is smaller than the Dio_PortType using the Dio_WritePort function
**           (see [DIO103]), the function shall ignore the MSB.
**  [DIO108] The Dio_WritePort function shall have no effect on channels within this port which are configured as input channels
**  Furthermore, the requirements DIO005, DIO119 and DIO026 are applicable to the Dio_WritePort function.
*/
void Dio_WritePort( Dio_PortType PortId, Dio_PortLevelType Level )
{
   uint8_t       channelOutputMask;  /* Mask for Channel Bits configured as Outputs. */
   uint8_t       channelOutputSetMask;    /* Mask for Setting Channel Bits.  */
   uint8_t       channelOutputClearMask;  /* Mask for Clearing Channel Bits. */
   uint8_t *     portPtr;            /* Pointer to the Port in which the Input Channel is defined. */
   uint8_t *     ddrPtr;             /* Pointer to the Port Data Direction Register.    */

   /* Verify specified Port is valid: */
   if (PortId >= DIO_MAX_PORTS)
   {  /* Error Condition: specified DIO Port out of range: */
      ;
   }
   else
   {
      portPtr = DIO_DataPortPtrTable[PortId];   /* Get pointer to specified Port. */
      ddrPtr  = DIO_DdrPortPtrTable[PortId];    /* Get pointer to specified Port's Data Direction Register. */

      /*
      ** Generate Output Bit Mask:
      */
      /* Only write the Channels that are configured as Outputs: */
      channelOutputMask = (uint8_t)(*ddrPtr);
      if (DIO_DATA_DIRECTION_CHANNEL_OUTPUT == 0u)
      {
         channelOutputMask = ~channelOutputMask;   /* Invert the Data Direction for "Positive Logic" */
      }
      channelOutputSetMask   =   channelOutputMask  & Level;
      channelOutputClearMask = (~channelOutputMask) | Level;

      /* Only write the Port Channels configured as a Outputs: */
      /* Set the Ouptut Channels specified as Level HIGH: */
      (*portPtr) |= channelOutputSetMask;
      /* Clear the Ouptut Channels specified as Level LOW: */
      (*portPtr) &= channelOutputClearMask;
   }

   return;
}

/* [DIO137]
** Service Name: Dio_ReadChannelGroup
** Syntax: Dio_PortLevelType Dio_ReadChannelGroup( const Dio_ChannelGroupType* ChannelGroupId )
** Service ID[hex]: 0x04
** Parameters:    ChannelGroupId - Pointer to ChannelGroup
** Return Value:  Dio_PortLevelType - Level of a subset of the adjoining bits of a port
**
** Description: Reads a subset of the adjoining channels of a port.
**
**  [DIO037] The Dio_ReadChannelGroup function shall read a subset of the adjoining bits of a port (channel group).
**  [DIO092] The Dio_ReadChannelGroup function shall do the masking of the channel group.
**  [DIO093] The Dio_ReadChannelGroup function shall do the shifting so that the values read by the function are aligned to the LSB.
**  Furthermore, the requirements DIO005, DIO056, DIO083, DIO084, DIO118 and DIO026 are applicable to the Dio_ReadChannelGroup function.
*/
Dio_PortLevelType Dio_ReadChannelGroup( Dio_ChannelGroups ChannelGroupId )
{
   Dio_PortLevelType Level = (Dio_PortLevelType)0u;     /* Return Value: Level of all channels of the specified Channel Group - aligned to the LSB. */

   uint8_t       groupOffset;       /* Bit Offset of Channel Group in the Port. */
   uint8_t       groupMask;         /* Mask for Channel Group in the Port. */
   Dio_PortType  portTableIndex;    /* Index into DIO_DataPortPtrTable[]. */
   uint8_t *     portPtr;           /* Pointer to the Port in which the Input Channel is defined. */

   portTableIndex = DIO_ChannelGroupTable[ChannelGroupId].port;

   /* Verify specified Port is valid: */
   if (portTableIndex >= DIO_MAX_PORTS)
   {  /* Error Condition: specified DIO Port out of range: */
      ;
   }
   else
   {
      portPtr = DIO_DataPortPtrTable[portTableIndex];   /* Get pointer to specified Port */
      
      /* Get group mask for the specific channel */
      groupOffset = (uint8_t)(DIO_ChannelGroupTable[ChannelGroupId].offset); /* Get Bit Offset of Channel Group in the Port. */
      groupMask   = (uint8_t)(DIO_ChannelGroupTable[ChannelGroupId].mask);   /* Get Mask for Channel Group in the Port. */

      /* Verify that Offset is valid: */
      if (groupOffset > (sizeof(Dio_PortLevelType) << 3) )  /* #Bytes * 8 = #Bits in PortLevelType */
      {  /* Error Condition: specified Offset is larger than Port size: */
        ;
      }
      else
      {
        Level   = (Dio_PortLevelType)(*portPtr);    /* Get Port contents. */
        Level >>= groupOffset;                      /* Align Group with LSBit. */ 
        Level  &= groupMask;                        /* Mask off Channels in the Group. */
      }
    }
 
   return Level;
}

/* [DIO138]
** Service Name: Dio_WriteChannelGroup
** Syntax: void Dio_WriteChannelGroup( Dio_ChannelGroups ChannelGroupId, Dio_PortLevelType Level )
** Service ID[hex]: 0x05
** Parameters:    ChannelGroupId - Pointer to ChannelGroup
**                Level             - Value to be written
** Return Value:  None
**
** Description: Set a subset of the adjoining channels of a port to the specified levels.
**
**  [DIO039] The Dio_WriteChannelGroup function shall set a subset of the adjoining bits of a port (channel group) to a specified level.
**  [DIO040] The Dio_WriteChannelGroup shall not change the remaining channels of the port and channels which are configured as input.
**  [DIO090] The Dio_WriteChannelGroup function shall do the masking of the channel group.
**  [DIO091] The function Dio_WriteChannelGroup shall do the shifting so that the values written by the function are aligned to the LSB.
**  Furthermore, the requirements DIO005, DIO056, DIO119 and DIO026 are applicable for the Dio_WriteChannelGroup function.
*/
void Dio_WriteChannelGroup( Dio_ChannelGroups ChannelGroupId, Dio_PortLevelType Level )
{
   uint8_t       groupOffset;        /* Bit Offset of Channel Group in the Port. */
   uint8_t       groupMask;          /* Mask for Channel Group in the Port. */
   uint8_t       channelOutputMask;  /* Mask for Channel Bits configured as Outputs. */
   uint8_t       channelOutputSetMask;    /* Mask for Setting Channel Bits.  */
   uint8_t       channelOutputClearMask;  /* Mask for Clearing Channel Bits. */
   uint8_t       dataDirectionValue; /* Value of Channel Data Direction */
   Dio_PortType  portTableIndex;     /* Index into DIO_DataPortPtrTable[] and DIO_DdrPortPtrTable[]. */
   uint8_t *     portPtr;            /* Pointer to the Port in which the Input Channel is defined. */
   uint8_t *     ddrPtr;             /* Pointer to the Port Data Direction Register. */

   portTableIndex = DIO_ChannelGroupTable[ChannelGroupId].port;

   /* Verify specified Port is valid: */
   if (portTableIndex >= DIO_MAX_PORTS)
   {  	/* Error Condition: specified DIO Port out of range: */
		;
   }
   else
   {
        portPtr = DIO_DataPortPtrTable[portTableIndex];    /* Get pointer to specified Port. */
        ddrPtr  = DIO_DdrPortPtrTable[portTableIndex];     /* Get pointer to specified Port's Data Direction Register. */
        groupOffset = (uint8_t)(DIO_ChannelGroupTable[ChannelGroupId].offset); /* Get Bit Offset of Channel Group in the Port. */
        groupMask   = (uint8_t)(DIO_ChannelGroupTable[ChannelGroupId].mask);   /* Get Mask for Channel Group in the Port. */

        /* Verify that Offset is valid: */
        if (groupOffset > (sizeof(Dio_PortLevelType) << 3) )  /* #Bytes * 8 = #Bits in PortLevelType */
        {  /* Error Condition: specified Offset is larger than Port size: */
            ;
        }
        else
        {
            /* Only write the Channels that are configured as Outputs: */
            dataDirectionValue = (uint8_t)(*ddrPtr);
            if (DIO_DATA_DIRECTION_CHANNEL_OUTPUT == 0u)
            {
                dataDirectionValue = ~dataDirectionValue;    /* Invert the Data Direction for "Positive Logic" */
            }

            /*
            ** Generate Output Bit Masks:
            */
            channelOutputMask   = (uint8_t)Level & groupMask;   /* Assure that specified Level fits within the specified Mask. */
            channelOutputMask <<= groupOffset;                  /* Shift the Output Mask to the Offset position. */

            channelOutputSetMask   =   dataDirectionValue  & channelOutputMask;
            channelOutputClearMask = (~dataDirectionValue) | channelOutputMask;

            /* Only write the Port Channels configured as a Outputs: */
            /* Set the Ouptut Channels specified as Level HIGH: */
            (*portPtr) |= channelOutputSetMask;
            /* Clear the Ouptut Channels specified as Level LOW: */
            (*portPtr) &= channelOutputClearMask;
        }
    }

    return;
}

/* [DIO190]
** Service Name: Dio_FlipChannel
** Syntax: Dio_LevelType Dio_FlipChannel( Dio_ChannelType ChannelId )
** Service ID[hex]: 0x11
** Parameters:    ChannelId     - ID of DIO Channel
** Return Value:  Dio_LevelType - STD_HIGH if the physical level of the corresponding Pin is STD_HIGH.
**                                STD_LOW  if the physical level of the corresponding Pin is STD_LOW.
**
** Description: Flip (change from 1 to 0 or from 0 to 1) the level of a channel and return the level of the channel after flip.
**
**  [DIO191] If the specified channel is configured as an output channel, the Dio_FlipChannel function shall read level of the channel 
**           (requirements [DIO083] & [DIO084] are applicable) and invert it, then write the inverted level to the channel.
**            The return value shall be the inverted level of the specified channel.
**  [DIO192] If the specified channel is configured as an input channel, the Dio_FlipChannel function shall have no influence on the physical output.
**            The return value shall be the level of the specified channel.
**  [DIO193] If the specified channel is configured as an input channel, the Dio_FlipChannel function shall have no influence on the result of the next Read-Service.
**  Furthermore, the requirements DIO005, DIO119 and DIO026 are applicable to the Dio_FlipChannel function.
*/
Dio_LevelType Dio_FlipChannel( Dio_ChannelType ChannelId )
{
   Dio_LevelType Level = STD_LOW;     /* Return Value: Level of the specified Input Channel. */

   uint8_t       channelBit;         /* Bit position of Channel in the Port. */
   uint8_t       channelMask;        /* Mask for Channel Bit position in the Port. */
   uint8_t       dataDirectionValue; /* Value of Channel Data Direction */
   Dio_PortType  portTableIndex;     /* Index into DIO_DataPortPtrTable[] and DIO_DdrPortPtrTable[]. */
   uint8_t *     portPtr;            /* Pointer to the Port in which the Input Channel is defined. */
   uint8_t *     ddrPtr;             /* Pointer to the Port Data Direction Register. */

   /* Verify specified Channel is valid: */
   if (ChannelId >= DIO_MAX_CHANNELS)
   {  /* Error Condition: specified DIO Channel out of range: */
      ;
   }
   else
   {
      portTableIndex = DIO_Channel[ChannelId].port;

      /* Verify specified Port is valid: */
      if (portTableIndex >= DIO_MAX_PORTS)
      {  /* Error Condition: specified DIO Port out of range: */
         ;
      }
      else
      {
         portPtr = DIO_DataPortPtrTable[portTableIndex];    /* Get pointer to specified Port. */
         ddrPtr  = DIO_DdrPortPtrTable[portTableIndex];     /* Get pointer to specified Port's Data Direction Register. */
         channelBit = DIO_Channel[ChannelId].bit & (uint8_t)0x07u;  /* Get Channel Bit Postion in Port, assuring that specified bit number fits in Port size. */

         /* Get the Data Direction for the specified Channel: */
         dataDirectionValue   = (*ddrPtr);      /* Get Port Data Direction. */
         dataDirectionValue >>= channelBit;     /* Shift Data Direction for selected Channel to LSBit. */
         dataDirectionValue  &= (uint8_t)1u;    /* Mask-off the individual Channel Data Direction. */

         /* Only write the Channel if it is configured as an Output: */
         if ( dataDirectionValue == (uint8_t)DIO_DATA_DIRECTION_CHANNEL_OUTPUT )
         {
            /* Generate Bit Mask: */
            channelMask = (1u << channelBit);

            /* Clear the Channel if specified Level is LOW: */
            if (Level == STD_LOW)
            {
               (*portPtr) &= ~channelMask;
            }
            /* Otherwise Set the Channel to HIGH: */
            else
            {
               (*portPtr) |= channelMask;
            }
         }

         /* Retrieve current Level of the Channel: */
         Level = ( ( ((*portPtr) & channelMask) == (uint8_t)0u ) ? STD_LOW : STD_HIGH );

      }
   }

   return Level;
}

/*
** NON-standard Accessors:
*/

/*
** Service Name: Dio_SetChannel
** Syntax: void Dio_SetChannel( Dio_ChannelType ChannelId, Dio_LevelType Level )
** Service ID[hex]: N/A
** Parameters:    ChannelId - ID of DIO Channel
**                Level     - Value to be written
** Return Value:  None
**
** Description: UNCONDITIONALLY Sets the level of the specified DIO channel.
**
** This function is similar to Autosar Dio_WriteChannel(), except that it does NOT follow 
**  [DIO028] , [DIO029],  [DIO079].
** It unconditionally writes the Channel regardless of whether it is configured
**   as an Input or Output
*/
void Dio_SetChannel( Dio_ChannelType ChannelId, Dio_LevelType Level )
{
   uint8_t       channelBit;     /* Bit position of Channel in the Port. */
   uint8_t       channelMask;    /* Mask for Channel Bit position in the Port. */
   Dio_PortType  portTableIndex; /* Index into DIO_PortPtrTable[]. */
   uint8_t *     portPtr;        /* Pointer to the Port in which the Input Channel is defined. */

   /* Verify specified Channel is valid: */
   if (ChannelId >= DIO_MAX_CHANNELS)
   {  /* Error Condition: specified DIO Channel out of range: */
      ;
   }
   else
   {
      portTableIndex = DIO_Channel[ChannelId].port;

      /* Verify specified Port is valid: */
      if (portTableIndex >= DIO_MAX_PORTS)
      {  /* Error Condition: specified DIO Port out of range: */
         ;
      }
      else
      {
         portPtr = DIO_DataPortPtrTable[portTableIndex];      /* Get pointer to specified Port. */
         channelBit = DIO_Channel[ChannelId].bit;             /* Get Channel Bit Postion in Port. */
         /* Generate Bit Mask, assuring that specified bit number fits in Port size. */
         channelMask = (1u<<((uint8_t)0x07u & channelBit));

         /* Clear the Channel if specified Level is LOW: */
         if (Level == STD_LOW)
         {
            (*portPtr) &= ~channelMask;
         }
         /* Otherwise Set the Channel to HIGH: */
         else
         {
            (*portPtr) |= channelMask;
         }
      }
   }

   return;
}

/*
** Service Name: Dio_SetPort
** Syntax: void Dio_SetPort( Dio_PortType PortId, Dio_PortLevelType Level )
** Service ID[hex]: N/A
** Parameters:    PortId    - ID of DIO Port
**                Level     - Value to be written
** Return Value:  None
**
** Description: UNCONDITIONALLY Set the level of all channels of the specified port.
**
** This function is similar to Autosar Dio_WritePort(), except that it does NOT follow 
**  [DIO035], [DIO108].
** It unconditionally writes the Port regardless of whether it is configured
**   as an Input or Output
*/
void Dio_SetPort( Dio_PortType PortId, Dio_PortLevelType Level )
{
   uint8_t *     portPtr;        /* Pointer to the Port in which the Input Channel is defined. */

   /* Verify specified Port is valid: */
   if (PortId >= DIO_MAX_PORTS)
   {  /* Error Condition: specified DIO Port out of range: */
      ;
   }
   else
   {
      portPtr = DIO_DataPortPtrTable[PortId];       /* Get pointer to specified Port. */

      /* Set the Port to the specified Level: */
      (*portPtr) = Level;
   }

   return;
}

/*
** Service Name: Dio_InitGPIO
** Syntax: void Dio_InitGPIO( Dio_PortType PortId, uint16_t DDR_CFG_INIT )
** Service ID[hex]: N/A
** Parameters:    PortId               - ID of DIO Port
**                DDR_CFG_INIT         - Data Direction Register Initial Configuration
** Return Value:  None
**
** Description: Initializes GPIO register.
**
** It only initalize GPIO ports and must not be used outside the DioInit() Function
*/
void Dio_InitGPIO( Dio_PortType PortId, uint8_t DDR_CFG_INIT )
{
   uint8_t *     portPtr;        /* Pointer to the Port register. */

   /* Verify specified Port is valid: */
   if (PortId >= DIO_MAX_PORTS)
   {  /* Error Condition: specified DIO Port out of range: */
      ;
   }
   else
   {
      portPtr = DIO_DdrPortPtrTable[PortId];       /* Get pointer to specified configuration register. */

      /* Set the configuration register to the specified value: */
      (*portPtr) = DDR_CFG_INIT;
   }

   return;
}
