
#ifndef GLOBALS_H
#define	GLOBALS_H

#include "RealTimeClockDriver.h"

#ifdef	__cplusplus
extern "C" {
#endif

// Home temperature vars.
extern signed char home_temperature_whole;
extern signed char home_temperature_decimal;

// Set Time Mode vars.
extern rtcTime set_time_time;
extern unsigned char set_time_flag;

// Set Date Mode vars.
extern rtcDate set_date_date;
extern unsigned char set_date_flag;

// Set Trigger Temperature Mode vars.
extern signed char set_trig_temp_whole;
extern signed char set_trig_temp_decimal;

// Trigger temperature vars.
extern signed char trigger_temperature_whole;
extern signed char trigger_temperature_decimal;

// Hot time vars.
extern unsigned char hot_time_actual;
extern unsigned char hot_time_temp;

// Cold time vars.
extern unsigned char cold_time_actual;
extern unsigned char cold_time_temp;

// The status of the temperature last calculation.
// 0 - Was cold
// 1 - Was hot
extern unsigned char temp_last;

// Time and dates used in determining the timer.
extern rtcDate start_trig_date;
extern rtcTime start_trig_time;
extern rtcTime goal_time;
extern rtcDate goal_date;
extern unsigned char trigger_timer_passed;

// Set value of the hot and cold time.
extern unsigned char cold_timer_actual; // Max 90 secs
extern unsigned char hot_timer_actual; // Max 60 secs

// Fake temperature vars.
extern signed char fake_temperature; // Set values
extern signed char fake_temperature_decimal;
extern signed char fake_temperature_temp; // To-be-set valus.
extern signed char fake_temperature_temp_decimal;
extern unsigned char fake_temp_onoff; // If the fake temperature is being use.

#ifdef	__cplusplus
}
#endif

#endif	/* GLOBALS_H */

