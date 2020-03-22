/*****************************************************************
 * File Name:   Q4.c
 * Author:      Mikaela Montaos
 *              Engineering School, NPU
 * description: Homework Q4 solved
 *              Using circular queue, get the total number of elements
 ****************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0

typedef int Status;
typedef int ElemType;

// Circular queue structure
typedef struct Qnode {
    ElemType data;
    struct Qnode* next;
} QNode;

typedef struct link_queue {
    QNode* front, * rear;
} LinkQueue;

LinkQueue* Init_LinkQueue(void) {
    LinkQueue* q;
    QNode* p;
    p = (QNode*)malloc(sizeof(QNode));
    p->next = NULL;
    q = (LinkQueue*)malloc(sizeof(LinkQueue));
    q->front = q->rear = p;
    return q;
}

Status Insert_CirQueue(LinkQueue* q, ElemType e) {
    QNode* p;
    p = (QNode*)malloc(sizeof(QNode));
    if (!p) return ERROR;
    p->data = e;
    p->next = NULL;
    q->rear->next = p;
    q->rear = p;
    return OK;
}

Status Delete_LinkQueue(LinkQueue* q, ElemType* e) {
    QNode* p;
    if (q->front == q->rear) return ERROR;
    p = q->front->next;
    *e = p->data;
    q->front->next = p->next;
    if (p == q->rear) q->rear == q->front;
    free(p);
    return OK;
}

void print_que(LinkQueue* q) {
    QNode* p;
    p = q->front;
    p = p->next;
    printf("Front->");
    while (p != NULL) {
        printf("%d->", p->data);
        p = p->next;
    }
    printf("Rear\n\n");
}

void get_num_elem(LinkQueue* q, int s, int f, int r) {
    QNode* p;
    p = q->front;
    int i = 0;
    while (p->data != r) {
        p = p->next;
        i++;
    }
    printf("There are %d elements in the queue\n", i);
}

int queue_size(LinkQueue* q) {
    QNode* p;
    p = q->front;
    p = p->next;
    int i = 0;
    while (p != NULL) {
        p = p->next;
        i++;
    }
    return i;
}

int queue_front(LinkQueue* q) {
    QNode* p;
    p = q->front;
    p = p->next;
    int i = p->data;
    return i;
}

int queue_rear(LinkQueue* q) {
    QNode* p;
    p = q->front;
    int i;
    while (p->next != NULL) {
        p = p->next;
        i++;
    }
    i = p->data;
    return i;
}

int main(void) {
    LinkQueue* q = Init_LinkQueue();
    Insert_CirQueue(q, 1);
    Insert_CirQueue(q, 2);
    Insert_CirQueue(q, 3);
    printf("Circular queue\n");
    print_que(q);

    int size = queue_size(q);
    printf("Queue size: %d\n", size);

    int front = queue_front(q);
    printf("Front of queue is: %d\n", front);

    int rear = queue_rear(q);
    printf("Rear of queue is: %d\n", rear);

    printf("\n");
    get_num_elem(q, size, front, rear);

    return 0;
}