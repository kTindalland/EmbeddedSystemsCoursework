#ifndef STRINGUTILS_H
#define	STRINGUTILS_H

#ifdef	__cplusplus
extern "C" {
#endif

unsigned char StringLength(char s[]);
unsigned char StringCopy(char from[], char to[], unsigned char length);
unsigned char Concatenate(char sA[], char sB[], char result[], unsigned char rLength);
unsigned char ConvertTime12ToString(char* result, unsigned char secs, unsigned char mins, unsigned char hours, unsigned char pm, unsigned char length);
unsigned char ConvertTime24ToString(char* result, unsigned char secs, unsigned char mins, unsigned char hours, unsigned char length);
unsigned char ConvertDateToString(char* result, unsigned char date, unsigned char month, short year, unsigned char length);
unsigned char ConvertDayToString(char* result, unsigned char day, unsigned char length);

#ifdef	__cplusplus
}
#endif

#endif	/* STRINGUTILS_H */

