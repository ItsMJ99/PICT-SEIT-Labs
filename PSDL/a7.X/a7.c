#include<pic18f4550.h>
#include<xc.h>

void delay(){
    for(int i=0;i<1000;i++){
        for(int j=0;j<1000;j++);
    }
}

int main(void){
    PR2=250;
    CCPR1L=0;
    CCP1CON=12;
    TMR2=0;
    TRISB=0;
    PORTB=0x55;
    T2CON=0;
    TRISCbits.TRISC2=0;
    T2CONbits.TMR2ON=1;
    while(1){
        for(int i=0;i<=250;i+=50){
            CCPR1L=i;
            PORTB=~PORTB;
            delay();
        }
    }
    return 0;
}
