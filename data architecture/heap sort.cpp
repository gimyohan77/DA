#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct element {
	int x;
	int y;
	int z;
}element;

void adjust(element a[], int root, int n, char key)
{
	int child, rootkey;
	element temp;
	temp = a[root];
	if (key == 'X')
	{
		rootkey = a[root].x;
		child = 2 * root;
		while (child <= n)
		{
			if((child < n) && (a[child].x > a[child+1].x))
				child++;
			if(rootkey < a[child].x)
				break;
			else
			{
				a[child / 2] = a[child];
				child *= 2;
			}
		}
		a[child/2] = temp;
	}

	if (key == 'Y')
	{
		rootkey = a[root].y;
		child = 2 * root;
		while (child <= n)
		{
			if ((child < n) && (a[child].y > a[child + 1].y))
				child++;
			if (rootkey < a[child].y)
				break;
			else
			{
				a[child / 2] = a[child];
				child *= 2;
			}
		}
		a[child / 2] = temp;
	}

	if (key == 'Z')
	{
		rootkey = a[root].z;
		child = 2 * root;
		while (child <= n)
		{
			if ((child < n) && (a[child].z > a[child + 1].z))
				child++;
			if (rootkey < a[child].z)
				break;
			else
			{
				a[child / 2] = a[child];
				child *= 2;
			}
		}
		a[child / 2] = temp;
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
		b[i + 1].x = x1;
		b[i + 1].y = y1;
		b[i + 1].z = z1;
	}

	printf("key : ");
	scanf_s(" %c", &a);

	element temp;

	for (i = n / 2; i > 0; i--)
		adjust(b, i, n, a);
	for (i = n - 1;i > 0;i--)
	{
		temp = b[1];
		b[1] = b[i + 1];
		b[i + 1] = temp;
		adjust(b, 1, i, a);
	}

	for (i = 1;i <= n;i++)
	{
		printf_s("%d %d %d\n", b[i].x, b[i].y, b[i].z);
	}
	printf("\n\n");

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