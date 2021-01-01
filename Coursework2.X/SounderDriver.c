#include <xc.h>

void InitialiseSounder(void)
{
    TRISA = TRISA & 0xFE;
}

void BeepSounder(short time)
{
    for (short i = 0; i < time; i++)
    {
        RA0 = 1;
    }
    RA0 = 0;
}