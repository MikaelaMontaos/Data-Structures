/*
Josephus circle/Monkey king election using a circular list
Head => 1 => 2 => 3 => 4 => 5 => Head

Input:
m-th value: 3

Output:
Monkey king: 4
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node* next;
} node;

node *create(void) {
    printf("Enter linked list numbers separated by spaces: ");
    int val;
    node *head, *c, *tmp;
    head = c = (node*)malloc(sizeof (node));
    head->next = NULL;
    do {
        scanf("%d", &val);
        tmp = (node*)malloc(sizeof (node));
        tmp->data = val;
        tmp->next = c->next;
        c->next = tmp;
        c = tmp;
    } while (getchar() != '\n');
    c->next = head;
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

int get_sz(node* l) {
    node *head = l;
    int cnt = 1;
    while(1) {
        l = l->next;
        if(l->next == head) return cnt;
        cnt++;
    }
}

void monkey(node* l, int m) {
    node *cur = l;
    node *head = l;
    node *prev;
    
    while(cur->next != head) {
        node *tmp;
        int cnt = 1;
        // Find m-th monkey
        while(cnt != m) {
            prev = cur;
            cur = cur->next;
            cnt++;
            // Remove the m-th monkey
            if(cnt == m) {
                prev->next = cur->next;
                tmp = cur;
                cur = prev->next;
                free(tmp);
            }
        }
    }
    printf("The new king is monkey %d", cur->data);
}

int main(void) {
    node *l = create();
    printf("List of monkeys for the throne:\n");
    print_ll(l);
    
    printf("Josephus problem/Monkey king\n");
    int sz = get_sz(l);
    printf("There are %d monkeys\n", sz);
    
    printf("Every m-th monkey to take out: ");
    int m;
    scanf("%d", &m);
    
    monkey(l, m);
    

    return 0;
}