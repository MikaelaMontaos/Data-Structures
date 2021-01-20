/*
Use common nodes from two linked lists to create a new linked list
list1 = Head -> G -> O -> O -> D -> NULL
list2 = Head -> G -> o -> O -> g -> L -> E -> NULL

common(list1, list2)

Output:
Head -> G -> O -> NULL
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char data;
    struct Node *next;
} node;

node *create(void) {
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
    while (getchar() != '\n');
    return(head);
}

void print_ll(node* l) {
    printf("Head ");
    while (1) {
        printf("-> ");
        l = l->next;
        if (l->next == NULL) {
            printf("%c -> NULL\n", l->data);
            break;
        } 
        else printf("%c ", l->data);
    }
}

node *common(node *l1, node *l2) { 
    if(l1 == NULL || l2 == NULL) {
        printf("At least one linked list is empty\n");
        exit;
    }
    
    node *p1 = l1->next;
    node *p2 = l2->next;
    node *new_ll, *cur, *tmp;
    new_ll = cur = (node*)malloc(sizeof(node));
    
    while(p1 != NULL) {
        while(p2 != NULL) {
            if(p1->data == p2->data) {
                tmp = (node*)malloc(sizeof(node));
                tmp->data = p1->data;
                tmp->next = cur->next;
                cur->next = tmp;
                cur = tmp;
            
                p1 = p1->next;
                p2 = p2->next;
                tmp = tmp->next;
            }
            else p2 = p2->next;
        }
        p1 = p1->next;
    }
    return new_ll;
}

int main(void) {    
    printf("Linked List 1: ");
    node *l1 = create();
    print_ll(l1);

    printf("Linked List 2: ");
    node *l2 = create();
    print_ll(l2);
    
    node *l3 = common(l1, l2);
    print_ll(l3);
    
    return 0;
}