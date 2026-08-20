#include <stdio.h>

int a[10] = {3, 2, 4, 6, 8, 5, 8, 4, 1, 7};

int find_min(int start, int end) {
    // Base Case为区间只有一个元素
    if (start == end) {
        return a[start];
    }

    int mid = (start + end) / 2;

    // 分别找左半和右半的最小值
    int left_min = find_min(start, mid);
    int right_min = find_min(mid + 1, end);

    // 返回更小的那个
    return (left_min < right_min) ? left_min : right_min;
}

int find_second_min() {
    // 1. 先找最小值
    int min = find_min(0,9);

    // 2. 找第二小：比 min 大的最小数
    int second_min = 2147483647;   // 很大的数（可以换成 a[0]）
    for (int i = 0; i < 10; i++) {
        if (a[i] > min && a[i] < second_min) {
            second_min = a[i];
        }
    }

    return second_min;
}

int main(void) {
    int min = find_min(0, 9);
    printf("数组中的最小值是：%d\n", min);
    int second_min = find_second_min();
    printf("数组中第二小的是：%d\n", second_min);
    return 0;
}