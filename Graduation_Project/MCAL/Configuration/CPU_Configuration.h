/*
 * CPU_config.h
 *
 * Created: 9/15/2023 10:48:56 AM
 *  Author: Belal Hassan
 */ 
//This header file includes all MCU-specific files and definitions.

#ifndef CPU_CONFIGURATION_H_
#define CPU_CONFIGURATION_H_

#undef F_CPU //Undefined the CPU Frequency it case it was defined before.
#define F_CPU 20000000 //Redefines the Frequency to 20MHz.
/*________________Header Files________________*/
#include <STD_Types.h>
#include <Bit_Math.h>
#include <avr/io.h>
#include <stddef.h>
#include <stdbool.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#endif /* CPU_CONFIGURATION_H_ */