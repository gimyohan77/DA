#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int seqSearch(int list[], int k, int n)
{
	int i;
	for (i = 0; i < n;i++)
	{
		if (list[i] == k) return i;
	}
	return -1;
}

int ibs(int list[], int k, int left, int right)
{
	int middle;
	int p;
	while (left <= right)
	{
		middle = (left + right) / 2;
		if (list[middle] < k) p = -1;
		else if (list[middle] == k) p = 0;
		else if (list[middle] > k) p = 1;

		switch (p)
		{
			case -1: left = middle + 1;
				break;
			case 0: return middle;
			case 1: right = middle - 1;
		}
	}
	return -1;
}

int rbs(int list[], int k, int left, int right)
{
	int middle;
	int p;
	while (left <= right)
	{
		middle = (left + right) / 2;
		if (list[middle] < k) p = -1;
		else if (list[middle] == k) p = 0;
		else if (list[middle] > k) p = 1;

		switch (p)
		{
			case -1: return rbs(list, k, middle + 1, right);
			case 0: return middle;
			case 1: return rbs(list, k, left, middle - 1);
		}
	}
	return -1;
}


int main()
{
	FILE* in, * out;
	int* L;
	int N, n, i = 0;
	int result;
	
	clock_t start, finish;
	double elapsed;

	fopen_s(&in, "in.txt", "r");
	fopen_s(&out, "out.txt", "w");

	fprintf_s(out, "경제통상학부 2016110398 신대희\n");
	
	fscanf_s(in, "%d", &n);
	L = (int*)malloc(sizeof(int) * n);

	while (!feof(in))
	{
		fscanf_s(in, "%d", &L[i]);
		i++;
	}

	while (1)
	{
		scanf_s("%d", &N);
		fprintf_s(out, "(scanf) %d\n", N);

		if (N < 0) break;
		else
		{
			start = clock();
			result = seqSearch(L, N, n);
			finish = clock();
			elapsed = ((double)(finish)-(double)(start)) / CLOCKS_PER_SEC;
			fprintf_s(out, "(Sequental) %d %fms\n", result, elapsed*1000.0);

			start = clock();
			result = ibs(L, N, 0, n-1);
			finish = clock();
			elapsed = ((double)(finish)-(double)(start)) / CLOCKS_PER_SEC;
			fprintf_s(out, "(Iterative) %d %fms\n", result, elapsed*1000.0);

			start = clock();
			result = rbs(L, N, 0, n - 1);
			finish = clock();
			elapsed = ((double)(finish)-(double)(start)) / CLOCKS_PER_SEC;
			fprintf_s(out, "(Recursive) %d %fms\n", result, elapsed*1000.0);
		}
	}

	free(L);
	return 0;
}