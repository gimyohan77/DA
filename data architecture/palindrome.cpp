#include <stdio.h>
#include <string.h>

int main()
{
	char str1[20], str2[20], c[20];
	int n,m,i, cnt=0, result;
	scanf_s("%s", str1, sizeof(str1));

	n = strlen(str1);

	for (i = 0;i <= n;i++)
	{
		if (str1[i] != '*')
		{
			str2[cnt] = str1[i];
			cnt++;
		}
	}
	m = strlen(str2);
	cnt = 0;
	for (i = m-1;i >=0;i--)
	{
		c[cnt] = str2[i];
		cnt++;
	}
	c[cnt] = '\0';
	result = strncmp(c, str2, m);

	printf("경제통상학부\n2016110398 신대희\n");
	printf("%s\n", str2);
	printf("%d\n", m);
	if (result == 0) printf("Yes");
	else printf("No");

	return 0;
}