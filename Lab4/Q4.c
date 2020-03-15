/*************************************************************
 * File Name: Q4.c
 * Author:    Mikaela Montaos
 *            Engineering School, NPU
 * Description: Lab4 Q4 unfinished
 *************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define MAX_SIZE 10
#define ElemType int
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 5
#define OVERFLOW -2

typedef int Status;
typedef char CharElemType;

// Create static char array

typedef struct {
    CharElemType data[MAX_SIZE];
    int length;
} CharSeqList;

CharSeqList *InitList() {
    CharSeqList *s = (CharSeqList*)malloc(sizeof(CharSeqList));
    if(s == NULL) {
        printf("Failed to allocate memory space by malloc\n");
        exit(1);
    }
    s->length = 0;
    return s;
}

Status ListInsert(CharSeqList *s, int i, const CharElemType e) {
    int k;
    /*
    if(i < 0 || i > s->length) {
        printf("Index is out of range\n");
        return FALSE;
    }
    if(s->length >= MAX_SIZE) {
        printf("Reached max size\n");
        return FALSE;
    }
    */
    if(i <= s->length-1) {
        for(k = s->length-1; k >= i; k--) s->data[k+1] = s->data[k];
    }
    s->data[i] = e;
    s->length++;
    return TRUE;
}

// Create dynamic char array

typedef struct {
    CharElemType *elem;
    int length;
    int listsize;
} CharSqList;

Status InitList_Sq(CharSqList *d) {
    d->elem = (CharElemType*)malloc(LIST_INIT_SIZE * sizeof(CharElemType));
    if(!d->elem) {
        printf("Failed to initialize array\n");
        exit(OVERFLOW);
    }
    d->length = 0;
    d->listsize = LIST_INIT_SIZE;
    return OK;
}

Status ListInsert_Sq(CharSqList *d, int pos, CharElemType e) {
    /*
    if(pos < 1 || pos > d->length+1) {
        printf("Error in int pos\n");
        return ERROR;
    }
    */
    if(d->length >= d->listsize) {
        CharElemType *newbase = (CharElemType*)realloc(d->elem, (d->listsize+LISTINCREMENT) * sizeof(CharElemType));
        if(!newbase) {
            printf("Failed to allocate space\n");
            exit(OVERFLOW);
        }
        d->elem = newbase;
        d->listsize += LISTINCREMENT;
    }
    CharElemType *q = &(d->elem[pos-1]);
    CharElemType *p = &(d->elem[d->length-1]);
    for(; p >= q; --p) *(p + 1) = *p;
    *q = e;
    ++d->length;
    return OK;
}

Status visit(CharElemType e) {
    printf("%c ", e);
    return OK;
}

Status ListTraverse_Sq(CharSqList d, Status(*pfn_visit)(CharElemType)) {
    if(!d.elem) {
        printf("Error: Non-initialized list/Destroyed list\n");
        return ERROR;
    }
    if(d.length == 0) printf("No elements\n");
    for(int i = 0; i < d.length; i++) visit(d.elem[i]);
    return OK;
}

// Question 4 Using dynamic array, merge two arrays into a new array while removing uncommon elements

int ListLength_Sq(CharSqList d) { return d.length; }

Status GetElem_Sq(CharSqList d, int pos, CharElemType *e) {
    if(d.length == 0 || pos < 1 || pos > d.length) return ERROR;
    *e = d.elem[pos-1];
    return OK;
}

Status compare(CharElemType listElem, CharElemType e) {
    if(listElem == e) return TRUE;
    else return FALSE;
}

void cmmSq(CharSqList d1, CharSqList d2) {
    /* 
     * {'C', 'o', 'm', 'p', 'l', 'i', 'm', 'e', 'n', 't'},
     * {'c', 'o', 'm', 'p', 'l', 'e', 'm', 'e', 'n', 't'}, 
     */
    int d1_len = ListLength_Sq(d1);
    int d2_len = ListLength_Sq(d2);
    int len;
    if(d1_len > d2_len) len = d1_len;
    else len = d2_len;
    for(int i = 1; i < len; i++) {
        if(compare(d1.elem[i], d2.elem[i]) == TRUE) visit(d1.elem[i]);
    }
}

int main(void) {
    CharSqList d1, d2;
    CharElemType e;
    int pos;
    
    InitList_Sq(&d1);
    InitList_Sq(&d2);
    
    ListInsert_Sq(&d1, 1, 'C');
    ListInsert_Sq(&d1, 2, 'o');
    ListInsert_Sq(&d1, 3, 'm');
    ListInsert_Sq(&d1, 4, 'p');
    ListInsert_Sq(&d1, 5, 'l');
    ListInsert_Sq(&d1, 6, 'i');
    ListInsert_Sq(&d1, 7, 'm');
    ListInsert_Sq(&d1, 8, 'e');
    ListInsert_Sq(&d1, 9, 'n');
    ListInsert_Sq(&d1, 10, 't');
    
    ListInsert_Sq(&d2, 1, 'c');
    ListInsert_Sq(&d2, 2, 'o');
    ListInsert_Sq(&d2, 3, 'm');
    ListInsert_Sq(&d2, 4, 'p');
    ListInsert_Sq(&d2, 5, 'l');
    ListInsert_Sq(&d2, 6, 'e');
    ListInsert_Sq(&d2, 7, 'm');
    ListInsert_Sq(&d2, 8, 'e');
    ListInsert_Sq(&d2, 9, 'n');
    ListInsert_Sq(&d2, 10, 't');
    
    printf("Dynamic array 1 = ");
    ListTraverse_Sq(d1, visit);
    printf("\nDynamic array 2 = ");
    ListTraverse_Sq(d2, visit);

    printf("\nCommon elements = ");
    cmmSq(d1, d2);  
    
    return 0;
}