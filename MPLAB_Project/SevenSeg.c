/*
 * File:   newmain.c
 * Author: 581402
 *
 * Created on 26 October 2020, 14:25
 */

#include <xc.h>
#include "Delay.h"

// Define Which LED
#define LED1 0x3E   //00111110
#define LED2 0x3D
#define LED3 0x3B
#define LED4 0x37
#define LED5 0x2F
#define LED6 0x1F

#define NUM0 0xC0
#define NUM1 0xF9
#define NUM2 0xA4
#define NUM3 0xB0
#define NUM4 0x99
#define NUM5 0x92
#define NUM6 0x82
#define NUM7 0xF8
#define NUM8 0x80
#define NUM9 0x90

int ledArray[6] = {LED1, LED2, LED3, LED4, LED5, LED6};
int numArray[10] = {NUM0, NUM1, NUM2, NUM3, NUM4, NUM5, NUM6, NUM7, NUM8, NUM9};

void ClearAllSeg(){
    PORTA = 0xff;
    PORTD = 0xff;   // Clear All Display
}

void InitSeg(){
    ADCON1 = 0x07;  // Set A Port General I/O Port
    TRISA = 0x00;   // Set A Port Output
    TRISD = 0x00;   // Set D Port Output
    
    PORTA = 0xff;
    PORTD = 0xff;   // Clear All Display
}

void SetSeg(int led, int num){
    InitSeg();
    
    PORTA = ledArray[led-1];
    PORTD = numArray[num];
    
    Delay(400);
}

void SetAllSeg(int a, int b, int c, int d, int e, int f)
{
    SetSeg(1, a);
    SetSeg(2, b);
    SetSeg(3, c);
    SetSeg(4, d);
    SetSeg(5, e);
    SetSeg(6, f);
}

void ExampleSeg() {
    SetAllSeg(2, 4, 6, 1, 3, 5);
    //SetSeg(3, 9);
    ClearAllSeg();
} // Example of Driver User



