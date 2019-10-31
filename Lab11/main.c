#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZEOFTABLE 7213

int insert_hashtable(char* string, int next_id, char** vector);


int main() {
    int next_id = 0;
    char** vector = malloc(SIZEOFTABLE*sizeof(char*[251]));
    while(1){
        char* string = malloc(251*sizeof(char));
        scanf(" %s", string);
        insert_hashtable(string, next_id, vector);
    }
}


unsigned long hash_str(char* string) {
    unsigned long hash = 0;
    int c = *string++;
    int strsize = strlen(string)+1;
    for(int i=1; i<strsize; i++) {
        hash += (c*i*55) % SIZEOFTABLE;
        hash = hash;
        c = *string++;
    }
    printf("%lu", hash%SIZEOFTABLE);
    return hash % SIZEOFTABLE;
}


int insert_hashtable(char* string, int next_id, char** vector) {
    unsigned long hash = hash_str(string);
    char* aux1 = vector[hash];
    //strcpy(string, aux1);
    //printf("%s\n", vector[hash]);
}
