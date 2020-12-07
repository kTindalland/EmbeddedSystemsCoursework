#include "ButtonDriver.h"
#include <xc.h>

void initialiseButtons() {
        
        ADCON1 = 0x07;
        TRISA = 0xFF;
        TRISB = 0xFF;
}

int* checkButtons() {
    initialiseButtons();
    int result[8] = { 0 };

    unsigned int mask;
    int i = 0;

    for (mask = 1; mask != 16; mask <<= 1) {

        if (PORTB & mask) {
            result[i] = RIGHT_SIDE_HIGH;
        }
        i++;
    }
    
    for (mask = 1; mask != 16; mask <<= 1) {

        if (PORTA & mask) {
            result[i] = RIGHT_SIDE_HIGH;
        }
        i++;
    }
    return result;
}