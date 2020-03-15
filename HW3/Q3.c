/*************************************************************
 * File Name: Q3.c
 * Author:    Mikaela Montaos
 *            Engineering School, NPU
 * Description: Homework Q3 unfinished
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

// Question 3 Delete all prime #
void delete_prime_CLL(LNode *L) { // Head=>13=>12=>15=>14=>Head
    LNode *p = L;
    LNode *n = L->next;
    LNode *d;
    int prime, i = 1;

    while(n != L) {
      prime = n->data;
      for(i = 2; i <= sqrt(prime); i++) {
        if((prime % i) != 0) {
          d = n;
          p->next = n->next;
          free(d);
        }
      }
      p = n;
      n = n->next;
    }
    if(p == L) printf("No elements\n");
}

int main(void) {
    LNode *cir;
    cir = circular_LinkList();
    cir_printList(cir);
 
    delete_prime_CLL(cir);
    printf("Delete prime numbers = ");
    cir_printList(cir);  

    return 0;
}