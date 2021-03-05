#include <stdio.h>

int prime(int x, int y)
{
	if (x == 1 || y == 1) return true;
	else if (x == y) return false;
	else if (x < y) prime(x, y - x);
	else if (y < x) prime(x - y, y);
}

int main()
{
	int x, y;
	int n;

	FILE* in, * out;

	fopen_s(&in, "in.txt", "r");
	fopen_s(&out, "out.txt", "w");
	fscanf_s(in, "%d %d", &x, &y);

	printf("경제통상학부\n2016110398 신대희\n");

	n = prime(x, y);
	if (n == 0) printf("false");
	else printf("true");
	return 0;
}