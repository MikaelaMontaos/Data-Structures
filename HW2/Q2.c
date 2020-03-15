/*************************************************************
 * File Name: Q2.c
 * Author:    Mikaela Montaos
 *            Engineering School, NPU
 * Description: Homework Q2 unfinished
 *************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Create int LL
typedef int ElemType;

typedef struct Lnode {
    ElemType data;
    struct Lnode *next;
} LNode;

LNode *create_LinkList(void) {
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
    return (head);
}

void printList(LNode* list) {
    printf("Head");
    while (1) {
        printf("->");
        list = list->next;
        if (list->next == NULL) {
            printf("%d->NULL\n", list->data);
            break;
        } else
            printf("%d", list->data);
    }
}

//Question 2 Add same index values and display result in LL
int LL_add(LNode *L1, LNode *L2) { 
    // Head->1->2->3->4->NULL, Head->5->6->7->8->NULL
    int n1, n2, sum;
    LNode *p1 = L1;
    LNode *p2 = L2;

    if (p1 == NULL || p2 == NULL) printf("Missing LL\n");

    while (p1 != NULL) {
        p1 = p1->next;
    }
    while (p2 != NULL) {
        n2 += p2->data;
        p2 = p2->next;
    }
    sum = n1 + n2;
    return sum;
}

int main(void) {
    LNode *l1, *l2;
    l1 = create_LinkList();
    printf("LL 1 = ");
    printList(l1);
    
    l2 = create_LinkList();
    printf("LL 2 = ");
    printList(l2);

    printf("LL add = %d", LL_add(l1, l2));

    return 0;
}