#include "arvore.h"	

int main() {
	bintree* bintree = NULL;
	char command[10];
	scanf(" %s", command);
	while(strcmp(command, "terminar")) {
		if(!strcmp(command, "inserir")) {

			int key;
			scanf(" %d", &key);
			if (!bintree_search(bintree, key))
				bintree_insert(&bintree, key);

		}else
		if(!strcmp(command, "buscar")) {

			int key;
			scanf(" %d", &key);
			if (bintree_search(bintree, key)) {
				printf("%d pertence\n", key);
			} else {
				printf("%d nao pertence\n", key);
			}
			
		}else
		if(!strcmp(command, "pos-ordem")) {

			if (bintree) {
				bintree_postorder(bintree);
				printf("\n");
			} else {
				printf("vazia\n");
			}
			
		}else
		if(!strcmp(command, "em-ordem")) {

			if (bintree) {
				bintree_order(bintree);
				printf("\n");
			} else {
				printf("vazia\n");
			}

		}else
		if(!strcmp(command, "pre-ordem")) {

			if (bintree) {
				bintree_preorder(bintree);
				printf("\n");
			} else {
				printf("vazia\n");
			}

		}else
		if(!strcmp(command, "largura")) {
			
		}

		scanf(" %s", command);
	}
	terminate(&bintree);
}