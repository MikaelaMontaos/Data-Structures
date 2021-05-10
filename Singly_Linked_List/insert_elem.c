/*
Insert an element by index into the linked list
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char data;
    struct Node *next;
} node;

node *create(void) {
    printf("Enter letters in a linked list separated by spaces: ");
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

void print(node* l) {
    printf("Head ");
    while(1) {
        printf("-> ");
        l = l->next;
        if(l->next == NULL) {
            printf("%c -> NULL\n", l->data);
            break;
        }
        else printf("%c ", l->data);
    }
}

int get_sz(node *l) {
    int cnt = 0;
    while(1) {
        cnt++;
        l = l->next;
    }
    return cnt;
}

void *insert_elem(node *l, char c, int n) {
    node *prev, *cur, *tmp;
    tmp->data = c;
    int cnt = 0;
    cur = l;

    if(l != NULL) {
        while(cur->next != NULL && cnt != n) {
            prev = cur;
            cur = cur->next;
            cnt++;
        }
        if(n == 0) printf("Empty list. Adding letter at the head.\n");
        else if(n > cnt+1) printf("Invalid position\n");
        // prev -> insert tmp -> cur
        else {
            prev->next = tmp;
            tmp->next = cur;
        }
    }
    else {
        l = tmp;
        tmp->next = NULL;
        printf("Empty list. Adding letter at the head.\n");
    }
}

int main() {
    node *l = create();
    print(l);

    printf("Insert element by index\n");
    insert_elem(l, 'r', 3);
    print(l);

    return 0;
}
