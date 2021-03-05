#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE* in;
	char a[100][3];
	int bin[27][100] = { 0 };
	int p[27] = { 0 };
	int n = 0;
	int i;
	int link;
	int link1[100];
	
	fopen_s(&in, "in.txt", "r");


	while (!feof(in))
	{
		fscanf_s(in, " %c", &a[n][0], sizeof(a));
		fscanf_s(in, " %c", &a[n][1], sizeof(a));
		fscanf_s(in, " %c", &a[n][2], sizeof(a));
		a[n][3] = '\0';
		n++;
	}
	*a[n + 1] = '\0';


	for (i = 0;i < n - 1;i++)
	{
		link = int(a[i][2]) - 96;
		bin[link][p[link]] = i+1;
		p[link]++;
	}

	int j = 0;
	for (i = 0;i < 27;i++)
	{
		int m = 0;
		while (bin[i][m]!= 0)
		{
			link1[j] = bin[i][m];
			m++;
			j++;
		}
	}
	for (i = 0;i < 27;i++)
	{	
		for (j = 0;j < n-1;j++)
		{
			bin[i][j] = 0;
		}
	}


	for (i = 0;i < 27;i++) p[i] = 0;
	
	for (i = 0;i < n - 1;i++)
	{
		link = int(a[link1[i]-1][1]) - 96;
		bin[link][p[link]] = link1[i];
		p[link]++;
	}
	for (i = 0;i < 100;i++)
	{
		link1[i] = 0;
	}

	j = 0;
	for (i = 0;i < 27;i++)
	{
		int m = 0;
		while (bin[i][m] != 0)
		{
			link1[j] = bin[i][m];
			m++;
			j++;
		}
	}

	for (i = 0;i < 27;i++)
	{	
		for (j = 0;j < n-1;j++)
		{
			bin[i][j] = 0;
		}
	}


	for (i = 0;i < 27;i++) p[i] = 0;
	
	for (i = 0;i < n - 1;i++)
	{
		link = int(a[link1[i]-1][1]) - 96;
		bin[link][p[link]] = link1[i];
		p[link]++;
	}
	for (i = 0;i < 100;i++)
	{
		link1[i] = 0;
	}

	j = 0;
	for (i = 0;i < 27;i++)
	{
		int m = 0;
		while (bin[i][m] != 0)
		{
			link1[j] = bin[i][m];
			m++;
			j++;
		}
	}
	// 1
	for (i = 0;i < 27;i++)
	{
		for (j = 0;j < n - 1;j++)
		{
			bin[i][j] = 0;
		}
	}


	for (i = 0;i < 27;i++) p[i] = 0;

	for (i = 0;i < n - 1;i++)
	{
		link = int(a[link1[i] - 1][0]) - 96;
		bin[link][p[link]] = link1[i];
		p[link]++;
	}
	for (i = 0;i < 100;i++)
	{
		link1[i] = 0;
	}

	j = 0;
	for (i = 0;i < 27;i++)
	{
		int m = 0;
		while (bin[i][m] != 0)
		{
			link1[j] = bin[i][m];
			m++;
			j++;
		}
	}
	
	
	/*while (link1[i] != 0)
	{
		printf("%d", link1[i]);
		i++;
	}*/
	i = 0;
	while (link1[i] != 0)
	{
		printf("%c", a[link1[i]-1][0]);
		printf("%c", a[link1[i]-1][1]);
		printf("%c", a[link1[i]-1][2]);
		printf("\n");
		i++;
	}


	//아스키코드 a-z, 97~122
	/*for (i = 0;i < n-1;i++)
	{
		printf("%c", a[i][0]);
		printf("%c", a[i][1]);
		printf("%c", a[i][2]);
		printf("\n");
	}*/

}