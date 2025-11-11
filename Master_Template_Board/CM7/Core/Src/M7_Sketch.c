	/******************************************************************************
	* Project: Rocket Avionics System
	* File: M7_Sketch.c
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

	/* PLEASE ENTER PRIVATE CODE WITHIN FUNCTION .c AND .h FILES, DO NOT ENETER CODE
	 * ANYWHERE ELSE NOR MODIFIY CODE OUTSIDE THESE FILES, THIS BOOTLOADER HAS BEEN CUSTOM
	 * DESIGNED BY MICHAEL CALLER*/

	#include "M7_Configuration.h"



	void setup(void){

	}


	void loop(void)
	{
	    static uint32_t lastBlink = 0;
	    static uint32_t lastOnline = 0;
	    uint32_t now = HAL_GetTick();


	    SerialPrintInt(SystemState);
	    SerialPrint(" ");
	    SerialPrintFloat(float_test, 2);
	    SerialPrint("\r\n");

	    if (SerialIsOnline()) {
	        lastOnline = now;
	    }


	    if ((now - lastOnline) > 50U) {
	        LED_on(&myLED, "blue");
	        return;
	    }

	    if ((now - lastBlink) >= 35U) {
	        LED_toggle(&myLED, "green");
	        lastBlink = now;
	    }
	}










