#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define NUMNODES 500

struct nodetype
{
    int info;
    bool used;
};

struct nodetype node[NUMNODES];

// void maketree(int x)
// {
//     node[0].info = x;
//     node[0].used = true;

//     for (int i = 1; i < NUMNODES; i++)
//     {
//         node[i].used = false;
//     }
// }

void insertNode(int nodeIndex, int info)
{
    if (node[nodeIndex].used)
    {
        printf("\nInvalid insertion!\n");
    }
    else
    {
        node[nodeIndex].info = info;
        node[nodeIndex].used = true;
    }
}

void preOrderTraversal(int nodeIndex)
{
    if (node[nodeIndex].used)
    {
        printf("%d ", node[nodeIndex].info);
        preOrderTraversal(2 * nodeIndex + 1);
        preOrderTraversal(2 * nodeIndex + 2);
    }
}

void postOrderTraversal(int nodeIndex)
{
    if (node[nodeIndex].used)
    {
        postOrderTraversal(2 * nodeIndex + 1);
        postOrderTraversal(2 * nodeIndex + 2);
        printf("%d ", node[nodeIndex].info);
    }
}

void inOrderTraversal(int nodeIndex)
{
    if (node[nodeIndex].used)
    {
        inOrderTraversal(2 * nodeIndex + 1);
        printf("%d ", node[nodeIndex].info);
        inOrderTraversal(2 * nodeIndex + 2);
    }
}

int main()
{
    for (int i = 0; i < NUMNODES; i++)
    {
        node[i].used = false;
    }

    int totalNodes;

    printf("How many nodes you want to create: ");
    scanf("%d", &totalNodes);

    int nodeCount = 0;
    int currentNode = 0;

    while (nodeCount != totalNodes)
    {
        if (node[currentNode].used)
        {
            printf("\nCurrent node info: %d", node[currentNode].info);
        }

        printf("\nWhat you want to do?\n");
        printf("\n  1) Enter info");
        printf("\n  2) Goto left node");
        printf("\n  3) Goto right node");
        printf("\n  4) Goto root node");
        printf("\n  5) Goto parent node");

        int choice;
        printf("\n\nOption: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter info: ");
            int info;

            scanf("%d", &info);

            insertNode(currentNode, info);
            nodeCount++;
            break;

        case 2:
            currentNode = 2 * currentNode + 1;
            break;

        case 3:
            currentNode = 2 * currentNode + 2;

            break;

        case 4:
            currentNode = 0;
            break;

        case 5:
            currentNode = (currentNode - 1) / 2;
            break;

        default:
            printf("\nInvalid option!");
            // exit(1);
            break;
        }

        // int info;

        // if (nodeCount == 0)
        // {
        //     printf("Enter the root node: ");
        //     scanf("%d", &info);

        //     insertNode(currentNode, info);
        //     nodeCount++;
        // }
    }

    printf("\nPre order traversal: ");
    preOrderTraversal(0);

    printf("\nPost order traversal: ");
    postOrderTraversal(0);

    printf("\nIn order traversal: ");
    inOrderTraversal(0);


    return 0;
}