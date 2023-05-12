/*
BELLMAN-FORD(G, w, s)
1 INITIALIZE-SINGLE-SOURCE(G, s)
2  for i=1 to |G.V| - 1
3   for each edge (u, v) (belongs to) G.E
4      RELAX(u, v, w)
5 for each edge (u, v) (belongs to) G.E
6    if v.d > u.d + w(u, v)
7      return FALSE
8 return TRUE
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void printDistance(int distance[], int V) {
    printf("Vertex    Distance from Source\n");
    for (int i = 0; i < V; ++i)
        printf("%d\t\t%d\n", i, distance[i]);
}

void BellmanFord(int graph[][100], int V, int source) {
    int distance[V];

    // Initialize distances from the source to all other vertices as infinite
    for (int i = 0; i < V; ++i)
        distance[i] = INT_MAX;
    distance[source] = 0;

    // Relax all edges |V| - 1 times
    for (int i = 1; i <= V - 1; ++i) {
        for (int u = 0; u < V; ++u) {
            for (int v = 0; v < V; ++v) {
                int weight = graph[u][v];
                if (distance[u] != INT_MAX && distance[u] + weight < distance[v])
                    distance[v] = distance[u] + weight;
            }
        }
    }

    // Check for negative-weight cycles
    for (int u = 0; u < V; ++u) {
        for (int v = 0; v < V; ++v) {
            int weight = graph[u][v];
            if (distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
                printf("Graph contains negative-weight cycle\n");
                return;
            }
        }
    }

    printDistance(distance, V);
}

int main() {
    int V, source;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &V);

    int graph[100][100];

    printf("Enter the source vertex: ");
    scanf("%d", &source);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            scanf("%d", &graph[i][j]);
        }
    }

    BellmanFord(graph, V, source);

    return 0;
}
