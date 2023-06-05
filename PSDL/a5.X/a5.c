#include<pic18f4550.h>
#include<xc.h>

int count=0;
int buzz=0;

void __interrupt() ISR(){
    if(PIR1bits.TMR1IF==1){
        INTCONbits.GIE=0;
        count++;
        if(buzz && count ==40){
            buzz=0;
            PORTAbits.RA5=0;
            count=0;
        }
        if(!buzz && count ==20){
            buzz=1;
            PORTAbits.RA5=1;
            count=0;
        }
        TMR1=28406;
        PIR1bits.TMR1IF=0;
        INTCONbits.GIE=1;
    }
}

int main(void){
    T1CON=0x30;
    TMR1=28406;
    
    TRISAbits.TRISA5=0;
    PORTAbits.RA5=0;
    PIE1bits.TMR1IE=1;
    PIR1bits.TMR1IF=0;
    INTCONbits.PEIE=1;
    INTCONbits.GIE=1;
    T1CONbits.TMR1ON=1;
    while(1);
    return 0;
}
