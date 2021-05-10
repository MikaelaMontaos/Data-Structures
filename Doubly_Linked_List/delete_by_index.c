// Delete element by index

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct node
{
  int data;
  struct node *prev, *next;
} node;

node *create(void)
{
  printf("Enter numbers separated by spaces (ENTER when done): ");
  int data;
  node *head, *cur, *tmp;
  head = cur = (node *)malloc(sizeof(node));
  head->next = NULL;
  head->prev = NULL;
  do
  {
    scanf("%d", &data);
    tmp = (node *)malloc(sizeof(node));
    tmp->data = data;
    tmp->next = cur->next;
    tmp->prev = cur;
    cur->next = tmp;
    cur = tmp;
  } while (getchar() != '\n');
  cur->next = NULL;
  return (head);
}

void print(node *list)
{
  node *head;
  printf("NULL <- Head ");
  while (1)
  {
    printf("<=> ");
    list = list->next;
    if (list->next == NULL)
    {
      printf("%d -> NULL\n", list->data);
      break;
    }
    else
      printf("%d ", list->data);
  }
}

void delete_by_index(node *list, int index)
{
  if(list == NULL || index < 0) {
    printf("Empty list\n");
    exit(1);
  }

  node *cur, *del;
  cur = list->next;
  int count;

  for(count = 0; cur != NULL && count < index; count++)
    cur = cur->next;
  
  if(cur == NULL) {
    printf("Invalid index\n");
    exit(1);
  }

  if(cur->next != NULL) {
    del = cur;
    cur->prev->next = cur->next;
    cur->next->prev = cur->prev->prev;
  }
  else {
    cur->prev->next = NULL;
  }
  free(cur);
}

int main(void)
{
  node *list;
  list = create();
  print(list);

  printf("Delete by index (2) = ");
  delete_by_index(list, 2);
  print(list);

  return 0;
}
