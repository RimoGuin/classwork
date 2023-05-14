#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define MAX_VERTICES 10
#define true 1
#define false 0

int isSafe(int v, int graph[MAX_VERTICES][MAX_VERTICES], int color[], int c, int numVertices)  {
	for(int i = 0; i < numVertices; i++) {
		if(graph[v][i] && c == color[i])
			return false;
	}
	return true;
}

int graphColoringUtil(int graph[MAX_VERTICES][MAX_VERTICES], int m, int color[], int v, int numVertices) {
	if(v == numVertices)
		return true;

	for(int c = 1; c <= m; c++) {
		if(isSafe(v, graph, color, c, numVertices)){
			color[v] = c;

			if(graphColoringUtil(graph, m, color, v + 1, numVertices))
				return true;

			color[v] = 0;
		}
	}
	return false;
}

void graphColoring(int graph[MAX_VERTICES][MAX_VERTICES], int m, int numVertices) {
	int color[MAX_VERTICES];
	for(int i = 0; i < numVertices; i++)
		color[i] = 0;

	if(!graphColoringUtil(graph, m, color, 0, numVertices)){
		printf("No solution exists.\n");
		return;
	}

	printf("The coloring of the graph using at most %d colors:\n", m);
	for(int i = 0; i < numVertices; i++)
		printf("Vertex %d: Color %d\n", i, color[i]);
}

void getGraph(int graph[MAX_VERTICES][MAX_VERTICES], int numVertices){
	printf("Enter the adjacency matrix representation of the graph:\n");
	for(int i = 0; i < numVertices; i++) {
		for(int j = 0; j < numVertices; j++)
			scanf("%d", &graph[i][j]);
	}
}

int main(){
	int numVertices, m;
	printf("Enter the number of vertices in the graph: ");
	scanf("%d", &numVertices);

	if(numVertices <= 0 || numVertices > MAX_VERTICES) {
		printf("Invalid number of vertices.\n");
		return 0;
	}
	int graph[MAX_VERTICES][MAX_VERTICES];
	getGraph(graph, numVertices);

	printf("Enter the maximum number of colors: ");
	scanf("%d", &m);

	if(m <= 0){
		printf("Invalid number of colors. \n");
		return 0;
	}

	graphColoring(graph, m, numVertices);
	return 0;
}
