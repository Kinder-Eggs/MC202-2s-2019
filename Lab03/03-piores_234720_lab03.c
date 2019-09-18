#include <stdio.h>
#include <string.h>

int l = 1;  // numero de loops ja executados

int ver_desc(void);

int main() {
	int n;
	n = ver_desc();
	while (n == 1) {
		getchar();
		n = ver_desc();  // retona zero quando ha uma linha em branco
	}
}

int ver_desc(void) {
 	int nchave, ndesc, maioroc = 0;

	if (scanf("%d %d ", &nchave, &ndesc) == EOF) return 0;  // obtem valores de chaves e respostas, caso nao existam mais testes  retorna 0 encerrando o programa

	char chaves[nchave][25];
	char desculpas[ndesc][100];
	int ocorrencias[100] = {0};

 	for (int i = 0; i < nchave; i++) {
 		scanf("%s", chaves[i]);  // le cada uma das chaves
 	}
	for (int i = 0; i < ndesc; i++) {
		scanf(" %[^\n]", desculpas[i]);  // le cada uma das desculpas
	}

	printf("Conjunto de desculpas #%d\n", l);  // imprime o numero do conjunto sendo iterado

	// itera sob o conjunto de desculpas em busca das palavras chaves
	for (int i = 0; i < ndesc; i++) {
		for (int j = 0; j < nchave; j++) {
			int n = 0;
			for (int c = 0; c < strlen(desculpas[i]); c++) {
				if (desculpas[i][c] == ' ') n = 0;
				if (desculpas[i][c] > 64 && desculpas[i][c] < 93){  // caso a letra seja maiuscula (codigo ASCII entre 65 e 92) soma 32 para alcancar a letra minuscula
					if ((desculpas[i][c] + 32) == chaves[j][n]){
						n++;
						if (strlen(chaves[j]) == n) {
							n = 0;
							ocorrencias[i]++;  // quando encontra uma palavra chave contida na desculpa aumenta o numero de ocorrencias com i = numero da desculpa
						}
					} else n = 0;
				} else {
					if (desculpas[i][c] == chaves[j][n]) {
						n++;
						if (strlen(chaves[j]) == n) {
							n = 0;
							ocorrencias[i]++;
						}
					} else n = 0;
				}
			}
		}
		if (ocorrencias[i] > maioroc) maioroc = ocorrencias[i];  // mantem salvo o maior numero de ocorrencias para um conjunto
	}

	for (int i = 0; i < 100; i++) {  // procura e entao imprime todas as desculpas que obtiveram o maior numero de ocorrencias
		if (ocorrencias[i] == maioroc) printf("%s\n", desculpas[i]);
	}
	printf("\n");
	l++;  // aumenta o numero de loops (utilizado para saber em qual conjunto de desculpas esta)
	return 1;  // retorna 1 para procurar por um proximo conjunto
}
