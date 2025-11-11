	/******************************************************************************
	* Project: Rocket Avionics System
	* File: M4_Pin_Map.h
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

	## Digital Outputs

	| Name | Port  | **Pin**           | Mode      | Pull   | Speed     | Level@init      |
	| ---- | ----- | ----------------- | --------- | ------ | --------- | --------------- |
	| DO   | GPIOE | *(from `main.h`)* | OUTPUT_PP | NOPULL | VERY_HIGH | **RESET (Low)** |
	| D1   | GPIOE | *(from `main.h`)* | OUTPUT_PP | NOPULL | VERY_HIGH | **RESET (Low)** |
	| D2   | GPIOE | *(from `main.h`)* | OUTPUT_PP | NOPULL | VERY_HIGH | **RESET (Low)** |
	| D3   | GPIOE | *(from `main.h`)* | OUTPUT_PP | NOPULL | VERY_HIGH | **RESET (Low)** |
	| D4   | GPIOF | *(from `main.h`)* | OUTPUT_PP | NOPULL | VERY_HIGH | **RESET (Low)** |
	| D5   | GPIOF | *(from `main.h`)* | OUTPUT_PP | NOPULL | VERY_HIGH | **RESET (Low)** |
	| D6   | GPIOF | *(from `main.h`)* | OUTPUT_PP | NOPULL | VERY_HIGH | **RESET (Low)** |
	| D7   | GPIOF | *(from `main.h`)* | OUTPUT_PP | NOPULL | VERY_HIGH | **RESET (Low)** |
	| D8   | GPIOF | *(from `main.h`)* | OUTPUT_PP | NOPULL | VERY_HIGH | **RESET (Low)** |
	| D9   | GPIOA | *(from `main.h`)* | OUTPUT_PP | NOPULL | VERY_HIGH | **RESET (Low)** |
	| D10  | GPIOA | *(from `main.h`)* | OUTPUT_PP | NOPULL | VERY_HIGH | **RESET (Low)** |
	| D11  | GPIOA | *(from `main.h`)* | OUTPUT_PP | NOPULL | VERY_HIGH | **RESET (Low)** |
	| D12  | GPIOC | *(from `main.h`)* | OUTPUT_PP | NOPULL | VERY_HIGH | **RESET (Low)** |
	| D13  | GPIOC | *(from `main.h`)* | OUTPUT_PP | NOPULL | VERY_HIGH | **RESET (Low)** |
	| D14  | GPIOB | *(from `main.h`)* | OUTPUT_PP | NOPULL | VERY_HIGH | **RESET (Low)** |
	| D15  | GPIOB | *(from `main.h`)* | OUTPUT_PP | NOPULL | VERY_HIGH | **RESET (Low)** |
	| D16  | GPIOB | *(from `main.h`)* | OUTPUT_PP | NOPULL | VERY_HIGH | **RESET (Low)** |
	| D17  | GPIOF | *(from `main.h`)* | OUTPUT_PP | NOPULL | VERY_HIGH | **RESET (Low)** |

	---

	## Analog Inputs

	| Name | Port  | **Pin**           | Mode   | Pull   |
	| ---- | ----- | ----------------- | ------ | ------ |
	| A0   | GPIOF | *(from `main.h`)* | ANALOG | NOPULL |
	| A1   | GPIOF | *(from `main.h`)* | ANALOG | NOPULL |
	| A2   | GPIOF | *(from `main.h`)* | ANALOG | NOPULL |
	| A3   | GPIOF | *(from `main.h`)* | ANALOG | NOPULL |
	| A4   | GPIOG | *(from `main.h`)* | ANALOG | NOPULL |
	| A5   | GPIOG | *(from `main.h`)* | ANALOG | NOPULL |

	> Note: Actual ADC channels depend on the concrete MCU pin (e.g., `PF3 -> ADC3_INP5`). Resolve once **Pin** values are filled.

	---

	## On‑board LEDs

	| Name         | Port  | **Pin**           | Mode      | Pull   | Speed     | Level@init     | Note                                       |
	| ------------ | ----- | ----------------- | --------- | ------ | --------- | -------------- | ------------------------------------------ |
	| M4_Red_LED   | GPIOD | *(from `main.h`)* | OUTPUT_PP | NOPULL | VERY_HIGH | **SET (High)** | LED polarity: if active‑low LED, SET = OFF |
	| M4_Green_LED | GPIOD | *(from `main.h`)* | OUTPUT_PP | NOPULL | VERY_HIGH | **SET (High)** | "                                          |
	| M4_Blue_LED  | GPIOD | *(from `main.h`)* | OUTPUT_PP | NOPULL | VERY_HIGH | **SET (High)** | "                                          |

	*/

	#ifndef M4_PIN_MAP_H
	#define M4_PIN_MAP_H

	#ifdef __cplusplus
	extern "C" {
	#endif

	// Logical IDs if you want indexed access
	typedef enum {
	  M4_DO,
	  M4_D1, M4_D2, M4_D3,
	  M4_D4, M4_D5, M4_D6, M4_D7, M4_D8,
	  M4_D9, M4_D10, M4_D11,
	  M4_D12, M4_D13,
	  M4_D14, M4_D15, M4_D16,
	  M4_D17,
	  M4_A0, M4_A1, M4_A2, M4_A3, M4_A4, M4_A5,
	  M4_LED_R, M4_LED_G, M4_LED_B,
	  M4_PIN_COUNT
	} M4_PinID;

	typedef struct {
	  const char *name;
	  GPIO_TypeDef *port;
	  uint16_t pin;
	} PinMapEntry;

	static const PinMapEntry M4_PinMap[M4_PIN_COUNT] = {
	  // Digital outputs
	  [M4_DO]   = {"DO",  DO_GPIO_Port,  DO_Pin},
	  [M4_D1]   = {"D1",  D1_GPIO_Port,  D1_Pin},
	  [M4_D2]   = {"D2",  D2_GPIO_Port,  D2_Pin},
	  [M4_D3]   = {"D3",  D3_GPIO_Port,  D3_Pin},
	  [M4_D4]   = {"D4",  D4_GPIO_Port,  D4_Pin},
	  [M4_D5]   = {"D5",  D5_GPIO_Port,  D5_Pin},
	  [M4_D6]   = {"D6",  D6_GPIO_Port,  D6_Pin},
	  [M4_D7]   = {"D7",  D7_GPIO_Port,  D7_Pin},
	  [M4_D8]   = {"D8",  D8_GPIO_Port,  D8_Pin},
	  [M4_D9]   = {"D9",  D9_GPIO_Port,  D9_Pin},
	  [M4_D10]  = {"D10", D10_GPIO_Port, D10_Pin},
	  [M4_D11]  = {"D11", D11_GPIO_Port, D11_Pin},
	  [M4_D12]  = {"D12", D12_GPIO_Port, D12_Pin},
	  [M4_D13]  = {"D13", D13_GPIO_Port, D13_Pin},
	  [M4_D14]  = {"D14", D14_GPIO_Port, D14_Pin},
	  [M4_D15]  = {"D15", D15_GPIO_Port, D15_Pin},
	  [M4_D16]  = {"D16", D16_GPIO_Port, D16_Pin},
	  [M4_D17]  = {"D17", D17_GPIO_Port, D17_Pin},

	  // Analog inputs
	  [M4_A0]   = {"A0",  A0_GPIO_Port,  A0_Pin},
	  [M4_A1]   = {"A1",  A1_GPIO_Port,  A1_Pin},
	  [M4_A2]   = {"A2",  A2_GPIO_Port,  A2_Pin},
	  [M4_A3]   = {"A3",  A3_GPIO_Port,  A3_Pin},
	  [M4_A4]   = {"A4",  A4_GPIO_Port,  A4_Pin},
	  [M4_A5]   = {"A5",  A5_GPIO_Port,  A5_Pin},

	  // LEDs (note: may be active-low on some boards)
	  [M4_LED_R] = {"LED_R", M4_Red_LED_GPIO_Port,   M4_Red_LED_Pin},
	  [M4_LED_G] = {"LED_G", M4_Green_LED_GPIO_Port, M4_Green_LED_Pin},
	  [M4_LED_B] = {"LED_B", M4_Blue_LED_GPIO_Port,  M4_Blue_LED_Pin},
	};

	// Convenience helpers
	static inline const PinMapEntry* M4_pin(M4_PinID id) { return &M4_PinMap[id]; }
	static inline void M4_write(M4_PinID id, GPIO_PinState s) { HAL_GPIO_WritePin(M4_PinMap[id].port, M4_PinMap[id].pin, s); }
	static inline GPIO_PinState M4_read(M4_PinID id) { return HAL_GPIO_ReadPin(M4_PinMap[id].port, M4_PinMap[id].pin); }

	#ifdef __cplusplus
	}
	#endif

	#endif
