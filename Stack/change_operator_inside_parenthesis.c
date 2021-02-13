/*
Remove parenthesis and change operators inside the parenthesis (+ to -, - to +)

x - (y + z)
Output:
x - y - z

x - (y - z - (u + v)) - w
Output:
x - y + z + u - v - w
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

void parenthesis(Stk_Node *list) {
	Stk_Node *p = list->next;
	if (p == NULL) printf("Empty stack\n");
	
	char minus = '-';
	char plus = '+';
	char open = '(';
	char close = ')';
	while (p != NULL) {
		if (p->data == open) {
			p = p->next;
			while(p->data != close) {
			    if (p->data == minus) {
			        printf("+ ");
			        p = p->next;
		        }
		        else if (p->data == plus) {
			        printf("- ");
			        p = p->next;
		        }
		        else if(p->data == open) {
		            p = p->next;
		        }
		        else {
		            printf("%c ", p->data);
			        p = p->next;
		        }
			}
			p = p->next;
		}
		else if(p->data == close) {
		    p = p->next;
		}
		else {
			printf("%c ", p->data);
			p = p->next;
		}
	}
	printf("\n\n");
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

	printf("Removing parenthesis and changing operator(s)...\n");
	parenthesis(S);

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

	printf("Removing parenthesis and changing operator(s)...\n");
	parenthesis(S2);

	return 0;
}