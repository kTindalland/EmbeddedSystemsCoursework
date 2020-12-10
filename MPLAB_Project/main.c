#include <xc.h>
#include "LCDPanelInterface.h"
#include "HeaterConfigManager.h"
#include "Mode.h"

#pragma config FOSC = HS
#pragma config WDTE = OFF
#pragma config PWRTE = ON
#pragma config BOREN = OFF
#pragma config LVP = OFF

double trigger = 100.0;
int hotTime = 0;
int coldTime = 0;

struct Mode modes[6];
int currentMode;

void main(void) {
    
    InstantiateModes(modes);
    currentMode = HOME;
    
    int lastTemp = 1; // 0 for under trigger, 1 for over trigger
    if(IThermometerGetTemp() < trigger)
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
        mode.refresh();
        ModeDisplay(mode);
        ModeCheckButtons(mode);
        
        temperature = IThermometerGetTemp();
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
