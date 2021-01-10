#include <xc.h>

// Set tris values
void InitialiseSounder(void)
{
    TRISE = TRISE & 0xFE;
}

// beep sounders for given time.
void BeepSounder(short time)
{    
    RE0 = 1;
    
    for (int i = 0; i < time; i++) {
        
    }
    
    RE0 = 0;
}
