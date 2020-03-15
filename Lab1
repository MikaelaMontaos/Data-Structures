/*************************************************************
 * File Name: Q1.c
 * Author:    Mikaela Montaos
 *            Engineering School, NPU
 * description: Lab1 Q1 unfinished
 *************************************************************/

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

// Question 1 insert element in terms of reverse index
void insert_rev_index(LNode *L, int i, ElemType e) {
    /* Head->11->12->13->NULL
                           i = 1, e = 123 
      2nd insert_rev_index i = 0, e = 456 */
        
    LNode *c = L;
    while(c != NULL && c->next != NULL) {
      c = c->next;
    }
    LNode *n = (LNode *) malloc(sizeof (LNode));
    n->data = e;
    n->next = NULL;
    if(c != NULL) c->next = n;
    else L = n;
}

int main(void) {
    LNode *a;
    a = create_LinkList();
    printf("Linked List A = ");
    printList(a);

    insert_rev_index(a, 1, 123);
    printf("insert_rev_index (insert 123 on index 1) = ");
    printList(a);
    insert_rev_index(a, 0, 456);
    printf("insert_rev_index (insert 456 on index 0) = ");
    printList(a);
    
    return 0;
}
