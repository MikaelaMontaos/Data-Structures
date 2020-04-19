/*************************************************************
 * File Name: Q2.c
 * Author:    Mikaela Montaos
 *            Engineering School, NPU
 * Description: Homework Q2 Cannot solve
 * 
 *              u = Head->1->2->3->4->NULL
 *              v = Head->5->6->7->8->NULL
 * 
 *              LL_add(u, v) to add two linked lists and use the sum to create a new linked list
 *              result = Head->6->9->1->2->NULL
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

// Convert to doubly linked list

typedef struct Dulnode {
  ElemType data;
  struct Dulnode *prior, *next;
} DulNode;

void *convToDoubly(LNode *L, DulNode *D) {
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
  D = head;
  return(head);
}

void printDulList(DulNode *list) {
  printf("Head");
  while(1) {
    list = list->next;
    if(list->next == NULL) {
      printf("%d->NULL\n", list->data);
      break;
    }
    else printf("%d->", list->data);
  }
}

void LL_add(LNode *L1, LNode *L2) {
    DulNode *d1 = convToDoubly(L1, d1);
    DulNode *d2 = convToDoubly(L2, d2);
    DulNode *result;
    int sum;

    while(d1 != NULL && d2 != NULL) {
      sum += (d1->data + d2->data);
      result->data = sum;
      result = result->next;
      d1 = d1->next;
      d2 = d2->next;
      if(sum / 10 > 0) {
        sum = 1;
        result->prior += 1;
      }
    }
    printDulList(result);
    
    /* Add each node and display sum
    LNode* p1 = L1->next;
    LNode* p2 = L2->next;
    int sum;
    printf("Head->");

    while(p1 && p2) {
        sum = d1->data + d2->data;
        printf("%d->", sum);

        p1 = p1->next;
        p2 = p2->next;
    }

    printf("->NULL");
    */
}

int main(void) {
    LNode *u, *v;

    printf("Enter linked list 1 with spaces in between values (ENTER when done)\n");
    u = create_LinkList();
    printList(u);
    
    printf("Enter linked list 2 with spaces in between values (ENTER when done)\n");
    v = create_LinkList();
    printList(v);

    LL_add(u, v);
}