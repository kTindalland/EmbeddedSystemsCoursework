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
#define SETDATE 2
#define TRIGTEMP 3
#define FAKETEMP 4
#define HOTTIME 5
#define COLDTIME 6


signed char home_temperature_whole;
unsigned char home_temperature_decimal;

rtcTime set_time_time;
unsigned char set_time_flag;

rtcDate set_date_date;
unsigned char set_date_flag;

unsigned char set_trig_temp;
unsigned char trigger_temperature;

unsigned char hot_time_actual;
unsigned char hot_time_temp;

unsigned char cold_time_actual;
unsigned char cold_time_temp;

unsigned char temp_last;

rtcDate start_trig_date;
rtcTime start_trig_time;
unsigned char trigger_timer_passed;


unsigned char cold_timer_actual;
unsigned char hot_timer_actual;

signed char fake_temperature;
signed char fake_temperature_decimal;
signed char fake_temperature_temp;
signed char fake_temperature_temp_decimal;
unsigned char fake_temp_onoff;

void PrintTimeNumber(unsigned char number, char* endString) {
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

void PrintDateToLCD(rtcDate date){
    PrintTimeNumber(date.date, "/");
    PrintTimeNumber(date.month, "/");
    PrintTimeNumber(date.year - 2000, " ");
    
    char* tags[] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    ILCDPanelWrite(tags[date.day -1]);
}

void Home(void) {
    
    rtcTime time;
    char string[10];
    
    getTime(&time);
        
    PrintTimeToLCD(time);

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

void SetDate(void)
{
    ILCDPanelWrite("Set System Date");
    
    ILCDPanelSetCursor(1, 0);
    
    PrintDateToLCD(set_date_date);
    
    unsigned char buttons = checkButtons();
    
    if (buttons) set_date_flag = 0;
    
    // TODO: Needs validation.
    set_date_date.date = set_date_date.date + ((buttons & 0x10) >> 4);
    set_date_date.date = set_date_date.date - (buttons & 0x01);
    
    set_date_date.month = set_date_date.month + ((buttons & 0x20) >> 5);
    set_date_date.month = set_date_date.month - ((buttons & 0x02) >> 1);
    
    set_date_date.year = set_date_date.year + ((buttons & 0x40) >> 6);
    set_date_date.year = set_date_date.year - ((buttons & 0x04) >> 2);
    
    set_date_date.day = set_date_date.day + ((buttons & 0x08) >> 3);
    if (set_date_date.day > 7) set_date_date.day = 1;
    
    if (buttons & 0x80) {
        setDate(set_date_date);
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

void SetFakeTemperature(void) {
    ILCDPanelWrite("Set Fake Temp.");
    
    if ((fake_temperature != fake_temperature_temp) ||
            (fake_temperature_decimal != fake_temperature_temp_decimal)) ILCDPanelWrite("*");
    else ILCDPanelWrite(" ");
    
    unsigned char buttons;
    buttons = checkButtons();
    
    fake_temperature_temp = fake_temperature_temp - (buttons & 0x01); // -1
    fake_temperature_temp = fake_temperature_temp + ((buttons & 0x10) >> 4); // +1
    
    fake_temperature_temp = fake_temperature_temp - (((buttons & 0x02) >> 1) * 10); // -10
    fake_temperature_temp = fake_temperature_temp + (((buttons & 0x20) >> 5) * 10); // +10
    
    fake_temperature_temp_decimal = fake_temperature_temp_decimal - ((buttons & 0x04) >> 2);
    fake_temperature_temp_decimal = fake_temperature_temp_decimal + ((buttons & 0x40) >> 6);
    
    // Reorganise numbers
    if (fake_temperature_temp_decimal < 0) {
        fake_temperature_temp_decimal = 9;
        fake_temperature_temp--;
    }
    
    if (fake_temperature_temp_decimal > 9) {
        fake_temperature_temp_decimal = 0;
        fake_temperature_temp++;
    }
    
    // Check numbers for bounds.
   if (fake_temperature_temp >= 115 && fake_temperature_temp_decimal > 0) {
       fake_temperature_temp = 115;
       fake_temperature_temp_decimal = 0;
    } 
    
    if (fake_temperature_temp <= -50 && fake_temperature_temp_decimal > 0) {
        fake_temperature_temp = -50;
       fake_temperature_temp_decimal = 0;
    }
    
    // Check set/cancel.
    if (buttons & 0x08) { // Cancel
        fake_temperature_temp = fake_temperature;
        fake_temperature_temp_decimal = fake_temperature_decimal;
    }
    
    if (buttons & 0x80) { // Set
        fake_temperature = fake_temperature_temp;
        fake_temperature_decimal = fake_temperature_temp_decimal;
    }
    
    // Write out numbers.
    char string[10];
    ILCDPanelSetCursor(1,0);
    
    nbrcnvt_convert_integer(fake_temperature_temp, string);
    ILCDPanelWrite(string);
    ILCDPanelWrite(".");
    
    nbrcnvt_convert_integer(fake_temperature_temp_decimal, string);
    ILCDPanelWrite(string);
    
    string[0] = 0xDF; // Degree symbol.
    string[1] = 'C';
    string[2] = '\0';
    
    ILCDPanelWrite(string);
    
    if (fake_temp_onoff) {
        ILCDPanelWrite(" ON  ");
    }
    else {
        ILCDPanelWrite(" OFF  ");
    }
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
    nbrcnvt_convert_integer(*temp, string);
    
    ILCDPanelSetCursor(1,0);
    ILCDPanelWrite(string);
}

void GetTemperatureProxy(unsigned char* whole, unsigned char* decimal) {
    if (fake_temp_onoff) {
        *whole = fake_temperature;
        *decimal = fake_temperature_decimal;
    }
    else {
        IThermGetTemperature(whole, decimal);
    }
};

void main(void) {
    // Use real temperature.
    fake_temp_onoff = 0x00;
    
    ILCDPanelClear();
    clearWP();
    
    getTime(&set_time_time);
    getDate(&set_date_date);
    
    set_trig_temp = 20;
    trigger_temperature = 20;
    
    // Set timer values
    hot_time_actual = 45;
    hot_time_temp = 45;
    
    cold_time_actual = 45;
    cold_time_temp = 45;
    
    // Set fake temp values.
    fake_temperature = 22;
    fake_temperature_decimal = 0;
    fake_temperature_temp = 22;
    fake_temperature_temp_decimal = 0;
    fake_temp_onoff = 0;
    
    unsigned char mode = HOME;
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
            GetTemperatureProxy(&home_temperature_whole, &home_temperature_decimal);
            
            if (home_temperature_whole < trigger_temperature && temp_last == 1)
            {
                trigger_timer_passed = 0;
                temp_last = 0;
                getTime(&start_trig_time);
            }
            else if (home_temperature_whole > trigger_temperature && temp_last == 0)
            {
                trigger_timer_passed = 0;
                temp_last = 1;
                getTime(&start_trig_time);
            }
            else if (trigger_timer_passed == 0)
            {
                rtcTime current_time;
                getTime(&current_time);
                
                rtcDate current_date;
                getDate(&current_date);
                
               
                unsigned int current_time_char = (current_time.hours * 60 * 60) + (current_time.mins * 60) + current_time.secs;
                unsigned int start_trig_time_char = (start_trig_time.hours * 60 * 60) + (start_trig_time.mins * 60) + start_trig_time.secs;
                unsigned int time_difference;
                
                int cY = current_date.year;
                int cM = current_date.month;
                int cD = current_date.date;
                int sY = start_trig_date.year;
                int sM = start_trig_date.month;
                int sD = start_trig_date.date;
                
                unsigned char time_flag = 0;
                
                if ((cY == sY + 1 && cM == 1 && cD == 1)  || // If next day is next day, but also next year.
                    (cY == sY && cM == sM + 1 && cD == 1) || // If next day is next day, but also next month.
                    (cY == sY && cM == sM && cD == sD + 1))  // If current day is next day, but in the same month/year.
                {
                    time_difference = current_time_char + (86400 - start_trig_time_char);
                }
                else
                {
                    time_difference = current_time_char - start_trig_time_char;
                }
                
                if (temp_last == 0 && 
                    start_trig_time_char + cold_time_actual <= time_difference)
                {
                    trigger_timer_passed = 1;
                    ISounderBuzz(0);
                }
                else if (temp_last == 1 &&
                         start_trig_time_char + hot_time_actual <= time_difference)
                {
                    trigger_timer_passed = 1;
                    ISounderBuzz(1);
                }
            }
        }
        
        // Get button states.
        unsigned char buttonResults[4][4] = {0};
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
            mode = SETDATE;
            ILCDPanelClear();
        }
        else if (buttonResults[0][3]) {
            getTime(&set_time_time);
            getDate(&set_date_date);
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
        else if (buttonResults[1][2]) {
            mode = TRIGTEMP;
            ILCDPanelClear();
        }
        else if (buttonResults[1][3]) {
            mode = FAKETEMP;
            ILCDPanelClear();
        }
        else if (buttonResults[2][0]) {
            // Toggle the fake temperature.
            fake_temp_onoff = ~fake_temp_onoff;
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
                
            case SETDATE:
                SetDate();
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
