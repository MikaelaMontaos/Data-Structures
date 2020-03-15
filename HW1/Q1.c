/***********************************************************
 * File Name: Q1.c
 * Author:    Mikaela Montaos
 *            Engineering School, NPU
 * description: Homework Q1 solved
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

// Question 1 delete given element + its dupes

void Delete_LinkList_Node(LNode *L, int i) { // Head 1 2 1 3 NULL, i = 1
    LNode *p = L; // p=previous, n=next
    LNode *n = L->next;
    LNode *d; // d=delete

    while (n != NULL) {
        if (n->data == i) {
            d = n;
            p->next = n->next;
            free(d);
        }
        else p = n;
        n = n->next;
    }
    if (p == NULL) printf("No elements\n");
}

int main(void) {
    LNode *a;
    a = create_LinkList();
    printf("Original linked list\n");
    printList(a);

    // Question 1
    Delete_LinkList_Node(a, 1);
    printf("Delete_LinkList_Node function\n");
    printList(a);

    return 0;
}
