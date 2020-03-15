/*************************************************************
 * File Name: Q3.c
 * Author:    Mikaela Montaos
 *            Engineering School, NPU
 * Description: Homework Q3 solved
 *************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef int ElemType;

// Create circular LL

LNode *circular_LinkList(void) {
    int data;
    LNode *head, *p, *q;
    head = p = (LNode *) malloc(sizeof (LNode));
    head->next = NULL;
    do {
        scanf("%d", & data);
        q = (LNode *) malloc(sizeof (LNode));
        q->data = data;
        q->next = p->next;
        p->next = q;
        p = q;
    } while (getchar() != '\n');
    p->next = head;
    return (head);
}

void cir_printList(LNode* list) {
    LNode *head;
    head = list;
    printf("Head");
    while (1) {
        printf("=>");
        list = list->next;
        if (list->next == head) {
            printf("%d=>Head\n", list->data);
            break;
        } else
            printf("%d", list->data);
    }
}

// Question 3 Circular LL monkey king

void monkey(LNode *L) { // Head->1->2->3->4->5->NULL
    printf("Enter total number of monkeys = ");
    int monkey;
    scanf("%d", &monkey);
    printf("Enter m value = ");
    int m;
    scanf("%d", &m);
    if(monkey < m) printf("Invalid number\n");

    LNode *mon = L;
    int count = 0;
    while (mon != NULL && count != m) {
        mon = mon->next;
        count++;
    }
    if (mon == NULL) printf("Empty LL\n");
    monkey = mon->data;
    printf("The king will be %d", monkey);
}


int main(void) {
    LNode *cir = circular_LinkList();
    printf("Circular LL = ");
    cir_printList(cir);
    
    printf("Josephus problem/Monkey king\n");
    monkey(cir);

    return 0;
}