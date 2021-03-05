#include <stdio.h>
#include <stdlib.h>

typedef struct node* treePointer;
typedef struct node {
	char data;
	treePointer lchild;
	treePointer rchild;
};

int p = 0;

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

node* itersearch(treePointer tree, int k)
{
	while (tree)
	{
		if (k == tree->data) return tree;
		if (k < tree->data) tree = tree->lchild;
		else tree = tree->rchild;
	}
	return NULL;
}

node* modifiedsearch(treePointer tree, int k)
{
	treePointer temp = tree;
	while (tree)
	{
		temp = tree;
		if (k < tree->data) tree = tree->lchild;
		else if (k > tree->data) tree = tree->rchild;
		else return NULL;
	}
	return temp;
}

void insert(treePointer* root, int k)
{
	treePointer ptr;
	treePointer temp = modifiedsearch(*root, k);
	if (temp || !(*root))
	{
		MALLOC(ptr, sizeof(*ptr));
		ptr->data = k;
		ptr->lchild = ptr->rchild = NULL;
		if (*root)
			if (k < temp->data) temp->lchild = ptr;
			else if (k == temp->data) p = 1;
			else temp->rchild = ptr;
		else *root = ptr;
	}
	else p = 1;
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

int main()
{
	FILE* in;
	char k;
	int n,m;

	treePointer bst;
	node* t;
	MALLOC(bst, sizeof(*bst));
	bst = NULL;

	printf("학부 : 경제통상학부 이름 : 신대희 학번 : 2016110398\n");
	fopen_s(&in, "in.txt", "r");

	while (!feof(in))
	{
		fscanf_s(in, "%c ", &k);
		fscanf_s(in, "%d ", &n);

		if (k == 'A')
		{
			insert(&bst, n);
			printf("%c %d:", k, n);
			if (p == 1) printf("%d cannot be inserted", n);
			else inorder(bst);
			printf("\n");

			p = 0;
		}
		else if (k == 'S')
		{
			t = itersearch(bst, n);
			printf("%c %d:", k, n);
			if (t != NULL) printf("%d is in T", n);
			else if (t == NULL) printf("%d is not in T", n);
			printf("\n");
		}
	}



	free(bst);
	fclose(in);
	return 0;
}