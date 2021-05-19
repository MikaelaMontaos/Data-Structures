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

void print(node* list) {
    printf("Head");
    while (list->next != NULL) {
        printf(" -> ");
        list = list->next;
        printf("%d", list->data);
    }
    printf(" -> NULL\n");
}

node *delete_dupes(node* list) {
    node *dmy = (node*)malloc(sizeof(node));
    dmy->data = 0;
    dmy->next = list;
    node *p = dmy;
    while(list != NULL) {
        if(list->next != NULL && list->next->data == list->data) {
            while(list->next != NULL && list->next->data == list->data) {
                node *tmp = list->next;
                list->next = tmp->next;
                free(tmp);
            }
            node *d = list;
            p->next = d->next;
            list = list->next;
            free(d);
        }
        else {
            p = list;
            list = list->next;
        }
    }
    return(dmy->next);
}

int main(void) {
    node *list;
    list = create();
    print(list);
    
    node* n = delete_dupes(list);
    printf("After deleting duplicates\n");
    print(n);

    return 0;
}