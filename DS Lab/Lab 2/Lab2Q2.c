/*
1) write a program for multiply two 2d matrox considering all the options (size 50 50)
2) create a linked list and add a node
2) wap to delete a node from a linked list
*/

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node * next;
};

void printLinkedList(struct Node * ptr){
    while(ptr != NULL){
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

struct Node * insertAtStart(struct Node * start, int data){
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    
    ptr->data = data;
    ptr->next = start;

    return ptr;

}

 struct Node * insertAtEnd(struct Node * start, int data){

    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = NULL;

    if(start == NULL){
        start = ptr;
        return start;
    }else{

        struct Node * p = start;

        while(p->next != NULL){
            p = p->next;
        }

        p->next = ptr;
    }

    return start;

}

void insertInBetween(struct Node * start, int data, int index){

    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node * p = start;

    for(int i = 0; i < index - 1; i++){
        p = p->next;
    }

    ptr->next = p->next;
    p->next = ptr;
    //printf("%d", p->data);
}



int main(){
    struct Node * start = NULL;

    int n;

    printf("How many nodes you want to create: ");

    scanf("%d", &n);


    printf("Enter your numbers:\n");

    for(int i = 0; i < n; i++){
        int data;
        scanf("%d", &data);
        start = insertAtEnd(start, data);

    }

    printf("Given Linklist: ");
    printLinkedList(start);

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
        start = insertAtStart(start, value);
    } 
    else if (num == 2)
    {
        int index;
        printf("Enter the index: ");
        scanf("%d", &index);

        insertInBetween(start, value, index);
    } 
    else if (num == 3)
    {
        start = insertAtEnd(start, value);
    } 
    else
    {
        printf("Invalid choice");
    }
    
    
    
    //start = insertAtStart(start, 500);


    printLinkedList(start);






    return 0;

}
