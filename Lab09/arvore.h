#ifndef ARVORE_H
#define ARVORE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>



typedef struct bintree {
	struct bintree *left, *right;
	int key;
} bintree;

void bintree_insert(bintree**, int);
int bintree_search(bintree*, int);
void bintree_postorder(bintree*);
void bintree_order(bintree*);
void bintree_preorder(bintree*);
void bintree_length(bintree*);
void terminate(bintree**);

#endif