#include<xc.h>
//or
//#include<pic18f458.h>
//#include<stdlib.h>
//#include<stdio.h>

void main() 
{
    TMR0 = 0x04;
    TMR1 = 0x02;
    
    TRISB = 0;
    PORTB = TMR0 + TMR1;
    TRISC = 0;
    PORTC = TMR0 - TMR1;
    return;
}

/*For 00H or some other kind of value check the SFRs present in Window menu then 
  in SFRs search for your output in PORT/REGISTER,then hover on it which will 
 show a popup with 7 bits use the bits to decimal conversion technique and 
 boom you will get the final result*/