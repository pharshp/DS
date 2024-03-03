/*
implement deque using array consisting of following functions-
add rear, delete rear, add front, delete front, isfull, isempty, size
*/

#include <stdio.h>
#include <stdlib.h>
#define MAXDEQUEUE 10

struct deque
{
    int item[MAXDEQUEUE];
    int front;
    int rear;
};

int isEmpty(struct deque *dq)
{
    if (dq->front == -1 && dq->rear == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct deque *dq)
{
    if ((dq->front == dq->rear + 1) || (dq->front == 0 && dq->rear == MAXDEQUEUE - 1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void addFront(struct deque *dq, int element)
{
    if (isFull(dq))
    {
        printf("Overflow!");
        exit(1);
    }

    if (dq->front == -1 && dq->rear == -1)
    {
        dq->front = 0;
        dq->rear = 0;

        dq->item[dq->front] = element;
    }
    else
    {
        if (dq->front == 0)
        {
            dq->front = MAXDEQUEUE - 1;
        }
        else
        {
            (dq->front)--;
        }
        dq->item[dq->front] = element;
    }
}

void addRear(struct deque *dq, int element)
{
    if (isFull(dq))
    {
        printf("Overflow!");
        exit(1);
    }

    if (dq->front == -1 && dq->rear == -1)
    {
        dq->front = 0;
        dq->rear = 0;

        dq->item[dq->rear] = element;
    }
    else
    {
        dq->rear = (dq->rear + 1) % MAXDEQUEUE;
        dq->item[dq->rear] = element;
    }
}

int deleteRear(struct deque *dq)
{
    if (isEmpty(dq))
    {
        printf("Underflow!");
        exit(1);
    }

    int x = dq->item[dq->rear];

    if (dq->front == dq->rear)
    {
        dq->front = -1;
        dq->rear = -1;
    }
    else
    {
        if (dq->rear == 0)
        {
            dq->rear = MAXDEQUEUE - 1;
        }
        else
        {
            dq->rear--;
        }
    }

    return x;
}

int deleteFront(struct deque *dq)
{
    if (isEmpty(dq))
    {
        printf("Underflow!");
        exit(1);
    }

    int x = dq->item[dq->front];

    if (dq->front == dq->rear)
    {
        dq->front = -1;
        dq->rear = -1;
    }
    else
    {
        dq->front = (dq->front + 1) % MAXDEQUEUE;
    }

    return x;
}

void printdq(struct deque *dq)
{

    printf("\nDeque: ");

    if (isEmpty(dq))
    {
        printf("\n");
        return;
    }
    for (int i = dq->front; i != dq->rear; i = (i + 1) % MAXDEQUEUE)
    {

        printf("%d ", dq->item[i]);
    }
    printf("%d\n", dq->item[dq->rear]);
}

int size(struct deque *dq)
{
    if (isEmpty(dq))
    {
        return 0;
    }
    else if (dq->front <= dq->rear)
    {
        return (dq->rear - dq->front + 1);
    }
    else
    {
        return (MAXDEQUEUE - dq->front + dq->rear + 1);
    }
}

int main()
{
    struct deque dq;
    dq.front = -1;
    dq.rear = -1;

    struct deque *pdq = &dq;

    int n = 0;

    do
    {
        printf("\nWhat you want to do?\n\n");

        printf("  1) Add front\n");
        printf("  2) Add rear\n");
        printf("  3) Delete front\n");
        printf("  4) Delete rear\n");
        printf("  5) Check full\n");
        printf("  6) Check empty\n");
        printf("  7) Check size\n");
        printf("  8) Exit\n");

        printf("\nOption: ");
        scanf("%d", &n);

        switch (n)
        {
        case 1:
        {
            int e;
            printf("\nEnter element: ");
            scanf("%d", &e);
            addFront(pdq, e);
            printdq(pdq);
            break;
        }

        case 2:

        {
            printf("\nEnter element: ");
            int e;
            scanf("%d", &e);
            addRear(pdq, e);
            printdq(pdq);
        }
        break;

        case 3:
            printf("\nDeleted element: %d", deleteFront(pdq));
            printdq(pdq);
            break;

        case 4:
            printf("\nDeleted element: %d", deleteRear(pdq));
            printdq(pdq);
            break;

        case 5:
            if (isFull(pdq))
            {
                printf("\nTrue\n");
            }
            else
            {
                printf("\nFalse\n");
            }

            break;

        case 6:
            if (isEmpty(pdq))
            {
                printf("\nTrue\n");
            }
            else
            {
                printf("\nFalse\n");
            }

            break;

        case 7:
            printf("\nSize: %d\n", size(pdq));

            break;

        case 8:
            exit(0);

            break;

        default:
            printf("\nEnter a valid option!\n");
            break;
        }

    } while (n != 8);

    return 0;
}
