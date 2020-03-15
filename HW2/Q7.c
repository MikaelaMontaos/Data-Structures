/*************************************************************
 * File Name: Q7.c
 * Author:    Mikaela Montaos
 *            Engineering School, NPU
 * Description: Homework Q7 solved
 *************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Create Ploy LL

typedef struct ploy {
    float coef;
    int expn;
    struct ploy *next;
} Ploy;

void ploy_printList(Ploy* list) {
    printf("Head");
    while (1) {
        printf("->");
        list = list->next;
        if (list->next == NULL) {
            printf("(%0.2f, %d)->NULL\n", list->coef, list->expn);
            break;
        } else printf("(%0.2f, %d)", list->coef, list->expn);
    }
}

// Question 7 2 polynomial multiplication operation
Ploy *conv_LL(Ploy *La, Ploy *Lb) { //
    Ploy *Lc, *pc, *pa, *pb, *ptr;
    float x;
    Lc = pc = La;
    pa = La->next;
    pb = Lb->next;

    while (pa != NULL && pb != NULL) {
        if (pa->expn < pb->expn) {
            pc->next = pa;
            pc = pa;
            pa = pa->next;
        } else if (pa->expn > pb->expn) {
            pc->next = pb;
            pc = pb;
            pb = pb->next;
        } else {
            x = pa->coef * pb->coef;
            if (fabsf(x) <= 1.0e-6) {
                ptr = pa;
                pa = pa->next;
                ptr = pb;
                pb = pb->next;
            } else {
                pc->next = pa;
                pa->coef = x;
                pc = pa;
                pa = pa->next;
                ptr = pb;
                pb = pb->next;   
            }
        }
    }
    if (pa == NULL) pc->next = pb;
    else pc->next = pa;
    return (Lc);
}

int main(void) {
    /*
    l = 1^0 + 2^2 + 3^3 + 4^5
    m = 5^0 + 6^1 + 7^3 + 8^4
    l * m = ?
    */
    Ploy head1, t10, t11, t12, t13;
    Ploy head2, t20, t21, t22, t23;

    t10.coef = 1;
    t10.expn = 0;
    t11.coef = 2;
    t11.expn = 2;
    t12.coef = 3;
    t12.expn = 3;
    t13.coef = 4;
    t13.expn = 5;
    head1.next = &t10;
    t10.next = &t11;
    t11.next = &t12;
    t12.next = &t13;
    t13.next = NULL;
    printf("Ploy 1 = ");
    ploy_printList(&head1);

    t20.coef = 5;
    t20.expn = 0;
    t21.coef = 6;
    t21.expn = 1;
    t22.coef = 7;
    t22.expn = 3;
    t23.coef = 8;
    t23.expn = 4;
    head2.next = &t20;
    t20.next = &t21;
    t21.next = &t22;
    t22.next = &t23;
    t23.next = NULL;
    printf("Ploy 2 = ");
    ploy_printList(&head2);

    Ploy *p;
    p = conv_LL(&head1, &head2);
    printf("Ploy 1 * Ploy 2 = ");
    ploy_printList(p);
    
    return 0;
}