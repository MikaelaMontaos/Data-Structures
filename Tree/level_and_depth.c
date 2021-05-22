/*
Assuming that there is an expression (x, y), if node x is the parent of node y in a given tree, the whole tree structure can be shown as { (e,i), (b,e), (b,d), (a,b), (g,j), (c,g), (c,f), (h,l), (c,h), (a,c) }.

1. Print tree
2. Which level is node b and c?
3. Depth of the subtree with node c as the root
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
    printf("($ for no branch): ");
    scanf(" %c", &n);

    if (n == '$')
        return NULL;

    p = (tree *)malloc(sizeof(tree));
    p->data = n;

    printf("Enter LEFT child of %c ", n);
    p->left = create();

    printf("Enter RIGHT child of %c ", n);
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

int level(tree *t)
{
    if (t == NULL)
        return 0;
    int left = 1 + level(t->left);
    int right = 1 + level(t->right);

    if (left > right)
        return left;
    else
        return right;
}

int level_elem(tree *t, char e, int lvl)
{
    if (t == NULL)
        return 0;
    if (t->data == e)
        return lvl;

    int dwn = level_elem(t->left, e, lvl + 1);
    if (dwn != 0)
        return dwn;
    dwn = level_elem(t->right, e, lvl + 1);
    return dwn;
}

int depth(tree *t, char e)
{
    if (t == NULL)
        return 0;
    else {
        int lvl = level(t);
        printf("%d\n", lvl);
        int sub = level_elem(t, e, 1);
        printf("%d\n", sub);
        return lvl - sub;
    }
}

int main()
{
    tree *root;
    printf("Enter the root node ");
    root = create();
    print(root, 0);

    printf("The tree has %d levels\n", level(root));
    printf("Node b is at level %d\n", level_elem(root, 'b', 1));
    printf("Node c is at level %d\n\n", level_elem(root, 'c', 1));

    printf("The depth of the subtree with c as the root %d\n", depth(root, 'c'));
}
