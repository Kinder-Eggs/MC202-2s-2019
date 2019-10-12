#include "arvore.h"


void bintree_insert(bintree **bintree, int key) {
	if (*bintree == NULL) {
		*bintree = malloc(sizeof(bintree));
		(*bintree)->key = key;
		return;
	}
	if ((*bintree)->key > key) {
		bintree_insert(&((*bintree)->left), key);
	} else {
		bintree_insert(&((*bintree)->right), key);
	}
}

int bintree_search(bintree *bintree, int key) {
	if (bintree == NULL) return 0;
	if (bintree->key == key) return 1;
	if (bintree->key > key) return bintree_search(bintree->left, key);
	if (bintree->key < key) return bintree_search(bintree->right, key);
}


void bintree_postorder(bintree *bintree) {
	if (bintree == NULL) return;
	bintree_postorder(bintree->left);
	bintree_postorder(bintree->right);
	printf("%d ", bintree->key);
}


void bintree_order(bintree *bintree) {
	if (bintree == NULL) return;
	bintree_order(bintree->left);
	printf("%d ", bintree->key);
	bintree_order(bintree->right);
}


void bintree_preorder(bintree *bintree) {
	if (bintree == NULL) return;
	printf("%d ", bintree->key);
	bintree_preorder(bintree->left);
	bintree_preorder(bintree->right);
}


void bintree_length() {
	
}


void terminate(bintree **bintree) {
	if (*bintree == NULL) return;
	terminate(&((*bintree)->left));
	terminate(&((*bintree)->right));
	free(*bintree);
}