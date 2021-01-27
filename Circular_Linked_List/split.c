/*
Split the first 3 nodes in a circular linked list while preserving the old nodes
Head => 2 => 3 => 4 => 5 => 6 => 7 => 8 => Head

Output:
Head => 2 => 3 => 4 => Head
Head => 5 => 6 => 7 => 8 => Head
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} node;

node *create(void) {
    printf("Enter number in a linked list separated by spaces: ");
    int val;
    node *head, *cur, *tmp;
    head = cur = (node*)malloc(sizeof(node));
    head->next = NULL;
    do {
        scanf("%d", &val);
        tmp = (node*)malloc(sizeof(node));
        tmp->data = val;
        tmp->next = cur->next;
        cur->next = tmp;
        cur = tmp;
    } 
    while (getchar() != '\n');
    cur->next = head;
    return (head);
}

void print_ll(node* l) {
    node *head = l;
    printf("Head ");
    while (1) {
        printf("=> ");
        l = l->next;
        if (l->next == head) {
            printf("%d => Head\n", l->data);
            break;
        } 
        else printf("%d ", l->data);
    }
}

int get_sz(node *l) {
    node *head = l;
    int cnt = 0;
    while(1) {
        l = l->next;
        cnt++;
        if(l->next == head) {
            return cnt;
        }
    }
}

void *split(node *l, int n) {
    node *cur = l;
    node *prev, *splt;
    int cnt = 0;
    
    while(prev->next != l && cnt != n) {
        prev = cur;
        prev = prev->next;
        cur = cur->next;
        cnt++;
    }
    if(cnt == n) {
        cur = cur->next;
        printf("Head ");
        for(int i = 0; i < get_sz-n; i++) {
            printf("=> %d ", cur->data);
            cur = cur->next;
            if(cur->next == l) {
                printf("=> %d => Head\n", cur->data);
                break;
            }
        }
        prev->next = l;
        print_ll(prev->next);
    }
    else printf("Error\n");
}

int main(void) {
    node *l = create();
    print_ll(l);

    printf("Split the first 3 nodes from the linked list\n");
    split(l, 3);  

    return 0;
}