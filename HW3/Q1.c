/*************************************************************
 * File Name: Q1.c
 * Author:    Mikaela Montaos
 *            Engineering School, NPU
 * Description: Homework Q1 unfinished
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

// Question 1 Traverse through circular LL until n > 20
void rabbit(LNode *L) { // 1-10
    LNode *p = L->next;
    int n = 0;
    
    while(n <= 20) {
      if(p->data == 0) p = p->next;
      printf("%d\n", p->data);
      n++;
      for(int i = 0; i <= n; i++) {
        p = p->next;
      }
    }
}

int main(void) {
    LNode *cir;
    cir = circular_LinkList();
    cir_printList(cir);
    
    printf("Rabbit hole\n");
    rabbit(cir);

    return 0;
}
