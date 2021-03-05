#include <stdio.h>
#include <stdlib.h>
#include <cstring>

int main()
{
	FILE* in;
	char str[100][4];
	char s[4];
	int i = 0, h, cnt = 0, b = -1;

	fopen_s(&in, "in.txt", "r");

	while (!feof(in))
	{
		fscanf_s(in, "%s ", str[i] , 4);
		i++;
		cnt++;
	}
	scanf_s("%s", s, sizeof(s));

	for (h = 0;h < cnt;h++)
	{
		if (strcmp(str[h], s) == 0) b = h;
	}
	printf("경제통상학부 2016110398 신대희\n");
	printf("Binary search result : %d", b);
	fclose(in);
	return 0;
}