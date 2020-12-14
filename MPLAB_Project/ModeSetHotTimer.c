#include "Mode.h"

extern int currentMode;
extern int hotTime;

int hotTimerTime;

void ModeSetHotTimerMode()
{
    currentMode = HOME;
}

void ModeSetHotTimerSet()
{
    if(hotTimerTime > -1 &&
       hotTimerTime < 61)
    {
        coldTime = hotTimerTime;
    }
    else
    {
        currentMode = ERRORS;
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
    if (coldTimerTime > 0)
    {
        coldTimerTime = coldTimerTime - 1;   
    }
}

void ModeSetHotTimerCancel()
{
    currentMode = SETHOTTIMER;
}

void ModeSetHotTimerAux1()
{
   
}

void ModeSetHotTimerAux2()
{
    
}

void ModeSetHotTimerAux3()
{
    
}