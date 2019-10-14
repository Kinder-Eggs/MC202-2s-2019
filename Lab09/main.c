#include "arvore.h"

// Gabriel Costa Kinder - 234720

int main() {
	bintree* bin_tree = NULL;
	char command[10];
	int size = 0;  // Numero de nos na arvore
	scanf(" %s", command);
	while(strcmp(command, "terminar")) {  // executa comandos ate receber "terminar"
		if(!strcmp(command, "inserir")) {

			int key;
			scanf(" %d", &key);
			if (!bintree_search(bin_tree, key)){  // se o no com key ja existe, nao insere
				bintree_insert(&bin_tree, key);
				size++;
			}

		}else
		if(!strcmp(command, "buscar")) {

			int key;
			scanf(" %d", &key);
			if (bintree_search(bin_tree, key)) {  // caso haja key, printa que pertence, caso nao haja, printa que nao pertence
				printf("%d pertence\n", key);
			} else {
				printf("%d nao pertence\n", key);
			}

		}else
		if(!strcmp(command, "pos-ordem")) {

			if (bin_tree) {
				bintree_postorder(bin_tree);
				printf("\n");
			} else {
				printf("vazia\n");
			}

		}else
		if(!strcmp(command, "em-ordem")) {

			if (bin_tree) {
				bintree_order(bin_tree);
				printf("\n");
			} else {
				printf("vazia\n");
			}

		}else
		if(!strcmp(command, "pre-ordem")) {

			if (bin_tree) {
				bintree_preorder(bin_tree);
				printf("\n");
			} else {
				printf("vazia\n");
			}

		}else
		if(!strcmp(command, "largura")) {

			if (bin_tree) {
				bintree** queue;
				queue = malloc((size+1)*sizeof(bintree*));  // cria um vetor de bintree* que sera utilizado como fila
				for (int i = 0; i < size; i++) {
					queue[i] = NULL;  // inicializa todos os valores com NULL
				}
				queue[0] = bin_tree;  // insere o primeiro no na primeira posicao
				int i = 0;
				bintree_length(bin_tree, queue, i);
				for (int j = 0; j < size; j++) {  // printa todos os valores de key, em ordem de largura
					printf("%d ", (queue[j])->key);
				}
				printf("\n");
				free(queue);  // libera a memoria usada pela fila
			} else {
				printf("vazia\n");
			}

		}

		scanf(" %s", command);
	}
	terminate(&bin_tree);  // Libera a memoria da arvore
}
