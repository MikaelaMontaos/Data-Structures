// Find the minimum and maximum value in a int or char type singly linked list

#include <stdio.h>
#include <stdlib.h>

// int linked list
typedef struct Node {
    int data;
    struct Node *next;
} node;

node *create(void) {
    printf("Enter values in a linked list separated by spaces(ENTER when done):\n");
    int data;
    node *head, *cur, *temp;
    head = cur = (node*)malloc(sizeof(node));
    head->next = NULL;
    do {
        scanf("%d", &data);
        temp = (node*)malloc(sizeof(node));
        temp->data = data;
        temp->next = cur->next;
        cur->next = temp;
        cur = temp;
    } 
    while(getchar() != '\n');
    return head;
}

void print(node* list) {
    printf("Head ");
    while(1) {
        printf("-> ");
        list = list->next;
        if (list->next == NULL) {
            printf("%d -> NULL\n", list->data);
            break;
        } 
        else printf("%d ", list->data);
    }
}

int min_int(node *list) {
    int min;
    node *p1 = list;
    node *p2;
    while(p1->next != NULL) {
        p2 = p1;
        p1 = p1->next;
        if(p1->data < p2->data) min = p1->data;
    }
    return min;
}

int max_int(node *list) {
    int max;
    node *p1 = list;
    node *p2;
    while(p1->next != NULL) {
        p2 = p1;
        p1 = p1->next;
        if(p1->data < p2->data) max = p2->data;
    }
    return max;
}

// char linked list
typedef struct CNode {
    char data;
    struct CNode *next;
} cnode;

cnode *create_char(void) {
    printf("Enter characters in a linked list separated by spaces(ENTER when done):\n");
    char data;
    cnode *head, *cur, *temp;
    head = cur = (cnode*)malloc(sizeof(cnode));
    head->next = NULL;
    do {
        scanf("%c", &data);
        temp = (cnode*)malloc(sizeof(cnode));
        temp->data = data;
        temp->next = cur->next;
        cur->next = temp;
        cur = temp;
    } 
    while(getchar() != '\n');
    return head;
}

void print_char(cnode* list) {
    printf("Head ");
    while(1) {
        printf("-> ");
        list = list->next;
        if (list->next == NULL) {
            printf("%c -> NULL\n", list->data);
            break;
        }
        else printf("%c ", list->data);
    }
}

char min_char(cnode *list) {
    char min;
    cnode *p1 = list;
    cnode *p2;
    while(p1->next != NULL) {
        p2 = p1;
        p1 = p1->next;
        if(p1->data < p2->data) min = p1->data;
    }
    return min;
}

char max_char(cnode *list) {
    char max;
    cnode *p1 = list;
    cnode *p2;
    while(p1->next != NULL) {
        p2 = p1;
        p1 = p1->next;
        if(p1->data < p2->data) max = p2->data;
    }
    return max;
}

int main(void) {
    node *int_list;
    int_list = create();
    printf("int linked list:\n");
    print(int_list);
    printf("Minimum: %d\n", min_int(int_list));
    printf("Maximum: %d\n", max_int(int_list));
    
    cnode *char_list;
    char_list = create_char();
    printf("char linked list:\n");
    print_char(char_list);
    printf("Minimum: %c\n", min_char(char_list));
    printf("Maximum: %c\n", max_char(char_list));

    return 0;
}
