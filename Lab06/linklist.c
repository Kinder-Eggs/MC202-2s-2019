#include <stdlib.h>
#include <stdio.h>

#include "linklist.h"

typedef struct linkedlist linkedlist;

void insert_node_head(linkedlist **listhead, int value) {
	linkedlist* p = *listhead;
	*listhead = malloc(sizeof(linkedlist));
	(*listhead)->index = value;
	(*listhead)->next = p;
	return;
}


int move_to_head(linkedlist **listhead, int value) {
	int cost = 2;
	linkedlist* p = *listhead;
	linkedlist* q;
	if(p->index == value){
		return 1;
	}
	while (p->next->index != value) {
		p = p->next;
		cost++;
	}
	q = p->next;
	p->next = q->next;
	q->next = *listhead;
	*listhead = q;
	return cost;
}


void free_linkedlist(linkedlist **listhead) {
	linkedlist* p = (*listhead)->next;
	while(!p->next) {
		free(*listhead);
		*listhead = p;
		p = p->next;
	}
	free(*listhead);
	free(p);
}


int transpose(linkedlist **listhead, int req) {
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

int count(linkedlist **listhead, int req) {
	linkedlist* p = (*listhead);
	linkedlist* q = p;
	linkedlist* w;
	while(p->index != req) {
		p = p->next;
	}
	p->counter += 1;
	int maxcounter = q->counter;	
	while (q->next != p) {
		if (q->next->counter > maxcounter) {
			q = p->next;
			maxcounter = q->counter;
		}
	}
}