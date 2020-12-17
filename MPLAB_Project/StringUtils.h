#ifndef STRINGUTILS_H
#define	STRINGUTILS_H

#ifdef	__cplusplus
extern "C" {
#endif

int StringLength(char s[]);
int StringCopy(char from[], char to[]);
int Concatenate(char sA[], char sB[], char result[]);
void ConvertTime12ToString(char* result, int secs, int mins, int hours, int pm);
void ConvertTime24ToString(char* result, int secs, int mins, int hours);
void ConvertDateToString(char* result, int date, int month, int year);
void ConvertDayToString(char* result, int day);

#ifdef	__cplusplus
}
#endif

#endif	/* STRINGUTILS_H */

