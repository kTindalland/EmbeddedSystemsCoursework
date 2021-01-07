#include "buttons.h"
#include <xc.h>

void initialiseButtons(void) {
        
        ADCON1 = 0x07;
        TRISA = TRISA | 0xF7;
        TRISB = 0xFF;
        TRISE = TRISE | 0x04; // use port E for one pin that clashes with important pin in the LCD screen.
}

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wconversion"

unsigned char checkButtons(void) {
    initialiseButtons();
    unsigned char result = 0;
    
    result = result | (PORTA & 0x0F);
    result = result & 0xF7; // Eliminate clashing bit.
    result = result | ((PORTE & 0x04) << 1); // Put in new bit.
    result = result << 4;
    result = result | (PORTB & 0x0F);
    
    
    
    return result;
}

#pragma GCC diagostic pop

void initialiseMatrixButtons(void) {
    TRISC = 0x0F;
}

void checkMatrixButtons(unsigned char result[4][4]) {
    initialiseMatrixButtons();
    
    // Check button states.
    for (unsigned char row = 0; row < 4; row++) {
        
        PORTC |= 0xF0; // Clear output
        PORTC &= ~(1 << (row + 4)); // Set row
        unsigned char inputs = ~(PORTC | 0xF0);
        
        for (unsigned char col = 0; col < 4; col++) {
            result[row][col] = 0;
            
            if (inputs & (1 << col)) {
                result[row][col] = 1;
            }
        }
    }
}
