#include "vector.h"

// Retorna 1 caso nao haja vector->start (vetor vazio)
int vector_empty(dynvector* vector) {
    if(vector->start == NULL) {
        return 1;
    }
    return 0;
}

// Imrpime o valor situado em vector->end caso a lista nao esteja vazia
void print_last(dynvector* vector) {
    if(vector_empty(vector)) return;
    printf("%d\n", *(vector->end));
}

// Remove o ultimo elemento, zerando a lista caso seja o ultimo e diminuindo seu tamanho pela metade quando mais de 3/4 vazio
void remove_last(dynvector* vector) {
    if (vector_empty(vector)) return;  // Caso vazia, retorna
    vector->occupied--;
    if (vector->end == vector->mem) {  // Caso o valor final esteja no primeiro espaco do vetor
        vector->end = vector->mem + vector->size;
    } else {
        vector->end = vector->end - 1;
    }
    if (vector->occupied == 0) {  // quando era o ultimo valor existente
        if (vector->size == 0) return;
        free(vector->mem);
        vector->size = 0;
        vector->start = vector->end = NULL;
        return;
    }
    if (vector->occupied * 4 <= vector->size) {  // quando e necessario reduzir o tamnanho pela metade
        int* p;
        p = malloc((vector->size/2) * sizeof(int));
        if (vector->mem == vector->start) {
            for (int i = 0; i < vector->occupied; i++) {
                p[i] = vector->mem[i];
            }
        } else {
            int i = 0;
            while (vector->start + i != vector->mem + vector->size && i < vector->occupied) {
                p[i] = vector->start[i];
                i++;
            }
            p[i] = vector->start[i];
            i++;
            for (int j = 0; i < vector->occupied; i++) {
                p[i] = vector->mem[j];
                j++;
            }
        }
        vector->size = vector->size / 2;
        free(vector->mem);
        vector->mem = vector->start = p;
        vector->end = vector->start + vector->occupied - 1;
    }
}

// Insere um valor na ultima posicao, dobrando o tamanho caso necessario
void insert_last(dynvector* vector, int value) {
    if(vector_empty(vector)) {  // Caso ainda nao haja um vetor cria um com tamanho 1
        vector->mem = malloc(sizeof(int));
        vector->start = vector->mem;
        vector->size = 1;
        vector->occupied = 1;
        vector->end = vector->start;
        *(vector->end) = value;
        return;
    }
    if(vector->occupied == vector->size) {  // Caso ja esteja cheio dobra de tamanho
        
        int* p;
        p = malloc(2*vector->size*sizeof(int));
        if (vector->mem == vector->start) {
            for (int i = 0; i < vector->size; i++) {
                p[i] = vector->mem[i];
            }
            vector->size = vector->size * 2;
            free(vector->mem);
            vector->mem = vector->start = p;
            vector->end = vector->start + vector->occupied;
            insert_last(vector, value);
            return;
        } else {
            int i = 0;
            while(&(vector->start[i]) != &(vector->mem[vector->size])) {
                p[i] = vector->start[i];
                i++;
            }
            p[i] = vector->start[i];
            i++;
            for (int j = 0 ; i < vector->size; i++) {
                p[i] = vector->mem[j];
                j++;
            }
            vector->size = vector->size * 2;
            free(vector->mem);
            vector->mem = vector->start = p;
            vector->end = &(vector->start[vector->occupied]);
            insert_last(vector, value);
            return;
        }

    }
    if(vector->end == &(vector->mem[vector->size])) {  // Quando o ultimo valor esta na ultima posicao do valor
        vector->end = vector->mem;
        *(vector->end) = value;
        vector->occupied++;
        return;
    }
    // Caso generico
    vector->end = vector->start + vector->occupied;
    *(vector->end) = value;
    vector->occupied++;
    return;
}


//As funcoes que executam os comandos em first sao analogas as de cima

void print_first(dynvector* vector) {
    if (vector_empty(vector)) return;
    printf("%d\n", *(vector->start));
}


void remove_first(dynvector* vector) {
    if (vector_empty(vector)) return;
    vector->occupied--;
    if(vector->start == vector->mem + vector->size) {
        vector->start = vector->mem;
    } else {
    vector->start = &(vector->start[1]);
    }
    if (vector->occupied == 0) {
        if (vector->size == 0) return;
        free(vector->mem);
        vector->size = 0;
        vector->start = vector->end = NULL;
        return;
    }
    if (vector->occupied * 4 <= vector->size) {
        int* p;
        p = malloc(vector->size/2 * sizeof(int));
        if (vector->mem == vector->start) {
            for (int i = 0; i < vector->occupied; i++) {
                p[i] = vector->mem[i];
            }
        } else {
            int i = 0;
            while (vector->start + i != vector->mem + vector->size && i < vector->occupied) {
                p[i] = vector->start[i];
                i++;
            }
            p[i] = vector->start[i];
            i++;
            for (int j = 0; i < vector->occupied; i++) {
                p[i] = vector->mem[j];
                j++;
            }
        }
        vector->size = vector->size / 2;
        free(vector->mem);
        vector->mem = vector->start = p;
        vector->end = vector->start + vector->occupied - 1;
    }
}

void insert_first(dynvector* vector, int value) {
    if(vector_empty(vector)) {
        vector->mem = malloc(sizeof(int));
        vector->start = vector->mem;
        vector->size = 1;
        vector->occupied = 1;
        vector->end = vector->start;
        *(vector->start) = value;
        return;
    }
    if(vector->occupied == vector->size) {
        int* p;
        p = malloc(2*vector->size*sizeof(int));
        if (vector->mem == vector->start) {
            for (int i = 0; i < vector->size; i++) {
                p[i] = vector->mem[i];
            }
            vector->size = vector->size * 2;
            free(vector->mem);
            vector->mem = vector->start = p;
            vector->end = vector->start + vector->occupied - 1;
            insert_first(vector, value);
            return;
        } else {
            int i = 0;
            while (vector->start + i != vector->mem + vector->size) {
                p[i] = vector->start[i];
                i++;
            }
            p[i] = vector->start[i];
            i++;
            for (int j = 0 ; i < vector->size; i++) {
                p[i] = vector->mem[j];
                j++;
            }
            vector->size = vector->size * 2;
            free(vector->mem);
            vector->mem = vector->start = p;
            vector->end = vector->start + vector->occupied - 1;
            insert_first(vector, value);
            return;
        }

    }
    if(vector->mem == vector->start) {
        vector->start = &(vector->mem[vector->size]);
        *(vector->start) = value;
        vector->occupied++;
        return;
    }
    vector->occupied++;
    vector->start = vector->start - 1;
    *(vector->start) = value;
    return;
}


void free_vector(dynvector* vector) {
    if (vector->size != 0)  // Caso ainda haja elementos no vetor, libera este
    free(vector->mem); 
    free(vector); // libera a struct
}