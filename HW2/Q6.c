/*************************************************************
 * File Name: Q6.c
 * Author:    Mikaela Montaos
 *            Engineering School, NPU
 * Description: Homework Q6 solved
 *************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

// Question 6 If there is an internal linked loop
void is_loopLL(CNode *C) {
    CNode *p1 = C;
    CNode *p2 = NULL;
    if (!p1) {
        p2 = p1->next;
        while (p1 && p1 != p2) {
            p1 = p1->next;
            if (p1) p1 = p1->next;
        }
        if (p1 == p2) {
            printf("There is a loop\n");
            exit(1);
        }
        p2 = p2->next;
    }
    printf("There is no loop\n");
}


int main(void) {
    CNode *c1;
    c1 = create_char_LinkList();
    printf("Char Linked List 1 = ");
    c_printList(c1);

    is_loopLL(c1);

    return 0;
}