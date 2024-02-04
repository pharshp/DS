#include <stdio.h>
#include <stdlib.h>

#define NUMNODES 500

struct nodetype
{
    int into;
    int next;
} node[NUMNODES];

int n;

int avail = 0;
int start = -1;

void printList()
{
    int p = start;

    while (p != -1)
    {
        printf("%d ", node[p].into);
        p = node[p].next;
    }
    printf("\n");
}

void insertAtEnd(int val)
{
    if (start == -1)
    {
        node[0].into = val;
        node[0].next = -1;
        avail = 1;

        start = 0;
        return;
    }

    int p = start;

    while (node[p].next != -1)
    {
        p = node[p].next;
    }

    node[p].next = avail;

    int nextAvail = node[avail].next;

    node[avail].into = val;
    node[avail].next = -1;

    avail = nextAvail;
}

void insertAtStart(int val)
{
    int nextAvail = node[avail].next;

    node[avail].into = val;
    node[avail].next = start;

    start = avail;
    avail = nextAvail;
}

void insertInBetween(int index, int val)
{
    int p = start;

    for (int i = 1; i < index; i++)
    {
        p = node[p].next;
    }

    int nextAvail = node[avail].next;

    node[avail].into = val;
    node[avail].next = node[p].next;
    node[p].next = avail;
    // start = avail;
    avail = nextAvail;

    // printf("%d\n", node[p].into);
}

void freeNode(int d)
{
    node[d].next = avail;
    avail = d;
}

void deleteAtIndex(int index)
{
    int p = start;

    if (index == 0)
    {
        start = node[start].next;
        freeNode(p);
    }
    else if (index > 0 && index < n - 1)
    {
        for (int i = 0; i < index - 1; i++)
        {
            p = node[p].next;
        }

        int d = node[p].next;
        node[p].next = node[d].next;

        freeNode(d);
    }
    else if (index == n - 1)
    {
        for (int i = 0; i < index - 1; i++)
        {
            p = node[p].next;
        }
        // printf("%d\n", node[p].into);
        freeNode(node[p].next);
        node[p].next = -1;
    }
    else
    {
        printf("Invalid index!");
        exit(0);
    }

    // printf("%d\n", node[p].into);
}

int main()
{

    for (int i = 0; i < NUMNODES - 1; i++)
    {
        node[i].next = i + 1;
    }
    node[NUMNODES - 1].next = -1;

    printf("How many nodes you want to create: ");
    scanf("%d", &n);

    if (n == 0)
    {
        printf("No nodes created!");
        exit(0);
    }
    else if (n < 0)
    {
        printf("Invalid input!");
        exit(0);
    }
    else if (n > NUMNODES)
    {
        printf("Maximum no of nodes is %d!", NUMNODES);
        exit(0);
    }

    printf("Enter your values: \n");

    for (int i = 0; i < n; i++)
    {
        int val;

        scanf("%d", &val);

        insertAtEnd(val);
    }

    printf("Given List: ");
    printList();

    int n1;

    printf("\nWhat you want to do?\n");

    printf("1) Insert element\n2) Delete element\n\n");
    scanf("%d", &n1);

    if (n1 == 1)
    {
        if (avail == -1)
        {
            printf("Overflow!");
            exit(0);
        }

        int n2;
        printf("Where you want to insert element?\n");

        printf("1) At start\n2) In between (give index)\n3) At end\n");
        scanf("%d", &n2);

        if (n2 == 1)
        {
            int val;

            printf("Enter your number: ");
            scanf("%d", &val);

            insertAtStart(val);
        }
        else if (n2 == 2)
        {
            int index;

            printf("Enter the index: ");
            scanf("%d", &index);

            if (index <= 0 || index >= n)
            {
                printf("Invalid index!");
                exit(0);
            }

            int val;

            printf("Enter your number: ");
            scanf("%d", &val);

            insertInBetween(index, val);
        }
        else if (n2 == 3)
        {
            int val;

            printf("Enter your number: ");
            scanf("%d", &val);

            insertAtEnd(val);
        }
        else
        {
            printf("Invalid choice!");
            exit(0);
        }
    }
    else if (n1 == 2)
    {
        int index;

        printf("Enter the index: ");
        scanf("%d", &index);

        deleteAtIndex(index);
    }
    else
    {
        printf("Invalid choice!");
        exit(0);
    }

    printf("List: ");
    printList();

    return 0;
}
