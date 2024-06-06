/*
 * bsp_can.c
 *
 *  Created on: 2024. 5. 30.
 *      Author: User
 */
#include "main.h"

void init_can(void)
{
    EALLOW;

    GpioCtrlRegs.GPAPUD.bit.GPIO12   = 0;   //  핀 내부 Pull-up 회로 활성화
    GpioCtrlRegs.GPAQSEL1.bit.GPIO12 = 3;   //  동기화나 필터링(Input Qualification)을 수행하지 않음
    GpioCtrlRegs.GPAMUX1.bit.GPIO12  = 2;   //  MUX 설정
    GpioCtrlRegs.GPAGMUX1.bit.GPIO12 = 0;   //  GMUX 설정

    GpioCtrlRegs.GPAPUD.bit.GPIO17   = 0;   //  핀 내부 Pull-up 회로 활성화
    GpioCtrlRegs.GPAQSEL2.bit.GPIO17 = 3;   //  동기화나 필터링(Input Qualification)을 수행하지 않음
    GpioCtrlRegs.GPAMUX2.bit.GPIO17  = 2;   //  MUX 설정
    GpioCtrlRegs.GPAGMUX2.bit.GPIO17 = 0;   //  GMUX 설정

    EDIS;

    //
    // Initialize the CAN controller
    //
    CANInit(CANA_BASE);

    //
    // Setup CAN to be clocked off the M3/Master subsystem clock
    //
    CANClkSourceSelect(CANA_BASE, 0);

    //
    // Set up the bit rate for the CAN bus.  This function sets up the CAN
    // bus timing for a nominal configuration.  You can achieve more control
    // over the CAN bus timing by using the function CANBitTimingSet() instead
    // of this one, if needed.
    // In this example, the CAN bus is set to 500 kHz.  In the function below,
    // the call to SysCtlClockGet() is used to determine the clock rate that
    // is used for clocking the CAN peripheral.  This can be replaced with a
    // fixed value if you know the value of the system clock, saving the extra
    // function call.  For some parts, the CAN peripheral is clocked by a fixed
    // 8 MHz regardless of the system clock in which case the call to
    // SysCtlClockGet() should be replaced with 8000000.  Consult the data
    // sheet for more information about CAN peripheral clocking.
    //
    CANBitRateSet(CANA_BASE, 200000000, 500000);


    //
    // Enable the CAN for operation.
    //
    CANEnable(CANA_BASE);
}
