#include <stdio.h>
#include <stdlib.h>
#include <stack>

#define MAX_SIZE 100

typedef struct {
	int row;
	int col;
	int dir;
}element;

element stack[MAX_SIZE];
int top = -1;


element stackEmpty()
{
	fprintf(stderr, "Stack is empty");
	element rtn;
	rtn.col = -1;
	rtn.row = -1;
	rtn.dir = -1;
	return rtn;
}

void stackFull()
{
	fprintf(stderr, "Stack is full");
	exit(EXIT_FAILURE);
}

void push(element item)
{
	if (top >= MAX_SIZE - 1)
		stackFull();
	stack[++top] = item;
}

element pop()
{
	if (top == -1)
		return stackEmpty();
	return stack[top--];
}



typedef struct {
	int vert;
	int horiz;
}offsets;

offsets move[8];

int main()
{
	FILE* in, * out;
	int ** mark;
	char** maze;
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

	maze = (char**)malloc(sizeof(*maze) * m);
	mark = (int**)malloc(sizeof(*mark) * m);
	for (i = 0;i < m;i++)
	{
		maze[i] = (char*)malloc(n * sizeof(**maze));
		mark[i] = (int*)malloc(n * sizeof(**mark));
		for (j = 0;j < n;j++)
		{
			fscanf_s(in, " %c", &maze[i][j]);
			mark[i][j] = 0;
		}
	}

	printf("Scanf 입력\n");
	scanf_s("%d %d %d %d", &s, &t, &u, &v);

	int row, col, next_row, next_col, dir, found = false;
	mark[s][t] = 1;
	top = 0;
	stack[0].row = s;
	stack[0].col = t;
	stack[0].dir = 0;

	while (top > -1 && !found)
	{
		position = pop();
		row = position.row;
		col = position.col;
		dir = position.dir;
		while (dir < 8 && !found)
		{
			next_row = row + move[dir].vert;
			next_col = col + move[dir].horiz;
			if (next_row == u && next_col == v) found = true;
			else if (maze[next_row][next_col] == '0' && mark[next_row][next_col] == 0)
			{
				mark[next_row][next_col] = 1;
				position.row = row;
				position.col = col;
				position.dir = ++dir;
				push(position);
				row = next_row;
				col = next_col;
				dir = 0;
			}
			else ++dir;
		}
		
	}

	for (i = 0;i <= top;i++)
	{
		maze[stack[i].row][stack[i].col] = 'x';
	}
	maze[row][col] = 'x';
	maze[u][v] = 'x';

	fprintf_s(out, "경제통상학부 2016110398 신대희\n");
	for (i = 0;i < m;i++)
	{
		for (j = 0;j < n;j++)
		{
			 fprintf_s(out, "%c", maze[i][j]);
		}
		fprintf_s(out, "\n");
	}
	fclose(in);
	fclose(out);
	free(maze);
	free(mark);
	return 0;

	
}