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

listPointer Header = NULL;
listPointer trailer = NULL;

listPointer getlist(int n)
{
	listPointer newlist;
	MALLOC(newlist, sizeof(*newlist));
	newlist->data = n;
	newlist->link = NULL;

	return newlist;
}

listPointer createlist(listPointer inputlist)
{
	if (Header == NULL) Header = inputlist;
	else trailer->link = inputlist;
	trailer = inputlist;
	return Header;
}

void printlist(listPointer first)
{
	listPointer curr = first;
	while (curr != NULL)
	{
		printf("%d ", curr->data);
		curr = curr->link;
	}
	printf("\n");
}


void findnode(listPointer c1, listPointer c2)
{
	while (c1 != NULL && c2 != NULL)
	{
		if (c1->data == c2->data)
		{
			printf("%d ", c1->data);
			c1 = c1->link;
			c2 = c2->link;
		}
		else if (c1->data > c2->data) c2 = c2->link;
		else if (c1->data < c2->data) c1 = c1->link;
	}
}

int main()
{
	FILE* in1, * in2;
	listPointer list1, list2;
	int input1, input2;

	MALLOC(list1, sizeof(*list1));
	MALLOC(list2, sizeof(*list2));

	fopen_s(&in1, "in1.txt", "r");
	fopen_s(&in2, "in2.txt", "r");

	printf("경제통상학부 2016110398 신대희\n");

	while (!feof(in1))
	{
		fscanf_s(in1, "%d ", &input1);
		list1 = createlist(getlist(input1));
	}
	Header = NULL;

	while (!feof(in2))
	{
		fscanf_s(in2, "%d ", &input2);
		list2 = createlist(getlist(input2));
	}


	findnode(list1, list2);

	free(list1);
	free(list2);
	fclose(in1);
	fclose(in2);

	return 0;
}