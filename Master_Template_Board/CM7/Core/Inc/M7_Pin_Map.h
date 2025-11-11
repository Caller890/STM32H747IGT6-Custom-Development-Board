	/******************************************************************************
	* Project: Rocket Avionics System
	* File: M7_Pin_Map.h
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

	Legend

	* **Level@init** = state set by `HAL_GPIO_WritePin(...)` before `HAL_GPIO_Init(...)`
	* **Mode** = `GPIO_MODE_*` used in `InitStruct`
	* **Speed** = `GPIO_SPEED_*`
	* **Pull** = `GPIO_NOPULL` unless stated otherwise

	---

	## On-board LEDs (M7)

	| Name           | Port  | **Pin**           | Mode      | Pull   | Speed     | Level@init     | Note                                       |
	| -------------- | ----- | ----------------- | --------- | ------ | --------- | -------------- | ------------------------------------------ |
	| M7_Green_LED   | GPIOD | *(from `main.h`)* | OUTPUT_PP | NOPULL | VERY_HIGH | **SET (High)** | If active-low LED, SET = OFF               |
	| M7_Red_LED     | GPIOD | *(from `main.h`)* | OUTPUT_PP | NOPULL | VERY_HIGH | **SET (High)** | \"                                         |
	| M7_Blue_LED    | GPIOD | *(from `main.h`)* | OUTPUT_PP | NOPULL | VERY_HIGH | **SET (High)** | \"                                         |

	*/

	#ifndef M7_PIN_MAP_H
	#define M7_PIN_MAP_H

	#ifdef __cplusplus
	extern "C" {
	#endif

	// Logical IDs for indexed access on M7
	typedef enum {
	  M7_LED_G = 0,   // Green
	  M7_LED_R,       // Red
	  M7_LED_B,       // Blue
	  M7_PIN_COUNT
	} M7_PinID;

	typedef struct {
	  const char *name;        // e.g. "M7_LED_G"
	  GPIO_TypeDef *port;      // e.g. GPIOD
	  uint16_t pin;            // e.g. M7_Green_LED_Pin
	} M7_PinMapEntry;

	static const M7_PinMapEntry M7_PinMap[M7_PIN_COUNT] = {
	  [M7_LED_G] = { "M7_LED_G", GPIOD, M7_Green_LED_Pin },
	  [M7_LED_R] = { "M7_LED_R", GPIOD, M7_Red_LED_Pin   },
	  [M7_LED_B] = { "M7_LED_B", GPIOD, M7_Blue_LED_Pin  },
	};

	// Convenience helpers
	static inline const M7_PinMapEntry* M7_pin(M7_PinID id) {
	  return &M7_PinMap[id];
	}
	static inline void M7_write(M7_PinID id, GPIO_PinState s) {
	  HAL_GPIO_WritePin(M7_PinMap[id].port, M7_PinMap[id].pin, s);
	}
	static inline GPIO_PinState M7_read(M7_PinID id) {
	  return HAL_GPIO_ReadPin(M7_PinMap[id].port, M7_PinMap[id].pin);
	}
	static inline void M7_toggle(M7_PinID id) {
	  HAL_GPIO_TogglePin(M7_PinMap[id].port, M7_PinMap[id].pin);
	}

	#ifdef __cplusplus
	}
	#endif

	#endif
