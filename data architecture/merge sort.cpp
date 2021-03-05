#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct element {
	int x;
	int y;
	int z;
}element;


void merge(element b[], element mer[], int i, int m, int n, char a)
{
	int j, k, t;
	j = m + 1;
	k = i;

	if (a == 'X')
	{
		while (i <= m && j <= n)
		{
			if (b[i].x >= b[j].x) 
				mer[k++] = b[i++];
			else 
				mer[k++] = b[j++];
		}
		if (i > m)
			for (t = j;t <= n;t++)
				mer[t] = b[t];
		else
			for (t = i;t <= m;t++)
				mer[k + t - i] = b[t];
	}
	if (a == 'Y')
	{
		while (i <= m && j <= n)
		{
			if (b[i].y >= b[j].y) 
				mer[k++] = b[i++];
			else 
				mer[k++] = b[j++];
		}
		if (i > m)
			for (t = j;t <= n;t++)
				mer[t] = b[t];
		else
			for (t = i;t <= m;t++)
				mer[k + t - i] = b[t];
	}
	if (a == 'Z')
	{
		while (i <= m && j <= n)
		{
			if (b[i].z >= b[j].z)
				mer[k++] = b[i++];
			else 
				mer[k++] = b[j++];
		}
		if (i > m)
			for (t = j;t <= n;t++)
				mer[t] = b[t];
		else
			for (t = i;t <= m;t++)
				mer[k + t - i] = b[t];
	}
}

void mergePass(element b[], element mer[], int n, int s, char a)
{
	int i, j;
	for (i = 1;i <= n - 2 * s + 1;i += 2 * s)
		merge(b, mer, i, i + s - 1, i + 2 * s - 1, a);
	if (i + s - 1 < n)
		merge(b, mer, i, i + s - 1, n, a);
	else
		for (j = i;j <= n;j++)
			mer[j] = b[j];
}

void mergeSort(element b[], int n, char a)
{
	int s = 1;
	element extra[MAX];

	while (s < n)
	{
		mergePass(b, extra, n, s, a);
		s *= 2;
		mergePass(extra, b, n, s, a);
		s *= 2;
	}
}

int main()
{
	FILE* in, * out, * out1;
	char a;
	element* b, * c;
	int* d;
	int n;
	int i, j;
	int x1, y1, z1;

	fopen_s(&in, "in.txt", "r");
	fopen_s(&out, "out.txt", "w");

	fscanf_s(in, "%d", &n);

	b = (element*)malloc(sizeof(element) * n + 1);
	c = (element*)malloc(sizeof(element) * n + 1);
	d = (int*)malloc(sizeof(int) * n + 1);
	for (i = 0;i < n;i++)
	{
		fscanf_s(in, "%d %d %d", &x1, &y1, &z1);
		b[i+1].x = x1;
		b[i+1].y = y1;
		b[i+1].z = z1;
	}


	/*for (i = 1;i <= n;i++)
	{
		printf("%d %d %d\n", b[i].x, b[i].y, b[i].z);
	}*/

	printf("key : ");
	scanf_s(" %c", &a);


	mergeSort(b, n, a);



	printf("\n\n");

	/*for (i = 1;i <= n;i++)
	{
		printf("%d %d %d\n", b[i].x, b[i].y, b[i].z);
	}*/

	fprintf_s(out, "%c\n", a);
	for (i = 1;i <= n;i++)
	{
		fprintf_s(out, "%d %d %d\n", b[i].x, b[i].y, b[i].z);
	}

	fclose(out);   /// 검증하는 부분

	fopen_s(&out1, "out.txt", "r");
	fscanf_s(out1, "%c", &a);
	for (i = 0;i < n;i++)
	{
		fscanf_s(out1, "%d %d %d", &c[i].x, &c[i].y, &c[i].z);
		if (a == 'X') d[i] = c[i].x;
		else if (a == 'Y') d[i] = c[i].y;
		else if (a == 'Z') d[i] = c[i].z;
	}

	int cnt = 0;
	for (i = 0;i < n;i++)
	{
		for (j = i;j < n;j++)
		{
			if (d[i] < d[j]) cnt++;
		}
	}

	if (cnt == 0) printf("화면출력 : true\n");
	else printf("화면출력 : false\n");

	fclose(in);
	fclose(out1);

	return 0;
}