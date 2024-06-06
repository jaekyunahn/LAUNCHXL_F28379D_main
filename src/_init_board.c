/*
 * jaekyunAhn_init_board.c
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
 *      initialize Board Function
 *  @param
 *      None
 *  @retval
 *      None
 */
void init_board(void)
{
    //  Step 1. Initialize System Control:
    //  PLL, WatchDog, enable Peripheral Clocks
    //  This example function is found in the F2837xD_SysCtrl.c file.
    InitSysCtrl();

    //  Low Speed Clock Prescaler setting
    //  LOSCLK = SYSCLKOUT/(LOSPCP*2)
    //  LOSCLK = 200MHz/(2*2) = 50MHz
    //EALLOW;
    //ClkCfgRegs.LOSPCP.bit.LSPCLKDIV = 2;
    //EDIS;

#ifdef CPU1
    //  Step 2. Initialize GPIO:
    //  This example function is found in the F2837xD_Gpio.c file and
    //  illustrates how to set the GPIO to it's default state.
    InitGpio();

    //  GPIO setting
    set_gpio();
#endif

    //  Step 3. Clear all interrupts and initialize PIE vector table:
    //  Disable CPU interrupts
    DINT;

    //  Initialize the PIE control registers to their default state.
    //  The default state is all PIE interrupts disabled and flags
    //  are cleared.
    //  This function is found in the F2837xD_PieCtrl.c file.
    InitPieCtrl();

    //  Disable CPU interrupts and clear all CPU interrupt flags:
    IER = 0x0000;
    IFR = 0x0000;

    //  Initialize the PIE vector table with pointers to the shell Interrupt
    //  Service Routines (ISR).
    //  This will populate the entire table, even if the interrupt
    //  is not used in this example.  This is useful for debug purposes.
    //  The shell ISR routines are found in F2837xD_DefaultIsr.c.
    //  This function is found in F2837xD_PieVect.c.
    InitPieVectTable();

    //  initialize Module or Core
    //  SCI
    init_sci();

    //  Enable global Interrupts and higher priority real-time debug events:
    EINT;  // Enable Global interrupt INTM
    ERTM;  // Enable Global realtime interrupt DBGM
}
