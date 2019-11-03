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


int bintree_search(bintree *bin_tree, int key) {
	if (bin_tree == NULL) return 0;  // quando o no eh null retorna 0
	if (bin_tree->key == key) return 1;  // quando encontra a chave retorna 1
	if (bin_tree->key > key) return bintree_search(bin_tree->left, key);  // chave > procurada, vai para o no esquerdo
	return bintree_search(bin_tree->right, key);  // caso contrario, vai para o no direito
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


void bintree_remove(bintree **bin_tree, int key){
	bintree *aux1, *aux2 = *bin_tree;  // aux1 sera o no anterior ao que deve ser removido, aux2 eh o no que deve ser removido
	int dir = 0;  // aponta em qual direcao de aux1 aux2 esta (1-direita;-1-esquerda;0-aux2 eh o no inicial)
	// Posiciona aux1 e aux2 corretamente e configura o valor de dir
	while (aux2->key != key) {
		aux1 = aux2;
		if(aux2->key > key) {
			aux2 = aux2->left;
			dir = -1;
		} else {
			aux2 = aux2->right;
			dir = 1;
		}
	}
	// Caso aux2 nao possua filhos
	if(aux2->right == NULL && aux2->left == NULL) {
		free(aux2);
		if(dir == 1)
			aux1->right = NULL;
		if(dir == -1)
			aux1->left = NULL;
		if(dir == 0)
			(*bin_tree) = NULL;
		return;
	}
	// Caso aux2 possua somente um filho a esquerda
	if(aux2->right == NULL) {
		if(dir == 1) {
			aux1->right = aux2->left;
			free(aux2);
			return;
		}
		if(dir == -1) {
			aux1->left = aux2->left;
			free(aux2);
			return;
		}
		if(dir == 0){
			(*bin_tree) = (*bin_tree)->left;
			free(aux2);
			return;
		}
	}
	// caso aux2 possua somente um filho a direita
	if(aux2->left == NULL) {
		if(dir == 1) {
			aux1->right = aux2->right;
			free(aux2);
			return;
		}
		if(dir == -1) {
			aux1->left = aux2->right;
			free(aux2);
			return;
		}
		if(dir == 0) {
			(*bin_tree) = (*bin_tree)->right;
			free(aux2);
			return;
		}
	}
	// caso aux2 possua dois filhos
	int nkey = bintree_successor((*bin_tree), key);  // obtem o sucessor de aux2
	bintree_remove(bin_tree, nkey);  // remove o sucessor de aux2
	aux2->key = nkey;  // coloca o valor da key de aux2 como a de seu sucessor resultando em aux2 tendo sido removido
}


int bintree_min(bintree* bin_tree){  // busca recursivamente o valor minimo
	if(bin_tree->left == NULL) return bin_tree->key;
	return bintree_min(bin_tree->left);
}


int bintree_max(bintree* bin_tree) {  // busca recursivamente o valor maximo
	if(bin_tree->right == NULL) return bin_tree->key;
	return bintree_max(bin_tree->right);	
}


int bintree_successor(bintree* bin_tree, int key){
	bintree* aux = bin_tree;  // aux apontara para o no que possui key
	int suc = 0;
	while (aux->key != key) {
		if(aux->key > key) {
			suc = aux->key;  // toda vez que, para encontrar aux, deve-se andar a esquerda, salva o valor dessa key
			aux = aux->left;
		} else {
			aux = aux->right;
		}
	}
	if(aux->right != NULL) { // Caso key possua filhos a direita
		return bintree_min(aux->right);  // retorna o menor valor entre os que sao maiores que key
	} else { // caso nao haja retorna a ultima chave que estava acima e a direita de aux
		return suc;
	}
}


int bintree_predecessor(bintree* bin_tree, int key){ // analogo a sucessor porem espelhado
	bintree* aux = bin_tree;
	int pre = 0;
	while (aux->key != key) {
		if(aux->key > key) {
			aux = aux->left;
		} else {
			pre = aux->key;
			aux = aux->right;
		}
	}
	if(aux->left != NULL) {
		return bintree_max(aux->left);
	} else {
		return pre;
	}
}


void orderqueue(bintree* bin_tree, int** queue, int* counter){
	if (bin_tree == NULL) return;  // quando chega em uma folha retorna
	orderqueue(bin_tree->left, queue, counter);
	(*queue)[(*counter)] = bin_tree->key;  // adiciona, em ordem, todos os valores da arvore na fila
	(*counter)++;
	orderqueue(bin_tree->right, queue, counter);
}


void bintree_interval(bintree* bin_tree, int** queue){
	int* counter = malloc(sizeof(int));  // cria um int que sera utilizado como contador para posicionar corretamente na fila
	*counter = 0;
	orderqueue(bin_tree, queue, counter);  // chama uma funcao recursiva auxiliar para criar a fila
	free(counter);  // libera o espaco do contador
}


void terminate(bintree **bintree) {  // avanca em todos os nos da arvore, dando free de baixo para cima
	if (*bintree == NULL) return;
	terminate(&((*bintree)->left));
	terminate(&((*bintree)->right));
	free(*bintree);
}
