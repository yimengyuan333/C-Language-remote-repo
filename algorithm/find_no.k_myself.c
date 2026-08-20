#include<stdio.h>

int a[10] = {3,4,2,5,6,7,3,6,3,9};

int partition(int start, int end){
    int pivot = a[start];
    int i = start + 1;
    int j = end;
    int temp;
    while (1)
    {
        while(i <= end && a[i] <= pivot)
            i++;
        while(j >= start + 1 && a[j] >= pivot)
            j--;
        if(i >= j)
            break;
        
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;

        i++;
        j--;
    }
    temp = a[j];
    a[j] = pivot;
    a[start] = temp;
    return j;
}

int find_k(int start, int end, int k){
    if (start <= end) {
        int pivot_index = partition(start, end);
        int rank = pivot_index - start + 1;

        if (k == rank) {
            return a[pivot_index];
        } else if (k > rank) {
            return find_k(pivot_index + 1, end, k - rank);
        } else {
            return find_k(start, pivot_index - 1, k);
        }
    }
    return -1; // 安全回退
}

int main(void){
    printf("第3小的数是： %d 。\n",find_k(0,9,3));
    return 0;
}