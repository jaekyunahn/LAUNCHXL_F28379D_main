/*
 * bsp_sci.c
 *
 *  Created on: 2023. 8. 29.
 *      Author: user
 */
#include "main.h"

#define BIT0        (1<<0)
#define BIT1        (1<<1)
#define BIT2        (1<<2)
#define BIT3        (1<<3)
#define BIT4        (1<<4)
#define BIT5        (1<<5)
#define BIT6        (1<<6)
#define BIT7        (1<<7)

#define CPU_CLK     200000000L          // 200MHz
#define LSP_CLK     (CPU_CLK/4)             // default at reset
#define BAUDRATE_A    115200L

void init_sci(void)
{
    //
    //  SCI A initialize, LAUNCHXL-F28379D Main SCI
    //
    init_sci_a();
}

//
//  SCI initialize
//      1. Clock 공급
//      2. 기본 설정 (stop 1bit, data길이 8bit, Loopback 비활성화, )
//      3. 수신 에러 인터럽트, TX / RX 활성화
//      4. 클럭설정
//      5. 송수신 인터럽트 결정
//      6. SCI 리셋
//
void init_sci_a(void)
{
    int32 i = 0;

    EALLOW;

    //
    //  GPIO
    //

    //
    //  23NPC RS485
    //
    GpioCtrlRegs.GPBPUD.bit.GPIO42   = 0;   //  핀 내부 Pull-up 회로 활성화
    GpioCtrlRegs.GPBQSEL1.bit.GPIO42 = 3;   //  동기화나 필터링(Input Qualification)을 수행하지 않음
    GpioCtrlRegs.GPBMUX1.bit.GPIO42  = 3;   //  MUX 설정
    GpioCtrlRegs.GPBGMUX1.bit.GPIO42 = 3;   //  GMUX 설정

    GpioCtrlRegs.GPBPUD.bit.GPIO43   = 0;   //  핀 내부 Pull-up 회로 활성화
    GpioCtrlRegs.GPBQSEL1.bit.GPIO43 = 3;   //  동기화나 필터링(Input Qualification)을 수행하지 않음
    GpioCtrlRegs.GPBMUX1.bit.GPIO43  = 3;   //  MUX 설정
    GpioCtrlRegs.GPBGMUX1.bit.GPIO43 = 3;   //  GMUX 설정

    EDIS;

    //  SCI-B to CPU1
    //  This register must be configured prior to enabling the peripheral clocks.
    EALLOW;
    DevCfgRegs.CPUSEL5.bit.SCI_A = 0;
    EDIS;

    // SCI-B CLOCK ENABLE
    EALLOW;
    CpuSysRegs.PCLKCR7.bit.SCI_A = 1;
    EDIS;

    SciaRegs.SCICCR.all = 0x7;                      // 1 stop & no parity & 8bit char, no loopback
    SciaRegs.SCICTL1.all = BIT1 | BIT0;      // enable RX-ERR interrupt, TX and RX operation

    i = (int32)(((float32)LSP_CLK/((float32)BAUDRATE_A*8.0) - 1) + 0.5);
    SciaRegs.SCIHBAUD.all = i >> 8;
    SciaRegs.SCILBAUD.all = i & 0xFF;

    SciaRegs.SCICTL2.all = 0x0;                             // enable RX/BK INT, TX INT
    SciaRegs.SCICTL1.all = BIT5 | BIT1 | BIT0;       // Relinquish SCI from Reset
}

void scia_write(Uint16 data)
{
    while(SciaRegs.SCICTL2.bit.TXEMPTY==0);
    SciaRegs.SCITXBUF.all = data;
}

Uint16 scia_read(void)
{
    Uint16 res = 0;
    while(SciaRegs.SCIRXST.bit.RXRDY==0); // wait for empty state
    res = SciaRegs.SCIRXBUF.all;
    return res;
}
