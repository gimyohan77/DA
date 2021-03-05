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
	printf("경제통상학부\n2016110398신대희\n");
	printf("%d", cnt + 1);

	return 0;
}