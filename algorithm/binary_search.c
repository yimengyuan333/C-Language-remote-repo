#include <stdio.h>

int lower_bound(int arr[], int n, int target) {
    int left = 0;
    int right = n;

    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;   // 第一个 >= target 的位置
}

int main(void) {
    int a[10] = {1, 1, 2, 3, 4, 5, 6, 6, 7, 9};

    int pos = lower_bound(a, 10, 6);
    printf("第一个6在第 %d 位\n", pos + 1);

    // 如果要检查 target 是否存在
    if (pos < 10 && a[pos] == 6) {
        printf("找到了\n");
    } else {
        printf("不存在\n");
    }

    return 0;
}