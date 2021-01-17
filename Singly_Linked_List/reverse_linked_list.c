/*
Reverse the order of the nodes
Head -> 1 -> 2 -> 3 -> NULL
reverse(list)

Output:
Head -> 3 -> 2 -> 1 -> NULL
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} node;

node* create(void) {
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
    } while (getchar() != '\n');
    return (head);
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

node *reverse(node *l) {
    node *c, *p, *n;
    c = l;
    p = NULL;
    while (c != NULL) {
        n = c->next;
        c->next = p;
        p = c;
        c = n;
    }
    l = p;
    return l;
}

void print_rev(node* l) {
    printf("Head");
    while(1) {
        printf(" -> ");
        if (l->next == NULL) {
            printf("NULL\n");
            break;
        } else {
            printf("%d", l->data);
            l = l->next;
        }
    }
}

int main(void) {
    node *l;
    l = create();
    print_ll(l);

    node *r;
    r = reverse(l);
    printf("Reversed linked list\n");
    print_rev(r); 

    return 0;
}