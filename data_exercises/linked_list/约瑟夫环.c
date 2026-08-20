#include <stdio.h>
#include <stdlib.h>

typedef struct node *link;
struct node {
    int num;        // 编号
    link next;      // 指向下一个节点
};

link create_circle(int n)
{
    link head = NULL;
    link tail = NULL;

    for (int i = 1; i <= n; i++) {
        link p = malloc(sizeof(struct node));
        p->num = i;
        p->next = NULL;

        if (head == NULL) {
            head = tail = p;
        } else {
            tail->next = p;
            tail = p;
        }
    }

    // 形成环：尾节点指向头节点
    tail->next = head;
    return head;
}

void josephus(int n, int m)
{
    link head = create_circle(n);
    link prev = NULL;
    link curr = head;

    printf("被杀者顺序：");

    // 当环中还有节点时继续
    while (curr->next != curr) {   // 只剩一个节点时退出
        // 数到第 m 个人
        for (int i = 1; i < m; i++) {
            prev = curr;
            curr = curr->next;
        }

        // 杀掉当前节点
        printf("%d ", curr->num);

        // 从环中删除 curr
        prev->next = curr->next;
        free(curr);

        // 从下一个节点继续数
        curr = prev->next;
    }

    printf("\n幸存者：%d\n", curr->num);
    free(curr);
}