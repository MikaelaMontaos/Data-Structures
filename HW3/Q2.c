/*************************************************************
 * File Name: Q2.c
 * Author:    Mikaela Montaos
 *            Engineering School, NPU
 * Description: Homework Q2 unfinished
 *************************************************************/

#include <stdio.h>
#include <stdlib.h>

// Create char LL

typedef char CElemType;

typedef struct Cnode {
    CElemType data;
    struct Cnode *next;
} CNode;

CNode *create_char_cir_LinkList(void) {
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
    p->next = head;
    return (head);
}

void char_cir_printList(CNode* list) {
    CNode *head = list;
    printf("Head");
    while (1) {
        printf("=>");
        list = list->next;
        if (list->next == head) {
            printf("%c=>Head\n", list->data);
            break;
        } else printf("%c", list->data);
    }
}

// Question 2 Make new circular LL for non-common node values from 2 LL
CNode *commElem(CNode *C1, CNode *C2) { // Head->G->O->O->D->NULL, Head->G->o->O->g->L->e->NULL
    CNode *p1 = C1;
    CNode *p2 = C2;
    CNode *head, *p, *q;
    head = p = (CNode *) malloc(sizeof (CNode));
    char data;

    while (p1 != NULL) {
        while (p2 != NULL) {
            if (p1->data != p2->data) {
                data = p2->data;
                q = (CNode *) malloc(sizeof (CNode));
                q->data = data;
                q->next = p->next;
                p->next = q;
                p = q;
            }
            p2 = p2->next;
        }
        p1 = p1->next;
    }
    p1->next = head;
    return(head);
}

int main(void) {
    CNode *c1, *c2;
    c1 = create_char_cir_LinkList();
    printf("Char linked list 1 = ");
    char_cir_printList(c1);
    
    c2 = create_char_cir_LinkList();
    printf("Char linked list 2 = ");
    char_cir_printList(c2);
    
    CNode *comm = commElem(c1, c2);
    printf("Common element removed = ");
    char_cir_printList(comm);

    return 0;
}