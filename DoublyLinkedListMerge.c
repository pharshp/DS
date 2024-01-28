#include <stdio.h>
#include <stdlib.h>


struct Poly
{
    int data;
    struct Poly * next;
    struct Poly * prev;
};

struct List
{
    struct Poly * fnode;
    struct Poly * lnode;
};


void printLinkedList(struct List * ptr);
void revprintLinkedList(struct List * ptr);
void insertAtEnd(struct List * list, int data);

void merge(struct List * list1,struct List * list2);



int main()
{
    // struct Node * NULL;

    printf("Linked list 1\n");

    struct List * myLinkedList1 = (struct List *) malloc(sizeof(struct List));

    myLinkedList1->fnode = NULL;
    myLinkedList1->lnode = NULL;



    int n1;

    printf("How many nodes you want to create: ");

    scanf("%d", &n1);


    printf("Enter your numbers:\n");

    for(int i = 0; i < n1; i++){
        int data;
        scanf("%d", &data);
        insertAtEnd(myLinkedList1, data);

    }

    printf("Given Linklist: ");
    
    // printf("%d", myLinkedList->fnode->data);
    printLinkedList(myLinkedList1);

    printf("Linked list 2\n");

    struct List * myLinkedList2 = (struct List *) malloc(sizeof(struct List));

    myLinkedList2->fnode = NULL;
    myLinkedList2->lnode = NULL;



    int n2;

    printf("How many nodes you want to create: ");

    scanf("%d", &n2);


    printf("Enter your numbers:\n");

    for(int i = 0; i < n2; i++){
        int data;
        scanf("%d", &data);
        insertAtEnd(myLinkedList2, data);

    }

    printf("Given Linklist: ");
    
    // printf("%d", myLinkedList->fnode->data);
    printLinkedList(myLinkedList2);

    printf("Merged linked list: ");

    merge(myLinkedList1, myLinkedList2);

    printLinkedList(myLinkedList1);


    return 0;

}








void printLinkedList(struct List * list)
{
    struct Poly * ptr = list->fnode;

    while(ptr != NULL){
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
    //revprintLinkedList(list);
}


void revprintLinkedList(struct List * list)
{
    struct Poly * ptr = list->lnode;

    while(ptr != NULL){
        printf("%d ", ptr->data);
        ptr = ptr->prev;
    }
    printf("\n");
}


 void insertAtEnd(struct List * list, int data)
 {

    struct Poly * ptr = (struct Poly *) malloc(sizeof(struct Poly));
    ptr->data = data;
    ptr->next = NULL;

    if(list->fnode == NULL){
        ptr->prev = NULL;
        //ptr;
        list->fnode = ptr;
        list->lnode = ptr;
        // return list->fnode;
    } else {

        struct Poly * p = list->fnode;

        while(p->next != NULL){
            p = p->next;
        }

        p->next = ptr;
        ptr->prev = p;

        list->lnode = ptr;
    }

    // return list->fnode;

}


void merge(struct List * list1, struct List * list2)
{
    list1->lnode->next = list2->fnode;
    list2->fnode->prev = list1->lnode;
    list1->lnode = list2->lnode;
}