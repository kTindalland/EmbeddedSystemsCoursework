#include "RealTimeClockConversions.h"

uch convertSecs(uch sec) {
	if (sec >= 60) return RTC_ERROR;
    
    uch result = 0;
    
    if (readCH()) result |= 0x80;
    
    uch ones = sec % 10;
    uch tens = (sec - ones) / 10;
    
    result |= ones;
    result |= (tens << 4);
    
    return result;
}

uch convertMins(uch mins) {
	if (mins >= 60) return RTC_ERROR;
    
    uch result = 0;
    
    uch ones = mins % 10;
    uch tens = (mins - ones) / 10;
    
    result |= ones;
    result |= (tens << 4);
    
    return result;
}

uch convertHours(uch hours, signed char AMPM) {
	if (AMPM == NULL && hours >= 24) return RTC_ERROR;
    if (AMPM != NULL && (hours < 1 || hours >= 13)) return RTC_ERROR;
    
    uch ones = hours % 10;
    uch tens = (hours - ones) / 10;
    
    uch result = 0;
    
    if (AMPM != NULL){ // 12Hr Mode
        result |= 0x80;// 12Hr Mode
        if (AMPM) { result |= 0x20; }//PM    
    }
    
    result |= ones;
    result |= (tens << 4);    
    
    return result;
}

uch convertDate(uch date, uch month, uch year) {
	if (month != 2){
        if ((month == 1) || (month == 3) || (month == 5) || (month == 7) || (month == 8) ||(month == 10) ||  (month == 12)){
            if (date < 1 || date >= 31) return RTC_ERROR;
        }
        else if (date < 1 || date >= 30) return RTC_ERROR; // Month
    }
    else{
        uch isLeapYear = GetIsLeapYear(year);
              
        if (isLeapYear && (date < 1 || date >= 29)) return RTC_ERROR; // Leap Year
        else if (date < 1 || date >= 28) return RTC_ERROR;
    }
    
    uch result = 0;
    
    uch ones = date % 10;
    uch tens = (date - ones) / 10;
    
    result |= ones;
    result |= (tens << 4);
    
    return result;
}

uch convertMonth(uch month) {
	if (month < 1 || month >= 13) return RTC_ERROR;
    
    uch result = 0;
    
    uch ones = month % 10;
    uch tens = (month - ones) / 10;
    
    result |= ones;
    result |= (tens << 4);
    
    return result;
}

uch convertDay(uch day) {
	if (day < 1 || day >= 8) return RTC_ERROR;
    
    uch result = 0;
    result |= day;
    
    return result;
}

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wconversion"

uch convertYear(uch year) {
	if (year >= 100) return RTC_ERROR;
    
    uch result = 0;
    
    uch ones = year % 10;
    uch tens = (year - ones) / 10;
    
    result |= ones;
    result |= (tens << 4);
    
    return result;
}

#pragma GCC diagnostic pop

unsigned char convertReadSecs(uch secs) {
	unsigned char result = 0;
    uch ones = secs & 0x0F;
    uch tens = ((secs & 0x70) >> 4 ) * 10;
    
    result += ones;
    result += tens;
    
    return result;
}

unsigned char convertReadMins(uch mins) {
	unsigned char result = 0;
    uch ones = mins & 0x0F;
    uch tens = ((mins & 0x70) >> 4 ) * 10;
    
    result += ones;
    result += tens;
    
    return result;
}

unsigned char convertReadHours(uch hours, signed char* AMPM) {
    unsigned char result = 0;
    
    uch hour12 = hours & 0x80;
    if (hour12) { *AMPM = (hours & 0x20) >> 5; }
    else { *AMPM = NULL; }
    
    uch ones = hours & 0x0f;
    uch tens;
    
    if (hour12) { tens = (hours & 0x10) >> 4; }
    else { tens = (hours & 0x30) >> 4; }
    
    result += ones;
    result += (tens * 10);

	return result;
}

unsigned char convertReadDate(uch date) {
	unsigned char result = 0;
    uch ones = date & 0x0F;
    uch tens = ((date & 0x30) >> 4 ) * 10;
    
    result += ones;
    result += tens;
    
    return result;
}

unsigned char convertReadMonth(uch month) {
	unsigned char result = 0;
    uch ones = month & 0x0F;
    uch tens = ((month & 0x10) >> 4 ) * 10;
    
    result += ones;
    result += tens;
    
    return result;
}

unsigned char convertReadDay(uch day) {
	unsigned char result = 0;
    
    result = day & 0x07;
    
    return result;
}

short convertReadYear(uch year) {
	short result = 0;
    uch ones = year & 0x0F;
    uch tens = ((year & 0xF0) >> 4 ) * 10;
    
    result += ones;
    result += tens;
    
    return result;
}

uch GetIsLeapYear(uch year)
{
    short fullYear = year + 2000;
    
    if (year % 400 == 0)        return 1;
    else if (year % 100 == 0)   return 0;
    else if (year % 4 == 0)     return 1;
    else                        return 0;
}