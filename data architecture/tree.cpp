#include <stdio.h>
#include <stdlib.h>

typedef struct node *treePointer;
typedef struct node {
	char data;
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
		printf("%c ", ptr->data);
		inorder(ptr->rchild);
	}
}

void preorder(treePointer ptr)
{
	if (ptr)
	{
		printf("%c ", ptr->data);
		preorder(ptr->lchild);
		preorder(ptr->rchild);
	}
}

int main()
{
	treePointer tree;
	MALLOC(tree, sizeof(*tree));
	tree->data = 'A';
	tree->lchild = NULL;
	tree->rchild = NULL;
	treePointer a, b, c, d, e, f;
	MALLOC(a, sizeof(*a));
	MALLOC(b, sizeof(*b));
	MALLOC(c, sizeof(*c));
	MALLOC(d, sizeof(*d));
	MALLOC(e, sizeof(*e));
	MALLOC(f, sizeof(*f));
	c->data = 'C'; c->lchild = a; c->rchild = e;
	a->data = 'A'; a->rchild = b; a->lchild = NULL;
	b->data = 'B'; b->rchild = NULL; b->lchild = NULL;
	e->data = 'E'; e->lchild = d; e->rchild = f;
	d->data = 'D'; d->lchild = NULL; d->rchild = NULL;
	f->data = 'F'; f->lchild = NULL; f->rchild = NULL;
	tree = c;
	printf("학부:경제통상학부 학번:2016110398 이름:신대희\n");
	printf("문제1: ");
	inorder(tree);
	printf("\n");
	printf("문제2: ");
	preorder(tree);
	printf("\n");

	return 0;
}