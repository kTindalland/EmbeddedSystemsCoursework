/* 
 * File:   DS18B20.h
 * Author: kaiti
 *
 * Created on 14 December 2020, 10:56
 */

#ifndef __UNIT_TESTING
#include <xc.h>
#endif

#ifndef DS18B20_H
#define	DS18B20_H

#ifdef	__cplusplus
extern "C" {
#endif

#ifndef __UNIT_TESTING
#define DQ RB7
#define DQ_TRIS TRISB7
#define DQ_HIGH() DQ_TRIS = 1; 
#define DQ_LOW() DQ_TRIS = 0; DQ = 0;
#endif


    void ThermInit(void); // Initialise the thermometer.
    void ThermReset(void); // Reset the thermometer.
    void ThermWriteByte(unsigned char); // Write a byte to the thermometer.
    unsigned char ThermReadByte(void); // Read a byte from the thermometer.
    void ThermMeasureTemp(void); // Instruct the thermometer to measure the temperature.
    void ThermGetTemp(unsigned char* msb, unsigned char* lsb); // Retrieve the current temperature.


#ifdef	__cplusplus
}
#endif

#endif	/* DS18B20_H */

