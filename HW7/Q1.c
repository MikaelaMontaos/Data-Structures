/*****************************************************************
 * File Name:   Q1.c
 * Author:      Mikaela Montaos
 *              Engineering School, NPU
 * description: HW7 Q1 Solved

                is_contain(tree, 5) to check if the tree has a node with the value 5
                return true or false
 *****************************************************************/

#include<stdio.h>
#include<stdlib.h>

#define FALSE 1
#define TRUE 0

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
}node;

node* create() {
    node* p;
    int n;
    printf("data (-1 for no branch): ");
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

void preorder(node* t) {
    if (t != NULL) {
        printf("%d\t", t->data);
        preorder(t->left);
        preorder(t->right);
    }
}

int is_contain(node* t, int n) {
    if (t == NULL) return FALSE;
    if (t->data == n) return TRUE;

    int left = is_contain(t->left, n);
    if (left) return TRUE;

    int right = is_contain(t->right, n);
    return right;
}

int main() {
    node* root;
    root = create();
    preorder(root);
    printf("\n");

    int key = 5;
    if (is_contain(root, key)) printf("There is no %d in the binary tree", key);
    else printf("There is %d in the binary tree", key);
}
