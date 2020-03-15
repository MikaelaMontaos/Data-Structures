/*************************************************************
 * File Name: Q2.c
 * Author:    Mikaela Montaos
 *            Engineering School, NPU
 * Description: Lab2 Q2 solved
 *************************************************************/
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct Lnode {
    ElemType data;
    struct Lnode *next;
} LNode;

LNode *circular_LinkList(void) {
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
    p->next = head;
    return (head);
}

void printList(LNode* list) {
    LNode *head;
    head = list;
    printf("Head");
    while (1) {
        printf("=>");
        list = list->next;
        if (list->next == head) {
            printf("%d=>Head\n", list->data);
            break;
        } else
            printf("%d", list->data);
    }
}

// Question 2 Insert an element by index into a circular LL
void cirLL_insert(LNode *L, int index, ElemType e) { 
    // Head->1->2->3->4->NULL
    LNode *p1, *p2;
    p1 = L->next;    
    int j = 0;

    while(p1 != L && j < index-1) {
        p1 = p1->next;
        j++;
    }
    if(p1 == L || j != index-1) printf("i too big or i is 0\n");
    else {
        p2 = (LNode*)malloc(sizeof(LNode));
        p2->data = e;
        p2->next = p1->next;
        p1->next = p2;
    }
}

int main(void) {
    LNode *a;
    a = circular_LinkList();
    printf("\nOriginal LL: ");
    printList(a);
    
    printf("Insert element into circular LL: ");
    cirLL_insert(a, 1, 123);
    printList(a);


    return 0;
}
