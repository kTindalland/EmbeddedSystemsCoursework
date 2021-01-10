#include "RealTimeClockDriver.h"
#include "RealTimeClockConversions.h"
#include "RealTimeClockInterface.h"

// Convert and write all the parts of the date
void setDate(rtcDate date) {
    
    uch dateByte = convertDate(date.date, date.month, date.year);
    writeByte(RTC_DATE, dateByte);
    
    uch monthByte = convertMonth(date.month);
    writeByte(RTC_MONTH, monthByte);
    
    uch yearByte = convertYear(date.year);
    writeByte(RTC_YEAR, yearByte);
    
    uch dayByte = convertDay(date.day);
    writeByte(RTC_DAY, dayByte);
}

// Convert and write all the parts of the time
void setTime(rtcTime time) {
    
    uch secByte = convertSecs(time.secs);
    writeByte(RTC_SEC, secByte);
    
    uch minsByte = convertMins(time.mins);
    writeByte(RTC_MINS, minsByte);
    
    uch hoursByte = convertHours(time.hours, time.AMPM);
    writeByte(RTC_HOURS, hoursByte);  
}

// Read and convert all the parts of a date
void getDate(rtcDate* date) {
    uch dateByte = readByte(RTC_DATE);
    date->date = convertReadDate(dateByte);
    
    uch monthByte = readByte(RTC_MONTH);
    date->month = convertReadMonth(monthByte);
    
    uch yearByte = readByte(RTC_YEAR);
    date->year = convertReadYear(yearByte);
    
    uch dayByte = readByte(RTC_DAY);
    date->day = convertReadDay(dayByte);
}

// Read and convert all the parts of a time
void getTime(rtcTime* time) {
    uch secsByte = readByte(RTC_SEC);
    time->secs = convertReadSecs(secsByte);
    
    uch minsByte = readByte(RTC_MINS);
    time->mins = convertReadMins(minsByte);
    
    uch hoursByte = readByte(RTC_HOURS);
    time->hours = convertReadHours(hoursByte, &time->AMPM);
}

// Gets the time and guarentees it's in 24hr mode
void getTime24(rtcTime* time) {
    
    getTime(time);
    
    if (time->AMPM != NULL) {
        convertHourFormat(time);
    }
}

// Converts from 24hr to 12hr mode and vice versa
void convertHourFormat(rtcTime* time) {
    // If 24 to 12
    if (time->AMPM == NULL) {
        time->AMPM = AM;
        
        if (time->hours > 12) {
            time->hours -= 12;
            time->AMPM = PM;
        }
    }
    else { // If 12 to 24
        if (time->AMPM == PM) {
            time->hours += 12;
        }
        
        if (time->hours >= 24) time->hours = 0;
        
        time->AMPM = NULL;
    }
}