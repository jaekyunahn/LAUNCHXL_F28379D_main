/*
 * jaekyunAhn_GPIO.c
 *
 *  Created on: 2022. 10. 23.
 *      Author: ajg10
 */

/*
 *  Include
 */
#include "main.h"

/*
 *  @brief
 *      GPIO setting Function
 *  @param
 *      None
 *  @retval
 *      None
 */
void set_gpio(void)
{
    EALLOW;

    //  LED Blue -> 31
    GpioCtrlRegs.GPADIR.bit.GPIO31 = 1;     //  output
    GpioCtrlRegs.GPAPUD.bit.GPIO31 = 0;     //  using Pull-up
    GpioCtrlRegs.GPAGMUX2.bit.GPIO31 = 0;   //  GPIO Mode
    GpioCtrlRegs.GPAMUX2.bit.GPIO31 = 0;    //  GPIO Mode

    //  LED Red -> 34
    GpioCtrlRegs.GPBDIR.bit.GPIO34 = 1;     //  output
    GpioCtrlRegs.GPBPUD.bit.GPIO34 = 0;     //  using Pull-up
    GpioCtrlRegs.GPBGMUX1.bit.GPIO34 = 0;   //  GPIO Mode
    GpioCtrlRegs.GPBMUX1.bit.GPIO34 = 0;    //  GPIO Mode

    EDIS;
}


