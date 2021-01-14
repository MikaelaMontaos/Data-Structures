/*
Delete all nodes along with its duplicates
Head -> 1 -> 2 -> 1 -> 3 -> 2 -> NULL
delete_dupes(list)

Output:
Head -> 3 -> NULL
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} node;

node *create(void) {
    printf("Enter linked list numbers separated by spaces: ");
    int val;
    node *head, *c, *tmp;
    head = c = (node*)malloc(sizeof(node));
    head->next = NULL;
    do {
        scanf("%d", &val);
        tmp = (node*)malloc(sizeof(node));
        tmp->data = val;
        tmp->next = c->next;
        c->next = tmp;
        c = tmp;
    }
    while(getchar() != '\n');
    return(head);
}

void print_ll(node* l) {
    printf("Head");
    while (l->next != NULL) {
        printf(" -> ");
        l = l->next;
        printf("%d", l->data);
    }
    printf(" -> NULL\n");
}

node *delete_dupes(node* l) {
    node *dmy = (node*)malloc(sizeof(node));
    dmy->data = 0;
    dmy->next = l;
    node *p = dmy;
    node *h = l;
    while(l != NULL) {
        if(l->next != NULL && l->next->data == l->data) {
            while(l->next != NULL && l->next->data == l->data) {
                node *tmp = l->next;
                l->next = tmp->next;
                free(tmp);
            }
            node *d = l;
            p->next = d->next;
            l = l->next;
            free(d);
        }
        else {
            p = l;
            l = l->next;
        }
    }
    return(dmy->next);
}

int main(void) {
    node *l;
    l = create();
    print_ll(l);
    
    node* n = delete_dupes(l);
    printf("After deleting duplicates\n");
    print_ll(n);

    return 0;
}