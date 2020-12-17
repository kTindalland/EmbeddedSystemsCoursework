#include "NumberConverter.h"
#include "StringUtils.h"

int StringLength(char s[]) {
	// Get char array length.
	int count = 0;

	for (int i = 0; s[i] != '\0'; i++) {
		count++;
	}

	return count;
}

int StringCopy(char from[], char to[], int length)
{
	int stringLength = StringLength(from); 

	if (stringLength < length) return 0; // String not big enough to satisfy length.

	int i;
	for (i = 0; i < length; i++) {
		to[i] = from[i];
	}

	to[i+1] = '\0';

	return 1;
}

int Concatenate(char sA[], char sB[], char result[], int rLength)
{
	int sALength = StringLength(sA);
	int sBLength = StringLength(sB);

	if (rLength < (sALength + sBLength + 1)) // Check result has enough space for the strings.
	{
		return 0;
	}
    
	// Storing Contents of A in Result
	StringCopy(sA, result, sALength);

	// Storing Contents of B in Result
	StringCopy(sB, &result[sALength], sBLength);

	return 1;
}

int ConvertTime12ToString(char* result, int secs, int mins, int hours, int pm, int length)
{
    if (secs < 0 || secs > 59 ||
        mins < 0 || mins > 59 ||
        hours < 1 || hours > 12 ||
        (pm != 0 && pm != 1)
        || length < 11 || length > 11)
    {
        return 0;
    }
    
    char s[3];
    nbrcnvt_convert_integer(secs, s);
    if (secs < 10)
    {
        s[1] = s[0];
        s[0] = '0'; 
    }
    s[2] = ' ';
    
    char m[3];
    nbrcnvt_convert_integer(mins, m);
    if (mins < 10)
    {
        m[1] = m[0];
        m[0] = '0'; 
    }
    m[2] = ':';
    
    char h[3];
    nbrcnvt_convert_integer(hours, h);
    if (hours < 10)
    { 
        h[1] = h[0];
        h[0] = '0'; 
    }
    h[2] = ':';
    
    for (int i = 0; i < 3; i++)
    {
        result[i] = h[i];
    }
    for (int i = 0; i < 3; i++)
    {
        result[i + 3] = m[i];
    }
    for (int i = 0; i < 3; i++)
    {
        result[i + 6] = s[i];
    }
    
    result[9] = 'A';
    if (pm = 1) { result[9] = 'P'; }
    
    result[10] = 'M';
    result[11] = '\0';
   
    return 1;
}

int ConvertTime24ToString(char* result, int secs, int mins, int hours, int length)
{
    if (secs < 0 || secs > 59 ||
        mins < 0 || mins > 59 ||
        hours < 1 || hours > 12 ||
        || length < 8 || length > 8)
    {
        return 0;
    }
    
    char s[3];
    nbrcnvt_convert_integer(secs, s);
    if (secs < 10)
    {
        s[1] = s[0];
        s[0] = '0'; 
    }
    s[2] = '\0';
    
    char m[3];
    nbrcnvt_convert_integer(mins, m);
    if (mins < 10)
    {
        m[1] = m[0];
        m[0] = '0'; 
    }
    m[2] = ':';
    
    char h[3];
    nbrcnvt_convert_integer(hours, h);
    if (hours < 10)
    { 
        h[1] = h[0];
        h[0] = '0'; 
    }
    h[2] = ':';
    
    for (int i = 0; i < 3; i++)
    {
        result[i] = h[i];
    }
    for (int i = 0; i < 3; i++)
    {
        result[i + 3] = m[i];
    }
    for (int i = 0; i < 3; i++)
    {
        result[i + 6] = s[i];
    }
    
    return 1;
}

void ConvertDateToString(char* result, int date, int month, int year)
{
    char d[3];
    nbrcnvt_convert_integer(date, d);
    if (date < 10)
    {
        d[1] = d[0];
        d[0] = '0'; 
    }
    d[2] = '/';
    
    char m[3];
    nbrcnvt_convert_integer(month, m);
    if (month < 10)
    {
        m[1] = m[0];
        m[0] = '0'; 
    }
    m[2] = '/';
    
    char y[5];
    nbrcnvt_convert_integer(year, y);
    if (year < 10) // Future Proofing
    { 
        y[3] = y[0];
        y[2] = '0';
        y[1] = '0';
        y[0] = '0';
    }
    else if (year < 100) // Future Proofing
    {
        y[2] = y[0];
        y[3] = y[1];
        y[0] = '0';
        y[1] = '0';
    }
    else if (year < 1000) // Future Proofing
    {
        y[3] = y[2];
        y[2] = y[1];
        y[1] = y[0];
        y[0] = '0';
    }
    y[4] = '\0';
    
    for (int i = 0; i < 3; i++)
    {
        result[i] = d[i];
    }
    for (int i = 0; i < 3; i++)
    {
        result[i + 3] = m[i];
    }
    for (int i = 0; i < 5; i++)
    {
        result[i + 6] = y[i];
    }
}

void ConvertDayToString(char* result, int day)
{
    if (day < 1 || day > 7)
    {
        //Error
    }
    
    char* days[] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    
    result[0] = days[day-1][0];
    result[1] = days[day-1][1];
    result[2] = days[day-1][2];
    result[3] = '\0';
}
