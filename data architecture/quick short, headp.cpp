#include <stdio.h>
#include <stdlib.h>

typedef struct node* treePointer;
typedef struct node {
	treePointer lchild;
	treePointer rchild;
	int data;
}node;

/*void insert(nodePointer first, int data)
{
	nodePointer second;
	second = (nodePointer)malloc(sizeof(node));
	second->data = data;
	second->link = NULL;
	first->link = second;
}

void p1()
{
	FILE* in1;
	int n;
	int g[20][20];
	int i, j;
	int d;

	nodePointer gg[20];
	fopen_s(&in1, "in1.txt", "r");

	fscanf_s(in1, "%d", &n);

	for (i = 0;i < 20;i++)
	{
		for (j = 0;j < 20;j++) g[i][j] = 0;
	}

	for (i = 1;i <= n;i++)
	{
		for (j = 0;j <= i-1;j++)
		{
			fscanf_s(in1, "%d", &d);
			g[i][j] = d;
			g[j][i] = d;
		}
	}

	for (i = 1;i <= n;i++)
	{
		gg[i]->data = -1;
		gg[i]->link = NULL;
		for (j = 0;j < n;j++)
		{
			insert(gg[i], g[i][j]);
		}
	}

}*/

void p2()
{
	FILE* in2;
	fopen_s(&in2, "in2.txt", "r");
	int a[200], i = 1;
	int k;
	int j, cnt = 0;
	for (j = 0;j <= 100;j++) a[j] = 0;

	while (!feof(in2))
	{
		fscanf_s(in2, "%d", &k);
		a[i] = k;
		i++;
	}

	k = i;

	for (i = 1;i < k/2+1;i++)
	{
		if (a[i] < a[i * 2] || a[i] < a[(i * 2) + 1])
		{
			cnt++;
		}
	}

	if (cnt > 0) printf("문제2 : NO\n");
	else printf("문제 2 : YES\n");
}

void quickSort(int a[], int left, int right)
{
	int pivot, i, j;
	int temp;
	int mind = (left + right) / 2;

	if (left < right)
	{
		i = left;
		j = right + 1;
		pivot = a[left];
		do{
			do
			{
				i++;
			} while (i < j && pivot > a[i]);
			do
			{
				j--;
			} while (i<j && pivot < a[j]);
			if (i < j)
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		} while (i < j);
		temp = a[i-1];
		a[i-1] = a[left];
		a[left] = temp;
		quickSort(a, left, i-1 );
		quickSort(a, i, right);
	}
}

void p3()
{
	FILE* in3;
	fopen_s(&in3, "in3.txt", "r");

	int a[200], i = 1;
	int k, j;

	for (j = 0;j <= 100;j++) a[j] = 0;

	while (!feof(in3))
	{
		fscanf_s(in3, "%d", &k);
		a[i] = k;
		i++;
	}
	k = i - 1;
	quickSort(a, 1, i - 1);

	printf("문제 3 :");
	for (i = 1;i <= k;i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

int main()
{
	printf("학부 : 경제통상학부 학번 : 2016110398 이름 : 신대희\n");
	//p1();
	p2();
	p3();
	//p4();
	return 0;
}