/*****************************************************************
 * File Name:   Q2.c
 * Author:      Mikaela Montaos
 *              Engineering School, NPU
 * description: Lab 7 Q2 Cannot solve

                Whole tree structure:
                { (e,i), (b,e), (b,d), (a,b), (g,j), (c,g), (c,f), (h,l), (c,h), (a,c) }
                Note: (x, y) with x as the parent of y

                1. Which level is node b and c?
                2. What is the depth of the tree? (Solved)
                3. What is the depth of the subtree for node c as the root
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

int level(node* t, char n) {
    if (t != NULL) {
        int left, right;
        if (t->data == n) {
            if (left > right) return left + 1;
            else return right + 1;
        }
        left = level(t->left, n);
        right = level(t->right, n);
    }
    else return 0;
}

int depth(node* t) {
    if (t != NULL) {
        int left = depth(t->left);
        int right = depth(t->right);
        if (left > right) return left + 1;
        else return right + 1;
    }
    else return 0;
}

int cDepth(node* t, char n) {
    if (t != NULL) {
        if (t->data == n) {
            int left = 0, right = 0;
            left = cDepth(t->left, n);
            right = cDepth(t->right, n);
            if (left > right) return left + 1;
            else return right + 1;
        }
        int left = cDepth(t->left, n);
        int right = cDepth(t->right, n);
    }
    else return 0;
}

int main() {
    node* root;
    root = create();
    printf("Tree structure (preorder):\n");
    preorder(root);
    printf("\n");

    printf("The level of b is %d\n", level(root, 'b'));
    printf("The level of c is %d\n", level(root, 'b'));

    printf("The depth is %d\n", depth(root));

    printf("The depth of subtree with c as the root %d\n", cDepth(root, 'c'));
}
