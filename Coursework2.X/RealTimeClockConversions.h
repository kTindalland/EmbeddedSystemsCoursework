#ifndef REALTIMECLOCKCONVERSIONS_H
#define	REALTIMECLOCKCONVERSIONS_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#define uch unsigned char
#define RTC_ERROR 0xFF
#define NULL -1
    
// Below functions convert from C datatypes to a byte the clock can recognise.
uch convertSecs(uch sec);
uch convertMins(uch mins);
uch convertHours(uch hours, signed char is24Hour);
uch convertDate(uch date, uch month, uch year);
uch convertMonth(uch month);
uch convertDay(uch day);
uch convertYear(uch year);

// Below functions convert from clock bytes to C datatypes.
unsigned char convertReadSecs(uch secs);
unsigned char convertReadMins(uch mins);
unsigned char convertReadHours(uch hours, signed char* AMPM);
unsigned char convertReadDate(uch date);
unsigned char convertReadMonth(uch month);
unsigned char convertReadDay(uch day);
short convertReadYear(uch year);

// Read the clock halt bit
uch readCH(void);

uch GetIsLeapYear(uch year);

#ifdef	__cplusplus
}
#endif

#endif	/* REALTIMECLOCKCONVERSIONS_H */

