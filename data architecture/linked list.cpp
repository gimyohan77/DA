#include <stdio.h>
#include <stdlib.h>

typedef struct listNode* listPointer;
typedef struct listNode {
	int data;
	listPointer link;
};




#define MALLOC(p,s)\
	if(!((p) = (listNode*)malloc(s))){\
		fprintf(stderr, "insufficien memory");\
		exit(EXIT_FAILURE);\
	}

#define REALLOC(p,s)\
	if(!((p) = (listNode*)realloc(p,s))){\
		fprintf(stderr, "insufficient memory");\
		exit(EXIT_FAILURE);\
	}

void addFirst(listPointer first, int input)
{
	listPointer second;
	MALLOC(second, sizeof(*second));
	second->link = first->link;
	second->data = input;
	first->link = second;
}


void printlist(listPointer first)
{
	listPointer curr = first;
	while (curr != NULL)
	{
		if(curr->data >=0) printf("%d ", curr->data);
		curr = curr->link;
	}
	printf("\n");
}

listPointer invert(listPointer lead)
{
	listPointer middle, trail;
	middle = NULL;
	while (lead)
	{
		trail = middle;
		middle = lead;
		lead = lead->link;
		middle->link = trail;
	}
	return middle;
}

void del(listPointer* first, listPointer trail, listPointer x)
{
	if (trail->link != NULL)
	{
		trail->link = x->link;
		if (x->data < 0) trail->data = -1;
		else trail->data = x->data;
	}
	else trail->data = -1;
	free(x);

}


int main()
{
	FILE* in;
	listPointer first;
	int input;
	int n;
	MALLOC(first, sizeof(*first));
	first->link = NULL;

	fopen_s(&in, "in.txt", "r");

	printf("경제통상학부 2016110398 신대희\n");

	while (!feof(in))
	{
		fscanf_s(in, "%d ", &input);
		addFirst(first, input);
	}
	addFirst(first, -1);

	listPointer curr = invert(first);

	printlist(curr);
	
	while (1)
	{
		printf("(Scanf_s) ");
		scanf_s("%d", &n);
		int k = 0;
		listPointer find = curr;
		if (n == -1) break;
		else 
		{
			
			while (find != NULL)
			{
				if (find->data == n)
				{
					del(&first, find, find->link);
					k = 1;
					break;
				}
				find = find->link;
			}
			if (k == 1) printlist(curr);
			if (k == 0) printf("%d is not found\n", n);
		}
	
	}

	fclose(in);
	free(first);

	return 0;
}