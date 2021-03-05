#include <stdio.h>
#include <stdlib.h>

#define MALLOC(p,s)\
if (!((p) = (Tree*)malloc(s))){\
	fprintf(stderr, "insufficien memory");\
	exit(EXIT_FAILURE);\
}

#define REALLOC(p,s)\
if (!((p) = (Tree*)realloc(p, s))){\
	fprintf(stderr, "insufficient memory");\
	exit(EXIT_FAILURE);\
}

#define MAX_SIZE 256


typedef struct node* nodePointer;
typedef struct node {
	nodePointer next;
	int data;
}node;

typedef struct Tree* treePointer;
typedef struct Tree {
	treePointer left;
	treePointer right;
	int data;
}Tree;

nodePointer root = NULL;
int size = 0;

treePointer queue[MAX_SIZE];
int rear = 0;
int front = 0;

nodePointer insert(nodePointer root, int data) {
	if (root == NULL) {
		root = (node*)malloc(sizeof(node));
		root->next = NULL;
		root->data = data;
		size++;
		return root;
	}
	else {
		root->next = insert(root->next, data);
		return root;
	}
}

void qfull()
{
	fprintf(stderr, "Queue is FUll");
	exit(EXIT_FAILURE);
}

treePointer qempty()
{
	fprintf(stderr, " ");
	exit(EXIT_FAILURE);
	treePointer rtn;
	MALLOC(rtn, sizeof(*rtn));
	rtn->data = -1;
	rtn->left = NULL;
	rtn->right = NULL;
	return rtn;
}

void addq(treePointer item)
{
	if (rear == MAX_SIZE) qfull();
	queue[++rear] = item;
}

treePointer deleteq()
{
	if (front == rear) return qempty();
	return queue[++front];
}

void levelorder(treePointer ptr)
{
	front = 0;
	rear = 0;
	if (!ptr) return;
	addq(ptr);
	for (; ;) {
		ptr = deleteq();
		if (ptr) {
			printf("%d ", ptr->data);
			if (ptr->left) addq(ptr->left);
			if (ptr->right) addq(ptr->right);
		}
		else break;
	}
}

int main() 
{
	printf("학부 : 경제통상학부 학번 : 2016110398 이름 : 신대희\n");
	int inputNum = 0;
	printf("Scanf : ");
	scanf_s("%d", &inputNum);
	Tree binaryTree[MAX_SIZE];
	printf("\n");
	for (int i = 1; i <= inputNum; i++) 
	{
		int key = inputNum;
		root = insert(root, key-i+1);
		binaryTree[i].data = root->data;
		binaryTree[i].left = NULL;
		binaryTree[i].right = NULL;
		root = root->next;

		if (i % 2 == 0) {
			binaryTree[i / 2].left = &binaryTree[i];
		}
		else {
			binaryTree[i / 2].right = &binaryTree[i];
		}
	}

	levelorder(&binaryTree[1]);

	return 0;
}