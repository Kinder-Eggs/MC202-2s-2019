#ifndef ARVORE_H
#define ARVORE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>



typedef struct bintree {
	struct bintree *left, *right;  // mantem os ponteiros para os nos da direita e esquerda
	int key;
} bintree;

void bintree_insert(bintree**, int);
int bintree_search(bintree*, int);
void bintree_postorder(bintree*);
void bintree_order(bintree*);
void bintree_preorder(bintree*);
void bintree_length(bintree*, bintree**, int);
void bintree_remove(bintree**, int);
int bintree_min(bintree*);
int bintree_max(bintree*);
int bintree_successor(bintree*, int);
int bintree_predecessor(bintree*, int);
void bintree_interval(bintree*, int**);
void terminate(bintree**);

#endif
