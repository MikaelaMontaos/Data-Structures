/*************************************************************
 * File Name: Q3.c
 * Author:    Mikaela Montaos
 *            Engineering School, NPU
 * description: Lab1 Q3 solved
 *************************************************************/

#include <stdio.h>
#include <stdlib.h>

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

// Question 3 find min & max for int & char linked list
int min_int_linked_list(LNode *L) { // Head->3->1->2->NULL
    int min;
    LNode *p1 = L;
    LNode *p2;
    while(p1->next != NULL) {
        p2 = p1;
        p1 = p1->next;
        if(p1->data < p2->data) min = p1->data;
    }
    return min;
}
int max_int_linked_list(LNode *L) { // Head->3->1->2->NULL
    int max;
    LNode *p1 = L;
    LNode *p2;
    while(p1->next != NULL) {
        p2 = p1;
        p1 = p1->next;
        if(p1->data < p2->data) max = p2->data;
    }
    return max;
}

//Create char LL
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
        scanf("%s", &data);
        q = (CNode *) malloc(sizeof (CNode));
        q->data = data;
        q->next = p->next;
        p->next = q;
        p = q;
    } while (getchar() != '\n');
    return (head);
}

void char_printList(CNode* list) {
    printf("Head");
    while (1) {
        printf("->");
        list = list->next;
        if (list->next == NULL) {
            printf("%c->NULL\n", list->data);
            break;
        }
        else printf("%c", list->data);
    }
}

char min_char_linked_list(CNode *C) { // Head->C->A->B->NULL
    char min;
    CNode *p1 = C;
    CNode *p2;
    while(p1->next != NULL) {
        p2 = p1;
        p1 = p1->next;
        if(p1->data < p2->data) min = p1->data;
    }
    return min;
}

char max_char_linked_list(CNode *C) { // Head->C->A->B->NULL
    char max;
    CNode *p1 = C;
    CNode *p2;
    while(p1->next != NULL) {
        p2 = p1;
        p1 = p1->next;
        if(p1->data < p2->data) max = p2->data;
    }
    return max;
}

int main(void) {
    LNode *a;
    a = create_LinkList();
    printf("Linked List A = ");
    printList(a);

    printf("min_int_linked_list = %d\n", min_int_linked_list(a));
    printf("max_int_linked_list = %d\n", max_int_linked_list(a));
    
    CNode *c;
    c = create_char_LinkList();
    printf("Char Linked List = ");
    char_printList(c);

    printf("min_char_linked_list = %c\n", min_char_linked_list(c));
    printf("max_char_linked_list = %c\n", max_char_linked_list(c));

    return 0;
}