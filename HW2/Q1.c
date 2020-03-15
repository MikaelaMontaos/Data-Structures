/*************************************************************
 * File Name: Q1.c
 * Author:    Mikaela Montaos
 *            Engineering School, NPU
 * Description: Homework Q1 unfinished
 *************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Create char LL
typedef char CElemType;

typedef struct Cnode {
    CElemType data;
    struct Cnode *next;
} CNode;

CNode *create_char_LinkList(void) {
    char data;
    CNode *head, *p, *q;
    head = p = (CNode *) malloc(sizeof (CNode));
    head->next = NULL;
    do {
        scanf("%c", &data);
        q = (CNode *) malloc(sizeof (CNode));
        q->data = data;
        q->next = p->next;
        p->next = q;
        p = q;
    } while (getchar() != '\n');
    return (head);
}

void c_printList(CNode* list) {
    printf("Head");
    while (1) {
        printf("->");
        list = list->next;
        if (list->next == NULL) {
            printf("%c->NULL\n", list->data);
            break;
        } else printf("%c", list->data);
    }
}

// Question 1 Sort from a-Z
void srt_LL(CNode *C) { // Head->D->A->C->A->G->NULL
    CNode *p1, *p2 = C;
    int sort;

    while (p1 != NULL) {
        p2 = p1;
        while (p2->next != NULL) {
            if (p2->data > p2->next->data) {
                sort = p2->data;
                p2->data = p2->next->data;
                p2->next->data = sort;
            }
            p2 = p2->next;
        }
        p1 = p1->next;
    }

    if (p1 == NULL) printf("Empty LL\n");
}

int main(void) {
    CNode *c1;
    c1 = create_char_LinkList();
    printf("Char Linked List 1 = ");
    c_printList(c1);

    srt_LL(c1);
    printf("Sorted Char Linked List = ");
    c_printList(c1);

    return 0;
}
