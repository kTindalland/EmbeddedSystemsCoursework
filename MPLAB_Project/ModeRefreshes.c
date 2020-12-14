#include "Mode.h"
#includ "StringUtils.h"

extern struct Mode modes;
extern int currentMode;

void ModeRefreshHome()
{
    char time[] = IRTCGetTime(); 
    char date[] = IRTCGetDate();
    
	int sizeA = StringLength(time);
	int sizeB = StringLength(date);
	char result[] = char[sizeA + sizeB + 1];
    Concatenate(time, date, result);
    
    char temp[] = IThermometerGetTemp();
    
    modes[currentMode].firstLine = result;
    modes[currentMode].secondLine = temp;
}

void ModeRefreshSetDate()
{
    modes[currentMode].firstLine = "Home";
    modes[currentMode].secondLine = "2";
}

void ModeRefreshSetTime()
{
    modes[currentMode].firstLine = "Home";
    modes[currentMode].secondLine = "3";
}

void ModeRefreshSetTrigTemp()
{
    modes[currentMode].firstLine = "Home";
    modes[currentMode].secondLine = "4";
}

void ModeRefreshSetFakeTemp()
{
    modes[currentMode].firstLine = "Home";
    modes[currentMode].secondLine = "5";
}

void ModeRefreshSetHotTimer()
{
    modes[currentMode].firstLine = "Home";
    modes[currentMode].secondLine = "6";
}

void ModeRefreshSetColdTimer()
{
    modes[currentMode].firstLine = "Home";
    modes[currentMode].secondLine = "7";
}

void ModeRefreshErrors()
{
    modes[currentMode].firstLine = "Home";
    modes[currentMode].secondLine = "8";
}