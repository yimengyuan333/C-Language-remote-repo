#include<stdio.h>

double mysqrt(double y){
    double left = 0.0;
    double right = y;
    double mid;
    while (right - left > 0.001)
    {
        mid = (left + right) / 2.0;
        double square = mid * mid;
        if(square > y)
            right = mid;
        else
            left = mid;
    }
    return (left + right) / 2.0;
}

int main(void){
    printf("the number is %.3f \n",mysqrt(2.0));
    return 0;
}