
#include <stdio.h>
#include <stdlib.h>

struct Poly{
    int data;
    struct Poly * next;
};

void printPolynomial(struct Poly * ptr){
    while(ptr != NULL){
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}


struct Poly * insertAtEnd(struct Poly * start, int data) {

    struct Poly * ptr = (struct Poly *) malloc(sizeof(struct Poly));
    ptr->data = data;
    ptr->next = NULL;

    if(start == NULL){
        //start = ptr;
        return ptr;
    } else {

        struct Poly * p = start;

        while(p->next != NULL){
            p = p->next;
        }

        p->next = ptr;
    }

    return start;

}

void searchLinkedList(struct Poly * start, int num){
    struct Poly * ptr = start;

    for (int i = 0; ptr != NULL; i++)
    {
        if (ptr->data == num)
        {
            printf("First occurence of %d is at index %d", num, i);
            return;
        }
        
        ptr = ptr->next;
    }
    printf("%d is not present in the linked list", num);
    
    
}

int main(){
    struct Poly * start = NULL;

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
    printPolynomial(start);

    
    int num;

    printf("Enter the number which you want to search: ");
    scanf("%d", &num);

    
    searchLinkedList(start, num);






    return 0;

}
