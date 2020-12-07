
#ifndef XC_HEADER_TEMPLATE_H
#define	XC_HEADER_TEMPLATE_H

#include <xc.h> 

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */
    
struct Heater {
    int mode;
    int triggerTemp;
    int hotTimer;
    int coldTimer;
    char[] error;
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

