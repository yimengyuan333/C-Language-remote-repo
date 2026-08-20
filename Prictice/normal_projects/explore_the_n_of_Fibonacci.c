#include<stdio.h>
int Fibonacci(int n){
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;
    return Fibonacci(n-1)+Fibonacci(n-2);
}

int main(void){
    int n = 0;
    printf("爹，输一个整数。\n");
    scanf("%d",&n);
    printf("爹，斐波那契数列的第%d项是%d\n",n,Fibonacci(n));
}