#include<stdio.h>
#include<string.h>

char *my_strtok(char *str, char *delim){
    /*实现这个字符串切割的函数，我们需要做4件事情
    1：保存当前字符串的第一个地址start，这个地址要作为返回值
    2：运用strchr函数找出str中第一个分隔符delim，返回它的地址key
    3：保存这个地址的下一个地址key+1，因为下一个地址是下一次切割的起点
       也就是下一个start
    4：将本次start的地址存到一个temp里，更新为下一个start，返回temp地址*/
    static char *save_start = NULL;
    char *key;
    char *temp;

    // 1. 判断是开始新的切分，还是继续切分
    if (str != NULL) {
        save_start = str;
    }

    // 2. 检查是否已经切分完毕
    if (save_start == NULL || *save_start == '\0') {
        return NULL;
    }

    // 3. 跳过分隔符
    while (*save_start && strchr(delim, *save_start)) {
        save_start++;   //能在delim中找到当前start则为1，说明当前start为分隔符
    }
    if (*save_start == '\0') {
        return NULL;
    }

    // 4. 找到第一个分隔符的位置
    temp = save_start;           // 保存当前令牌的起始地址
    key = save_start;
    while (*key && !strchr(delim, *key)) {
        key++;
    }

    // 5. 处理查找到的分隔符（对应你的第3、4步）
    if (*key != '\0') {
        *key = '\0';             // 把分隔符替换成 '\0'，截断字符串
        save_start = key + 1;    // 更新下一次切割的起点
    } else {
        // 没有找到分隔符，说明是最后一个令牌了
        save_start = key;        // 指向末尾的 '\0'
    }

    // 6. 返回当前令牌
    return temp;
}