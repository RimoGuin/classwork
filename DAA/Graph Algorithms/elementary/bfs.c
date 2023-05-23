/*
BFS(G,s)
1  for each vertex u in G.V - {s}
2     u.color = white
3     u.d = INF
4     u.p = NIL
5  s.color = grey
6  s.d = 0
7  s.p = NIL
8  Q = NULL
9  ENQUEUE(Q,s)
10 while Q != NULL
11    u = DEQUEUE(Q)
12    for each v in G.Adj[u]
13       if v.color == white
14          v.color = green
15          v.d = u.d + 1
16          v.p = u
17          ENQUEUE(Q,v)
18    u.color = BLACK
*/

#include<stdio.h>
#include<stdlib.h>
#define MAX_NODES 1000

typedef struct node {
	int value;
	struct node *next;
} node;

typedef struct graph {
	node *edges[MAX_NODES];
	int num_nodes;
} Graph;

typedef enum color { WHITE, GREY, BLACK } color;
void init_graph(Graph *g, int num_nodes) {
	g->num_nodes = num_nodes;
	for(int i = 0; i < num_nodes; i++)
		g->edges[i] = NULL;
}

void add_edge(Graph *g, int u, int v){
	node *new_node = (node*)malloc(sizeof(node));
	new_node->value = v;
	new_node->next = g->edges[u];
	g->edges[u] = new_node;
}

void bfs(Graph *g, int start) {
	color colors[MAX_NODES];
	int queue[MAX_NODES];
	int front = 0;
	int rear = 0;
	for(int i = 0; i < g->num_nodes; i++) {
		colors[i] = WHITE;
		queue[i] = -1;
	}
	queue[rear++] = start;
	colors[start] = GREY;
	
	node *neighbor;
	while(front != rear) {
		int node = queue[front++];
		printf("%d ", node);
		for(neighbor = g->edges[node]; neighbor != NULL; neighbor = neighbor->next) {
			if(colors[neighbor->value] == WHITE) {
				queue[rear++] = neighbor->value;
				colors[neighbor->value] = GREY;
			}
		}
		colors[node] = BLACK;
	}
}

int main() {
	Graph g;
	printf("Enter the number of nodes: ");
	int nodes, u, v, root;
	scanf("%d", &nodes);
	init_graph(&g, nodes);
	for(int i = 0; i < nodes; i++) {
		printf("Enter the source and destination edges:\n");
		scanf("%d", &u);
		scanf("%d", &v);
		add_edge(&g, u, v);
	}
	printf("Enter the bfs root node: ");
	scanf("%d", &root);
	bfs(&g, root);
	return 0;
}
