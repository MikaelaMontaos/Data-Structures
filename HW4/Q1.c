/*************************************************************
 * File Name: Q1.c
 * Author:    Mikaela Montaos
 *            Engineering School, NPU
 * Description: Homework Q1 unfinished
 *************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 5
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef char CharElemType;
typedef int ElemType;
typedef int Status;

// Create static structure for LL

typedef struct {
    CharElemType data;
    int cur;
} component;

component *create_SL() {
    static component SLinkList[MAX_SIZE];
    char c;
    printf("Enter characters in array of linear list: ");
    int i = 1;
    SLinkList[0].cur = 1;
    while (1) {
        scanf("%c", &c);
        SLinkList[i].data = c;
        SLinkList[i].cur = i + 1;
        if (getchar() != '\n') i++;
        else break;
    }
    SLinkList[i].cur = -1;
    return SLinkList;
}

void printCharLL(component *s) {
    int i = 0;
    if(s[i].cur == -1) {
        printf("Head->NULL\n");
    }
    else {
        printf("Head->");
        while(s[i].cur != -1) {
            i = s[i].cur;
            if(s[i].cur != -1) {
                printf("%c->", s[i].data);
            }
        }
        printf("%c->NULL\n", s[i].data);
    }
}

int sLength(component *s) {
    int i, count = 0;
    while (s[i].cur != -1) {
        count++;
    }
    return count;
}

//0 Question 1 Insert an element by index to LL in array structure
component *insertElem(component *s, int i, CharElemType e) {
    /*
     * Head->S->t->i->n->g->NULL
     * Head->S->t->r->i->n->g->NULL
     */
    int j;
    if(s[i].cur == -1) {
        printf("Empty array\n");
        exit(1);
    }
    for(j = s[i].cur-1; j >= i-1; j--) {
        s[j+1].data = s[j].data; 
        s[j].cur = j + 1;
    }
    s[i].data = e;
}

int main() {
    component *ls;
    ls = create_SL();
    printCharLL(ls);
    
    printf("Insert element by index = \n");
    insertElem(ls, 3, 'r');
    printCharLL(ls);
    
    return 0;
}
