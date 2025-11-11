	/******************************************************************************
	* Project: Rocket Avionics System
	* File: M4_LED.c
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


	#include "M4_Configuration.h"

	// SYSTEM DEFINITIONS
	int flash_counter = 0;
	LED myLED;

	// ========== LED FUNCTIONS (now use Pin IDs) ==========

	void LED_init(LED* led, M4_PinID r_id, M4_PinID g_id, M4_PinID b_id){
	led->r_id = r_id;
	led->g_id = g_id;
	led->b_id = b_id;

	// Assume active-low LEDs: SET = off at init (matches your HAL init)
	M4_write(led->r_id, GPIO_PIN_SET);
	M4_write(led->g_id, GPIO_PIN_SET);
	M4_write(led->b_id, GPIO_PIN_SET);
	}

	static inline void LED__only(LED* led, M4_PinID on_id){
	// active-low: the selected color is RESET, others SET
	M4_write(led->r_id, (on_id == led->r_id) ? GPIO_PIN_RESET : GPIO_PIN_SET);
	M4_write(led->g_id, (on_id == led->g_id) ? GPIO_PIN_RESET : GPIO_PIN_SET);
	M4_write(led->b_id, (on_id == led->b_id) ? GPIO_PIN_RESET : GPIO_PIN_SET);
	}

	void LED_red(LED* led)   { LED__only(led, led->r_id); }
	void LED_green(LED* led) { LED__only(led, led->g_id); }
	void LED_blue(LED* led)  { LED__only(led, led->b_id); }

	void LED_on(LED* led, const char* color){
	if (strcmp(color, "red") == 0) {
	LED_red(led);
	} else if (strcmp(color, "green") == 0) {
	LED_green(led);
	} else if (strcmp(color, "blue") == 0) {
	LED_blue(led);
	}
		}

	void LED_off(LED* led, const char* color){
	if (strcmp(color, "red") == 0) {
	M4_write(led->r_id, GPIO_PIN_SET);
	} else if (strcmp(color, "green") == 0) {
	M4_write(led->g_id, GPIO_PIN_SET);
	} else if (strcmp(color, "blue") == 0) {
	M4_write(led->b_id, GPIO_PIN_SET);
	}
	}

	void LED_flash(LED* led, unsigned long interval_ms, const char* color){
	static unsigned long last_time = 0;
	static GPIO_PinState state = GPIO_PIN_SET;
	unsigned long now = HAL_GetTick();
	M4_PinID target =
	(strcmp(color, "red") == 0)   ? led->r_id :
	(strcmp(color, "green") == 0) ? led->g_id :
	                                led->b_id;

	// Turn OFF all other LEDs (force SET = OFF)
	M4_write(led->r_id, (target == led->r_id) ? state : GPIO_PIN_SET);
	M4_write(led->g_id, (target == led->g_id) ? state : GPIO_PIN_SET);
	M4_write(led->b_id, (target == led->b_id) ? state : GPIO_PIN_SET);

	// Handle timing for flashing the selected LED
	if (now - last_time >= interval_ms)
	{
	last_time = now;
	state = (state == GPIO_PIN_SET) ? GPIO_PIN_RESET : GPIO_PIN_SET;  // toggle
	M4_write(target, state);
	}
		}

	void LED_count(LED* led, int count, const char* color, int delay_ms){
	static uint32_t last_flash_time = 0;
	static int local_counter = 0;
	uint32_t now = HAL_GetTick();
	M4_PinID target =
	(strcmp(color, "red") == 0)   ? led->r_id :
	(strcmp(color, "green") == 0) ? led->g_id :
											led->b_id;
	if (now - last_flash_time >= (uint32_t)delay_ms) {
	if (local_counter < count) {
	M4_write(target, (local_counter % 2 == 0) ? GPIO_PIN_RESET : GPIO_PIN_SET);
	local_counter++;
	last_flash_time = now;
	}
	}
	if (local_counter >= count) {
	local_counter = 0;
	}
		}

