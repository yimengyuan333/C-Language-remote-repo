#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

#define MAX_LINE 128

// 获取文件最后一行
char *get_last_line(const char *filename) {
    static char line[MAX_LINE];
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }

    char *last = NULL;
    while (fgets(line, sizeof(line), fp) != NULL) {
        last = line;
    }
    fclose(fp);
    return last;
}

// 解析最后一行的序号
int get_last_number(const char *filename) {
    char *last_line = get_last_line(filename);
    if (last_line == NULL) {
        return 0;
    }

    int n;
    if (sscanf(last_line, "%d", &n) == 1) {
        return n;
    }
    return 0;
}

// 获取当前时间字符串
void get_time_str(char *buf, size_t size) {
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);
    strftime(buf, size, "%Y-%m-%d %H:%M:%S", tm_info);
}

int main(void) {
    FILE *fp = fopen("test.txt", "a");
    if (fp == NULL) {
        perror("fopen");
        return 1;
    }

    // 设置行缓冲，确保每行立即写入
    setvbuf(fp, NULL, _IOLBF, 0);

    int n = get_last_number("test.txt");
    char time_buf[32];

    printf("从序号 %d 开始\n", n + 1);

    while (1) {
        n++;
        get_time_str(time_buf, sizeof(time_buf));
        fprintf(fp, "%d %s\n", n, time_buf);
        fflush(fp);   // 确保写入磁盘
        sleep(1);
    }

    fclose(fp);
    return 0;
}