//Gabriel Costa Kinder - 234720

#include <stdio.h>

int main()
{
	int numclientes, atendentes, clientes10 = 0;
	float media, soma = 0;

	scanf("%d %d ", &atendentes, &numclientes); // obtem o numero de atendentes e clientes
	int clientes[numclientes*2], momento[atendentes];  // inicializa duas matrizes, a primeira contera as informacoes de quando e quanto tempo cada cliente gasta com * atendente, a segunda possuira quando cada atendente estara disponivel

	for (int i = 0; i < atendentes; i++){
		momento[i] = 0;  // inicializa todos os valores de momento como 0
	}

	for (int i = 0; i < numclientes; i++){
		scanf("%d %d", &clientes[i*2], &clientes[(i*2)+1]);  // adiciona todas as informacoes passadas na matriz clientes
	}

	if (atendentes == 1){  // caso so haja um atendente utiliza um caso basico para calcular tempos de espera que possui indice 0 em todas as chamadas a momento
		momento[0] = clientes[0];
		for (int i = 0; i < numclientes-1; i++){
			momento[0] += clientes[(i*2)+1];
			if (momento[0] <= clientes[(i*2)+2]){
				momento[0] = clientes[(i*2)+2];
			} else {
				if (momento[0] - clientes[(i*2)+2] > 10) clientes10++;
				soma += momento[0] - clientes[(i*2)+2];
			}
		}

	} else {  // quando houver mais que um atendente o programa verifica qual atendente possui menor momento e calcula a espera para o proximo cliente como se so houvesse aquele atendente
		momento[0] = clientes[0] + clientes[1];
		for (int i = 1; i < numclientes; i++){
			int menor = 0;
			for (int j = 1; j < atendentes; j++){
				if (momento[j] < momento[menor]) menor = j;
			}
			if (clientes[i*2] > momento[menor]){
				momento[menor] = clientes[i*2] + clientes[(i*2)+1];
			} else {
				if (momento[menor] - clientes[i*2] > 10) clientes10++;
				soma += momento[menor] - clientes[i*2];
				momento[menor] += clientes[(i*2)+1];
			}
		}		
	}


	float a = numclientes;  // copia soma para um float para poder realizar a media com precisao
	media = soma/a;
	printf("Espera media para %d clientes: %.1f minutos\n", numclientes, media);
	printf("Numero de clientes que esperaram mais que 10 minutos: %d\n", clientes10);
	
}