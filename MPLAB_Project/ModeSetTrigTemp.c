#include "Mode.h"

extern int currentMode;
extern double trigger;

double currentTrigger;

void ModeSetTrigTempMode()
{
    currentMode = HOME;
}

void ModeSetTrigTempSet()
{
    trigger = currentTrigger;
}

void ModeSetTrigTempInc()
{
    currentTrigger = currentTrigger + 0.1;
}

void ModeSetTrigTempDec()
{
   currentTrigger = currentTrigger - 0.1;
}

void ModeSetTrigTempCancel()
{
    currentTrigger = trigger;
    currentMode = SETTRIGTEMP;
}

void ModeSetTrigTempAux1()
{
   
}

void ModeSetTrigTempAux2()
{
    
}

void ModeSetTrigTempAux3()
{
    
