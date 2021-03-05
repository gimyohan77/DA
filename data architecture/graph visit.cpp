#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
int queue[MAX_SIZE];
int rear = -1;
int front = -1;
int cnt = 0;

void qfull()
{
	fprintf(stderr, "Queue is FUll");
	exit(EXIT_FAILURE);
}

int qempty()
{
	fprintf(stderr, "Queue is Empty");
	return -1;
}

void addq(int item)
{
	if (rear == MAX_SIZE) qfull();
	queue[++rear] = item;
}

int deleteq()
{
	if (front == rear) return qempty();
	return queue[++front];
}

int main()
{
	FILE* in;
	int i, j, n, v;
	int** graphs;
	int* visit;
	int input;

	fopen_s(&in, "in.txt", "r");
	fscanf_s(in, "%d", &n);

	visit = (int*)malloc(sizeof(int) * (n + 1));
	graphs = (int**)malloc(sizeof(*graphs) * (n + 1));

	printf("학부 : 경제통상학부 학번 : 2016110398 이름 : 신대희\n");

	for (i = 0;i < n + 1;i++) visit[i] = 0;
	for (i = 0;i < n + 1;i++) graphs[i] = (int*)malloc((n + 1) * sizeof(**graphs));

	for (i = 1;i < n + 1;i++)
	{
		for (j = 1;j < n + 1;j++) graphs[i][j] = 0;
	}

	for (i = 1;i < n + 1;i++)
	{
		for (j = 1;j < i;j++)
		{
			fscanf_s(in, "%d", &input);
			graphs[i][j] = input;
			graphs[j][i] = input;
		}
	}

	/*for (i = 1;i <= n;i++)
	{
		for (j = 1;j <= n;j++)
		{
			printf("%d ", graphs[i][j]);
		}
		printf("\n");
	}*/

	for (i = 1;i <= n;i++)
	{
		if (visit[i] == 0)
		{
			cnt++;
			front = -1;
			rear = -1;
			visit[i] = 1;
			addq(i);
			while (front != rear)
			{
				v = deleteq();
				for (j = 1;j <= n;j++)
				{
					if (visit[j] == 0 && graphs[v][j] == 1)
					{
						addq(j);
						visit[j] = 1;
					}
				}
			}
		}
	}

	printf("%d", cnt);

	return 0;
}