/*************************************************************
 * File Name: Q3.c
 * Author:    Mikaela Montaos
 *            Engineering School, NPU
 * Description: Lab3 Q3 solved
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
  //head = list;
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

// Question 3 Sort dul LL in ascending order
void srt_dul_LL(DulNode *D) { 
    // NULL<-Head<=>2<=>0<=>2<=>0->NULL
    DulNode *p1, *p2 = D;
    int sort;

    while (p1 != NULL) {
        p2 = p1;
        while (p2 != NULL) {
            if (p1->data > p2->data) {
                sort = p1->data;
                p1->data = p2->data;
                p2->data = sort;
            }
            p2 = p2->next;
        }
        p1 = p1->next;
    }
}

int main(void) {
    DulNode *dul;
    dul = create_Dul_LinkList();
    dul_printList(dul);

    srt_dul_LL(dul);
    dul_printList(dul);


    return 0;
}
