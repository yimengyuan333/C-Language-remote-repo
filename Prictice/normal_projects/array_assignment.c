#include<stdio.h>
int main(void){
    int a[5] = {1,2,3,4,5};
    int b[5] = {6,7,8,9,10};
    int len = sizeof(a)/sizeof(a[0]);
    for(int i = 0;i < len;i++){
        b[i] = a[i];
    }
    for(int i = 0;i < len;i++){
        printf("b[%d] is %d\n",i,b[i]);
    }
}