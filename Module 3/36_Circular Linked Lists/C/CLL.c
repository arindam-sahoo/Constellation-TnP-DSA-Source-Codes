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
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> data = nodeData;
    newNode -> next = NULL;
    return newNode;
}

// Printing Function
void printLinkedList(struct Node* head) {
    struct Node* current = head;
    do {
        printf("%d ", current -> data);
        current = current -> next;
    } while (current != head);
}

// Inserting a New Node at the Beginning of the Linked List
struct Node* insertFront(struct Node* head, int newNodeData) {
    struct Node* newNode = create(newNodeData);

    if (head == NULL) {
        newNode -> next = newNode;
        return newNode;
    }
    else {
        struct Node* temp = head;
        while (temp->next != head) {
            temp = temp -> next;
        }
        newNode -> next = head;
        temp -> next = newNode;
        return head;
    }
}

// Inserting a New Node at a Given Position
struct Node* insertPos(struct Node* head, int newNodeData, int pos) {
    struct Node* newNode = create(newNodeData);

    if (pos == 1) {
        return insertFront(head, newNodeData);
    }

    struct Node* temp = head;
    for (int i=1; i < pos-1 && temp -> next != head; i++) {
        temp = temp -> next;
    }
    
    newNode -> next = temp -> next;
    temp -> next = newNode;
    
    return head;
}

// Inserting a New Node at the End
struct Node* insertEnd(struct Node* head, int newNodeData) {
    struct Node* newNode = create(newNodeData);

    if (head == NULL) {
        newNode -> next = newNode;
        return newNode;
    }
    else {
        struct Node* temp = head;
        while (temp->next != head) {
            temp = temp -> next;
        }
        temp -> next = newNode;
        newNode -> next = head;
        return head;
    }
}

// Deleting a Node from the Beginning
struct Node* deleteFront(struct Node* head) {
    if (head == NULL) {
        printf("The Circular Linked List is Empty\n");
        return NULL;
    }

    struct Node* temp = head;
    // Only 1 Node in the List
    if (temp -> next == head) {
        free(head);
        return NULL;
    }

    while (temp -> next != head) {
        temp = temp -> next;
    }

    // By the end of this while loop, the temp node is the last node.

    temp -> next = head -> next;
    struct Node* newHead = head -> next;
    free(head);
    return newHead;
}

// Deleting a Node from the Given Position
struct Node* deletePos(struct Node* head, int pos) {
    if (head == NULL) {
        printf("The Circular Linked List is Empty\n");
        return NULL;
    }

    if (pos == 1) {
        return deleteFront(head);
    }

    struct Node* temp = head;
    for (int i=1; i<pos-1 && temp -> next != head; i++) {
        temp = temp -> next;
    }

    if (temp-> next == head) {
        printf("The position is out of bounds\n");
        return head;
    }

    struct Node* delNode = temp->next;
    temp -> next = delNode -> next;
    free(delNode);

    return head;
}

// Deleting the Last Ndoe
struct Node* deleteEnd(struct Node* head) {
    if (head == NULL) {
        printf("The Circular Linked List is Empty\n");
        return NULL;
    }

    struct Node* temp = head;
    // Only 1 Node in the List
    if (temp -> next == head) {
        free(head);
        return NULL;
    }

    struct Node* prev = NULL;
    while(temp->next != head) {
        prev = temp;
        temp = temp -> next;
    }

    prev -> next = head;
    free(temp);

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

    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* nextNode = NULL;
    struct Node* tail = head;

    do {
        nextNode = current -> next;
        current -> next = prev;
        prev = current;
        current = nextNode;
    } while (current != head);

    tail->next = prev;
    head = prev;
    
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
    // struct Node* head = create(10);
    // struct Node* node2 = create(20);
    // struct Node* node3 = create(30);
    // struct Node* node4 = create(40);
    // struct Node* last = create(50);

    // // Establishing connections between the Nodes
    // head -> next = node2;
    // node2 -> next = node3;
    // node3 -> next = node4;
    // node4 -> next = last;
    // last -> next = head; // makes it a circular linked list

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
    head = updateNode(head, 3, 20);

    printf("\nAfter Updating a Node, the Linked List goes like\n");
    printLinkedList(head);
}