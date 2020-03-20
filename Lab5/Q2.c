/*****************************************************************
 * File Name:   Q2.c
 * Author:      Mikaela Montaos
 *              Engineering School, NPU
 * Description: Homework Q2 unfinished
                Using char array, reverse the array by stack
                string[] = "reward"
                rev(string)
                newString = "drawer"
 /*****************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 1
#define STACKINCREMENT 1
#define OK 1
#define ERROR 0
#define TRUE 0
#define FALSE -1

typedef int Status;
typedef char CharElemType;

typedef struct Stack_Node {
    CharElemType data;
    struct Stack_Node* next, * prior;
} Stk_Node;

// Create stack
Stk_Node Init_Link_Stack(void) {
    Stk_Node* top;
    top = (Stk_Node*)malloc(sizeof(Stk_Node));
    top->next = NULL;
    top->prior = NULL;
    return *top;
}

void printStkList(Stk_Node* list) {
    while (1) {
        list = list->next;
        if (list->next == NULL) {
            printf("%c\tEnd of stack\n", list->data);
            break;
        }
        else printf("%c", list->data);
    }
}

Status push(Stk_Node* top, CharElemType e) {
    Stk_Node* p;
    p = (Stk_Node*)malloc(sizeof(Stk_Node));
    if (!p) return ERROR;

    p->data = e;
    p->next = top->next;
    top->next = p;
    p->prior = top;
    return OK;
}

Stk_Node* rev(Stk_Node* s) {
    Stk_Node* temp = s->next;
    s->next = s->prior;
    s->prior = temp;
    if (temp == NULL) return s;
    return rev(temp);
}

int main(void) {
    Stk_Node s = Init_Link_Stack();
    push(&s, 'd');
    push(&s, 'r');
    push(&s, 'a');
    push(&s, 'w');
    push(&s, 'e');
    push(&s, 'r');
    printStkList(&s);

    rev(&s);
    printStkList(&s);
}
