#include<xc.h>
#include "External_interrupt.h"

void External_interrupt(void)
{
        INT0IF=0;
        INT0IE=1;
        INTEDG0=1;
}
