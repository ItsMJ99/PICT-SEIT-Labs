//ASSIGNMENT 1 Addition and Subtraction

/*these include the header files so that 
all necessary registers and settings for 
particular PIC and XC compiler is loaded */ 
#include<xc.h>
#include<pic18f458.h>

int main(){
    TMR0=0xA7;
    TMR1=0x3F;
    TRISB=0;//configures PORTB as output PORT.
    PORTB=TMR0+TMR1;

    TRISC=0;//configures PORTC as output PORT.
    PORTC=TMR0-TMR1;
    return 0;
}

/*hex addition if sum is >15 then subtract 16 from the sum and add 1 to next bits sum*/
/*hex subtraction if diff is negative then add 16 to diff and subtract 1 from next bits subtraction*/

/*c1
 * A 7
  +3 F
   E 6 -- as 7+15=22 so 22-16 = 6 and 1 carry to next sum*/

/*b1 16
 * A 7
  -3 F
   6 8 -- as 7-15=-8 so -8+16 = 8 and borrow 1 from next bit*/