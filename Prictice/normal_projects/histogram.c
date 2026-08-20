#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 10
#define N 20

int a[N];
int histogram[MAX];

void gen_rand(int the_up_bound){
    srand(time(NULL));
    for(int i = 0; i < N; i++){
        a[i] = rand() % the_up_bound;
    }
}

int main (void){
    
    for (int i = 0; i < MAX; i++) {
        histogram[i] = 0;
    }

    gen_rand(MAX);

    for (int i = 0; i < N; i++){
        histogram[a[i]]++;
    }

    //想想打印的逻辑
    for(int i = 0; i < MAX; i++){
        printf("%d\t",i);
        for(int j = 0;j < histogram[i]; j++){
            printf("*");
        }
        printf("\n");
    }

}