/*
1) Implement a stack using array consisting of function: empty, push, pop, stack top
2) WAP to compute a postfix expression using stack
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

    char str[100];

    printf("Enter postfix expression: ");
    scanf("%s", str);

    for (int i = 0; str[i] != '\0'; i++)
    {
        char symb = str[i];

        switch (symb)
        {
        case '+':
        {
            int b = pop(ps);
            int a = pop(ps);
            push(ps, a + b);
            break;
        }
        case '-':
        {
            int b = pop(ps);
            int a = pop(ps);
            push(ps, a - b);
            break;
        }

        case '*':
        {
            int b = pop(ps);
            int a = pop(ps);
            push(ps, a * b);
            break;
        }

        case '/':
        {
            int b = pop(ps);
            int a = pop(ps);
            push(ps, a / b);
            break;
        }

        case '$':
        {
            int b = pop(ps);
            int a = pop(ps);
            push(ps, pow(a, b));
            break;
        }

        default:
        {
            int num = symb - '0';
            push(ps, num);
        }

        break;
        }
    }

    printf("Answer: %d", s.item[s.top]);

    return 0;
}
