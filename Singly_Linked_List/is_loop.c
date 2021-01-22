/*
Find out if the linked list has in internal loop
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char data;
    struct Node *next;
} node;

node *create(void) {
    printf("Enter linked list letters separated by spaces: ");
    char ltr;
    node *head, *cur, *tmp;
    head = cur = (node*)malloc(sizeof(node));
    head->next = NULL;
    do {
        scanf("%c", &ltr);
        tmp = (node*)malloc(sizeof(node));
        tmp->data = ltr;
        tmp->next = cur->next;
        cur->next = tmp;
        cur = tmp;
    } 
    while(getchar() != '\n');
    return head;
}

void print_ll(node* l) {
    printf("Head ");
    while (1) {
        printf("-> ");
        l = l->next;
        if (l->next == NULL) {
            printf("%c -> NULL\n", l->data);
            break;
        } else
            printf("%c ", l->data);
    }
}

node* push(char ltr) {
    node *tmp = (node*)malloc(sizeof(node));
    tmp->data = ltr;
    tmp->next = NULL;
    return tmp;
}

void is_loop(node *l) {
    node *p1, *p2 = l;
    while(p1 && p2 && p1->next) {
        p1 = p1->next;
        p2 = p2->next ->next;
        // If p1 and p2 intersect
        if(p1 == p2) {
            printf("Loop found\n");
            return;
        }
    }
    printf("No loop\n");
}

int main(void) {
    node *l1 = create();
    printf("Linked list 1\n");
    print_ll(l1);
    is_loop(l1);
    
    node *l2 = push('l');
    l2->next = push('o');
    l2->next->next = push('o');
    l2->next->next->next = push('p');
    // Internal loop
    l2->next->next->next->next = l2->next->next;
    printf("Linked list 2\n");
    printf("Head -> l -> o -> o -> p -> (loops back to 1st o)\n");
    is_loop(l2);

    return 0;
}