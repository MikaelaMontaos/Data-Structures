// Convert circular singly linked list to circular doubly linked list

#include <stdio.h>
#include <stdlib.h>

typedef struct Lnode {
        int data;
        struct Lnode * next;
} LNode;

typedef struct Dulnode {
        int data;
        struct Dulnode *prior, *next;
} DulNode;

LNode *create(void) {
        printf("Enter values in the linked list separated by a space (ENTER when done): ");
        int data;
        LNode * head, * cur, * tmp;
        head = cur = (LNode * ) malloc(sizeof(LNode));
        head->next = NULL;
        do {
                scanf("%d", &data);
                tmp = (LNode * ) malloc(sizeof(LNode));
                tmp->data = data;
                tmp->next = cur->next;
                cur->next = tmp;
                cur = tmp;
        } while (getchar() != '\n');
        cur->next = head;
        return (head);
}

void *create_doubly(LNode *L, DulNode *D) {
        int data;
        DulNode *head, *cur, *tmp;
        LNode *singly = L->next;
        head = cur = (DulNode*)malloc(sizeof(DulNode));
        head->next = NULL;
        head->prior = NULL;
        do {
                tmp = (DulNode*)malloc(sizeof(DulNode));
                tmp->data = singly->data;
                singly = singly->next;
                tmp->next = cur->next;
                tmp->prior = cur;
                cur->next = tmp;
                cur = tmp;
        } while(singly != L);
        cur->next = NULL;
        return(head);
}

void printSingly(LNode *list) {
        LNode *head;
        head = list;
        printf("NULL <- Head ");
        while (1) {
                printf("<=> ");
                list = list->next;
                if (list->next == head) {
                        printf("%d -> NULL\n", list->data);
                        break;
                } else
                        printf("%d ", list->data);
        }
}
void printDoubly(DulNode *list) {
        LNode *head;
        printf("Head ");
        while(1) {
                printf("<=> ");
                list = list->next;
                if(list->next == NULL) {
                        printf("%d <=> Head\n", list->data);
                        break;
                }
                else printf("%d ", list->data);
        }
}


int main(void) {
        LNode *a;
        a = create();
        printf("\nOriginal LL: ");
        printSingly(a);

        DulNode *d;
        d = create_doubly(a, d);

        printf("\nChange to circular doubly LL\nFROM: ");
        printSingly(a);
        printf("TO: ");
        printDoubly(d);

        return 0;
}