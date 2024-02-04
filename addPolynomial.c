#include <stdio.h> // not complete
#include <stdlib.h>

struct Poly{
    int coef;
    int exp;
    struct Poly * next;
};

void printLinkedList(struct Poly * ptr){
    while(ptr != NULL){
        printf("%d %d, ", ptr->coef, ptr->exp);
        ptr = ptr->next;
    }
    printf("\n");
}

void printPolynomial(struct Poly * ptr)
{
    while(ptr != NULL)
    {
        if (ptr->coef != 1)
        {
            printf("%d", ptr->coef);
        }
        

        if (ptr->exp > 1)
        {
            printf("x^%d", ptr->exp);
        } 
        else if (ptr->exp == 1)
        {
            printf("x");
        }
        
        
        
        

        if (ptr->next != NULL)
        {
            printf(" + ");
        }
        
        ptr = ptr->next;
    }
    printf("\n");
}


struct Poly * insertAtEnd(struct Poly * start, int coef, int exp)
{
    struct Poly * ptr = (struct Poly *) malloc(sizeof(struct Poly));
    ptr->coef = coef;
    ptr->exp = exp;
    ptr->next = NULL;

    if(start == NULL){
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

struct Poly * addPolynomial(struct Poly * poly1, struct Poly * poly2){
    
    struct Poly * sum = NULL;
    struct Poly * p1 = poly1;
    struct Poly * p2 = poly2;

    while (p1 == NULL && p2 == NULL)
    {
        int coefSum;
        int exp;

        if (p1->exp == p2->exp)
        {
            coefSum = p1->coef + p2->coef;
            exp = p1->exp;

            sum = insertAtEnd(sum, coefSum, exp);

            p1 = p1->next;
            p2 = p2->next;

        }
        else if (p1->exp > p2->exp)
        {
            coefSum = p1->coef;
            exp = p1->exp;

            sum = insertAtEnd(sum, coefSum, exp);
            
            p1 = p1->next;
        }
        else
        {
            coefSum = p2->coef;
            exp = p2->exp;

            sum = insertAtEnd(sum, coefSum, exp);
            
            p2 = p2->next;
        }
        
    }
    
    return sum;
    

}


int main(){
    struct Poly * poly1 = NULL;
    struct Poly * poly2 = NULL;
    struct Poly * sum = NULL;


    int n1;

    printf("Enter the degree of first polynomial: ");

    scanf("%d", &n1);

    printf("\n");

    
    // printf("Enter your numbers:\n");

    for(int exp = n1; exp >= 0; exp--)
    {
        int coef;

        if (exp != 0)
        {
            printf("Enter the coefficient of %d degree term: ", exp);

        } else
        {
            printf("Enter the constant term: ");
        }
        
        
        scanf("%d", &coef);
        
        if (coef != 0)
        {
            poly1 = insertAtEnd(poly1, coef, exp);

        }
    }

    printf("Given polynomial: ");
    printPolynomial(poly1);


    int n2;

    printf("Enter the degree of second polynomial: ");

    scanf("%d", &n2);

    printf("\n");

    
    // printf("Enter your numbers:\n");

    for(int exp = n2; exp >= 0; exp--)
    {
        int coef;

        if (exp != 0)
        {
            printf("Enter the coefficient of %d degree term: ", exp);

        } else
        {
            printf("Enter the constant term: ");
        }
        
        
        scanf("%d", &coef);
        
        if (coef != 0)
        {
            poly2 = insertAtEnd(poly2, coef, exp);

        }
    }

    printf("Given polynomial: ");

    printPolynomial(poly2);

    printf("Sum: ");

    sum = addPolynomial(poly1, poly2);

    printPolynomial(sum);


    
    
    

    






    return 0;

}
