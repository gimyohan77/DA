#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE* in;
	int i;
	int max = -9999999, min = 9999999, cnt = 0;

	fopen_s(&in, "in.txt", "r");

	while (!feof(in))
	{
		fscanf_s(in, "%d", &i);
		cnt++;
		if (i > max) max = i;
		if (i < min) min = i;
	}

	printf("경제통상학부 2016110398 신대희\n");
	printf("원소의 개수 : %d\n", cnt);
	printf("최소값 : %d\n", min);
	printf("최대값 : %d\n", max);

	fclose(in);
}