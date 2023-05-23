/*
 * FLOYD-WARSHALL'(W)
 *  n = W.rows
 *	D = W
 *  for k = 1 to n
 *      for i = 1 to n
 *          for j = 1 to n
 *              d[i, j] = min(d[i, j], d[i, k] + d[k, j])
 *	return D
 */

#include <stdio.h>

#define MAX_V 10 // Maximum number of vertices in the graph
#define INF 999

// Function to print the final matrices
void printSolution(int dist[][MAX_V], int pred[][MAX_V], int V) {
    printf("Shortest distances between every pair of vertices:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf("%7d", dist[i][j]);
        }
        printf("\n");
    }

    printf("\nPredecessor matrix:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (pred[i][j] == -1)
                printf("%7s", "NIL");
            else
                printf("%7d", pred[i][j]);
        }
        printf("\n");
    }
}

// Function implementing the Floyd-Warshall algorithm
void floydWarshall(int graph[][MAX_V], int V) {
    int dist[MAX_V][MAX_V];
    int pred[MAX_V][MAX_V];
    int i, j, k;

    // Initialize the distance and predecessor matrices
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            dist[i][j] = graph[i][j];
            if (graph[i][j] != INF && i != j)
                pred[i][j] = i;
            else
                pred[i][j] = -1;
        }
    }

    // Compute the shortest distance and predecessor matrices
    for (k = 0; k < V; k++) {
        for (i = 0; i < V; i++) {
            for (j = 0; j < V; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    pred[i][j] = pred[k][j];
                }
            }
        }
    }

    // Print the final matrices
    printSolution(dist, pred, V);
}

// Driver program to test the algorithm
int main() {
    int V;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &V);

    int graph[MAX_V][MAX_V];

    printf("Enter the adjacency matrix (use INF for no direct edge):\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    floydWarshall(graph, V);

    return 0;
}
