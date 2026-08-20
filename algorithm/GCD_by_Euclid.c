#include<stdio.h>
int explore_divisor(int a,int b){
    if(a<0)
        a = -a;
    if(b<0)
        b = -b;    
    int GCD = 0;
    if(b == 0)
        return a;
    if(a % b == 0){
        return b;
    } 
    return explore_divisor(b,a%b);
}

int main(void){
    int a = -10,b = -90;
    printf("the GCD of -10 and -90 is: %d .\n",explore_divisor(a,b));
    return 0;
}