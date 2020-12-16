#include "ButtonDriver.h"
#include <xc.h>

void initialiseButtons() {
        
        ADCON1 = 0x07;
        TRISA = 0xFF;
        TRISB = 0xFF;
}

void checkButtons(int* button_array) {
    initialiseButtons();

    unsigned int mask;
    int i = 0;

    for (mask = 1; mask != 16; mask <<= 1) {

        if (PORTB & mask) {
            button_array[i] = RIGHT_SIDE_HIGH;
        }
        i++;
    }
    
    for (mask = 1; mask != 16; mask <<= 1) {

        if (PORTA & mask) {
            button_array[i] = RIGHT_SIDE_HIGH;
        }
        i++;
    }
}