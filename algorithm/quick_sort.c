#include <stdio.h>
#define LEN 8
int a[LEN] = { 5, 2, 4, 7, 1, 3, 2, 6 };

int partition(int start, int end)
{
    int pivot = a[start];          //选第一个元素作为基准元素
    int i = start + 1;             //左指针：指向大于pivot的位置
    int j = end;                   //右指针：从右向左扫描
    int temp;

    while (1) {
        // 左指针向右移动，直到找到 >= pivot 的元素
        while (i <= end && a[i] < pivot) i++;
        // 右指针向左移动，直到找到 <= pivot 的元素
        while (j >= start && a[j] > pivot) j--;

        if (i >= j) break;         //两个指针相遇或交错，结束循环

        //交换 a[i] 和 a[j]
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;

        i++;
        j--;
    }

    //把pivot放到正确位置（j的位置）
    temp = a[start];
    a[start] = a[j];
    a[j] = temp;

    return j;   // pivot 的最终位置
}

void quicksort(int start, int end)
{
	int mid;
	if (end > start) {
		mid = partition(start, end);
		quicksort(start, mid-1);
		quicksort(mid+1, end);
	}
}

int main(void){
    quicksort(0,7);
    printf("%d,%d,%d,%d,%d,%d,%d,%d,\n",a[0],a[1],a[2],a[3],a[4],a[5],a[6],a[7]);
    return 0;
}