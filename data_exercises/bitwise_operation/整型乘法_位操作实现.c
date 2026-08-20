#include<stdio.h>
//比如(11011)2×(10010)2=((11011)2<<1)+((11011)2<<4)
int countbit(unsigned int x){
    if (x > 4294967295){
        printf("超出范围，请重试。\n");
    }
    unsigned int b;
    int which_sit = 0, how_many_1 = 0;
    for (which_sit; which_sit < 32; which_sit++){
        b = (x >> which_sit) & 1;
        if (b == 1)
            how_many_1++;
    }
    return how_many_1;
}
/*打算调用上面的函数来求出how_many_1，然后以其为长度建立数组，即最后需要相加几项
  数组用于存放每一项需要移动的位数，这个数组是用于实现累加的，需要一个数据结构记住数据。*/
unsigned int multiply(unsigned int x, unsigned int y){
    int how_many_1 = countbit(y);
    int the_sit_now = 0, arr_index = 0, result = 0;
    unsigned int is_one = 0;
    int arr[how_many_1];
    for (the_sit_now = 0; the_sit_now < 32; the_sit_now++){
        is_one = (y >> the_sit_now) & 1;
        if (is_one == 1){
            arr[arr_index] = the_sit_now;
            arr_index++;
        }
    }
    for (int i = 0; i < how_many_1; i++){
        result = result + (x << arr[i]);
    }
    return result;
}