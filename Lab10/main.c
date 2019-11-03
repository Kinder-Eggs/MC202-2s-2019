#include "arvore.h"

// Gabriel Costa Kinder - 234720

int main() {
	bintree* bin_tree = NULL;
	char command[20];
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
		
		}else
		if(!strcmp(command, "remover")) {

			int key;
			scanf(" %d", &key);
			if(bintree_search(bin_tree, key)){
				bintree_remove(&bin_tree, key);
				size--;
			}


		}else
		if(!strcmp(command, "minimo")) {

			if(bin_tree) {
				int min = bintree_min(bin_tree);
				printf("%d\n", min);
			} else {
				printf("vazia\n");
			}

		}else
		if(!strcmp(command, "maximo")) {

			if(bin_tree) {
				int max = bintree_max(bin_tree);
				printf("%d\n", max);
			} else {
				printf("vazia\n");
			}

		}else
		if(!strcmp(command, "sucessor")) {

			int key;
			scanf(" %d", &key);
			if(bintree_search(bin_tree, key)) {
				int suc = bintree_successor(bin_tree, key);
				if(suc != 0)
					printf("%d\n", suc);
				else 
					printf("nao ha\n");
			} else {
				printf("vazia\n");
			}

		}else
		if(!strcmp(command, "predecessor")) {

			int key;
			scanf(" %d", &key);
			if(bintree_search(bin_tree, key)) {
				int pre = bintree_predecessor(bin_tree, key);
				if(pre != 0)
					printf("%d\n", pre);
				else 
					printf("nao ha\n");
			} else {
				printf("vazia\n");
			}

		}else
		if(!strcmp(command, "buscar-intervalo")) {

			int key1, key2;
			scanf(" %d %d", &key1, &key2);
			if(bin_tree){
				int* queue;  // cria uma fila onde sera inserido todos os valores da arvore em ordem crescente
				queue = malloc((size+1)*sizeof(int));
				bintree_interval(bin_tree, &queue);
				if(queue[0] > key2 || queue[(size-1)] < key1)  // quando nenhuma chave esta dentro do intervalo
					printf("nenhuma");
				for(int i = 0; i < size; i++) {
					if(queue[i] < key1 || queue[i] > key2)  // nao imprime chaves fora do intervalo
						continue;
					printf("%d ", queue[i]);
				}
				printf("\n");
				free(queue);  // libera a memoria da fila
			}else{
				printf("nenhuma\n");
			}
		}

		scanf(" %s", command);
	}
	terminate(&bin_tree);  // Libera a memoria da arvore
}
