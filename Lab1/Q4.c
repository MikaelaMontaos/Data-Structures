/*************************************************************
 * File Name: Q4.c
 * Author:    Mikaela Montaos
 *            Engineering School, NPU
 * description: Lab1 Q4 solved
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

// Create char LL
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

// Question 4 swap min and max data for both int and char LL
int min_int_linked_list(LNode *L) {
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

int max_int_linked_list(LNode *L) {
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

char min_char_linked_list(CNode *C) {
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

char max_char_linked_list(CNode *C) {
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

void swap_int_linkedlist(LNode *L) { // Head->3->1->2->NULL
  LNode *a = L;
  int min = min_int_linked_list(a);
  int max = max_int_linked_list(a);
  if(min == max) return;
  
  LNode *p1;
  LNode *c1 = L;
  while(c1 && c1->data != min) {
    p1 = c1;
    c1 = c1->next;
  }

  LNode *p2;
  LNode *c2 = L;
  while(c2 && c2->data != max) {
    p2 = c2;
    c2 = c2->next;
  }

  if(p1 != NULL) p1->next = c2;
  else L = c2;
  if(p2 != NULL) p2->next = c1;
  else L = c1;

  LNode *swap = c2->next;
  c2->next = c1->next;
  c1->next = swap;
}

void swap_char_linkedlist(CNode *C) { // Head->C->A->B->NULL
  CNode *c = C;
  char min = min_char_linked_list(c);
  char max = max_char_linked_list(c);
  if(min == max) return;
  
  CNode *p1;
  CNode *c1 = C;
  while(c1 && c1->data != min) {
    p1 = c1;
    c1 = c1->next;
  }

  CNode *p2;
  CNode *c2 = C;
  while(c2 && c2->data != max) {
    p2 = c2;
    c2 = c2->next;
  }
  
  if(p1 != NULL) p1->next = c2;
  else C = c2;
  if(p2 != NULL) p2->next = c1;
  else C = c1;
  
  CNode *swap = c2->next;
  c2->next = c1->next;
  c1->next = swap;
}

int main(void) {
    LNode *a;
    a = create_LinkList();
    printf("Linked List A = ");
    printList(a);
    
    swap_int_linkedlist(a);
    printf("swap_int_linkedlist = ");
    printList(a);

    CNode *c;
    c = create_char_LinkList();
    printf("Char Linked List = ");
    char_printList(c);

    swap_char_linkedlist(c);
    printf("swap_char_linkedlist = ");
    char_printList(c);
    
    return 0;
}