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
#define DQ RA0
#define DQ_TRIS TRISA0
#define DQ_HIGH() DQ_TRIS = 1; 
#define DQ_LOW() DQ_TRIS = 0; DQ = 0;
#endif


    void ThermInit();
    void ThermReset();
    void ThermWriteByte(unsigned char);
    unsigned char ThermReadByte();
    void ThermMeasureTemp();
    void ThermGetTemp(unsigned char* msb, unsigned char* lsb);


#ifdef	__cplusplus
}
#endif

#endif	/* DS18B20_H */

