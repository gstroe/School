#ifndef DIO_CFG_H
#define DIO_CFG_H
/**************************************************************************
**
** Module Name:   Dio_cfg.h
**
** Module Description:  Digital Input/Output Port configuration file.
**  Define constants and macros for Digital I/O Port configuration and Access.
**
***************************************************************************
**
**  Author:      Ben Sweet
**  Revision:    2.2
**  Date:        16-Oct-2012
**
***************************************************************************
**
** Revision History:
**
** Revision: 2.2   16-Oct-2012    Ben Sweet
** * Added "Simple Abstraction" macros for Port K and Port T.
** * Added macro WriteBitPortX to write an arbitrary Boolean value to a Bit in an Port.
**
** Revision: 2.1   26-May-2012    Ben Sweet
** * Added Channel definitions for Debug Toggle pins.
**
** Revision: 2.0   05-May-2012    Ben Sweet
** * Extracted from Port component.
** * Deprecated Get/Set Port/Mask accessors:
**   GetPortX, SetPortX, SetMaskPortX, ClearMaskPortX, SetBitPortX, ClearBitPortX, TestBitPortX.
** * Added conditional configuration value for MICROCONTROLLER_SIM.
**
** Revision: 1.1   06-Jun-2008    Ben Sweet
** * Added Port Accessor macros (defined in Port_cfg.h):
**   GetPortX, SetPortX, SetMaskPortX, ClearMaskPortX, SetBitPortX, ClearBitPortX, TestBitPortX.
**
**   Re: "An architecture for designing reusable embedded systems software, Part 2", Dinu Madau
**        http://embedded.com/design/opensource/207403738?pgno=2
**
** Revision: 1.0   03-Jun-2008    Ben Sweet
** * Original version based on existing methods in general use.
**
**************************************************************************/

/*
** Values for port register configuration:
*/

/*
** For MC9S12DG128 DIO driver Data Direction:
** * Output is specified by: '1'
*/
#define DIO_DATA_DIRECTION_CHANNEL_OUTPUT   (1u)

/* 
** Port A
*/
#define     PORTA_CFG_INIT      ((uint8_t)0x00)        /* Initial Value of Port A */
#define     DDRA_CFG_INIT       ((uint8_t)0xFF)        /* Set Port A as Output    */

/*
** Port B 
*/
#define     PORTB_CFG_INIT      ((uint8_t)0x00)        /* Initial Value of Port B */

#ifndef MICROCONTROLLER_SIM  /* Normal operation */
 #define     DDRB_CFG_INIT       ((uint8_t)0x00)       /* Normal operation: Set port B as Input */
#else /* Simulated Microcontroller */
 #define     DDRB_CFG_INIT       ((uint8_t)0xFF)       /* To allow simulation of hardware inputs, Set port B direction as Output */
#endif /* MICROCONTROLLER_SIM */

/* 
** Port K
*/
#define     PORTK_CFG_INIT      ((uint8_t)0x00)        /* Initial Value of Port K */

#if defined (DEBUG)
  #define     DDRK_CFG_INIT       ((uint8_t)0x0F)        /* Set Port K: PK0-PK3 as Output ; PK4-PK7 as Input */
#else
  #define     DDRK_CFG_INIT       ((uint8_t)0x00)        /* Set Port K: PK0-PK7 as Input */
#endif

/*
** Port T 
*/
#define     PORTT_CFG_INIT      ((uint8_t)0x00)        /* Initial Value of Port T */

#ifndef MICROCONTROLLER_SIM  /* Normal operation */
 #define     DDRT_CFG_INIT       ((uint8_t)0x00)       /* Normal operation: Set port T as Input */
#else /* Simulated Microcontroller */
 #define     DDRT_CFG_INIT       ((uint8_t)0xFF)       /* To allow simulation of hardware inputs, Set port T direction as Output */
#endif /* MICROCONTROLLER_SIM */


#if(1) /* "Simple Abstraction" - Deprecated to standard DIO functions in Dio.c. */
/*
** Port A Accessors:
*/
#define GetPortA()              (PORTA)                       /* Usage: variable = GetPortA();    */
#define SetPortA(x)             (PORTA  =  (uint8_t)x)        /* Usage: SetPortA(value);          */
#define SetMaskPortA(x)         (PORTA |=  (uint8_t)x)        /* Usage: SetMaskPortA(mask);       */
#define ClearMaskPortA(x)       (PORTA &= ~(uint8_t)x)        /* Usage: ClearMaskPortA(mask);     */
#define SetBitPortA(bit)        (PORTA |=  (1<<((uint8_t)0x07 & bit))) /* Usage: SetBitPortA(BitNumber);   */
#define ClearBitPortA(bit)      (PORTA &= ~(1<<((uint8_t)0x07 & bit))) /* Usage: ClearBitPortA(BitNumber); */

/* Usage: logicalValue = TestBitPortA(BitNumber);
**    OR  if (TestBitPortA(BitNumber) == state)
*/
#define TestBitPortA(bit)       (((PORTA & (1<<((uint8_t)0x07 & bit))) != 0) ? (1u) : (0u) )

/* Usage: WriteBitPortA(BitNumber, boolValue);
*/
#define WriteBitPortA(bit, boolValue) {PORTA |=  ((1&boolValue)<<((uint8_t)0x07 & bit)); PORTA &=  ~((1&(!boolValue))<<((uint8_t)0x07 & bit));}


/*
** Port B Accessors:
*/
#define GetPortB()              (PORTB)                       /* Usage: variable = GetPortB();    */
#define SetPortB(x)             (PORTB  =  (uint8_t)x)        /* Usage: SetPortB(value);          */
#define SetMaskPortB(x)         (PORTB |=  (uint8_t)x)        /* Usage: SetMaskPortB(mask);       */
#define ClearMaskPortB(x)       (PORTB &= ~(uint8_t)x)        /* Usage: ClearMaskPortB(mask);     */
#define SetBitPortB(bit)        (PORTB |=  (1<<((uint8_t)0x07 & bit))) /* Usage: SetBitPortB(BitNumber);   */
#define ClearBitPortB(bit)      (PORTB &= ~(1<<((uint8_t)0x07 & bit))) /* Usage: ClearBitPortB(BitNumber); */

/* Usage: logicalValue = TestBitPortB(BitNumber);
**    OR  if (TestBitPortB(BitNumber) == state)
*/
#define TestBitPortB(bit)       (((PORTB & (1<<((uint8_t)0x07 & bit))) != 0) ? (1u) : (0u) )

/* Usage: WriteBitPortB(BitNumber, boolValue);
*/
#define WriteBitPortB(bit, boolValue) {PORTB |=  ((1&boolValue)<<((uint8_t)0x07 & bit)); PORTB &=  ~((1&(!boolValue))<<((uint8_t)0x07 & bit));}


/*
** Port K Accessors:
*/
#define GetPortK()              (PORTK)                       /* Usage: variable = GetPortK();    */
#define SetPortK(x)             (PORTK  =  (uint8_t)x)        /* Usage: SetPortK(value);          */
#define SetMaskPortK(x)         (PORTK |=  (uint8_t)x)        /* Usage: SetMaskPortK(mask);       */
#define ClearMaskPortK(x)       (PORTK &= ~(uint8_t)x)        /* Usage: ClearMaskPortK(mask);     */
#define SetBitPortK(bit)        (PORTK |=  (1<<((uint8_t)0x07 & bit))) /* Usage: SetBitPortK(BitNumber);   */
#define ClearBitPortK(bit)      (PORTK &= ~(1<<((uint8_t)0x07 & bit))) /* Usage: ClearBitPortK(BitNumber); */

/* Usage: logicalValue = TestBitPortK(BitNumber);
**    OR  if (TestBitPortK(BitNumber) == state)
*/
#define TestBitPortK(bit)       (((PORTK & (1<<((uint8_t)0x07 & bit))) != 0) ? (1u) : (0u) )

/* Usage: WriteBitPortK(BitNumber, boolValue);
*/
#define WriteBitPortK(bit, boolValue) {PORTK |=  ((1&boolValue)<<((uint8_t)0x07 & bit)); PORTK &=  ~((1&(!boolValue))<<((uint8_t)0x07 & bit));}


/*
** Port T Accessors:
*/
#define GetPortT()              (PTT)                         /* Usage: variable = GetPortT();    */
#define SetPortT(x)             (PTT  =  (uint8_t)x)          /* Usage: SetPortT(value);          */
#define SetMaskPortT(x)         (PTT |=  (uint8_t)x)          /* Usage: SetMaskPortT(mask);       */
#define ClearMaskPortT(x)       (PTT &= ~(uint8_t)x)          /* Usage: ClearMaskPortT(mask);     */
#define SetBitPortT(bit)        (PTT |=  (1<<((uint8_t)0x07 & bit))) /* Usage: SetBitPortT(BitNumber);   */
#define ClearBitPortT(bit)      (PTT &= ~(1<<((uint8_t)0x07 & bit))) /* Usage: ClearBitPortT(BitNumber); */

/* Usage: logicalValue = TestBitPortT(BitNumber);
**    OR  if (TestBitPortT(BitNumber) == state)
*/
#define TestBitPortT(bit)       (((PTT & (1<<((uint8_t)0x07 & bit))) != 0) ? (1u) : (0u) )

/* Usage: WriteBitPortT(BitNumber, boolValue);
*/
#define WriteBitPortT(bit, boolValue) {PTT |=  ((1&boolValue)<<((uint8_t)0x07 & bit)); PTT &=  ~((1&(!boolValue))<<((uint8_t)0x07 & bit));}


#endif /* "Simple Abstraction" - Deprecated to standard DIO functions in Dio.c. */


/*
** AUTOSAR DIO Driver:
**   Re: "Specification of DIO Driver", V2.5.0, R4.0 Rev3
**        http://autosar.org/download/R4.0/AUTOSAR_SWS_DIODriver.pdf
*/

/*
**  [DIO065] The Dio module shall detect the following errors and exceptions depending on its build version (development/production mode):
*/
#define DIO_E_PARAM_INVALID_CHANNEL_ID (0x0Au)  /* [DIO175] Invalid channel name requested, Relevance: Development */
#define DIO_E_PARAM_INVALID_PORT_ID    (0x14u)  /* [DIO177] Invalid port name requested   , Relevance: Development */
#define DIO_E_PARAM_INVALID_GROUP      (0x1Fu)  /* [DIO178] Invalid ChannelGroup passed   , Relevance: Development */

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
typedef enum
{
    /*
    ** These values _MUST_ match the associated array indices in DIO_Channel[] table - dio_cfg.c
    */

    /* Input Channels: */
    DIO_IN_CHANNEL_EmergencyStopCommand = 0u,
    DIO_IN_CHANNEL_StopCommand          ,
    DIO_IN_CHANNEL_StartCommand         ,

    /* Output Channels: */
    DIO_OUT_CHANNEL_Debug_Toggle_Bit_Task_01MS ,
    DIO_OUT_CHANNEL_Debug_Toggle_Bit_Task_05MS ,
    DIO_OUT_CHANNEL_Debug_Toggle_Bit_Task_10MS ,

    /* THIS MUST ALWAYS BE THE LAST ENTRY IN THE ENUMERATION: */
    DIO_MAX_CHANNELS
} Dio_ChannelType;

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
**
** Note:
**  In order to implement [DIO028], [DIO029], [DIO079] to only write channels that are
**  configured as Outputs, the Data registers in the table _MUST_ be immediately followed
**  by their Data Direction registers.  The implementation assumes the table to be arranged
**  in this way.
*/
typedef enum
{
    /*
    ** The order of these values _MUST_ match the associated array indices for the associated
    ** Data Registers in DIO_DataPortPtrTable[] table - dio_cfg.c
    **
    ** The associated Data Direction registers are defined in DIO_DdrPortPtrTable[] (dio_cfg.c)
    ** and _MUST_ be arranged in the same order as the Data registers. 
    */
    DIO_PortA = 0u,  /* Port A Data           */
    DIO_PortB ,      /* Port B Data           */
    DIO_PortK ,      /* Port K Data           */
    DIO_PortT ,      /* Port T Data           */
    
    /* THIS MUST ALWAYS BE THE LAST ENTRY IN THE ENUMERATION: */
    DIO_MAX_PORTS
} Dio_PortType;

#define DIO_OUT_PORT_MotorControl   (DIO_PortA)


/* Re: [DIO184]
** Name: Dio_ChannelGroups
**
**  [DIO022] For parameter values of type Dio_ChannelGroupType, the user shall use the
**            symbolic names provided by the configuration description.
*/
typedef enum
{
    /*
    ** These values _MUST_ match the associated array indices in DIO_ChannelGroup[] table - dio_cfg.c
    */
    DIO_GroupDemo1 = 0u,
    DIO_GroupDemo2 ,

    /* THIS MUST ALWAYS BE THE LAST ENTRY IN THE ENUMERATION: */
    DIO_MAX_GROUPS
} Dio_ChannelGroups;


#endif /* DIO_CFG_H */
