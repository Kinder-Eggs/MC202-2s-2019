#include "hashtable.h"


int main() {
	int next_id = 0;  // mantem qual sera o proximo id a ser alocado
	int ids[SIZEOFTABLE];  // vetor com os ids para cada posicao da hashtable
	for(int i = 0; i < SIZEOFTABLE; i++){
		ids[i] = -1;  // inicializa todos com -1, eh posteriormente utilizado para nao dar free nos espacos vazios
	}
	char command[2];
	char** vector = malloc(SIZEOFTABLE*sizeof(char*));  // aloca o vetor que contera as strings com tamanho definido no .h
	scanf(" %s", command);
	char* string = malloc(251*sizeof(char));  // cria uma string para auxiliar na leitura dos comandos
	while(strcmp(command, "f")){  // continua executando enquanto nao recebe 'f'
		// executa as funcoes dos comandos requisitados, mais detalhes nas proprias funcoes
		if(!strcmp(command, "i")){
			scanf(" %s", string);
			next_id = insert_hashtable(string, next_id, vector, ids);
		}else
		if(!strcmp(command, "b")){
			scanf(" %s", string);
			unsigned long aux = search_hashtable(string, vector);
			if(aux==SIZEOFTABLE){
				printf("%s nao encontrada\n", string);
			}else{
				printf("%s encontrada, id %d\n", string, ids[aux]);
			}
		}else
		if(!strcmp(command, "r")){
			scanf(" %s", string);
			remove_hashtable(string, vector, ids);
		}
		scanf(" %s", command);
	}
	free_hashtable(vector, ids);  // funcao para liberar a memoria utilizada pela hashtable
	free(string);  // libera a string auxiliar
	free(vector);  // libera a hashtable
}
