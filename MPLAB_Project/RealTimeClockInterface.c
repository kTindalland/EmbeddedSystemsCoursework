#include "RealTimeClockDriver.h"

double IRTCGetTime12()
{
    rtcTime getTime;
    getTime24(getTime*);
    
    char secs[];
    nbrcnvt_convert_integer(getTime.secs, secs);
    
    char mins[];
    nbrcnvt_convert_integer(getTime.mins, mins);
    
    char hours[];
    nbrcnvt_convert_integer(getTime.hours, hours);
    
    char result[] = MakeTimeString(result, secs, mins, hours, pm);
    result[] = AddToString(result, mins);
    result[] = AddToString(result, hours);
    
    if (getTime.AMPM == AM){ result[] = AddToString(result, hours);}
    
    
    int seconds = getTime.secs;
    int minutes = getTime.mins;
    int hours = getTime.hours;
    int pm = getTime.AMPM;
    
    nbrcnvt_convert_integer(seconds,)
}

void IRTCGetTime24()
{
    rtcTime getTime;
    getTime24(getTime*);
    int seconds = getTime.secs;
    int minutes = getTime.mins;
    int hours = getTime.hours;
    int pm = NULL;
}

double IRTCGetDate()
{
    rtcDate getDate;
    getDate(getDate*);
    int date = getDate.date;
    int month = getDate.month;
    int year = getDate.year;
    int day = getDate.day;
}

int IRTCSetTime24(int hour, int minutes, int seconds)
{
    if (hour > -1 && hour < 24 &&
    minutes > 0 && minutes < 61 &&
    seconds > 0 && seconds < 61)
    {
        rtcTime setTime;
        setTime.secs = seconds;
        setTime.mins = minutes;
        setTime.hours = hour;
        setTime.AMPM = NULL;
        
        setTime(setTime);
        return IRTC_SUCCESS;
    }
    else
    {
        return IRTC_ERROR; // IRTC_ERROR_UNDERZERO etc
    }
}

void IRTCSetTime12(int hour, int minutes, int seconds, int pm)
{
    if (hour > 0 && hour < 13 &&
        minutes > 0 && minutes < 61 &&
        seconds > 0 && seconds < 61
        && (pm == 0 || pm == 1))
    {
        rtcTime setTime;
        setTime.secs = seconds;
        setTime.mins = minutes;
        setTime.hours = hour;
        setTime.AMPM = pm;
        
        setTime(setTime);
    }
    else
    {
        // Error?
    }
}

void IRTCSetDate(int date, int month, int year)
{
    int dayLimit = 30;
    int isLeapYear = 0;
    
    if (year % 4 == 0)
    {
        if (year % 100 == 0)
        {
            if (year % 400 == 0)
            {
               isLeapYear = 1;
            }
        }
        else
        {
            isLeapYear = 1;
        }
    }
    
    if (month == 1 || month == 3 || month == 5 || 
       month == 7 || month == 8 || month == 10 || month == 12)
    {
        dayLimit == 31;
    }
    
    if (month == 2 && isLeapYear = 1)
    {
        dayLimit == 29;
    }
    else if (month == 2 && isLeapYear == 0)
    {
        dayLimit == 28;
    }
    
    if (date > 0 && date < dayLimit &&
        month > 0 && month < 13 &&
        year > 0 && year < 2099) // Check Year
    {
        rtcDate setDate;
        setDate.date = date;
        setDate.month = month;
        setDate.year = year;
        
        setDate(setDate);
    }
    else
    {
        // Errors
    }
}