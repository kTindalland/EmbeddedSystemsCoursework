#include <xc.h>

void InitialiseSounder()
{
    TRISC = 0;
}

void BeepSounder(int time)
{
    for (int i = 0; i < time; i++)
    {
        PORTC = 1;
    }
    PORTC = 0;
}