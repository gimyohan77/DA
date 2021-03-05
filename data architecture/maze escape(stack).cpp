#include <stdio.h>
#include <stdlib.h>
#include <stack>

#define MAX_STACK_SIZE 100

typedef struct {
	int short row;
	int short col;
	int short dir;
} element;

element stack[MAX_STACK_SIZE];
int top = -1;

typedef struct {
	int short vert;
	int short horiz;
}offsets;

offsets move[8];

void push(element item)
{
	if (top >= MAX_STACK_SIZE - 1)
		stackFull();
	stack[++top] = item;
}

void stackFull()
{
	fprintf(stderr, "Stack is full, cnnot add element");
	exit(EXIT_FAILURE);
}

element pop()
{
	if (top == -1)
		return;
	return stack[top--];
}

int main()
{
	FILE* in, * out;
	int** maze, ** mark;
	int m, n, i, j;
	int s, t, u, v;
	element position;

	move[0].vert = -1;
	move[0].horiz = 0;
	move[1].vert = -1;
	move[1].horiz = 1;
	move[2].vert = 0;
	move[2].horiz = 1;
	move[3].vert = 1;
	move[3].horiz = 1;
	move[4].vert = 1;
	move[4].horiz = 0;
	move[5].vert = 1;
	move[5].horiz = -1;
	move[6].vert = 0;
	move[6].horiz = -1;
	move[7].vert = -1;
	move[7].horiz = -1;



	fopen_s(&in, "in.txt", "r");
	fopen_s(&out, "out.txt", "w");
	
	fscanf_s(in, "%d %d", &m, &n);

	maze = (int**)malloc(sizeof(*maze) * m);
	mark = (int**)malloc(sizeof(*mark) * m);
	for (i = 0;i < m;i++)
	{
		maze[i] = (int*)malloc(n * sizeof(**maze));
		mark[i] = (int*)malloc(n * sizeof(**mark));
		for (j = 0;j < n;j++)
		{
			fscanf_s(in, "%d", &maze[i][j]);
			mark[i][j] = 0;
		}
	}

	printf("Scanf ют╥б\n");
	scanf_s("%d %d %d %d", &s, &t, &u, &v);


	int row, col, next_row, next_col, dir, found = false;
	mark[s][t] = 1;
	top = 0;
	stack[0].row = s; stack[0].col = t; stack[0].dir = 0;

/*	while (top > -1 && !found)
	{
		pop();
		row = position.row;
		col = position.col;
		dir = position.dir;
		while (dir < 8 && !found)
		{
			next_row = row + move[dir].vert;
			next_col = col + move[dir].horiz;
			if (next_row == u && next_col == v) found = true;
			else if (!maze[next_row][next_col] && !mark[next_row][next_col])
			{
				mark[next_row][next_col] = 1;
				position.row = row;
				position.col = col;
				position.dir = ++dir;
				push(position);
				row = next_row; col = next_col; dir = 0;
			}
			else ++dir;
		}
	}

	if (found)
	{
		printf("the path is:\n");
		printf("row col");
		for (i = 0;i <= top;i++)
		{
			printf("%2d%5d", stack[i].row, stack[i].col);
			printf("%2d%5d", row, col);
			printf("%2d%5d", u, v);
		}
	}
	else printf("the maze does not have a path");
	*/
	return 0;



}