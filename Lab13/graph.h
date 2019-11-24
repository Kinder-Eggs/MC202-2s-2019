#ifndef GRAPHH
#define GRAPHH

#include <stdio.h>
#include <stdlib.h>

typedef struct graphs {
	int* vertices;
	int* edges;
	int size;
	int nedges;
} graphs;

graphs* make_graph();
void search_graph_length(graphs*, int);



#endif