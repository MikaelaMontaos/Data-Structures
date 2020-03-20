/*****************************************************************
 * File Name:   Q3.c
 * Author:      Mikaela Montaos
 *              Engineering School, NPU
 * Description: Homework Q3
                Check for unmatched parenthesis
                Unmatched left ( as $
                Unmatched right ) as ?
 /*****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define OK 1
#define ERROR 0
#define TRUE 0
#define FALSE -1

typedef int Status;
typedef char CharElemType;

typedef struct Stack_Node {
    CharElemType data;
    struct Stack_Node* next;
} Stk_Node;

Stk_Node* Init_Link_Stack(void) {
    Stk_Node* top;
    top = (Stk_Node*)malloc(sizeof(Stk_Node));
    top->next = NULL;
    return(top);
}

Status push(Stk_Node* top, CharElemType e) {
    Stk_Node* p;
    p = (Stk_Node*)malloc(sizeof(Stk_Node));
    if (!p) return ERROR;
    p->data = e;
    p->next = top->next;
    top->next = p;
    return OK;
}

void printStkList(Stk_Node* list) {
    while (1) {
        list = list->next;
        if (list->next == NULL) {
            printf("\n");
            break;
        }
        else printf("%c", list->data);
    }
}

void Match_Brackets() {
    Stk_Node* S;
    S = Init_Link_Stack();

    char ch, x;
    int count = 0;

    printf("Enter a string: ");

    while (ch != '\n')
    {
        scanf("%c", &ch);
        if (ch == '(') {
            count++;
        }
        else if (ch == ')')
        {
            count--;
            if (count < 0) {
                push(S, '?');
            }
        }
        else push(S, ' ');
    }
    if (count != 0) {
        push(S, '$');
    }
    printStkList(S);
}

int main(void) {
    Match_Brackets();

    return 0;
}