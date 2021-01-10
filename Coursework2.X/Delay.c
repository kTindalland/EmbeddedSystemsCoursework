#include "Delay.h"

// Delay for a set amount of time.
void Delay(unsigned short n)
{
 for(unsigned short i=0;i<n;i++);
}

// Thermometer specific delay
void Therm_Delay(char x, char y) {
    for (char i=0; i < x; i++) {
        for (char j = 0; j < y; j++);
    }    
}