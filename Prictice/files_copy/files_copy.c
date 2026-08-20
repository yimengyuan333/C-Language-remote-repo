#include<stdio.h>
#include<stdlib.h>

int main(void){
    FILE * src = fopen("file_A.txt", "r");
    FILE * des = fopen("file_B.txt", "w");
    int ch;

    if(src == NULL){
        perror("fopen src_file filed.\n");
        return 1;
    }
    
    if(des == NULL){
        perror("fopen des_file filed.\n");
        return 1;
    }

    while ((ch = fgetc(src)) != EOF) {
        if (fputc(ch, des) == EOF) {
            perror("write filed.\n");
            fclose(src);
            fclose(des);
            exit(1);
        }
    }
    
    if (ferror(src)) {
        perror("读取源文件失败");
        fclose(src);
        fclose(des);
        exit(1);
    }

    fclose(src);
    fclose(des);

    printf("复制成功\n");
    return 0;

}