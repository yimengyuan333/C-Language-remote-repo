#include <stdio.h>

#define LEN 10
int a[LEN] = {3, 2, 4, 6, 8, 5, 8, 4, 1, 7};

// 交换两个数
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// partition 函数：选 a[start] 为 pivot，分成左右两半，返回 pivot 最终位置
int partition(int start, int end) {
    int pivot = a[start];
    int i = start + 1;
    int j = end;

    while (1) {
        while (i <= end && a[i] < pivot) i++;
        while (j >= start && a[j] > pivot) j--;
        if (i >= j) break;
        swap(&a[i], &a[j]);
        i++;
        j--;
    }

    swap(&a[start], &a[j]);
    return j;   // pivot 的最终位置
}

// 查找第 k 小的元素（k 从 0 开始）
int order_statistic(int start, int end, int k) {
    if (start == end) {
        return a[start];
    }

    int pivot_index = partition(start, end);

    // pivot 在当前区间中的排名（从 start 开始算）
    int rank = pivot_index - start + 1;

    if (k == rank - 1) {          // 因为 k 是从 0 开始算的
        return a[pivot_index];
    } else if (k > rank - 1) {
        return order_statistic(pivot_index + 1, end, k - rank);
    } else {
        return order_statistic(start, pivot_index - 1, k);
    }
}

int main(void) {
    // 输出排序后的数组（验证用）
    printf("原数组：");
    for (int i = 0; i < LEN; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    // 找第 k 小（k 从 0 开始，0 表示最小，1 表示第二小...）
    for (int k = 0; k < LEN; k++) {
        int result = order_statistic(0, LEN - 1, k);
        printf("第 %d 小的元素是：%d\n", k + 1, result);
    }

    return 0;
}