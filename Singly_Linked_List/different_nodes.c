/*
Use different nodes from two linked lists to create a new linked list
list1 = Head -> G -> O -> O -> D -> NULL
list2 = Head -> G -> o -> O -> g -> L -> E -> NULL

Output:
list3 = Head -> D -> o -> g -> L -> E -> NULL
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
    while(1) {
        printf("-> ");
        l = l->next;
        if (l->next == NULL) {
            printf("%c -> NULL\n", l->data);
            break;
        } 
        else printf("%c ", l->data);
    }
}

int get_sz(node* l) {
    node *head = l;
    int cnt = 1;
    while(1) {
        l = l->next;
        if(l->next == NULL) return cnt;
        cnt++;
    }
}

node *different(node *l1, node *l2) { 
    if(l1 == NULL || l2 == NULL) {
        printf("At least one linked list is empty\n");
        exit;
    }
    
    node *p1 = l1->next;
    node *p2 = l2->next;
    node *new_ll, *cur, *tmp;
    new_ll = cur = (node*)malloc(sizeof(node));
    int sz1 = get_sz(l1);
    int sz2 = get_sz(l2);
    
    if(sz1 > sz2) {
        while(p1 != NULL) {
            while(p2 != NULL) {
                if(p1->data != p2->data) {
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
    }
    else {
        while(p2 != NULL) {
            while(p1 != NULL) {
                if(p2->data != p1->data) {
                    tmp = (node*)malloc(sizeof(node));
                    tmp->data = p2->data;
                    tmp->next = cur->next;
                    cur->next = tmp;
                    cur = tmp;
            
                    p2 = p2->next;
                    p1 = p1->next;
                    tmp = tmp->next; 
                }
                else p1 = p1->next;
            }
            p2 = p2->next;
        }
    }
    return new_ll;
}

int main(void) {
    printf("Linked List 1\n");
    node *l1 = create();
    print_ll(l1);

    printf("Linked List 2\n");
    node *l2 = create();
    print_ll(l2);
    
    node *l3 = different(l1, l2);
    printf("Removed common nodes\n");
    print_ll(l3);

    return 0;
}