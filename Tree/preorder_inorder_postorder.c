/*
1. Print a tree diagram
2. Print preorder sequence
3. Print inorder sequence
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct tree
{
    char data;
    struct tree *left;
    struct tree *right;
} tree;

tree *create()
{
    tree *p;
    char n;
    printf("data ($ for no branch): ");
    scanf(" %c", &n);

    if (n == '$')
        return NULL;

    p = (tree *)malloc(sizeof(tree));
    p->data = n;

    printf("LEFT child of %c and\n ", n);
    p->left = create();

    printf("RIGHT child of %c and\n ", n);
    p->right = create();

    return p;
}

void padding(char e, int n)
{
    for (int i = 0; i < n; i++)
        putchar(e);
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
        printf("%c\n", t->data);
        print(t->left, lvl + 1);
    }
}

void preorder(tree *t)
{
    if (t != NULL)
    {
        printf("%c ", t->data);
        preorder(t->left);
        preorder(t->right);
    }
}

void inorder(tree *t)
{
    if (t != NULL)
    {
        inorder(t->left);
        printf("%c ", t->data);
        inorder(t->right);
    }
}

void postorder(tree *t){
    if(t != NULL){
        postorder(t->left);
        postorder(t->right);
        printf("%c ", t->data);
    }
}

int main()
{
    tree *root;
    root = create();
    print(root, 0);

    printf("Preorder: ");
    preorder(root);
    printf("\n");

    printf("Inorder: ");
    inorder(root);
    printf("\n");

    printf("Postorder: ");
    postorder(root);
    printf("\n");
}