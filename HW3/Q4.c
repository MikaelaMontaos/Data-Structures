/*************************************************************
 * File Name: Q4.c
 * Author:    Mikaela Montaos
 *            Engineering School, NPU
 * Description: Homework Q4 unfinished
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

// Question 4 Split circular LL
LNode *split_CLL(LNode *L, int i) { // Head=>2=>3=>4=>5=>6=>7=>8=>Head, i=3
    LNode *f, *s, *list1, *list2;
    f = L;
    list2 = s = L;
    int count = 0;
    while(f->next != NULL && count != i) {
      s = f;
      f = f->next;
      count++;
    }
    if(count == i) {
      cir_printList(f);
      s = s->next;
      s->next = L;
      cir_printList(list2);
    }
    else printf("Error\n");
}

int main(void) {
    LNode *cir;
    cir = circular_LinkList();
    cir_printList(cir);

    printf("Split circular LL\n");
    split_CLL(cir, 3);  

    return 0;
}