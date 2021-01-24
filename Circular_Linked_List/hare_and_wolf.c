/*
Hare moves around nests 1-10
Wolf hunts for the hare and goes through the nests:
- Check nest 1
- Skip 1 nest (nest 2) to check nest 3
- Increase skip to 2 nests (nest 4-5) to check nest 6
- Skip value increases to check nest 10
- Skip value increases to check nest 4

Output:
Display the nest number where the wolf should check
If it moves more than 20 times, it is not safe for the hare to hide
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} node;

node *create(void) {
    int val = 1;
    node *head, *cur, *tmp;
    head = cur = (node*)malloc(sizeof(node));
    head->next = NULL;
    do {
        tmp = (node*)malloc(sizeof(node));
        tmp->data = val;
        tmp->next = cur->next;
        cur->next = tmp;
        cur = tmp;
        val++;
    } 
    while(val <= 10);
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

void hare(node *l) {
    node *cur = l->next;
    int cnt = 0;
    
    while(cnt < 20) {
      if(cur->data == 0) cur = cur->next;
      if(cnt == 0) printf("Wolf checks %d time: ", cnt+1);
      else printf("Wolf checks %d times: ", cnt+1);
      printf("Nest %d\n", cur->data);
      cnt++;
      // Skip nests
      for(int i = 0; i <= cnt; i++) {
        cur = cur->next;
      }
    }
    printf("Hare: Not safe to hide\n");
}

int main(void) {
    node *l = create();
    print_ll(l);
    
    hare(l);

    return 0;
}
