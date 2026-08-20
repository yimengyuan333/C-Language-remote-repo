#include<stdio.h>
int diamond(int n){
    //此处n是菱形的高度
    if(n % 2 == 0){
        printf("error!\n");
        return 0;
    }
    for (int i = 1; i <= n/2+1; i++) {
        // 打印空格
        for (int j = 1; j <= n/2+1 - i; j++) {
            printf(" ");
        }
        // 打印星号
        for (int j = 1; j <= 2 * i - 1; j++) {
            printf("*");
        }
        printf("\n");
    }
    int mid = n/2+1;
    for (int i = mid - 1; i >= 1; i--) {
        // 打印空格
        for (int j = 1; j <= mid - i; j++) {
            printf(" ");
        }
        // 打印星号
        for (int j = 1; j <= 2 * i - 1; j++) {
            printf("*");
        }
        printf("\n");
    }
    return 1;
}

int main(void){
    int n = 0;
    scanf("%d",&n);
    diamond(n);
    return 0;
}