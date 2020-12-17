#include "SounderDriver.h"

void ISounderBuzz(int hot) // 1 for hot 0 for cold;
{
    InitialiseSounder();
    if(hot)
    {
        BeepSounder(2000);
        Delay(500);
        BeepSounder(2000);
    }
    else 
    {
        BeepSounder(500);
        Delay(500)
        BeepSounder(500);
        Delay(500);
        BeepSounder(500);
    }
}