/*************************************************************
 * File Name: Q4.c
 * Author:    Mikaela Montaos
 *            Engineering School, NPU
 * Description: Homework Q4 unfinished
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

typedef int ElemType;
typedef int Status;

// Create dynamic array
typedef struct {
    ElemType *elem;
    int length;
    int listsize;
} SqList;

Status InitList_Sq(SqList *L) {
    L->elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if(!L->elem) {
        printf("Failed to initialized array");
        exit(OVERFLOW);
    }
    L->length = 0;
    L->listsize = LIST_INIT_SIZE;
    return OK;
}

Status ListInsert_Sq(SqList *L, int pos, ElemType e) {
    if(pos < 1 || pos > L->length+1) {
        printf("Error in insert pos\n");
        return ERROR;
    }
    if(L->length >= L->listsize) {
        ElemType *newbase = (ElemType*)realloc(L->elem, (L->listsize + LISTINCREMENT) * sizeof(ElemType));
        if(!newbase) {
            printf("Failed to allocate space\n");
            exit(OVERFLOW);
        }
        L->elem = newbase;
        L->listsize += LISTINCREMENT;
    }
    ElemType *q = &(L->elem[pos-1]);
    ElemType *p = &(L->elem[L->length-1]);
    for(; p >= q; --p) *(p + 1) = *p;
    *q = e;
    ++L->length;
    return OK;
}

Status visit(ElemType e) {
    printf("%d ", e);
    return OK;
}

Status ListTraverse_Sq(SqList L, Status (*pfn_visit)(ElemType)) {
    if(!L.elem) {
        printf("Non-initialized list/Destroyed list\n");
        return ERROR;
    }
    if(L.length == 0) printf("No elements\n");
    for(int i = 0; i < L.length; i++) visit(L.elem[i]);
    printf("\n");
    return OK;
}

// Question 4 Using array, reverse the order while getting the max total for a[u] – a[v] + a[w] –a[x]
Status reorderToMaxTotal(SqList L) {
    // {3, 9, 10, 1, 30, 40}
    if(!L.elem) {
        printf("Non-initialized list/Destroyed list\n");
        exit(ERROR);
    }
    if(L.length == 0) printf("No elements to get sum\n");
    int i, total, max = 0;
    int num1, num2, num3, num4;
    while(i != L.length) {
        num1 = L.elem[i+1];
        num2 = L.elem[i+2];
        num3 = L.elem[i+3];
        num4 = L.elem[i+4];
        total = findMax(num1, num2, num3, num4);
        if(total > max) max = total;
        else i++;
    }
    return max;
}

int findMax(ElemType a, ElemType b, ElemType c, ElemType d) {
    int num1 = a;
    int num2 = b;
    int num3 = c;
    int num4 = d;
    int max = a - b + c - d;
    return max;
}

Status ListTraverseMax_Sq(SqList L, Status (*pfn_visit)(ElemType)) {
    // {3, 9, 10, 1, 30, 40}
    if(!L.elem) {
        printf("Non-initialized list/Destroyed list\n");
        return ERROR;
    }
    if(L.length == 0) printf("No elements\n");
    for(int i = 0; i < L.length; i++) {
        visit(L.elem[i]);
        if(i == 0 || i == 2) printf("- ");
        else if(i == 1) printf("+ ");
    }
    printf("\n");
    return OK;
}

int main() {
    SqList a;
    InitList_Sq(&a);
    ListInsert_Sq(&a, 1, 3);
    ListInsert_Sq(&a, 2, 9);
    ListInsert_Sq(&a, 3, 10);
    ListInsert_Sq(&a, 4, 1);
    ListInsert_Sq(&a, 5, 30);
    ListInsert_Sq(&a, 6, 40);
    ListTraverse_Sq(a, visit);
    
    reorderToMaxTotal(a);
    ListTraverseMax_Sq(a, visit);
    
    return 0;
}