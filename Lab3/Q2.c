/*************************************************************
 * File Name: Q2.c
 * Author:    Mikaela Montaos
 *            Engineering School, NPU
 * Description: Lab3 Q2 unfinished
 *************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef int ElemType;

// Create doubly LL

typedef struct Dulnode{     
    ElemType  data ;
    struct Dulnode  *prior , *next ;
}DulNode ;

DulNode  *create_Dul_LinkList(void){  
  int data;
  DulNode *head, *p, *q;
  head=p=(DulNode *)malloc(sizeof(DulNode)); 
  head->next=NULL; head->prior=NULL;       
  do{ 
      scanf("%d",& data);
      q= (DulNode  *)malloc(sizeof(DulNode)); 
      q->data=data;     
      q->next=p->next;
      q->prior=p;
      p->next=q; 
      p=q ; 
  }while(getchar()!='\n');
  p->next = NULL;
  return (head);
}

void dul_printList(DulNode* list){
  DulNode *head;
  printf("NULL<-Head");
  while(1){
    printf("<=>");
    list = list->next;
    if(list->next == NULL) {
      printf("%d->NULL\n", list->data);
      break;
    }
    else 
      printf("%d",list->data);
  }
}

// Question 2 Doubly LL delete by index
void dul_LL_delete_index(DulNode *D, int index) { 
    // NULL<-Head<=>11<=>9<=>13<=>8->NULL
    DulNode *p1, *p2, *d;
    p1 = D->next;
    p2 = D;
    int count = 0;

    while(p1 != D) {
      if(count == index) {
        d = p1;
        p2->next = p1->next;
        p2->next->prior = p1->prior->prior;
        free(d);
      }
      else p2 = p1;
      p1 = p1->next;
    }
    if(p1 == D) printf("No elements\n");
}

int main(void) {
    DulNode *dul;
    dul = create_Dul_LinkList();
    dul_printList(dul);
    
    printf("Delete doubly LL by index (start at 0) = ");
    dul_LL_delete_index(dul, 3);

    return 0;
}
