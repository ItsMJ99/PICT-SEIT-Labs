//ASSIGNMENT 2 ARRAY

/*these include the header files so that 
all that all necessary registers and settings for 
particular PIC and XC compiler is loaded */      
#include<xc.h>
#include<pic18f458.h>

/*main function which is also called the driver function
int is mainly used so we have to return 0*/ 
int main(void){
    
    //declares an int array of 100 size
    int arr[100];
    //declares int sum which will store the sum of array values
    int sum;
    
    /*BANK SELECT REGISTER is used to select memory bank for accessing data
    it is set to 0x00, which selects the Bank 0.*/
    BSR=0x00;
    
    //0 to 99 = 100
    for(int i=0;i<100;i++){
        arr[i]=1;//all values in the array will be 1
        sum+=arr[i];//each value is added to sum
    }
    
    //BSR is set to 0x01, which selects Bank 1. 
    //This changes the memory bank for accessing data.
    BSR=0x01;
    
    /*The sum value is assigned to the TMR0 register. 
     * TMR0 is a timer register, and here it is assigned the value of the sum.
    tmr0 size = 8bits counts from 0 to 255*/
    TMR0=sum;
    
    //reinitialized value to 100
    sum=100;
    
    //ends the program
    return 0;
}

