/*****************************************************************
 * File Name:   Q4.c
 * Author:      Mikaela Montaos
 *              Engineering School, NPU
 * description: Lab 7 Q4 Solved

                Create a tree structure to display as:
                Inorder: BDCEAFHG
                Postorder: DECBHGFA (Question incorrect. Need 2 different trees.)
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

void inorder(node* t) {
    if (t != NULL) {
        inorder(t->left);
        printf("%c\t", t->data);
        inorder(t->right);
    }
}

void postorder(node* t) {
    if (t != NULL) {
        postorder(t->left);
        postorder(t->right);
        printf("%c\t", t->data);
    }
}

int main() {
    printf("Create first tree\n");
    node* root;
    root = create();

    printf("Tree structure (inorder):\n");
    inorder(root);
    printf("\n");

    printf("Tree structure (postorder):\n");
    postorder(root);
    printf("\n");

    printf("Create second tree\n");
    node* root2;
    root2 = create();

    printf("Tree structure 2 (inorder):\n");
    inorder(root2);
    printf("\n");

    printf("Tree structure 2 (postorder):\n");
    postorder(root2);
    printf("\n");
}