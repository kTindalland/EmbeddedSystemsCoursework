#include "Mode.h"

extern int currentMode;
extern int hotTime;
extern struct Mode modes[];
extern int hotTimerTime;

void ModeSetHotTimerMode()
{
    currentMode = HOME;
}

void ModeSetHotTimerSet()
{
    if(hotTimerTime > -1 &&
       hotTimerTime < 61)
    {
        hotTime = hotTimerTime;
        currentMode = HOME;
    }
    else
    {
        currentMode = ERRORS;
        modes[ERRORS].firstLine = "Hot Timer: Incorrect Value";
    }
}

void ModeSetHotTimerInc()
{
    if (hotTimerTime < 60)
    {
        hotTimerTime = hotTimerTime + 1;
    }
}

void ModeSetHotTimerDec()
{
    if (hotTimerTime > 0)
    {
        hotTimerTime = hotTimerTime - 1;   
    }
}

void ModeSetHotTimerCancel()
{
    hotTimerTime = hotTime;
}