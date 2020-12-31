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

signed char set_trig_temp_whole;
signed char set_trig_temp_decimal;
signed char trigger_temperature_whole;
signed char trigger_temperature_decimal;

unsigned char hot_time_actual;
unsigned char hot_time_temp;

unsigned char cold_time_actual;
unsigned char cold_time_temp;

unsigned char temp_last;

rtcDate start_trig_date;
rtcTime start_trig_time;
rtcTime goal_time;
rtcDate goal_date;
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
    
    if ((set_trig_temp_whole != trigger_temperature_whole) || (set_trig_temp_decimal != trigger_temperature_decimal)) ILCDPanelWrite("*"); // Change indicator.
    else ILCDPanelWrite(" ");
    
    unsigned char buttons;
    buttons = checkButtons();
    
    set_trig_temp_whole = set_trig_temp_whole + ((buttons & 0x10) >> 4); // Add 1
    set_trig_temp_whole = set_trig_temp_whole - (buttons & 0x01); // Sub 1
    
    set_trig_temp_whole = set_trig_temp_whole + ((buttons & 0x20) >> 5) * 10; // Add 10
    set_trig_temp_whole = set_trig_temp_whole - ((buttons & 0x02) >> 1) * 10; // Sub 10
    
    set_trig_temp_decimal = set_trig_temp_decimal + ((buttons & 0x40) >> 6); // Add 0.1
    set_trig_temp_decimal = set_trig_temp_decimal - ((buttons & 0x04) >> 2); // Sub 0.1

    // Check the decimal stuff
    if (set_trig_temp_decimal < 0) {
        set_trig_temp_decimal = 9;
        set_trig_temp_whole--;
    }
    
    if (set_trig_temp_decimal > 9) {
        set_trig_temp_decimal = 0;
        set_trig_temp_whole++;
    }
    
    // Check bounds?
    
    if (buttons & 0x80) {
        trigger_temperature_whole = set_trig_temp_whole; // Set
        trigger_temperature_decimal = set_trig_temp_decimal;
    }
    
    if (buttons & 0x08) {
        set_trig_temp_whole = trigger_temperature_whole; // Cancel
        set_trig_temp_decimal = trigger_temperature_decimal;
    }
    
    ILCDPanelSetCursor(1, 0);
    char string[10];
    nbrcnvt_convert_integer(set_trig_temp_whole, string);
    ILCDPanelWrite(string);
    
    ILCDPanelWrite(".");
    
    nbrcnvt_convert_integer(set_trig_temp_decimal, string);
    ILCDPanelWrite(string);
    
    ILCDPanelWrite("   ");
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

unsigned char GetMaximumDateForMonth(unsigned char month, short year)
{
    if (month != 2)
    {
        if ((month == 1) || (month == 3) || (month == 5) || (month == 7) || (month == 8) ||(month == 10) ||  (month == 12))
        {
            return 31;
        }
        else return 30;
    }
    else
    {
        if (year % 400 == 0)        return 29;
        else if (year % 100 == 0)   return 28;
        else if (year % 4 == 0)     return 29;
        else                        return 28;
    }
}

void GetGoalTriggerTime(unsigned char hot)
{
    trigger_timer_passed = 0;
    getTime24(&start_trig_time);
    getDate(&start_trig_date);
    goal_time = start_trig_time;
    goal_date = start_trig_date;
    
    if (goal_time.secs + cold_time_actual > 59)
    {
        goal_time.secs = goal_time.secs - 60;
        goal_time.mins = goal_time.mins + 1;
        if (goal_time.mins > 59)
        {
            goal_time.mins = 0;
            goal_time.hours = goal_time.hours + 1;
            if ((set_time_time.AMPM == -1 && goal_time.hours > 23) ||
                goal_time.hours > 11) // Open to Being Extended for 12Hr Mode
                {
                    goal_time.hours = 0;
                    goal_date.date = goal_date.date + 1;
                    if (goal_date.day == 7) { goal_date.day = 1; }
                    else { goal_date.day = goal_date.day + 1; }
                            
                    if (goal_date.date > GetMaximumDateForMonth(goal_date.month, goal_date.year))
                    {
                        goal_date.date = 1;
                        goal_date.month = goal_date.month + 1;
                        if (goal_date.month > 12)
                        {
                            goal_date.month = 1;
                            goal_date.year = goal_date.year + 1;
                        }
                    }
                }
            }
    }
}

unsigned char GetTriggerTimeStatus(void)
{
    rtcTime current_time;
    getTime24(&current_time);
                
    rtcDate current_date;
    getDate(&current_date);   
    
    if (current_date.year > goal_date.year) { return 1; }
    if (current_date.year < goal_date.year) { return 0; }
    
    if (current_date.month > goal_date.month) { return 1; }
    if (current_date.month < goal_date.month) { return 0; }
    
    if (current_date.date > goal_date.date) { return 1; }
    if (current_date.date < goal_date.date) { return 0; }
    
    if (current_time.hours > goal_time.hours) { return 1; }
    if (current_time.hours < goal_time.hours) { return 0; }
    
    if (current_time.mins > goal_time.mins) { return 1; }
    if (current_time.mins < goal_time.mins) { return 0; }
    
    if (current_time.secs >= goal_time.secs) { return 1; }
    if (current_time.secs < goal_time.secs) { return 0; }
    
    return 0;
}

void main(void) {
    // Use real temperature.
    fake_temp_onoff = 0x00;
    
    ILCDPanelClear();
    clearWP();
    
    getTime(&set_time_time);
    getDate(&set_date_date);
    
    set_trig_temp_whole = 30;
    set_trig_temp_decimal = 0;
    trigger_temperature_whole = 30;
    set_trig_temp_whole = 0;
    
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
    trigger_timer_passed = 1;
    
    while(1) {    
        
        rtcTime time;
        getTime(&time);
        
        if (time.secs % 6 == 0) { // Every 6 secs to reduce time.
            GetTemperatureProxy(&home_temperature_whole, &home_temperature_decimal);

            // Hot To Cold
            if (((home_temperature_whole < trigger_temperature_whole) || // EG: 23.9 < 24.1
               ((home_temperature_whole == trigger_temperature_whole) && (home_temperature_decimal < trigger_temperature_decimal))) // 25.4 < 25.5
               && temp_last == 1)         
            {
                temp_last = 0;
                GetGoalTriggerTime(0);
            }

            
            // Cold To Hot
            else if (((home_temperature_whole > trigger_temperature_whole) || // EG: 24.1 > 23.9
               ((home_temperature_whole == trigger_temperature_whole) && (home_temperature_decimal > trigger_temperature_decimal))) // 25.5 > 25.4
               && temp_last == 0)         
            {        
                temp_last = 1;
                GetGoalTriggerTime(1);
            }           
            
            // No Trigger, But Buzzer Hasn't Gone Off From Last Trigger
            else if (trigger_timer_passed == 0)
            {
                if(GetTriggerTimeStatus())
                {
                    trigger_timer_passed = 1;
                    ISounderBuzz(temp_last);
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
