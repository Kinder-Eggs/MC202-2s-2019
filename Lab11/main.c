#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define SIZEOFTABLE 7213

int insert_hashtable(char* string, int next_id, char** vector, int ids[SIZEOFTABLE]);


int main() {
	int next_id = 0;
	int ids[SIZEOFTABLE];
	char** vector = malloc(SIZEOFTABLE*sizeof(char*));
	while(1){
		char* string = malloc(251*sizeof(char));
		scanf(" %s", string);
		next_id = insert_hashtable(string, next_id, vector, ids);
		free(string);
	}
}


unsigned long hash_str(char* string) {
	unsigned long hash = 0;
	int strsize = strlen(string);
	for(int i=0; i < strsize; i++) {
		hash += (string[i]*((long)pow(i+1,i+1))*55);
	}
	return hash;
}


unsigned long double_hash(char* string) {
	return 1 + (hash_str(string)%SIZEOFTABLE-2);
}


int insert_hashtable(char* string, int next_id, char** vector, int ids[SIZEOFTABLE]) {
	unsigned long hash = hash_str(string)%SIZEOFTABLE;
	while(vector[hash]) {
		hash += double_hash(string);
		hash = hash%SIZEOFTABLE;
	}
	printf("%lu\n", hash);
	if(!vector[hash]){
		vector[hash] = malloc(251*sizeof(char));
		strcpy(vector[hash], string);
		ids[hash] = next_id;
		printf("%s, %d\n", vector[hash], next_id);
		next_id++;
		return next_id;
	}
}


