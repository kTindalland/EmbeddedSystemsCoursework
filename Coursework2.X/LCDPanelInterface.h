#ifndef __LCDINTERFACE
#define __LCDINTERFACE

// Interface just calls driver functions.
// Should be nicer to use.

void ILCDPanelSetCursor(char down, char along); // Set the cursor of the LCD Screen.

void ILCDPanelClear(void); // Clear the LCD screen.

void ILCDPanelWrite(char s[]); // Write a string to the LCD panel.

#endif