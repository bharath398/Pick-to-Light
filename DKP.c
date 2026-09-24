#include <xc.h>
#include "DKP.h"
void init_DKP()
{
    TRISC=TRISC|0x0F;
}
unsigned int read_DKP(char detection_type)
{
    static unsigned char once=1;
 if(detection_type==STATE_CHANGE)
  {
    if(((KEY_PORT & INPUT_PINS)!= All_released) && once)
    {
              once=0;
              return  (KEY_PORT & INPUT_PINS);   
    }
    else if((KEY_PORT & INPUT_PINS )== All_released)
    {
        once=1;
    }
   }
    return 0xff;
}
