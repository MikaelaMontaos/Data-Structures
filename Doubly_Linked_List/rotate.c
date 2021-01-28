/*
Rotate a doubly linked list by N places
NULL <- Head <=> c <=> i <=> v <=> i <=> c -> NULL

Output:
NULL <- Head <=> v <=> i <=> c <=> c <=> i -> NULL
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {     
    char data;
    struct Node *prev , *next;
} node;

node *create(void){  
    printf("Enter letters for the linked list separated by spaces: ");
    char ltr;
    node *head, *cur, *tmp;
    head = cur = (node*)malloc(sizeof(node)); 
    head->next = NULL;
    head->prev = NULL;       
    do{ 
        scanf("%c", &ltr);
        tmp = (node*)malloc(sizeof(node)); 
        tmp->data = ltr;     
        tmp->next = cur->next;
        tmp->prev = cur;
        cur->next = tmp; 
        cur = tmp; 
    }
    while(getchar()!='\n');
    cur->next = NULL;
    return (head);
}

void print_ll(node* l){
  printf("NULL <- Head ");
  while(1){
    printf("<=> ");
    l = l->next;
    if(l->next == NULL) {
      printf("%c -> NULL\n", l->data);
      break;
    }
    else printf("%c ",l->data);
  }
}

void rotate(node *l, int n) {
    if(l == NULL) {
        printf("Empty list\n");
        return;
    }
    node *cur = l;
    int cnt = 1;
    
    while(cnt < n && cur != NULL) {
        cur = cur->next;
        cnt++;
    }
    if(cur == NULL) {
        printf("Number given is more than the linked list\n");
        return;
    }
    
    node *nth_node = cur;
    while(cur->next != NULL) cur = cur->next;
    cur->next = l;
    l->prev = cur;
    l = nth_node->next;
    l->prev = NULL;
    nth_node->next = NULL;
    
    node *head = l;
    printf("NULL <- Head <=> ");
    while(head->next != NULL) {
        printf("%c <=> ", head->data);
        head = head->next;
    }
    printf("%c -> NULL\n", head->data);
}

int main(void) {
    node *l = create();
    print_ll(l);
    
    printf("Rotated\n");
    rotate(l, 3);

    return 0;
}