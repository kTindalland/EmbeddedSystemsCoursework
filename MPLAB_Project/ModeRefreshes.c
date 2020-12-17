#include "Mode.h"
#include "StringUtils.h"
#include "ModeSetColdTimer.h"
#include "ModeSetHotTimer.h"
#include "ModeSetDate.h"
#include "ModeSetTime.h"
#include "ModeSetFakeTemp.h"
#include "ModeSetTrigTemp.h"
#include "NumberConverter.h"
#include "ThermometerInterface.h"
#include "RealTimeClockInterface.h"
#include "StringUtils.h"

extern Mode_t modes[];
extern int currentMode;

void ModeRefreshHome()
{
    char time[12];
    IRTCGetTime12(time, 12); 
    
    char date[11];
    char day[4];
    
    IRTCGetDate(date, 11, day, 4);
    
	char result[22];
    Concatenate(time, date, result, 22);
    
    double temperature = IThermGetTemperature();
    
    char temperature_string[8];
    nbrcnvt_convert_double(temperature, temperature_string);
    
    StringCopy(result, modes[currentMode].firstLine, StringLength(result));
    StringCopy(temperature_string, modes[currentMode].secondLine, StringLength(temperature_string));
}

void ModeRefreshSetDate()
{
    StringCopy("Home", modes[currentMode].firstLine, 4);
    StringCopy("2", modes[currentMode].secondLine, 1);
}

void ModeRefreshSetTime()
{
    StringCopy("Home", modes[currentMode].firstLine, 4);
    StringCopy("3", modes[currentMode].secondLine, 1);
}

void ModeRefreshSetTrigTemp()
{
    StringCopy("Home", modes[currentMode].firstLine, 4);
    StringCopy("4", modes[currentMode].secondLine, 1);
}

void ModeRefreshSetFakeTemp()
{
    StringCopy("Home", modes[currentMode].firstLine, 4);
    StringCopy("5", modes[currentMode].secondLine, 1);
}

void ModeRefreshSetHotTimer()
{
    StringCopy("Home", modes[currentMode].firstLine, 4);
    StringCopy("6", modes[currentMode].secondLine, 1);
}

void ModeRefreshSetColdTimer()
{
    StringCopy("Home", modes[currentMode].firstLine, 4);
    StringCopy("7", modes[currentMode].secondLine, 1);
}

void ModeRefreshErrors()
{
    StringCopy("Home", modes[currentMode].firstLine, 4);
    StringCopy("8", modes[currentMode].secondLine, 1);
}