#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct node* nodePointer;
typedef struct node {
	int data;
	nodePointer link;
};
int compare(int mid, int searchNum) {
	if (searchNum > mid) return -1;
	else if (searchNum == mid) return 0;
	else if (searchNum < mid) return 1;
}
int binSearch(int list[], int searchNum, int left, int right) {
	int middle;
	while (left <= right) {
		middle = (left + right) / 2;
		switch (compare(list[middle], searchNum)) {
		case -1:
			left = middle + 1;
			break;
		case 0:
			return middle;
		case 1:
			right = middle - 1;
		}
	}
	return -1;
}
void P1() {
	FILE* fp;
	int K = 3, n = 4;
	int* list;
	fopen_s(&fp, "in1.txt", "r");
	fscanf_s(fp, "%d", &K);
	fscanf_s(fp, "%d", &n);

	list = (int*)malloc(sizeof(*list) * n);

	for (int i = 0; i < n; i++) {
		int tmp;
		fscanf_s(fp, "%d", &tmp);
		list[i] = tmp;
	}

	printf("문제1 : %d\n", binSearch(list, K, 0, n - 1));
	
}
void push(nodePointer* list, int data) {
	nodePointer ptr;
	nodePointer node;
	node = (nodePointer)malloc(sizeof(*node));
	node->data = data;
	node->link = NULL;
	ptr = *list;

	if (*list == NULL) {
		(*list) = node;
	}
	else {
		if ((*list)->data < node->data) {
			node->link = (*list);
			(*list) = node;
		}
		else {
			while (ptr->link != NULL && ptr->link->data > node->data) {
				ptr = ptr->link;
			}
			if (ptr->link == NULL) {
				ptr->link = node;
			}
			else {
				node->link = ptr->link;
				ptr->link = node;
			}
		}
	}
}
void printList(nodePointer list) {
	nodePointer ptr;
	ptr = list;
	while (ptr != NULL) {
		printf("%d ", ptr->data);
		ptr = ptr->link;
	}
	printf("\n");
}
void P2() {
	FILE* fp;
	int n;
	nodePointer list = NULL;
	fopen_s(&fp, "in2.txt", "r");
	fscanf_s(fp, "%d", &n);

	while (!feof(fp)) {
		int tmp;
		fscanf_s(fp, "%d", &tmp);
		push(&list, tmp);
	}
	printf("문제2 : ");
	printList(list);
}
void push_3(nodePointer *list, int data) {
	nodePointer ptr;
	nodePointer node;
	node = (nodePointer)malloc(sizeof(*node));
	node->data = data;
	node->link = NULL;
	ptr = (*list);

	if ((*list) == NULL) {
		(*list) = node;
	}
	else {
		while (ptr->link != NULL) {
			ptr = ptr->link;
		}
		ptr->link = node;
	}
	
}
void pop(nodePointer* list) {
	nodePointer ptr1;
	ptr1 = *list;
	(*list) = (*list)->link;
	free(ptr1);
}
void P3() {
	FILE* fp;
	nodePointer list = NULL;
	fopen_s(&fp, "in3.txt", "r");

	while (!feof(fp)) {
		int tmp;
		fscanf_s(fp, "%d", &tmp);
		if (tmp > 0) {
			push_3(&list, tmp);
		}
		else {
			pop(&list);
		}	
	}
	printf("문제3 : ");
	printList(list);
}


typedef struct poly {
	int coef;
	int expon;
};
poly terms[1000];
int avail;
void attach(int coef, int expon) {
	terms[avail].coef = coef;
	terms[avail].expon = expon;
	avail++;
}
int compare_4(int A, int B) {
	if (A > B) return 1;
	else if (A == B) return 0;
	else if (A < B) return -1;
}
void padd(int startA, int finishA, int startB, int finishB, int* startD, int* finishD) {
	int coefficint;
	*startD = avail;
	while (startA <= finishA && startB <= finishB) {
		switch (compare_4(terms[startA].expon, terms[startB].expon)) {
		case -1:
			attach(terms[startB].coef, terms[startB].expon);
			startB++;
			break;
		case 0:
			coefficint = terms[startA].coef + terms[startB].coef;
			if (coefficint)
				attach(coefficint, terms[startA].expon);
			startA++;
			startB++;
			break;
		case 1:
			attach(terms[startA].coef, terms[startA].expon);
			startA++;
			break;
		}
	}
	for (;startA <= finishA; startA++)
		attach(terms[startA].coef, terms[startA].expon);
	for (;startB <= finishB; startB++)
		attach(terms[startB].coef, terms[startB].expon);

	*finishD = avail-1;
}
void P4() {
	FILE* fp;
	int N, M;
	fopen_s(&fp, "in4.txt", "r");
	fscanf_s(fp, "%d %d", &N, &M);
	int startA, finishA, startB, finishB, startD, finishD;
	startA = 0;
	finishA = N - 1;
	startB = N;
	finishB = N + M - 1;
	avail = finishB + 1;

	for (int i = startA; i <= finishA; i++) {
		fscanf_s(fp, "%d %d", &terms[i].coef, &terms[i].expon);
	}
	for (int i = startB; i <= finishB; i++) {
		fscanf_s(fp, "%d %d", &terms[i].coef, &terms[i].expon);
	}

	padd(startA, finishA, startB, finishB, &startD, &finishD);
	printf("문제4 : ");
	for (int i = startD; i <= finishD; i++) {
		printf("%d %d ", terms[i].coef, terms[i].expon);
	}
	printf("\n");
}
int main(void) {
	printf("학과 : 컴퓨터학부 학번 : 2017113301 이름 : 김재현\n");

	P1();
	P2();
	P3();
	P4();

	return 0;
}