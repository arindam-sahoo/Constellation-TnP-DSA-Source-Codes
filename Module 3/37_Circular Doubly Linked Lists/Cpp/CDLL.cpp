#include <iostream>
using namespace std;

// Structure Definition
struct Node {
    int data;
    Node* next;
    Node* prev;
};

// Create Node Function
Node* create(int nodeData) {
    Node* newNode = new Node();
    newNode->data = nodeData;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Printing Function
void printLinkedList(Node* head) {
    if (head == NULL) {
        cout << "The Linked List is Empty" << endl;
        return;
    }
    Node* current = head;
    do {
        cout << current->data << " ";
        current = current->next;
    } while (current != head);
    cout << endl;
}

// Inserting at the Beginning
Node* insertFront(Node* head, int newNodeData) {
    Node* newNode = create(newNodeData);

    if (head == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        return newNode;
    } else {
        Node* last = head->prev;  // Find the last node

        newNode->next = head;
        newNode->prev = last;
        head->prev = newNode;
        last->next = newNode;

        return newNode;
    }
}

// Inserting at a Given Position
Node* insertPos(Node* head, int newNodeData, int pos) {
    Node* newNode = create(newNodeData);

    if (pos == 1) {
        return insertFront(head, newNodeData);
    }

    Node* temp = head;
    for (int i = 1; i < pos - 1 && temp->next != head; i++) {
        temp = temp->next;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;

    return head;
}

// Inserting at the End
Node* insertEnd(Node* head, int newNodeData) {
    Node* newNode = create(newNodeData);

    if (head == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        return newNode;
    } else {
        Node* last = head->prev;

        newNode->next = head;
        newNode->prev = last;
        last->next = newNode;
        head->prev = newNode;

        return head;
    }
}

// Deleting the First Node
Node* deleteFront(Node* head) {
    if (head == NULL) {
        cout << "The Doubly Circular Linked List is Empty" << endl;
        return NULL;
    }

    Node* temp = head;

    if (head->next == head) {
        delete head;
        return NULL;
    }

    Node* last = head->prev;

    head = head->next;
    head->prev = last;
    last->next = head;

    delete temp;
    return head;
}

// Deleting a Node at a Given Position
Node* deletePos(Node* head, int pos) {
    if (head == NULL) {
        cout << "The Doubly Circular Linked List is Empty" << endl;
        return NULL;
    }

    if (pos == 1) {
        return deleteFront(head);
    }

    Node* temp = head;

    for (int i = 1; i < pos && temp->next != head; i++) {
        temp = temp->next;
    }

    if (temp->next == head) {
        cout << "The position is out of bounds" << endl;
        return head;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    delete temp;

    return head;
}

// Deleting the Last Node
Node* deleteEnd(Node* head) {
    if (head == NULL) {
        cout << "The Doubly Circular Linked List is Empty" << endl;
        return NULL;
    }

    Node* last = head->prev;

    if (head->next == head) {
        delete head;
        return NULL;
    }

    last->prev->next = head;
    head->prev = last->prev;

    delete last;

    return head;
}

// Search Operation
bool searchNode(Node* head, int target) {
    if (head == NULL) {
        return false;
    }

    Node* current = head;
    do {
        if (current->data == target) {
            return true;
        }
        current = current->next;
    } while (current != head);

    return false;
}

// Finding Length
int findLength(Node* head) {
    if (head == NULL) return 0;

    int c = 0;
    Node* current = head;

    do {
        c++;
        current = current->next;
    } while (current != head);

    return c;
}

// Reversing the Linked List
Node* reverseList(Node* head) {
    if (head == NULL || head->next == head) {
        return head;
    }

    Node* current = head;
    Node* temp = NULL;

    do {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    } while (current != head);

    head = temp->prev;

    return head;
}

// Updating a Node
Node* updateNode(Node* head, int pos, int val) {
    if (head == NULL) {
        cout << "The Circular Linked List is Empty" << endl;
        return NULL;
    }

    Node* current = head;

    for (int i = 1; i < pos && current->next != head; i++) {
        current = current->next;
    }

    if (current->next == head && pos > findLength(head)) {
        cout << "The position is out of bounds" << endl;
        return head;
    }

    current->data = val;
    return head;
}

// Main Function
int main() {
    Node* head = NULL;

    // Insertion Operations
    head = insertFront(head, 50);
    head = insertFront(head, 40);
    head = insertFront(head, 30);
    head = insertFront(head, 20);
    head = insertFront(head, 10);

    cout << "The Linked List goes like: ";
    printLinkedList(head);

    // Inserting at a Position
    head = insertPos(head, 200, 3);

    cout << "After Inserting at a Position: ";
    printLinkedList(head);

    // Inserting at the End
    head = insertEnd(head, 300);

    cout << "After Inserting at the End: ";
    printLinkedList(head);

    // Deleting the First Node
    head = deleteFront(head);

    cout << "After Deleting the First Node: ";
    printLinkedList(head);

    // Deleting at a Position
    head = deletePos(head, 4);

    cout << "After Deleting at a Position: ";
    printLinkedList(head);

    // Deleting the Last Node
    head = deleteEnd(head);

    cout << "After Deleting the Last Node: ";
    printLinkedList(head);

    // Searching for a Node
    int target = 30;
    if (searchNode(head, target)) {
        cout << target << " is in the Linked List" << endl;
    } else {
        cout << target << " is not in the Linked List" << endl;
    }

    target = 303;
    if (searchNode(head, target)) {
        cout << target << " is in the Linked List" << endl;
    } else {
        cout << target << " is not in the Linked List" << endl;
    }

    // Finding Length
    cout << "Length of the Linked List: " << findLength(head) << endl;

    // Reversing the Linked List
    head = reverseList(head);

    cout << "After Reversing: ";
    printLinkedList(head);

    // Updating a Node
    head = updateNode(head, 3, 250);

    cout << "After Updating: ";
    printLinkedList(head);

    return 0;
}
