// Reverse sequence to the n-th element

#include <stdio.h>
#include <stdlib.h>

#define MAX 10

struct queue
{
	int que[MAX];
	int rear;
	int front;
	int cnt;
};

void init(struct queue *qu)
{
	qu->rear = 0;
	qu->front = 0;
	qu->cnt = 0;
}

void insert(struct queue *qu, int a)
{
	if (qu->cnt != MAX)
	{
		qu->que[qu->rear % MAX] = a;
		qu->rear++;
		qu->cnt++;
	}
}

int pop(struct queue *qu)
{
	int pop_value;
	if (qu->cnt != 0)
	{
		pop_value = qu->que[qu->front % MAX];
		qu->front++;
		qu->cnt--;
	}
	else
		printf("Queue is empty\n");
	return pop_value;
}

void print(struct queue *qu)
{
	for (int i = 0; i < MAX; i++)
		printf("%d ", qu->que[i]);
	printf("\n");
}

void reverse(struct queue *qu)
{
	if (qu->cnt != 0)
	{
		long long int data;
		data = pop(qu);
		reverse(qu);
		insert(qu, data);
	}
}

void reverseToNth(struct queue *qu, struct queue *nth)
{
	int n;
	printf("Enter n-th number: ");
	scanf("%d", &n);

	if (n < MAX)
	{
		printf("Reversing queue...\n");
		reverse(qu);
		for (int i = (MAX - n); i < MAX; i++)
			insert(nth, qu->que[i]);
		
		reverse(qu);
		for (int i = n; i <= MAX; i++)
			insert(nth, qu->que[i]);
	}
	else
	{
		printf("Invalid number. Enter a number less than or equal to %d\n.", MAX);
		exit(1);
	}
}

int main(void)
{
	struct queue q;
	init(&q);
	for (int i = 0; i < MAX; i++)
	{
		insert(&q, i + 1);
	}
	print(&q);

	struct queue nth;
	init(&nth);
	reverseToNth(&q, &nth);
	print(&nth);

	return 0;
}