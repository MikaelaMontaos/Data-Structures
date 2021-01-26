/*
Create a new circular linked list using uncommon nodes from two different circular linked lists
list1 = Head => G => O => O => D => Head
list2 = Head => G => o => O => g => L => E => Head

Output:
list3 = Head => D => o => g => L => E => Head
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char data;
    struct Node *next;
} node;

node *create(void) {
    printf("Enter characters separated by spaces: ");
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
            printf("%c => Head\n", l->data);
            break;
        } else printf("%c ", l->data);
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

node *remove_common(node *l1, node *l2) { 
    if(l1 == NULL || l2 == NULL) {
        printf("At least one linked list is empty\n");
        exit;
    }
    
    node *p1 = l1->next;
    node *p2 = l2->next;
    node *head1 = l1;
    node *head2 = l2;
    node *new_ll, *cur, *tmp;
    new_ll = cur = (node*)malloc(sizeof(node));
    int sz1 = get_sz(l1);
    int sz2 = get_sz(l2);
    
    if(sz1 > sz2) {
        while(p1 != head1) {
            while(p2 != head2) {
                if(p1->data != p2->data) {
                    tmp = (node*)malloc(sizeof(node));
                    tmp->data = p1->data;
                    tmp->next = cur->next;
                    cur->next = tmp;
                    cur = tmp;
            
                    p1 = p1->next;
                    p2 = p2->next;
                    tmp = tmp->next; 
                }
                else p2 = p2->next;
            }
            p1 = p1->next;
        }
    }
    else {
        while(p2 != head2) {
            while(p1 != head1) {
                if(p2->data != p1->data) {
                    tmp = (node*)malloc(sizeof(node));
                    tmp->data = p2->data;
                    tmp->next = cur->next;
                    cur->next = tmp;
                    cur = tmp;
            
                    p2 = p2->next;
                    p1 = p1->next;
                    tmp = tmp->next; 
                }
                else p1 = p1->next;
            }
            p2 = p2->next;
        }
    }
    cur->next = new_ll;
    return new_ll;
}

int main(void) {
    printf("Linked list 1\n");
    node *l1 = create();
    print_ll(l1);
    
    printf("Linked list 2\n");
    node *l2 = create();
    print_ll(l2);
    
    node *l3 = remove_common(l1, l2);
    printf("Common element removed\n");
    print_ll(l3);

    return 0;
}