#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LINE 128

// 日志记录结构
typedef struct record *link;
struct record {
    int num;              // 序号
    char date[16];        // 日期
    char time[16];        // 时间
    link next;            // 链表指针
};

// 从文件中读取所有记录，创建链表（按文件原有顺序）
link read_records(const char *filename)
{
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("fopen");
        return NULL;
    }

    link head = NULL;
    link tail = NULL;
    char line[MAX_LINE];

    while (fgets(line, sizeof(line), fp) != NULL) {
        link p = malloc(sizeof(struct record));
        if (p == NULL) {
            perror("malloc");
            exit(1);
        }

        // 解析一行：序号 日期 时间
        sscanf(line, "%d %s %s", &p->num, p->date, p->time);
        p->next = NULL;

        if (head == NULL) {
            head = tail = p;
        } else {
            tail->next = p;
            tail = p;
        }
    }

    fclose(fp);
    return head;
}

// 比较两条记录的时间先后
// 返回 1 表示 a 的时间晚于 b（a 应该排在 b 后面）
int is_later(link a, link b)
{
    // 先比较日期，再比较时间
    int date_cmp = strcmp(a->date, b->date);
    if (date_cmp != 0) {
        return date_cmp > 0;   // 日期更大 → 时间更晚
    }
    return strcmp(a->time, b->time) > 0;   // 时间更大 → 更晚
}

// 插入排序：按时间排序
link sort_records(link head)
{
    if (head == NULL || head->next == NULL) {
        return head;   // 空链表或单节点
    }

    link sorted = NULL;   // 已排序链表头
    link curr = head;     // 当前要插入的节点

    while (curr != NULL) {
        link next = curr->next;   // 保存下一个节点
        link prev = NULL;
        link pos = sorted;

        // 在已排序链表中找插入位置
        while (pos != NULL && is_later(pos, curr)) {
            prev = pos;
            pos = pos->next;
        }

        // 插入 curr
        if (prev == NULL) {
            curr->next = sorted;
            sorted = curr;
        } else {
            curr->next = pos;
            prev->next = curr;
        }

        curr = next;
    }

    return sorted;
}

// 写回文件
void write_records(const char *filename, link head)
{
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        perror("fopen");
        return;
    }

    int new_num = 1;
    link p;
    for (p = head; p; p = p->next) {
        fprintf(fp, "%d %s %s\n", new_num++, p->date, p->time);
    }

    fclose(fp);
}

// 释放链表
void destroy(link head)
{
    link p = head;
    while (p) {
        link q = p;
        p = p->next;
        free(q);
    }
}

int main(int argc, char *argv[])
{
    if (argc != 2) {
        fprintf(stderr, "用法：%s <日志文件>\n", argv[0]);
        return 1;
    }

    const char *filename = argv[1];

    // 1. 读取记录
    link head = read_records(filename);
    if (head == NULL) {
        printf("文件为空或读取失败\n");
        return 1;
    }

    // 2. 排序
    head = sort_records(head);

    // 3. 写回文件（重新编号）
    write_records(filename, head);

    // 4. 释放内存
    destroy(head);

    printf("排序完成\n");
    return 0;
}