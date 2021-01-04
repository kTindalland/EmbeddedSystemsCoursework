#ifndef REALTIMECLOCKCONVERSIONS_H
#define	REALTIMECLOCKCONVERSIONS_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#define uch unsigned char
#define RTC_ERROR 0xFF
#define NULL -1
    
// Below functions convert from C datatypes to a byte the clock can recognise.
uch convertSecs(unsigned char sec);
uch convertMins(unsigned char mins);
uch convertHours(unsigned char hours, signed char is24Hour);
uch convertDate(unsigned char date, unsigned char month, short year);
uch convertMonth(unsigned char month);
uch convertDay(unsigned char day);
uch convertYear(short year);

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

#ifdef	__cplusplus
}
#endif

#endif	/* REALTIMECLOCKCONVERSIONS_H */

