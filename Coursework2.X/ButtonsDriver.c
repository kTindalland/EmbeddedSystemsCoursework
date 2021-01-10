#include "ButtonsDriver.h"

#include <xc.h>

void initialiseButtons(void) {
        
        ADCON1 = 0x07;
        TRISA = TRISA | 0xF7;
        TRISB = TRISB | 0x0F;
        TRISE = TRISE | 0x04; // use port E for one pin that clashes with important pin in the LCD screen.
}

void initialiseMatrixButtons(void) {
    TRISC = 0x0F;
}
