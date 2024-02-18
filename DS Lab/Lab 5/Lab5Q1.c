/*
1) Implement a stack using array consisting of function: empty, push, pop, stack top
2) WAP to compute a postfix expression using stack
*/

#include <stdio.h>
#include <stdlib.h>

#define STACKSIZE 100

struct stack
{
    int top;
    int item[STACKSIZE];
};

int empty(struct stack *ps)
{
    if (ps->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int pop(struct stack *ps)
{
    if (empty(ps))
    {
        printf("\nStack underflow!");
        exit(1);
    }

    int element = ps->item[ps->top];

    ps->top--;

    return element;
}

void push(struct stack *ps, int element)
{
    if (ps->top == STACKSIZE - 1)
    {
        printf("\nStack overflow!");
        exit(1);
    }

    ps->top++;
    ps->item[ps->top] = element;
}

int stacktop(struct stack *ps)
{
    if (empty(ps))
    {
        printf("\nStack underflow!");
        exit(1);
    }

    return ps->item[ps->top];
}

void printStack(struct stack *ps)
{
    printf("\nStack: ");
    for (int i = 0; i <= ps->top; i++)
    {
        printf("%d ", ps->item[i]);
    }

    printf("\n");
}

int main()
{
    struct stack s;
    s.top = -1;

    struct stack *ps = &s;

    int input = 0;

    while (input != 5)
    {
        printf("\nWhat you want to do?\n\n");

        printf("  1) Push\n");
        printf("  2) Pop\n");
        printf("  3) Empty\n");
        printf("  4) Stacktop\n");
        printf("  5) Exit\n");

        printf("\nOption: ");

        scanf("%d", &input);

        switch (input)
        {
        case 1:
            printf("\nEnter your element: ");
            int element;
            scanf("%d", &element);
            push(ps, element);
            printStack(ps);
            break;

        case 2:
            pop(ps);
            printStack(ps);
            break;

        case 3:
            if (empty(ps))
            {
                printf("True\n");
            }
            else
            {
                printf("False\n");
            }
            break;

        case 4:
            printf("\nStacktop: %d\n", stacktop(ps));
            break;

        case 5:
            exit(0);

        default:
            printf("\nEnter a valid option!\n");
            break;
        }        
    }

    return 0;
}
