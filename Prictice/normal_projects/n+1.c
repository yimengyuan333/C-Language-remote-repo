#include<stdio.h>
int n_add_1 (int a){
    a = a+1;
    return a ;
}
int main(void){
    int a = 1 ;
    a = n_add_1(a);
    printf("%d",a);
    return 0 ;
}