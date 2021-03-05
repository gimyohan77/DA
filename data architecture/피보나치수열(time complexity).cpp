#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int fibo(int n)
{
	if (n <= 1)
		return 1;
	return fibo(n - 1) + fibo(n - 2);
}

int main()
{
	int n, i;
	int* F;
	int result;

	clock_t start, finish;
	double elapsed;

	while (1)
	{
		scanf_s("%d", &n);
		if (n >= 0 && n <= 50)
		{
			F = (int*)malloc(sizeof(int) * (n + 1));
			F[0] = 1;
			F[1] = 1;

			start = clock();
			for (i = 2; i <= n; i++)
			{
				F[i] = F[i - 1] + F[i - 2];
			}
			result = F[n];
			printf("%d\n", result);
			finish = clock();
			elapsed = ((double)(finish)-(double)(start)) / CLOCKS_PER_SEC;
			printf("time:%f\n", elapsed * 1000.0);
			free(F);


			start = clock();
			result = fibo(n);
			printf("%d\n", result);
			finish = clock();
			elapsed = ((double)(finish)-(double)(start)) / CLOCKS_PER_SEC;
			printf("time:%f\n\n", elapsed * 1000.0);

		}
		else break;
	}
	printf("경제통상학부\n2016110398 신대희\n");
	return 0;
}