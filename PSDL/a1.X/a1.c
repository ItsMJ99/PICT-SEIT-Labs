#include<xc.h>
#include<pic18f458.h>

int main(){
    TMR0=0xff;
    TMR1=0x05;
    TRISB=0;
    PORTB=TMR0+TMR1;
    
    TMR0=0x0A;
    TMR1=0x05;
    TRISC=0;
    PORTC=TMR0-TMR1;
    return 0;
}
