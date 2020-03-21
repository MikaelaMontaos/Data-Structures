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

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0

typedef int Status;
typedef char ElemType;

typedef struct Qnode {
    ElemType data;
    struct Qnode* next;
} QNode;

typedef struct link_queue {
    QNode* front, * rear;
} LinkQueue;

LinkQueue* Init_LinkQueue(void) {
    LinkQueue* q = (LinkQueue*)malloc(sizeof(LinkQueue));
    QNode* p = (QNode*)malloc(sizeof(QNode));
    
    p->next = NULL;
    q->front = q->rear = p;
    
    return(q);
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

Status Delete_LinkQueue(LinkQueue* q, ElemType* x) {
    QNode* p;
    if (q->front == q->rear) return ERROR;
    
    p = q->front->next;
    while (p->data != x) {
        p = p->next;
        q->front = p;
    }
    q->front->next = p->next;
    q->front->next = p->next;

    if (p == q->rear) q->rear = q->front;
    free(p);
    return OK;
}

void print_que(LinkQueue* q) {
    QNode* p;
    p = q->front;
    printf("Front->");
    p = p->next;
    while (p != NULL) {
        printf("%c", p->data);
        p = p->next;
        printf("->");
    }
    printf("Rear\n\n");
}

void finalLocation(LinkQueue* q) {
    QNode* p;
    if (q->front == q->rear) return ERROR;

    p = q->front->next;
    printf("Element in the front of the queue is: %c\n", p->data);

    while (p->next != NULL)
        p = p->next;
    printf("Element in the rear of the queue is: %c\n", p->data);
}

int main(void) {
    LinkQueue* q = Init_LinkQueue();
    Insert_CirQueue(q, 'd');
    Insert_CirQueue(q, 'e');
    Insert_CirQueue(q, 'b');
    Insert_CirQueue(q, 'g');
    Insert_CirQueue(q, 'h');
    print_que(q);

    printf("Delete d and e\n");
    Delete_LinkQueue(q, 'd');
    Delete_LinkQueue(q, 'e');
    print_que(q);
    
    printf("Insert i j k l m\n");
    Insert_CirQueue(q, 'i');
    Insert_CirQueue(q, 'j');
    Insert_CirQueue(q, 'k');
    Insert_CirQueue(q, 'l');
    Insert_CirQueue(q, 'm');
    print_que(q);

    printf("Delete b\n");
    Delete_LinkQueue(q, 'b');
    print_que(q);

    printf("Insert n o p q r\n");
    Insert_CirQueue(q, 'n');
    Insert_CirQueue(q, 'o');
    Insert_CirQueue(q, 'p');
    Insert_CirQueue(q, 'q');
    Insert_CirQueue(q, 'r');
    print_que(q);

    finalLocation(q);

    return 0;
}