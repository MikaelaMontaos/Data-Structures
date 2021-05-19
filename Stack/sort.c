// Create a stack and sort it alphabetically

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

int pop(stack* top, char* e) {
	stack* p;
	if (top->next == NULL) return ERROR;
	p = top->next;
	*e = p->data;
	top->next = p->next;
	free(p);
	return OK;
}

void print(stack* list) {
	while (1) {
		list = list->next;
		if (list->next == NULL) {
			printf("%c\nEnd of stack\n\n", list->data);
			break;
		}
		else printf("%c ", list->data);
	}
}

void sort(stack* list) {
	stack* cur = list;
	stack* prev;
	int sort;

	while (cur->next != NULL) {
		prev = cur;
		while (prev->next != NULL) {
			if (prev->data > prev->next->data) {
				sort = prev->data;
				prev->data = prev->next->data;
				prev->next->data = sort;
			}
			prev = prev->next;
		}
		cur = cur->next;
	}
	if (cur == NULL) printf("Empty stack\n");
}

int main(void) {
	stack* stk = init();
	push(stk, 's');
	push(stk, 'o');
	push(stk, 'r');
	push(stk, 't');
	print(stk);

	printf("Sorting stack...\n");
	sort(stk);
	print(stk);

	return 0;
}