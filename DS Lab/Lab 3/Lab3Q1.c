/*
WAP to insert an item into a doubly linked list
WAP to delete an item in a doubly linked list
WAP to implement linked list in an array as discussed in class
*/

#include <stdio.h>
#include <stdlib.h>


struct Node
{
    int data;
    struct Node * next;
    struct Node * prev;
};

struct List
{
    struct Node * fnode;
    struct Node * lnode;
};


void printLinkedList(struct List * ptr);
void revprintLinkedList(struct List * ptr);
void insertAtStart(struct List * list, int data);
void insertAtEnd(struct List * list, int data);
void insertInBetween(struct List * list, int data, int index);

int sizeOfLinkedList(struct List * ptr);



int main()
{
    // struct Node * NULL;

    struct List * myLinkedList = (struct List *) malloc(sizeof(struct List));

    myLinkedList->fnode = NULL;
    myLinkedList->lnode = NULL;



    int n;

    printf("How many nodes you want to create: ");

    scanf("%d", &n);

    if (n == 0){
        printf("No nodes created!");
        exit(0);
    }
    else if (n < 0)
    {
        printf("Invalid input!");
        exit(0);
    }


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
    printf("2) In between (give index)\n");
    printf("3) At end\n");

    int num, value;
    scanf("%d", &num);

    //printf("Enter the value you want to add: ");
    //scanf("%d", &value);

    if (num == 1)
    {

        printf("Enter the value you want to add: ");
        scanf("%d", &value);
        insertAtStart(myLinkedList, value);
    }
    else if (num == 2)
    {
        int index;
        printf("Enter the index: ");
        scanf("%d", &index);

        //printf("size is %d", sizeOfLinkedList(myLinkedList));

        if (index > 0 && index < sizeOfLinkedList(myLinkedList))
        {
            printf("Enter the value you want to add: ");
            scanf("%d", &value);
            insertInBetween(myLinkedList, value, index);
        } else
        {
            printf("Invalid index!");
            exit(0);
        }
    }
    else if (num == 3)
    {

        printf("Enter the value you want to add: ");
        scanf("%d", &value);
        insertAtEnd(myLinkedList, value);
    }
    else
    {
        printf("Invalid choice!");
        exit(0);
    }



    //insertAtStart(start, 500);


    printLinkedList(myLinkedList);


    return 0;

}








void printLinkedList(struct List * list)
{
    struct Node * ptr = list->fnode;

    while(ptr != NULL){
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
    //revprintLinkedList(list);
}


void revprintLinkedList(struct List * list)
{
    struct Node * ptr = list->lnode;

    while(ptr != NULL){
        printf("%d ", ptr->data);
        ptr = ptr->prev;
    }
    printf("\n");
}


void insertAtStart(struct List * list, int data)
{
    struct Node * start = list->fnode;
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));

    ptr->data = data;
    ptr->prev = NULL;

    ptr->next = list->fnode;
    list->fnode->prev = ptr;

    list->fnode = ptr;

    // return ptr;

}


 void insertAtEnd(struct List * list, int data)
 {

    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = NULL;

    if(list->fnode == NULL){
        ptr->prev = NULL;
        //ptr;
        list->fnode = ptr;
        list->lnode = ptr;
        // return list->fnode;
    } else {

        struct Node * p = list->fnode;

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

    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->data = data;

    struct Node * p = list->fnode;

    for(int i = 0; i < index - 1; i++){
        p = p->next;
    }

    ptr->next = p->next;
    ptr->prev = p;
    p->next = ptr;
    ptr->next->prev = ptr;

    //printf("%d", p->data);
}

int sizeOfLinkedList(struct List * list){
    struct Node * ptr = list->fnode;
    int n = 0;

    while(ptr != NULL){
        n++;
        ptr = ptr->next;
    }

    return n;
}
