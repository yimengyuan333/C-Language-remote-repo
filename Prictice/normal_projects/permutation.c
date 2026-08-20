#include<stdio.h>
#define N 3

int a[N] = { 1, 2, 3 };

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void permutation(int start,int n){
    if(start == n){
        for(int i = 0;i < n;i++){
            printf("%d ", a[i]);
        }
        printf("\n");
    }

    for(int i=start;i < n;i++){
        swap(&a[start], &a[i]);
        permutation(start + 1, n);
        swap(&a[start], &a[i]);
    }
    return;
}

int main(void){
    permutation(0,3);
    return 0;
}