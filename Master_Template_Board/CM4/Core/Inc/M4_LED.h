	/******************************************************************************
	* Project: Rocket Avionics System
	* File: M4_LED.h
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

	#ifndef M4_LED_H
	#define M4_LED_H

	#ifdef __cplusplus
	extern "C" {
	#endif

	// CUSTOM TYPEDEF'S
	typedef struct {
		M4_PinID r_id;
		M4_PinID g_id;
		M4_PinID b_id;
	} LED;

	// CUSTOM SYSTEM DEFINITIONS
	extern LED myLED;
	extern int flash_counter;

	// CUSTOM SYSTEM FUNCTIONS
	void LED_init(LED* led, M4_PinID r_id, M4_PinID g_id, M4_PinID b_id);
	void LED_red(LED* led);
	void LED_green(LED* led);
	void LED_blue(LED* led);
	void LED_on(LED* led, const char* color);
	void LED_off(LED* led, const char* color);
	void LED_flash(LED* led, unsigned long interval_ms, const char* color);
	void LED_count(LED* led, int count, const char* color, int delay_ms);
	void LED_toggle(LED* led, const char* color);


	#ifdef __cplusplus
	}
	#endif

	#endif
