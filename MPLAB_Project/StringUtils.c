#include "NumberConverter.h"
#include "StringUtils.h"

int StringLength(char s[]) {
   int c = 0;
   while (s[c] != '\0') // While Current Character Is Not Null Terminator
      c++;
   
   return c;
}

int StringCopy(char from[], char to[])
{
    int lengthFrom = StringLength(from);
    int lengthTo = StringLength(to);
    
    if (lengthFrom == 0)
    {
        return 0;
    }
    if (lengthTo < lengthFrom)
    {
        return 0;
    }
    
    int i;
    
    for (i = 0; from[i] != '\0'; ++i)
    {
        to[i] = from[i];
    }
    
    to[i] = '\0';
    
    return 1;
}

int Concatenate(char sA[], char sB[], char result[])
{
    int rLength = StringLength(result);
    int sALength = StringLength(sA);
    int sBLength = StringLength(sB);
    
    if (rLength < (sALength + sBLength + 1))
    {
        return 0;
    }
    
    // Storing Contents of A in Result
	for (int i = 0; i < sALength; i++)
	{
		result[i] = sA[i];
	}

    // Storing Contents of B in Result
	for (int i = 0; i < sBLength; i++)
	{
		result[i + sALength] = sB[i];
	}

    // Add Terminating Character
	result[sALength + sBLength] = '\0';
    
    return 1;
}

void ConvertTime12ToString(char* result, int secs, int mins, int hours, int pm)
{
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
    
    result[10] = 'A';
    if (pm = 1) { result[10] = 'P'; }
    
    result[11] = 'M';
    result[12] = '\0';
}

void ConvertTime24ToString(char* result, int secs, int mins, int hours)
{
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
