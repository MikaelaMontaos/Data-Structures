/*****************************************************************
 * File Name:   Q3.c
 * Author:      Mikaela Montaos
 *              Engineering School, NPU
 * description: Lab 7 Q3 Solved

                Create a tree structure to display as:
                Preorder: ABDGHCEFI
                Inorder: GDHBAECIF
 *****************************************************************/

#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    char data;
    struct node* left;
    struct node* right;
} node;

node* create() {
    node* p;
    char n;
    printf("data ($ for no branch): ");
    scanf(" %c", &n);

    if (n == '$') return NULL;

    p = (node*)malloc(sizeof(node));
    p->data = n;

    printf("LEFT child of %c and\n ", n);
    p->left = create();

    printf("RIGHT child of %c and\n ", n);
    p->right = create();

    return p;
}

void preorder(node* t) {
    if (t != NULL) {
        printf("%c\t", t->data);
        preorder(t->left);
        preorder(t->right);
    }
}

void inorder(node* t) {
    if (t != NULL) {
        inorder(t->left);
        printf("%c\t", t->data);
        inorder(t->right);
    }
}

int main() {
    node* root;
    root = create();

    printf("Tree structure (preorder):\n");
    preorder(root);
    printf("\n");

    printf("Tree structure (inorder):\n");
    inorder(root);
    printf("\n");
}