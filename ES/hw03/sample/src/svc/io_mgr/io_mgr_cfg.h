#ifndef IO_MGR_CFG_H
#define IO_MGR_CFG_H
/**************************************************************************
**
** Module Name:   io_mgr_cfg.h
**
** Module Description:  General I/O Manager configuration file.
**  Define constants and macros for General Input/Output configuration and Access.
**
***************************************************************************
**
**  Author:      Ben Sweet
**  Revision:    3.0
**  Date:        16-Oct-2012
**
***************************************************************************
**
** Revision History:
**
** Revision: 3.0   16-Oct-2012    Ben Sweet
** * Define initial value for UserInput signal.
** * Define Channel (Bit) numbers for UserInput Boolean signal on Port B and
**   ApplicationOutput Boolean signal on Port A.
**
** Revision: 2.2   26-May-2012    Ben Sweet
** * Move Input & Output "Bit" definitions moved to "Channels" in DIO dio_cfg.h.
**
** Revision: 2.1   23-Apr-2012    Ben Sweet
** * Added utilities for Debug output toggle bits.
**
** Revision: 2.0   16-Sep-2010    Ben Sweet
** * Customized for Main Machine Controller (MMC) application.
**
** Revision: 1.0    7-Jun-2008    Ben Sweet
** * Original version based on existing methods in general use.
**
**************************************************************************/

/*
** Initialization values for defined signals:
*/
#define UserInput_INIT      (0u)

/*
** Channel (Bit) numbers for defined Boolean signals:
*/
#define DIO_IN_CHANNEL_UserInput1            (0u)   /* Port B, Bit 0 */
#define DIO_IN_CHANNEL_UserInput2            (1u)   /* Port B, Bit 1 */

#define DIO_OUT_CHANNEL_ApplicationOutput1   (0u)   /* Port A, Bit 0 */
#define DIO_OUT_CHANNEL_ApplicationOutput2   (1u)   /* Port A, Bit 1 */


#endif  /* IO_MGR_CFG_H */
