/***********************************************************
 * File Name: Q5.c
 * Author:    Mikaela Montaos
 *            Engineering School, NPU
 * description: Homework Q5 unfinished
 ***********************************************************/

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

// Question 5 get average of linked list
void Average_List(LNode *L) { // Head 1 2 3 NULL
    LNode *p = L;
    int count, sum;
    float avg;

    while (p != NULL) {
        sum += p->data;
        p = p->next;
        count++;
    }
    avg = (float) sum / count;

    printf("Average_List function = %5.2f\n", avg);
}

int main(void) {
    LNode *a;
    a = create_LinkList();
    printf("Original linked list\n");
    printList(a);

    Average_List(a);

    return 0;
}
