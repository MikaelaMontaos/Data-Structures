/*
Delete duplicates
Head -> 1 -> 2 -> 1 -> 3 -> 2 -> NULL
delete_dupes(list)

Output:
Head -> 1 -> 2 -> 3 -> NULL
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} node;

node* create(void) {
    printf("Enter linked list numbers separated by spaces: ");
    int val;
    node* head, * c, * tmp;
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

void delete_dupes(node* l) {
    node* p1, * p2, * d;
    p1 = l;

    while (p1 != NULL && p1->next != NULL) {
        p2 = p1;
        while (p2->next != NULL) {
            if (p1->data == p2->next->data) {
                d = p2->next;
                p2->next = p2->next->next;
                free(d);
            }
            else p2 = p2->next;
        }
        p1 = p1->next;
    }
}

int main(void) {
    node* l;
    l = create();
    print_ll(l);

    delete_dupes(l);
    printf("After deleting duplicates:\n");
    print_ll(l);

    return 0;
}