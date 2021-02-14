/*
Convert integer to binary numbers
1 2 3 4 5 6 7

Output:
1 10 11 100 101 110 111
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 7

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

void genBin(unsigned n) {
	if (n > 1) genBin(n / 2);
	printf("%d", n % 2);
}

void convertToBinary(struct queue* qu) {
	unsigned int n;
	for (int i = 0; i < MAX; i++) {
		n = qu->que[i];
		genBin(n);
		printf(" ");
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
	print_que(&q);

	printf("1-7 binary numbers\n");
	convertToBinary(&q);

	return 0;
}