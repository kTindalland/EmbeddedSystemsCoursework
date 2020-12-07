#include <xc.h>
#include "LCDPanelInterface.h"
#include "HeaterConfigManager.h"


#pragma config FOSC = HS
#pragma config WDTE = OFF
#pragma config PWRTE = ON
#pragma config BOREN = OFF
#pragma config LVP = OFF



struct Buttons{
    void (*mode)(void);
    void (*set)(void);
    void (*increment)(void);
    void (*decrement)(void);
    void (*cancel)(void);
    void (*aux1)(void);
    void (*aux2)(void);
    void (*aux3)(void);
};

void main(void) {
    char[] action;
    int lastTemp = -1; // 0 for under trigger, 1 for over trigger
    double trigger = 25.0; // Move to temperature
    double temperature = 0;
    int startTime; // Change to appropriate type
    int currentTime; // Change to appropriate type
    int timerGone = 0; // Has timer buzzed
    
    while(1)
    {
        DisplayMode(heater.mode); // Add to LCDPanelInterface
        CheckButtonsPressed(); // Add to ButtonInterface
        temperature = GetCurrentTemperature(); // Add to TemperatureInterface
        
        if (lastTemp == 1 && temperature < trigger) // Temp Hot to Cold
        {
            lastTemp = 0;
            startTime = GetCurrentTime();
        }
        else if (lastTemp == 0 && temperature > trigger) // Temp Cold to Hot
        {
            lastTemp = 1;
            startTime = GetCurrentTime();
        }
        else if (lastTemp == 0) // Temp Cold
        {
            currentTime = GetCurrentTime();
            if (startTime >= currentTime && timerGone == 0)
            {
                timerGone = 1;
                ProduceSound(TIMERFORCOLD)
            }
        }
        else if (lastTemp == 1) // Temp Hot
        {
            currentTime = GetCurrentTime();
            if (startTime >= currentTime && timerGone == 0)
            {
                timerGone = 1;
                ProduceSound(TIMERFORHOT)
            }
        } // Refactor this temperature crap
    }
    
    return;
}
