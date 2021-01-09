#include <pic16f877a.h>
#include "timer.h"

// Implementation using Timer1
unsigned int count = 0;
unsigned int limit = 0;
void (*limit_function)(void);

unsigned int CheckTimer(void) {
    return count;
}

void StartTimer(void) {
    T1CON = (1<<SBIT_PS1) | (1<<SBIT_PS0); // Timer0 with external freq and 8 as prescalar
    TMR1H=0x0B;     // Load the time value(0xBDC) for 100ms delay
    TMR1L=0xDC;       
    TMR1IE=1;       //Enable timer interrupt bit in PIE1 register
    GIE=1;          //Enable Global Interrupt
    PEIE=1;         //Enable the Peripheral Interrupt
    TMR1ON = 1;     //Start Timer1    
}

void __interrupt() timer_isr(void)
{  
    if(TMR1IF==1)
    {
        TMR1H=0x0B;     // Load the time value(0xBDC) for 100ms delay
        TMR1L=0xDC;
        TMR1IF=0;       // Clear timer interrupt flag
        
        count++;
    } 
    
    if (limit =! 0 && count >= limit) {
        limit_function();
        limit = 0;
    }
}

void ResetTimer(void) {
    TMR1H=0x0B;     // Load the time value(0xBDC) for 100ms delay
    TMR1L=0xDC;
    TMR1IF=0;       // Clear timer interrupt flag
        
    count = 0;
}

void SetTimerLimit(unsigned int new_limit) {
    limit = new_limit;
}

void SetLimitFunction(void (*new_limit_function)(void)) {
    limit_function = new_limit_function;
}