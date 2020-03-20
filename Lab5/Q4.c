/*****************************************************************
 * File Name:   Q4.c
 * Author:      Mikaela Montaos
 *              Engineering School, NPU
 * Description: Homework Q4 unfinished
				For empty stack display: f(S) = 0
				Otherwise display: fnew(S) = max(fprevious(S), 0) + topNum = max(nextNum, 0) + topNum = sum
/*****************************************************************/

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

Stk_Node Init_Link_Stack(void) {
	Stk_Node* top;
	top = (Stk_Node*)malloc(sizeof(Stk_Node));
	top->next = NULL;
	return*top;
}

Status push(Stk_Node* top, ElemType e) {
	Stk_Node* p = (Stk_Node*)malloc(sizeof(Stk_Node));
	if (!p) return ERROR;
	p->data = e;
	p->next = top->next;
	top->next = p;
	return OK;
}

void printStkList(Stk_Node* list) {
	int top, next, sum;

	if (list->next == NULL) {
		printf("f(S) = 0\n\n");
	}
	else {
		top = list->next->data;
		printf("fnew(S) = max(fprevious(S), 0) + %d = ", top);

		next = list->next->next->data;
		printf("max(%d, 0) + ", next);

		sum = top + next;
		printf("%d = ", top);
		printf("%d\n\n", sum);
	}

}

int main(void) {
	Stk_Node S = Init_Link_Stack();
	printf("Print empty stack...\n");
	printStkList(&S);
	int num;

	push(&S, 1);
	printf("Push 1\n");
	printStkList(&S);

	push(&S, 2);
	printf("Push 2\n");
	printStkList(&S);

	push(&S, -2);
	printf("Push -2\n");
	printStkList(&S);

	push(&S, 4);
	printf("Push 4\n");
	printStkList(&S);

	push(&S, 5);
	printf("Push 5\n");
	printStkList(&S);

	return 0;
}