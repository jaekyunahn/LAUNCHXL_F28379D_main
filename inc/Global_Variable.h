/*
 * Global_Variable.h
 *
 *  Created on: 2023. 8. 24.
 *      Author: user
 */

#ifndef INC_GLOBAL_VARIABLE_H_
#define INC_GLOBAL_VARIABLE_H_

#include "F28x_Project.h"

extern float32 openloop_a_phase;
extern float32 openloop_b_phase;
extern float32 openloop_c_phase;
extern Uint16 cc_cnt;

void init_var(void);

#endif /* INC_GLOBAL_VARIABLE_H_ */
