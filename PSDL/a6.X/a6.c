//ASSIGNMENT 6 external interrupt given at switch generating an output at relay

/*these include the header files so that 
all necessary registers and settings for 
particular PIC and XC compiler is loaded */ 
#include<pic18f4550.h>
#include<xc.h>

//this function generates a delay it depends on the hardware and CPU speed/performance.
void delay(){
    for(int i=0;i<2000;i++){
        for(int j=0;j<2000;j++);
    }
}

//This is the Interrupt Service Routine for handling the INT1 external interrupt. 
void __interrupt() relay(){
    //it checks if the INT1 interrupt flag is set. If it is set (indicating an interrupt event occurred on INT1 pin).
    if(INTCON3bits.INT1IF==1){
        INTCONbits.GIE=0;//Disables global interrupts to prevent further interrupts during the ISR execution.
        PORTAbits.RA4=1;
        delay();
        PORTAbits.RA4=0;
    }
    INTCON3bits.INT1IF=0;//After performing the necessary actions, it clears the INT1 interrupt flag to acknowledge the interrupt event and prevent retriggering.
    INTCONbits.GIE=1;//it enables global interrupts again
}

int main(){
    TRISAbits.TRISA4=0;
    TRISBbits.TRISB1=1;//configures the RB1 pin (INT1 pin) as an input by setting the corresponding TRISB register bit.
    INTCON2bits.INTEDG1=0;//When a falling edge is detected on the INT1 pin, the interrupt will be triggered.
    INTCON3bits.INT1IF=0;// clears the INT1 interrupt flag to ensure a clean start.
    INTCON3bits.INT1IE=1;//enables the INT1 external interrupt.
    INTCONbits.PEIE=1;//enables peripheral interrupts.
    INTCONbits.GIE=1;//enables global interrupts.
    while(1);
    return 0;
}

