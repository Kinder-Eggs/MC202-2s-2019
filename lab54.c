#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int value;
	struct node *next, *previous;
} node;

int main() {
	node* list = malloc(sizeof(node*));
	scanf(" %d", int size);
	generate_list(&list, size)
}

void generate_list(**list, size) {
	node *p, *q = *list;
	for (int i = 0; i < size; i++) {

	}
}