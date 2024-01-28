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

void deleteFirstNode(struct List * list);
void deleteInBetween(struct List * list, int index);
void deleteLastNode(struct List * list);



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

    printf("Which node you want to delete?\n");

    printf("1) First\n");
    printf("2) In between\n");
    printf("3) Last\n");

    int num;
    scanf("%d", &num);

    if (num == 1)
    {
        deleteFirstNode(myLinkedList);
    } 
    else if (num == 2)
    {
        int index;
        printf("Enter the index: ");
        scanf("%d", &index);

        deleteInBetween(myLinkedList, index);
    } 
    else if (num == 3)
    {
        deleteLastNode(myLinkedList);
    } 
    else
    {
        printf("Invalid choice");
    }

    printf("Linkedlist: ");
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

void deleteFirstNode(struct List *list)
{
    list->fnode = list->fnode->next;
    free(list->fnode->prev);
    list->fnode->prev = NULL;

}

void deleteInBetween(struct List *list, int index)
{
    struct Poly * p = list->fnode;

    for(int i = 0; i < index - 1; i++){
        p = p->next;
    }

    // struct Node * ptr = p->next;

    p->next = p->next->next;


    free(p->next->prev); 
    p->next->prev = p;
}

void deleteLastNode(struct List *list)
{
    list->lnode = list->lnode->prev;
    free(list->lnode->next);
    list->lnode->next = NULL;
}
