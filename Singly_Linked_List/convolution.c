/*
l1 = 1x^0 +        2x^2 + 3x^3 +       4x^5
l2 = 5x^0 + 6x^1 +      + 7x^3 + 8x^4

Output:
l1->coef * l2->coef
l1->expn + l2->expn
...
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct ploy {
    int coef, expn;
    struct ploy *next;
} Ploy;

void print_ploy(Ploy* l) {
    printf("Head ");
    while (1) {
        printf("-> ");
        l = l->next;
        if (l->next == NULL) {
            printf("%dx^%d -> NULL\n", l->coef, l->expn);
            break;
        } 
        else printf("%dx^%d ", l->coef, l->expn);
    }
}

Ploy* push(Ploy* l, int coef, int expn) {
    Ploy* new_ploy = (Ploy*)malloc(sizeof(Ploy));
    new_ploy->coef = coef;
    new_ploy->expn = expn;
    new_ploy->next = NULL;
    if(l == NULL) return new_ploy;
    
    Ploy *cur = l;
    while(cur->next != NULL) cur = cur->next;
    cur->next = new_ploy;
    return new_ploy;
}

Ploy *conv(Ploy *l1, Ploy *l2) {
    Ploy *p1, *p2, *cur, *l3, *p3, *tmp;
    l3 = p3 = (Ploy*)malloc(sizeof(Ploy));
    l3->next = NULL;
    p1 = l1->next;
    p2 = l2->next;

    while (p1 != NULL && p2 != NULL) {
        tmp = (Ploy*)malloc(sizeof(Ploy));
        tmp->coef = p1->coef * p2->coef;
        tmp->expn = p1->expn + p2->expn;
        tmp->next = p3->next;
        p3->next = tmp;
        p3 = tmp;
        p1 = p1->next;
        p2 = p2->next;
    }
    return l3;
}

int main(void) {
    Ploy head1, t10, t11, t12, t13;
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
    
    printf("Poly 1\n");
    print_ploy(&head1);

    Ploy head2, t20, t21, t22, t23;
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
    
    printf("Poly 2\n");
    print_ploy(&head2);

    Ploy *new_ploy;
    new_ploy = conv(&head1, &head2);
    printf("Poly 1 * Poly 2\n");
    print_ploy(new_ploy);
    
    return 0;
}