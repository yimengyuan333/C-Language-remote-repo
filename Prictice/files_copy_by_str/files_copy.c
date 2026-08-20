#include<stdio.h>
#include<stdlib.h>
#include<errno.h>

int main(void){
    FILE * src = fopen("file_A.txt", "r");
    FILE * des = fopen("file_B.txt", "w");
    char buf[256]; 

    if(src == NULL){
        perror("fopen filed.\n");
        fclose(src);
        fclose(des);
        exit(1);
    }
    
    if(des == NULL){
        perror("fclose filed.\n");
        fclose(src);
        fclose(des);
        exit(1);
    }

    while(fgets(buf, sizeof(buf), src) != NULL){
        if(fputs(buf, des) == EOF){
            perror("copy filed.\n");
            fclose(src);
            fclose(des);
            exit(1);
        }
    }
    
    if (ferror(src))
    {
        perror("read src filed.\n");
        fclose(src);
        fclose(des);
        exit(1);
    }

    fclose(src);
    fclose(des);
    return 0;
}