/*************************************************************
 * File Name: Q3.c
 * Author:    Mikaela Montaos
 *            Engineering School, NPU
 * Description: Lab2 Q3 solved
 *************************************************************/
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

// Question 3 Change from circular LL to circular doubly LL
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


int main(void) {
    LNode *a;
    a = circular_LinkList();
    printf("\nOriginal LL: ");
    printList(a);
    
    DulNode *d;
    d = cirDul_LL(a, d);

    printf("\nChange to circular doubly LL\nFROM: ");
    printCirNull(a);
    printf("TO: ");
    printDulList(d);


    return 0;
}