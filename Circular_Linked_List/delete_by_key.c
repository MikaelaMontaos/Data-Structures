// Delete an element by key

#include <stdio.h>
#include <stdlib.h>

typedef struct Lnode {
        int data;
        struct Lnode *next;
} LNode;

LNode *create(void) {
        printf("Enter numbers separated by spaces (ENTER when done): ");
        int data;
        LNode *head, *cur, *tmp;
        head = cur = (LNode *)malloc(sizeof(LNode));
        head->next = NULL;
        do {
                scanf("%d", &data);
                tmp = (LNode *)malloc(sizeof(LNode));
                tmp->data = data;
                tmp->next = cur->next;
                cur->next = tmp;
                cur = tmp;
        } while(getchar() != '\n');
        cur->next = head;
        return (head);
}

void print(LNode* list) {
        LNode *head;
        head = list;
        printf("Head ");
        while (1) {
                printf("=> ");
                list = list->next;
                if (list->next == head) {
                        printf("%d => Head\n", list->data);
                        break;
                } else
                        printf("%d ", list->data);
        }
}

void delete_by_key(LNode *list, int key) {
        LNode *p1, *p2, *del;
        p1 = list->next;
        p2 = list;

	if(p1 == list) printf("Invalid key\n");
	
        while(p1 != list) {
                if(p1->data == key) {
                        del = p1;
                        p1 = p1->next;
                        p2->next = p1;
                        free(del);
                }
                p2 = p1;
                p1 = p1->next;
        }
}

int main(void) {
        LNode *list;
        list = create();
        print(list);

        printf("Delete by key (2): ");
        delete_by_key(list, 2);
        print(list);

        return 0;
}
