#include<stdio.h>
int is_prime(int n){
    //n为当前正在检测的数字
    if(n < 2&&n >= 0)
        return 0;
    if(n == 2)
        return 1;
    if(n % 2 == 0)
        return 0;
    for(int i = 3;i < n;i+=2){
        if(n % i == 0&&i != n)
            return 0;
    }
    return 1;
}

int main(void){
    printf("接下来将打印2到100的素数。\n");
    for(int i = 2;i < 100;i++){
        if(is_prime(i))
            printf("%d\n",i);
    }
    return 0;
}
