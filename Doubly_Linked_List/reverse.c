// Reverse the order

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  char data;
  struct Node *prev, *next;
} node;

node *create(void)
{
  printf("Enter letters separated by spaces (ENTER when done): ");
  char data;
  node *head, *cur, *tmp;
  head = cur = (node *)malloc(sizeof(node));
  head->next = NULL;
  head->prev = NULL;
  do
  {
    scanf("%c", &data);
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
  printf("NULL <- Head ");
  while (list->next != NULL)
  {
    list = list->next;
    if (list == NULL)
      break;
    printf("<=> %c ", list->data);
  }
  printf("-> NULL\n");
}

node *reverse(node *list)
{
  if (list == NULL)
  {
    printf("Empty list\n");
    exit(1);
  }
  else
  {
    node *cur = list;
    node *pre = NULL;
    while (cur != NULL)
    {
      cur->prev = cur->next;
      cur->next = pre;
      pre = cur;
      cur = cur->prev;
    }
    node *head;
    head = (node *)malloc(sizeof(node));
    head->prev = NULL;
    head->next = pre;
    list = head;
  }
}

int main(void)
{
  node *list;
  list = create();
  print(list);

  printf("Reverse the order: ");
  node *rev = reverse(list);
  print(rev);

  return 0;
}
