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
#include "SounderInterface.h"

#define HOME 0
#define SETTIME 1
#define TRIGTEMP 2
#define FAKETEMP 3
#define HOTTIME 4
#define COLDTIME 5

double home_temperature;
rtcTime set_time_time;
unsigned char set_time_flag;
double set_trig_temp;
double trigger_temperature;

double temp_last;
rtcTime start_trig_time;
int trigger_timer_passed;

unsigned char cold_timer_actual;
unsigned char hot_timer_actual;

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

    nbrcnvt_convert_double(home_temperature, string);

    ILCDPanelSetCursor(1,0);
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
    
    ILCDPanelSetCursor(1, 0);
    
    char string[10];
    nbrcnvt_convert_double(set_trig_temp, string);
    ILCDPanelWrite(string);
}

void SetFakeTemperature() {
    ILCDPanelWrite("Set Fake Temp.");
}

void SetHotTime() {
    ILCDPanelWrite("Set Hot Timer");
}

void SetColdTime() {
    ILCDPanelWrite("Set Cold Timer");
}

void main(void) {
    ILCDPanelClear();
    clearWP();
    
    getTime(&set_time_time);
    
    set_trig_temp = 20.0;
    trigger_temperature = 20.0;
    
    int mode = HOME;
//    time.AMPM = PM;
//    time.hours = 2;
//    time.mins = 36;
//    time.secs = 0;
//    
//    setTime(time);
    trigger_timer_passed = 0;
    
    while(1) {    
        
        rtcTime time;
        getTime(&time);
        
        if (time.secs % 6 == 0) { // Every 6 secs to reduce time.
            home_temperature = IThermGetTemperature();
            
            if (home_temperature < trigger_temperature && temp_last == 1)
            {
                trigger_timer_passed = 0;
                temp_last = 0;
                getTime(&start_trig_time);
            }
            else if (home_temperature > trigger_temperature && temp_last == 0)
            {
                trigger_timer_passed = 0;
                temp_last = 1;
                getTime(&start_trig_time);
            }
            else if (trigger_timer_passed == 0)
            {
                rtcTime current_time;
                getTime(&current_time);
                               
                unsigned char current_time_int = (current_time.mins * 60) + current_time.secs;
                unsigned char start_trig_time_int = (start_trig_time.mins * 60) + start_trig_time.secs;
                unsigned char time_difference = current_time_int - start_trig_time_int;
                
                if (temp_last == 0 && 
                    start_trig_time_int + cold_timer_actual >= current_time_int)
                {
                    trigger_timer_passed = 1;
                    ISounderBuzz(0);
                }
                else if (temp_last == 1 &&
                         start_trig_time_int + hot_timer_actual >= current_time_int)
                {
                    trigger_timer_passed = 1;  
                    ISounderBuzz(1);
                }
            }
        }
        
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
                SetHotTime();
                break;
                
            case COLDTIME:
                SetColdTime();
                break;
        }
    }
    
    return;
}
