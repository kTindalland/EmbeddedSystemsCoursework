#include <xc.h>

void initialiseSounder()
{
    TRISC = 0;
}

void beepSounder(int time)
{
    for (int i = 0; i < time; i++)
    {
        PORTC = 1;
    }
    PORTC = 0;
}
