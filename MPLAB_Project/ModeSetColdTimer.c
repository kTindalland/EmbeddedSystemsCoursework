#include "Mode.h"

extern int currentMode;
extern int coldTime;

int coldTimerTime;

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
    }
    else
    {
        currentMode = ERRORS;
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
    currentMode = SETHOTTIMER;
}

void ModeSetColdTimerAux1()
{
   
}

void ModeSetColdTimerAux2()
{
    
}

void ModeSetColdTimerAux3()
{
    
}