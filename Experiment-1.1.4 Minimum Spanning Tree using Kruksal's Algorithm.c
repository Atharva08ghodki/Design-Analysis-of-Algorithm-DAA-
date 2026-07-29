#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void kruskalMST(int **cost, int V) {
    int parent[V];

    // Initialize disjoint sets
    for (int i = 0; i < V; i++)
        parent[i] = i;

    int edges = 0, minCost = 0, edgeNo = 0;

    while (edges < V - 1) {
        int min = 9999;
        int u = -1, v = -1;

        // Find the minimum weight edge
        for (int i = 0; i < V; i++) {
            for (int j = i + 1; j < V; j++) {
                if (cost[i][j] < min) {
                    min = cost[i][j];
                    u = i;
                    v = j;
                }
            }
        }

        // Find roots of u and v
        int ru = u;
        while (parent[ru] != ru)
            ru = parent[ru];

        int rv = v;
        while (parent[rv] != rv)
            rv = parent[rv];

        // If they belong to different sets, include the edge
        if (ru != rv) {
            parent[rv] = ru;

            printf("Edge %d:(%d, %d) cost:%d\n",
                   edgeNo++, u, v, min);

            minCost += min;
            edges++;
        }

        // Remove the processed edge
        cost[u][v] = cost[v][u] = 9999;
    }

    printf("Minimum cost= %d\n", minCost);
}

int main() {
    int V;
    printf("No of vertices: ");
    scanf("%d", &V);

    int **cost = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++)
        cost[i] = (int *)malloc(V * sizeof(int));

    printf("Adjacency matrix:\n");
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            scanf("%d", &cost[i][j]);

    kruskalMST(cost, V);

    for (int i = 0; i < V; i++)
        free(cost[i]);
    free(cost);

    return 0;
}
