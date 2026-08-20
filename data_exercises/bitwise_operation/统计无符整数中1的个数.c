#include<stdio.h>
int countbit(unsigned int x){
    if (x > 4294967295){
        printf("超出范围，请重试。\n");
    }
    unsigned int b, mask = 0x00000001;
    int which_sit = 0, how_many_1 = 0;
    for (which_sit; which_sit < 32; which_sit ++){
        b = (x >> which_sit) & 1;
        if (b == 1)
            how_many_1++;
        mask = mask << 1;
    }
    return how_many_1;
}