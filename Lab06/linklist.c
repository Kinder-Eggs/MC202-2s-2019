#include <stdlib.h>
#include <stdio.h>

#include "linklist.h"

typedef struct linkedlist linkedlist;

void insert_node_head(linkedlist **listhead, int value) {  // insere um no no comeco da lista com index = value
	linkedlist* p = *listhead;
	*listhead = malloc(sizeof(linkedlist));
	(*listhead)->index = value;
	(*listhead)->next = p;
	return;
}


int move_to_head(linkedlist **listhead, int value) {  // move o no com index = value para o comeco da lista e retorna o custo da operacao
	int cost = 2;
	linkedlist* p = *listhead;
	linkedlist* q;
	if(p->index == value){  // caso seja o primeiro elemento
		return 1;
	}
	// processo para encontrar o elemento, aumentando o custo para quao mais longe o valor esta localizado
	while (p->next->index != value) {
		p = p->next;
		cost++;
	}
	// troca de posicoes da lista
	q = p->next;
	p->next = q->next;
	q->next = *listhead;
	*listhead = q;

	return cost;
}


void free_linkedlist(linkedlist **listhead, int size) {  // libera a memoria alocada de uma lista
	linkedlist* p = (*listhead)->next;
	for (int i = 1; i < size; i++) {
		free(*listhead);
		*listhead = p;
		p = p->next;
	}
	free(*listhead);
}


int transpose(linkedlist **listhead, int req) {  // analogo ao move to front porem com a estrategia de transpose
	linkedlist* p = (*listhead);
	int cost = 3;
	if (p->index == req) {
		return 1;
	}
	if(p->next->index == req) {
		*listhead = p->next;
		p->next = (*listhead)->next;
		(*listhead)->next = p;
		return 2;
	}
	while(p->next->next->index != req) {
		p = p->next;
		cost++;
	}
	linkedlist* q = p->next;
	p->next = q->next;
	q->next = p->next->next;
	p->next->next = q;

	return cost;
}

int count(linkedlist **listhead, int req) {  // analogo as outras duas estrategias porem com a estrategia de count
	int cost = 2;
	linkedlist* p = (*listhead);
	linkedlist* q = p;
	linkedlist* w;
	if(p->index == req) {
		p->counter += 1;
		return 1;
	}
	while(p->next->index != req) {
		p = p->next;
		cost++;
	}
	p->next->counter += 1;
	w = p->next;
	if (p->next->counter >= q->counter) {
		*listhead = w;
		p->next = w->next;
		w->next = q;
		return cost;
	}
	while (q != w && q->next->counter > w->counter) {
		q = q->next;
	}

	p->next = w->next;
	w->next = q->next;
	q->next = w;

	return cost;
}
