#include<xc.h>
#include<stdlib.h>
#include<stdio.h>
#include<pic18f458.h>

void main(){
    int ch=0x1;
    TMR1H=0x3;
    TMR1L=0x2;
    while(1){
        TRISB=0;
        TRISC=0;
        if(ch==1){
            TMR0=TMR1H*TMR1L;
            PORTB=TMR0H;
            PORTC=TMR0L;
        }
        else if(ch==2){
            PORTB = TMR1L % TMR1H;
            PORTC = TMR1L / TMR1H;
        }
    }
    return;
}

