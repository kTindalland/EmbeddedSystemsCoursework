#include <xc.h>
#include "main.h"
#include "RealTimeClockConversions.h"
#include "LCDPanelInterface.h"
#include "ThermometerInterface.h"
#include "NumberConverter.h"
#include "ButtonsInterface.h"
#include "SounderInterface.h"

// Config
#pragma config FOSC = HS
#pragma config WDTE = OFF
#pragma config PWRTE = ON
#pragma config BOREN = OFF
#pragma config LVP = OFF

// Weird function won't work if not given exactly what it wants.
void SmartHeaterSetHotColdTime(unsigned char* actual, unsigned char* temp, unsigned char bound, char* title);

signed char home_temperature_whole;
signed char home_temperature_decimal;

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

rtcTime global_time;
rtcTime global_time_24;
rtcDate global_date;

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
    
    unsigned char year_digits = (unsigned char)(date.year);
    PrintTimeNumber(year_digits, " ");
}

void PrintDayToLCD(unsigned char day) {
    if (day > 7 || day < 1) return;
    
    char* tags[] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    ILCDPanelWrite(tags[day - 1]);
}

void GetTemperatureProxy(signed char* whole, signed char* decimal) {
    if (fake_temp_onoff) {
        *whole = fake_temperature;
        *decimal = fake_temperature_decimal;
    }
    else {
        IThermGetTemperature(whole, decimal);
    }
}

unsigned char GetMaximumDateForMonth(unsigned char month, unsigned char year)
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
        if (GetIsLeapYear(year)) { return 29; }
        else { return 28; }
    }
}

void GetGoalTriggerTime(unsigned char hot)
{
    
    goal_time = global_time_24;
    goal_date = global_date;
    
    unsigned char time_used;
    if (hot) { time_used = hot_time_actual;}
    else {time_used = cold_time_actual;}
    
    goal_time.secs = goal_time.secs + time_used;
    if (goal_time.secs > 59)
    {
        unsigned char secs_over = goal_time.secs % 60;
        unsigned char mins_extra = (goal_time.secs - secs_over) / 60;
        
        goal_time.secs = secs_over;
        goal_time.mins = goal_time.mins + mins_extra;
    }
    
    if (goal_time.mins > 59)
    {
        unsigned char mins_over = goal_time.mins % 60;
        unsigned char hours_extra = (goal_time.mins - mins_over) / 60;
        goal_time.mins = mins_over;
        goal_time.hours = goal_time.hours + hours_extra;
    }
    
    if (goal_time.hours > 23)
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

unsigned char GetTriggerTimeStatus(void)
{
    rtcTime current_time;
    current_time = global_time_24;
                
    rtcDate current_date;
    current_date = global_date;
    
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

// returns if the temperature is above or below the trigger.
unsigned char IsTemperatureHot() {
    unsigned char whole_above = 0;
    unsigned char whole_equal = 0;
    unsigned char decimal_above = 0;
    
    if (home_temperature_whole > trigger_temperature_whole) {
        whole_above = 1;
    }
    
    if (home_temperature_whole == trigger_temperature_whole) {
        whole_equal = 1;
    }
    
    if (home_temperature_decimal >= trigger_temperature_decimal) {
        decimal_above = 1;
    }
    
    // Returns 1 for hot and 0 for cold.    
    if (whole_equal == 1 && decimal_above == 1) {
        return 1;
    }
    return whole_above;
}

unsigned char IsInTimePeriod(void) {
    if (global_time_24.hours > 22) {
        return 0;
    }
    
    if (global_time_24.hours == 22) {
        if (global_time_24.mins >= 30) {
            return 0;
        }
    }
    
    
    
    if (global_time_24.hours < 7) {
        return 0;
    }
    
    return 1;
}

void main(void) {
    TRISB = 0x00;
    TRISE = 0x00;
    PORTE = 0x00;
    // Use real temperature.
    fake_temp_onoff = 0x00; 
    
    ILCDPanelClear();
    clearWP();
    
    getTime(&set_time_time);
    getDate(&set_date_date);
    global_time = set_time_time;
    
    global_time_24 = global_time;
    if (global_time_24.AMPM != -1) convertHourFormat(&global_time_24);
    
    global_date = set_date_date;
    
    set_trig_temp_whole = 30;
    set_trig_temp_decimal = 0;
    trigger_temperature_whole = 30;
    trigger_temperature_decimal = 0;
    
    // Set timer values
    hot_time_actual = 5;
    hot_time_temp = 5;
    
    cold_time_actual = 5;
    cold_time_temp = 5;
    
    // Set fake temp values.
    fake_temperature = 22;
    fake_temperature_decimal = 0;
    fake_temperature_temp = 22;
    fake_temperature_temp_decimal = 0;
    fake_temp_onoff = 0;
    
    unsigned char mode = HOME;
    unsigned char system_just_initialised = 0xFF;
    unsigned char isOverTriggerTemperature;
    unsigned char old_temperature_over_trigger;
    
    unsigned char in_time_period;
    unsigned char old_in_time_period;
    
    unsigned char system_on = IsInTimePeriod();
    
    unsigned char heating_latch = 0;

//    rtcTime time;
//    time.AMPM = 1;
//    time.hours = 9;
//    time.mins = 36;
//    time.secs = 0;
//    
//    setTime(time);
    
//    rtcDate date;
//    date.date = 1;
//    date.month = 1;
//    date.year = 21;
//    date.day = 5;
//    setDate(date);
    
    trigger_timer_passed = 0;
    
    
    
    while(1) {
        getTime(&global_time);
        
        global_time_24 = global_time;
        if (global_time_24.AMPM != -1) convertHourFormat(&global_time_24);
        
        getDate(&global_date);
        
        GetTemperatureProxy(&home_temperature_whole, &home_temperature_decimal);
        
        // Check the time is in bounds.
        in_time_period = IsInTimePeriod();
        
        
        isOverTriggerTemperature = IsTemperatureHot();
        temp_last = isOverTriggerTemperature; // For use in the mode_functions.c
        
        
        if (system_just_initialised) {
            // Clear the flag
            system_just_initialised = 0x00;
            
            // Set the old values equal to new
            old_temperature_over_trigger = isOverTriggerTemperature;
            old_in_time_period = in_time_period;
            
            // Get calculate the goal time.
            GetGoalTriggerTime(isOverTriggerTemperature);
            trigger_timer_passed = 0;
        }
        
        // Calculate change in time period.
        if (in_time_period != old_in_time_period) {
            // Set system on flag
            system_on = in_time_period;
            
            // When system comes back online, reinitialise it.
            system_just_initialised = in_time_period;
          
        }
        
        if (system_on) {
            RB5 = 1;
        }
        else {
            RB5 = 0;
        }
        
        if (system_on) {
            // Calculate the flip
            if (isOverTriggerTemperature != old_temperature_over_trigger) {
                GetGoalTriggerTime(isOverTriggerTemperature);
                trigger_timer_passed = 0;
            }

            // Assign current temperature to old value for next time.
            old_temperature_over_trigger = isOverTriggerTemperature;

            // If the timer hasn't already passed and it's over the threshold.
            if(!trigger_timer_passed && GetTriggerTimeStatus()) {
                // Need to buzz.
                ISounderBuzz(isOverTriggerTemperature);
                trigger_timer_passed = 1;

                // Change heating circuit.
                if (isOverTriggerTemperature) {
                    // If it's hot again, turn off the circuit.
                    heating_latch = 0;
                }
                else {
                    // If it's gone cold, turn on the circuit.
                    heating_latch = 1;
                }
            }
            
            if (heating_latch) {
                RB7 = 1;
            }
            else {
                RB7 = 0;
            }
        }
        
        
        // Get button states.
        unsigned char buttonResults[4][4] = {0};
        // Check buttons for mode change.
        CheckMatrixButtons(buttonResults);
        
        
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
            set_time_time = global_time;
            set_date_date = global_date;
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
                SmartHeaterSetHotColdTime(&hot_time_actual, &hot_time_temp, (unsigned char)60, "Set Hot Timer");
                break;
                
            case COLDTIME:
                SmartHeaterSetHotColdTime(&cold_time_actual, &cold_time_temp, (unsigned char)90, "Set Cold Timer");
                break;
        }
    }
    
    return;
}
