// Sort numbers

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  int data;
  struct Node *prev, *next;
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

void sort(node *list)
{
  if (list == NULL)
  {
    printf("Empty list\n");
    exit(1);
  }
  else
  {
    node *cur = list->next;
    node *nxt;
    int tmp;
    
    while (cur->next != NULL)
    {
      nxt = cur->next;
      while (nxt != NULL)
      {
        if (cur->data > nxt->data)
        {
          tmp = cur->data;
          cur->data = nxt->data;
          nxt->data = tmp;
        }
        nxt = nxt->next;
      }
      cur = cur->next;
    }
  }
}

int main(void)
{
  node *list;
  list = create();
  print(list);

  printf("List after sorting: ");
  sort(list);
  print(list);

  return 0;
}
