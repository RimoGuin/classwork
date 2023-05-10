#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void printSolution(int** dist, int V) {
    printf("Shortest distances between every pair of vertices:\n");
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            if (dist[i][j] == INT_MAX)
                printf("INF\t");
            else
                printf("%d\t", dist[i][j]);
        }
        printf("\n");
    }
}

void floydWarshall(int** graph, int V) {
    int** dist = (int**)malloc(V * sizeof(int*));
    for (int i = 0; i < V; ++i)
        dist[i] = (int*)malloc(V * sizeof(int));

    // Initialize the distance matrix with the graph values
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j)
            dist[i][j] = graph[i][j];
    }

    // Find the shortest distances between every pair of vertices
    for (int k = 0; k < V; ++k) {
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX
                    && dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    printSolution(dist, V);

    // Free allocated memory
    for (int i = 0; i < V; ++i)
        free(dist[i]);
    free(dist);
}

int main() {
    int V;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &V);

    int** graph = (int**)malloc(V * sizeof(int*));
    for (int i = 0; i < V; ++i)
        graph[i] = (int*)malloc(V * sizeof(int));

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            scanf("%d", &graph[i][j]);
        }
    }

    floydWarshall(graph, V);

    // Free allocated memory
    for (int i = 0; i < V; ++i)
        free(graph[i]);
    free(graph);

    return 0;
}
