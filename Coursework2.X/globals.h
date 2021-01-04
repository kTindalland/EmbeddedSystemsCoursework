/* 
 * File:   globals.h
 * Author: kaiti
 *
 * Created on 19 December 2020, 16:14
 */

#ifndef GLOBALS_H
#define	GLOBALS_H

#include "RealTimeClockInterface.h"

#ifdef	__cplusplus
extern "C" {
#endif

extern signed char home_temperature_whole;
extern signed char home_temperature_decimal;

extern rtcTime set_time_time;
extern unsigned char set_time_flag;

extern rtcDate set_date_date;
extern unsigned char set_date_flag;

extern signed char set_trig_temp_whole;
extern signed char set_trig_temp_decimal;
extern signed char trigger_temperature_whole;
extern signed char trigger_temperature_decimal;

extern unsigned char hot_time_actual;
extern unsigned char hot_time_temp;

extern unsigned char cold_time_actual;
extern unsigned char cold_time_temp;

extern unsigned char temp_last;

extern rtcDate start_trig_date;
extern rtcTime start_trig_time;
extern rtcTime goal_time;
extern rtcDate goal_date;
extern unsigned char trigger_timer_passed;


extern unsigned char cold_timer_actual;
extern unsigned char hot_timer_actual;

extern signed char fake_temperature;
extern signed char fake_temperature_decimal;
extern signed char fake_temperature_temp;
extern signed char fake_temperature_temp_decimal;
extern unsigned char fake_temp_onoff;

#ifdef	__cplusplus
}
#endif

#endif	/* GLOBALS_H */

