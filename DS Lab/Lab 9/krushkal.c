#include <stdio.h>
#include <stdlib.h>

#define MAXNODES 50
#define MAXEDGES ((MAXNODES * (MAXNODES - 1)) / 2)


struct Edge {
    int src, dest, weight;
};

struct Subset {
    int parent;
    int rank;
};

int arr[MAXNODES][MAXNODES]; 
int totalNodes;
struct Edge edges[MAXEDGES];


void kruskal();
int find(struct Subset subsets[], int i);
void unionSets(struct Subset subsets[], int x, int y);
int comparator(const void* a, const void* b);

int main() {
    printf("Enter total number of nodes: ");
    scanf("%d", &totalNodes);

    if (totalNodes > MAXNODES) {
        printf("Maximum number of nodes can be %d", MAXNODES);
        exit(1);
    } else if (totalNodes < 1) {
        printf("Number of nodes can't be less than 1!");
        exit(1);
    }

    int choice;
    do {
        printf("What you want to do?\n\n");
        printf("  1) Insert edge\n");
        printf("  2) Show graph\n");
        printf("  3) Kruskal's algorithm\n");
        printf("  4) Exit\n");
        printf("\nOption: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter FROM and TO node: ");
                int fromNode, toNode, weight;
                scanf("%d %d", &fromNode, &toNode);
                printf("Enter weight: ");
                scanf("%d", &weight);
                arr[fromNode][toNode] = weight;
                arr[toNode][fromNode] = weight;
                break;

            case 2:
                printf("    ");
                for (int c = 0; c < totalNodes; c++) {
                    printf("%d ", c);
                }
                printf("\n\n");
                for (int i = 0; i < totalNodes; i++) {
                    printf("%d   ", i);
                    for (int j = 0; j < totalNodes; j++) {
                        printf("%d ", arr[i][j]);
                    }
                    printf("\n");
                }
                break;

            case 3:
                kruskal();
                break;
        }
    } while (choice != 4);

    return 0;
}


void kruskal() {
    int edgeCount = 0;
    
    for (int i = 0; i < totalNodes; i++) {
        for (int j = i + 1; j < totalNodes; j++) {
            if (arr[i][j] != 0) {
                edges[edgeCount].src = i;
                edges[edgeCount].dest = j;
                edges[edgeCount].weight = arr[i][j];
                edgeCount++;
            }
        }
    }

    
    qsort(edges, edgeCount, sizeof(struct Edge), comparator);

    
    struct Subset* subsets = malloc(totalNodes * sizeof(struct Subset));

    
    for (int i = 0; i < totalNodes; i++) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    int minCost = 0; 

    printf("Edges of Minimum Spanning Tree:\n");
    for (int i = 0; i < edgeCount; i++) {
        int srcParent = find(subsets, edges[i].src);
        int destParent = find(subsets, edges[i].dest);

        
        if (srcParent != destParent) {
            printf("%d -- %d == %d\n", edges[i].src, edges[i].dest, edges[i].weight);
            minCost += edges[i].weight;
            unionSets(subsets, srcParent, destParent);
        }
    }

    printf("Minimum Cost: %d\n", minCost);

    free(subsets);
}


int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}


void unionSets(struct Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

int comparator(const void* a, const void* b) {
    struct Edge* edge1 = (struct Edge*)a;
    struct Edge* edge2 = (struct Edge*)b;
    return edge1->weight - edge2->weight;
}
