/*
 * bsp_sci.h
 *
 *  Created on: 2023. 8. 29.
 *      Author: user
 */

#ifndef INC_BSP_BSP_SCI_H_
#define INC_BSP_BSP_SCI_H_

void init_sci(void);
void init_sci_a(void);

Uint16 scia_read(void);
void scia_write(Uint16 data);

//
//
//

#endif /* INC_BSP_BSP_SCI_H_ */
