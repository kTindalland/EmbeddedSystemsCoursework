#include "Mode.h"

void InstantiateModes(Mode* modes)
{
    modes[HOME];
    modes[SETDATE];
    modes[SETTIME]; // Aux 1 for AM/PM to 24hr.
    modes[SETTRIGTEMP];
    modes[SETFAKETEMP];
    modes[SETHOTTIMER];
    modes[SETCOLDTIMER];
    modes[ERRORS];

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
    else if(buttonStates[1]) { mode.buttons.set(); }
    else if(buttonStates[2]) { mode.buttons.increment(); }
    else if(buttonStates[3]) { mode.buttons.decrement(); }
    else if(buttonStates[4]) { mode.buttons.cancel(); }
    else if(buttonStates[5]) { mode.buttons.aux1(); }
    else if(buttonStates[6]) { mode.buttons.aux2(); }
    else if(buttonStates[7]) { mode.buttons.aux3(); }
}