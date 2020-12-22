#include "RealTimeClockDriver.h"

int IRTCGetTime12(char result[], int length) // Have 12 in result
{
    
    if (length < 12) // 12 Is Minimum Chars To Store Formatted 12H Time
    {
        return IRTC_ERROR;
    }
    else
    {
        rtcTime getTime;
        getTime12(&getTime);
    
        ConvertTime12ToString(result, getTime.secs, getTime.mins, getTime.hours, getTime.AMPM);
        return IRTC_SUCCESS;
    }
}

int IRTCGetTime24(char result[], int length)
{
    
    if (length < 9) // 9 Is Minimum Chars To Store Formatted 24H Time
    {
        return IRTC_ERROR;
    }
    else
    {
        rtcTime getTime;
        getTime24(&getTime);
    
        ConvertTime24ToString(result, getTime.secs, getTime.mins, getTime.hours);
        return IRTC_SUCCESS;
    }
}

void IRTCGetDate(char date[], int lengthDate, char day[], int lengthDay)
{
    if (lengthDate >= 11 && lengthDay >= 4)
    {
        rtcDate date_var;
        getDate(&date_var);
    
        ConvertDateToString(date, date_var.date, date_var.month, date_var.year);
        ConvertDayToString(day, date_var.day);
    }
}

int IRTCSetTime24(int hour, int minutes, int seconds)
{
    if (hour > -1 && hour < 24 &&
    minutes > 0 && minutes < 61 &&
    seconds > 0 && seconds < 61)
    {
        rtcTime time;
        time.secs = seconds;
        time.mins = minutes;
        time.hours = hour;
        time.AMPM = NULL;
        
        setTime(time);
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
        rtcTime time;
        time.secs = seconds;
        time.mins = minutes;
        time.hours = hour;
        time.AMPM = pm;
        
        setTime(time);
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
        dayLimit = 31;
    }
    
    if (month == 2 && isLeapYear == 1)
    {
        dayLimit = 29;
    }
    else if (month == 2 && isLeapYear == 0)
    {
        dayLimit = 28;
    }
    
    if (date > 0 && date < dayLimit &&
        month > 0 && month < 13 &&
        year > 0 && year < 2099) // Check Year
    {
        rtcDate date_var;
        date_var.date = date;
        date_var.month = month;
        date_var.year = year;
        
        setDate(date_var);
    }
    else
    {
        // Errors
    }
}