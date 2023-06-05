//ASSIGNMENT 3 MENU DRIVEN MULTIPLICATION & DIVISION

/*these include the header files so that 
all that all necessary registers and settings for 
particular PIC and XC compiler is loaded */ 
#include<xc.h>
#include<pic18f458.h>

int main(void){
    //TRIS set all pins of PORTB & PORTC output mode
    TRISB=0;
    TRISC=0;
    
    //assigns hex values to timers
    TMR1=0x02;
    TMR2=0x10;
    
    /*this variable will decide which if statement to execute,in file registers 
     * it can be set to 1 or 2 */
    int choice=0xF;
    
    //infinite while loop
    while(1){
        if(choice==1){
          TMR0=TMR1*TMR2;//It performs the multiplication of TMR1 and TMR2 and stores the result in TMR0.
          PORTB=TMR0H;//It updates the value of PORTB with the MOST significant bits of TMR0.
          PORTC=TMR0L;//It updates the value of PORTC with the LEAST significant bits of TMR0.
        }
        if(choice==2){
            PORTB=TMR2/TMR1;//It calculates the integer division result and updates the value of PORTB.
            PORTC=TMR2%TMR1;// It calculates the modulus operation and updates the value of PORTC.
        }
    }
    return 0;
}