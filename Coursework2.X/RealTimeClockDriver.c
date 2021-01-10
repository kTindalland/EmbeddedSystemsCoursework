#include "RealTimeClockDriver.h"
#include "RealTimeClockConversions.h"
#include <xc.h>

// Ignore conversion warnings
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wconversion"

void rtcInit(void){
    TRISB = 0x00;
}

void clearWP(void) {
    
    writeByte(RTC_CTRL, 0x00);
}

uch readCH(void) {
    uch secsByte = readByte(RTC_SEC);
    
    return (secsByte & 0x80) >> 7;
}

void startClock(void) {
    uch currentSeconds = readByte(RTC_SEC);
    
    uch newSeconds = currentSeconds & 0x7F;
    
    writeByte(RTC_SEC, newSeconds);
}

void stopClock(void) {
    uch currentSeconds = readByte(RTC_SEC);
    
    uch newSeconds = currentSeconds | 0x80;
    
    writeByte(RTC_SEC, newSeconds);
}

uch readByte(uch addr) {
    rtcInit();
    
    uch readAddr = addr | RTC_READ;
    uch result = 0;
    
    SCLK = 0;
    RST = 0;
    
    // Start transaction 
    RST = 1;
    uch value;
    // Send addr
    TRISB = TRISB & 0xEF; // Set TRISB4 to output
    for (unsigned char i = 0; i < 8; i++) {
        value = (readAddr & 0x80) >> 7;
        RTC_IO = value;
               
        SCLK = 1;
        
        SCLK = 0;
        
        readAddr <<= 1;
    }
    
    TRISB = TRISB | 0x10; // Set TRISB4 to input
    // Read result 
    for (unsigned char i = 0; i < 8; i++) {
        // Read
        value = RTC_IO;
        
        result >>= 1;
        
        if (value) result |= 0x80;
        
        // Put up
        SCLK = 1;
        
        // Put down
        SCLK = 0;
    }
    
    RST = 0;   
    
    return result;    
}

void writeByte(uch addr, uch data) {
    rtcInit();
    
    uch writeAddr = addr | RTC_WRITE;
    
    SCLK = 0;
    RST = 0;
    
    RST = 1;
    uch value;
    // Send addr
    TRISB = TRISB & 0xEF; // Set TRISB4 to output
    for (unsigned char i = 0; i < 8; i++) {
        value = (writeAddr & 0x80) >> 7;
        
        RTC_IO = value;
        
        SCLK = 1;
        
        SCLK = 0;
        
        writeAddr <<= 1;
    }
    
    // Send data
    for (unsigned char i = 0; i < 8; i++) {
        value = (data & 0x01);
        
        RTC_IO = value;
        
        SCLK = 1;
        
        SCLK = 0;
        
        data >>= 1;
    }
    
    RST = 0;
}

#pragma GCC diagnostic pop