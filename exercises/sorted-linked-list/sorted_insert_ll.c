#include <stdio.h>
#include "linkedListInt.h"

void sortedInsert(Node** headRef, Node* newNode) {

    // Initialise current, previous and next pointers
    Node* current = *headRef;

    // Special Cases
    // insert new at the start of the LL
    if (*headRef == NULL || (*headRef)->data >= newNode->data) {
        newNode->next = *headRef;
        *headRef = newNode;
        return;
    }

    // Iterate through LL and insert in order
    // Locate the node before the point of insertion
    while (current->next != NULL && current->next->data < newNode->data) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;


}

int main(void) {
    Node* head = NULL;

    // Creating a linked list with 5 integers
    insertAtHead(&head, 6);
    insertAtHead(&head, 5);
    insertAtHead(&head, 4);
    insertAtHead(&head, 2);
    insertAtHead(&head, 1);

    printf("Original Linked List: ");
    printList(head);

    // Create a new node to insert
    Node* newNode = createNode(3);

    // Insert the new node into the sorted list
    sortedInsert(&head, newNode);

    printf("Linked List after insertion: ");
    printList(head);

    freeList(&head);
    return 0;
}
