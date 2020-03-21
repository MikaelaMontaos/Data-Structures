/***********************************************************
 * File Name:   Q4.c
 * Author:      Mikaela Montaos
 *              Engineering School, NPU
 * description: Homework Q4 unfinished
 *              Using stack structure, switch - to + and vice versa while removing parenthesis
				x - (y + z)		=>		x - y - z
				x - (y - z - (u + v)) - w		=>		x - y + z + u + v - w
 ***********************************************************/
#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define TRUE 0
#define FALSE -1

typedef int Status;
typedef char ElemType;

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
			printf("%c\nEnd of stack\n", list->data);
			break;
		}
		else printf("%c ", list->data);
	}
}

void minusToPlus(Stk_Node* list) {
	Stk_Node* p = list->next;
	if (p == NULL) printf("Empty LL\n");
	char m = '-';
	char pl = '+';
	char o = '(';
	char c = ')';
	while (p != NULL) {
		if (p->data == o) {
			p = p->next;
		}
		else if (p->data == m) {
			printf("+ ");
			p = p->next;
		}
		else if (p->data == pl) {
			printf("- ");
			p = p->next;
		}
		else if (p->data == c) {
			p = p->next;
		}
		else {
			printf("%c ", p->data);
			p = p->next;
		}
	}
	printf("\n");
}

int main(void) {
	Stk_Node* S = Init_Link_Stack();
	push(S, ')');
	push(S, 'z');
	push(S, '+');
	push(S, 'y');
	push(S, '(');
	push(S, '-');
	push(S, 'x');
	printStkList(S);

	printf("Remove parenthesis and switch - to + and vice versa\n");
	minusToPlus(S);

	Stk_Node* S2 = Init_Link_Stack();
	push(S2, 'w');
	push(S2, '-');
	push(S2, ')');
	push(S2, ')');
	push(S2, 'v');
	push(S2, '+');
	push(S2, 'u');
	push(S2, '(');
	push(S2, '-');
	push(S2, 'z');
	push(S2, '-');
	push(S2, 'y');
	push(S2, '(');
	push(S2, '-');
	push(S2, 'x');
	printStkList(S2);

	printf("Remove parenthesis and switch - to + and vice versa\n");
	minusToPlus(S2);

	return 0;
}