/* 
Delete elements with the same value as the input argument key
a = Head -> 1 -> 2 -> 1 -> 3 -> NULL
delete_node(a, 1)

Output:
a = Head -> 2 -> 3 -> NULL
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

void delete_node(node *l, int key) {
    node *tmp = l;
    node *p, *d = NULL;
    if(tmp != NULL && tmp->data == key) {
        l = tmp->next;
        d = tmp;
        free(d);
    }
    while(tmp != NULL) {
        p = tmp;
        tmp = tmp->next;
        if(tmp == NULL) return;
        if(tmp->data == key) {
            p->next = tmp->next;
            d = tmp;
            tmp = tmp->next;
            free(d);
        }
    }
}

int main() {
    node* l;
    l = create();
    print_ll(l);
    
    int d;
    printf("Enter the node you want to delete: ");
    scanf("%d", &d);
    printf("\n");
    
    delete_node(l, d);
    printf("After deleting nodes with the value of %d \n", d);
    print_ll(l);
    
    return 0;
}
