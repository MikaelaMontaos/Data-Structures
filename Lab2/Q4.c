/*************************************************************
 * File Name: Q4.c
 * Author:    Mikaela Montaos
 *            Engineering School, NPU
 * Description: Lab2 Q4 solved
 *************************************************************/
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

/* NULL<-Head<=>1<=>2<=>3<=>4->NULL 
  to
  Head<=>1<=>2<=>3<=>4<=>Head */
typedef struct Dulnode {
  ElemType data;
  struct Dulnode *prior, *next;
} DulNode;

void *cirDul_LL(LNode *L, DulNode *D) {
  int data;
  DulNode *head, *p, *q;
  LNode *d = L->next;
  head = p = (DulNode*)malloc(sizeof(DulNode));
  head->next = NULL;
  head->prior = NULL;
  do {
    q = (DulNode*)malloc(sizeof(DulNode));
    q->data = d->data;
    d = d->next;
    q->next = p->next;
    q->prior = p;
    p->next = q;
    p = q;
  } while(d != L);
  p->next = NULL;
  return(head);
}

void printCirNull(LNode *list) {
    LNode *head;
    head = list;
    printf("NULL<-Head");
    while (1) {
        printf("<=>");
        list = list->next;
        if (list->next == head) {
            printf("%d->NULL\n", list->data);
            break;
        } else
            printf("%d", list->data);
    }
}

void printDulList(DulNode *list) {
  LNode *head;
  printf("Head");
  while(1) {
    printf("<=>");
    list = list->next;
    if(list->next == NULL) {
      printf("%d<=>Head\n", list->data);
      break;
    }
    else printf("%d", list->data);
  }
}

// Question 4 Insert an element by index in a doubly linked list
void dul_LL_insert(DulNode *D, int index, ElemType e) {
    DulNode *p1, *p2;
    p1 = D->next;    
    int j = 0;

    while(p1 != NULL && j < index-1) {
        p1 = p1->next;
        j++;
    }
    if(p1 == NULL || j != index-1) printf("i too big or i is 0\n");
    else {
        p2 = (DulNode*)malloc(sizeof(DulNode));
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

    DulNode *d;
    d = cirDul_LL(a, d);

    dul_LL_insert(d, 1, 123);
    printDulList(d);

    return 0;
}