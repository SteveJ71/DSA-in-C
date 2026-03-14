// Creates a linked list of integers from user input

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


typedef struct node {
    int data;
    struct node* next;
} NodeT;

// Display the linked list
void showLL(NodeT* list) {
    if (list == NULL) {
        printf("Done.\n");
        return;
    }
    NodeT* p;
    printf("Done. List is ");
    for (p = list; p != NULL; p = p->next) {
        if (p->next != NULL) {
            printf("%d-->", p->data);
        }
        else {
            printf("%d\n", p->data);
        }
    }
}

// Create a new node with given value
NodeT* makeNode(int v) {
    NodeT* new = malloc(sizeof(NodeT));
    assert(new != NULL);
    new->data = v;       // initialise data
    new->next = NULL;    // initialise link to next node
    return new;          // return pointer to new node
}


// Append a new node with given value to the end of the list
NodeT* joinLL(NodeT* list, int v) {
    NodeT* new = makeNode(v);   // create new list element
    if (list == NULL) {
        return new;
    }
    NodeT* p = list;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = new;
    return list;
}

// Free the memory allocated for the linked list
void freeLL(NodeT* list) {
    NodeT* p, * temp;
    p = list;
    while (p != NULL) {
        temp = p->next;
        free(p);
        p = temp;
    }
}


int main(void) {
    NodeT* myList = NULL;
    char line[256];
    int x;
    printf("Enter an integer: ");
    while (fgets(line, sizeof(line), stdin) && sscanf(line, "%d", &x) == 1) {
        myList = joinLL(myList, x);
        printf("Enter an integer: ");
    }
    showLL(myList);
    freeLL(myList);
	return 0;
}
