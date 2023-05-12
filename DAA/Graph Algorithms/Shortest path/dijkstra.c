/*
	DIJKSTRA(G, w, s)
	1. INITIALIZE-SINGLE-SOURCE(G, s)
	2. S = phi
	3. Q = G.V
	4. while Q!=phi:
	5.		u = EXTRACT-MIN(Q)
	6.		S = S U {u}
	7.		for each vertex v (belongs to) G.Adj[u]:
	8.			RELAX(u, v, w)
*/

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define MAX_NODES 100
#define INF INT_MAX

typedef struct {
	int cost;
	int parent;
	int visited;
} Node;

void dijkstra(int graph[MAX_NODES][MAX_NODES], int startNode, int numNodes){
	Node nodes[MAX_NODES];

	for(int i = 0; i < numNodes; i++){
		nodes[i].cost = INF;
		nodes[i].parent = -1;
		nodes[i].visited = 0;
	}
	nodes[startNode].cost = 0;

	for(int count = 0; count < numNodes - 1; count++) {
		int minCost = INF;
		int minNode = -1;

		for(int i = 0; i < numNodes; i++) {
			if(!nodes[i].visited && nodes[i].cost < minCost){
				minCost = nodes[i].cost;
				minNode = i;
			}
		}

		if(minNode == -1)
			break;

		nodes[minNode].visited = 1;

		for(int i = 0; i < numNodes; i++) {
			if(!nodes[i].visited && graph[minNode][i] && nodes[minNode].cost != INF &&
				nodes[minNode].cost + graph[minNode][i] < nodes[i].cost) {
				nodes[i].cost = nodes[minNode].cost + graph[minNode][i];
				nodes[i].parent = minNode;
			}
		}
	}

	for(int i = 0; i < numNodes; i++){
		printf("Node %d - Cost: %d - Path: ", i, nodes[i].cost);

		int j = i;
		while(j != startNode) {
			printf("%d <- ", j);
			j = nodes[j].parent;
		}

		printf("%d\n", startNode);
	}
}

int main() {
	int numNodes, startNode;
	int graph[MAX_NODES][MAX_NODES];
	
	printf("Enter the number of nodes: ");
	scanf("%d", &numNodes);

	printf("Enter the adjacency matrix (cost of edges):\n");
	for(int i = 0; i < numNodes; i++) {
		for(int  j = 0; j < numNodes; j++)
			scanf("%d", &graph[i][j]);
	}

	printf("Enter the starting node: ");
	scanf("%d", &startNode);

	dijkstra(graph, startNode, numNodes);
	return 0;
}
