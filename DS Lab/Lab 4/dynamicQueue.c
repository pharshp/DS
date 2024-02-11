#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int item;
    struct Node *next;
};

struct Queue
{
    struct Node *front;
    struct Node *rear;
};

void insert(struct Queue *q, int item)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));

    temp->item = item;
    temp->next = NULL;

    if (q->front == NULL)
    {
        q->front = temp;
        q->rear = temp;
    }
    else
    {
        q->rear->next = temp;
        q->rear = temp;
    }
}

void printQueue(struct Queue *q)
{
    struct Node *temp = q->front;

    printf("\nQueue: ");
    while (temp != NULL)
    {
        printf("%d ", temp->item);
        temp = temp->next;
    }
    printf("\n");
}

void delete(struct Queue *q)
{
    struct Node *temp = q->front;

    if (temp == NULL)
    {
        printf("\nQueue underflow!");
        exit(0);
    }
    
    q->front = q->front->next;
    free(temp);
}

int main()
{
    struct Queue *q = (struct Queue *) malloc(sizeof(struct Queue));

    q->front = NULL;
    q->rear = NULL;

    int size;

    printf("How many values you want to add: ");
    scanf("%d", &size);

    if (size < 0)
    {
        printf("\nInvalid input!");
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
        insert(q, item);
    }

    printQueue(q);

    printf("\nWhat you want to do?\n");

    printf("1) Insert\n2) Delete\n");

    int n;

    scanf("%d", &n);

    switch (n)
    {
    case 1:
    {
        int item;
        printf("Enter the value: ");
        scanf("%d", &item);
        insert(q, item);
        break;
    }

    case 2:
        delete(q);
        break;

    default:
        printf("\nInvalid choice!");
        exit(0);
        break;
    }

    printQueue(q);

    return 0;
}
