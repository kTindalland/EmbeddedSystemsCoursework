/*
 * File:   main.c
 * Author: kaiti
 *
 * Created on 18 December 2020, 10:33
 */


#include <xc.h>
#include "LCDPanelInterface.h"
#include "RealTimeClockDriver.h"
#include "RealTimeClockConversions.h"
#include "ThermometerInterface.h"
#include "NumberConverter.h"
#include "buttons.h"

#define HOME 0
#define SETTIME 1
#define TRIGTEMP 2
#define FAKETEMP 3
#define HOTTIME 4
#define COLDTIME 5

signed char home_temperature_whole;
unsigned char home_temperature_decimal;

rtcTime set_time_time;
unsigned char set_time_flag;

unsigned char set_trig_temp;
unsigned char trigger_temperature;

unsigned char hot_time_actual;
unsigned char hot_time_temp;

unsigned char cold_time_actual;
unsigned char cold_time_temp;

void PrintTimeNumber(int number, char* endString) {
    char string[10];
    
    nbrcnvt_convert_integer(number, string);
    if (number < 10) ILCDPanelWrite("0");
    ILCDPanelWrite(string);
    ILCDPanelWrite(endString);
}

void PrintTimeToLCD(rtcTime time) {
        
    PrintTimeNumber(time.hours, ":");
    PrintTimeNumber(time.mins, ":");
    PrintTimeNumber(time.secs, " ");
    
    char* tags[] = {"  ", "AM", "PM" };
    ILCDPanelWrite(tags[time.AMPM + 1]);
}

void Home(void) {
    
    rtcTime time;
    char string[10];
    
    getTime(&time);
        
    

    PrintTimeToLCD(time);

    // Temperature stuff now
    if (time.secs % 6 == 0) { // Every 6 secs to reduce time.
        IThermGetTemperature(&home_temperature_whole, &home_temperature_decimal);
    }

    nbrcnvt_convert_integer(home_temperature_whole, string);

    ILCDPanelSetCursor(1,0);
    ILCDPanelWrite(string);
    ILCDPanelWrite(".");
    
    nbrcnvt_convert_integer(home_temperature_decimal, string);
    ILCDPanelWrite(string);
    

    string[0] = 0xDF; // Degree symbol.
    string[1] = 'C';
    string[2] = '\0';

    ILCDPanelWrite(string);
}

void SetTime(void) {
    
    ILCDPanelWrite("Set System Time");
    
    ILCDPanelSetCursor(1, 0);
    PrintTimeToLCD(set_time_time);
    
    unsigned char buttons = checkButtons();
    
    if (buttons) set_time_flag = 0;
    
    // TODO: Needs validation.
    set_time_time.hours = set_time_time.hours + ((buttons & 0x10) >> 4);
    set_time_time.hours = set_time_time.hours - (buttons & 0x01);
    
    set_time_time.mins = set_time_time.mins + ((buttons & 0x20) >> 5);
    set_time_time.mins = set_time_time.mins - ((buttons & 0x02) >> 1);
    
    set_time_time.secs = set_time_time.secs + ((buttons & 0x40) >> 6);
    set_time_time.secs = set_time_time.secs - ((buttons & 0x04) >> 2);
    
    set_time_time.AMPM = set_time_time.AMPM + ((buttons & 0x08) >> 3);
    if (set_time_time.AMPM > 1) set_time_time.AMPM = -1;
    
    if (buttons & 0x80) {
        setTime(set_time_time);
        set_time_flag = 1;
    }
    
    
    if (set_time_flag) {
        ILCDPanelWrite(" Set");
    }
    else {
        ILCDPanelWrite("    ");
    }
}

void SetTriggerTemperature() {
    
    ILCDPanelWrite("Trigger Temp.");
    
    if (set_trig_temp != trigger_temperature) ILCDPanelWrite("*"); // Change indicator.
    else ILCDPanelWrite(" ");
    
    unsigned char buttons;
    buttons = checkButtons();
    
    set_trig_temp = set_trig_temp + ((buttons & 0x10) >> 4); // Add 1
    set_trig_temp = set_trig_temp - (buttons & 0x01); // Sub 1
    
    //set_trig_temp = set_trig_temp + ((buttons & 0x20) >> 5); // Add 0.1
    
    //set_trig_temp = set_trig_temp - ((buttons & 0x02) >> 1); // Sub 0.1

    if (buttons & 0x40) trigger_temperature = set_trig_temp; // Set
    if (buttons & 0x04) set_trig_temp = trigger_temperature; // Cancel
    
    ILCDPanelSetCursor(1, 0);
    char string[10];
    nbrcnvt_convert_integer(set_trig_temp, string);
    ILCDPanelWrite(string);
}

void SetFakeTemperature() {
    ILCDPanelWrite("Set Fake Temp.");
}

void SetHotColdTime(unsigned char* actual, unsigned char* temp, unsigned char bound, char* title) {
    ILCDPanelWrite(title);
    
    if (*actual != *temp) ILCDPanelWrite("*");
    else ILCDPanelWrite(" ");
    
    unsigned char buttons;
    buttons = checkButtons();
    
    *temp = *temp - (buttons & 0x01);
    *temp = *temp + ((buttons & 0x10) >> 4);
    
    if (*temp > bound) *temp = bound;
    
    if (buttons & 0x02) *temp = *actual; // Cancel;
    if (buttons & 0x20) *actual = *temp; // Set;
    
    char string[10];
    nbrcnvt_convert_integer(temp, string);
    
    ILCDPanelSetCursor(1,0);
    ILCDPanelWrite(string);
}

void main(void) {
    ILCDPanelClear();
    clearWP();
    
    getTime(&set_time_time);
    
    set_trig_temp = 20;
    trigger_temperature = 20;
    
    int mode = HOME;
//    time.AMPM = PM;
//    time.hours = 2;
//    time.mins = 36;
//    time.secs = 0;
//    
//    setTime(time);
    
    while(1) {
        
        // Get button states.
        int buttonResults[4][4] = {0};
        // Check buttons for mode change.
        checkMatrixButtons(buttonResults);
        
        
        if (buttonResults[0][0]) {
            mode = HOME;
            ILCDPanelClear();
        }
        else if (buttonResults[0][1]) {
            mode = SETTIME;
            ILCDPanelClear();
        }
        else if (buttonResults[0][2]) {
            mode = TRIGTEMP;
            ILCDPanelClear();
        }
        else if (buttonResults[0][3]) {
            mode = FAKETEMP;
            ILCDPanelClear();
        }
        else if (buttonResults[1][0]) {
            mode = HOTTIME;
            ILCDPanelClear();
        }
        else if (buttonResults[1][1]) {
            mode = COLDTIME;
            ILCDPanelClear();
        }
        else if (buttonResults[3][0]) {
            getTime(&set_time_time);
        }
                
        
        ILCDPanelSetCursor(0,0);
        // Run mode function.       
        switch (mode) {
            case HOME:
                Home();
                break;
                
            case SETTIME:
                SetTime();
                break;
                
            case TRIGTEMP:
                SetTriggerTemperature();
                break;
                
            case FAKETEMP:
                SetFakeTemperature();
                break;
                
            case HOTTIME:
                SetHotColdTime(&hot_time_actual, &hot_time_temp, 60, "Set Hot Timer");
                break;
                
            case COLDTIME:
                SetHotColdTime(&cold_time_actual, &cold_time_temp, 90, "Set Cold Timer");
                break;
        }
    }
    
    return;
}
