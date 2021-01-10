#include "globals.h"
#include "NumberConverter.h"
#include "LCDPanelInterface.h"
#include "buttons.h"
#include "main.h"

void Home(void) {
    
    rtcTime time;
    rtcDate date;
    char string[10];
    
    time = global_time;
    date = global_date;
        
    // Print day of week.
    PrintDayToLCD(date.day);
    ILCDPanelWrite(" ");
    
    // Print time
    PrintTimeToLCD(time);

    nbrcnvt_convert_integer(home_temperature_whole, string);

    ILCDPanelSetCursor(1,0);
    
    PrintDateToLCD(date);
    
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
    
    if (buttons) set_time_flag = 0; // Check if any button has been pressed.
    
    set_time_time.hours = set_time_time.hours + ((buttons & 0x10) >> 4);
    set_time_time.hours = set_time_time.hours - (buttons & 0x01);
    
    set_time_time.mins = set_time_time.mins + ((buttons & 0x20) >> 5);
    set_time_time.mins = set_time_time.mins - ((buttons & 0x02) >> 1);
    
    set_time_time.secs = set_time_time.secs + ((buttons & 0x40) >> 6);
    set_time_time.secs = set_time_time.secs - ((buttons & 0x04) >> 2);
    
    set_time_time.AMPM = set_time_time.AMPM + ((buttons & 0x08) >> 3);
    if (set_time_time.AMPM > 1) set_time_time.AMPM = -1;
    
    // Validation
    // Validate hours
    // Don't have to handle negatives because datatype is unsigned.
    // Will just wrap around if it tries to go negative.
    if (set_time_time.AMPM == -1 && set_time_time.hours > 23) set_time_time.hours = 23;
    else if (set_time_time.AMPM != -1 && set_time_time.hours > 12) set_time_time.hours = 12;
    
    // Validate minutes
    if (set_time_time.mins > 59) set_time_time.mins = 59;
    
    // Validate seconds
    if (set_time_time.secs > 59) set_time_time.secs = 59;
    
    if (buttons & 0x80) { // Set the time.
        setTime(set_time_time);
        set_time_flag = 1;
        
        // Reset the goal time.
        GetGoalTriggerTime(temp_last);
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
    PrintDayToLCD(set_date_date.day);
    
    unsigned char buttons = checkButtons();
    
    if (buttons) set_date_flag = 0;
    
    set_date_date.date = set_date_date.date + ((buttons & 0x10) >> 4);
    set_date_date.date = set_date_date.date - (buttons & 0x01);
    
    set_date_date.month = set_date_date.month + ((buttons & 0x20) >> 5);
    set_date_date.month = set_date_date.month - ((buttons & 0x02) >> 1);
    
    set_date_date.year = set_date_date.year + ((buttons & 0x40) >> 6);
    set_date_date.year = set_date_date.year - ((buttons & 0x04) >> 2);
    
    set_date_date.day = set_date_date.day + ((buttons & 0x08) >> 3);
    if (set_date_date.day > 7) set_date_date.day = 1;
    
    
    // Validation.
    unsigned char max_date = GetMaximumDateForMonth(set_date_date.month, set_date_date.year);
    if (set_date_date.date > max_date) set_date_date.date = max_date;
    
    if (set_date_date.month > 12) set_date_date.month = 12;
    if (set_date_date.month == 0) set_date_date.month = 1;
    
    if (set_date_date.year > 99) set_date_date.year = 99;
    if (set_date_date.year == 127) set_date_date.year = 0;
    
    if (buttons & 0x80) { // Set the date.
        setDate(set_date_date);
        set_date_flag = 1;
        
        // Reset the goal time.
        GetGoalTriggerTime(temp_last);
    }
    
    if (set_date_flag) {
        ILCDPanelWrite(" Set");
    }
    else {
        ILCDPanelWrite("    ");
    }
}

void SetTriggerTemperature(void) {
    
    ILCDPanelWrite("Set Trig Temp");
    
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
    
    if (set_trig_temp_whole > 115 || (set_trig_temp_whole == 115 && set_trig_temp_decimal > 0)) {
        set_trig_temp_whole = 115;
        set_trig_temp_decimal = 0;
    } 
    
    if (set_trig_temp_whole < -50 || (set_trig_temp_whole == -50 && set_trig_temp_decimal > 0)) {
        set_trig_temp_whole = -50;
        set_trig_temp_decimal = 0;
    }
    
    if (buttons & 0x80) {
        trigger_temperature_whole = set_trig_temp_whole; // Set
        trigger_temperature_decimal = set_trig_temp_decimal;
        
        // Reset the goal time.
        GetGoalTriggerTime(temp_last);
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
    
    string[0] = 0xDF; // Degree symbol.
    string[1] = 'C';
    string[2] = '\0';

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

void SmartHeaterSetHotColdTime(unsigned char* actual, unsigned char* temp, unsigned char bound, char* title) {
    ILCDPanelWrite(title);
    
    if (*actual != *temp) ILCDPanelWrite("*");
    else ILCDPanelWrite(" ");
    
    unsigned char buttons;
    buttons = checkButtons();
    
    *temp = *temp - (buttons & 0x01); // Take 1
    *temp = *temp + ((buttons & 0x10) >> 4); // Add 1
    
    *temp = *temp - (((buttons & 0x02) >> 1) * 10); // Take 10
    *temp = *temp + (((buttons & 0x20) >> 5) * 10); // Add 10
    
    if (*temp > bound) *temp = bound;
    
    if (buttons & 0x04) *temp = *actual; // Cancel;
    if (buttons & 0x40) {
        *actual = *temp; // Set;
        
        // Reset the goal time.
        GetGoalTriggerTime(temp_last);
    }
    
    char string[10];
    nbrcnvt_convert_integer(*temp, string);
    
    ILCDPanelSetCursor(1,0);
    ILCDPanelWrite(string);
    ILCDPanelWrite("    "); // Clear it out
}