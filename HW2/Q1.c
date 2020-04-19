/*************************************************************
 * File Name: Q1.c
 * Author:    Mikaela Montaos
 *            Engineering School, NPU
 * Description: Homework Q1 Solved

                ls = Head->D->A->C->A->G->NULL
                
                srt_LL(ls) to sort from A-z
                Head->A->A->C->D->G->NULL
                Note: A > a otherwise it will not sort the nodes alphabetically
 *************************************************************/

#include <stdio.h>
#include <stdlib.h>

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
        scanf("%c", &data);
        q = (CNode *) malloc(sizeof (CNode));
        q->data = data;
        q->next = p->next;
        p->next = q;
        p = q;
    } while (getchar() != '\n');
    return (head);
}

void c_printList(CNode* list) {
    printf("Head");
    while (1) {
        printf("->");
        list = list->next;
        if (list->next == NULL) {
            printf("%c->NULL\n", list->data);
            break;
        } else printf("%c", list->data);
    }
}

void srt_LL(CNode *C) {
    CNode* c = C;
    CNode* p;
    int temp;
    
    if(c == NULL) exit(0);
    else {
      while(c != NULL) {
        p = c->next;
        while(p != NULL) {
          if(c->data > p->data) {
            temp = c->data;
            c->data = p->data;
            p->data = temp;
          }
          p = p->next;
        }
        c = c->next;
      }
    }
}

int main(void) {
    CNode *c1;
    printf("Type characters separated with spaces (ENTER when done):\n");
    c1 = create_char_LinkList();
    c_printList(c1);

    srt_LL(c1);
    printf("Sorted = ");
    c_printList(c1);

    return 0;
}