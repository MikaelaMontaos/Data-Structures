/***********************************************************
 * File Name: Q2.c
 * Author:    Mikaela Montaos
 *            Engineering School, NPU
 * description: Homework Q2 unfinished
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


// Question 2 delete all elements with dupes
void Delete_Node_Value(LNode *L) { // Head 1 2 1 3 2 NULL
    LNode *p1, *p2, *d; 
    p1 = L;

    while (p1 != NULL && p1->next != NULL) { 
        p2 = p1; 
        while (p2->next != NULL) {
            if (p1->data == p2->next->data) { 
                d = p2->next; 
                p2->next = p2->next->next; 
                free(d); 
            } 
            else p2 = p2->next;
        }
        p1 = p1->next; 
    }
}

int main(void) {
    LNode *a;
    a = create_LinkList();
    printf("Original linked list\n");
    printList(a);

    Delete_Node_Value(a);
    printf("Delete_Node_Value function\n");
    printList(a);

    return 0;
}
