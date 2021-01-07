#include <xc.h>

void InitialiseSounder(void)
{
    TRISE = TRISE & 0xFE;
}

void BeepSounder(short time)
{
    for (short i = 0; i < time; i++)
    {
        RE0 = 1;
    }
    RE0 = 0;
}