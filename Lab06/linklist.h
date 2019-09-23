#ifndef linklist
#define linklist

#include <stdlib.h>
#include <stdio.h>

struct linkedlist{
	int index;
	int counter;
	struct linkedlist* next;
};

void insert_node_head(struct linkedlist**, int);
int move_to_head(struct linkedlist**, int);
void free_linkedlist(struct linkedlist**, int);
int transpose(struct linkedlist**, int);
int count(struct linkedlist**, int);

#endif
