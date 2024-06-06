/*
 * app_define.h
 *
 *  Created on: 2023. 1. 1.
 *      Author: ajg10
 */

#ifndef INC_APP_DEFINE_H_
#define INC_APP_DEFINE_H_

#include "F28x_Project.h"

//
//  Define
//

//  ePWM Switching Clock
#define period  2000 // 50kHz

//  Core Clock
#define SYS_CLK_PRD     ((float)5e-9)

//
//  Rx data
//
struct SCI_RX_DATA
{
    char data;
    char flag;
};

//
//  CLA
//
struct CPU_CLA_DATA
{
    Uint32 int32_data;
    Uint16 int16_array[256];
    float32 fp32_array[256];
};

#endif /* INC_APP_DEFINE_H_ */
