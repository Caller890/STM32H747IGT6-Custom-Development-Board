	/******************************************************************************
	* Project: Rocket Avionics System
	* File: M7_Configuration.h
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

	#ifndef M7_CONFIGURATION_H
	#define M7_CONFIGURATION_H

	#ifdef __cplusplus
	extern "C" {
	#endif

	// SYSTEM LIBRARIES
	#include <main.h>
	#include "stm32h7xx_hal.h"
	#include <ctype.h>
	#include <inttypes.h>

	#include <stdio.h>
	#include <stdint.h>
	#include <stdbool.h>
	#include <string.h>
	#include <stdarg.h>

	#include "usbd_cdc_if.h"
	#include "usbd_core.h"
	#include "usbd_def.h"

	#include "usb_device.h"

	// CUSTOM SYSTEM LIBRARIES
	#include "M7_CDC_User.h"
	#include "M7_Pin_Map.h"
	#include "M7_Sketch.h"
	#include "M7_Cache.h"
	#include "M7_Shared.h"
	#include "M7_Serial.h"
	#include "M7_LED.h"
	#include "M7_Digital_Write.h"

	// CUSTOM SYSTEM DEFINITIONS


	// CUSTOM CONFIGURATION INIT
	void ConfigurationInit(void);

	// CUSTOM HAL TRANSLATIONS
	void delay(uint32_t ms);
	void Error_HandlerEx(uint32_t errorCode, const char *errorMsg);
	void I2C_Scan_hi2c1(void);
	void I2C_Scan_hi2c2(void);
	void MPU_Config_D2_NonCacheable(void);
	void Data_Input();

	// IPC
	void IPC_PollAndPrint_M7(void);
	bool USB_GetChar(uint8_t *ch);

	#ifdef __cplusplus
	}
	#endif

	#endif
