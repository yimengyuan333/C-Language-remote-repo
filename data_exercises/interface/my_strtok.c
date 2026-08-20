#include<stdio.h>
#include<string.h>

char *my_strtok(char *str, char *delim){

    static char *start = NULL;
    char *key;
    char *result;

    if(str != NULL)
        start = str;

    if(*start == '\0')
        return NULL;
    
    while(*start != '\0' && strchr(delim, *start))
        start++;
    if(*start == '\0')
        return NULL;
    
    result = start;
    key = start;

    while (*key != '\0' && strchr(delim, *key))
    {
        key++;
    }
    
    if(*key != '\0'){
        *key = '\0';
        start = key + 1;
    }else{
        start = key;            //此时*key = '\0'，赋给start是使得下一次调用无效，因为所有工作以及做完了
    }

    return result;
}

