#include<stdio.h>
#include<stdlib.h>
#include"doublylinkedlist.h"

struct node tail_sentinel;
struct node head_sentinel = {0, NULL, &tail_sentinel};
struct node tail_sentinel = {0, &head_sentinel, NULL};

static link head = &head_sentinel;
static link tail = &tail_sentinel;

link make_node(unsigned char item)
{
    link p = malloc(sizeof(link));
    p->item = item;
    p->next = p->prev = NULL;
    return p;
}

void free_node(link p)
{
    free(p);
}

link search(unsigned char key)
{
	link p;
	for (p = head->next; p != tail; p = p->next)
		if (p->item == key)
			return p;
	return NULL;
}

void insert(link p)         //插到head后面
{
    p->prev = NULL;        // 新节点的 prev 指向 NULL（它将变成头节点）
    p->next = head;        // 新节点的 next 指向旧头节点

    if (head != NULL) {
        head->prev = p;    // 旧头节点的 prev 指向新节点
    }

    head = p;              // 更新头指针为新节点
}

void delete(link p)
{
	p->prev->next = p->next;
	p->next->prev = p->prev;
}

void traverse(void (*visit)(link))
{
	link p;
	for (p = head->next; p != tail; p = p->next)
		visit(p);
}