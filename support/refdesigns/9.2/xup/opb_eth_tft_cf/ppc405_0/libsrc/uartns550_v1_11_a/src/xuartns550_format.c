/* $Id: xuartns550_format.c,v 1.1 2007/04/04 18:35:36 wre Exp $ */
/*****************************************************************************
*
*       XILINX IS PROVIDING THIS DESIGN, CODE, OR INFORMATION "AS IS"
*       AS A COURTESY TO YOU, SOLELY FOR USE IN DEVELOPING PROGRAMS AND
*       SOLUTIONS FOR XILINX DEVICES.  BY PROVIDING THIS DESIGN, CODE,
*       OR INFORMATION AS ONE POSSIBLE IMPLEMENTATION OF THIS FEATURE,
*       APPLICATION OR STANDARD, XILINX IS MAKING NO REPRESENTATION
*       THAT THIS IMPLEMENTATION IS FREE FROM ANY CLAIMS OF INFRINGEMENT,
*       AND YOU ARE RESPONSIBLE FOR OBTAINING ANY RIGHTS YOU MAY REQUIRE
*       FOR YOUR IMPLEMENTATION.  XILINX EXPRESSLY DISCLAIMS ANY
*       WARRANTY WHATSOEVER WITH RESPECT TO THE ADEQUACY OF THE
*       IMPLEMENTATION, INCLUDING BUT NOT LIMITED TO ANY WARRANTIES OR
*	   REPRESENTATIONS THAT THIS IMPLEMENTATION IS FREE FROM CLAIMS OF
*       INFRINGEMENT, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
*       FOR A PARTICULAR PURPOSE.
*
*       (c) Copyright 2002-2007 Xilinx Inc.
*       All rights reserved.
*
*****************************************************************************/
/****************************************************************************/
/**
*
* @file xuartns550_format.c
*
* This file contains the data format functions for the 16450/16550 UART driver.
* The data format functions allow the baud rate, number of data bits, number
* of stop bits and parity to be set and retrieved.
*
* <pre>
* MODIFICATION HISTORY:
*
* Ver   Who  Date     Changes
* ----- ---- -------- -----------------------------------------------
* 1.00b jhl  03/11/02 Repartitioned driver for smaller files.
* 1.00b rmm  05/15/03 Fixed diab compiler warnings.
* 1.11a sv   03/20/07 Updated to use the new coding guidelines.
* </pre>
*
*****************************************************************************/

/***************************** Include Files ********************************/

#include "xstatus.h"
#include "xuartns550.h"
#include "xuartns550_i.h"
#include "xio.h"

/************************** Constant Definitions ****************************/


/**************************** Type Definitions ******************************/


/***************** Macros (Inline Functions) Definitions ********************/


/************************** Variable Definitions ****************************/


/************************** Function Prototypes *****************************/


/****************************************************************************/
/**
*
* Sets the data format for the specified UART. The data format includes the
* baud rate, number of data bits, number of stop bits, and parity. It is the
* caller's responsibility to ensure that the UART is not sending or receiving
* data when this function is called.
*
* @param	InstancePtr is a pointer to the XUartNs550 instance .
* @param	FormatPtr is a pointer to a format structure containing the data
*		format to be set.
*
* @return
*
*		- XST_SUCCESS if the data format was successfully set.
*		- XST_UART_BAUD_ERROR indicates the baud rate could not be set
*		because of the amount of error with the baud rate and the input
*		clock frequency.
*		- XST_INVALID_PARAM if one of the parameters was not valid.
*
* @note
*
* The data types in the format type, data bits and parity, are 32 bit fields
* to prevent a compiler warning that is a bug with the GNU PowerPC compiler.
* The asserts in this function will cause a warning if these fields are
* bytes.
* <br><br>
* The baud rates tested include: 1200, 2400, 4800, 9600, 19200, 38400, 57600
* and 115200.
*
*****************************************************************************/
int XUartNs550_SetDataFormat(XUartNs550 *InstancePtr,
					XUartNs550Format *FormatPtr)
{
	int Status;
	u8 LcrRegister;

	XASSERT_NONVOID(InstancePtr != NULL);
	XASSERT_NONVOID(FormatPtr != NULL);

	/*
	 * Verify the inputs specified are valid and return an error if any
	 * are not, without setting the data format
	 */
	if ((FormatPtr->DataBits > XUN_FORMAT_8_BITS)	||
		(FormatPtr->Parity > XUN_FORMAT_EVEN_PARITY) ||
		((FormatPtr->StopBits != XUN_FORMAT_2_STOP_BIT) &&
		(FormatPtr->StopBits != XUN_FORMAT_1_STOP_BIT))) {
		return XST_INVALID_PARAM;
	}

	/*
	 * Try to set the baud rate and if it's not successful then don't
	 * continue altering the data format, this is done first to avoid the
	 * format from being altered when an error occurs
	 */
	Status = XUartNs550_SetBaudRate(InstancePtr, FormatPtr->BaudRate);
	if (Status != XST_SUCCESS) {
		return Status;
	}

	/*
	 * Read the line control register which contains the parity, length and
	 * stop bits so they can be updated without affecting any other bits
	 */
	LcrRegister = XIo_In8(InstancePtr->BaseAddress + XUN_LCR_OFFSET);

	/*
	 * Set the length of data (8,7,6,5) by first clearing out the bits
	 * that control it in the register, then set the length in the register
	 */
	LcrRegister &= ~XUN_LCR_LENGTH_MASK;
	LcrRegister |= FormatPtr->DataBits;

	/*
	 * Set the number of stop bits in the line control register, if the
	 * number of stop bits is not 2, then it must be one which is the bit
	 * in the register cleared
	 */
	if (FormatPtr->StopBits == XUN_FORMAT_2_STOP_BIT) {
		LcrRegister |= XUN_LCR_2_STOP_BITS;
	} else {
		LcrRegister &= ~XUN_LCR_2_STOP_BITS;
	}

	/*
	 * Set the parity by first clearing out the bits that control it in the
	 * register, then set the bits in the register, the default is no parity
	 * after clearing the register bits
	 */
	LcrRegister &= ~XUN_LCR_PARITY_MASK;
	if (FormatPtr->Parity != XUN_FORMAT_NO_PARITY) {
		/* Some form of parity is specified, set the bit indicating that
		 * parity is enabled, then setup even or odd, the default is odd
		 * after clearing the register bits
		 */
		LcrRegister |= XUN_LCR_ENABLE_PARITY;
		if (FormatPtr->Parity == XUN_FORMAT_EVEN_PARITY) {
			LcrRegister |= XUN_LCR_EVEN_PARITY;
		}
	}

	/*
	 * Write the line control register out to save the new data format
	 * that has been created
	 */
	XIo_Out8(InstancePtr->BaseAddress + XUN_LCR_OFFSET, LcrRegister);

	return XST_SUCCESS;
}
/****************************************************************************/
/**
*
* Gets the data format for the specified UART. The data format includes the
* baud rate, number of data bits, number of stop bits, and parity.
*
* @param	InstancePtr is a pointer to the XUartNs550 instance .
* @param	FormatPtr is a pointer to a format structure that will contain
*		the data format after this call completes.
*
* @return	None.
*
* @note		None.
*
* @internal
*
* This function gets the state of the hardware rather than returning a state
* that has been stored to ensure that the hardware is correct.
*
*****************************************************************************/
void XUartNs550_GetDataFormat(XUartNs550 *InstancePtr,
				XUartNs550Format *FormatPtr)
{
	u8 LcrRegister;

	XASSERT_VOID(InstancePtr != NULL);
	XASSERT_VOID(FormatPtr != NULL);

	/*
	 * Assert validates the input arguments
	 */
	XASSERT_VOID(InstancePtr != NULL);
	XASSERT_VOID(InstancePtr->IsReady == XCOMPONENT_IS_READY);

	/*
	 * Get the baud rate from the instance, this is not retrieved from the
	 * hardware because it is only kept as a divisor such that it is more
	 * difficult to get back to the divisor
	 */
	FormatPtr->BaudRate = InstancePtr->BaudRate;

	/*
	 * Read the line control register which contains the parity, length and
	 * stop bits so they can be updated without affecting any other bits
	 */
	LcrRegister = XIo_In8(InstancePtr->BaseAddress + XUN_LCR_OFFSET);

	/*
	 * Set the length of data (8,7,6,5) by first clearing out the bits
	 * that control it in the register, then set the length in the register
	 */
	FormatPtr->DataBits = LcrRegister & XUN_LCR_LENGTH_MASK;

	/*
	 * Set the number of stop bits by first clearing out the bits in that
	 * control it in the register, then set the bits in the register, the
	 * default is one stop bit after clearing the register bits
	 */
	if (LcrRegister & XUN_LCR_2_STOP_BITS) {
		FormatPtr->StopBits = XUN_FORMAT_2_STOP_BIT;
	} else {
		FormatPtr->StopBits = XUN_FORMAT_1_STOP_BIT;
	}

	/*
	 * Determine what parity is set from the register and setup the format
	 * to correspond
	 */
	if ((LcrRegister & XUN_LCR_ENABLE_PARITY) == 0) {
		FormatPtr->Parity = XUN_FORMAT_NO_PARITY;
	} else {

		/*
		 * Parity is enables, so determine if it's even or odd and set the
		 * format to correspond
		 */
		if (LcrRegister & XUN_LCR_EVEN_PARITY) {
			FormatPtr->Parity = XUN_FORMAT_EVEN_PARITY;
		} else {
			FormatPtr->Parity = XUN_FORMAT_ODD_PARITY;
		}
	}
}

