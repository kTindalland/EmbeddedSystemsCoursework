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
    temp = IThermometerGetTemp();
}

void ModeSetFakeTempAux2()
{
    temp = temp + 0.1;
}

void ModeSetFakeTempAux3()
{
    temp = temp - 0.1;
}
