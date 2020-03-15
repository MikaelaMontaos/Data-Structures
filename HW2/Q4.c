/*************************************************************
 * File Name: Q4.c
 * Author:    Mikaela Montaos
 *            Engineering School, NPU
 * Description: Homework Q4 unfinished
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

// Question 4 Find common elements between 2 LL
CNode *commElem(CNode *C1, CNode *C2) { 
    // Head->G->O->O->D->NULL, Head->G->o->O->g->L->e->NULL
    CNode *p1 = C1;
    CNode *p2 = C2;
    CNode *head, *p, *q;
    head = p = (CNode *) malloc(sizeof (CNode));
    head->next = NULL;
    char data;

    while (p1 != NULL) {
        while (p2 != NULL) {
            if (p1->data == p2->data) {
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
    return (head);
}

int main(void) {    
    CNode *c1;
    c1 = create_char_LinkList();
    printf("Char Linked List 1 = ");
    c_printList(c1);

    CNode *c2;
    c2 = create_char_LinkList();
    printf("Char Linked List 2 = ");
    c_printList(c2);
    
    CNode *common = commElem(c1, c2);
    c_printList(common);
    
    return 0;
}