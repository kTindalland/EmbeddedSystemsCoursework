#ifndef MAIN_H
#define	MAIN_H

#include "RealTimeClockInterface.h"

#ifdef	__cplusplus
extern "C" {
#endif

#define HOME 0
#define SETTIME 1
#define SETDATE 2
#define TRIGTEMP 3
#define FAKETEMP 4
#define HOTTIME 5
#define COLDTIME 6

void PrintTimeNumber(unsigned char, char*);
void PrintTimeToLCD(rtcTime);
void PrintDateToLCD(rtcDate);
void PrintDayToLCD(unsigned char day);
void Home(void);
void SetTime(void);
void SetDate(void);
void SetTriggerTemperature(void);
void SetFakeTemperature(void);

// Weird function won't work :(
//void SmartHeaterSetHotColdtime(unsigned char*, unsigned char*, unsigned char, char*);
void GetTemperatureProxy(signed char*, signed char*);

unsigned char GetMaximumDateForMonth(unsigned char, unsigned char);
void GetGoalTriggerTime(unsigned char);
unsigned char GetTriggerTimeStatus(void);

#ifdef	__cplusplus
}
#endif

#endif	/* MAIN_H */

