
#ifndef XC_HEADER_TEMPLATE_H
#define	XC_HEADER_TEMPLATE_H

#include <xc.h> 

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */
    
struct Heater {
    int mode;
    double triggerTemp;
    double displayTemp;
    int hotTimer;
    int coldTimer;
    char errorLine1[17];
    char errorLine2[17];
} heater;

void SetTriggerTemp(double temp);
double GetTriggerTemp();
void IncrementMode();
void DecrementMode();
void SetHotTimer(int time);
int GetHotTimer();
void SetColdTimer(int time);
int GetColdTimer();


#ifdef	__cplusplus
}
#endif /* __cplusplus */



#endif	/* XC_HEADER_TEMPLATE_H */

