/*************************************************************
 * File Name: Q5.c
 * Author:    Mikaela Montaos
 *            Engineering School, NPU
 * Description: Homework Q5 unfinished
 *************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Create int LL
typedef int ElemType;

typedef struct Lnode {
    ElemType data;
    struct Lnode *next;
} LNode;

LNode *create_LinkList(void) {
    int data;
    LNode *head, *p, *q;
    head = p = (LNode *) malloc(sizeof (LNode));
    head->next = NULL;
    do {
        scanf("%d", & data);
        q = (LNode *) malloc(sizeof (LNode));
        q->data = data;
        q->next = p->next;
        p->next = q;
        p = q;
    } while (getchar() != '\n');
    return (head);
}

void printList(LNode* list) {
    printf("Head");
    while (1) {
        printf("->");
        list = list->next;
        if (list->next == NULL) {
            printf("%d->NULL\n", list->data);
            break;
        } else
            printf("%d", list->data);
    }
}

// Create circular LL

LNode *circular_LinkList(void) {
    int data;
    LNode *head, *p, *q;
    head = p = (LNode *) malloc(sizeof (LNode));
    head->next = NULL;
    do {
        scanf("%d", & data);
        q = (LNode *) malloc(sizeof (LNode));
        q->data = data;
        q->next = p->next;
        p->next = q;
        p = q;
    } while (getchar() != '\n');
    p->next = head;
    return (head);
}

void cir_printList(LNode* list) {
    LNode *head;
    head = list;
    printf("Head");
    while (1) {
        printf("=>");
        list = list->next;
        if (list->next == head) {
            printf("%d=>Head\n", list->data);
            break;
        } else
            printf("%d", list->data);
    }
}

// Create char LL

typedef char CElemType;

typedef struct Cnode {
    CElemType data;
    struct Cnode *next;
} CNode;

CNode *create_char_cir_LinkList(void) {
    char data;
    CNode *head, *p, *q;
    head = p = (CNode *) malloc(sizeof (CNode));
    head->next = NULL;
    do {
        scanf("%c", &data);
        q = (CNode *) malloc(sizeof (CNode));
        q->data = data;
        q->next = p->next;
        p->next = q;
        p = q;
    } while (getchar() != '\n');
    p->next = head;
    return (head);
}

void char_cir_printList(CNode* list) {
    CNode *head = list;
    printf("Head");
    while (1) {
        printf("=>");
        list = list->next;
        if (list->next == head) {
            printf("%c=>Head\n", list->data);
            break;
        } else printf("%c", list->data);
    }
}

// Create doubly LL

typedef struct Dulnode{     
    CElemType  data ;
    struct Dulnode  *prior , *next ;
}DulNode ;

DulNode  *create_Dul_LinkList(void){  
  char data;
  DulNode *head, *p, *q;
  head=p=(DulNode *)malloc(sizeof(DulNode)); 
  head->next=NULL; head->prior=NULL;       
  do{ 
      scanf("%c",& data);
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
      printf("%c->NULL\n", list->data);
      break;
    }
    else 
      printf("%c",list->data);
  }
}

// Question 5 Rearrange and start using given index #
void rotate_DLL(DulNode *D, int i) {
    /* 
     * NULL<-Head<=>c<=>i<=>v<=>i>=>c->NULL
     * NULL<-Head<=>v<=>i<=>c<=>c>=>i->NULL
     */
    DulNode *p, *list;
    p = D;
    int count = 0;
    while(p->next != NULL && count != i) {
      p = p->next;
      count++;
    }
    if(p == NULL || count > i) printf("Error\n");
    else if(count == i) {
      list = p;
      dul_printList(list);
    }
}

int main(void) {
    DulNode *dul;
    dul = create_Dul_LinkList();
    dul_printList(dul);
    
    printf("Rotate DLL = ");
    rotate_DLL(dul, 2);   

    return 0;
}