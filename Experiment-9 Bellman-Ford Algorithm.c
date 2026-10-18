#include <stdio.h>
#include <stdlib.h>
#define INF 999999

struct Edge {
    int src, dest, weight;
};

int main() {
    int V, E, i, j, src;
    scanf("%d", &V);
    scanf("%d", &E);

    struct Edge edges[E];

    for (i = 0; i < E; i++) {
        scanf("%d %d %d", &edges[i].src,
              &edges[i].dest, &edges[i].weight);
    }

    scanf("%d", &src);

    int dist[V + 1];
    int parent[V + 1];

    for (i = 1; i <= V; i++) {
        dist[i] = INF;
        parent[i] = -1;
    }

    dist[src] = 0;

    for (i = 1; i < V; i++) {
        int updated = 0;

        for (j = 0; j < E; j++) {
            int u = edges[j].src;
            int v = edges[j].dest;
            int w = edges[j].weight;

            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                updated = 1;
            }
        }

        if (!updated)
            break;
    }

    for (i = 0; i < E; i++) {
        int u = edges[i].src;
        int v = edges[i].dest;
        int w = edges[i].weight;

        if (dist[u] != INF && dist[u] + w < dist[v]) {
            printf("Negative cycle detected\n");
            return 0;
        }
    }

    for (i = 1; i <= V; i++) {
        if (i == src)
            continue;

        if (dist[i] == INF) {
            printf("%d INF None\n", i);
        } else {
            int path[V + 1];
            int count = 0;
            int current = i;

            while (current != -1) {
                path[count++] = current;
                current = parent[current];
            }

            printf("%d %d ", i, dist[i]);

            for (j = count - 1; j >= 0; j--) {
                printf("%d", path[j]);

                if (j > 0)
                    printf("->");
            }

            printf("\n");
        }
    }

    return 0;
}
