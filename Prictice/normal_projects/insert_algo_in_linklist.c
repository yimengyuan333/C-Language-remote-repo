#include <stdio.h>
#include <stdlib.h>

typedef struct node *link;
struct node {
    unsigned char item;
    link next;
};

static link head = NULL;
static link tail = NULL;   // 仅用于队列

link make_node(unsigned char item)
{
    link p = malloc(sizeof *p);
    p->item = item;
    p->next = NULL;
    return p;
}

void insert_sorted(link p)
{
    link prev = NULL;      // prev 指向当前节点的前一个节点
    link curr = head;      // curr 从链表头部开始遍历

    while (curr != NULL && curr->item < p->item) {
        prev = curr;       // prev 跟上当前节点
        curr = curr->next; // curr 移到下一个节点
    }

    /*
     * 插入操作：
     * 1. p->next 指向 curr（当前节点或 NULL）
     * 2. 判断 prev 是否为 NULL
     *    - 如果 prev == NULL，说明 p 应该插入到链表头部
     *    - 否则插入到 prev 和 curr 之间
     */
    p->next = curr;
    if (prev == NULL) {
        head = p;          // 插入到头部
    } else {
        prev->next = p;    // 插入到中间或尾部
    }
}