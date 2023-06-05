/*
 * File:   rel.c
 * Author: mplab-14
 *
 * Created on 12 May, 2023, 9:47 AM
 */


#include <xc.h>
#include <pic18f4550.h>
void __interrupt() relay()
{
    int count=0;
    int buzz=0;
    if(INTCON3bits.INT1IF=1)
    {
        if(buzz && count == 50){
            buzz=0;
            PORTAbits.RA5=0;
            count=0;
        }
        if(!buzz && count==100){
            buzz=1;
            PORTAbits.RA5=1;
            count=0;
        }
        count++;
        INTCONbits.GIE=0;
        PORTAbits.RA4=1;
        for(int i=0;i<100;i++)
        { for(int j=0;j<100;j++);
        }
        PORTAbits.RA4=0;
        INTCON3bits.INT1IF=0;
        INTCONbits.GIE=1;
           
    }
}
void main(void) {
    TRISBbits.RB1=1;
    TRISAbits.RA4=0;
    TRISAbits.RA5=0;
    INTCON3bits.INT1IF=0;
    INTCON3bits.INT1E=1;
    INTCON2bits.INTEDG1=0;
    INTCONbits.PEIE=1;
    INTCONbits.GIE=1;
    while(1);
    return;
}
