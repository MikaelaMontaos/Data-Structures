/*************************************************************
 * File Name: Q2.c
 * Author:    Mikaela Montaos
 *            Engineering School, NPU
 * Description: Lab4 Q2 solved
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

// Question 2 Using static array, get element indices & count of dupes

void getIndex(CharSeqList *s, const CharElemType e) { 
    // {'b', 'e', 'e', 'e', 'a', 't', 'e', 'r'}
    int count = 0;
    for(int i = 0; i < s->length; i++) {
        if(e == s->data[i]) {
            printf("%d ", i);
            count++;
        }
    }
    printf("\nCount of duplicate elements = %d", count);
}

int main(void) {
    CharSeqList *s = InitList();

    ListInsert(s, 0, 'b');
    ListInsert(s, 1, 'e');
    ListInsert(s, 2, 'e');
    ListInsert(s, 3, 'e');
    ListInsert(s, 4, 'a');
    ListInsert(s, 5, 't');
    ListInsert(s, 6, 'e');
    ListInsert(s, 7, 'r');

    printf("e elements are in indices = ");
    getIndex(s, 'e');

    
    return 0;
}
