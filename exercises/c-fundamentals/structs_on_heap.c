// Allocating a struct node on the heap with malloc

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


struct node {
	int value;
	struct node* next;
};

int main(void) {
	struct node* n = malloc(sizeof(struct node));
	assert(n != NULL);

	n->value = 42;
	n->next = NULL;

	printf("%d\n", n->value);
	printf("%p\n", n->next);
}
