/* 
 * File:   main.h
 * Author: kaiti
 *
 * Created on 18 December 2020, 10:33
 */

#ifndef MAIN_H
#define	MAIN_H

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
void Home(void);
void SetTime(void);
void SetDate(void);
void SetTriggerTemperature(void);
void SetFakeTemperature(void);
void SetHotColdtime(unsigned char*, unsigned char*, unsigned char, char*);
void GetTemperatureProxy(unsigned char*, unsigned char*);
unsigned char GetMaximumDateForMonth(unsigned char, short);
void GetGoalTriggerTime(unsigned char);
unsigned char GetTriggerTimeStatus(void);
void main(void);

#ifdef	__cplusplus
extern "C" {
#endif



#ifdef	__cplusplus
}
#endif

#endif	/* MAIN_H */

