#ifndef __LCDINTERFACE
#define __LCDINTERFACE


void ILCDPanelSetCursor(char down, char along);

void ILCDPanelClear(void);

void ILCDPanelWrite(char s[]);

#endif