/*
Get the average of all nodes
Head -> 1 -> 2 -> 3 -> NULL
average(list)

Output:
2.0
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
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
    } while (getchar() != '\n');
    return (head);
}

void print_ll(node* l) {
    printf("Head ");
    while (1) {
        printf("-> ");
        l = l->next;
        if (l->next == NULL) {
            printf("%d -> NULL\n", l->data);
            break;
        } else
            printf("%d ", l->data);
    }
}

void average(node *l) {
    if(l == NULL) {
        printf("No nodes in the linked list\n");
        return;
    }
    node *p = l;
    int count = 0;
    int sum = 0;
    float avg = 0.0;

    while (p != NULL) {
        sum += p->data;
        p = p->next;
        if(p != NULL) count++;
    }
    
    printf("Sum = %d\n", sum);
    printf("Node count = %d\n", count);
    avg = (double)sum / count;
    printf("Average = %.2f \n", avg);
}

int main(void) {
    node *l;
    l = create();
    print_ll(l);

    average(l);

    return 0;
}