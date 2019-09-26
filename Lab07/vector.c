#include "vector.h"

int vector_empty(dynvector* vector) {
    if(vector->start == NULL) {
        return 1;
    }
    return 0;
}


void print_last(dynvector* vector) {
    printf("%d\n", *(vector->end));
}


void remove_last(dynvector* vector) {
    vector->occupied--;
    vector->end = vector->end - 1;
    if (vector->occupied == 0) {
        free(vector->start);
        vector->size = 0;
        vector->start = vector->end = NULL;
    }
}


void insert_last(dynvector* vector, int value) {
    if(vector_empty(vector)) {
        vector->mem = malloc(sizeof(int));
        vector->start = vector->mem;
        vector->size = 1;
        vector->occupied = 1;
        vector->end = vector->start;
        *(vector->end) = value;
        return;
    }
    if(vector->occupied == vector->size) {
        
        vector->start = realloc(vector->start, 2*vector->size*sizeof(int));

    }
    vector->occupied++;
    vector->end = vector->start + vector->occupied - 1;
    *(vector->end) = value;
    return;
}


void print_first(dynvector* vector) {
    printf("%d\n", *(vector->start));
}


void remove_first(dynvector* vector) {
    vector->occupied--;
    vector->start = vector->start + 1;
    if (vector->occupied == 0) {
        free(vector->start);
        vector->size = 0;
        vector->start = vector->end = NULL;
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

        vector->mem = realloc(vector->mem, 2*vector->size*sizeof(int));

    }
    vector->occupied++;
    vector->start = vector->start - 1;
    *(vector->start) = value;
    return;
}
