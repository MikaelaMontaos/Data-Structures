// Insert an element with the index starting from the end of the list

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} node;

node *create(void) {
    printf("Enter values separated by spaces (ENTER when done): ");
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
    while (getchar() != '\n');
    return head;
}

void print(node* list) {
    printf("Head ");
    while (1) {
        printf("-> ");
        list = list->next;
        if (list->next == NULL) {
            printf("%d -> NULL\n\n", list->data);
            break;
        } 
        else printf("%d ", list->data);
    }
}

int get_size(node *l) {
    int size = 0;
    while(l->next != NULL) {
        size++;
        l = l->next;
    }
    return size;
}

void insert_rev_index(node *l, int index, int num) {
    if(l == NULL) {
        printf("Empty list\n");
        exit(1);
    }
    
    int size = get_size(l);
    if(index > size) {
        printf("Index larger than list\n");
        exit(1);
    }
    
    node *p = l;
    int idx = size - index;
    int cnt = 0;
    while(cnt != idx) {
        cnt++;
        p = p->next;
    }
    node *tmp = (node*)malloc(sizeof(node));
    tmp->data = num;
    tmp->next = p->next;
    p->next = tmp;
    p = tmp;
}

int main(void) {
    node *l;
    l = create();
    print(l);

    insert_rev_index(l, 1, 123);
    printf("Insert 123 on index 1:\n");
    print(l);
    insert_rev_index(l, 0, 456);
    printf("Insert 456 on index 0:\n");
    print(l);
    
    return 0;
}
