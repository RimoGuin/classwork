/*MST-PRIM(G,w,r)
 * 1   for each u ∈ G.V   //initialization
 * 2      u.key = ∞
 * 3      u.π = NIL
 * 4   r.key = 0
 * 5   Q = G.V          //end initialization
 * 6   while Q ≠ ∅
 * 7      u = EXTRACT-MIN(Q)
 * 8      for each v ∈ G.Adj[u]
 * 9         if v ∈ Q and w(u,v) < v.key
 * 10           v.π = u
 * 11           v.key = w(u,v)*/


#include <stdio.h>
#define MAX_NODES 100

int graph[MAX_NODES][MAX_NODES];
int visited[MAX_NODES];
int parent[MAX_NODES];
int key[MAX_NODES];

int findMinKey(int nodes) {
    int minKey = -1;
    int minVal = __INT_MAX__;
    for (int i = 0; i < nodes; i++) {
        if (!visited[i] && key[i] < minVal) {
            minVal = key[i];
            minKey = i;
        }
    }
    return minKey;
}

void prim(int nodes) {
    for (int i = 0; i < nodes; i++) {
        visited[i] = 0;
        key[i] = __INT_MAX__;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < nodes - 1; count++) {
        int u = findMinKey(nodes);
        visited[u] = 1;

        for (int v = 0; v < nodes; v++) {
            if (graph[u][v] && !visited[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
}

int main() {
    int nodes;

    printf("Enter the number of nodes: ");
    scanf("%d", &nodes);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < nodes; i++) {
        for (int j = 0; j < nodes; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    prim(nodes);

    printf("Minimum Spanning Tree Edges:\n");
    for (int i = 1; i < nodes; i++) {
        printf("%d - %d\n", parent[i], i);
    }

    return 0;
}
