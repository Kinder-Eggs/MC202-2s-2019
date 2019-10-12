#include "symlist.h"

void insert_at_pos (symlist** list, int pos, double value) {
	if(pos == -1) {  // Quando nao ha elementos na lista, inicializa o valor no espaco ja existente
		(*list)->value = value;
		(*list)->A = (*list)->B = NULL;
		return;
	}
	// Inicializa ponteiros p e q para encontrar a posicao desejada
	// p sera o espaco logo apos a posicao desejada (NULL quando a posicao desejada for a ultima)
	// q aponta para a posicao desejada (ultima posicao quando a posicao desejada eh maior do que o numero de espacos)
	symlist *p = *list, *q = NULL;
	for (int i = 0; i < pos; i++) {
		if(p->A == q && p->B != q) {
			if(p->B == NULL) {
				// Ao encontrar a posicao desejada aloca o espaco de memoria e inicializa os valores corretamente
				// Este mesmo algoritmo se repete para as diversas possiveis formas de localizar a posicao
				p->B = malloc(sizeof(symlist));
				symlist *z = p->B;
				z->value = value;
				z->B = p;
				z->A = NULL;
				return;
			}
			q = p;
			p = p->B;
		} else if(p->A != q && p->B == q) {
			if(p->A == NULL) {
				p->A = malloc(sizeof(symlist));
				symlist *z = p->A;
				z->value = value;
				z->B = p;
				z->A = NULL;
				return;
			}
			q = p;
			p = p->A;
		} else if(pos != 0) {
			symlist *w = malloc(sizeof(symlist));
			w->value = value;
			(*list)->A = w;
			w->B = *list;
			w->A = NULL;
			return;
		}
	}
	symlist *w = malloc(sizeof(symlist));
	w->value = value;
	w->A = p;
	w->B = q;
	if(q != NULL){
		if(q->A == p) {
			q->A = w;
		} else {
			q->B = w;
		}
	} else {
		*list = w;
	}
	if(p->A == q) {
		p->A = w;
	} else {
		p->B = w;
	}
}

void print_list (symlist* list) {
	// Quando so ha um valor imprime este valor e retorna
	if(list->A == NULL && list->B == NULL) {
		printf("%.4lf \n", list->value);
		return;
	}
	// Quando ha multiplos valores utiliza p e q da mesma forma que na insercao
	// Percorre a lista ate encontrar o valor final e imprimindo cada um deles
	symlist *p, *q = NULL;
	for (p = list; p != NULL; ) {
		printf("%.4lf ", p->value);
		if(p->A == q && p->B != q) {
			q = p;
			p = p->B;
		} else if(p->A != q && p->B == q) {
			q = p;
			p = p->A;
		}
	}
	printf("\n");
}


void reverse_list_at (symlist** list, int pos1, int pos2) {
	if (pos1 == pos2) {  // Quando pos1 = pos2 nao ha o que inverter
		return;
	}
	if(pos1 == 0) {  // Caso de pos1 == 0 (nao existe valor anterior e eh necessario alterar o ponteiro pra head)
		symlist *w = *list, *z = NULL;  // w e z sao analogos a p e q nas funcoes anteriores, desta vez caminhando ate pos2+1 e pos2 respectivamente
		for (int i = 0; i <= pos2; i++) {
			if(w->A == z && w->B != z) {
				z = w;
				w = w->B;
			} else if(w->A != z && w->B == z) {
				z = w;
				w = w->A;
			}
			if (w == NULL) {
				break;
			}
		}
		// Ao encontrar a posicao altera todos os ponteiros de forma a espelhar a lista
		if((*list)->A == NULL) {
			(*list)->A = w;
		} else {
			(*list)->B = w;
		}
		if(z->A == w) {
			z->A = NULL;
		} else {
			z->B = NULL;
		}
		if(w != NULL){
			if(w->A == z) {
				w->A = *list;
			} else {
				w->B = *list;
			}
		}
		*list = z;
		return;

	}
	// Analogo ao funcionamento acima, porem com o dobro de ponteiros
	// p e q encontram pos1 e pos1-1 respectivamente
	// z e w encontram pos2 e pos2+1 respectivamente
	symlist *p = *list, *q = NULL;
	for (int i = 0; i < pos1; i++) {
		if(p->A == q && p->B != q) {
			q = p;
			p = p->B;
		} else if(p->A != q && p->B == q) {
			q = p;
			p = p->A;
		}
	}
	symlist *w = *list, *z = NULL;
	for (int i = 0; i <= pos2; i++) {
		if(w->A == z && w->B != z) {
			z = w;
			w = w->B;
		} else if(w->A != z && w->B == z) {
			z = w;
			w = w->A;
		}
		if (w == NULL){
			break;
		}
	}
	if(q->A == p) {
		q->A = z;
	} else {
		q->B = z;
	}
	if(p->A == q) {
		p->A = w;
	} else {
		p->B = w;
	}
	if(z->A == w) {
		z->A = q;
	} else {
		z->B = q;
	}
	if(w != NULL){
		if(w->A == z) {
			w->A = p;
		} else {
			w->B = p;
		}
	}
}

void recursive_free(symlist* p, symlist* q) {
	// Utiliza uma funcao recursiva para dar free em todos os valores
	// A funcao recebe a posicao atual e a posicao anterior (NULL na primeira chamada)
	// Ao utilizar a funcao recursiva nao eh necessario percorrer a lista ate o final e entao percorrer ate o inicio novamente
	if((p->A == q && p->B == NULL) || (p->A == NULL && p->B == q)) {  // ao encontrar o ultimo valor da free e retorna
		free(p);
		return;
	}
	if(p->A == q && p->B != q) {  // Percorre todos os valores, chamando a funcao novamente para a proxima posicao
		recursive_free(p->B, p);  // ao receber o retorno da ultima um efeito cascata da free e retorna para cada um dos valores
		free(p);
		return;
	} else if(p->A != q && p->B == q) {
		recursive_free(p->A, p);
		free(p);
		return;
	}
}

void free_list(symlist** list) {
	recursive_free(*list, NULL);  // chama a funcao recursiva para dar free em todos os valores
}

