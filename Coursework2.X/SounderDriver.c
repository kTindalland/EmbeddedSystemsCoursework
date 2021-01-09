#include <xc.h>

void InitialiseSounder(void)
{
    TRISE = TRISE & 0xFE;
}


void BeepSounder(short time)
{    
    RE0 = 1;
    
    for (int i = 0; i < time; i++) {
        
    }
    
    RE0 = 0;
}
