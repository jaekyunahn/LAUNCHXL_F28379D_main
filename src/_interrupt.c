/*
 * jaekyunAhn_interrupt.c
 *
 *  Created on: 2022. 10. 23.
 *      Author: ajg10
 */

/*
 *  Include
 */
#include "main.h"

// #pragma DATA_SECTION 전처리 지시를 사용하는 것은 해당 변수들을 사용자가 정의한 섹션에
// 배치시키기 위함임.
// 해당 사용자 정의 섹션은 CMD 파일에서 적절한 메모리(CLA message RAM) 위치에 배치해야 합니다.
// 아래 변수들은 CPU에서 CLA로 입력되는 데이터와 CLA에서 CPU로 출력되는 데이터를 전달하기 위해
// 각각 변수들을 CLA message RAM 영역에 배치하기 위한 코드 입니다.

/*
 *  @brief
 *      epwm4 interrupt Function
 *  @param
 *      None
 *  @retval
 *      None
 */
__interrupt void _epwm1_interrupt_isr(void)
{

}

//
//  ePWM Trip-Zone
//
__interrupt void epwm1_tzint_isr(void)
{

}

__interrupt void cla1Isr1 (void)
{

}

__interrupt void cla1Isr2 (void)
{

}

__interrupt void cla1Isr3 (void)
{

}

__interrupt void cla1Isr4 (void)
{

}

__interrupt void cla1Isr5 (void)
{

}

__interrupt void cla1Isr6 (void)
{

}

__interrupt void cla1Isr7 (void)
{

}

__interrupt void cla1Isr8 (void)
{

}
//
//  End file
//
