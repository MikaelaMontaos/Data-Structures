/*****************************************************************
 * File Name:   Q3.c
 * Author:      Mikaela Montaos
 *              Engineering School, NPU
 * description: Homework Q3 solved
 *              Using queue structure with maximum of 3 arrays, pop the largest letter once the max is reached when pushing a new letter
				Push A: C O D A
				Pop O: C D A
				Push B: C D A B
				Pop D: C A B
 ****************************************************************/

#include <stdio.h>

#define MAX 3

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
void insert_que(struct queue* qu, char a) {
	if (qu->cnt != MAX) {
		qu->que[(qu->rear) % MAX] = a;
		qu->rear++;
		qu->cnt++;
	}
	else {
		int aNum = a;
		for (int i = 0; i < MAX; i++) {
			if (qu->que[i + 1] > qu->que[i]) {
				qu->que[i + 1] = a;
				break;
			}
		}
	}
}

char pop_que(struct queue* qu) {
	char pop_value;
	if (qu->cnt != 0) {
		pop_value = qu->que[(qu->front) % MAX];
		qu->front++;
		qu->cnt--;
	}
	else
		printf("Empty queue\n");
	return pop_value;
}

void print_que(struct queue* qu) {
	for (int i = 0; i < MAX; i++) {
		printf("%c ", qu->que[i]);
	}
	printf("\n\n");
}

int main(void) {
	struct queue q;
	init_que(&q);
	printf("Original queue\n");
	insert_que(&q, 'C');
	insert_que(&q, 'O');
	insert_que(&q, 'D');
	print_que(&q);

	printf("Pushing A will automatically remove O\n");
	insert_que(&q, 'A');
	print_que(&q);

	printf("Pushing B will automatically remove D\n");
	insert_que(&q, 'B');
	print_que(&q);

	return 0;
}