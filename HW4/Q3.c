/*************************************************************
 * File Name: Q3.c
 * Author:    Mikaela Montaos
 *            Engineering School, NPU
 * Description: Homework Q3 unfinished
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

// Question 3 Using array, split into two array while having a sum of 5 in each
int sumOf5(SqList L) {
    // {1, 3, 2, 1, 2, 1}
    int leftSum, rightSum;
    for(int i = 0; i < L.length; i++) {
        leftSum += L.elem[i+1];
        for(int j = i+1; j < L.length; j++) {     
            rightSum += L.elem[j+1];
            if(leftSum == rightSum) return i + 1;
        }
    }
    return -1;
}
Status ListTraverse5_Sq(SqList L, Status (*pfn_visit)(ElemType)) {
    int splitPoint = sumOf5(L);
    if(splitPoint == -1 || splitPoint == L.length) {
        printf("Cannot split array into equal sum\n");
        return ERROR;
    }
    for(int i = 0; i < L.length; i++) {
        if(splitPoint == i) printf("\n");
        visit(L.elem[i-1]);
    }
    return OK;
}

int main() {
    SqList arr;
    InitList_Sq(&arr);
    ListInsert_Sq(&arr, 1, 1);
    ListInsert_Sq(&arr, 2, 3);
    ListInsert_Sq(&arr, 3, 2);
    ListInsert_Sq(&arr, 4, 1);
    ListInsert_Sq(&arr, 5, 2);
    ListInsert_Sq(&arr, 6, 1);
    ListTraverse_Sq(arr, visit);
    
    sumOf5(arr);
    ListTraverse5_Sq(arr, visit);

    return 0;
}