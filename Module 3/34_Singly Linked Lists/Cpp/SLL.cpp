#include <iostream>
using namespace std;

// Structure Definition
struct Node {
    int data;
    Node* next;
};

// Create Node Function
Node* create(int nodeData) {
    Node* newNode = new Node();
    newNode->data = nodeData;
    newNode->next = nullptr;
    return newNode;
}

// Printing Function
void printLinkedList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
}

// Iterative Key Search Function
bool searchIterative(Node* head, int key) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == key)
            return true;
        current = current->next;
    }
    return false;
}

// Recursive Key Search Function
bool searchRecursive(Node* head, int key) {
    if (head == nullptr)
        return false;
    if (head->data == key)
        return true;
    return searchRecursive(head->next, key);
}

// Inserting a New node at the beginning/front of the Singly Linked List
Node* insertFront(Node* head, int newNodeData) {
    Node* newNode = create(newNodeData);
    newNode->next = head;
    return newNode;
}

// Inserting a New node after a Given Node of the Singly Linked List
Node* insertAfterNode(Node* head, int newNodeData, int key) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == key)
            break;
        current = current->next;
    }

    if (current == nullptr)
        return head;

    Node* newNode = create(newNodeData);
    newNode->next = current->next;
    current->next = newNode;
    return head;
}

// Inserting a New node at the End of the Singly Linked List
Node* insertBack(Node* head, int newNodeData) {
    Node* newNode = create(newNodeData);
    if (head == nullptr) {
        return newNode;
    }

    Node* lastNode = head;
    while (lastNode->next != nullptr) {
        lastNode = lastNode->next;
    }

    lastNode->next = newNode;
    return head;
}

// Reversing a Singly Linked List
Node* reverseLinkedList(Node* head) {
    Node* current = head, *previous = nullptr, *next;

    while (current != nullptr) {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }

    return previous;
}

// Deleting the head node
Node* deleteHead(Node* head) {
    if (head == nullptr) {
        return nullptr;
    }

    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

// Deleting a Node at a given position
Node* deleteNode(Node* head, int pos) {
    if (head == nullptr) {
        return head;
    }

    if (pos == 1) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node* previous = nullptr;
    Node* temp = head;
    for (int i = 1; temp != nullptr && i < pos; i++) {
        previous = temp;
        temp = temp->next;
    }

    if (temp != nullptr) {
        previous->next = temp->next;
        delete temp;
    } else {
        cout << "Node is not there in the Singly Linked List." << endl;
    }

    return head;
}

// Deleting the Last Node
Node* deleteTail(Node* head) {
    if (head == nullptr) {
        return nullptr;
    }

    if (head->next == nullptr) {
        delete head;
        return nullptr;
    }

    Node* secondLast = head;
    while (secondLast->next->next != nullptr) {
        secondLast = secondLast->next;
    }

    delete secondLast->next;
    secondLast->next = nullptr;
    return head;
}

// Main Function
int main() {
    Node* head = create(10);
    head->next = create(20);
    head->next->next = create(30);
    head->next->next->next = create(40);
    head->next->next->next->next = create(50);
    
    cout << "\nThe Linked List goes like\n";
    printLinkedList(head);

    cout << "\n\nSearch Operation Ahead\n";
    int k = 40;
    if (searchRecursive(head, k))
        cout << k << " is there in the Linked List." << endl;
    else
        cout << k << " is not there in the Linked List." << endl;

    k = 42;
    if (searchIterative(head, k))
        cout << k << " is there in the Linked List." << endl;
    else
        cout << k << " is not there in the Linked List." << endl;

    cout << "\nInserting a New Node at the Beginning\n";
    head = insertFront(head, 200);
    printLinkedList(head);

    cout << "\nInserting a New Node after a Given Node\n";
    head = insertAfterNode(head, 150, 20);
    printLinkedList(head);

    cout << "\nInserting a New Node at the End\n";
    head = insertBack(head, 300);
    printLinkedList(head);

    cout << "\nReversing the Linked List\n";
    head = reverseLinkedList(head);
    printLinkedList(head);

    cout << "\nDeleting the Head Node\n";
    head = deleteHead(head);
    printLinkedList(head);

    cout << "\nDeleting a Node at a Given Position\n";
    head = deleteNode(head, 4);
    printLinkedList(head);

    cout << "\nDeleting the Last Node\n";
    head = deleteTail(head);
    printLinkedList(head);

    return 0;
}
