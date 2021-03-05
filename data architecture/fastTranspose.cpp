#include <stdio.h>
#include <stdlib.h>


#define MAX_TERMS 101

typedef struct {
	int col;
	int row;
	int value;
} term;

term a[MAX_TERMS];
term b[MAX_TERMS];

void fastTranspose(term a[], term b[])
{
	int rowTerms[MAX_TERMS], startingPos[MAX_TERMS];
	int i, j, numCols = a[0].col, numTerms = a[0].value;
	b[0].row = numCols;
	b[0].col = a[0].row;
	b[0].value = numTerms;

	if (numTerms > 0)
	{
		for (i = 0;i < numCols;i++)
			rowTerms[i] = 0;
		for (i = 1;i <= numTerms;i++)
			rowTerms[a[i].col]++;
		startingPos[0] = 1;
		for (i = 1;i < numCols;i++)
			startingPos[i] = startingPos[i - 1] + rowTerms[i - 1];
		for (i = 1;i <= numTerms;i++)
		{
			j = startingPos[a[i].col]++;
			b[j].row = a[i].col;
			b[j].col = a[i].row;
			b[j].value = a[i].value;
		}
	}
}

int main()
{
	FILE* in;
	int** A, m, n, i, j;
	int k = 1;
	fopen_s(&in, "in.txt", "r");
	fscanf_s(in, "%d %d", &m, &n);

	printf("경제통상학부 2016110398 신대희\n\n");
	A = (int**)malloc(sizeof(*A) * m);
	for (i = 0;i < m;i++)
	{
		A[i] = (int*)malloc(n * sizeof(**A));
		for (j = 0;j < n;j++)
		{
			fscanf_s(in, "%d", &A[i][j]);
			if (A[i][j] != 0)
			{
				a[k].row = i;
				a[k].col = j;
				a[k].value = A[i][j];
				k++;
			}
		}
	}
	a[0].row = m;
	a[0].col = n;
	a[0].value = k-1;
	
	printf("A  row col val\n");
	for (i = 0;i < k;i++)
	{
		printf("[%d] %d   %d   %d\n",i, a[i].row, a[i].col, a[i].value);
	}
	printf("\n\n");

	fastTranspose(a, b);
	printf("After fastTranspose\n");
	printf("B row col val\n");
	for (i = 0;i < k;i++)
	{
		printf("[%d] %d   %d   %d\n", i, b[i].row, b[i].col, b[i].value);
	}

	free(A);
	fclose(in);
	return 0;
}
