#include <stdio.h>
#include <stdlib.h>

#define MALLOC(p,s)\
	if(!((p) = (char*)malloc(s))){\
		fprintf(stderr, "insufficien memory");\
		exit(EXIT_FAILURE);\
	}

#define REALLOC(p,s)\
	if(!((p) = (char*)realloc(p,s))){\
		fprintf(stderr, "insufficient memory");\
		exit(EXIT_FAILURE);\
	}

char* stack;

int top = -1;
int capacity = 1;


char empty()
{
	fprintf(stderr, "stack empty");
	exit(EXIT_FAILURE);
	char rtn = '\n';
	return rtn;
}

void full()
{
	REALLOC(stack, 2 * capacity * sizeof(*stack));
	capacity *= 2;
}

void push(char item)
{
	if (top+1 == capacity) full();
	stack[++top] = item;
}

char pop()
{
	if (capacity >= (top) * 2 && top != 0)
	{
		REALLOC(stack, (capacity / 2) * sizeof(*stack));
		capacity /= 2;
	}
	if (top == -1)
		return empty();
	return stack[top--];

}

int main()
{
	FILE* in;
	MALLOC(stack, capacity * sizeof(*stack));
	char input;
	char n;
	int i;
	fopen_s(&in, "in.txt", "r");
	
	printf("경제통상학부 2016110398 신대희\n");

	while (!feof(in))
	{
		fscanf_s(in, "%c ", &input);
		if (input == 'A')
		{
			fscanf_s(in, "%c ", &n);
			push(n);
		}
		else if (input == 'R')
		{
			pop();
		}
		else if (input == 'E') break;
		

		printf("Stack capacity: %d\n", capacity);
		for (i = 0;i <= top;i++)
		{
			printf("%c ", stack[i]);
		}
		printf("\n");
	}

	fclose(in);
	free(stack);
	return 0;
}