#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define SIZEOFTABLE 6857  // Tamanho que sera utilizada na hashtable (o valor for adotado por ser primo e > 5000*1,3)

int insert_hashtable(char* string, int next_id, char** vector, int ids[SIZEOFTABLE]);
unsigned long search_hashtable(char* string, char** vector);
void remove_hashtable(char* string, char** vector, int ids[SIZEOFTABLE]);
void free_hashtable(char** vector, int ids[SIZEOFTABLE]);


#endif
