/*****************************************************************
 * File Name:   Q2.c
 * Author:      Mikaela Montaos
 *              Engineering School, NPU
 * description: Lab Q2 solved
 *              Using queue structure, reverse the sequence to a new queue without using other data structures
 *              11 9 8 12 4 13 16 7     =>  7 16 13 4 12 8 9 11
 ****************************************************************/

#include <stdio.h>

#define MAX 8

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
	for (int i = 0; i < MAX; i++)
		printf("%d ", qu->que[i]);
	printf("\n\n");
}

void reverse(struct queue* qu) {
	if (qu->cnt != 0) {
		long long int data;
		data = pop_que(qu);
		reverse(qu);
		insert_que(qu, data);
	}
}

int main(void) {
	struct queue q;
	init_que(&q);

	printf("Insert to queue\n");
	insert_que(&q, 11);
	insert_que(&q, 9);
	insert_que(&q, 8);
	insert_que(&q, 12);
	insert_que(&q, 4);
	insert_que(&q, 13);
	insert_que(&q, 16);
	insert_que(&q, 7);
	print_que(&q);

	printf("Reverse sequence\n");
	reverse(&q);
	print_que(&q);

	return 0;
}
