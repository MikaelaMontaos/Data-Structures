// Check if the binary tree has a node with the value of 5

#include <stdio.h>
#include <stdlib.h>

#define FALSE 1
#define TRUE 0

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;

node *create()
{
    node *p;
    int n;
    printf("data (-1 for no branch): ");
    scanf("%d", &n);

    if (n == -1)
        return NULL;

    p = (node *)malloc(sizeof(node));
    p->data = n;

    printf("LEFT child of %d ", n);
    p->left = create();

    printf("RIGHT child of %d ", n);
    p->right = create();

    return p;
}

void padding(int e, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d", e);
}

void print(tree *t, int lvl)
{
    if (t == NULL)
    {
        padding('\t', lvl);
        puts(" ");
    }
    else
    {
        print(t->right, lvl + 1);
        padding('\t', lvl);
        printf("%d\n", t->data);
        print(t->left, lvl + 1);
    }
}

int is_contain(node *t, int n)
{
    if (t == NULL)
        return FALSE;
    if (t->data == n)
        return TRUE;

    int left = is_contain(t->left, n);
    if (left)
        return TRUE;

    int right = is_contain(t->right, n);
    return right;
}

int main()
{
    node *root;
    root = create();
    print(root);
    printf("\n");

    int key = 5;
    if (is_contain(root, key))
        printf("There is no %d in the binary tree", key);
    else
        printf("There is %d in the binary tree", key);
}