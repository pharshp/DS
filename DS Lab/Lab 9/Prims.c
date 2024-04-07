#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAXNODES 50

int main()
{
    int arr[MAXNODES][MAXNODES];
    int totalNodes;

    printf("Enter total number of nodes: ");
    scanf("%d", &totalNodes);

    if (totalNodes > MAXNODES)
    {
        printf("Maximum number of nodes can be %d", MAXNODES);
        exit(1);
    }
    else if (totalNodes < 1)
    {
        printf("Number of nodes can't be less than 1!");
        exit(1);
    }

    int choice;

    do
    {
        printf("What you want to do?\n\n");

        printf("  1) Insert edge\n");
        printf("  2) Show graph\n");
        printf("  3) Prims algorithm\n");
        printf("  4) Exit\n");

        printf("\nOption: ");

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter FROM and TO node: ");

            int fromNode, toNode;
            scanf("%d %d", &fromNode, &toNode);

            // printf("Enter TO node : ");
            // int toNode;
            // scanf("%d", &toNode);

            printf("Enter weight: ");
            int weight;
            scanf("%d", &weight);

            arr[fromNode][toNode] = weight;
            arr[toNode][fromNode] = weight;

            break;

        case 2:
            printf("    ");

            for (int c = 0; c < totalNodes; c++)
            {
                printf("%d ", c);
            }
            printf("\n\n");

            for (int i = 0; i < totalNodes; i++)
            {
                printf("%d   ", i);

                for (int j = 0; j < totalNodes; j++)
                {
                    printf("%d ", arr[i][j]);
                }
                printf("\n");
            }
            break;

        case 3:
            {
                int key[MAXNODES];
                int parent[MAXNODES];
                int mstSet[MAXNODES];

                for (int i = 0; i < totalNodes; i++)
                {
                    key[i] = INT_MAX;
                    mstSet[i] = 0;
                }

                key[0] = 0;
                parent[0] = -1;

                for (int count = 0; count < totalNodes - 1; count++)
                {
                    int minKey = INT_MAX, minIndex;

                    for (int v = 0; v < totalNodes; v++)
                        if (mstSet[v] == 0 && key[v] < minKey)
                            minKey = key[v], minIndex = v;

                    mstSet[minIndex] = 1;

                    for (int v = 0; v < totalNodes; v++)
                        if (arr[minIndex][v] && mstSet[v] == 0 && arr[minIndex][v] < key[v])
                            parent[v] = minIndex, key[v] = arr[minIndex][v];
                }

                printf("Edge \tWeight\n");
                for (int i = 1; i < totalNodes; i++)
                {
                    printf("%d - %d \t%d \n", parent[i], i, arr[i][parent[i]]);
                }

                // printf("\nGraph:\n");
                int primsResult[MAXNODES][MAXNODES];

                for (int i = 1; i < totalNodes; i++)
                {
                    // printf("%d - %d \t%d \n", parent[i], i, arr[i][parent[i]]);
                    primsResult[parent[i]][i] = arr[i][parent[i]];
                    primsResult[i][parent[i]] = arr[i][parent[i]];
                }

                printf("\nGraph:\n");

                printf("    ");

                for (int c = 0; c < totalNodes; c++)
                {
                    printf("%d ", c);
                }
                printf("\n\n");

                for (int i = 0; i < totalNodes; i++)
                {
                    printf("%d   ", i);

                    for (int j = 0; j < totalNodes; j++)
                    {
                        printf("%d ", primsResult[i][j]);
                    }
                    printf("\n");
                }
            }
            break;
        }

    } while (choice != 4);

    return 0;
}
