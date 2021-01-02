/* 
 * File:   main.h
 * Author: kaiti
 *
 * Created on 18 December 2020, 10:33
 */



#ifndef MAIN_H
#define	MAIN_H

#include "RealTimeClockDriver.h" 

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

unsigned char GetMaximumDateForMonth(unsigned char, short);
void GetGoalTriggerTime(unsigned char);
unsigned char GetTriggerTimeStatus(void);

#ifdef	__cplusplus
}
#endif

#endif	/* MAIN_H */

