#include "graph.h"
// Gabriel Costa Kinder - 234720
int main() {
	graphs* graph = make_graph(); // Cria o grafo
	
	int start;
	scanf(" %d", &start);  // Obtem valor de comeco
	search_graph_length(graph, start);  // Executa bfs

	free(graph->edges);  // Libera a memoria alocada pelo grafo
	free(graph->vertices);
	free(graph);
}