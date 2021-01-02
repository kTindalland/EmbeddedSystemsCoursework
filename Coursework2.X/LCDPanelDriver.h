#include <xc.h> 

#define rs RA1 // Data
#define rw RA2 // Read/Write
#define e  RA3 // Enable

void LcdInit(void); // Initialise the tris vals.
void WriteCmd(char x); // Write a command to the LCD display.
void WriteChar(char x); // Write a character to the LCD display.
void WriteString(char s[]); // Write a full string to the LCD display.
void SetCursorPos(char line, char col); // Set the cursor position.
void ClearCmd(void); // Clear the screen.
