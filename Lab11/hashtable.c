#include "hashtable.h"


unsigned long hash_str(char* string) {  // funcao de hashing da string (sdbm-gawk)
    unsigned long hash = 0;
    int c;

    while ((c = *string++))
        hash = c + (hash << 6) + (hash << 16) - hash;

    return hash;
}


unsigned long double_hash(char* string) {  // para utilizar hashing duplo (casos de colisao)
	return 1 + (hash_str(string)%SIZEOFTABLE-2);
}


int insert_hashtable(char* string, int next_id, char** vector, int ids[SIZEOFTABLE]) {  // insere a string na hashtable
    if(search_hashtable(string, vector) != SIZEOFTABLE){  // caso a variavel ja esteja na hashtable retorna
        return next_id;
    }
    unsigned long hash = hash_str(string)%SIZEOFTABLE;  // o primeiro hash eh realizado com a string em mod do tamanho da hashtable
	while(vector[hash]) {  // se a posicao da tabela ja esta ocupada
        if(ids[hash] == -2){  // se o id eh -2 era uma posicao que foi ocupada e posteriormente removida, nesse caso libera a memoria e retorna ao funcionamento padrao
            free(vector[hash]);
            break;
        }
		hash += double_hash(string);  // Modifica o hash somando o hash duplo e utilizando mod do tamanho da hashtable
		hash = hash%SIZEOFTABLE;
	}
	vector[hash] = malloc(251*sizeof(char));  // ao encontrar um espaco da tabela vazio, aloca espaco para a string
	strcpy(vector[hash], string);  // copia a string para tal posicao
	ids[hash] = next_id;  // adiciona o devido id no vetor de ids
	next_id++;
	return next_id;  // retorna o proximo id a ser utilizado
}


unsigned long search_hashtable(char* string, char** vector){  // busca se um valor existe na hashtable
    unsigned long hash = hash_str(string)%SIZEOFTABLE;  // adquire o hash da string
    while(1){
        if(vector[hash]){  // quando a posicao ja esta ocupada verifica se a string procurada esta localizada nela
            if(!strcmp(vector[hash], string)){
                return hash;  // ao encontrar retorna o valor de sua posicao
            }
        }else{
            return SIZEOFTABLE;  // caso nao esteja na hashtable retorna o tamanho da mesma
        }
        hash += double_hash(string);  // caso haja colisoes, obtem o hash duplo
        hash = hash%SIZEOFTABLE;
    }
}


void remove_hashtable(char* string, char** vector, int ids[SIZEOFTABLE]){
    unsigned long hash = search_hashtable(string, vector);  // encontra a posicao da string a ser removida
    if(hash==SIZEOFTABLE)  // caso recebe SIZEOFTABLE a string nao esta inclusa
        return;
    /* sobrescreve a string anterior com _____*****_____ para saber que havia uma string anteriormente ali
    (caso tenha havido colisoes ele nao ira interferir com as outrars funcoes da hashtable) */
    strcpy(vector[hash], "_____*****_____");
    ids[hash] = -2;  // Coloca o id como -2
}


void free_hashtable(char** vector, int ids[SIZEOFTABLE]){  // libera a memoria de todos os espacos utilizados
    for(int i = 0; i < SIZEOFTABLE; i++){
        if(ids[i] != -1){
            free(vector[i]);  // realiza free em todos os espacos que possuem id diferente de -1
        }
    }
}
