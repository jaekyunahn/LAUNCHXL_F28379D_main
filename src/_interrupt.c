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

// #pragma DATA_SECTION ��ó�� ���ø� ����ϴ� ���� �ش� �������� ����ڰ� ������ ���ǿ�
// ��ġ��Ű�� ������.
// �ش� ����� ���� ������ CMD ���Ͽ��� ������ �޸�(CLA message RAM) ��ġ�� ��ġ�ؾ� �մϴ�.
// �Ʒ� �������� CPU���� CLA�� �ԷµǴ� �����Ϳ� CLA���� CPU�� ��µǴ� �����͸� �����ϱ� ����
// ���� �������� CLA message RAM ������ ��ġ�ϱ� ���� �ڵ� �Դϴ�.

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
