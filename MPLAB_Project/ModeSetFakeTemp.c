#include "Mode.h"

extern int currentMode;

int temp = IThermometerGetTemp();

void ModeSetFakeTempMode()
{
    currentMode = HOME;
}

void ModeSetFakeTempSet()
{
    IThermometerSetTemp(temp);
}

void ModeSetFakeTempInc()
{
    temp = temp + 1;
}

void ModeSetFakeTempDec()
{
    temp = temp - 1;
}

void ModeSetFakeTempCancel()
{
    currentMode = SETFAKETEMP;
}

void ModeSetFakeTempAux1()
{
   
}

void ModeSetFakeTempAux2()
{
    
}

void ModeSetFakeTempAux3()
{
    
}
