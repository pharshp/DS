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

struct Node * merge(struct Node * start1, struct Node * start2){
    struct Node * p = start1;

    if (p == NULL)
    {
        return start2;
    }
    

    while (p->next != NULL)
    {
        p = p->next;
    }

    p->next = start2;
    return start1;
    

}


int main(){
    struct Node * start1 = NULL;
    struct Node * start2 = NULL;

    int n1;

    printf("Linked List 1\n");
    printf("How many nodes you want to create: ");

    scanf("%d", &n1);


    if (n1 > 0)
    {
        printf("Enter your numbers:\n");

        for(int i = 0; i < n1; i++)
        {
            int data;
            scanf("%d", &data);
            start1 = insertAtEnd(start1, data);

        }

        printf("Given Linklist: ");
        printLinkedList(start1);
    }
    

    int n2;

    printf("Linked List 2\n");
    printf("How many nodes you want to create: ");

    scanf("%d", &n2);


    if (n2 > 0)
    {
        printf("Enter your numbers:\n");

        for(int i = 0; i < n2; i++){
            int data;
            scanf("%d", &data);
            start2 = insertAtEnd(start2, data);

        }

        printf("Given Linklist: ");
        printLinkedList(start2);
    }
    

    
    start1 = merge(start1, start2);


    printf("Merged Linklist: ");
    printLinkedList(start1);






    return 0;

}
