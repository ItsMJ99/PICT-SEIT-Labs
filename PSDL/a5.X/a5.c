//ASSIGNMENT 5 TMR1 programming with ISR to switch buzzer on for 0.255 and off for 1s continuously.

/*these include the header files so that 
all necessary registers and settings for 
particular PIC and XC compiler is loaded */ 
#include<xc.h>
#include<pic18f4550.h>

int buzz=0;//controls buzzer if set to 1 it is ON
int count=0;//counts the number of interrupts

//__interrupt() specifies that it is an interrupt handler and
//the buzz() function is ISR for handling timer 1 interrupt
void __interrupt() buzzbeep(){
    //this checks if PIR1.TMR1 interrupt flag is set if it is set then timer 1 overflow
    //interrupt has occurred
    if(PIR1bits.TMR1IF==1){
        //INTCONbits.GIE=0;
        if(buzz&&count==10){//checks if buzz is non zero  and count = 10
            buzz=0;
            PORTAbits.RA5=0;
            count=0;
        }
        if(!buzz&&count==40){//checks if buzz is zero  and count = 40 if both met then buzzer is on
            buzz=1;
            PORTAbits.RA5=1;
            count=0;
        }
        count++;
        PIR1bits.TMR1IF=0;//this clears the TIMER1 INTERRUPT FLAG acknowledging the interrupt
        TMR1=28038;//It determines the initial value from which the timer will start counting.
        //INTCONbits.GIE=1;
    }
}

int main(void){
    T1CON=0xB0;
    TRISAbits.TRISA5=0;// configuring pin RA5 as an output pin.
    PORTAbits.RA5=0;// clearing the output on pin RA5.
    PIE1bits.TMR1IE=1;// It enables Timer 1 overflow interrupts.
    PIR1bits.TMR1IF=0;//This clears the Timer 1 interrupt flag.It ensures any previous Timer 1 interrupt events are cleared.
    INTCONbits.PEIE=1;//These lines enable peripheral interrupts (PEIE) and 
    INTCONbits.GIE=1;//global interrupts (GIE) by setting the corresponding bits in the INTCON register.
    T1CONbits.TMR1ON=1;//This enables Timer 1 by setting the Timer
    while(1);
    return 0;
}

/*By enabling both PEIE and GIE, the program ensures that the microcontroller is ready to handle Timer 1 
 * overflow interrupts by allowing peripheral interrupts and enabling their execution at the global level.*/