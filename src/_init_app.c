/*
 * init_app.c
 *
 *  Created on: 2023. 9. 8.
 *      Author: user
 */
#include "main.h"

#define PI_COUNT  30000
Uint32 pi_data[PI_COUNT + 1];
#pragma DATA_SECTION(pi_data, "ramgs0");

void tprintf(const Uint16 *p) {
    while (*p != '\0') {
        scia_write(*p);
        p++;// 다음 글자 주소
    }
}

Uint16 stringBuffer[4];
    int32 tmp = 0;

void init_app(void) {

    int32 i, k;
    int32 b, d;
    int32 c = 0;

    for (i = 0; i < PI_COUNT; i++) {
        pi_data[i] = 2000;
    }
    pi_data[i] = 0;

    for (k = PI_COUNT; k > 0; k -= 14) {
        d = 0;
        i = k;
        while(1) {
            d += pi_data[i] * 10000;
            b = 2 * i - 1;
            pi_data[i] = d % b;
            d /= b;
            i--;
            if (i == 0)
                break;
            d *= i;
        }
        tmp = (c + d / 10000);

        if(tmp<10) {
            stringBuffer[0]= tmp + 0x30;
            stringBuffer[1]= 0x30;
            stringBuffer[2]= 0x30;
            stringBuffer[3]= 0x30;
        }
        else if(tmp<100) {
            stringBuffer[0]= ( tmp % 10) + 0x30;
            stringBuffer[1]= (( tmp / 10) % 10) + 0x30;
            stringBuffer[2]= 0x30;
            stringBuffer[3]= 0x30;
        }
        else if(tmp<100) {
            stringBuffer[0]= ( tmp % 10) + 0x30;
            stringBuffer[1]= (( tmp / 10) % 10) + 0x30;
            stringBuffer[2]= (( tmp / 100) % 10) + 0x30;
            stringBuffer[3]= 0x30;
        }
        else {
            stringBuffer[0]= ( tmp % 10) + 0x30;
            stringBuffer[1]= (( tmp / 10) % 10) + 0x30;
            stringBuffer[2]= (( tmp / 100) % 10) + 0x30;
            stringBuffer[3]= (( tmp / 1000) % 10) + 0x30;
        }
        scia_write(stringBuffer[3]);
        scia_write(stringBuffer[2]);
        scia_write(stringBuffer[1]);
        scia_write(stringBuffer[0]);

        c = d % 10000;
    }
}


