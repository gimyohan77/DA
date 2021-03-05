#include <stdio.h>
#include <stdlib.h>

typedef struct node *treePointer;
typedef struct node {
	int data;
	treePointer lchild;
	treePointer rchild;
};

#define MALLOC(p,s)\
	if(!((p) = (node*)malloc(s))){\
		fprintf(stderr, "insufficien memory");\
		exit(EXIT_FAILURE);\
	}

#define REALLOC(p,s)\
	if(!((p) = (node*)realloc(p,s))){\
		fprintf(stderr, "insufficient memory");\
		exit(EXIT_FAILURE);\
	}

void inorder(treePointer ptr)
{
	if (ptr)
	{
		inorder(ptr->lchild);
		printf("%d ", ptr->data);
		inorder(ptr->rchild);
	}
}

void addtree(treePointer tree, int x, int y)
{
	treePointer a1, a2;
	int k = tree->data;
	MALLOC(a1, sizeof(*a1));
	MALLOC(a2, sizeof(*a2));
	a1->data = k / x;
	a1->lchild = tree->lchild;
	a1->rchild = tree->rchild;
	tree->lchild = a1;
	a2->data = k / y;
	a2->rchild = tree->rchild;
	a2->lchild = tree->lchild;
	tree->rchild = a2;
	if (a1->data > 1) addtree(a1, x, y);
	else { a1->lchild = NULL; a1->rchild = NULL; }
	if (a2->data > 1) addtree(a2, x, y);
	else { a2->lchild = NULL; a2->rchild = NULL; }
}


int main()
{
	int n, x, y;
	treePointer tree;
	MALLOC(tree, sizeof(*tree));
	printf("n: ");
	scanf_s("%d", &n);
	printf("x: ");
	scanf_s("%d", &x);
	printf("y: ");
	scanf_s("%d", &y);
	tree->data = n;
	tree->lchild = NULL;
	tree->rchild = NULL;
	addtree(tree, x, y);
	inorder(tree);

	return 0;
}