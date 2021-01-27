/*
Delete prime numbers in a circular linked list
Head => 13 => 12 => 15 => 14 => Head

Output:
Head => 12 => 15 => 14 => Head
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node *next;
} node;

node *create(void) {
    printf("Enter numbers for linked list separated by spaces: ");
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
    node *head;
    head = l;
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

void delete_node(node *l, node *del) {
    node *tmp = l;
    if(l == del) l = del->next;
    while(tmp->next != del) tmp = tmp->next;
    tmp->next = del->next;
    free(del);
    return;
}

bool is_prime(int n) {
    if(n <= 1) return false;
    if(n <= 3) return true;
    if(n%2==0 || n%3==0) return false;
    for(int i = 5; i*i<=n; i = i+6)
        if(n%i==0 || n%(i+2)==0) return false;
    return true;
}

void delete_prime_nos(node *l) {
    node *p = l;
    node *nxt;
    do {
        if(is_prime(p->data)) delete_node(l, p);
        nxt = p->next;
        p = nxt;
    }
    while(p != l);
}

int main(void) {
    node *l = create();
    print_ll(l);
    
    printf("Delete prime numbers\n");
    delete_prime_nos(l);
    print_ll(l);  

    return 0;
}