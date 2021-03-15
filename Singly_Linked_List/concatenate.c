// Concatenate two singly linked list

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} node;

node *create(void) {
    int data;
    node *head, *cur, *tmp;
    head = cur = (node*)malloc(sizeof(node));
    head->next = NULL;
    do {
        scanf("%d", &data);
        tmp = (node*)malloc(sizeof(node));
        tmp->data = data;
        tmp->next = cur->next;
        cur->next = tmp;
        cur = tmp;
    } 
    while(getchar() != '\n');
    return head;
}

void print(node* list) {
    printf("Head ");
    while(1) {
        printf("-> ");
        list = list->next;
        if (list->next == NULL) {
            printf("%d -> NULL\n", list->data);
            break;
        } 
        else printf("%d ", list->data);
    }
}

void concat(node *A, node *B) {
    node *p1 = A;
    node *p2 = B->next;
    
    while(p1->next != NULL) p1 = p1->next;
    if(p1->next == NULL) p1->next = p2;
    while(p2->next != NULL) p2 = p2->next;
}

int main(void) {
    printf("Enter values for linked list 1 (ENTER when done):\n");
    node *list1 = create();
    printf("Linked list 1: ");
    print(list1);

    printf("Enter values for linked list 2 (ENTER when done):\n");
    node *list2;
    list2 = create();
    printf("Linked list 2: ");
    print(list2);
    
    concat(list1, list2);
    printf("Concatenated linked list:\n");
    print(list1);
    
    return 0;
}
