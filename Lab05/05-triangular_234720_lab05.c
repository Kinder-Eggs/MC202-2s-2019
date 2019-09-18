#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//Gabriel Costa Kinder - 234720
int main() {
	double med = 0, desv = 0;
	int tam, cont = 0;
	scanf(" %d", &tam); // obtem numero de linhas
	double** matriz;
	matriz = malloc(tam*sizeof(double*));  // aloca tam ponteiros pra double
	for (int i = 0; i < tam; i++) {
		matriz[i] = malloc((tam+1)*sizeof(double));  // aloca o numero de doubles correspondente aa quantos valores existira em cada linha
		for (int j = 0; j <= i; j++){
			scanf(" %le", &matriz[i][j]);  // obtem o valor de cada numero como um double
			cont++;  // conta quantos valores existem
			med += matriz[i][j];  // soma todos os valores em med
		}
 	}
 	med /= cont;  // divide pelo numero de valores, obtendo a media

 	// calcula o desvio padrao dos valores da matriz
 	for (int i = 0; i < tam; i++) {
 		for (int j = 0; j <= i; j++) {
 			desv += ((matriz[i][j] - med) * (matriz[i][j] - med));
 		}
 	}
 	desv = sqrt(desv/cont);


 	// printa os valores pedidos no formato requisitado
 	for (int i = 0; i < tam; i++) {
 		for (int j = 0; j <= i; j++) {
 			matriz[i][j] = (matriz[i][j] - med)/desv;
 			printf("%.12f ", matriz[i][j]);
 		}
 		printf("\n");
 	}
 	printf("\n");

 	printf("%.12f %.12f \n", med, desv);  // printa os valores de media e desvio padrao

 	// libera os espacos de memoria alocados
	for (int i = 0; i < tam; i++){
		free(matriz[i]);
  	}
 	free(matriz);
}
