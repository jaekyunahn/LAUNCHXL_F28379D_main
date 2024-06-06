/*
 * jaekyunAhn_interrupt.h
 *
 *  Created on: 2022. 10. 23.
 *      Author: ajg10
 */

#ifndef INC_JAEKYUNAHN_INTERRUPT_H_
#define INC_JAEKYUNAHN_INTERRUPT_H_

__interrupt void _epwm1_interrupt_isr(void);
__interrupt void epwm1_tzint_isr(void);

__interrupt void cla1Isr1 (void);
__interrupt void cla1Isr2 (void);
__interrupt void cla1Isr3 (void);
__interrupt void cla1Isr4 (void);
__interrupt void cla1Isr5 (void);
__interrupt void cla1Isr6 (void);
__interrupt void cla1Isr7 (void);
__interrupt void cla1Isr8 (void);

#endif /* INC_JAEKYUNAHN_INTERRUPT_H_ */
