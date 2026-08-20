#include<stdio.h>
#include<stdlib.h>

size_t size = 1024 * 1024 * 100; //每次100MB
int main(void){
    int i = 0;
    while (1)
    {
    void * p = malloc(sizeof(size));
    i++;
    printf("Allocated memory %d times, 100 bytes per allocation\n",i);
    }
    return 0;
}