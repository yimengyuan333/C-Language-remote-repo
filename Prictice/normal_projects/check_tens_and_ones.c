#include<stdio.h>
int check_tens_and_ones(int number){
    if(number >= 10){
    printf("the tens place is %d.\n",number/10);
    printf("the ones place is %d.\n",number%10);
    }
    else{
    printf("no tens.\n");
    printf("the ones place is %d.\n",number);
    }
return 0 ;
}

int main(void){
    printf("please enter a number.\n");
    int number = 0;
    scanf("%d",&number);
    check_tens_and_ones(number);
    return 0 ;
}