#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct element {
	int x;
	int y;
	int z;
}element;

int listMerge(element a[], int link[], int start1, int start2, char key)
{
	int last1, last2, lastResult = 0;
	if (key == 'X')
	{
		for (last1 = start1, last2 = start2; last1 && last2;)
		{
			if (a[last1].x >= a[last2].x)
			{
				link[lastResult] = last1;
				lastResult = last1;
				last1 = link[last1];
			}
			else
			{
				link[lastResult] = last2;
				lastResult = last2;
				last2 = link[last2];
			}
		}
		if (last1 == 0) link[lastResult] = last2;
		else link[lastResult] = last1;
		return link[0];
	}
	else if (key == 'Y')
	{
		for (last1 = start1, last2 = start2; last1 && last2;)
		{
			if (a[last1].y >= a[last2].y)
			{
				link[lastResult] = last1;
				lastResult = last1;
				last1 = link[last1];
			}
			else
			{
				link[lastResult] = last2;
				lastResult = last2;
				last2 = link[last2];
			}
		}
		if (last1 == 0) link[lastResult] = last2;
		else link[lastResult] = last1;
		return link[0];
	}
	else if (key == 'Z')
	{
		for (last1 = start1, last2 = start2; last1 && last2;)
		{
			if (a[last1].z >= a[last2].z)
			{
				link[lastResult] = last1;
				lastResult = last1;
				last1 = link[last1];
			}
			else
			{
				link[lastResult] = last2;
				lastResult = last2;
				last2 = link[last2];
			}
		}
		if (last1 == 0) link[lastResult] = last2;
		else link[lastResult] = last1;
		return link[0];
	}
}

int rmergeSort(element a[], int link[], int left, int right, char key)
{
	if (left >= right) return left;
	int mid = (left + right) / 2;
	return listMerge(a, link, rmergeSort(a, link, left, mid, key), rmergeSort(a, link, mid + 1, right, key), key);
}

int main()
{
	FILE* in, * out, * out1;
	char a;
	element* b, * c;
	int* d, * link;
	int n;
	int i, j;
	int x1, y1, z1;
	int result;

	fopen_s(&in, "in.txt", "r");
	fopen_s(&out, "out.txt", "w");

	fscanf_s(in, "%d", &n);

	b = (element*)malloc(sizeof(element) * n + 1);
	c = (element*)malloc(sizeof(element) * n + 1);
	d = (int*)malloc(sizeof(int) * n + 1);
	link = (int*)malloc(sizeof(int) * n + 1);
	for (i = 0;i < n;i++)
	{
		fscanf_s(in, "%d %d %d", &x1, &y1, &z1);
		b[i + 1].x = x1;
		b[i + 1].y = y1;
		b[i + 1].z = z1;
		link[i + 1] = 0;
	}

	printf("key : ");
	scanf_s(" %c", &a);

	result = rmergeSort(b, link, 1, n, a);


	int pointer = -1;

	fprintf_s(out, "%c\n", a);
	fprintf_s(out, "%d %d %d\n", b[result].x, b[result].y, b[result].z);
	while (link[pointer] != 0)
	{
		pointer = link[result];
		fprintf_s(out, "%d %d %d\n", b[pointer].x, b[pointer].y, b[pointer].z);
		result = pointer;
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