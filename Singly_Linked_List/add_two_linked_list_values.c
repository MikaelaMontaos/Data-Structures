/*
Concatenate the nodes on each linked list to create a new number and get the sum
list1 = Head -> 1 -> 2 -> 3 -> 4 -> NULL
list2 = Head -> 5 -> 6 -> 7 -> 8 -> NULL

add(list1, list2, &sum)
	num1 = 1234
	num2 = 5678
	sum = num1 + num2 = 6912

Output:
new_list = Head -> 6 -> 9 -> 1 -> 2 -> NULL
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

void push(node** head, int val) {
    node *l = (node*)malloc(sizeof(node));
    l->data = val;
    l->next = NULL;
    if(*head == NULL) *head = l;
    else {
        node *c = *head;
        while(c->next != NULL) c = c->next;
        c->next = l;
    }
}

int get_sz(node* l) {
    int ct = 0;
    node *c = l;
    while(c) {
        ct++;
        c = c->next;
    }
    return ct;
}

node* rev(node* l) {
    node* p = NULL;
    node* c = l;
    node* n = NULL;
    while(c != NULL) {
        n = c->next;
        c->next = p;
        p = c;
        c = n;
    }
    return p;
}

void add(node* l1, node* l2) {
    int sz1 = get_sz(l1);
    int sz2 = get_sz(l2);
    node* e1 = rev(l1);
    node* e2 = rev(l2);
    node* new_ll = NULL;
    node* lnk = NULL;
    int carry = 0;
    while(e1 != NULL && e2 != NULL) {
        node *tmp = (node*)malloc(sizeof(node));
        node *nxt = e1->next;
        tmp->data = e1->data + e2->data;
        if(tmp->data > 9) {
            carry = 1;
            tmp->data = tmp->data - 10;
            if(nxt != NULL) nxt->data = nxt->data + carry;
            else if(e2->next != NULL) e2->next->data = e2->next->data + carry;
        }
        tmp->next = NULL;
        e1 = e1->next;
        e2 = e2->next;
        if(new_ll == NULL) new_ll = tmp;
        else {
            node *lnk = new_ll;
            while(lnk->next != NULL) lnk = lnk->next;
            lnk->next = tmp;
            // Over for overflow of nodes/number of nodes should be more bec of carry
            if(nxt == NULL && (carry && e2 == NULL)) {
                node *over = (node*)malloc(sizeof(node));
                over->next = NULL;
                over->data = 1;
                lnk->next->next = over;
            }
        }
        carry = 0;
    }
    if(e1 != NULL) {
        node *lnk = new_ll;
        while(lnk->next != NULL) lnk = lnk->next;
        lnk->next = e1;
    }
    if(e2 != NULL) {
        node *lnk = new_ll;
        while(lnk->next != NULL) lnk = lnk->next;
        lnk->next = e2;
    }
    print_ll(rev(new_ll));
}

int main(void) {
    node *l1, *l2;
    printf("Linked list 1\n");
    l1 = create();
    print_ll(l1);
    
    printf("Linked list 2\n");
    l2 = create();
    print_ll(l2);

    add(l1, l2);
    
    return 0;
}