#include<xc.h>
#include "INTERNAL_EEPROM.h"
 unsigned char read_internal_eeprom(unsigned char address)
 {
        EEADR=address;
        
        EECON1bits.WREN=0;
        
        EECON1bits.CFGS=0;
        
        EECON1bits.EEPGD=0;
        
        EECON1bits.RD=1;
        
        return EEDATA;
        
  }
 void write_internal_eeprom(unsigned char address,unsigned char data)
 {
     EEADR=address;
     
     EEDATA=data;
     
     EECON1bits.CFGS=0;
        
     EECON1bits.EEPGD=0;
     
     EECON1bits.WREN=1;
     
     GIE=0;
     
     EECON2 = 0x55;
	 EECON2 = 0xAA;
     
     EECON1bits.WR=1;
     
     GIE=1;
     
     
     while (!PIR2bits.EEIF);
	 PIR2bits.EEIF = 0;
     
 }