/* 
 * File:   timer.h
 * Author: kaiti
 *
 * Created on 08 January 2021, 15:25
 */

#ifndef TIMER_H
#define	TIMER_H

#ifdef	__cplusplus
extern "C" {
#endif
    
    #define SBIT_PS1  5
    #define SBIT_PS0  4
    
    unsigned int CheckTimer(void);
    void StartTimer(void);
    void ResetTimer(void);
    
    void SetTimerLimit(unsigned int new_limit);
    void SetLimitFunction(void (*new_limit_function)(void));


#ifdef	__cplusplus
}
#endif

#endif	/* TIMER_H */

