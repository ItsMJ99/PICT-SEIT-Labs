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
    TMR1=0x3A;
    TMR2=0xAE88;
    
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

/*Hex multiplication
 
        A   5   7   1
    x           D   8
    5   2   B   8   8
8   6   6   B   D   X 
perform the multiplication of each if value is >15 then subtract 16xN less than each multiplication 
then add N as carry to next bits multiplication and then perform the same step,after that at 
final perform addition of answer columns to get final answer*/

/*Hex division
 form a table of divisor then based on the table use values and find the quotient and remainder*/