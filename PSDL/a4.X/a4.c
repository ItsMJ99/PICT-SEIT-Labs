//ASSIGNMENT 4 PIC18F458 interfacing with LED

/*these include the header files so that 
all necessary registers and settings for 
particular PIC and XC compiler is loaded */ 
#include<xc.h>
#include<pic18f4550.h>

void Delay(){
    //higher the prescale more is the delay
    T0CON=0x07;//configures the T0CON with prescaler of 256
    TMR0=18720;//sets the initial value of Timer 0 register (TMR0) to 18720 for delay.
    //above two lines are used for delay
    
    T0CONbits.TMR0ON=1;// turns on Timer 0 by setting the TMR0ON
    INTCONbits.TMR0IF=0;//clears the Timer 0 interrupt flag to ensure it is in the reset state before using it.
    
    while(INTCONbits.TMR0IF==0);//counting till the interrupt occurs or TMR0IF is not set to 1
    T0CONbits.TMR0ON=0;// turns off Timer 0 by clearing the TMR0ON
    INTCONbits.TMR0IF=0;//clears the Timer 0 interrupt flag again to reset it for the next delay.
    return;
}

int main(void){
    TRISB=0;
    PORTB=0x55;//used to set the pattern 55 = 0101 0101
    while(1){
        PORTB=~PORTB;//compliments PORTB values 1010 -> 0101;
        Delay();
    }
    return 0;
}


