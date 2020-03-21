/***********************************************************
 * File Name:   Q2.c
 * Author:      Mikaela Montaos
 *              Engineering School, NPU
 * description: Homework Q2 unfinished
 *              Using stack structure, replace the element to the next biggest value
				5 3 2 10 6 8 1 4 12 7 4
				5->10, 3->10, 2->10, 10->12, 6->8, 8->12, 1->4, 4->12,
12->none, 7->none, 4->none
 ***********************************************************/
#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define TRUE 0
#define FALSE -1

typedef int Status;
typedef int ElemType;

typedef struct Stack_Node {
	ElemType data;
	struct Stack_Node* next;
} Stk_Node;

Stk_Node* Init_Link_Stack(void) {
	Stk_Node* top;
	top = (Stk_Node*)malloc(sizeof(Stk_Node));
	top->next = NULL;
	return (top);
}

Status push(Stk_Node* top, ElemType e) {
	Stk_Node* p;
	p = (Stk_Node*)malloc(sizeof(Stk_Node));

	if (!p)
		return ERROR;
	p->data = e;
	p->next = top->next;
	top->next = p;
	return OK;
}

Status pop(Stk_Node* top, int e) {
	Stk_Node* p = top->next;
	if (top->next == NULL) return ERROR;
	while (top->next != NULL && e != p->next->data) {
		p = p->next;
	}
	p->next = p->next->next;
	free(p);
	return OK;
}

void printStkList(Stk_Node* list) {
	while (1) {
		list = list->next;
		if (list->next == NULL) {
			printf("%d\tEnd of stack\n", list->data);
			break;
		}
		else printf("%d ", list->data);
	}
}

void switchElements(Stk_Node* list) {
	Stk_Node* p1 = list;
	Stk_Node* p2, * p3;
	int del, change;
	while (p1->next != NULL) {
		p2 = p1;
		while (p2->next != NULL) {
			if (p2->data > p2->next->data) {
				p3 = p2;
				while (p3->data < p2->data) {
					p3 = p3->next;
					if (p3->data > p2->data) {
						change = p3->data;
						p2->data = change;
					}
				}

			}
			p2 = p2->next;
		}
		p1 = p1->next;
	}
	if (p1 == NULL) printf("Empty LL\n");
}

int main(void) {
	Stk_Node* S = Init_Link_Stack();
	push(S, 4);
	push(S, 7);
	push(S, 12);
	push(S, 4);
	push(S, 1);
	push(S, 8);
	push(S, 6);
	push(S, 10);
	push(S, 2);
	push(S, 3);
	push(S, 5);
	printStkList(S);

	printf("Switch values to next bigger value in the stack\n");
	switchElements(S);
	printStkList(S);

	return 0;
}