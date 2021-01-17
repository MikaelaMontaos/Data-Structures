/*
Alphabetically sort nodes
Head -> D -> A -> C -> A -> G -> NULL
sort(list)

Output:
Head -> A -> A -> C -> D -> G -> NULL
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
    node *head, *c, *tmp;
    head = c = (node*)malloc(sizeof(node));
    head->next = NULL;
    do {
        scanf("%c", &ltr);
        tmp = (node*)malloc(sizeof(node));
        tmp->data = ltr;
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
            printf("%c -> NULL\n", l->data);
            break;
        } 
        else printf("%c ", l->data);
    }
}

void sort(node *l) {
    node* c = l;
    node* p;
    int temp;
    
    if(c == NULL) exit(0);
    else {
      while(c != NULL) {
        p = c->next;
        while(p != NULL) {
          if(c->data > p->data) {
            temp = c->data;
            c->data = p->data;
            p->data = temp;
          }
          p = p->next;
        }
        c = c->next;
      }
    }
}

int main(void) {
    node *l;
    l = create();
    print_ll(l);

    sort(l);
    printf("Sorted linked list:\n");
    print_ll(l);

    return 0;
}