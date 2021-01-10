#include "LCDPanelDriver.h"
#include "StringUtils.h"
#include "Delay.h"
#include <xc.h> 

// Pins
#define rs RA1
#define rw RA2
#define e  RA3

//Clear the screen
void ClearCmd(void)
{
    WriteCmd(0x1); 
}

// Initialise TRIS and screen
void LcdInit(void)
{
    ADCON1=0x07;               
    TRISA=0x00;             
    TRISD=0x00;
    
    WriteCmd(0x0C); //display on
    WriteCmd(0x38); //8 bits 2 lines 5*7 mode
}

// Write single command
void WriteCmd(char x)
{
 rs=0;      //Command, not data
 rw=0;      //Write, not read
 e=0;       //Pull low enable signal.
 e=1;       //Pull high to build the rising edge
 PORTD=x;     
 Delay(2000);
 e=0;
}

// Write single char
void WriteChar(char x)
{
    rs=1;       //Data, not command
    rw=0;      //Write, not read
    e=0;       //Pull low enable signal.
    e=1;       //Pull high to build the rising edge
    PORTD=x;     
    Delay(2000);
    e=0;
}

// Write full string to the LCDPanel
void WriteString(char s[])
{ 
    for (unsigned char i=0; i<StringLength(s); i++)
    {
        // Call write char for each char
        WriteChar(s[i]);
    }
}

// Set the cursor position.
void SetCursorPos(char line, char col){
    
    char basePos = line ? 0xC0 : 0x80;
    WriteCmd(basePos + col);
}