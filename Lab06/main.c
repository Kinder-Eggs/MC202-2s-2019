// Gabriel Costa Kinder - 234720
// Objetivo: Verificar os diferentes custos das estrategias de listas auto organizaveis Move-to-Front, Transpose e Count
#include "linklist.h"

typedef struct linkedlist linkedlist;

//Declaracoes de funcoes
void start_list(linkedlist**, int);
void start_counters(linkedlist**, int);

int main() {
	int size, nreq, mtfcost = 0, transcost = 0, countcost = 0;  // variaveis para o tamanho, numero de requests e custos totais das estrategias
	linkedlist* listhead;  // ponteiro que ira manter a head da lista ligada
	scanf(" %d", &size);
	scanf(" %d", &nreq);
	int req[nreq];  // matriz que mantem as requests que devem ser realizacas

	// Comeco do processo de move-to-front

	start_list(&listhead, size);  // cria uma lista ligada do tamanho especificado
	for (int i = 0; i < nreq; i++) {
		scanf(" %d", &req[i]);  // obtem e salva cada um dos requests
		mtfcost += move_to_head(&listhead, req[i]);  // chama a funcao para obter o custo de cada request somando no custo final
	}
	printf("%d", mtfcost);  // imprime custo final
	free_linkedlist(&listhead, size);  // desaloca a memoria ocupada pela lista

	// Comeco do processo de Transpose

	start_list(&listhead, size);  // processo analogo ao de cima
	for (int i = 0; i < nreq; i++) {
		transcost += transpose(&listhead, req[i]);
	}
	printf(" %d", transcost);
	free_linkedlist(&listhead, size);

	// Comeco do processo de Count

	start_list(&listhead, size); // processo analogo ao de cima
	start_counters(&listhead, size); // inicializa a variavel count de todos os nos da lista como 0
	for (int i = 0; i < nreq; i++) {
		countcost += count(&listhead, req[i]);
	}
	printf(" %d\n", countcost);
	free_linkedlist(&listhead, size);
}


void start_list(linkedlist **listhead, int size) {
	for (int i = size; i > 0; i--) { // chama size vezes a funcao de inserir no
		insert_node_head(listhead, i);
	}
}

void start_counters(linkedlist **listhead, int size) { // inicializa a variavel count de todos os nos da lista como 0
	linkedlist* p = *listhead;
	for (int i = 0; i < size; i++) {
		p->counter = 0;
		p = p->next;
	}
}