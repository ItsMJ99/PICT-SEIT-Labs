#include<xc.h>
//#include<pic18f458.h>
//#include<stdlib.h>
//#include<stdio.h>

void main(){
    int sum=0;
    int val[100];
    for(int i=0;i<100;i++){
        val[i]=3;
        sum+=val[i];
    }
    TMR1=sum;
    return;
}
