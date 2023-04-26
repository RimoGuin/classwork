#include "../../graph.h"

typedef struct bfs_result{
	int *p;
	int *d;
} bfs_result;

bfs_result BFS(graph *g, int s);
void PrintBFSPath(bfs_result result, int s, int v);
