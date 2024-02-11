#include <stdio.h>
#include <stdlib.h>

#define MAXQUEUE 100

struct Queue
{
    int item[MAXQUEUE];
    int front, rear;
} q;

void insert(int item)
{
    q.rear++;
    q.item[q.rear] = item;
}

void printQueue()
{
    printf("\nQueue: ");

    for (int i = q.front; i <= q.rear; i++)
    {
        printf("%d ", q.item[i]);
    }

    printf("\n");
}

void delete()
{
    q.front++;
}

int main()
{
    q.front = 0;
    q.rear = -1;
    int size;

    printf("How many values you want to add: ");
    scanf("%d", &size);

    if (size < 0)
    {
        printf("\nInvalid input!");
        exit(0);
    }
    else if (size > MAXQUEUE)
    {
        printf("\nMaximum size is %d!", MAXQUEUE);
        exit(0);
    }

    if (size != 0)
    {
        printf("\nEnter your values:\n");
    }

    for (int i = 0; i < size; i++)
    {
        int item;
        scanf("%d", &item);
        insert(item);
    }

    printQueue();

    printf("\nWhat you want to do?\n");

    printf("1) Insert\n2) Delete\n");

    int n;

    scanf("%d", &n);

    switch (n)
    {
    case 1:
        if (size == MAXQUEUE)
        {
            printf("\nQueue overflow!");
            exit(0);
        }

        int item;
        printf("Enter the value: ");
        scanf("%d", &item);
        insert(item);
        break;

    case 2:
        if (size == 0)
        {
            printf("\nQueue underflow!");
            exit(0);
        }

        delete ();
        break;

    default:
        printf("\nInvalid choice!");
        exit(0);
        break;
    }

    printQueue(q);

    return 0;
}
