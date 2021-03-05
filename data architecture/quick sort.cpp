#include <stdio.h>
#include <stdlib.h>

typedef struct element{
	int x;
	int y;
	int z;
}element;

void quickSortx(element a[], int left, int right)
{
	int pivot, i, j;
	element temp;
	if (left < right)
	{
		i = left;
		j = right + 1;
		pivot = a[left].x;
		do {
			do i++; while (a[i].x > pivot);
			do j--; while (a[j].x < pivot);
			if (i < j)
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		} while (i < j);
		temp = a[left];
		a[left] = a[j];
		a[j] = temp;
		quickSortx(a, left, j - 1);
		quickSortx(a, j + 1, right);
	}
}

void quickSorty(element a[], int left, int right)
{
	int pivot, i, j;
	element temp;
	if (left < right)
	{
		i = left;
		j = right + 1;
		pivot = a[left].y;
		do {
			do i++; while (a[i].y > pivot);
			do j--; while (a[j].y < pivot);
			if (i < j)
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		} while (i < j);
		temp = a[left];
		a[left] = a[j];
		a[j] = temp;
		quickSorty(a, left, j - 1);
		quickSorty(a, j + 1, right);
	}
}

void quickSortz(element a[], int left, int right)
{
	int pivot, i, j;
	element temp;
	if (left < right)
	{
		i = left;
		j = right + 1;
		pivot = a[left].z;
		do {
			do i++; while (a[i].z > pivot);
			do j--; while (a[j].z < pivot);
			if (i < j)
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		} while (i < j);
		temp = a[left];
		a[left] = a[j];
		a[j] = temp;
		quickSortz(a, left, j - 1);
		quickSortz(a, j + 1, right);
	}
}

int main()
{
	FILE* in, * out, *out1;
	char a;
	element* b, * c;
	int* d;
	int n;
	int i,j;
	int x1, y1, z1;


	fopen_s(&in, "in.txt", "r");
	fopen_s(&out, "out.txt", "w");

	fscanf_s(in, "%d", &n);

	b = (element*)malloc(sizeof(element) * n+1);
	c = (element*)malloc(sizeof(element) * n + 1);
	d = (int*)malloc(sizeof(int) * n + 1);
	for (i = 0;i < n;i++)
	{
		fscanf_s(in, "%d %d %d", &x1, &y1, &z1);
		b[i].x = x1;
		b[i].y = y1;
		b[i].z = z1;
	}

	/*for (i = 0;i < n + 1;i++)
	{
		printf("%d %d %d\n", b[i].x, b[i].y, b[i].z);
	}*/

	printf("key : ");
	scanf_s(" %c", &a);
	if (a == 'X') quickSortx(b, 0, n-1);
	else if (a == 'Y') quickSorty(b, 0, n-1);
	else if (a == 'Z') quickSortz(b, 0, n-1);

	fprintf_s(out, "%c\n", a);
	for (i = 0;i < n;i++)
	{
		fprintf_s(out,"%d %d %d\n", b[i].x, b[i].y, b[i].z);
	}

	fclose(out);

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