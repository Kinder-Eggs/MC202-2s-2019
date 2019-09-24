#ifndef linklist
#define linklist

#include <stdlib.h>
#include <stdio.h>

struct linkedlist{  // estrutura da lista ligada
	int index;  // valor que sera requisitado
	int counter;  // contador para a estrategia de count
	struct linkedlist* next;  // proximo elemento da lista
};

// declaracoes das funcoes existentes em linklist.c
void insert_node_head(struct linkedlist**, int);
int move_to_head(struct linkedlist**, int);
void free_linkedlist(struct linkedlist**, int);
int transpose(struct linkedlist**, int);
int count(struct linkedlist**, int);

#endif
