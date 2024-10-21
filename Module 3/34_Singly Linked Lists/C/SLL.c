#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure Definition
struct Node {
    int data;
    struct Node* next;
};

// Create Node Function
struct Node* create(int nodeData) {
    // Allocating the memory dynamically for a new node using the `malloc`. The `sizeof(struct Node)` returns the size of memory required for a Node. The result of malloc is typecast to `struct Node*` to make it a node pointer.
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> data = nodeData;
    newNode -> next = NULL;
    return newNode;
}

// Printing Function
void printLinkedList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current -> data);
        current = current -> next;
    }
}

// Iterative Key Search Function
bool searchIterative(struct Node* head, int key) {
    struct Node* current = head;
    while (current != NULL) {
        if (current -> data == key)
            return true;
        current = current -> next;
    }
    return false;
}

// Recursive Key Search Function
bool searchRecursive(struct Node* head, int key) {
    // Base Case
    if (head == NULL)
        return 0;
    
    if (head -> data == key)
        return 1;

    return searchRecursive(head -> next, key);
}

// Inserting a New node at the beginning/front of the Singly Linked List
struct Node* insertFront(struct Node* head, int newNodeData) {
    struct Node* newNode = create(newNodeData);

    newNode -> next = head;

    return newNode;
}

// Inserting a New node after a Given Node of the Singly Linked List
struct Node* insertAfterNode(struct Node* head, int newNodeData, int key) {
    struct Node* current = head;

    while (current != NULL) {
        if (current -> data == key)
            break;
        current = current -> next;
    }

    if (current == NULL)
        return head;

    // Allocating new node
    struct Node* newNode = create(newNodeData);
    newNode -> next = current -> next;
    current -> next = newNode;

    return head;
}

// Inserting a New node at the End of the Singly Linked List
struct Node* insertBack(struct Node* head, int newNodeData) {
    struct Node* newNode = create(newNodeData);

    if (head == NULL) {
        return newNode;
    }

    struct  Node* lastNode = head;

    while (lastNode -> next != NULL) {
        lastNode = lastNode -> next;
    }

    lastNode -> next = newNode;

    return head;
}

// Reversing a Singly Linked List
struct Node* reverseLinkedList(struct Node* head) {
    struct Node *current = head, *previous = NULL, *next;

    while (current != NULL) {
        next = current -> next;

        current -> next = previous;

        previous = current;
        current = next;
    }

    return previous;
}

// Deleting the head node
struct Node* deleteHead(struct Node* head) {
    if (head == NULL) {
        return NULL;
    }

    struct Node* temp = head;

    head = head -> next;

    free(temp);

    return head;
}

// Deleting a Node at a given position
struct Node* deleteNode(struct Node* head, int pos) {
    struct Node* previous;
    struct Node* temp = head;
    
    if (temp == NULL) {
        return head;
    }

    if (pos == 1) {
        head = temp -> next;
        free(temp);
        return head;
    }

    for (int i=1; temp != NULL && i < pos; i++) {
        previous = temp;
        temp = temp -> next;
    }

    if (temp != NULL) {
        previous -> next = temp -> next;
        free(temp);
    }
    else {
        printf("Node is not there in the Singly Linked List.\n");
    }

    return head;
}

// Deleting the Last Node
struct Node* deleteTail(struct Node* head) {
    if (head == NULL) {
        return NULL;
    }

    if (head -> next == NULL) {
        free(head);
        return NULL;
    }

    struct Node* secondLast = head;

    while (secondLast -> next -> next != NULL) {
        secondLast = secondLast -> next;
    }

    free(secondLast -> next);

    secondLast -> next = NULL;

    return head;
}

// Main Function
void main() {
    struct Node* head = create(10);
    head -> next = create(20);
    head -> next -> next = create(30);
    head -> next -> next -> next = create(40);
    head -> next -> next -> next -> next = create(50);
    // 10 -> 20 -> 30 -> 40 -> 50

    printf("\nThe Linked List goes like\n");
    printLinkedList(head);

    printf("\n\nSearch Operation Ahead\n");
    // Key that we are searching in the linked list
    int k = 40;

    if (searchRecursive(head, k))
        printf("%d is there in the Linked List.\n", k);
    else
        printf("%d is not there in the Linked List.\n", k);

    k = 42;

    if (searchIterative(head, k))
        printf("%d is there in the Linked List.\n", k);
    else
        printf("%d is not there in the Linked List.\n", k);

    printf("\nInserting a New Node at the Beginning of the Singly Linked List\n");
    int d = 200;
    head = insertFront(head, d);
    printf("\nThe Linked List goes like this now\n");
    printLinkedList(head);

    printf("\nInserting a New Node after a Given Node of the Singly Linked List\n");
    k = 20;
    d = 150;
    head = insertAfterNode(head, d, k);
    printf("\nThe Linked List goes like this now\n");
    printLinkedList(head);

    printf("\nInserting a New Node at the End of the Singly Linked List\n");
    d = 300;
    head = insertBack(head, d);
    printf("\nThe Linked List goes like this now\n");
    printLinkedList(head);

    printf("\n\nReversing the Singly Linked List\n");
    head = reverseLinkedList(head);
    printf("\nThe Linked List goes like this now\n");
    printLinkedList(head);

    printf("\n\nDeleting the Head Node of the Singly Linked List\n");
    head = deleteHead(head);
    printf("\nThe Linked List goes like this now\n");
    printLinkedList(head);

    printf("\n\nDeleting a Node at a given position of the Singly Linked List\n");
    head = deleteNode(head, 4);
    printf("\nThe Linked List goes like this now\n");
    printLinkedList(head);

    printf("\n\nDeleting the Last Node of the Singly Linked List\n");
    head = deleteTail(head);
    printf("\nThe Linked List goes like this now\n");
    printLinkedList(head);
}