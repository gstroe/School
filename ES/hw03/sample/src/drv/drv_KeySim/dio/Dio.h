#ifndef DIO_H
#define DIO_H
/**************************************************************************
**
** Module Name:   Dio.h
**
** Module Description:  Declarations for Digital Input/Output Port functions.
**  Delcare external functions Digital I/O Port operation.
**
***************************************************************************
**
**  Author:      Ben Sweet
**  Revision:    2.1
**  Date:        26-May-2012
**
***************************************************************************
**
** Revision History:
**
** Revision: 2.1   26-May-2012    Ben Sweet
** * Added type definition for Dio_ChannelStructType.
**
** Revision: 2.0   05-May-2012    Ben Sweet
** * Extracted from Port component.
** * Deprecated Get/Set Port/Mask accessors:
**   GetPortX, SetPortX, SetMaskPortX, ClearMaskPortX, SetBitPortX, ClearBitPortX, TestBitPortX.
** * Added type definition for Dio_LevelType: STD_LOW and STD_HIGH
**    as per http://autosar.org/download/R4.0/AUTOSAR_SWS_DIODriver.pdf.
** * Added Autosar-like accessors based on DIO Driver naming convention:
**   Dio_Init(), Dio_ReadChannel(), Dio_WriteChannel(), Dio_ReadPort(), Dio_WritePort(), 
**   Dio_ReadChannelGroup(), Dio_WriteChannelGroup(), Dio_FlipChannel()
**
**   Re: "Specification of DIO Driver", V2.5.0, R4.0 Rev3
**        http://autosar.org/download/R4.0/AUTOSAR_SWS_DIODriver.pdf
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
**  Include files
*/
   /* Project configuration */
   #include "..\..\..\project_cfg.h"

   /* Standard Type Definitions */
   #include "..\..\..\Types.h"

   /* Component Configuration */
   #include "dio_cfg.h"    /* Port Accessor Macro definitions */

   /* Target Specific Definitions */
   #include "..\KeySim_cfg.h"   /* access to KeySim simulated registers */


/*
** Function Prototypes
*/
extern void Dio_Init(void);

/*
** Macro Definitions
*/

/*
** AUTOSAR DIO Driver:
**   Re: "Specification of DIO Driver", V2.5.0, R4.0 Rev3
**        http://autosar.org/download/R4.0/AUTOSAR_SWS_DIODriver.pdf
*/

/*
** AUTOSAR Type Definitions
*/
#ifndef USE_SIMPLE_HAL	/* "Simple Hardware Abstraction Layer" - Deprecated to standard DIO functions in Dio.c. */

#if(0) /* typedef in dio_cfg.h */
/* [DIO182]
** Name: Dio_ChannelType
** Type: uint
** Range: This is implementation specific but not all values may be valid within the type.
**        Shall cover all available DIO channels.
**
** Description: Numeric ID of a DIO channel.
**
**  [DIO015] Parameters of type Dio_ChannelType contain the numeric ID of a DIO channel.
**  [DIO180] The mapping of the ID is implementation specific but not configurable.
**  [DIO017] For parameter values of type Dio_ChannelType, the Dio’s user shall use the
**            symbolic names provided by the configuration description.
*/
typedef uint8_t     Dio_ChannelType;
#endif

/*
** Name: Dio_ChannelStructType
** Type: Structure:
**  Element: 
**    bit:    Type: uint8        - This element shall be the Bit position in the Port counted from the LSB being Bit 0.
**    port:   Type: Dio_PortType - This shall be the Port in which the Bit is defined.
**
** Description: Type for the definition of a channel structure, which consists of a single bit within a port.
*/
typedef struct
{
    uint8_t      bit;      /* Bit position in the Port counted from the LSB being Bit 0. */
    Dio_PortType port;     /* The Port in which the Bit is defined.                      */
} Dio_ChannelStructType;


#if(0) /* typedef in dio_cfg.h */
/* [DIO183]
** Name: Dio_PortType
** Type: uint
** Range: 0..<number of ports>.
**        Shall cover all available DIO Ports.
**
** Description: Numeric ID of a DIO port.
**
**  [DIO018] Parameters of type Dio_PortType contain the numeric ID of a DIO port.
**  [DIO181] The mapping of ID is implementation specific but not configurable.
**  [DIO020] For parameter values of type Dio_PortType, the user shall use the 
**            symbolic names provided by the configuration description.
*/
typedef uint8_t     Dio_PortType;
#endif

/* [DIO184]
** Name: Dio_ChannelGroupType
** Type: Structure:
**  Element: 
**    mask:   Type: uint8/16/32  - This element mask which defines the positions of the channel group.
**    offset: Type: uint8        - This element shall be the position of the Channel Group on the port, counted from the LSB.
**    port:   Type: Dio_PortType - This shall be the port on which the Channel group is defined.
**
** Description: Type for the definition of a channel group, which consists of several adjoining channels within a port.
**
**  [DIO021] Dio_ChannelGroupType is the type for the definition of a channel group, 
**            which consists of several adjoining channels within a port.
**  [DIO022] For parameter values of type Dio_ChannelGroupType, the user shall use the
**            symbolic names provided by the configuration description.
*/
typedef struct
{
    uint8_t      mask;     /* Defines the positions of the channel group WITHOUT offset from the LSB. */
    uint8_t      offset;   /* Offset position of the Channel Group on the port, counted from the LSB. */
    Dio_PortType port;     /* The port on which the Channel group is defined.                         */
} Dio_ChannelGroupType;

/* [DIO185]
** Name: Dio_LevelType
** Type: uint8
** Range: STD_LOW:  0x00 - Physical state 0V
**        STD_HIGH: 0x01 - Physical state 5V or 3.3V
**
** Description: These are the possible levels a DIO channel can have (input or output.)
**
**  [DIO023] Dio_LevelType is the type for the possible levels that a DIO channel can have (input or output).
*/
typedef enum
{
  STD_LOW  = 0x00u,
  STD_HIGH = 0x01u
} Dio_LevelType;

/* [DIO186]
** Name: Dio_PortLevelType
** Type: uint8
** Range: 0...xxx  - If the µC owns ports of different port widths (e.g. 4, 8,16...Bit)
**                    Dio_PortLevelType inherits the size of the largest port
**
** Description: If the µC owns ports of different port widths (e.g. 4, 8,16...Bit)
**               Dio_PortLevelType inherits the size of the largest port.
**
**  [DIO024] Dio_PortLevelType is the type for the value of a DIO port.
*/
typedef uint8_t     Dio_PortLevelType;


/*
** AUTOSAR Function Prototypes:
*/

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
extern Dio_LevelType Dio_ReadChannel( Dio_ChannelType ChannelId );

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
extern void Dio_WriteChannel( Dio_ChannelType ChannelId, Dio_LevelType Level );

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
extern Dio_PortLevelType Dio_ReadPort( Dio_PortType PortId );

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
extern void Dio_WritePort( Dio_PortType PortId, Dio_PortLevelType Level );

/* [DIO137]
** Service Name: Dio_ReadChannelGroup
** Syntax: Dio_PortLevelType Dio_ReadChannelGroup( const Dio_ChannelGroupType* ChannelGroupIdPtr )
** Service ID[hex]: 0x04
** Parameters:    ChannelGroupIdPtr - Pointer to ChannelGroup
** Return Value:  Dio_PortLevelType - Level of a subset of the adjoining bits of a port
**
** Description: Reads a subset of the adjoining channels of a port.
**
**  [DIO037] The Dio_ReadChannelGroup function shall read a subset of the adjoining bits of a port (channel group).
**  [DIO092] The Dio_ReadChannelGroup function shall do the masking of the channel group.
**  [DIO093] The Dio_ReadChannelGroup function shall do the shifting so that the values read by the function are aligned to the LSB.
**  Furthermore, the requirements DIO005, DIO056, DIO083, DIO084, DIO118 and DIO026 are applicable to the Dio_ReadChannelGroup function.
*/
extern Dio_PortLevelType Dio_ReadChannelGroup( const Dio_ChannelGroupType* ChannelGroupIdPtr );

/* [DIO138]
** Service Name: Dio_WriteChannelGroup
** Syntax: void Dio_WriteChannelGroup( const Dio_ChannelGroupType* ChannelGroupIdPtr, Dio_PortLevelType Level )
** Service ID[hex]: 0x05
** Parameters:    ChannelGroupIdPtr - Pointer to ChannelGroup
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
extern void Dio_WriteChannelGroup( const Dio_ChannelGroupType* ChannelGroupIdPtr, Dio_PortLevelType Level );

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
extern Dio_LevelType Dio_FlipChannel( Dio_ChannelType ChannelId );

#endif /* ifndef USE_SIMPLE_HAL	/* "Simple Hardware Abstraction Layer" - Deprecated to standard DIO functions in Dio.c. */

#endif /* DIO_H */
