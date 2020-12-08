#include "LCDPanelDriver.h"    

void ILCDPanelSetCursor(char down, char along)
{
    LcdInit();
    SetCursorPos(down, along);
}

void ILCDPanelWrite(char s[])
{
    ClearCmd();
    LcdInit();
    WriteString(s);
}