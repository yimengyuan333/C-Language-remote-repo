#include<stdio.h>
unsigned int rotate_right(unsigned int x, int n){
    n = n % 32;
    return (x >> n) | (x << (32 - n));
}