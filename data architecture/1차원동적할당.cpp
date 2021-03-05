#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE* in, * out;
	int num = 0, sum = 0, i,x=0;
	int* L;
	double avg;

	printf("경제통상학부 206110398 신대희\n");
	fopen_s(&in, "in.txt", "r");
	fopen_s(&out, "out.txt", "w");
	
	fscanf_s(in, "%d ", &num);
	printf("원소의 갯수 : %d\n", num);

	fclose(in);
	fopen_s(&in, "in.txt", "r");

	L = (int*)malloc(sizeof(int) * (num+1));
	for (i = 0; i <= num; i++)
	{
		fscanf_s(in, "%d", &L[i]);
	}
	for (i = 1; i <= num; i++)
	{
		sum = sum + L[i];
	}
	avg = (double)sum / num;
	printf("합계: %d\n", sum);
	printf("평균: %g\n", avg);

	while (1)
	{
		scanf_s("%d", &x);
		if (x > 0) break;
	}
	printf("%d의 배수: ", x);
	fprintf(out, "%d의 배수: ", x);
	for (i = 1;i <= num;i++)
	{
		if (L[i] % x == 0)
		{
			printf("%d ", L[i]);
			fprintf_s(out, "%d ", L[i]);
		}
	}

	fclose(in);
	fclose(out);
}