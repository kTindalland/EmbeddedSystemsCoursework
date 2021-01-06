#ifndef MAIN_H
#define	MAIN_H

#include "RealTimeClockInterface.h"

#ifdef	__cplusplus
extern "C" {
#endif

    // Mode macros.
#define HOME 0
#define SETTIME 1
#define SETDATE 2
#define TRIGTEMP 3
#define FAKETEMP 4
#define HOTTIME 5
#define COLDTIME 6

void PrintTimeNumber(unsigned char, char*); // Individual numbers for date or time
void PrintTimeToLCD(rtcTime); // Print the time to the screen formatted.
void PrintDateToLCD(rtcDate); // Print the date to the screen formatted.
void PrintDayToLCD(unsigned char day); // Print the day to the screen formatted.
void Home(void); // The home mode function.
void SetTime(void); // The set time mode function.
void SetDate(void); // The set date mode function.
void SetTriggerTemperature(void); // The set trigger temperature function.
void SetFakeTemperature(void); // The set fake temperature function.

// Weird function won't work :(
//void SmartHeaterSetHotColdtime(unsigned char*, unsigned char*, unsigned char, char*);

void GetTemperatureProxy(signed char*, signed char*); // Returns the current temperature. Knows if to return real or fake.

unsigned char GetMaximumDateForMonth(unsigned char, unsigned char); // Gets the maximum valid date for the given month and year.
void GetGoalTriggerTime(unsigned char); // Reset the goal trigger time.
unsigned char GetTriggerTimeStatus(void); // Gets the current status of the trigger time.

#ifdef	__cplusplus
}
#endif

#endif	/* MAIN_H */

