#include<stdio.h>

int *get_number(void)
  {
      int number = 100;
      return &number;
  }

int main(void){
    int * result = get_number();
    printf("%p",result);
    return 0;

}
