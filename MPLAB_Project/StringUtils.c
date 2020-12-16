#include "NumberConverter.h"

int StringLength(char s[]) {
   int c = 0;
   while (s[c] != '\0') // While Current Character Is Not Null Terminator
      c++;
   
   return c;
}

void Concatenate(char sA[], char sB[], char result[])
{
    int sALength = StringLength(sA);
    int sBLength = StringLength(sB);
    
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
}

char* ConvertTime12ToString(char* result, int secs, int mins, int hours, int pm)
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

char* ConvertTime24ToString(char* result, int secs, int mins, int hours)
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