/*************************************************************
 * File Name: Q1A.c
 * Author:    Mikaela Montaos
 *            Engineering School, NPU
 * Description: Lab3 Q1A solved
 *************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct Lnode {
    ElemType data;
    struct Lnode *next;
} LNode;

// Create circular LL

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

void cir_printList(LNode* list) {
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

// Question 1 Circular LL delete by key
void cirLL_delete_key(LNode *L, int key) { 
    // Head->13->12->15->14->NULL
    LNode *p1, *p2, *del;
    p1 = L->next;
    p2 = L;

    while(p1 != L) {
      if(p1->data == key) {
        del = p1;
        p1 = p1->next;
        p2->next = p1;
        free(del);
      }
      p2 = p1;
      p1 = p1->next;
    }
    if(p1 == L) printf("Cannot find key");
}

int main(void) {
    LNode *cir;
    cir = circular_LinkList();
    cir_printList(cir);

    printf("Delete circular LL by key = ");
    cirLL_delete_key(cir, 15);
    cir_printList(cir);

    return 0;
}
