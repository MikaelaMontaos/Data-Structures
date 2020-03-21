/***********************************************************
 * File Name:   Q3.c
 * Author:      Mikaela Montaos
 *              Engineering School, NPU
 * description: Homework Q3 solved
 *              Using stack structure, Find and display pairs of consecutive values
				If the count of elements is odd then ignore the top element
				4, 5, -2, -3, 11, 10, 5, 6, 20
				(4 5), (-2 -3), (11 10), (5 6)
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

void consecutive(Stk_Node* list) {
	Stk_Node* p = list;
	if (p == NULL) printf("Empty LL\n");
	while (p->next != NULL) {
		if (p->data < p->next->data && p->next->data < p->data + 2)
			printf("(%d, %d)", p->data, p->next->data);
		else if(p->data > p->next->data && p->next->data > p->data -2)
			printf("(%d, %d)", p->data, p->next->data);
		p = p->next;
	}
}

int main(void) {
	Stk_Node* S = Init_Link_Stack();
	push(S, 4);
	push(S, 5);
	push(S, -2);
	push(S, -3);
	push(S, 11);
	push(S, 10);
	push(S, 5);
	push(S, 6);
	push(S, 20);
	printStkList(S);

	printf("Consecutive sequence\n");
	consecutive(S);

	return 0;
}