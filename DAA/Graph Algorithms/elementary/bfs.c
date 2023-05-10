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
