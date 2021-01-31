/*
Convert an int linked list to a char where 1 = A, 2 = B, etc.
Head -> 1 -> 2 -> 2 -> 1 -> NULL

Output:
Head -> A -> B -> B -> A -> NULL
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} node;

node *create(void) {
    printf("Enter numbers in a linked list separated by spaces: ");
    int val;
    node *head, *cur, *tmp;
    head = cur = (node*)malloc(sizeof(node));
    head->next = NULL;
    do {
        scanf("%d", &val);
        tmp = (node*)malloc(sizeof(node));
        tmp->data = val;
        tmp->next = cur->next;
        cur->next = tmp;
        cur = tmp;
    } 
    while (getchar() != '\n');
    return (head);
}

void print(node* l) {
    printf("Head ");
    while (1) {
        printf("-> ");
        l = l->next;
        if (l->next == NULL) {
            printf("%d -> NULL\n", l->data);
            break;
        } 
        else printf("%d ", l->data);
    }
}

void convert(node *l) {
    if(l == NULL) {
        printf("Empty list\n");
        exit(1);
    }
    printf("Head -> ");
    node *cur = l->next;
    int n = 0;
    while(cur != NULL) {
        n = cur->data;
        switch(n) {
            case 1:
                printf("A -> ");
                break;
            case 2:
                printf("B -> ");
                break;
            case 3:
                printf("C -> ");
                break;
            case 4:
                printf("D -> ");
                break;
            case 5:
                printf("E -> ");
                break;
            case 6:
                printf("F -> ");
                break;
            case 7:
                printf("G -> ");
                break;
            case 8:
                printf("H -> ");
                break;
            case 9:
                printf("I -> ");
                break;
            case 10:
                printf("J -> ");
                break;
            case 11:
                printf("K -> ");
                break;
            case 12:
                printf("L -> ");
                break;
            case 13:
                printf("M -> ");
                break;
            case 14:
                printf("N -> ");
                break;
            case 15: 
                printf("O -> ");
                break;
            case 16:
                printf("P -> ");
                break;
            case 17:
                printf("Q -> ");
                break;
            case 18:
                printf("R -> ");
                break;
            case 19:
                printf("S -> ");
                break;
            case 20:
                printf("T -> ");
                break;
            case 21:
                printf("U -> ");
                break;
            case 22:
                printf("V -> ");
                break;
            case 23:
                printf("W -> ");
                break;
            case 24:
                printf("X -> ");
                break;
            case 25:
                printf("Y -> ");
                break;
            case 26:
                printf("Z -> ");
                break;
            default:
                printf("# -> ");
                break;
        }
        cur = cur->next;
    }
    printf("NULL\n");
}

int main() {
    node *l = create();
    print(l);
    
    printf("Convert integers to characters\n");
    convert(l);
    
    return 0;
}