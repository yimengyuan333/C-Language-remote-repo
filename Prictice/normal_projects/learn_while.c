#include<stdio.h>
int explore_divisor(int a,int b){
    if(a<0)
        a = -a;
    if(b<0)
        b = -b;
    while(b!=0){
        int mid = a%b;
        a = b;
        b = mid;
    }
    return a;
}

int Fibonacci(int n){
    if(n == 0)
        return 0;
    if(n == 0)
        return 1;
    
    int a = 0;
    int b = 1;
    int i = 2;
    while(i<=n){
        int next = a + b;
        a = b;
        b = next;
        i++;
    }
    return b;
}

int main(void){
    printf("enter two numbers.\n");
    int a =0;
    int b =0;
    scanf("%d %d",&a,&b);
    printf("the GCD is %d .\n",explore_divisor(a,b));
    printf("now let's explore the Fibonacci sequence.\n");
    int n = 0;
    printf("enter a number.\n");
    scanf("%d", &n);
    printf("the %dth Fibonacci number is %d.\n", n, Fibonacci(n));
    return 0;
}