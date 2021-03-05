#include <stdio.h>
#include <stdlib.h>

#define MALLOC(p,s)\
	if(!((p) = (node*)malloc(s))){\
		fprintf(stderr, "insufficien memory");\
		exit(EXIT_FAILURE);\
	}

#define REALLOC(p, s)\
	if(!((p) = (node*)realloc(p,s))){\
		fprintf(stderr, "insufficient memory");\
		exit(EXIT_FAILURE);\
	}

typedef struct node* nodePointer;
typedef struct node {
	int data;
	nodePointer link;
};

int main()
{
	FILE* in;
	short int *out;
	nodePointer *seq;
	nodePointer x, y, top;
	int i, j, n,m;


	printf("경제통상학부 2016110398 신대희\n");

	fopen_s(&in, "in.txt", "r");
	fscanf_s(in, "%d %d", &n, &m);

	out = (short int*)malloc(sizeof(short int) * n);
	seq = (nodePointer*)malloc(sizeof(nodePointer) * n);

	for (i = 0;i < n;i++)
	{
		out[i] = 1; seq[i] = NULL;
	}

	

	while (!feof(in))
	{
		fscanf_s(in, "%d %d", &i, &j);
		MALLOC(x, sizeof(*x));
		x->data = j; ; x->link = seq[i]; seq[i] = x;
		MALLOC(x, sizeof(*x));
		x->data = i; x->link = seq[j]; seq[j] = x;
	}

	for (i = 0;i < n;i++)
	{
		if (out[i])
		{
			printf("%d", i);
			out[i] = 0;
			x = seq[i];
			top = NULL;
			while (1)
			{
				while (x)
				{
					j = x->data;
					if (out[j])
					{
						printf("%2d", j);
						out[j] = 0;
						y = x->link; x->link = top; top = x; x = y;
					}
					else x = x->link;
				}
				if (!top) break;
				x = seq[top->data]; top = top->link;
			}
			printf("\n");
		}
	}
	fclose(in);
	return 0;
}