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

	printf("��������к� 2016110398 �Ŵ���\n");
	printf("������ ���� : %d\n", cnt);
	printf("�ּҰ� : %d\n", min);
	printf("�ִ밪 : %d\n", max);

	fclose(in);
}