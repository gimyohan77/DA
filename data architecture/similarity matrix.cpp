#include <stdio.h>
#include <stdlib.h>

int main()
{
	int** M, ** K;
	int a, b, m, n;
	int i, j, x, y;
	int cnt = 0;
	int rex = -1, rey = -1;
	FILE* in, * key;


	fopen_s(&in, "in.txt", "r");
	fopen_s(&key, "key.txt", "r");

	fscanf_s(in, "%d", &a);
	fscanf_s(in, "%d", &b);

	M = (int**)malloc(sizeof(*M) * a);
	for (i = 0;i < a;i++)
	{
		M[i] = (int*)malloc(b * sizeof(**M));
		for (j = 0;j < b;j++)
		{
			fscanf_s(in, "%d", &M[i][j]);
		}
	}

	fscanf_s(key, "%d", &m);
	fscanf_s(key, "%d", &n);

	K = (int**)malloc(sizeof(*K) * m);
	for (i = 0;i < m;i++)
	{
		K[i] = (int*)malloc(n * sizeof(**K));
		for (j = 0;j < n;j++)
		{
			fscanf_s(key, "%d", &K[i][j]);
		}
	}

	for (i = 0;i <= a - m;i++)
	{
		for (j = 0;j <= b - n;j++)
		{
			cnt = 0;
			for (x = 0;x < m;x++)
			{
				for (y = 0; y < n;y++)
				{
					if (M[i + x][j + y] == K[x][y]) cnt++;
				}
			}
			if (cnt == m * n || cnt ==m*n-1)
			{
				if (rex == -1 && rey == -1)
				{
					rex = i;
					rey = j;
				}
			}
		}
	}
	printf("경제통상학부 2016110398 신대희\n");
	printf("(%d, %d)", rex, rey);

	free(M);
	free(K);
	fclose(in);
	fclose(key);

	return 0;
}