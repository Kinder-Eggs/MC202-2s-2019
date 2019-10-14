#include "arvore.h"

void bintree_insert(bintree **bintree, int key) {
	if (*bintree == NULL) {  // ao encontrar um no vazio, aloca e coloca a chave
		*bintree = malloc(sizeof(bintree));
		(*bintree)->key = key;
		return;
	}
	if ((*bintree)->key > key) {  // caso o no atual possua chave > a chave a ser adicionada vai para o no esquerdo
		bintree_insert(&((*bintree)->left), key);
	} else {  // caso contrario vai para o no direito
		bintree_insert(&((*bintree)->right), key);
	}
}

int bintree_search(bintree *bintree, int key) {
	if (bintree == NULL) return 0;  // quando o no eh null retorna 0
	if (bintree->key == key) return 1;  // quando encontra a chave retorna 1
	if (bintree->key > key) return bintree_search(bintree->left, key);  // chave > procurada, vai para o no esquerdo
	if (bintree->key < key) return bintree_search(bintree->right, key);  // caso contrario, vai para o no direito
}


void bintree_postorder(bintree *bintree) {
	if (bintree == NULL) return;  // ao encontrar um no vazio retorna
	bintree_postorder(bintree->left);  // avanca para o no esquerdo
	bintree_postorder(bintree->right);  // avanca para o no direito
	printf("%d ", bintree->key);  // printa apos printar ambos os nos direitos e esquerdos quando houver
}


void bintree_order(bintree *bintree) {  // analogo ao de cima, porem printa somente apos o esquerdo, printando o direito posteriormente
	if (bintree == NULL) return;
	bintree_order(bintree->left);
	printf("%d ", bintree->key);
	bintree_order(bintree->right);
}


void bintree_preorder(bintree *bintree) { // analogo porem printando e depois avancando os nos
	if (bintree == NULL) return;
	printf("%d ", bintree->key);
	bintree_preorder(bintree->left);
	bintree_preorder(bintree->right);
}

void insert_queue(bintree** queue, bintree* bin_tree) {  // insere um ponteiro de bintree na fila
	if(!bin_tree) return;
	int i;
	for (i = 0; queue[i]; i++);
	queue[i] = bin_tree;
}

void bintree_length(bintree *bin_tree, bintree** queue, int i) {  // utiliza a arvore e uma fila para printar as chaves em ordem de largura
	if(!bin_tree) return;  // quando encontra um no nulo, retorna
	insert_queue(queue, bin_tree->left);  // adiciona o no esquerdo e o direito na fila
	insert_queue(queue, bin_tree->right);
	i++;
	bintree_length(queue[i], queue, i);  // avanca para o proximo no da fila e repete com ele
}  // ao final da recursao a fila possui todas as chaves em ordem de largura

void terminate(bintree **bintree) {  // avanca em todos os nos da arvore, dando free de baixo para cima
	if (*bintree == NULL) return;
	terminate(&((*bintree)->left));
	terminate(&((*bintree)->right));
	free(*bintree);
}
