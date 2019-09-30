#include "vector.h"
// Gabriel Costa Kinder - 234720
int main() {
    char command[13];  // Variavel para verificacao do comando desejado
    scanf(" %s", command);
    dynvector* vector = malloc(sizeof(dynvector));  // Aloca o struct que contera o vetor dinamico
    // Chama as funcoes correspondentes a cada comando ate ser recebido "exit"
    while(strcmp(command, "exit")) {
        if(!strcmp(command, "is-empty")) {
            if(vector_empty(vector)) {
                printf("yes\n");
            } else {
                printf("no\n");
            }
        }else if(!strcmp(command, "print-last")) {
            print_last(vector);
        }else if(!strcmp(command, "remove-last")) {
            remove_last(vector);
        }else if(!strcmp(command, "insert-last")) {
            int value;
            scanf(" %d", &value);
            insert_last(vector, value);
        }else if(!strcmp(command, "print-first")) {
            print_first(vector);
        }else if(!strcmp(command, "remove-first")) {
            remove_first(vector);
        }else if(!strcmp(command, "insert-first")) {
            int value;
            scanf(" %d", &value);
            insert_first(vector, value);
        }
        scanf(" %s", command);
    }
    // Libera toda a memoria
    free_vector(vector);
}
