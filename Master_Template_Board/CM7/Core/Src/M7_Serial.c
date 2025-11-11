	/******************************************************************************
	* Project: Rocket Avionics System
	* File: M7_Serial.c
	* Author: Michael Caller
	* Created: November 2025
	*
	* Description:
	* This file contains custom code for the Rocket Avionics System. The code
	* implements various functions required for the avionics system used in
	* liquid propelled rocket. All rights reserved.
	*
	* Copyright (c) 2024 Michael Caller. All rights reserved.
	*
	* Redistribution and use in source and binary forms, with or without
	* modification, are permitted provided that the following conditions are met:
	*
	* 1. Redistributions of source code must retain the above copyright notice,
	*    this list of conditions, and the following disclaimer.
	*
	* 2. Redistributions in binary form must reproduce the above copyright notice,
	*    this list of conditions, and the following disclaimer in the documentation
	*    and/or other materials provided with the distribution.
	*
	* THIS SOFTWARE IS PROVIDED BY THE AUTHOR "AS IS" AND ANY EXPRESS OR IMPLIED
	* WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
	* MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO
	* EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
	* EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT
	* OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
	* INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
	* CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
	* IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY
	* OF SUCH DAMAGE.
	*****************************************************************************/

	#include "M7_Configuration.h"

	/* Use the RX ring owned by usbd_cdc_if.c */
//	extern uint8_t  CDC_RxBuffer[64];
//	extern volatile uint16_t CDC_RxHead;
//	extern volatile uint16_t CDC_RxTail;

	// ---------------------- USB CDC RX BUFFER ----------------------
	#define USB_RX_BUFFER_SIZE 256
	static uint8_t usb_rx_buffer[USB_RX_BUFFER_SIZE];
	static volatile uint16_t usb_rx_head = 0;
	static volatile uint16_t usb_rx_tail = 0;
	extern USBD_HandleTypeDef hUsbDeviceFS;

	// Called by CDC_Receive_FS() from usbd_cdc_if.c
	void USB_RxHandler(uint8_t* Buf, uint32_t Len) {
	for (uint32_t i = 0; i < Len; i++)
	{
	uint16_t next = (usb_rx_head + 1) % USB_RX_BUFFER_SIZE;
	if (next != usb_rx_tail)
	{
	usb_rx_buffer[usb_rx_head] = Buf[i];
	usb_rx_head = next;
	}
		}
			}

//	int SerialAvailable(void){
//	uint16_t head = CDC_RxHead;
//	uint16_t tail = CDC_RxTail;
//	if (head >= tail) return (int)(head - tail);
//	return (int)(sizeof(CDC_RxBuffer) - tail + head);
//	}
//
//	char SerialRead(void){
//	if (CDC_RxTail == CDC_RxHead) return 0;
//	char c = (char)CDC_RxBuffer[CDC_RxTail];
//	CDC_RxTail = (uint16_t)((CDC_RxTail + 1) % sizeof(CDC_RxBuffer));
//	return c;
//	}

	int SerialAvailable(void){
	    return CDC_Available();
	}

	char SerialRead(void){
	    int c = CDC_GetCharNonBlocking();
	    return (c < 0) ? 0 : (char)c;
	}

	void SerialPrint(const char *format, ...)	{
	static char buffer[128];
	va_list args;
	va_start(args, format);
	vsnprintf(buffer, sizeof(buffer)-1, format, args);
	buffer[sizeof(buffer)-1] = '\0';   // safety
	va_end(args);

	uint32_t start = HAL_GetTick();
	uint8_t result;
	do {
	result = CDC_Transmit_FS((uint8_t*)buffer, strlen(buffer));
	if ((HAL_GetTick() - start) > 20) break;  // I recommend 20ms, not 100ms
	} while (result == USBD_BUSY);
	}

	void SerialPrintln(const char *format, ...){
	SerialPrint(format);
	SerialPrint("\r\n");
	}

	void SerialPrintInt(int v){
	SerialPrint("%d", v);
	}

	void SerialPrintFloat(float v, int dp){
	if (dp < 0) dp = 0;
	if (dp > 6) dp = 6;
	SerialPrint("%.*f", dp, v);
	}

	bool SerialIsOnline(void){
	return (hUsbDeviceFS.dev_state == USBD_STATE_CONFIGURED);
	}

	void Data_Input(void){
	if (SerialAvailable() > 0)
	{
	char c = SerialRead();
	if (c == '\r' || c == '\n') return;

	switch (c)
	{
	case 'q': SystemState = 0; break;
	case 'w': SystemState = 1; break;
	case 'e': SystemState = 2; break;
	case 'r': SystemState = 3; break;
	case 't': SystemState = 4; break;
	case 'y': SystemState = 5; break;
	default:

	return;
	}
		}
			}

