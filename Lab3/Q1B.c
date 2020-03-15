/*************************************************************
 * File Name: Q1B.c
 * Author:    Mikaela Montaos
 *            Engineering School, NPU
 * Description: Lab3 Q1B solved
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

// Question 1 Circular LL delete by index
void cirLL_delete_index(LNode *L, int index) { 
    // Head->13->12->15->14->NULL
    LNode *p1, *p2, *del;
    p1 = L->next;
    p2 = L;
    int count = 0;

    while(p1 != L) {
      if(count == index) {
        del = p1;
        p1 = p1->next;
        p2->next = p1;
        free(del);
      }
      p2 = p1;
      p1 = p1->next;
      count++;
    }
    if(count <= index) {
      printf("Index too big");
      exit(1);
    }
}

int main(void) {
    LNode *cir;
    cir = circular_LinkList();
    cir_printList(cir);
    
    printf("Delete circular LL by index (start at 0) = ");
    cirLL_delete_index(cir, 1);
    cir_printList(cir);

    return 0;
}
