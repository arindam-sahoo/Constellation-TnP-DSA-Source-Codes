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
    newNode->next = NULL;
    return newNode;
}

// Printing Function
void printLinkedList(Node* head) {
    Node* current = head;
    if (!head) return;
    do {
        cout << current->data << " ";
        current = current->next;
    } while (current != head);
    cout << endl;
}

// Inserting a New Node at the Beginning of the Linked List
Node* insertFront(Node* head, int newNodeData) {
    Node* newNode = create(newNodeData);

    if (head == NULL) {
        newNode->next = newNode;
        return newNode;
    }
    else {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        newNode->next = head;
        temp->next = newNode;
        return head;
    }
}

// Inserting a New Node at a Given Position
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
    temp->next = newNode;

    return head;
}

// Inserting a New Node at the End
Node* insertEnd(Node* head, int newNodeData) {
    Node* newNode = create(newNodeData);

    if (head == NULL) {
        newNode->next = newNode;
        return newNode;
    }
    else {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
        return head;
    }
}

// Deleting a Node from the Beginning
Node* deleteFront(Node* head) {
    if (head == NULL) {
        cout << "The Circular Linked List is Empty\n";
        return NULL;
    }

    Node* temp = head;
    if (temp->next == head) {
        delete head;
        return NULL;
    }

    while (temp->next != head) {
        temp = temp->next;
    }

    temp->next = head->next;
    Node* newHead = head->next;
    delete head;
    return newHead;
}

// Deleting a Node from the Given Position
Node* deletePos(Node* head, int pos) {
    if (head == NULL) {
        cout << "The Circular Linked List is Empty\n";
        return NULL;
    }

    if (pos == 1) {
        return deleteFront(head);
    }

    Node* temp = head;
    for (int i = 1; i < pos - 1 && temp->next != head; i++) {
        temp = temp->next;
    }

    if (temp->next == head) {
        cout << "The position is out of bounds\n";
        return head;
    }

    Node* delNode = temp->next;
    temp->next = delNode->next;
    delete delNode;

    return head;
}

// Deleting the Last Node
Node* deleteEnd(Node* head) {
    if (head == NULL) {
        cout << "The Circular Linked List is Empty\n";
        return NULL;
    }

    Node* temp = head;
    if (temp->next == head) {
        delete head;
        return NULL;
    }

    Node* prev = NULL;
    while (temp->next != head) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = head;
    delete temp;

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

    Node* prev = NULL;
    Node* current = head;
    Node* nextNode = NULL;
    Node* tail = head;

    do {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    } while (current != head);

    tail->next = prev;
    head = prev;

    return head;
}

// Updating
Node* updateNode(Node* head, int pos, int val) {
    if (head == NULL) {
        cout << "The Circular Linked List is Empty\n";
        return NULL;
    }

    Node* current = head;

    for (int i = 1; i < pos && current->next != head; i++) {
        current = current->next;
    }

    if (current->next == head && pos > findLength(head)) {
        cout << "The position is out of bounds\n";
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

    cout << "\nThe Linked List goes like\n";
    printLinkedList(head);

    head = insertPos(head, 200, 3);

    cout << "\nAfter Inserting a New Node at a given position, the Linked List goes like\n";
    printLinkedList(head);

    head = insertEnd(head, 300);

    cout << "\nAfter Inserting a New Node at the End, the Linked List goes like\n";
    printLinkedList(head);

    head = deleteFront(head);

    cout << "\nAfter Deleting the Head Node, the Linked List goes like\n";
    printLinkedList(head);

    head = deletePos(head, 4);

    cout << "\nAfter Deleting a Node from the given position, the Linked List goes like\n";
    printLinkedList(head);

    head = deleteEnd(head);

    cout << "\nAfter Deleting the Last Node, the Linked List goes like\n";
    printLinkedList(head);

    int target = 30;
    if (searchNode(head, target)) {
        cout << "\n" << target << " is there in the Linked List";
    }
    else {
        cout << "\n" << target << " is not there in the Linked List";
    }

    target = 303;
    if (searchNode(head, target)) {
        cout << "\n" << target << " is there in the Linked List";
    }
    else {
        cout << "\n" << target << " is not there in the Linked List";
    }

    cout << "\nThe Length of the Linked List is " << findLength(head);

    head = reverseList(head);

    cout << "\nAfter Reversing, the Linked List goes like\n";
    printLinkedList(head);

    head = updateNode(head, 3, 20);

    cout << "\nAfter Updating a Node, the Linked List goes like\n";
    printLinkedList(head);

    return 0;
}
