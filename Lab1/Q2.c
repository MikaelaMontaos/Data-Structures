/*************************************************************
 * File Name: Q2.c
 * Author:    Mikaela Montaos
 *            Engineering School, NPU
 * description: Lab1 Q2 solved
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

// Question 2 concatenate 2 linked lists
void concat_linked_list(LNode *A, LNode *B) {
    /*  A = Head->4->2->1->NULL
        B = Head->5->7->3->NULL
        Output = Head->4->2->1->5->7->3->NULL */
    LNode *p1 = A;
    LNode *p2 = B->next;
    
    while(p1->next != NULL) p1 = p1->next;
    if(p1->next == NULL) p1->next = p2;
    while(p2->next != NULL) p2 = p2->next;
}

int main(void) {
    LNode *a;
    a = create_LinkList();
    printf("Linked List A = ");
    printList(a);
    
    LNode *b;
    b = create_LinkList();
    printf("Linked List B = ");
    printList(b);
    
    concat_linked_list(a, b);
    printf("concat_linked_list = ");
    printList(a);
    
    return 0;
}