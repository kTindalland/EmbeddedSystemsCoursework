#ifndef RTCI_H
#define	RTCI_H

#include "RealTimeClockDriver.h"
#include "RealTimeClockConversions.h"

#ifdef	__cplusplus
extern "C" {
#endif
    
    typedef struct rtcTime {
        unsigned char secs;
        unsigned char mins;
        unsigned char hours;       
        signed char AMPM;
    } rtcTime;
    
    typedef struct rtcDate {
        unsigned char date;
        unsigned char month;
        unsigned char year;
        unsigned char day;        
    } rtcDate;

    void setDate(rtcDate date);
    void setTime(rtcTime time);
    void set24HourMode(unsigned char mode);
    void getDate(rtcDate* date);
    void getTime(rtcTime* time);
    void getTime24(rtcTime* time);
    void convertHourFormat(rtcTime* time);
    
    void clearWP(void);
    
    #ifdef	__cplusplus
}
#endif
#endif	/* RTCI_H */