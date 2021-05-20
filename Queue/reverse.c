// Reverse a queue without using other data structures (temporary array)

#include <stdio.h>

#define MAX 8

struct queue {
	int que[MAX];
	int rear;
	int front;
	int cnt;
};

void init(struct queue* qu) {
	qu->rear = 0;
	qu->front = 0;
	qu->cnt = 0;
}

void insert(struct queue* qu, int a) {
	if (qu->cnt != MAX) {
		qu->que[qu->rear % MAX] = a;
		qu->rear++;
		qu->cnt++;
	}
	else printf("Queue is full\n");
}

int pop(struct queue* qu) {
	int pop_value;
	if (qu->cnt != 0) {
		pop_value = qu->que[qu->front % MAX];
		qu->front++;
		qu->cnt--;
	}
	else printf("Queue is empty\n");
	return pop_value;
}

void print(struct queue* qu) {
	for (int i = 0; i < MAX; i++)
		printf("%d ", qu->que[i]);
	printf("\n");
}

void reverse(struct queue* qu) {
	if (qu->cnt != 0) {
		long long int data;
		data = pop(qu);
		reverse(qu);
		insert(qu, data);
	}
}

int main(void) {
	struct queue q;
	init(&q);
	insert(&q, 11);
	insert(&q, 9);
	insert(&q, 8);
	insert(&q, 12);
	insert(&q, 4);
	insert(&q, 13);
	insert(&q, 16);
	insert(&q, 7);
	print(&q);

	printf("Reversing queue...\n");
	reverse(&q);
	print(&q);

	return 0;
}
