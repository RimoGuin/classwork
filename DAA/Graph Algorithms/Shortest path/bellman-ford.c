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

struct Edge {
    int source, destination, weight;
};

struct Graph {
    int V, E;
    struct Edge* edge;
};

struct Graph* createGraph(int V, int E) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    graph->edge = (struct Edge*)malloc(E * sizeof(struct Edge));
    return graph;
}

void printPath(int parent[], int v) {
    if (parent[v] == -1) {
        printf("%d ", v);
        return;
    }
    printPath(parent, parent[v]);
    printf("%d ", v);
}

void printDistance(int distance[], int parent[], int V, int source) {
    printf("Vertex    Distance    Path\n");
    for (int i = 0; i < V; ++i) {
        printf("%d\t\t%d\t\t", i, distance[i]);
        printPath(parent, i);
        printf("\n");
    }
}

void BellmanFord(struct Graph* graph, int source) {
    int V = graph->V;
    int E = graph->E;
    int distance[V];
    int parent[V];
    for (int i = 0; i < V; ++i) {
        distance[i] = INT_MAX;
        parent[i] = -1;
    }
    distance[source] = 0;

    for (int i = 1; i <= V - 1; ++i) {
        for (int j = 0; j < E; ++j) {
            int u = graph->edge[j].source;
            int v = graph->edge[j].destination;
            int weight = graph->edge[j].weight;
            if (distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
                parent[v] = u;
            }
        }
    }

    for (int i = 0; i < E; ++i) {
        int u = graph->edge[i].source;
        int v = graph->edge[i].destination;
        int weight = graph->edge[i].weight;
        if (distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
            printf("Graph contains negative-weight cycle\n");
            return;
        }
    }

    printDistance(distance, parent, V, source);
}

int main() {
    int V, E, source;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &V);
    printf("Enter the number of edges in the graph: ");
    scanf("%d", &E);

    struct Graph* graph = createGraph(V, E);

    printf("Enter the source vertex: ");
    scanf("%d", &source);

    printf("Enter the source, destination, and weight for each edge:\n");
    for (int i = 0; i <= E; ++i) {
        scanf("%d %d %d", &graph->edge[i].source, &graph->edge[i].destination, &graph->edge[i].weight);
    }

    BellmanFord(graph, source);

    return 0;
}
