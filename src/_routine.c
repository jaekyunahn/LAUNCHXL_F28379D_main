/*
 * app_routine.c
 *
 *  Created on: 2022. 12. 31.
 *      Author: ajg10
 */
#include "main.h"

Uint16      debug_check_main_loop_counter = 0;
Uint16      debug_check_Control_loop_counter = 0;

float32     control_loop_Time_us = 0.0;
uint32_t    control_loop_TimeInit = 0;
uint32_t    control_loop_TimePresent = 0;

void control_routine(void)
{

}

//
//  ===============================================================================================================================================================================
//

void main_routine(void)
{
    //
    //  main loop code
    //
    debug_check_main_loop_counter++;
}

//
//  End File
//
