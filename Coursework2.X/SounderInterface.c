#include "SounderInterface.h"
#include "SounderDriver.h"
#include "Delay.h"

void ISounderBuzz(unsigned char hot) // 1 for hot 0 for cold;
{
    InitialiseSounder();
    if(hot)
    {
        // Two long beeps
        BeepSounder(20000);
        Delay(2500);
        BeepSounder(20000);
    }
    else 
    {
        // Three short beeps
        BeepSounder(10000);
        Delay(2500);
        BeepSounder(10000);
        Delay(2500);
        BeepSounder(10000);
    }
}
