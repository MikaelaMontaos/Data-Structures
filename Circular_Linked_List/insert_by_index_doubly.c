// Insert an element by index in a circular doubly linked list

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {     
    int data;
    struct Node *prev , *next;
} node;

node *create(void){  
    printf("Enter letters for the linked list separated by spaces: ");
    int num;
    node *head, *cur, *tmp;
    head = cur = (node*)malloc(sizeof(node)); 
    head->next = NULL;
    head->prev = NULL;       
    do{ 
        scanf("%d", &num);
        tmp = (node*)malloc(sizeof(node)); 
        tmp->data = num;     
        tmp->next = cur->next;
        tmp->prev = cur;
        cur->next = tmp; 
        cur = tmp; 
    }
    while(getchar()!='\n');
    cur->next = NULL;
    return (head);
}

void print(node* list){
  printf("NULL <- Head ");
  while(1){
    printf("<=> ");
    list = list->next;
    if(list->next == NULL) {
      printf("%d -> NULL\n", list->data);
      break;
    }
    else printf("%d ",list->data);
  }
}

void insert(node *list, int index, int elem) {
    node *cur, *new;
    cur = list->next;
    int idx = 0; 

    while (cur != NULL && idx < index-1) {
        cur = cur->next;
        idx++;
    }
    
    if(cur == NULL || idx != index-1) printf("Invalid index\n");
    else {
        new = (node*)malloc(sizeof(node));
        new->data = elem;
        new->next = cur->next;
        new->prev = cur;
        cur->next = new;
    }
}

int main(void) {
    node *list;
    list = create();
    printf("Original LL: ");
    print(list);

    insert(list, 1, 123);
    printf("After inserting 123 at index 1: ");
    print(list);

    return 0;
}