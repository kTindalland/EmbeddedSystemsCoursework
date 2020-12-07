#include "Mode.h"

void InstantiateModes(Mode* modes)
{
    modes[HOME];
    modes[SETDATE];
    modes[SETTIME];
    modes[SETTRIGTEMP];
    modes[SETFAKETEMP];
    modes[SETHOTTIMER];
    modes[SETCOLDTIMER];
    modes[ERRORS];
    
    /*
    modes[SETHOUR];
    modes[SETMINUTES];
    modes[SETSECONDS];
    modes[SETDAY];
    modes[SETMONTH];
    modes[SETYEAR];
     modes[SETAMPM]; - Could be Aux function in hour/min/seconds or settime
     */
}

void ModeDisplay(Mode mode)
{
    ILCDPanelSetCursor(0,0);
    ILCDPanelWrite(mode.firstLine);
    ILCDPanelSetCursor(1,0);
    ILCDPanelWrite(mode.secondLine);
}

void ModeCheckButtons(Mode mode)
{
    char buttonStates[8]; 
    
    IButtonsCheckButtons(buttonStates);
    
    if(buttonStates[0]) { mode.buttons.mode(); }
    if(buttonStates[1]) { mode.buttons.set(); }
    if(buttonStates[2]) { mode.buttons.increment(); }
    if(buttonStates[3]) { mode.buttons.decrement(); }
    if(buttonStates[4]) { mode.buttons.cancel(); }
    if(buttonStates[5]) { mode.buttons.aux1(); }
    if(buttonStates[6]) { mode.buttons.aux2(); }
    if(buttonStates[7]) { mode.buttons.aux3(); }
}