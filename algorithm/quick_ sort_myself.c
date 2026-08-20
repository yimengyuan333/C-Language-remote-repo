#include <stdio.h>
#define LEN 8
int a[LEN] = { 5, 2, 4, 7, 1, 3, 2, 6 };

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
    a[start] = a[j];
    a[j] = pivot;
    return j;
}

void quick_sort(int start, int end){
    if(start < end){
        int mid = partition(start, end);
        quick_sort(start, mid - 1);
        quick_sort(mid + 1, end);
    }
}