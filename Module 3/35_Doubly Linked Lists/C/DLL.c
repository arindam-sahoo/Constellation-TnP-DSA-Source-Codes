#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure Definition
struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

// Create Node Function
struct Node* create(int nodeData) {
    // Allocating the memory dynamically for a new node using the `malloc`. The `sizeof(struct Node)` returns the size of memory required for a Node. The result of malloc is typecast to `struct Node*` to make it a node pointer.
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> data = nodeData;
    newNode -> next = NULL;
    newNode -> prev = NULL;
    return newNode;
}

// Forward Traversal (Iterative)
void forwardTraversalIterative(struct Node* head) {
    struct Node* current = head;

    while (current != NULL) {
        printf("%d ", current -> data);
        current = current -> next;
    }
}

// Forward Traversal (Recursive)
void forwardTraversalRecursive(struct Node *head) {
    if (head == NULL)
        return;

    printf("%d ", head -> data);

    forwardTraversalRecursive(head -> next);
}

// Backward Traversal (Iterative)
void backwardTraversalIterative(struct Node* head) {
    struct Node* current = head;

    while (current != NULL) {
        printf("%d ", current -> data);
        current = current -> prev;
    }
}

// Backward Traversal (Recursive)
void backwardTraversalRecursive(struct Node *head) {
    if (head == NULL)
        return;

    printf("%d ", head -> data);

    backwardTraversalRecursive(head -> prev);
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

// Finding out the Length of Doubly Linked List
int lengthDLL(struct Node* head) {
    int c = 0;
    for (struct Node* curr = head; curr != NULL; curr = curr -> next)
        c++;
    return c;
}

// Inserting a New Node at the Beginning
struct Node *insertFront(struct Node *head, int newNodeData) {
    struct Node* newNode = create(newNodeData);

    newNode -> next = head;

    head -> prev = newNode;

    return newNode;
}

// Inserting a New Node at the End
struct Node *insertLast(struct Node *head, int newNodeData) {
    struct Node* newNode = create(newNodeData);

    if (head == NULL) {
        head = newNode;
    }
    else {
        struct Node *curr = head;
        while (curr -> next != NULL) {
            curr = curr -> next;
        }
        curr -> next = newNode;
        newNode -> prev = curr;
    }

    return head;
}

// Inserting after a given node
struct Node* insertAfter(struct Node* head, int newNodeData, int key) {
    struct Node* curr = head;

    while (curr != NULL) {
        if (curr -> data == key)
            break;
        curr = curr -> next;
    }

    if (curr == NULL)
        return head;

    struct Node* newNode = create(newNodeData);

    newNode -> prev = curr;
    newNode -> next = curr -> next;
    curr -> next = newNode;

    if (newNode -> next != NULL) {
        newNode -> next -> prev = newNode;
    }

    return head;
}

// Inserting before a given node
struct Node* insertBefore(struct Node* head, int newNodeData, int key) {
    struct Node* curr = head;

    while (curr != NULL) {
        if (curr -> data == key)
            break;
        curr = curr -> next;
    }

    if (curr == NULL)
        return head;

    struct Node* newNode = create(newNodeData);

    newNode -> prev = curr -> prev;
    newNode -> next = curr;

    if (newNode -> prev != NULL) {
        newNode -> prev -> next = newNode;
    }
    else {
        head = newNode;
    }

    curr -> prev = newNode;

    return head;
}

// Inserting at a given position
struct Node* insertPos(struct Node* head, int newNodeData, int pos) {
    struct Node* newNode = create(newNodeData);
    
    if (pos == 1) {
        newNode -> next = head;

        if (head != NULL) {
            head -> prev = newNode;
        }

        head = newNode;
        return head;
    }

    struct Node *curr = head;

    for(int i = 1; i < pos - 1 && curr != NULL; ++i) {
        curr = curr -> next;
    }

    if (curr == NULL) {
        printf("The position given is out of bounds.");
        free(newNode);
        return head;
    }

    newNode -> prev = curr;
    newNode -> next = curr -> next;
    curr -> next = newNode;

    if (newNode -> next != NULL) {
        newNode -> next -> prev = newNode;
    }

    return head;
}

// Deleting the first node
struct Node* deleteFirst(struct Node* head) {
    if (head == NULL)
        return NULL;

    struct Node *temp = head;

    head = head -> next;

    if (head != NULL)
        head -> prev = NULL;

    free(temp);
    return head;
}

// Deleting the last node
struct Node* deleteLast(struct Node* head) {
    if (head == NULL)
        return NULL;
    
    if (head -> next == NULL) {
        free(head);
        return NULL;
    }

    struct Node *curr = head;

    while(curr -> next != NULL)
        curr = curr -> next;

    curr -> prev -> next = NULL;

    free(curr);

    return head;
}

// Deleting a node at a specific position
struct Node* deletePos(struct Node* head, int pos) {
    if (head == NULL) 
        return head;

    struct Node* curr = head;

    for(int i = 1; curr!= NULL && i < pos; ++i) {
        curr = curr -> next;
    }

    if (curr == NULL) {
        printf("Position is out of range.");
        return head;
    }
        
    if (curr -> prev != NULL)
        curr -> prev -> next = curr -> next;

    if (curr -> next != NULL)
        curr -> next -> prev = curr -> prev; 

    if (head == curr)
        head = curr -> next;

    free(curr);
    return head;
}

// Deleting a node after a specific node
struct Node *deleteAfter(struct Node *head, int key) {
    struct Node* curr = head;

    while (curr != NULL) {
        if (curr -> data == key)
            break;
        curr = curr -> next;
    }

    if (curr == NULL || curr -> next == NULL) {
        return head;
    }

    struct Node *ntDel = curr -> next;

    curr -> next = ntDel -> next;

    if (ntDel -> next != NULL) {
        ntDel -> next -> prev = curr;
    }

    free(ntDel);

    return head;
}

// Deleting a node before a specific node
struct Node *deleteBefore(struct Node *head, int key) {
    struct Node* curr = head;

    while (curr != NULL) {
        if (curr -> data == key)
            break;
        curr = curr -> next;
    }

    if (curr == NULL || curr -> next == NULL) {
        return head;
    }

    struct Node *ntDel = curr -> prev;

    curr -> prev = ntDel -> prev;

    if (ntDel -> prev != NULL) {
        ntDel -> prev -> next = curr;
    }
    else {
        head = curr;
    }

    free(ntDel);

    return head;
}

void main() {
    struct Node* head = create(10);
    struct Node* secondNode = create(20);
    struct Node* thirdNode = create(30);
    struct Node* fourthNode = create(40);
    struct Node* fifthNode = create(50);

    head -> next = secondNode;
    secondNode -> prev = head;
    secondNode -> next = thirdNode;
    thirdNode -> prev = secondNode;
    thirdNode -> next = fourthNode;
    fourthNode -> prev = thirdNode;
    fourthNode -> next = fifthNode;
    fifthNode -> prev = fourthNode;

    printf("\nForward Traversal (Iterative)\n");
    forwardTraversalIterative(head);

    printf("\nForward Traversal (Recursive)\n");
    forwardTraversalRecursive(head);

    printf("\nBackward Traversal (Iterative)\n");
    backwardTraversalIterative(fifthNode);

    printf("\nBackward Traversal (Recursive)\n");
    backwardTraversalRecursive(fifthNode);

    printf("\nSearch Operation Ahead\n");
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

    printf("Length of the Linked List: %d", lengthDLL(head));

    printf("\nInserting a New Node at the Beggining\n");
    head = insertFront(head, 200);
    forwardTraversalIterative(head);

    printf("\nInserting a New Node at the End\n");
    head = insertLast(head, 300);
    forwardTraversalIterative(head);

    printf("\nInserting a New Node after a given Node\n");
    insertAfter(head, 150, 40);
    forwardTraversalIterative(head);

    printf("\nInserting a New Node before a given Node\n");
    insertBefore(head, 160, 30);
    forwardTraversalIterative(head);

    printf("\nInserting a New Node at a given Position\n");
    insertPos(head, 170, 2);
    forwardTraversalIterative(head);

    printf("\nDeleting the First Node at\n");
    head = deleteFirst(head);
    forwardTraversalIterative(head);

    printf("\nDeleting the Last Node at\n");
    head = deleteLast(head);
    forwardTraversalIterative(head);

    printf("\nDeleting a New Node after a given Node\n");
    deleteAfter(head, 40);
    forwardTraversalIterative(head);

    printf("\nDeleting a New Node before a given Node\n");
    deleteBefore(head, 30);
    forwardTraversalIterative(head);

    printf("\nDeleting a New Node at a given Position\n");
    deletePos(head, 2);
    forwardTraversalIterative(head);
}