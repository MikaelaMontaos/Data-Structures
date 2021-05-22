// Get average value of all nodes

#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
}node;

node* create() {
    node* p;
    int n;
    printf("Enter value (-1 for no branch): ");
    scanf(" %d", &n);

    if (n == -1)
        return NULL;

    p = (node*)malloc(sizeof(node));
    p->data = n;

    printf("LEFT child of %d and\n", n);
    p->left = create();

    printf("RIGHT child of %d and\n", n);
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

int sum(node* t) {
    if (t == NULL) return 0;
    return(t->data + sum(t->left) + sum(t->right));
}

int numOfNodes(node* t) {
    int count = 1;
    if (t->left != NULL) count += numOfNodes(t->left);
    if (t->right != NULL) count += numOfNodes(t->right);
    return count;
}

int ave(node* t) {
    if (t == NULL) return 0;
    int avg = sum(t) / numOfNodes(t);
    return avg;
}

int main() {
    node* root;
    root = create();
    print(root);
    printf("\n");

    printf("The average value is %d", ave(root));
}