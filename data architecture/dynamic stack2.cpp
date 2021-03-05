#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_STACK_SIZE 100

typedef struct {
	int key;
}element;

int top = -1;
int stacksize = 1;

#define MALLOC(p,s)\
	if(!((p)=(element*) malloc(s))){\
		fprintf(stderr,"insufficient memory");\
		exit(EXIT_FAILURE);\
	}
#define REALLOC(p,s)\
	if(!((p)=(element*) realloc(p,s))){\
		fprintf(stderr,"insufficient memory");\
		exit(EXIT_FAILURE);\
	}

element* stack;
void pop() {
	top--;
	return;
}

void push(int key) {
	top++;
	stack[top].key = key;
	stacksize += 1;
}

void printStack() {
	for (int i = 0; i <= top;i++) {
		printf("%d ", stack[i].key);
	}
}

int main()
{
	FILE* in;
	char temp[101] = { NULL };
	char command[101] = { NULL };
	int j = 0;
	int k = 0;

	printf("2016118168 영어영문학과 강지혜\n");
	fopen_s(&in, "in.txt", "r");
	fgets(temp, 100, in);
	while (temp[j] != NULL) {
		if (temp[j] != ' ') {
			command[k] = temp[j];
			k++;
			j++;
		}
		else { j++; };
	}


	int i = 0;
	int isfirstA = 1;
	int capacity = 1;

	while (1) {
		if (i > k) {
			break;
		}
		if (command[i] == 'E') {
			break;
		}
		if (isalpha(command[i])) {
			if (command[i] == 'A') {
				if (isfirstA) {
					MALLOC(stack, capacity * sizeof(*stack));
					push(command[i + 1] - 48);
					printf("Stack capacity: %d\n", capacity);
					printStack();
					puts("");
					i++;
					isfirstA = 0;
				}
				else {

					if (stacksize > capacity) {
						REALLOC(stack, 2 * capacity * sizeof(*stack));
						capacity *= 2;
						push(command[i + 1] - 48);
						printf("Stack capacity: %d\n", capacity);
						printStack();
						puts("");
						i++;
					}
					else {
						push(command[i + 1] - 48);
						printf("Stack capacity: %d\n", capacity);
						printStack();
						puts("");
						i++;
					}


				}

			}
			if (command[i] == 'R') {
				if (top == -1) {
					printf("stack empty");
					break;
				}
				pop();
				printf("Stack capacity: %d\n", capacity);
				printStack();
				puts("");
				i++;
			}

		}
		else if (isdigit(command[i])) {
			i++;
		}
	}

}