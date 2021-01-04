#include "RealTimeClockConversions.h"
#include <xc.h>

#ifndef RTC_H
#define	RTC_H

#ifdef	__cplusplus
extern "C" {
#endif

    #define RTC_READ 0x80
    #define RTC_WRITE 0x00
    #define AM 0
    #define PM 1

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

    #define RST RB5
    #define SCLK RB0
    #define RTC_IO RB4
    
    #define IRTC_SUCCESS 1
    #define IRTC_ERROR 2
    
    void clearWP(void);

    void writeByte(uch addr, uch data);    
    uch readByte(uch addr);
    void startClock(void);
    void stopClock(void);

#ifdef	__cplusplus
}
#endif
#endif	/* RTC_H */

