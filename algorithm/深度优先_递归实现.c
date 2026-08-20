#include <stdio.h>

#define MAX_ROW 5
#define MAX_COL 5

struct point { int row, col; } stack[512];
int top = 0;

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

enum direction { NONE, UP, DOWN, LEFT, RIGHT };
unsigned char predecessor[MAX_ROW][MAX_COL];

int recursionDFS(int row, int col, int from_dir)
{
	struct point visit_point = { row, col };
	maze[row][col] = 2;
	predecessor[row][col] = from_dir;
    
    print_maze();

    if(row == MAX_ROW - 1 && col == MAX_COL - 1)
        return 1;

    if (col + 1 < MAX_COL && maze[row][col + 1] == 0){
        if(recursionDFS(row, col + 1, LEFT))
            return 1;
    }

    if (col - 1 >= 0 && maze[row][col - 1] == 0){
        if(recursionDFS(row, col - 1, RIGHT))
            return 1;
    }

    if (row + 1 < MAX_ROW && maze[row + 1][col] == 0){
        if(recursionDFS(row + 1, col, UP))
            return 1;
    }

    if (row - 1 >= 0 && maze[row - 1][col] == 0){
        if(recursionDFS(row - 1, col, DOWN))
            return 1;
    }
    return 0;
}

int main(void)
{
	if (recursionDFS(0, 0, NONE)) {
        struct point p = { MAX_ROW - 1, MAX_COL - 1 };
        printf("找到路了。\n");
		printf("(%d, %d)\n", p.row, p.col);         //此处打印的是终点，倒序打印往前推
		while (predecessor[p.row][p.col] != NONE) {
			switch (predecessor[p.row][p.col])
			{
				case UP:    p.row--; break;
        		case DOWN:  p.row++; break;
    			case LEFT:  p.col--; break;
        		case RIGHT: p.col++; break;
			}
			printf("(%d, %d)\n", p.row, p.col);     
		}                                           /*最后一次前驱节点的来自方向不为NONE
                                                    的情况为第一次移动，这一次也会触发while
                                                    因此最后一个printf将输出(0，0)*/
	} else
		printf("No path!\n");

	return 0;
}