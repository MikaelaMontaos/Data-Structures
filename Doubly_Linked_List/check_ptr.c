// Check if there is a random pointer and if there is, correct it

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {     
    int data;
    struct Node *prev, *next;
} node;

node *push(int n) {
    node *tmp = (node*)malloc(sizeof(node));
    tmp->data = n;
    tmp->next = tmp->prev = NULL;
    return tmp;
}

void print_ll(node* l){
  printf("NULL <- Head ");
  while(1){
    printf("<=> ");
    if(l->next == NULL) {
      printf("%d -> NULL\n", l->data);
      break;
    }
    else printf("%d ",l->data);
    l = l->next;
  }
}

void check_ptr(node *l) {
    if(l == NULL) {
        printf("Empty list\n");
        return;
    }
    node *tmp = l;
    if(l->next && l->next->prev != l) {
        l->next->prev = l;
        return;
    }
    if(l->prev != NULL) {
        l->prev = NULL;
        return;
    }
    
    tmp = tmp->next;
    while(tmp) {
        if(tmp->next && tmp->next->prev != tmp) {
            printf("Correcting...\n");
            tmp->next->prev = tmp;
            return;
        }
        else if(tmp->prev && tmp->prev->next != tmp) {
            printf("Correcting...\n");
            tmp->prev->next = tmp;
            return;
        }
        tmp = tmp->next;
    }
}

int main(void) {
    node *head = push(1);
    
    head->next = push(2);
    head->next->prev = head;
    
    head->next->next = push(3);
    head->next->next->prev = head; // Incorrect pointer
    
    head->next->next->next = push(4);
    head->next->next->next->prev = head->next->next;
    
    head->next->next->next->next = push(5);
    head->next->next->next->next->prev = head->next->next->next;
    
    printf("Checking for random pointer\n");
    check_ptr(head);
    print_ll(head);

    return 0;
}