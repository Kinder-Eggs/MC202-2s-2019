#include <stdio.h>
#include <stdlib.h>

// Gabriel Costa Kinder - 234720

void make_heap(int*, int);
void fix_heap(int*, int, int);
void remove_heap(int*, int*);


int main() {
	int size;  // mantem o tamanho atual do heap
	scanf("%d", &size);
	int orig_size = size;  // mantem o tamanho do vetor
	int* vector = malloc(size*sizeof(int));  // aloca o vetor
	if (!vector) return 0;  // para se nao consegue alocar
	for (int i=0; i < size; i++) {
		scanf("%d", &vector[i]);  // coloca os valores necessarios no vetor
	}
	make_heap(vector, size);  // cria o heap
	for(int i = size-1; i >= 0; i--) {
		remove_heap(vector, &size);  // remove cada valor do heap, colocando na ultima posicao e diminuindo size
	}
	for(int i = 0; i < orig_size; i++) {
		printf("%d ", vector[i]);  // printa os valores em ordem
	}
	printf("\n");
	free(vector);
}


void make_heap(int* vector, int size) {
	for (int i=size/2; i >= 0; i--) {
		fix_heap(vector, size, i);  // arruma o heap de baixo para cima, comecando no ultimo pai
	}
}


void fix_heap(int* vector, int size, int i) {
	int max;  // salva a posicao do valor maximo
	int left = 2*(i+1) - 1;  // salva a posicao dos filhos da esquerda e direita
	int right = 2*(i+1);

	/* quando a posicao esquerda nao esta fora do heap (filho inexistente)
	e possui valor maior que o pai salva a posicao como maximo */
	if (left < size && vector[left] > vector[i])
		max = left;
	else  // caso nao seja salva a posicao do pai como max
		max = i;
	if (right < size && vector[right] > vector[max])  // analogo para o filho direito
		max = right;
	if (max != i) {  // caso um dos filhos sejam maiores que o pai
		int aux = vector[i];  // troca o filho com o pai
		vector[i] = vector[max];
		vector[max] = aux;
		fix_heap(vector, size, max);  // executa a funcao para arrumar novamente
	}
}


void remove_heap(int* vector, int* size) {
	int aux = vector[(*size)-1];  // coloca o maior valor no fim do heap
	vector[(*size)-1] = vector[0];
	vector[0] = aux;
	(*size)--;  // diminui o tamanho do heap em 1
	fix_heap(vector, *size, 0);  // reorganiza o primeiro elemento
}