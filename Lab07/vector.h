#ifndef VECTORH
#define VECTORH

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct dynvector {
    int size, occupied;
    int* start;
    int* end;
    int* mem;
} dynvector;

int vector_empty(dynvector*);
void print_last(dynvector*);
void remove_last(dynvector*);
void insert_last(dynvector*, int);
void print_first(dynvector*);
void remove_first(dynvector*);
void insert_first(dynvector*, int);

#endif
