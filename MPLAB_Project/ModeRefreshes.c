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

extern Mode_t modes[];
extern int currentMode;

void ModeRefreshHome()
{
    char time[] = IRTCGetTime(); 
    char date[] = IRTCGetDate();
    
	int sizeA = StringLength(time);
	int sizeB = StringLength(date);
	char result[] = char[sizeA + sizeB + 1];
    Concatenate(time, date, result);
    
    double temperature = IThermGetTemperature();
    
    char temperature_string[8];
    nbrcnvt_convert_double(temperature, temperature_string);
    
    modes[currentMode].firstLine = result;
    modes[currentMode].secondLine = temperature_string;
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