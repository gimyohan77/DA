#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 101
typedef struct {
	int col;
	int row;
	int value;
} term;

int main()
{
	FILE* A, * B;
	term a[MAX_TERMS], b[MAX_TERMS], c[MAX_TERMS];
	int i, j,x;

	fopen_s(&A, "A.txt", "r");
	fopen_s(&B, "B.txt", "r");
	
	fscanf_s(A, "%d %d %d", &a[0].row, &a[0].col, &a[0].value);
	fscanf_s(B, "%d %d %d", &b[0].row, &b[0].col, &b[0].value);

	for (i = 1;i <= a[0].value;i++)
	{
		fscanf_s(A, "%d %d %d", &a[i].row, &a[i].col, &a[i].value);
	}
	for (i = 1;i <= b[0].value;i++)
	{
		fscanf_s(B, "%d %d %d", &b[i].row, &b[i].col, &b[i].value);
	}
	i = 1;
	j = 1;
	x = 1;
	while (i <= a[0].value && j <= b[0].value)
	{
		if (a[i].row == b[j].row)
		{
			if (a[i].col == b[j].col)
			{
				if (a[i].value + b[j].value == 0)
				{
					i++;
					j++;
				}
				else
				{
					c[x].row = a[i].row;
					c[x].col = a[i].col;
					c[x].value = a[i].value + b[j].value;
					i++;
					j++;
					x++;
				}
			}
			else if (a[i].col > b[j].col)
			{
				c[x].row = b[j].row;
				c[x].col = b[j].col;
				c[x].value = b[j].value;
				j++;
				x++;
			}
			else if (a[i].col < b[j].col)
			{
				c[x].row = a[i].row;
				c[x].col = a[i].col;
				c[x].value = a[i].value;
				i++;
				x++;
			}
		}
		else if (a[i].row > b[j].row)
		{
			c[x].row = b[j].row;
			c[x].col = b[j].col;
			c[x].value = b[j].value;
			x++;
			j++;
		}
		else if (a[i].row < b[j].row)
		{
			c[x].row = a[i].row;
			c[x].col = a[i].col;
			c[x].value = a[i].value;
			x++;
			i++;
		}
	}
	for (i;i <= a[0].value;i++)
	{
		c[x].row = a[i].row;
		c[x].col = a[i].col;
		c[x].value = a[i].value;
		x++;
	}
	for (j;j <= b[0].value;j++)
	{
		c[x].row = b[j].row;
		c[x].col = b[j].col;
		c[x].value = b[j].value;
		x++;
	}
	printf("A+B row col val\n");
	printf("[0]  %d   %d   %d\n", a[0].row, a[0].col, x-1);
	for (i = 1;i < x; i++)
	{
		printf("[%d]  %d   %d   %d\n",i, c[i].row, c[i].col, c[i].value);
	}
	fclose(A);
	fclose(B);
	return 0;
}