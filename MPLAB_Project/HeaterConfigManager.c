#include "HeaterConfigManager.h"

void IncrementMode()
{
    heater.mode++;
}

void DecrementMode()
{
    heater.mode--;
}

void IncrementTemp()
{
    heater.displayTemp++;
}

void DecrementTemp()
{
    heater.displayTemp--;
}
  
void SetTriggerTemp()
{
    double temp;
    temp = heater.displayTemp;
    
    if (temp <  - 50 || temp > 150)
        heater.error = "Trigger Temp Not Between -50 and 150 degrees.";
    else
        heater.triggerTemp = temp;
}

double GetTriggerTemp()
{
    return heater.triggerTemp;
}

void SetHotTimer(int time)
{
    if (time < 0  || time > 90)
        heater.hotTimer = time;
    else
        heater.error = "Hot timer not between 0 and 90 seconds.";
}

int GetHotTimer()
{
    return heater.hotTimer;
}

void SetColdTimer(int time)
{
    if (time < 0  || time > 90)
        heater.hotTimer = time;
    else
        heater.error = "Cold timer not between 0 and 60 seconds.";
}

int GetColdTimer()
{
    return heater.coldTimer;
}