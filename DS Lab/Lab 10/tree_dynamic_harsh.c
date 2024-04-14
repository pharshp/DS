
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct nodetype
{
    int info;
    struct nodetype *left;
    struct nodetype *right;
    struct nodetype *father;
};

typedef struct nodetype *NODEPTR;

NODEPTR maketree(int info)
{
    NODEPTR newNode = (NODEPTR)malloc(sizeof(struct nodetype));

    newNode->info = info;

    newNode->left = NULL;
    newNode->right = NULL;
    newNode->father = NULL;

    return newNode;
}

// void insertNode(int nodeIndex, int info)
// {
//     if (node[nodeIndex].used)
//     {
//         printf("\nInvalid insertion!\n");
//     }
//     else
//     {
//         node[nodeIndex].info = info;
//         node[nodeIndex].used = true;
//     }
// }

void preOrderTraversal(NODEPTR root)
{
    if (root != NULL)
    {
        printf("%d ", root->info);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

void postOrderTraversal(NODEPTR root)
{
    if (root != NULL)
    {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%d ", root->info);
    }
}

void inOrderTraversal(NODEPTR root)
{
    if (root != NULL)
    {
        inOrderTraversal(root->left);
        printf("%d ", root->info);
        inOrderTraversal(root->right);
    }
}

int main()
{
    // for (int i = 0; i < NUMNODES; i++)
    // {
    //     node[i].used = false;
    // }
    NODEPTR root = NULL;

    int totalNodes;

    printf("How many nodes you want to create: ");
    scanf("%d", &totalNodes);

    int nodeCount = 0;
    NODEPTR currentNode = NULL;

    while (nodeCount != totalNodes)
    {
        if (nodeCount == 0)
        {
            printf("Enter info: ");
            int info;

            scanf("%d", &info);

            root = maketree(info);
            currentNode = root;
            nodeCount++;
        }

        if (currentNode != NULL)
        {
            printf("\nCurrent node info: %d", currentNode->info);
        }

        printf("\nWhat you want to do?\n");
        // printf("\n  1) Enter info");
        printf("\n  1) Create left node");
        printf("\n  2) Create right node");
        printf("\n  3) Goto left node");
        printf("\n  4) Goto right node");
        printf("\n  5) Goto root node");
        printf("\n  6) Goto parent node");

        int choice;
        printf("\n\nOption: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            printf("Enter info: ");
            int info;

            scanf("%d", &info);

            NODEPTR newNode = maketree(info);
            currentNode->left = newNode;
            newNode->father = currentNode;
            nodeCount++;
            break;
        }

        case 2:
        {
            printf("Enter info: ");
            int info;

            scanf("%d", &info);

            NODEPTR newNode = maketree(info);
            currentNode->right = newNode;
            newNode->father = currentNode;
            nodeCount++;
            break;
        }

        case 3:
            if (currentNode->left != NULL)
            {
                currentNode = currentNode->left;
            }
            else
            {
                printf("\nNo node exist!\n");
            }

            break;

        case 4:
            if (currentNode->right != NULL)
            {
                currentNode = currentNode->right;
            }
            else
            {
                printf("\nNo node exist!\n");
            }
            break;

        case 5:
            currentNode = root;
            break;

        case 6:
            currentNode = currentNode->father;
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
    preOrderTraversal(root);

    printf("\nPost order traversal: ");
    postOrderTraversal(root);

    printf("\nIn order traversal: ");
    inOrderTraversal(root);

    return 0;
}