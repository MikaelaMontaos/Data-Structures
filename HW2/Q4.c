/*************************************************************
 * File Name: Q4.c
 * Author:    Mikaela Montaos
 *            Engineering School, NPU
 * Description: Homework Q4 Cannot solve

                l = Head->G->O->O->D->NULL
                m = Head->G->o->O->g->L->E->NULL

                commElem(l, m) to display the common elements
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

void commElem(CNode *C1, CNode *C2) { 
    CNode *p1 = C1;
    CNode *p2 = C2;
    CNode *head, *p, *q;
    head = p = (CNode*)malloc(sizeof (CNode));
    head->next = NULL;
    char data;
    
    for(;p1 != NULL; p1 = p1->next) {
      for(;p2 != NULL; p2 = p2->next) {
        if(p2->data == p1->data) {
          data = p2->data;
          q = (CNode *) malloc(sizeof(CNode));
          q->data = data;
          q->next = p->next;
          p->next = q;
          p = q;
        }
      }
    }
    c_printList(head);
}

int main(void) {    
    printf("Enter linked list 1 separated with spaces between letters (ENTER when done)\n");
    CNode *c1 = create_char_LinkList();
    printf("Linked List 1 = ");
    c_printList(c1);

    printf("Enter linked list 2 separated with spaces between letters (ENTER when done)\n");
    CNode *c2 = create_char_LinkList();
    printf("Linked List 2 = ");
    c_printList(c2);
    
    commElem(c1, c2);
    
    return 0;
}