#ifndef SYMLIST_H
#define SYMLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct symlist {

	double value;
	struct symlist *A, *B;

} symlist;

void insert_at_pos (symlist**, int, double);
void print_list (symlist*);
void reverse_list_at (symlist**, int, int);
void free_list(symlist**);

#endif