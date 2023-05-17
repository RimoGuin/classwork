#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 100
#define MAX_EDGES 100

struct Edge {
    int source, destination, weight;
};

struct Graph {
    int num_vertices, num_edges;
    struct Edge edges[MAX_EDGES];
};

void bellmanFord(struct Graph graph, int source) {
    int dist[MAX_VERTICES];
    int i, j;

    // Initialize distances to all vertices as infinity except the source vertex
    for (i = 0; i < graph.num_vertices; i++) {
        dist[i] = INT_MAX;
    }
    dist[source] = 0;

    // Relax edges repeatedly V-1 times
    for (i = 1; i <= graph.num_vertices - 1; i++) {
        for (j = 0; j < graph.num_edges; j++) {
            int u = graph.edges[j].source;
            int v = graph.edges[j].destination;
            int weight = graph.edges[j].weight;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }

    // Check for negative-weight cycles
    for (i = 0; i < graph.num_edges; i++) {
        int u = graph.edges[i].source;
        int v = graph.edges[i].destination;
        int weight = graph.edges[i].weight;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            printf("Graph contains negative-weight cycle\n");
            return;
        }
    }

    // Print distances to all vertices
    printf("Shortest path distances from source vertex %d:\n", source);
    for (i = 0; i < graph.num_vertices; i++) {
        printf("Vertex %d: %d\n", i, dist[i]);
    }
}

int main() {
    struct Graph graph;
    int i;

    // Read number of vertices and edges from user input
    printf("Enter number of vertices: ");
    scanf("%d", &graph.num_vertices);
    printf("Enter number of edges: ");
    scanf("%d", &graph.num_edges);

    // Read edge information from user input
    printf("Enter edge information as source, destination, weight:\n");
    for (i = 0; i < graph.num_edges; i++) {
        scanf("%d %d %d", &graph.edges[i].source, &graph.edges[i].destination, &graph.edges[i].weight);
    }

    // Run Bellman-Ford algorithm from source vertex 0
    bellmanFord(graph, 0);

    return 0;
}