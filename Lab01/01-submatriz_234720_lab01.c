// Gabriel Costa Kinder - 234720

#include <stdio.h>

int main() {
	int col, lin, r, s, somaparcial, somafinal = 0;
	scanf("%d %d %d %d", &col, &lin, &r, &s); // obtem parametros de inicializacao
	int matriz[col][lin];// declara matriz com o tamanho especificado

	for (int i = 0; i<col; i++){  // obtem o valor de cada elemento da matriz
		for (int j = 0; j<lin; j++){
			scanf("%d", &matriz[i][j]);
		}
	}

	for (int i = 0; i<col; i++){  // itera sob cada elemento da matriz verificando se a soma de todos os elementos dentro de um retangulo rxs eh maior que a soma anterior
		if (i+r-1 < col){  // verifica que nao esta sendo obtido valores fora da matriz
			for (int j = 0; j<lin; j++){
				if (j+s-1 < lin){			
					somaparcial = 0;
					for (int k = 0; k<r; k++){
						for (int l = 0; l<s; l++){
							somaparcial += matriz[i+k][j+l];
						}
					}
					if (somaparcial > somafinal){
						somafinal = somaparcial;
					}
				}
			}
		} else break;
	}
	printf("%d\n", somafinal);
	return 0;
}