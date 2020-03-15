/*************************************************************
 * File Name: Q2.c
 * Author:    Mikaela Montaos
 *            Engineering School, NPU
 * Description: Homework Q2 unfinished
 *************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef char CharElemType;
typedef int ElemType;

// Create singly int LL
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

// Create singly char LL
typedef struct Cnode {
    CharElemType data;
    struct Cnode *next;
} CNode;

CNode *createCharLinkList(void) {
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

void printCharList(CNode* list) {
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

// Question 2 Convert singly int LL to a corresponding letter. Use '#' if > 26
CNode *convIntLLToChar(LNode *L) {
    /* 
    lst0 = Head->1->2->2->1->NULL
            Head->A->B->B->A->NULL
    lst1 = Head->12->2->1->NULL
            Head->L->B->A->NULL
    lst2 = Head->1->22->1->NULL
            Head->A->V->A->NULL
    lst3 = Head->1->2->21->NULL
            Head->A->B->U->NULL
    */
    int num;
    char letter;
    LNode *lst = L;
    CNode *head, *p, *q;
    head = p = (CNode*)malloc(sizeof(CNode));
    head->next = NULL;
    do {
        q = (CNode*)malloc(sizeof(CNode));
        num = lst->data;
        if(num < 10) letter = '0' + num;
        else letter = 'A' + num - 10;
        letter = num;
        q->data = letter;
        q->next = p->next;
        p->next = q;
        p = q;
        lst = lst->next;
    } while(lst != NULL);
    return(head);
}

int main() {
    LNode *lst0 = create_LinkList();
    LNode *lst1 = create_LinkList();
    LNode *lst2 = create_LinkList();
    LNode *lst3 = create_LinkList();
    
    printList(lst0);
    printList(lst1);
    printList(lst2);
    printList(lst3);
    
    printf("Convert int LL to char LL\n");
    CNode *c0 = convIntLLToChar(lst0);
    printCharList(c0);
    
    return 0;
}