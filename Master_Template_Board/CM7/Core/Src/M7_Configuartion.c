	/******************************************************************************
	* Project: Rocket Avionics System
	* File: M7_Function.c
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

	extern I2C_HandleTypeDef hi2c1;
	extern I2C_HandleTypeDef hi2c2;
	#define SharedData  IPC_ADDR

	void ConfigurationInit(void){
	LED_init(&myLED, M7_LED_R, M7_LED_G, M7_LED_B);
	LED_green(&myLED);
	I2C_Scan_hi2c1();
	I2C_Scan_hi2c2();
	SerialPrintln("\r\n[CM7] Init complete.");
	}

	void delay(uint32_t ms){
	HAL_Delay(ms);
	}

	void MPU_Config_D2_NonCacheable(void){
	MPU_Region_InitTypeDef cfg;
	HAL_MPU_Disable();
	cfg.Enable           = MPU_REGION_ENABLE;
	cfg.Number           = MPU_REGION_NUMBER2;
	cfg.BaseAddress      = 0x30000000;
	cfg.Size             = MPU_REGION_SIZE_512KB;
	cfg.SubRegionDisable = 0x00;
	cfg.TypeExtField     = MPU_TEX_LEVEL0;
	cfg.AccessPermission = MPU_REGION_FULL_ACCESS;
	cfg.DisableExec      = MPU_INSTRUCTION_ACCESS_ENABLE;
	cfg.IsShareable      = MPU_ACCESS_NOT_SHAREABLE;
	cfg.IsCacheable      = MPU_ACCESS_NOT_CACHEABLE;
	cfg.IsBufferable     = MPU_ACCESS_NOT_BUFFERABLE;
	HAL_MPU_ConfigRegion(&cfg);
	HAL_MPU_Enable(MPU_PRIVILEGED_DEFAULT);
	}

	void Error_HandlerEx(uint32_t errorCode, const char *errorMsg){
	(void)errorCode;
	(void)errorMsg;
	__disable_irq();
	}

	void I2C_Scan_hi2c1(void){
	HAL_StatusTypeDef result;
	uint8_t devicesFound = 0;
	char msg[64];
	SerialPrintln("Scanning I2C_1...");
	for (uint8_t i = 1; i < 128; i++) {
	result = HAL_I2C_IsDeviceReady(&hi2c1, (uint16_t)(i << 1), 1, 10);
	if (result == HAL_OK) {
	devicesFound++;
	snprintf(msg, sizeof(msg), "Device found at 0x%02X", i);
	SerialPrintln("%s", msg);
	}
	}
	if (devicesFound == 0) {
	SerialPrintln("No I2C devices found on I2C_1.");
	}
	SerialPrintln("Scan complete I2C_1.");
	HAL_Delay(2000);
	}

	void I2C_Scan_hi2c2(void){
	HAL_StatusTypeDef result;
	uint8_t devicesFound = 0;
	char msg[64];
	SerialPrintln("Scanning I2C_2...");
	for (uint8_t i = 1; i < 128; i++) {
	result = HAL_I2C_IsDeviceReady(&hi2c2, (uint16_t)(i << 1), 1, 10);
	if (result == HAL_OK) {
	devicesFound++;
	snprintf(msg, sizeof(msg), "Device found at 0x%02X", i);
	SerialPrintln("%s", msg);
	}
	}
	if (devicesFound == 0) {
	SerialPrintln("No I2C devices found on I2C_2.");
	}
	SerialPrintln("Scan complete I2C_2.");
	HAL_Delay(2000);
	}

