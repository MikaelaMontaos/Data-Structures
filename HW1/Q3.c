/***********************************************************
 * File Name: Q3.c
 * Author:    Mikaela Montaos
 *            Engineering School, NPU
 * description: Homework Q3 solved
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

// Question 3 delete all dupes and to leave only 1 value for each
void Delete_Dupl_Node(LNode *L) { // Head 1 2 1 3 2 NULL
    LNode *p1, *p2, *d; // p1=pointer1, p2=pointer2, d=delete
    p1 = L;

    while (p1 != NULL && p1->next != NULL) { // 1 == 2?
        p2 = p1; // 1(p2, p1)
        while (p2->next != NULL) {
            if (p1->data == p2->next->data) { // 1 == 1?    for 1st loop
                d = p2->next; // d = 1
                p2->next = p2->next->next; // move -> from 2->1 to 2->3
                free(d); // delete 1
            } 
            else p2 = p2->next;
        }
        p1 = p1->next; // 1(p1)->1 moves to 1->1(p1)
    }
}

int main(void) {
    LNode *a;
    a = create_LinkList();
    printf("Original linked list\n");
    printList(a);

    Delete_Dupl_Node(a);
    printf("Delete_Dupl_Node function\n");
    printList(a);

    return 0;
}
