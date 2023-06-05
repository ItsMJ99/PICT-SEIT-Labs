#include<xc.h>
#include<pic18f4550.h>

void Delay(){
    T0CON=0x07;
    TMR0=18662;
    T0CONbits.TMR0ON=1;
    INTCONbits.TMR0IF=0;
    
    while(INTCONbits.TMR0IF==0);
    T0CONbits.TMR0ON=0;
    INTCONbits.TMR0IF=0;
    return;
}

int main(void){
    TRISB=0;
    PORTB=0x55;
    while(1){
        PORTB=~PORTB;
        Delay();
    }
    return 0;
}

//#include <xc.h>
//void Delay();
//void main(void) 
//{
//    TRISB = 0;
//    PORTB = 0x55;
//    while(1)
//    {
//        PORTB = ~ PORTB;
//        Delay();
//    }
//    return;
//}
//
//void Delay()
//{
//    T0CON = 0x07;
//    TMR0 = 18661;
//    T0CONbits.TMR0ON=1;
//    INTCONbits.TMR0IF = 0;
//    
//    while(INTCONbits.TMR0IF==0);
//    T0CONbits.TMR0ON=0;
//    INTCONbits.TMR0IF = 0;    
//    return;
//}