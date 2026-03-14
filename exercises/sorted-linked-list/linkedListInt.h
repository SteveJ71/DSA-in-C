#ifndef LINKEDLISTINT_H
#define LINKEDLISTINT_H

typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function prototypes
Node* createNode(int data);
void insertAtHead(Node** head, int data);
void insertAtTail(Node** head, int data);
void printList(Node* head);
//void freeList(Node** head);

#endif // LINKEDLISTINT_H
