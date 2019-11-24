#include "graph.h"

graphs* make_graph() {  // constroi o grafo
	graphs* graph = malloc(sizeof(graphs));  // Aloca a memoria para o ponteiro pra grafo
	scanf(" %d", &(graph->size));  // Obtem o numero de vertices
	graph->vertices = malloc(graph->size * sizeof(int));  // Aloca o vetor de vertices
	int** aux = malloc(graph->size * sizeof(int*));  // Aloca duas variaveis auxiliares para auxiliar na montagem do vetor de adjacencias
	int* aux_size = malloc(graph->size * sizeof(int));
	for (int i = 0; i < graph->size; i++) {
		aux[i] = malloc((graph->size - 1) * sizeof(int));
		aux_size[i] = 0;
	}
	int aux2, aux3;
	scanf(" %d", &aux2);  // obtem o primeiro valor
	while (aux2 != 0) {  // enquanto nao encontra "0,0"
		getchar();  // consome a virgula
		scanf(" %d", &aux3);  // obtem o segundo valor
		aux[aux2-1][aux_size[aux2-1]] = aux3;  // monta o vetor auxiliar com as adjacencias
		aux[aux3-1][aux_size[aux3-1]] = aux2;
		aux_size[aux2-1]++;
		aux_size[aux3-1]++;
		scanf(" %d", &aux2); // obtem o primeiro valor
	}
	getchar();  // consome o ",0"
	getchar();
	graph->nedges = 0;
	for (int i = 0; i < graph->size; i++) {
		graph->nedges += aux_size[i];  // calcula numero de arestas
	}
	graph->edges = malloc(graph->nedges * sizeof(int));  // aloca vetor de arestas para o numero de arestas existentes
	int aux4 = 0;
	for (int i = 0; i < graph->size; i++) {
		if(aux_size[i] == 0) {  // marca todos os vertices sem aresta com "-1"
			graph->vertices[i] = -1;
			continue;
		}
		graph->vertices[i] = aux4;
		for (int j = 0; j < aux_size[i]; j++) {
			graph->edges[graph->vertices[i] + j] = aux[i][j];
			aux4++;
		}
	}
	// libera a memoria utilizada e retorna o ponteiro para o grafo
	for (int i = 0; i < graph->size; i++) free(aux[i]);
	free(aux);
	free(aux_size);
	return graph;
}


void add_to_queue(int** queue, int value) {  // adiciona value na fila
	int i;
	for (i = 0; (*queue)[i] != -1; i++);
	(*queue)[i] = value;
}


int not_in_queue(int size, int** queue, int value) {  // verifica se value existe na fila
	for (int i = 0; i < size; i++) if ((*queue)[i] == value) return 0;
	return 1;
}


void visit_node(graphs* graph, int** queue, int** distances, int** previousn, int node) {  // visita o vertice e adiciona os vertices adjacentes na fila
	if (graph->vertices[node] < 0) return;  // se nao possui arestas retorna
	printf("%d %d\n",node + 1, (*distances)[node]);  // printa a distancia ate o no sendo visitado
	int n = 1;
	while (graph->vertices[node+n] == -1) n++;
	if(node+n >= graph->size){
			for (int i = graph->vertices[node]; i < graph->nedges; i++) {
				if (not_in_queue(2*graph->nedges, queue, graph->edges[i] - 1)) {
					if ((*distances)[graph->edges[i]-1] == -1) {
						(*previousn)[graph->edges[i]-1] = node;  // caso ainda nao esteja na fila e nao tenha sido visitado ainda (dist == -1) adiciona a fila e verifica qual o no anterior
						add_to_queue(queue, graph->edges[i] - 1);
					}
				}
			}
		return;
	}
	for (int i = graph->vertices[node]; i < graph->vertices[node+n]; i++) {
		if(not_in_queue(2*graph->nedges, queue, graph->edges[i] - 1)) {
			if((*distances)[graph->edges[i]-1] == -1) {
				(*previousn)[graph->edges[i]-1] = node;  // analogo ao ultimo caso
				add_to_queue(queue, graph->edges[i] - 1);
			}
		}
	}
}


int queue_not_empty(int* queue, int size) {  // verifica se a fila esta vazia
	for (int i = 0; i < size; i++) {
		if (queue[i] != -1 && queue[i] != -2) return 1;
	}
	return 0;
}


int dequeue(int** queue, int size) {  // remove o valor da fila, dando prioridade para o ultimo valor aa entrar
	int i = 0;
	while((*queue)[i] == -1 || (*queue)[i] == -2) {
		i++;
		if(i > size) return -1;
	}
	int aux = (*queue)[i];
	(*queue)[i] = -2;
	return aux;
}


void search_graph_length(graphs* graph, int start) {  // Executa o algoritmo bfs
	start--;  // Reduz em 1 o valor do vertice inicial (vertices iniciam em 1 mas os vetores em 0)
	int* queue = malloc(2*graph->nedges * sizeof(int));  // aloca vetores para fila, distancias e vertices anteriores
	int* distances = malloc(graph->size * sizeof(int));
	int* previousn = malloc(graph->size * sizeof(int));
	for (int i = 0; i < graph->size; i++) {  // inicializa todos com -1
		queue[i] = -1;
		distances[i] = -1;
		previousn[i] = -1;
	}
	for (int i = graph->size; i < 2*graph->nedges; i++)
		queue[i] = -1;

	printf("Origem da busca: %d\n", start+1);
	printf("Vertices alcancados e distancias:\n");

	distances[start] = 0;  // Coloca o valor da distancia do vertice inicial como 0
	visit_node(graph, &queue, &distances, &previousn, start);  // visita o vertice inicial
	int nnode;
	while (queue_not_empty(queue, 2*graph->nedges)) {  // enquanto a fila nao estiver vazia (todos os vertices possiveis visitados)
		nnode = dequeue(&queue, 2*graph->nedges);
		distances[nnode] = 1 + distances[previousn[nnode]];  // distancia do vertice eh igual aa distancia do vertice anterior + 1
		visit_node(graph, &queue, &distances, &previousn, nnode);  // visita este vertice
	}
	// libera o uso da memoria utilizada
	free(queue);
	free(distances);
	free(previousn);
}
