#include <stdio.h>

int cnt = 0;

int bin(int n)
{
	if (n < 2) return 0;
	if (n % 2 == 0)
	{
		bin(n / 2);
	}
	else
	{
		cnt++;
		bin(n / 2);
	}
}

int main()
{
	int n;
	scanf_s("%d", &n);

	bin(n);
	printf("��������к�\n2016110398�Ŵ���\n");
	printf("%d", cnt + 1);

	return 0;
}