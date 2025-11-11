	/******************************************************************************
	* Project: Rocket Avionics System
	* File: M7_LED.c
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

	// SYSTEM DEFINITIONS
	int flash_counter = 0;
	LED myLED;

	// ========== LED FUNCTIONS (now use Pin IDs) ==========

	void LED_init(LED* led, M7_PinID r_id, M7_PinID g_id, M7_PinID b_id){
	led->r_id = r_id;
	led->g_id = g_id;
	led->b_id = b_id;

	// Off (active-low -> SET = off)
	M7_write(led->r_id, GPIO_PIN_SET);
	M7_write(led->g_id, GPIO_PIN_SET);
	M7_write(led->b_id, GPIO_PIN_SET);
	}

	static inline void LED__only(LED* led, M7_PinID on_id){
	// Force non-selected OFF; selected ON (active-low)
	M7_write(led->r_id, (on_id == led->r_id) ? GPIO_PIN_RESET : GPIO_PIN_SET);
	M7_write(led->g_id, (on_id == led->g_id) ? GPIO_PIN_RESET : GPIO_PIN_SET);
	M7_write(led->b_id, (on_id == led->b_id) ? GPIO_PIN_RESET : GPIO_PIN_SET);
	}

	void LED_red(LED* led)   { LED__only(led, led->r_id); }
	void LED_green(LED* led) { LED__only(led, led->g_id); }
	void LED_blue(LED* led)  { LED__only(led, led->b_id); }

	void LED_on(LED* led, const char* color){
	if      (strcmp(color, "red")   == 0) LED_red(led);
	else if (strcmp(color, "green") == 0) LED_green(led);
	else if (strcmp(color, "blue")  == 0) LED_blue(led);
	}

	void LED_off(LED* led, const char* color){
	if      (strcmp(color, "red")   == 0) M7_write(led->r_id, GPIO_PIN_SET);
	else if (strcmp(color, "green") == 0) M7_write(led->g_id, GPIO_PIN_SET);
	else if (strcmp(color, "blue")  == 0) M7_write(led->b_id, GPIO_PIN_SET);
	}

	// Non-blocking flasher; forces non-selected colors OFF every call
	void LED_flash(LED* led, unsigned long interval_ms, const char* color){
	static unsigned long last_time = 0;
	static GPIO_PinState state = GPIO_PIN_SET;  // SET = off (active-low)
	unsigned long now = HAL_GetTick();

	M7_PinID target =
	(strcmp(color, "red")   == 0) ? led->r_id :
	(strcmp(color, "green") == 0) ? led->g_id :
									led->b_id;

	// Force other LEDs OFF always
	M7_write(led->r_id, (target == led->r_id) ? state : GPIO_PIN_SET);
	M7_write(led->g_id, (target == led->g_id) ? state : GPIO_PIN_SET);
	M7_write(led->b_id, (target == led->b_id) ? state : GPIO_PIN_SET);

	if (now - last_time >= interval_ms) {
	last_time = now;
	state = (state == GPIO_PIN_SET) ? GPIO_PIN_RESET : GPIO_PIN_SET; // toggle
	M7_write(target, state);
	}
		}

	void LED_count(LED* led, int count, const char* color, int delay_ms){
	static uint32_t last_flash_time = 0;
	static int local_counter = 0;
	uint32_t now = HAL_GetTick();

	// Select which LED to blink
	M7_PinID target =
	(strcmp(color, "red")   == 0) ? led->r_id :
	(strcmp(color, "green") == 0) ? led->g_id :
	                                        led->b_id;

	// 🔥 Force all non-selected LEDs OFF (active-low = SET)
	M7_write(led->r_id, (target == led->r_id) ? GPIO_PIN_SET : GPIO_PIN_SET);
	M7_write(led->g_id, (target == led->g_id) ? GPIO_PIN_SET : GPIO_PIN_SET);
	M7_write(led->b_id, (target == led->b_id) ? GPIO_PIN_SET : GPIO_PIN_SET);

	// Only blink the target LED
	if (now - last_flash_time >= (uint32_t)delay_ms)
	{
	if (local_counter < count * 2)  // *2 because ON+OFF = 2 toggles per blink
	{
	// Toggle selected LED (active-low: RESET = ON, SET = OFF)
	GPIO_PinState state = (local_counter % 2 == 0) ? GPIO_PIN_RESET : GPIO_PIN_SET;
	M7_write(target, state);
	local_counter++;
	last_flash_time = now;
	}
	else
	{
	// Done – turn off LED and reset counter
	M7_write(target, GPIO_PIN_SET);  // OFF
	local_counter = 0;
	}
		}
			}

	void LED_toggle(LED* led, const char* color)
	{
	    // Determine target LED ID
	    M7_PinID target =
	        (strcmp(color, "red")   == 0) ? led->r_id :
	        (strcmp(color, "green") == 0) ? led->g_id :
	                                        led->b_id;

	    // Read current state of selected LED
	    GPIO_PinState current = M7_read(target);

	    // ACTIVE-LOW: SET = OFF, RESET = ON
	    GPIO_PinState newState = (current == GPIO_PIN_SET) ? GPIO_PIN_RESET : GPIO_PIN_SET;

	    // Force non-selected LEDs OFF (SET)
	    M7_write(led->r_id, (target == led->r_id) ? newState : GPIO_PIN_SET);
	    M7_write(led->g_id, (target == led->g_id) ? newState : GPIO_PIN_SET);
	    M7_write(led->b_id, (target == led->b_id) ? newState : GPIO_PIN_SET);
	}
