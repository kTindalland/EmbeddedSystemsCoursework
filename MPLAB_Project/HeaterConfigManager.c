#include "HeaterConfigManager.h"
#include "StringUtils.h"

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
    
    if (temp <  - 50 || temp > 150) {
        char errorMsg[] = "Trigger Temp Not Between -50 and 150 degrees.";
        StringCopy(errorMsg, heater.errorLine1, 16);
        StringCopy(&errorMsg[16], heater.errorLine2, 16);
    }
    else { heater.triggerTemp = temp; }
        
}

double GetTriggerTemp()
{
    return heater.triggerTemp;
}

void SetHotTimer(int time)
{
    if (time < 0  || time > 90)
        heater.hotTimer = time;
    else {
        char errorMsg[] = "Hot timer not between 0 and 90 seconds.";
        StringCopy(errorMsg, heater.errorLine1, 16);
        StringCopy(&errorMsg[16], heater.errorLine2, 16);
    }
}

int GetHotTimer()
{
    return heater.hotTimer;
}

void SetColdTimer(int time)
{
    if (time < 0  || time > 90)
        heater.hotTimer = time;
    else {
        char errorMsg[] = "Cold timer not between 0 and 60 seconds.";
        StringCopy(errorMsg, heater.errorLine1, 16);
        StringCopy(&errorMsg[16], heater.errorLine2, 16);
    }
}

int GetColdTimer()
{
    return heater.coldTimer;
}