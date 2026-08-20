#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 20

int a[N];

void gen_random(int upper_bound)
{
	int i;
	for (i = 0; i < N; i++)
		a[i] = rand() % upper_bound;
}

int howmany(int value)
{
	int count = 0, i;
	for (i = 0; i < N; i++)
		if (a[i] == value)
			++count;
	return count;
}

int main(void){
    int i, histogram[10] = {0};
    gen_random(10);
    for(i=0;i<N;i++){
		histogram[a[i]]++;
	}

	int numbers = 0;
	for(numbers = 0; numbers < 10; numbers++){
		printf("%d : ", numbers);
		for(i=0;i<histogram[numbers];i++){
			printf("*");
		}
		printf("\n");
	}
}