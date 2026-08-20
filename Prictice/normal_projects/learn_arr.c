#include<stdio.h>
int main(void){
    int arr1[] = {1,2,3,4,5};
    int arr2[sizeof(arr1)/sizeof(arr1[0])];
    int length = sizeof(arr1)/sizeof(arr1[0]);
    for(int i = 0;i<length;i++){
        arr2[i] = arr1[i];
        printf("%d\n", arr2[i]);
    }
    return 0;
}