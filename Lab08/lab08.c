#include "symlist.h"

int main() {
	char command;  // Mantem o comando que deseja-se ser utilizado
	int empty = 1;  // Sabe se a lista ainda esta vazia ou nao (1==vazio)
	scanf(" %c", &command);
	symlist* list;  // Declara e aloca a lista simetrica
	list = malloc(sizeof(symlist));
	list->A = list->B = NULL;  // Inicializa ambos ponteiros como NULL
	while (command != 't') {  // Finaliza quando eh inserido 't'
		if (command == 'i') {
			int pos;
			double value;
			scanf(" %d %lf", &pos, &value);  // obtem a pos e o valor desejado
			if (empty) {  // quando a lista ainda esta vazia coloca pos como -1 para a funcao inicializar corretamente o primeiro valor
				pos = -1;
				empty = 0;  // Declara empty como 0
			}  
			insert_at_pos(&list, pos, value);  // Chama a funcao de insercao
		}else if (command == 'p') {
			if(!empty){
				print_list(list);  // Chama a funcao que imprime a lista
			} else {
				printf("\n");  // Quando a lista esta vazia imprime uma linha em branco
			}
		}else if (command == 'v') {
			if(!empty){
				int pos1, pos2;
				scanf(" %d %d", &pos1, &pos2);
				reverse_list_at(&list, pos1, pos2);  // chama a funcao para inverter entre pos1 e pos2
			}
		}
		scanf(" %c", &command);
	}
	free_list(&list);  // Libera os espacos de memoria ocupados
}