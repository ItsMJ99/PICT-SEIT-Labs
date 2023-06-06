//ASSIGNMENT 7 PWM for rotating a DC motor at different speed

/*these include the header files so that 
all necessary registers and settings for 
particular PIC and XC compiler is loaded */ 
#include<pic18f4550.h>
#include<xc.h>

void delay(){
    for(int i=0;i<1000;i++){
        for(int j=0;j<1000;j++);
    }
}

int main(void){
    PR2=250;//PR2 is used in conjunction with TMR2 for PWM generation and determines the period of the PWM signal.
    CCPR1L=0;//which determines the duty cycle of the PWM signal. By setting it to 0 initially, the PWM output will be off.
    CCP1CON=12;//This line configures the CCP1CON register. The value 12 (0b00001100) sets the CCP1 module to PWM mode with active high output.
    TMR2=0;//ensuring that the timer starts counting from the beginning.
    TRISB=0;
    PORTB=0x55;//This line initializes PORTB with the value 0x55 (binary 01010101), which alternates the output pins high and low.
    T2CON=0;// disabling any prescaler and setting the timer to operate in normal mode.
    TRISCbits.TRISC2=0;//This line configures pin RC2 as an output by setting TRISC2 bit of TRISC register to 0.
    T2CONbits.TMR2ON=1;//This starts the timer and enables the PWM operation.
    
    /*This is the main loop of the program. It repeatedly loops through the duty cycle values from 0 to 250 with a step size of 50. 
     * It sets the duty cycle using CCPR1L register, toggles the output state of PORTB using the bitwise negation (~) operator, 
     * and introduces a delay between each change in duty cycle.*/
    while(1){
        for(int i=0;i<=255;i+=50){
            CCPR1L=i;
            PORTB=~PORTB;
            delay();
        }
    }
    return 0;
}
