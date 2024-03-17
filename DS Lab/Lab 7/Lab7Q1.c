/*
Implement priority queue using array as discussed in the class
*/

#include <stdio.h>
#include <stdlib.h>

#define MAXPQ 100

struct pqueue
{
    int item[MAXPQ];
    int rear;
};

int isFull(struct pqueue *pq)
{
    if (pq->rear == MAXPQ - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void pqInsert(struct pqueue *pq, int element)
{
    if (isFull(pq))
    {
        printf("Overflow!");
        exit(1);
    }

    int i = 0;

    while (i <= pq->rear && element > pq->item[i])
        i++;

    for (int j = pq->rear; j >= i; j--)
    {
        pq->item[j + 1] = pq->item[j];
    }

    pq->item[i] = element;
    (pq->rear)++;
}

int isEmpty(struct pqueue *pq)
{
    if (pq->rear == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int pqmindelete(struct pqueue *pq)
{
    if (isEmpty(pq))
    {
        printf("Underflow!");
        exit(1);
    }

    int min = pq->item[0];

    for (int i = 0; i < pq->rear; i++)
    {
        pq->item[i] = pq->item[i + 1];
    }

    (pq->rear)--;

    return min;
}

int pqmaxdelete(struct pqueue *pq)
{
    if (isEmpty(pq))
    {
        printf("Underflow!");
        exit(1);
    }
    int max = pq->item[pq->rear];
    (pq->rear)--;

    return max;
}

void printQueue(struct pqueue *pq)
{
    printf("\nQueue: ");

    for (int i = 0; i <= pq->rear; i++)
    {
        printf("%d ", pq->item[i]);
    }

    printf("\n");
}

int main()
{
    struct pqueue pq;
    pq.rear = -1;

    struct pqueue *ppq = &pq;

    int n;
    printf("How many elements you want to add? ");
    scanf("%d", &n);
    printf("\n");

    if (n >= 0 && n <= MAXPQ)
    {
        for (int i = 0; i < n; i++)
        {
            int e;
            printf("  Enter your element: ");
            scanf("%d", &e);

            pqInsert(ppq, e);
        }
    }
    else if (n > MAXPQ)
    {
        printf("Maximum size is %d!", MAXPQ);
        exit(1);
    }

    else
    {
        printf("Enter a valid number!");
        exit(1);
    }
    printQueue(ppq);

    int choice;

    do
    {
        printf("\nWhat you want to do?\n\n");

        printf("  1) Insert\n");
        printf("  2) Delete Minimum\n");
        printf("  3) Delete Maximum\n");
        printf("  4) Check Empty\n");
        printf("  5) Check Full\n");
        printf("  6) Exit\n");

        printf("\nOption: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter your element: ");
            int e;
            scanf("%d", &e);
            pqInsert(ppq, e);

            printQueue(ppq);
            break;

        case 2:
        {
            int e = pqmindelete(ppq);
            printf("\nDeleted element: %d\n", e);
            printQueue(ppq);
            break;
        }

        case 3:
        {
            int e = pqmaxdelete(ppq);
            printf("\nDeleted element: %d\n", e);
            printQueue(ppq);
            break;
        }

        case 4:
            if (isEmpty(ppq))
            {
                printf("\nTrue\n");
            }
            else
            {
                printf("\nFalse\n");
            }

            break;

        case 5:
            if (isFull(ppq))
            {
                printf("\nTrue\n");
            }
            else
            {
                printf("\nFalse\n");
            }

            break;

        default:
            break;
        }

    } while (choice != 6);

    return 0;
}
