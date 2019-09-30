#ifndef VECTORH
#define VECTORH

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct dynvector {
    int size, occupied; // Mantem tamanho e numero de espacos utilizados
    int* start;  // Mantem o endereco que contem o elemento inicial da sequencia
    int* end;  // Mantem o endereco que contem o elemento final da sequencia
    int* mem;  // Mantem o endereco inicial do vetor
} dynvector;

int vector_empty(dynvector*);
void print_last(dynvector*);
void remove_last(dynvector*);
void insert_last(dynvector*, int);
void print_first(dynvector*);
void remove_first(dynvector*);
void insert_first(dynvector*, int);
void free_vector(dynvector*);

#endif
