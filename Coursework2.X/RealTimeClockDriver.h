#include "RealTimeClockConversions.h"
#include <xc.h>

#ifndef RTC_H
#define	RTC_H

#ifdef	__cplusplus
extern "C" {
#endif

    // Read and Write bits
    // These can be bitwise OR'ed onto memory addresses
    // to give the read or write versions.
    #define RTC_READ 0x80
    #define RTC_WRITE 0x00

    // Helpful AMPM macros
    #define AM 0
    #define PM 1

    // Clock memory addresses
    #define RTC_SEC 0x01
    #define RTC_MINS 0x41
    #define RTC_HOURS 0x21
    #define RTC_DATE 0x61
    #define RTC_MONTH 0x11
    #define RTC_DAY 0x51
    #define RTC_YEAR 0x31
    #define RTC_CTRL 0x71
    #define RTC_TRICKLE_CHARGER 0x09
    #define RTC_CLK_BURST 0x7D

    // Clock pins
    #define RST RB5
    #define SCLK RB0
    #define RTC_IO RB4
    
    // Error codes
    #define IRTC_SUCCESS 1
    #define IRTC_ERROR 2
    

    void clearWP(void); // Clear the write protect bit
    
    // Read and write to the clock.
    void writeByte(uch addr, uch data);  
    uch readByte(uch addr);
    
    // Start and stop the clock.
    void startClock(void);
    void stopClock(void);

#ifdef	__cplusplus
}
#endif
#endif	/* RTC_H */

