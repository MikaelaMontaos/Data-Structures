/*
Create a stack and sort it alphabetically
t r o s

Output:
o r s t
*/

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

Status pop(Stk_Node* top, ElemType* e) {
	Stk_Node* p;
	if (top->next == NULL) return ERROR;
	p = top->next;
	*e = p->data;
	top->next = p->next;
	free(p);
	return OK;
}

void printStkList(Stk_Node* list) {
	while (1) {
		list = list->next;
		if (list->next == NULL) {
			printf("%c\nEnd of stack\n\n", list->data);
			break;
		}
		else printf("%c ", list->data);
	}
}

void srt(Stk_Node* list) {
	Stk_Node* p1 = list;
	Stk_Node* p2;
	int sort;
	while (p1->next != NULL) {
		p2 = p1;
		while (p2->next != NULL) {
			if (p2->data > p2->next->data) {
				sort = p2->data;
				p2->data = p2->next->data;
				p2->next->data = sort;
			}
			p2 = p2->next;
		}
		p1 = p1->next;
	}
	if (p1 == NULL) printf("Empty LL\n");
}

int main(void) {
	Stk_Node* S = Init_Link_Stack();
	push(S, 's');
	push(S, 'o');
	push(S, 'r');
	push(S, 't');
	printStkList(S);

	printf("Sorting stack...\n");
	srt(S);
	printStkList(S);

	return 0;
}