/*
 * main.h
 *
 *  Created on: 2022. 10. 14.
 *      Author: ajg10
 */

#ifndef MAIN_H_
#define MAIN_H_

//  Standard include file
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdarg.h>

//  TI include
#include "F28x_Project.h"
#include "F2837xD_Ipc_drivers.h"

//
//  Driver lib
//
#include "hw_memmap.h"
#include "hw_can.h"
#include "can.h"
#include "hw_ints.h"
#include "hw_types.h"
#include "hw_uart.h"
#include "debug.h"
#include "interrupt.h"
#include "sysctl.h"

#include "uartstdio.h"
#include "ustdlib.h"

//  user include
#include "_define.h"
#include "_routine.h"
#include "_init_app.h"
#include "_interrupt.h"
#include "_init_board.h"
#include "Global_Variable.h"

#include "bsp_can.h"
#include "bsp_gpio.h"
#include "bsp_sci.h"

//
//
//
#include "_ramfunction.h"

//
//  Define
//
#define NPC_CPU_SYS_CLOCK       200000000.0
#define NPC_PWMSYSCLOCK_FREQ    100000000.0
#define NPC_ECAPSYSCLOCK_FREQ   200000000.0
#define NPC_ACQPS_SYS_CLKS      ((float32_t)100.0 * (float32_t)0.000000001 * (float32_t)NPC_CPU_SYS_CLOCK)

#endif /* MAIN_H_ */
