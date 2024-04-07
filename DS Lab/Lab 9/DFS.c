#include <stdio.h>
#include <stdlib.h>

struct nodetype
{
    struct nodetype *nextnode;
    int info;
    struct arctype *arcptr;
};

struct arctype
{
    struct nodetype *ndptr;
    struct arctype *nextarc;
};

struct nodetype *createNode(int n)
{
    struct nodetype *newNode = malloc(sizeof(struct nodetype));
    newNode->info = n;
    newNode->nextnode = NULL;
    newNode->arcptr = NULL;
    return newNode;
}

void createEdge(struct nodetype *head, int from, int to)
{

    struct arctype *newEdge = malloc(sizeof(struct arctype));
    newEdge->nextarc = NULL;

    struct nodetype *fromNode;
    struct nodetype *toNode;

    struct nodetype *tempNode = head;

    while (tempNode->info != from)
    {
        tempNode = tempNode->nextnode;
    }

    fromNode = tempNode;

    tempNode = head;

    while (tempNode->info != to)
    {
        tempNode = tempNode->nextnode;
    }

    toNode = tempNode;

    newEdge->ndptr = toNode;

    struct arctype *tempEdge;

    tempEdge = fromNode->arcptr;

    if (tempEdge == NULL)
    {
        fromNode->arcptr = newEdge;
    }
    else
    {
        while (tempEdge->nextarc != NULL)
        {
            if (tempEdge->ndptr->info == to)
            {
                printf("\nEdge already exists!\n");
                return;
            }

            tempEdge = tempEdge->nextarc;
        }
        if (tempEdge->ndptr->info == to)
        {
            printf("\nEdge already exists!\n");
            return;
        }

        tempEdge->nextarc = newEdge;
    }
}

void printGraph(struct nodetype *head)
{
    struct nodetype *tempNode = head;

    while (tempNode != NULL)
    {
        printf("\n  [%d] ", tempNode->info);
        struct arctype *tempEdge = tempNode->arcptr;

        while (tempEdge != NULL)
        {
            printf("-> %d ", tempEdge->ndptr->info);

            tempEdge = tempEdge->nextarc;
        }

        tempNode = tempNode->nextnode;
    }
    printf("\n");
}

void DFSUtil(struct nodetype *node, int visited[])
{
    visited[node->info] = 1;
    printf("%d ", node->info);

    struct arctype *tempEdge = node->arcptr;
    while (tempEdge != NULL)
    {
        if (!visited[tempEdge->ndptr->info])
        {
            DFSUtil(tempEdge->ndptr, visited);
        }
        tempEdge = tempEdge->nextarc;
    }
}

void DFS(struct nodetype *head)
{
    int *visited = (int *)calloc(sizeof(int), 100); // Assuming max number of nodes is 100

    printf("\nDepth First Traversal: ");
    struct nodetype *tempNode = head;

    while (tempNode != NULL)
    {
        if (!visited[tempNode->info])
        {
            DFSUtil(tempNode, visited);
        }
        tempNode = tempNode->nextnode;
    }

    printf("\n");

    free(visited);
}

int main()
{
    printf("How many nodes you want to create: ");
    int totalNodes;
    scanf("%d", &totalNodes);

    if (totalNodes < 0)
    {
        printf("Number of nodes can't be negative!");
        exit(1);
    }
    else if (totalNodes == 0)
    {
        printf("Number of nodes can't be zero!");
        exit(1);
    }

    struct nodetype *head;

    for (int i = 1; i <= totalNodes; i++)
    {
        if (i == 1)
        {
            head = createNode(i);
        }
        else
        {
            struct nodetype *newNode = createNode(i);

            struct nodetype *temp = head;

            while (temp->nextnode != NULL)
            {
                temp = temp->nextnode;
            }
            temp->nextnode = newNode;
        }
    }

    while (1)
    {
        int choice;

        printf("\nWhat you want to do?\n");
        printf("\n  1) Add an edge");
        printf("\n  2) Print graph");
        printf("\n  3) DFS");
        printf("\n  4) Exit");

        printf("\n\nChoice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter FROM and TO node: ");
            int from, to;
            scanf("%d %d", &from, &to);
            if ((from > 0 && to > 0) && (from <= totalNodes && to <= totalNodes))
            {
                createEdge(head, from, to);
            }
            else
            {
                printf("\nInvalid Node!\n");
            }

            break;

        case 2:
            printGraph(head);

            break;

        case 3:
            // printf("\nEnter starting node: ");
            // int s;
            // scanf("%d", &s);

            // struct nodetype startNode;


            
            DFS(head);
            break;

        case 4:
            exit(0);

            break;

        default:
            printf("Invalid choice!");

            break;
        }
    }

    return 0;
}
