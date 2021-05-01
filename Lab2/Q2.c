// Insert an element by index into a circular linked list

#include <stdio.h>
#include <stdlib.h>

typedef struct Lnode {
  int data;
  struct Lnode * next;
} LNode;

LNode * create(void) {
  printf("Enter values in the linked list separated by a space (ENTER when done): ");
  int data;
  LNode * head, * cur, * tmp;
  head = cur = (LNode * ) malloc(sizeof(LNode));
  head -> next = NULL;
  do {
    scanf("%d", & data);
    tmp = (LNode * ) malloc(sizeof(LNode));
    tmp -> data = data;
    tmp -> next = cur -> next;
    cur -> next = tmp;
    cur = tmp;
  } while (getchar() != '\n');
  cur -> next = head;
  return (head);
}

void print(LNode * list) {
  LNode * head;
  head = list;
  printf("Head ");
  while (1) {
    printf("=> ");
    list = list -> next;
    if (list -> next == head) {
      printf("%d => Head\n", list -> data);
      break;
    } else
      printf("%d ", list -> data);
  }
}

void insert(LNode * L, int index, int num) {
  LNode * p1, * p2;
  p1 = L -> next;
  int j = 0;

  while (p1 != L && j < index - 1) {
    p1 = p1 -> next;
    j++;
  }
  
  if (p1 == L || j != index - 1) printf("Invalid index\n");
  else {
    p2 = (LNode * ) malloc(sizeof(LNode));
    p2 -> data = num;
    p2 -> next = p1 -> next;
    p1 -> next = p2;
  }
}

int main(void) {
  LNode * list;
  list = create();
  printf("Original: ");
  print(list);

  insert(list, 1, 123);
  printf("After inserting 123 at index 1: ");
  print(list);

  return 0;
}