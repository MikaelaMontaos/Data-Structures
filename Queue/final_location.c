/*****************************************************************
 * File Name:   Q4.c
 * Author:      Mikaela Montaos
 *              Engineering School, NPU
 * description: Lab Q4 solved
 *              Using circular queue, find the final locations of front & rear after the following operations
 *              enqueue: d e b g h
                dequeue: d e
                enqueue: i j k l m
                dequeue: b
                enqueue: n o p q r
 ****************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0

typedef struct Queue
{
    char data;
    struct Queue *next;
} queue;

typedef struct Link
{
    queue *front, *rear;
} link;

link *init(void)
{
    link *l = (link *)malloc(sizeof(link));
    queue *q = (queue *)malloc(sizeof(queue));

    q->next = NULL;
    l->front = l->rear = q;

    return l;
}

int enqueue(link *l, char e)
{
    queue *q;
    q = (queue *)malloc(sizeof(queue));
    if (!q)
        return ERROR;

    q->data = e;
    q->next = NULL;
    l->rear->next = q;
    l->rear = q;

    return OK;
}

int dequeue(link *l, char e)
{
    queue *q;
    if (l->front == l->rear)
        return ERROR;

    q = l->front->next;
    while (q->data != e)
    {
        q = q->next;
        l->front = q;
    }
    l->front->next = q->next;
    l->front->next = q->next;

    if (q == l->rear)
        l->rear = l->front;
    free(q);

    return OK;
}

void print(link *l)
{
    queue *q;
    q = l->front;
    printf("Front -> ");
    q = q->next;
    while (q != NULL)
    {
        printf("%c ", q->data);
        q = q->next;
        printf("-> ");
    }
    printf("Rear\n\n");
}

void finalLocation(link *l)
{
    queue *q;
    if (l->front == l->rear)
        return ERROR;

    printf("Final location...\n");
    q = l->front->next;
    printf("Front: %c\n", q->data);

    while (q->next != NULL)
        q = q->next;
    printf("Rear: %c\n", q->data);
}

int main(void)
{
    link *q = init();
    enqueue(q, 'd');
    enqueue(q, 'e');
    enqueue(q, 'b');
    enqueue(q, 'g');
    enqueue(q, 'h');
    printf("Current queue:\n");
    print(q);

    printf("Deleting d and e...\n");
    dequeue(q, 'd');
    dequeue(q, 'e');
    printf("Current queue:\n");
    print(q);

    printf("Inserting i j k l m...\n");
    enqueue(q, 'i');
    enqueue(q, 'j');
    enqueue(q, 'k');
    enqueue(q, 'l');
    enqueue(q, 'm');
    printf("Current queue:\n");
    print(q);

    printf("Deleting b...\n");
    dequeue(q, 'b');
    printf("Current queue:\n");
    print(q);

    printf("Inserting n o p q r...\n");
    enqueue(q, 'n');
    enqueue(q, 'o');
    enqueue(q, 'p');
    enqueue(q, 'q');
    enqueue(q, 'r');
    printf("Current queue:\n");
    print(q);

    finalLocation(q);

    return 0;
}