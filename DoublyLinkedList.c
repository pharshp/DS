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
void insertAtStart(struct List * list, int data);
void insertAtEnd(struct List * list, int data);
void insertInBetween(struct List * list, int data, int index);



int main()
{
    // struct Node * NULL;

    struct List * myLinkedList = (struct List *) malloc(sizeof(struct List));

    myLinkedList->fnode = NULL;
    myLinkedList->lnode = NULL;



    int n;

    printf("How many nodes you want to create: ");

    scanf("%d", &n);


    printf("Enter your numbers:\n");

    for(int i = 0; i < n; i++){
        int data;
        scanf("%d", &data);
        insertAtEnd(myLinkedList, data);

    }

    printf("Given Linklist: ");
    
    // printf("%d", myLinkedList->fnode->data);
    printLinkedList(myLinkedList);

    printf("Where you want to add node?\n");

    printf("1) At start\n");
    printf("2) In between\n");
    printf("3) At end\n");

    int num, value;
    scanf("%d", &num);

    printf("Enter the value you want to add: ");
    scanf("%d", &value);

    if (num == 1)
    {
        insertAtStart(myLinkedList, value);
    } 
    else if (num == 2)
    {
        int index;
        printf("Enter the index: ");
        scanf("%d", &index);

        insertInBetween(myLinkedList, value, index);
    } 
    else if (num == 3)
    {
        insertAtEnd(myLinkedList, value);
    } 
    else
    {
        printf("Invalid choice");
    }
    
    
    
    //insertAtStart(start, 500);


    printLinkedList(myLinkedList);


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


void insertAtStart(struct List * list, int data)
{
    struct Poly * start = list->fnode;
    struct Poly * ptr = (struct Poly *) malloc(sizeof(struct Poly));
    
    ptr->data = data;
    ptr->prev = NULL;

    ptr->next = list->fnode;
    list->fnode->prev = ptr;

    list->fnode = ptr;

    // return ptr;

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


void insertInBetween(struct List * list, int data, int index)
{

    struct Poly * ptr = (struct Poly *) malloc(sizeof(struct Poly));
    ptr->data = data; 

    struct Poly * p = list->fnode;

    for(int i = 0; i < index - 1; i++){
        p = p->next;
    }

    ptr->next = p->next;
    ptr->prev = p;
    p->next = ptr;
    ptr->next->prev = ptr;

    //printf("%d", p->data);
}
