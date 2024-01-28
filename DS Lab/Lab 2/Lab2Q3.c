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


struct Node * insertAtEnd(struct Node * start, int data) {

    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = NULL;

    if(start == NULL){
        //start = ptr;
        return ptr;
    } else {

        struct Node * p = start;

        while(p->next != NULL){
            p = p->next;
        }

        p->next = ptr;
    }

    return start;

}

struct Node * deleteFirstNode(struct Node * start){
    struct Node * ptr = start->next;

    free(start);

    return ptr;

}

void deleteLastNode(struct Node * start){
    struct Node * p = start;

        while(p->next->next != NULL){
            p = p->next;
        }

        free(p->next);

        p->next = NULL;



}

void deleteInBetween(struct Node * start, int index){
    struct Node * p = start;

    for(int i = 0; i < index - 1; i++){
        p = p->next;
    }

    struct Node * ptr = p->next;

    p->next = ptr->next;

    free(ptr); 
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

    

    printf("Which node you want to delete?\n");

    printf("1) First\n");
    printf("2) In between\n");
    printf("3) Last\n");

    int num;
    scanf("%d", &num);

    if (num == 1)
    {
        start = deleteFirstNode(start);
    } 
    else if (num == 2)
    {
        int index;
        printf("Enter the index: ");
        scanf("%d", &index);

        deleteInBetween(start, index);
    } 
    else if (num == 3)
    {
        deleteLastNode(start);
    } 
    else
    {
        printf("Invalid choice");
    }

    printf("Linkedlist: ");
    printLinkedList(start);






    return 0;

}
