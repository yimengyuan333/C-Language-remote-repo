#include <stdio.h>

#define MAX_ROW 5
#define MAX_COL 5
#define QUEUE_SIZE 128

struct point { int row, col, predecessor; } queue[QUEUE_SIZE];
int head = 0, tail = 0;

void enqueue(struct point p)
{
	if ((tail + 1) % QUEUE_SIZE == head) {
        printf("队列已满！\n");
        return;
    }
    queue[tail] = p;
    tail = (tail + 1) % QUEUE_SIZE;
}

struct point dequeue(void)
{
	struct point out_element;
    if (head == tail){
        printf("队列为空。\n");
        /*队列为空就不用出队了，没得出了，head和tail中间留的一个空间
          是环形队列的底裤，但不出编译器会说没返回值，随便出个没用的东西*/
          return (struct point){-1, -1, -1};
    }
    out_element = queue[head];
    head = (head + 1) % QUEUE_SIZE;
    return out_element;
}

int is_empty(void)
{   
    return head == tail;
}

int is_full(void) {
    return (tail + 1) % QUEUE_SIZE == head;
}

int maze[MAX_ROW][MAX_COL] = {
	0, 1, 0, 0, 0,
	0, 1, 0, 1, 0,
	0, 0, 0, 0, 0,
	0, 1, 1, 1, 0,
	0, 0, 0, 1, 0,
};

void print_maze(void)
{
	int i, j;
	for (i = 0; i < MAX_ROW; i++) {
		for (j = 0; j < MAX_COL; j++)
			printf("%d ", maze[i][j]);
		putchar('\n');
	}
	printf("*********\n");
}

void visit(int row, int col)
{
	struct point visit_point = { row, col, head-1 };
	maze[row][col] = 2;
	enqueue(visit_point);
}

int main(void)
{
    struct point p = { 0, 0, -1 };

	maze[p.row][p.col] = 2;
	enqueue(p);
	
	while (!is_empty()) {
        p = dequeue();
		if (p.row == MAX_ROW - 1  /* goal */
		    && p.col == MAX_COL - 1)
			break;
		if (p.col+1 < MAX_COL     /* right */
		    && maze[p.row][p.col+1] == 0)
			visit(p.row, p.col+1);
		if (p.row+1 < MAX_ROW     /* down */
		    && maze[p.row+1][p.col] == 0)
			visit(p.row+1, p.col);
		if (p.col-1 >= 0          /* left */
		    && maze[p.row][p.col-1] == 0)
			visit(p.row, p.col-1);
		if (p.row-1 >= 0          /* up */
		    && maze[p.row-1][p.col] == 0)
			visit(p.row-1, p.col);
		print_maze();
	}
	if (p.row == MAX_ROW - 1 && p.col == MAX_COL - 1) {
		printf("(%d, %d)\n", p.row, p.col);
		while (p.predecessor != -1) {
			p = queue[p.predecessor];
			printf("(%d, %d)\n", p.row, p.col);
		}
	} else
		printf("No path!\n");
    if (is_full())
        printf("队列空间已出现覆盖，数据无效，需扩容。\n");
    
	return 0;
}