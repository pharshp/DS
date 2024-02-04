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
void insertAtEnd(struct List * list, int data);

void deleteFirstNode(struct List * list);
void deleteInBetween(struct List * list, int index);
void deleteLastNode(struct List * list);

int sizeOfLinkedList(struct List * list){
    struct Node * ptr = list->fnode;
    int n = 0;

    while(ptr != NULL){
        n++;
        ptr = ptr->next;
    }

    return n;
}




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

    printf("Which node you want to delete?\n");

    // printf("1) First\n");
    printf("Enter index: ");
    // printf("3) Last\n");

    int index;
    scanf("%d", &index);

    
    if (index == n - 1)
    {
        deleteLastNode(myLinkedList);
    }
    else if (index == 0)
    {
        deleteFirstNode(myLinkedList);
    }
    else if (index > 0 && index < n - 1)
    {
        deleteInBetween(myLinkedList, index);

        //deleteInBetween(myLinkedList, index);
    }
    else
    {
        printf("Invalid index!");
        exit(0);
    }

    printf("Linkedlist: ");
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

void deleteFirstNode(struct List *list)
{
    list->fnode = list->fnode->next;
    free(list->fnode->prev);
    list->fnode->prev = NULL;

}

void deleteInBetween(struct List *list, int index)
{
    struct Node * p = list->fnode;

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
    if (list->fnode->next == NULL) // only one element is present
    {
        free(list->fnode);
        list->fnode = NULL;
        list->lnode = NULL;
        return;
    }
    
    list->lnode = list->lnode->prev;
    free(list->lnode->next);
    list->lnode->next = NULL;
}
