/*****************************************************************
 * File Name:   Q3.c
 * Author:      Mikaela Montaos
 *              Engineering School, NPU
 * description: Lab Q3 solved
 *              Using queue structure, reverse sequence to the nth element
 *              1 2 3 4 5 6 7 8 9 10	=>	5 4 3 2 1 6 7 8 9 10
 ****************************************************************/

#include <stdio.h>

#define MAX 10

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

void reverseToNth(struct queue* qu, struct queue* nth) {
	reverse(qu);
	for (int i = 0; i < MAX; i++) {
		int data;
		if (i >= 5) {
			insert_que(nth, qu->que[i]);
		}
	}

	reverse(qu);
	for (int i = 0; i < MAX; i++) {
		int data;
		if (i >= 5) {
			insert_que(nth, qu->que[i]);
		}
	}
}

int main(void) {
	struct queue q;
	init_que(&q);

	printf("Insert to queue\n");
	insert_que(&q, 1);
	insert_que(&q, 2);
	insert_que(&q, 3);
	insert_que(&q, 4);
	insert_que(&q, 5);
	insert_que(&q, 6);
	insert_que(&q, 7);
	insert_que(&q, 8);
	insert_que(&q, 9);
	insert_que(&q, 10);
	print_que(&q);

	printf("Reverse sequence to the fifth element\n");
	struct queue nth;
	init_que(&nth);
	reverseToNth(&q, &nth);
	print_que(&nth);

	return 0;
}