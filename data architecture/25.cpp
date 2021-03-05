#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE* in;
	char str[100][20];
	int n,i=0,j;
	int* h;
	int* key;

	fopen_s(&in, "in.txt", "r");

	fscanf_s(in, "%d", &n);
	while (!feof(in))
	{
		fgets(str[i], sizeof(str), in);
		//str[i][strlen(str[i]) - 1] = '\0';
		i++;
	}

	int cnt = i;
	for(i=1;i<cnt-1;i++) str[i][strlen(str[i]) - 1] = '\0';

	h = (int*)malloc(sizeof(int) * n);
	key = (int*)malloc(sizeof(int) * n);
	for (i = 0;i < n;i++) key[i] = 0;
	for (i = 0; i < n;i++) h[i] = 0;

	for (i = 0;i < cnt;i++)
	{
		j = 0;
		while (int(str[i][j]) >=97 && int(str[i][j])<=122 )
		{
			key[i] += int(str[i][j]);
			j++;
		}
	}

	int k;
	for (i = 1;i < cnt;i++)
	{
		k = key[i] % n;
		if (h[k] == 0) h[k] = i;
		else
		{
			while (h[k] != 0)
			{
				k++;
				if (k > n - 1) k = 0;
			}
			h[k] = i;
		}
	}

	for (i = 0;i < n;i++) //printf("%d\n", h[i]);
	{
		if (h[i] == 0) printf("%d: \n", i);
		else printf("%d: %s %d\n", i, str[h[i]], key[h[i]]);
	}
	printf("\n");
	char scan[100];
	int s;
	while (1)
	{
		s = 0;
		i = 0;
		gets_s(scan, sizeof(scan));
		if (strcmp(scan, "END") == 0) break;
		else
		{
			/*while (int(scan[i]) >= 97 && int(str[i]) <= 122)
			{
				s += int(scan[i]);
				i++;
			}
			s = s % n;
			if (strcmp(scan, str[h[s]]) == 0) printf("S");
			else
			{

			}*/
			for (j = 0;j < n;j++)
			{
				if (strcmp(scan, str[j]) == 0) s = 1;
			}
		}
		if (s == 1) printf("S\n");
		else printf("F\n");

		printf("\n");
	}

	free(h);
	free(key);
	fclose(in);
	return 0;
}