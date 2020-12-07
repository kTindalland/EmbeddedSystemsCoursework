
#include "HeaterConfigManager.h"


  
void SetTriggerTemp(double temp)
{
    
}

double GetTriggerTemp()
{
    
}

void IncrementMode()
{
    
}

void DecrementMode()
{
    
}

void SetHotTimer(int time)
{
    if (time < 0  || time > 90)
        heater.hotTimer = time;
    else
        heater.error = "Hot timer not between 0 and 90 seconds."
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
        heater.error = "Cold timer not between 0 and 60 seconds."
}

int GetColdTimer()
{
    return heater.coldTimer;
}