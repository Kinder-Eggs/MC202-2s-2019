#include "vector.h"
// Gabriel Costa Kinder - 234720
int main() {
    char command[13];
    scanf(" %s", command);
    dynvector* vector = malloc(sizeof(dynvector));
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
        printf("\nOK\n\n");
        
        scanf(" %s", command);
    }
    //free_vector();
}
