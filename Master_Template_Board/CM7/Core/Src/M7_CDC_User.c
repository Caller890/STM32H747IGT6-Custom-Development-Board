	/******************************************************************************
	* Project: Rocket Avionics System
	* File: M7_CDC_User.c
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

	extern USBD_HandleTypeDef hUsbDeviceFS;

	/* Our own IO buffers (avoid depending on Cube's file) */
	static uint8_t  cdcRxScratch[APP_RX_DATA_SIZE];
	static uint8_t  cdcTxScratch[APP_TX_DATA_SIZE];

	/* RX ring buffer for app consumption */
	static uint8_t  CDC_RxBuffer[64];
	static volatile uint16_t CDC_RxHead = 0;
	static volatile uint16_t CDC_RxTail = 0;

	/* ---- Forward declarations (MUST be before the table) ---- */
	static int8_t CDC_Init_User(void);
	static int8_t CDC_DeInit_User(void);
	static int8_t CDC_Control_User(uint8_t cmd, uint8_t *pbuf, uint16_t length);
	static int8_t CDC_Receive_User(uint8_t *Buf, uint32_t *Len);
	static int8_t CDC_TxCplt_User(uint8_t *pbuf, uint32_t *Len, uint8_t epnum);

	/* ---- Interface table (now sees the symbols above) ---- */
	USBD_CDC_ItfTypeDef USBD_Interface_fops_User = {
	  CDC_Init_User,
	  CDC_DeInit_User,
	  CDC_Control_User,
	  CDC_Receive_User,
	  CDC_TxCplt_User
	};

	/* ---- Implementations ---- */
	static int8_t CDC_Init_User(void)
	{
	  USBD_CDC_SetTxBuffer(&hUsbDeviceFS, cdcTxScratch, 0);
	  USBD_CDC_SetRxBuffer(&hUsbDeviceFS, cdcRxScratch);
	  return USBD_OK;
	}

	static int8_t CDC_DeInit_User(void) { return USBD_OK; }
	static int8_t CDC_Control_User(uint8_t cmd, uint8_t *p, uint16_t l) { (void)cmd; (void)p; (void)l; return USBD_OK; }

	static int8_t CDC_Receive_User(uint8_t *Buf, uint32_t *Len)
	{
	  for (uint32_t i = 0; i < *Len; i++) {
		uint16_t next = (uint16_t)((CDC_RxHead + 1) % sizeof(CDC_RxBuffer));
		if (next == CDC_RxTail) { CDC_RxTail = (uint16_t)((CDC_RxTail + 1) % sizeof(CDC_RxBuffer)); }
		CDC_RxBuffer[CDC_RxHead] = Buf[i];
		CDC_RxHead = next;
	  }
	  USBD_CDC_SetRxBuffer(&hUsbDeviceFS, &Buf[0]);
	  USBD_CDC_ReceivePacket(&hUsbDeviceFS);
	  return USBD_OK;
	}

	static int8_t CDC_TxCplt_User(uint8_t *p, uint32_t *l, uint8_t ep) { (void)p; (void)l; (void)ep; return USBD_OK; }

	/* Optional: your public helpers (non-static) */
	int CDC_Available(void)
	{
	  return (int)((CDC_RxHead + sizeof(CDC_RxBuffer) - CDC_RxTail) % sizeof(CDC_RxBuffer));
	}
	int CDC_GetCharNonBlocking(void)
	{
	  if (CDC_RxHead == CDC_RxTail) return -1;
	  int c = CDC_RxBuffer[CDC_RxTail];
	  CDC_RxTail = (uint16_t)((CDC_RxTail + 1) % sizeof(CDC_RxBuffer));
	  return c & 0xFF;
	}
	int CDC_Read(uint8_t *dst, int max_len)
	{
	  int n = 0;
	  while (n < max_len && CDC_RxHead != CDC_RxTail) {
		dst[n++] = CDC_RxBuffer[CDC_RxTail];
		CDC_RxTail = (uint16_t)((CDC_RxTail + 1) % sizeof(CDC_RxBuffer));
	  }
	  return n;
	}
