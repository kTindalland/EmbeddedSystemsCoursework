#include "RealTimeClockDriver.h"
#include <xc.h>

uch convertSecs(int sec) {
	if (sec < 0 || sec >= 60) return RTC_ERROR;
    
    uch result = 0;
    
    if (readCH()) result |= 0x80;
    
    uch ones = sec % 10;
    uch tens = (sec - ones) / 10;
    
    result |= ones;
    result |= (tens << 4);
    
    return result;
}

uch convertMins(int mins) {
	if (mins < 0 || mins >= 60) return RTC_ERROR;
    
    uch result = 0;
    
    uch ones = mins % 10;
    uch tens = (mins - ones) / 10;
    
    result |= ones;
    result |= (tens << 4);
    
    return result;
}

uch convertHours(int hours, int AMPM) {
	if (AMPM == NULL && (hours < 0 || hours >= 24)) return RTC_ERROR;
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

uch convertDate(int date, int month, int year) {
	if (month != 2){
        if ((month == 1) || (month == 3) || (month == 5) || (month == 7) || (month == 8) ||(month == 10) ||  (month == 12)){
            if (date < 1 || date >= 31) return RTC_ERROR;
        }
        else if (date < 1 || date >= 30) return RTC_ERROR; // Month
    }
    else{
        int isLeapYear = 0;
        if (year % 400 == 0)        isLeapYear = 1;
        else if (year % 100 == 0)   isLeapYear = 0;
        else if (year % 4 == 0)     isLeapYear = 1;
        else                        isLeapYear = 0;
        
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

uch convertMonth(int month) {
	if (month < 1 || month >= 13) return RTC_ERROR;
    
    uch result = 0;
    
    uch ones = month % 10;
    uch tens = (month - ones) / 10;
    
    result |= ones;
    result |= (tens << 4);
    
    return result;
}

uch convertDay(int day) {
	if (day < 1 || day >= 8) return RTC_ERROR;
    
    uch result = 0;
    result |= day;
    
    return result;
}

uch convertYear(int year) {
	if (year < 0 || year >= 100) return RTC_ERROR;
    
    uch result = 0;
    
    uch ones = year % 10;
    uch tens = (year - ones) / 10;
    
    result |= ones;
    result |= (tens << 4);
    
    return result;
}





int convertReadSecs(uch secs) {
	int result = 0;
    uch ones = secs & 0x0F;
    uch tens = ((secs & 0x70) >> 4 ) * 10;
    
    result += ones;
    result += tens;
    
    return result;
}

int convertReadMins(uch mins) {
	int result = 0;
    uch ones = mins & 0x0F;
    uch tens = ((mins & 0x70) >> 4 ) * 10;
    
    result += ones;
    result += tens;
    
    return result;
}

int convertReadHours(uch hours, int* AMPM) {
    int result = 0;
    
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

int convertReadDate(uch date) {
	int result = 0;
    uch ones = date & 0x0F;
    uch tens = ((date & 0x30) >> 4 ) * 10;
    
    result += ones;
    result += tens;
    
    return result;
}

int convertReadMonth(uch month) {
	int result = 0;
    uch ones = month & 0x0F;
    uch tens = ((month & 0x10) >> 4 ) * 10;
    
    result += ones;
    result += tens;
    
    return result;
}

int convertReadDay(uch day) {
	int result = 0;
    
    result = day & 0x07;
    
    return result;
}

int convertReadYear(uch year) {
	int result = 0;
    uch ones = year & 0x0F;
    uch tens = ((year & 0xF0) >> 4 ) * 10;
    
    result += ones;
    result += tens;
    
    return result;
}

void rtcInit(){
    TRISB = 0x00;
    PORTB = 0xFF;
}

void clearWP() {
    
    writeByte(RTC_CTRL, 0x00);
    
}

uch readCH() {
    uch secsByte = readByte(RTC_SEC);
    
    return (secsByte & 0x80) >> 7;
}

void startClock() {
    uch currentSeconds = readByte(RTC_SEC);
    
    uch newSeconds = currentSeconds & 0x7F;
    
    writeByte(RTC_SEC, newSeconds);
}

void stopClock() {
    uch currentSeconds = readByte(RTC_SEC);
    
    uch newSeconds = currentSeconds | 0x80;
    
    writeByte(RTC_SEC, newSeconds);
}

uch readByte(uch addr) {
    rtcInit();
    
    uch readAddr = addr | RTC_READ;
    uch result = 0;
    
    SCLK = 0;
    RST = 0;
    
    // Start transaction 
    RST = 1;
    uch value;
    // Send addr
    TRISB = TRISB & 0xEF; // Set TRISB4 to output
    for (int i = 0; i < 8; i++) {
        value = (readAddr & 0x80) >> 7;
        RTC_IO = value;
               
        SCLK = 1;
        
        SCLK = 0;
        
        readAddr <<= 1;
    }
    
    TRISB = TRISB | 0x10; // Set TRISB4 to input
    // Read result 
    for (int i = 0; i < 8; i++) {
        // Read
        value = RTC_IO;
        
        result >>= 1;
        
        if (value) result |= 0x80;
        
        // Put up
        SCLK = 1;
        
        // Put down
        SCLK = 0;
    }
    
    RST = 0;
    
    // Flip the result
    result = reverseBits(result);
    
    
    return result;    
}

void writeByte(uch addr, uch data) {
    rtcInit();
    
    uch writeAddr = addr | RTC_WRITE;
    
    SCLK = 0;
    RST = 0;
    
    RST = 1;
    uch value;
    // Send addr
    TRISB = TRISB & 0xEF; // Set TRISB4 to output
    for (int i = 0; i < 8; i++) {
        value = (writeAddr & 0x80) >> 7;
        
        RTC_IO = value;
        
        SCLK = 1;
        
        SCLK = 0;
        
        writeAddr <<= 1;
    }
    
    // Send data
    for (int i = 0; i < 8; i++) {
        value = (data & 0x80) >> 7;
        
        RTC_IO = value;
        
        SCLK = 1;
        
        SCLK = 0;
        
        data <<= 1;
    }
    
    RST = 0;
}

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

void setTime(rtcTime time) {
    
    uch secByte = convertSecs(time.secs);
    writeByte(RTC_SEC, secByte);
    
    uch minsByte = convertMins(time.mins);
    writeByte(RTC_MINS, minsByte);
    
    uch hoursByte = convertHours(time.hours, time.AMPM);
    writeByte(RTC_SEC, hoursByte);
    
}

void setDateTime(rtcDateTime datetime) {
    setDate(datetime.date);
    setTime(datetime.time);
}

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

void getTime(rtcTime* time) {
    uch secsByte = readByte(RTC_SEC);
    time->secs = convertReadSecs(secsByte);
    
    uch minsByte = readByte(RTC_MINS);
    time->mins = convertReadMins(minsByte);
    
    uch hoursByte = readByte(RTC_HOURS);
    time->hours = convertReadHours(hoursByte, &time->AMPM);
}

void getTime24(rtcTime* time) {
    
    getTime(time);
    
    if (time->AMPM != NULL) {
        convertHourFormat(time);
    }
    
}

void getTime12(rtcTime* time) {
    
    getTime(time);
    
    if (time->AMPM == NULL) {
        convertHourFormat(time);
    }
    
}

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
    }
}

void getDateTime(rtcDateTime* datetime) {
    getTime(&datetime->time);
    getDate(&datetime->date);
}

uch reverseBits(uch number) {
    uch reversedNumber = 0;
    
    while (number > 0) {
        reversedNumber <<= 1;
        if (number & 1 == 1) {
            reversedNumber ^= 1;
        } 
        number >>= 1;
    }
    
    return reversedNumber;
}