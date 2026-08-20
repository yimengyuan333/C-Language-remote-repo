#include<stdio.h>
int mypow(int x, int n){                  //mypow函数的设计本意是返回x^2
    if(n == 0)
        return 1;
    double half_of_power = mypow(x, n/2);
    if(n % 2 ==0)
        return mypow(half_of_power, 2);         
    else
        return x*mypow(half_of_power, 2);/*优化：此处用了嵌套调用，half of power本就是递归结果
                                           现在每次递归调用的时候又递归调用了一整遍*/
}                               
