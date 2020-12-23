#include "buttons.h"
#include <xc.h>

void initialiseButtons(void) {
        
        ADCON1 = 0x07;
        TRISA = 0xFF;
        TRISB = 0xFF;
        
}

unsigned char checkButtons() {
    initialiseButtons();
    unsigned char result = 0;
    
    result = result | (PORTA & 0x0F);
    result = result << 4;
    result = result | (PORTB & 0x0F);
    
    return result;
}

void initialiseMatrixButtons() {
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
        
        for (unsigned char i = 0; i < 255; i++);
    }
    
}
