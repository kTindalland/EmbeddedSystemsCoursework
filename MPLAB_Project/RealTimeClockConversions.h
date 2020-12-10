#ifndef REALTIMECLOCKCONVERSIONS_H
#define	REALTIMECLOCKCONVERSIONS_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#define uch unsigned char
#define RTC_ERROR 0xFF
    
uch convertSecs(int sec);
uch convertMins(int mins);
uch convertHours(int hours, int is24Hour);
uch convertDate(int date, int month, int year);
uch convertMonth(int month);
uch convertDay(int day);
uch convertYear(int year);

int convertReadSecs(uch secs);
int convertReadMins(uch mins);
int convertReadHours(uch hours, int* AMPM);
int convertReadDate(uch date);
int convertReadMonth(uch month);
int convertReadDay(uch day);
int convertReadYear(uch year);

#ifdef	__cplusplus
}
#endif

#endif	/* REALTIMECLOCKCONVERSIONS_H */

