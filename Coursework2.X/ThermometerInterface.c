#include "ThermometerInterface.h"
#include "ThermometerDriver.h"

void IThermGetTemperature(signed char* whole, unsigned char* decimal) {
    // Variable declarations.
    unsigned char msb;
    unsigned char lsb;
    
    signed char whole_number;
    unsigned char decimal_number;
    
    unsigned char sign;
    
    *whole = 0;
    *decimal = 0;
    
    // Measure current ambient temperature.
    ThermMeasureTemp();
    
    // Populate msb and lsb
    ThermGetTemp(&msb, &lsb);

    if (msb == 0 && lsb == 0) return;
    
    // Get the sign.
    sign = msb & 0xF8;
    
    // Get rid of the sign
    whole_number = msb & 0x07; 
    
    // Move along four
    whole_number <<= 4;
    
    // Move lsb four to the left
    decimal_number = lsb >> 4;
    
    whole_number = whole_number | decimal_number; // Complete whole number.
    if (sign) whole_number = whole_number * -1;
    
    *whole = whole_number;
    
    // Make decimal number just the decimal part.
    decimal_number = lsb & 0x0F;
    
    if (decimal_number & 0x08) *decimal = *decimal + 5;
    if (decimal_number & 0x04) *decimal = *decimal + 3;
    if (decimal_number & 0x02) *decimal = *decimal + 1;
    //if (decimal_number & 0x01) *decimal = *decimal + 0.0625;
    
}
