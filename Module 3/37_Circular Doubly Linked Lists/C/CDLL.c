#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure Definition
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Create Node Function
struct Node* create(int nodeData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = nodeData;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Printing Function
void printLinkedList(struct Node* head) {
    if (head == NULL) {
        printf("The Linked List is Empty\n");
        return;
    }
    struct Node* current = head;
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);
}

// Inserting a New Node at the Beginning of the Doubly Circular Linked List
struct Node* insertFront(struct Node* head, int newNodeData) {
    struct Node* newNode = create(newNodeData);

    if (head == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        return newNode;
    } else {
        struct Node* last = head->prev;  // Find the last node

        newNode->next = head;
        newNode->prev = last;
        head->prev = newNode;
        last->next = newNode;

        return newNode;
    }
}

// Inserting a New Node at a Given Position
struct Node* insertPos(struct Node* head, int newNodeData, int pos) {
    struct Node* newNode = create(newNodeData);

    if (pos == 1) {
        return insertFront(head, newNodeData);
    }

    struct Node* temp = head;
    for (int i = 1; i < pos - 1 && temp->next != head; i++) {
        temp = temp->next;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;

    return head;
}

// Inserting a New Node at the End
struct Node* insertEnd(struct Node* head, int newNodeData) {
    struct Node* newNode = create(newNodeData);

    if (head == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        return newNode;
    } else {
        struct Node* last = head->prev;

        newNode->next = head;
        newNode->prev = last;
        last->next = newNode;
        head->prev = newNode;

        return head;
    }
}

// Deleting a Node from the Beginning
struct Node* deleteFront(struct Node* head) {
    if (head == NULL) {
        printf("The Doubly Circular Linked List is Empty\n");
        return NULL;
    }

    struct Node* temp = head;

    if (head->next == head) {  // Only one node in the list
        free(head);
        return NULL;
    }

    struct Node* last = head->prev;

    head = head->next;
    head->prev = last;
    last->next = head;

    free(temp);
    return head;
}

// Deleting a Node from the Given Position
struct Node* deletePos(struct Node* head, int pos) {
    if (head == NULL) {
        printf("The Doubly Circular Linked List is Empty\n");
        return NULL;
    }

    if (pos == 1) {
        return deleteFront(head);
    }

    struct Node* temp = head;

    for (int i = 1; i < pos && temp->next != head; i++) {
        temp = temp->next;
    }

    if (temp->next == head) {
        printf("The position is out of bounds\n");
        return head;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    free(temp);

    return head;
}

// Deleting the Last Node
struct Node* deleteEnd(struct Node* head) {
    if (head == NULL) {
        printf("The Doubly Circular Linked List is Empty\n");
        return NULL;
    }

    struct Node* last = head->prev;

    if (head->next == head) {  // Only one node in the list
        free(head);
        return NULL;
    }

    last -> prev -> next = head;
    head -> prev = last -> prev;

    free(last);

    return head;
}

// Search Operation
bool searchNode(struct Node* head, int target) {
    if (head == NULL) {
        return false;
    }

    struct Node* current = head;
    do {
        if(current -> data == target) {
            return true;
        }
        current = current -> next;
    } while (current != head);

    return false;
}

// Finding Length
int findLength(struct Node* head) {
    if (head == NULL) return 0;

    int c = 0;
    struct Node* current = head;

    do {
        c++;
        current = current -> next;
    } while (current != head);

    return c;
}

// Reversing the Linked List
struct Node* reverseList(struct Node* head) {
    if (head == NULL || head->next == head) {
        return head;
    }

    struct Node* current = head;
    struct Node* temp = NULL;

    do {
        temp = current -> prev;
        current -> prev = current -> next;
        current -> next = temp;
        current = current -> prev;
    } while (current != head);

    head = temp -> prev;
    
    return head;
}

// Updating
struct Node* updateNode(struct Node* head, int pos, int val) {
    if (head == NULL) {
        printf("The Circular Linked List is Empty\n");
        return NULL;
    }

    struct Node* current = head;

    for(int i=1; i<pos && current->next != head; i++) {
        current = current -> next;
    }

    if (current->next == head && pos > findLength(head)) {
        printf("The position is out of bounds\n");
        return head;
    }

    current -> data = val;
    return head;
}

// Main Function
void main() {
    struct Node* head = NULL;

    // Insertion Operations
    // Beginning
    head = insertFront(head, 50);
    head = insertFront(head, 40);
    head = insertFront(head, 30);
    head = insertFront(head, 20);
    head = insertFront(head, 10);

    printf("\nThe Linked List goes like\n");
    printLinkedList(head);

    // Given Position
    head = insertPos(head, 200, 3);

    printf("\nAfter Inserting a New Node at a given position, the Linked List goes like\n");
    printLinkedList(head);

    // End
    head = insertEnd(head, 300);

    printf("\nAfter Inserting a New Node at the End, the Linked List goes like\n");
    printLinkedList(head);

    // Deletion Operations
    // Beginning
    head = deleteFront(head);

    printf("\nAfter Deleting the Head Node, the Linked List goes like\n");
    printLinkedList(head);

    // Given Position
    head = deletePos(head, 4);

    printf("\nAfter Deleting a Node from the given position, the Linked List goes like\n");
    printLinkedList(head);

    // End
    head = deleteEnd(head);

    printf("\nAfter Deleting the Last Node, the Linked List goes like\n");
    printLinkedList(head);

    // Searching Operation
    int target = 30;
    if(searchNode(head, target)) {
        printf("\n%d is there in the Linked List", target);
    }
    else {
        printf("\n%d is not there in the Linked List", target);
    }
    target = 303;
    if(searchNode(head, target)) {
        printf("\n%d is there in the Linked List", target);
    }
    else {
        printf("\n%d is not there in the Linked List", target);
    }

    // Finding Length
    printf("\nThe Length of the Linked List is %d", findLength(head));

    // Reversing the Linked List
    head = reverseList(head);

    printf("\nAfter Reversing, the Linked List goes like\n");
    printLinkedList(head);

    // Update a Node Data
    head = updateNode(head, 3, 250);

    printf("\nAfter Updating a Node, the Linked List goes like\n");
    printLinkedList(head);
}
