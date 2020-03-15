/***********************************************************
 * File Name: Q4.c
 * Author:    Mikaela Montaos
 *            Engineering School, NPU
 * description: Homework Q4 solved
 ***********************************************************/
#include <stdio.h>
#include <stdlib.h>

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

// Question 4 reverse linked list
LNode *Reverse_Node(LNode *L) { // Head 1 2 3 NULL
    LNode *c, *p, *n; // c=current, p=previous, n=next
    c = L; // 1(c)->2->3->NULL
    p = NULL; // NULL(p)->1(c)->2->3->NULL
    while (c != NULL) { // p->c
        n = c->next; //    p->c->n
        c->next = p; //    p<-c->n
        p = c; //          <-p/c->n
        c = n; //          <-p->c/n
    }
    L = p; // NULL<-1<-2<-3(p/L)<-NULL
    return L;
}

void printRevList(LNode* list) {
    printf("Head");
    while (1) {
        printf("->");
        if (list->next == NULL) {
            printf("NULL\n");
            break;
        } else {
            printf("%d", list->data);
            list = list->next;
        }
    }
}

int main(void) {
    LNode *a;
    a = create_LinkList();
    printf("Original linked list\n");
    printList(a);

    LNode *r;
    r = Reverse_Node(a);
    printf("Reverse_Node function\n");
    printRevList(r); 

    return 0;
}
