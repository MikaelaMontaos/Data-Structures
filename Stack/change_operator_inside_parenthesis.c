/*
Remove parenthesis and change operators inside the parenthesis (+ to -, - to +)

x - (y + z)
Output:
x - y - z

x - (y - z - (u + v)) - w
Output:
x - y + z + u - v - w
*/

#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0

typedef struct Stack {
	char data;
	struct Stack* next;
} stack;

stack* init(void) {
	stack* top;
	top = (stack*)malloc(sizeof(stack));
	top->next = NULL;
	
	return (top);
}

int push(stack* top, char e) {
	stack* p;
	p = (stack*)malloc(sizeof(stack));

	if (!p)
		return ERROR;
	p->data = e;
	p->next = top->next;
	top->next = p;

	return OK;
}

int pop(stack* top, int e) {
	stack* p = top->next;
	if (top->next == NULL) return ERROR;
	while (top->next != NULL && e != p->next->data) {
		p = p->next;
	}

	p->next = p->next->next;
	free(p);

	return OK;
}

void print(stack* list) {
	while (1) {
		list = list->next;
		if (list->next == NULL) {
			printf("%c\nEnd of stack\n", list->data);
			break;
		}
		else printf("%c ", list->data);
	}
}

void parenthesis(stack *list) {
	stack *p = list->next;
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
	stack* list1 = init();
	push(list1, ')');
	push(list1, 'z');
	push(list1, '+');
	push(list1, 'y');
	push(list1, '(');
	push(list1, '-');
	push(list1, 'x');
	print(list1);

	printf("Removing parenthesis and changing operator(s)...\n");
	parenthesis(list1);

	stack* list2 = init();
	push(list2, 'w');
	push(list2, '-');
	push(list2, ')');
	push(list2, ')');
	push(list2, 'v');
	push(list2, '+');
	push(list2, 'u');
	push(list2, '(');
	push(list2, '-');
	push(list2, 'z');
	push(list2, '-');
	push(list2, 'y');
	push(list2, '(');
	push(list2, '-');
	push(list2, 'x');
	print(list2);

	printf("Removing parenthesis and changing operator(s)...\n");
	parenthesis(list2);

	return 0;
}
