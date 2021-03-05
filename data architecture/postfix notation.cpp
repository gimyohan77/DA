#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100
#define MAX_EXPR_SIZE 100

typedef enum {
	lparen, rparen, plus, minus, times, divide, mod, left, right, eos, operand
}precedence;

precedence stack[MAX_STACK_SIZE];
int top = 0;
char expr[MAX_EXPR_SIZE];

static int isp[] = { 0, 19, 12, 12, 13, 13, 13, 10, 10, 0 };
static int icp[] = { 20, 19, 12, 12, 13, 13, 13, 10, 10, 0 };

precedence get_token(char *symbol, int* n)
{
	*symbol = expr[(*n)++];
	switch (*symbol)
	{
		case '(': return lparen;
		case ')': return rparen;
		case '+': return plus;
		case '-': return minus;
		case '/': return divide;
		case '*': return times;
		case '%': return mod;
		case '>': return left;
		case '<': return right;
		case '\0': return eos;
		default: return operand;
	}
}

precedence empty()
{
	//fprintf(stderr, "stack is empty");
	precedence rtn = eos;
	return rtn;
}

void full()
{
	fprintf(stderr, "stack is full");
	exit(EXIT_FAILURE);
}

void push(precedence item)
{
	if (top >= MAX_STACK_SIZE - 1)
		full();
	stack[++top] = item;
}

precedence pop()
{
	if (top == -1)
		return empty();
	return stack[top--];
}

void print_token(precedence s)
{
	switch (s)
	{
		case 0: break;
		case 1: break;
		case 2: printf("+"); break;
		case 3: printf("-"); break;
		case 4: printf("*"); break;
		case 5: printf("/"); break;
		case 6: printf("%%"); break;
		case 7: printf(">"); break;
		case 8: printf("<"); break;
	}
}

int main()
{
	FILE* in;
	char symbol;
	precedence token;
	int n = 0;
	stack[0] = eos;
	char input;
	int i = 0;

	fopen_s(&in, "in.txt", "r");

	while (!feof(in))
	{
		fscanf_s(in, "%c ", &input);
		if (input != ' ')
		{
			expr[i] = input;
			i++;
		}
	}
	printf("경제통상학부 2016110398 신대희\n");
	printf("Postfix: ");
	
	for(token = get_token(&symbol, &n); token != eos ; token = get_token(&symbol, &n))
	{
		if (token == operand)
			printf("%c", symbol);
		else if (token == rparen)
		{
			while (stack[top] != lparen)
			{
				print_token(pop());
			}
			pop();
		}
		else
		{
			while (isp[stack[top]] >= icp[token])
			{
				print_token(pop());
			}
			push(token);
		}
	}
	while ((token = pop()) != eos)
	{
		print_token(token);
	}
	printf("\n");
	fclose(in);
	return 0;

}