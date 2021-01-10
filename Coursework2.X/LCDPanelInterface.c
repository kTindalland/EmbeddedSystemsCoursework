#include "LCDPanelDriver.h"    

// Set the cursor
void ILCDPanelSetCursor(char down, char along)
{
    LcdInit();
    SetCursorPos(down, along);
}

// Clear the LCD panel
void ILCDPanelClear(void)
{
    LcdInit();
    ClearCmd();
}

// Write a string to the LCD panel
void ILCDPanelWrite(char s[])
{
    LcdInit();
    WriteString(s);
}