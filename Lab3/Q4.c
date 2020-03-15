/*************************************************************
 * File Name: Q4.c
 * Author:    Mikaela Montaos
 *            Engineering School, NPU
 * Description: Lab3 Q4 unfinished
 *************************************************************/

#include <stdio.h>
#include <stdlib.h>

// Create char LL

typedef char CElemType;

typedef struct Cnode {
    CElemType data;
    struct Cnode *prior , *next ;
} CNode;

CNode *create_char_dul_LinkList(void) {
    char data;
    CNode *head, *p, *q;
    head=p=(CNode *)malloc(sizeof(CNode)); 
    head->next=NULL; head->prior=NULL;do{ 
      scanf("%s",& data);
      q= (CNode  *)malloc(sizeof(CNode)); 
      q->data=data;     
      q->next=p->next;
      q->prior=p;
      p->next=q; 
      p=q ; 
  }while(getchar()!='\n');
  p->next = NULL;
  return (head);
}

void char_dul_printList(CNode* list) {
  CNode *head;
  //head = list;
  printf("NULL<-Head");
  while(1){
    printf("<=>");
    list = list->next;
    if(list->next == NULL) {
      printf("%c->NULL\n", list->data);
      break;
    }
    else 
      printf("%c",list->data);
  }
}

// Question 4 Reverse char doubly LL
CNode *rev_dul_LL(CNode *C) { 
    // NULL<-Head<=>r<=>A<=>d<=>a<=>R->NULL
    CNode *c, *p, *n; // c=current, p=previous, n=next
    c = C;
    p = NULL;
    while (c != NULL) {
        n = c->next; 
        c->next = p;
        c->prior = n;
        p = c;
        c = n;
    }
    C = p;
    return C;
}

int main(void) {
    CNode *c;
    c = create_char_dul_LinkList();
    char_dul_printList(c);
    
    CNode *rev;
    rev = rev_dul_LL(c);
    printf("Reverse char doubly LL = ");
    char_dul_printList(rev);

    return 0;
}
