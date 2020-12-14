#include "Mode.h"

extern int currentMode;
extern int coldTime;
extern struct Mode modes[];
extern int coldTimerTime;

void ModeSetColdTimerMode()
{
    currentMode = HOME;
}

void ModeSetColdTimerSet()
{
    if(coldTimerTime > -1 &&
       coldTimerTime < 61)
    {
        coldTime = coldTimerTime;
        currentMode = HOME;
    }
    else
    {
        currentMode = ERRORS;
        modes[ERRORS].firstLine = "Cold Timer: Incorrect Value";
    }
}

void ModeSetColdTimerInc()
{
    if (coldTimerTime < 60)
    {
        coldTimerTime = coldTimerTime + 1;   
    }
}

void ModeSetColdTimerDec()
{
    if (coldTimerTime > 0)
    {
        coldTimerTime = coldTimerTime - 1;   
    }
}

void ModeSetColdTimerCancel()
{
    coldTimerTime = coldTime;
}