/* 
 * File:   globals.h
 * Author: kaiti
 *
 * Created on 19 December 2020, 16:14
 */

#ifndef GLOBALS_H
#define	GLOBALS_H

#include "RealTimeClockDriver.h"

#ifdef	__cplusplus
extern "C" {
#endif

#define HOME 0
#define SETTIME 1
#define TRIGTEMP 2
#define FAKETEMP 3
#define HOTTIME 4
#define COLDTIME 5
    
    extern double home_temperature;
    extern rtcTime set_time_time;
    extern unsigned char set_time_flag;

#ifdef	__cplusplus
}
#endif

#endif	/* GLOBALS_H */

