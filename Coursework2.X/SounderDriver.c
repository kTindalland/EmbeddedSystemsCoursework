#include <xc.h>

void InitialiseSounder()
{
    TRISC = 0;
}

void BeepSounder(short time)
{
    for (short i = 0; i < time; i++)
    {
        PORTC = 1;
    }
    PORTC = 0;
}