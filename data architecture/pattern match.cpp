#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE* in, *key;
	int M[10][10], *S;
	int i, j, k, n, t=1;
	int cnt = 0;

	fopen_s(&in, "in.txt", "r");
	fopen_s(&key, "key.txt", "r");

	printf("경제통상학부 2016110398 신대희\n");

	for (i = 0;i < 10;i++)
	{
		for (j = 0;j < 10;j++)
		{
			fscanf_s(in, "%d", &M[i][j]);
		}
	}

	fscanf_s(key, "%d", &n);
	S = (int*)malloc(sizeof(int) * n);
	i = 0;
	while (!feof(key))
	{
		fscanf_s(key, "%d", &S[i]);
		i++;
	}

	for (i = 0;i < 10;i++)
	{
		for (j = 0;j < 10;j++)
		{
			cnt = 0;
			if (M[i][j] == S[0])
			{
				for (k = 1;k < n;k++)
				{
					if (M[i][j + k] == S[k] && (j+k)<10) cnt++;
				}
			}
			if ((n - 1) == cnt)
			{
				printf("(%d, %d)\n", i, j);
				t = 0;
			}
		}
	}
	if (t == 1) printf("(-1, -1)");
	free(S);
	fclose(in);
	fclose(key);
	return 0;
}