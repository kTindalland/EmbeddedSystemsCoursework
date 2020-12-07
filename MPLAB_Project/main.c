#include <xc.h>
#include "LCDPanelInterface.h"
#include "HeaterConfigManager.h"
#include "Mode.h"

#pragma config FOSC = HS
#pragma config WDTE = OFF
#pragma config PWRTE = ON
#pragma config BOREN = OFF
#pragma config LVP = OFF


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
}

double trigger = 100.0;
int hotTime = 0;
int coldTime = 0;

void ModeDisplay(Mode mode)
{
    ILCDPanelSetCursor(0,0);
    ILCDPanelWrite(mode.firstLine);
    ILCDPanelSetCursor(1,0);
    ILCDPanelWrite(mode.secondLine);
}

void CheckButtons(Mode mode)
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

void main(void) {
    
    struct Mode modes[6];
    InstantiateModes(modes);
    int currentMode = HOME;
    
    int lastTemp = 1; // 0 for under trigger, 1 for over trigger
    if(ITemperatureGetTemp() < trigger)
    {
        lastTemp = 0;  
    }
    
    double temperature;
    
    int startTime; // Change to appropriate type
    int currentTime; // Change to appropriate type
    int timerGone = 0; // Has timer buzzed
    
    while(1)
    {
        Mode mode = modes[currentMode];
        mode.Refresh();
        Display(mode);
        CheckButtons(mode);
        
        temperature = ITemperatureGetTemp();
        if (lastTemp == 1 && temperature < trigger) // Temp Hot to Cold
        {
            lastTemp = 0;
            startTime = IRTCGetTime();
        }
        else if (lastTemp == 0 && temperature > trigger) // Temp Cold to Hot
        {
            lastTemp = 1;
            startTime = IRTCGetTime();
        }
        else if (lastTemp == 0) // Temp Cold
        {
            currentTime = IRTCGetTime();
            if (startTime + coldTime >= currentTime && timerGone == 0)
            {
                timerGone = 1;
                ISounderBuzz(0);
            }
        }
        else if (lastTemp == 1) // Temp Hot
        {
            currentTime = IRTCGetTime();
            if (startTime + hotTime >= currentTime && timerGone == 0)
            {
                timerGone = 1;
                ISounderBuzz(1);
            }
        }
    }
    
    return;
}
