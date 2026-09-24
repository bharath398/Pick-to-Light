/*
 * File:   main.c
 * Author: Bharath
 *
 * Created on 22 February, 2025, 11:06 AM
 */

#include <xc.h>
#include"can.h"
#include"UT1.h"
unsigned char can_payload[13];
extern unsigned char E_UST[5],E_PID[5];
unsigned int flag=0,z,e=0,i,j;
unsigned char a[5],ch;

 void init()
 {
    init_can();
    init_uart();
    GIE=1;
    PEIE=1;
     
 }
   void __interrupt() isr(void)
 {
      if (RCIF == 1)
    {
        if (OERR == 1)
            OERR = 0;
        
        ch = RCREG;
        
        RCIF = 0;
    }
 }
 
 
 

void main(void) {
  
  
    unsigned char ust[5],pid[5];
    init();

    while(1)
    {
       //puts("STOCK DETAILS\n\r");
        if (can_receive())
	    {
        ust[0]=can_payload[D0];
        ust[1]=can_payload[D1];
        ust[2]=can_payload[D2];
        ust[3]=can_payload[D3];
        ust[4]='\0';
        pid[0]=can_payload[D4];
        pid[1]=can_payload[D5];
        pid[2]=can_payload[D6];
        pid[3]=can_payload[D7];
        pid[4]='\0';
        puts("\n\r");
        puts("U_ST: ");
        puts(ust);
        puts("\n\r");
        puts("P_ID: ");
        puts(pid);
        flag=0;
        }
     if(ch=='\r')
    {
       flag++;
       if(flag==1)
       {
       puts("\r\nEnter P_ID:");
       ch='\0';
       }
       else if(flag==2)
       {
           puts("\r\nEnter U_ST:");
           ch='\0';
       }
       else if(flag==3)
       {
           can_transmit();
           puts("\r\nDATA TRANSMITTED");
           ch='\0';
           flag=0;
       }
    }
    
    if(flag==1 && ch!='\0')
    {
     if(ch>='0' && ch<='9' && i<4)
    {
        putch(ch);
        E_PID[i++]=ch;
         ch='\0';
    }
    else if(i==4)
    {
    E_PID[i]='\0';
    i=0;
    }
    }
        
    else if(flag==2 && ch!='\0')
    {
      if(ch>='0' && ch<='9' && i<4)
    {
        putch(ch);
        E_UST[i++]=ch;
         ch='\0';
    }
    else if(i==4)
    {
    E_UST[i]='\0';
    i=0;
    }
    }
  }
            
 return;
}