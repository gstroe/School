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
**  Revision:    2.1
**  Date:        31-May-2012
**
***************************************************************************
**
** Revision History:
**
** Revision: 2.2   10-Sep-2015    Ben Sweet
** * Added "Simple Abstraction" macros for Ports 00, 01, 02 & 03.
** * Added macro WriteBitPortX to write an arbitrary Boolean value to a Bit in an Port.
**
** Revision: 2.1   31-May-2012    Ben Sweet
** * Configured for Drv_KeySim component.
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
** For KeySim DIO driver Data Direction:
** * Output is specified by: '0'
*/
#define DIO_DATA_DIRECTION_CHANNEL_OUTPUT   (0u)

/* 
** GPIO_Port_00
*/
#define     GPIO_Port_00_Data_CFG_INIT      ((uint8_t)0x00)        /* Initial Value of GPIO_Port_00 Data */
#define     GPIO_Port_00_Dir_CFG_INIT       ((uint8_t)0x00)        /* Set GPIO_Port_00 as Output         */

/* 
** GPIO_Port_01
*/
#define     GPIO_Port_01_Data_CFG_INIT      ((uint8_t)0x00)        /* Initial Value of GPIO_Port_01 Data */
#define     GPIO_Port_01_Dir_CFG_INIT       ((uint8_t)0x00)        /* Set GPIO_Port_01 as Output         */

/* 
** GPIO_Port_02
*/
#define     GPIO_Port_02_Data_CFG_INIT      ((uint8_t)0x00)        /* Initial Value of GPIO_Port_02 Data */
#define     GPIO_Port_02_Dir_CFG_INIT       ((uint8_t)0xFF)        /* Set GPIO_Port_02 as Input          */

/* 
** GPIO_Port_03
*/
#define     GPIO_Port_03_Data_CFG_INIT      ((uint8_t)0x00)        /* Initial Value of GPIO_Port_03 Data */

#if defined (DEBUG)
  #define     GPIO_Port_03_Dir_CFG_INIT       ((uint8_t)0x0F)        /* Set GPIO_Port_03: Bits 0-3 as Input ; Bits 4-7 as Output */
#else
  #define     GPIO_Port_03_Dir_CFG_INIT       ((uint8_t)0xFF)        /* Set GPIO_Port_03: Bits 0-7 as Input */
#endif


#ifdef USE_SIMPLE_HAL	/* "Simple Hardware Abstraction Layer" - Deprecated to standard DIO functions in Dio.c. */
/*
** Port 00 Accessors:
*/
#define GetPort00()             (GPIO_Port_00_Data)                    /* Usage: variable = GetPort00();   */
#define SetPort00(x)            (GPIO_Port_00_Data  =  (uint8_t)x)     /* Usage: SetPort00(value);         */
#define SetMaskPort00(x)        (GPIO_Port_00_Data |=  (uint8_t)x)     /* Usage: SetMaskPort00(mask);      */
#define ClearMaskPort00(x)      (GPIO_Port_00_Data &= ~(uint8_t)x)     /* Usage: ClearMaskPort00(mask);    */
#define SetBitPort00(bit)       (GPIO_Port_00_Data |=  (1<<((uint8_t)0x07 & bit))) /* Usage: SetBitPort00(BitNumber);   */
#define ClearBitPort00(bit)     (GPIO_Port_00_Data &= ~(1<<((uint8_t)0x07 & bit))) /* Usage: ClearBitPort00(BitNumber); */

/* Usage: logicalValue = TestBitPort00(BitNumber);
**    OR  if (TestBitPort00(BitNumber) == state)
*/
#define TestBitPort00(bit)       (((GPIO_Port_00_Data & (1<<((uint8_t)0x07 & bit))) != 0) ? (1u) : (0u) )

/* Usage: WriteBitPort00(BitNumber, boolValue);
*/
#define WriteBitPort00(bit, boolValue) {GPIO_Port_00_Data |=  ((1&boolValue)<<((uint8_t)0x07 & bit)); GPIO_Port_00_Data &=  ~((1&(!boolValue))<<((uint8_t)0x07 & bit));}


/*
** Port 01 Accessors:
*/
#define GetPort01()             (GPIO_Port_01_Data)                    /* Usage: variable = GetPort01();   */
#define SetPort01(x)            (GPIO_Port_01_Data  =  (uint8_t)x)     /* Usage: SetPort01(value);         */
#define SetMaskPort01(x)        (GPIO_Port_01_Data |=  (uint8_t)x)     /* Usage: SetMaskPort01(mask);      */
#define ClearMaskPort01(x)      (GPIO_Port_01_Data &= ~(uint8_t)x)     /* Usage: ClearMaskPort01(mask);    */
#define SetBitPort01(bit)       (GPIO_Port_01_Data |=  (1<<((uint8_t)0x07 & bit))) /* Usage: SetBitPort01(BitNumber);   */
#define ClearBitPort01(bit)     (GPIO_Port_01_Data &= ~(1<<((uint8_t)0x07 & bit))) /* Usage: ClearBitPort01(BitNumber); */

/* Usage: logicalValue = TestBitPort01(BitNumber);
**    OR  if (TestBitPort01(BitNumber) == state)
*/
#define TestBitPort01(bit)       (((GPIO_Port_01_Data & (1<<((uint8_t)0x07 & bit))) != 0) ? (1u) : (0u) )

/* Usage: WriteBitPort01(BitNumber, boolValue);
*/
#define WriteBitPort01(bit, boolValue) {GPIO_Port_01_Data |=  ((1&boolValue)<<((uint8_t)0x07 & bit)); GPIO_Port_01_Data &=  ~((1&(!boolValue))<<((uint8_t)0x07 & bit));}


/*
** Port 02 Accessors:
*/
#define GetPort02()             (GPIO_Port_02_Data)                    /* Usage: variable = GetPort02();   */
#define SetPort02(x)            (GPIO_Port_02_Data  =  (uint8_t)x)     /* Usage: SetPort02(value);         */
#define SetMaskPort02(x)        (GPIO_Port_02_Data |=  (uint8_t)x)     /* Usage: SetMaskPort02(mask);      */
#define ClearMaskPort02(x)      (GPIO_Port_02_Data &= ~(uint8_t)x)     /* Usage: ClearMaskPort02(mask);    */
#define SetBitPort02(bit)       (GPIO_Port_02_Data |=  (1<<((uint8_t)0x07 & bit))) /* Usage: SetBitPort02(BitNumber);   */
#define ClearBitPort02(bit)     (GPIO_Port_02_Data &= ~(1<<((uint8_t)0x07 & bit))) /* Usage: ClearBitPort02(BitNumber); */

/* Usage: logicalValue = TestBitPort02(BitNumber);
**    OR  if (TestBitPort02(BitNumber) == state)
*/
#define TestBitPort02(bit)       (((GPIO_Port_02_Data & (1<<((uint8_t)0x07 & bit))) != 0) ? (1u) : (0u) )

/* Usage: WriteBitPort02(BitNumber, boolValue);
*/
#define WriteBitPort02(bit, boolValue) {GPIO_Port_02_Data |=  ((1&boolValue)<<((uint8_t)0x07 & bit)); GPIO_Port_02_Data &=  ~((1&(!boolValue))<<((uint8_t)0x07 & bit));}


/*
** Port 03 Accessors:
*/
#define GetPort03()             (GPIO_Port_03_Data)                    /* Usage: variable = GetPort03();   */
#define SetPort03(x)            (GPIO_Port_03_Data  =  (uint8_t)x)     /* Usage: SetPort03(value);         */
#define SetMaskPort03(x)        (GPIO_Port_03_Data |=  (uint8_t)x)     /* Usage: SetMaskPort03(mask);      */
#define ClearMaskPort03(x)      (GPIO_Port_03_Data &= ~(uint8_t)x)     /* Usage: ClearMaskPort03(mask);    */
#define SetBitPort03(bit)       (GPIO_Port_03_Data |=  (1<<((uint8_t)0x07 & bit))) /* Usage: SetBitPort03(BitNumber);   */
#define ClearBitPort03(bit)     (GPIO_Port_03_Data &= ~(1<<((uint8_t)0x07 & bit))) /* Usage: ClearBitPort03(BitNumber); */

/* Usage: logicalValue = TestBitPort03(BitNumber);
**    OR  if (TestBitPort03(BitNumber) == state)
*/
#define TestBitPort03(bit)       (((GPIO_Port_03_Data & (1<<((uint8_t)0x07 & bit))) != 0) ? (1u) : (0u) )

/* Usage: WriteBitPort03(BitNumber, boolValue);
*/
#define WriteBitPort03(bit, boolValue) {GPIO_Port_03_Data |=  ((1&boolValue)<<((uint8_t)0x07 & bit)); GPIO_Port_03_Data &=  ~((1&(!boolValue))<<((uint8_t)0x07 & bit));}


#else /*  #ifndef USE_SIMPLE_HAL -  "Simple Hardware Abstraction Layer" - Deprecated to standard DIO functions in Dio.c. */

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
    DIO_IN_CHANNEL_UserImput = 0u,

#if(0)  // Examples...
    DIO_IN_CHANNEL_AnotherInput         ,
    DIO_IN_CHANNEL_YetAnotherIn         ,
#endif

    /* Output Channels: */
    DIO_OUT_CHANNEL_Debug_Toggle_Bit_Task_01MS ,
    DIO_OUT_CHANNEL_Debug_Toggle_Bit_Task_05MS ,
    DIO_OUT_CHANNEL_Debug_Toggle_Bit_Task_10MS ,

    DIO_OUT_CHANNEL_ApplicationOutput ,

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
    DIO_Port_00 = 0u,  /* Port 00 Data           */
    DIO_Port_01 ,      /* Port 01 Data           */
    DIO_Port_02 ,      /* Port 02 Data           */
    DIO_Port_03 ,      /* Port 03 Data           */
    
    /* THIS MUST ALWAYS BE THE LAST ENTRY IN THE ENUMERATION: */
    DIO_MAX_PORTS
} Dio_PortType;

#define DIO_OUT_PORT_MotorControl   (DIO_Port_00_Data)


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

#endif /* ifdef USE_SIMPLE_HAL	- "Simple Hardware Abstraction Layer" - Deprecated to standard DIO functions in Dio.c. */


#endif /* DIO_CFG_H */
