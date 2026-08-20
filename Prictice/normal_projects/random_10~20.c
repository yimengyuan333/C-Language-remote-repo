#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));   // 初始化随机种子

    for (int i = 0; i < 10; i++) {
        int r = rand() % 11 + 10;
        printf("%d ", r);
    }
    return 0;
}