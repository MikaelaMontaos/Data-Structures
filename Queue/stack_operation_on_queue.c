/*
Simulate stack push and pop operations using only one queue
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 3

typedef int Status;
typedef int ElemType;

// Queue structure
struct queue {
	int que[MAX];
	int rear;
	int front;
	int cnt;
};

void init_que(struct queue* qu) {
	qu->rear = 0;
	qu->front = 0;
	qu->cnt = 0;
}

void insert_que(struct queue* qu, int a) {
	if (qu->cnt != MAX) {
		qu->que[qu->rear % MAX] = a;
		qu->rear++;
		qu->cnt++;
	}
	else printf("Queue is full\n");
}

int pop_que(struct queue* qu) {
	int pop_value;
	if (qu->cnt != 0) {
		pop_value = qu->que[qu->front % MAX];
		qu->front++;
		qu->cnt--;
	}
	else printf("Queue is empty\n");
	return pop_value;
}

void print_que(struct queue* qu) {
	for (int i = 0; i < qu->cnt; i++)
		printf("%d ", qu->que[i]);
	printf("\n\n");
}

// Stack structure
typedef struct Node {
	ElemType data;
	struct Stack_Node* next;
} Node;

typedef struct Stack {
	Node* data;
	int count;
} Stack;

Stack* s;

void initStack() {
	s = (Stack*)malloc(sizeof(Stack));
	s->count = 0;
	s->data = NULL;
}

void push(struct queue* qu, int data) {
	insert_que(qu, data);
}

int pop(struct queue* qu) {
	int i;
	int n = qu->cnt;
	int r;
	for (i = 0; i < (n - 1); i++) {
		r = pop_que(qu);
		insert_que(qu, r);
	}
	r = pop_que(qu);
	return r;
}

void printQueueS(struct queue* q) {
	for (int i = 0; i <= q->cnt - 1; i++) {
		printf("%d ", q->que[i]);
	}
	printf("\n\n");
}

int main(void) {
	struct queue q;
	init_que(&q);

	int choice, num;
	do {
		printf("Type in choice\n");
		printf("Choice 1: Push\n");
		printf("Choice 2: Pop\n");
		printf("Choice 3: Exit\n");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			printf("\nPush number: ");
			scanf("%d", &num);
			push(&q, num);

			printf("Queue after push\n");
			printQueueS(&q);
			break;
		case 2:
			num = pop(&q);

			printf("Queue after pop\n");
			printQueueS(&q);
			break;
		case 3: default:
			printf("Exiting...\n");
			printf("Current queue: ");
			printQueueS(&q);
			return 0;
		}
	} while (1);

	return 0;
}