#include "Mode.h"

extern int currentMode;

void ModeHomeMode()
{
    currentMode = SETDATE;
}

void ModeHomeSet()
{
    currentMode = SETTIME;
}

void ModeHomeInc()
{
    currentMode = SETTRIGTEMP;
}

void ModeHomeDec()
{
    currentMode = SETFAKETEMP;
}

void ModeHomeCancel()
{
    currentMode = SETHOTTIMER;
}

void ModeHomeAux1()
{
    currentMode = SETCOLDTIMER;
}

void ModeHomeAux2()
{
    currentMode = ERRORS;
}
