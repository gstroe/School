/**************************************************************************
**
** Module Name:  Dio_cfg.c.
**
** Module Description:  Configuration for Digital Input/Output Driver.
**
***************************************************************************
**
**  Author:      Benjamin Sweet
**  Revision:    1.4
**  Date:        08-Nov-2012
**
***************************************************************************
**
** Revision History:
**
** Revision: 1.4    08-Nov-2012  Ben Sweet, Gabriel Moreno, Leonardo Bueno
** * Split DIO_PortPtrTable[] into two tables:
**   + DIO_DataPortPtrTable[] for Data port registers
**   + DIO_DdrPortPtrTable[]  for Data Direction registers
** * Rename DIO_ChannelGroup[] to DIO_ChannelGroupTable[].
**
** Revision: 1.3   12-Jun-2012    Ben Sweet
** * Minor corrections to various comment blocks after code review.
**
** Revision: 1.2    31-May-2012  B. Sweet
** * Configured for Drv_KeySim component.
** * Added Channel definitions for Debug Toggle pins.
**
** Revision: 1.1    26-May-2012  B. Sweet
** * Added DIO_Channel[].
** * Moved Digital Input & Output channel definitions from IO_Mgr component.
**
** Revision: 1.0    06-May-2012  B. Sweet
** * Original implementation.
**   Re: "Specification of DIO Driver", V2.5.0, R4.0 Rev3
**        http://autosar.org/download/R4.0/AUTOSAR_SWS_DIODriver.pdf

**************************************************************************/

/*
**  Include files
*/

   /* Component Configuration and Typedefs: */
   #include "dio.h"

/*
** Global Variables:
*/
   #include "..\KeySim_cfg.h"   /* access to KeySim simulated registers */

/*
** Local variable declarations
*/

/*
** DIO Channels:
**
** The order of these Channels _MUST_ match the associated values in Dio_ChannelType enumeration - dio_cfg.h
*/
Dio_ChannelStructType DIO_Channel[DIO_MAX_CHANNELS] =
{
  /* Input Channels: */

    /* Table Index: 0
    **  Channel: DIO_IN_CHANNEL_EmergencyStopCommand
    **   Bit 7 on GPIO_Port_02
    */
    {
        0x07u,                  /* Bit   */
        DIO_Port_02_Data,       /* Port  */
    },
    /* Table Index: 1
    **  Channel: DIO_IN_CHANNEL_StopCommand
    **   Bit 6 on GPIO_Port_02
    */
    {
        0x06u,       	        /* Bit   */
        DIO_Port_02_Data,       /* Port  */
    },
    /* Table Index: 2
    **  Channel: DIO_IN_CHANNEL_StartCommand
    **   Bit 0 on GPIO_Port_03
    */
    {
        0x00u,                  /* Bit   */
        DIO_Port_03_Data,       /* Port  */
    },

  /* Output Channels: */

    /* Table Index: 3
    **  Channel: DIO_OUT_CHANNEL_Debug_Toggle_Bit_Task_01MS
    **   Bit 7 on GPIO_Port_03
    */
    {
        0x07u,                  /* Bit   */
        DIO_Port_03_Data,       /* Port  */
    },

    /* Table Index: 4
    **  Channel: DIO_OUT_CHANNEL_Debug_Toggle_Bit_Task_05MS
    **   Bit 6 on GPIO_Port_03
    */
    {
        0x06u,                  /* Bit   */
        DIO_Port_03_Data,       /* Port  */
    },

    /* Table Index: 5
    **  Channel: DIO_OUT_CHANNEL_Debug_Toggle_Bit_Task_10MS
    **   Bit 5 on GPIO_Port_03
    */
    {
        0x05u,                  /* Bit   */
        DIO_Port_03_Data,       /* Port  */
    },

};

/*
** DIO Port Pointers:
**  Port names and addresses are defined in <mc9s12dg128.h>
**
** The order of these Ports _MUST_ match the associated values in Dio_PortType enumeration - dio_cfg.h
**
** Note:
**  In order to implement [DIO028], [DIO029], [DIO079] to only write channels that are
**  configured as Outputs, the Data registers in the table _MUST_ be immediately followed
**  by their Data Direction registers.  The implementation assumes the table to be arranged
**  in this way.
*/
volatile uint8_t * DIO_DataPortPtrTable[DIO_MAX_PORTS] =
{
    &GPIO_Port_00_Data,      /* General Purpose Input/Output Port: 0x00 - Data Register              */
    &GPIO_Port_01_Data,      /* General Purpose Input/Output Port: 0x01 - Data Register              */
    &GPIO_Port_02_Data,      /* General Purpose Input/Output Port: 0x02 - Data Register              */
    &GPIO_Port_03_Data,      /* General Purpose Input/Output Port: 0x03 - Data Register              */
};

volatile uint8_t * DIO_DdrPortPtrTable[DIO_MAX_PORTS] =
{
    &GPIO_Port_00_Dir,       /* General Purpose Input/Output Port: 0x00 - Data Direction Register    */
    &GPIO_Port_01_Dir,       /* General Purpose Input/Output Port: 0x01 - Data Direction Register    */
    &GPIO_Port_02_Dir,       /* General Purpose Input/Output Port: 0x02 - Data Direction Register    */
    &GPIO_Port_03_Dir,       /* General Purpose Input/Output Port: 0x03 - Data Direction Register    */
};


/*
** DIO Channel Groups:
**
** The order of these Groups _MUST_ match the associated values in Dio_ChannelGroups enumeration - dio_cfg.h
*/
Dio_ChannelGroupType DIO_ChannelGroupTable[DIO_MAX_GROUPS] =
{
    /* Channel Group: DIO_GroupDemo1 - 0b0000 1100 on GPIO_Port_00 */
    {
        0x03u,  /* Mask   */
        2u,     /* Offset */
        DIO_Port_00_Data,
    },
    /* Channel Group: DIO_GroupDemo2 - 0b0111 0000 on GPIO_Port_02 */
    {
        0x07u,  /* Mask   */
        4u,     /* Offset */
        DIO_Port_02_Data,
    },
};
