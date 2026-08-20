#include<stdio.h>
#include<stdlib.h>

typedef struct node *link;
struct node {
    unsigned char item;
    link next;
};

static link head = NULL;
static link tail = NULL;   // 仅用于队列

void enqueue(link p)       // 这个p是要加在队尾的新节点的指针
{
    p->next = NULL;        // p的下一个位置当然是未知的
    if (tail == NULL) {
        head = tail = p;   // 空队列
    } else {
        tail->next = p;    // 尾部插入，让tail先接上p
        tail = p;          // 然后再更新 tail
    }
}

link dequeue(void)
{
    if (head == NULL)
        return NULL;

    link p = head;         // 先把原有的真head存到p
    head = head->next;     // 然后真head移到下一位去

    if (head == NULL)
        tail = NULL;       // 队列变空，tail 也置 NULL

    p->next = NULL;        // 断开原链表关系，但并不影响p这个节点内容
    return p;              // 返回原head的指针
}

void reverse(void)
{
    link prev = NULL;
    link curr = head;
    link next = NULL;

    while (curr != NULL) {
        next = curr->next;   // 保存下一个节点
        curr->next = prev;   // 反转当前节点的指针
        prev = curr;         // prev 前移
        curr = next;         // curr 前移
    }

    head = prev;             // 更新头指针
}