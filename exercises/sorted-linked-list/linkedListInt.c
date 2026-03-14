#include <stdio.h>
#include <stdlib.h>
#include "linkedListInt.h"

// Create a new node with given data
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert a new node at the beginning of the list
void insertAtHead(Node** head, int data) {
    Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Insert a new node at the end of the list
void insertAtTail(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    }
    else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Print the elements of the list
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

//// Free the memory allocated for the list
//void freeList(Node** head) {
//    Node* temp;
//    while (*head != NULL) {
//        temp = *head;
//        *head = (*head)->next;
//        free(temp);
//    }
//}
