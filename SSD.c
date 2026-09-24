#include<xc.h>
void init_confi()
{
    TRISA=TRISA & 0xF0;
    TRISD=0x00;
}
unsigned int  display(char digit[])
{
    unsigned int i;
    for(i=0;i<4;i++)
    {
        PORTD = digit[i];
        PORTA=((PORTA & 0xF0)|1<<i);
        for(volatile unsigned int wait=1000;wait--;);
    }
    
}
