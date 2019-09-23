// Gabriel Costa Kinder - 234720
// Objetivo: Verificar os diferentes custos das estrategias de listas auto organizaveis Move-to-Front, Transpose e Count
#include "linklist.h"

typedef struct linkedlist linkedlist;

void start_list(linkedlist**, int);

int main() {
	int size, nreq, mtfcost = 0, transcost = 0, countcost = 0;
	linkedlist* listhead;
	scanf(" %d", &size);
	scanf(" %d", &nreq);
	int req[nreq];

	// Comeco do processo de move-to-front

	start_list(&listhead, size);
	for (int i = 0; i < nreq; i++) {
		scanf(" %d", &req[i]);
		mtfcost += move_to_head(&listhead, req[i]);
	}
	printf("%d", mtfcost);
	free_linkedlist(&listhead, size);

	// Comeco do processo de Transpose

	start_list(&listhead, size);
	for (int i = 0; i < nreq; i++) {
		transcost += transpose(&listhead, req[i]);
	}
	printf(" %d", transcost);
	free_linkedlist(&listhead, size);

	// Comeco do processo de Count

	start_list(&listhead, size);
	for (int i = 0; i < nreq; i++) {
		countcost += count(&listhead, req[i]);
	}
	printf(" %d\n", countcost);
	free_linkedlist(&listhead, size);
}


void start_list(linkedlist **listhead, int size){
	for (int i = size; i > 0; i--) {
		insert_node_head(listhead, i);
	}
}
