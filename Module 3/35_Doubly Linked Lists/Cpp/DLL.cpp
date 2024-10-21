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

// Forward Traversal (Iterative)
void forwardTraversalIterative(Node* head) {
    Node* current = head;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
}

// Forward Traversal (Recursive)
void forwardTraversalRecursive(Node *head) {
    if (head == NULL)
        return;

    cout << head->data << " ";
    forwardTraversalRecursive(head->next);
}

// Backward Traversal (Iterative)
void backwardTraversalIterative(Node* head) {
    Node* current = head;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->prev;
    }
}

// Backward Traversal (Recursive)
void backwardTraversalRecursive(Node *head) {
    if (head == NULL)
        return;

    cout << head->data << " ";
    backwardTraversalRecursive(head->prev);
}

// Iterative Key Search Function
bool searchIterative(Node* head, int key) {
    Node* current = head;
    while (current != NULL) {
        if (current->data == key)
            return true;
        current = current->next;
    }
    return false;
}

// Recursive Key Search Function
bool searchRecursive(Node* head, int key) {
    if (head == NULL)
        return false;
    
    if (head->data == key)
        return true;

    return searchRecursive(head->next, key);
}

// Finding out the Length of Doubly Linked List
int lengthDLL(Node* head) {
    int c = 0;
    for (Node* curr = head; curr != NULL; curr = curr->next)
        c++;
    return c;
}

// Inserting a New Node at the Beginning
Node* insertFront(Node* head, int newNodeData) {
    Node* newNode = create(newNodeData);

    newNode->next = head;
    if (head != NULL)
        head->prev = newNode;

    return newNode;
}

// Inserting a New Node at the End
Node* insertLast(Node* head, int newNodeData) {
    Node* newNode = create(newNodeData);

    if (head == NULL) {
        head = newNode;
    } else {
        Node *curr = head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = newNode;
        newNode->prev = curr;
    }

    return head;
}

// Inserting after a given node
Node* insertAfter(Node* head, int newNodeData, int key) {
    Node* curr = head;
    while (curr != NULL) {
        if (curr->data == key)
            break;
        curr = curr->next;
    }

    if (curr == NULL)
        return head;

    Node* newNode = create(newNodeData);

    newNode->prev = curr;
    newNode->next = curr->next;
    curr->next = newNode;

    if (newNode->next != NULL) {
        newNode->next->prev = newNode;
    }

    return head;
}

// Inserting before a given node
Node* insertBefore(Node* head, int newNodeData, int key) {
    Node* curr = head;
    while (curr != NULL) {
        if (curr->data == key)
            break;
        curr = curr->next;
    }

    if (curr == NULL)
        return head;

    Node* newNode = create(newNodeData);

    newNode->prev = curr->prev;
    newNode->next = curr;

    if (newNode->prev != NULL) {
        newNode->prev->next = newNode;
    } else {
        head = newNode;
    }

    curr->prev = newNode;

    return head;
}

// Inserting at a given position
Node* insertPos(Node* head, int newNodeData, int pos) {
    Node* newNode = create(newNodeData);
    
    if (pos == 1) {
        newNode->next = head;
        if (head != NULL) {
            head->prev = newNode;
        }
        head = newNode;
        return head;
    }

    Node *curr = head;
    for(int i = 1; i < pos - 1 && curr != NULL; ++i) {
        curr = curr->next;
    }

    if (curr == NULL) {
        cout << "The position given is out of bounds.";
        delete newNode;
        return head;
    }

    newNode->prev = curr;
    newNode->next = curr->next;
    curr->next = newNode;

    if (newNode->next != NULL) {
        newNode->next->prev = newNode;
    }

    return head;
}

// Deleting the first node
Node* deleteFirst(Node* head) {
    if (head == NULL)
        return NULL;

    Node* temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;

    delete temp;
    return head;
}

// Deleting the last node
Node* deleteLast(Node* head) {
    if (head == NULL)
        return NULL;
    
    if (head->next == NULL) {
        delete head;
        return NULL;
    }

    Node *curr = head;
    while(curr->next != NULL)
        curr = curr->next;

    curr->prev->next = NULL;

    delete curr;

    return head;
}

// Deleting a node at a specific position
Node* deletePos(Node* head, int pos) {
    if (head == NULL) 
        return head;

    Node* curr = head;
    for(int i = 1; curr != NULL && i < pos; ++i) {
        curr = curr->next;
    }

    if (curr == NULL) {
        cout << "Position is out of range.";
        return head;
    }
        
    if (curr->prev != NULL)
        curr->prev->next = curr->next;

    if (curr->next != NULL)
        curr->next->prev = curr->prev; 

    if (head == curr)
        head = curr->next;

    delete curr;
    return head;
}

// Deleting a node after a specific node
Node* deleteAfter(Node* head, int key) {
    Node* curr = head;
    while (curr != NULL) {
        if (curr->data == key)
            break;
        curr = curr->next;
    }

    if (curr == NULL || curr->next == NULL) {
        return head;
    }

    Node* ntDel = curr->next;
    curr->next = ntDel->next;

    if (ntDel->next != NULL) {
        ntDel->next->prev = curr;
    }

    delete ntDel;

    return head;
}

// Deleting a node before a specific node
Node* deleteBefore(Node* head, int key) {
    Node* curr = head;
    while (curr != NULL) {
        if (curr->data == key)
            break;
        curr = curr->next;
    }

    if (curr == NULL || curr->next == NULL) {
        return head;
    }

    Node* ntDel = curr->prev;

    curr->prev = ntDel->prev;
    if (ntDel->prev != NULL) {
        ntDel->prev->next = curr;
    } else {
        head = curr;
    }

    delete ntDel;

    return head;
}

int main() {
    Node* head = create(10);
    Node* secondNode = create(20);
    Node* thirdNode = create(30);
    Node* fourthNode = create(40);
    Node* fifthNode = create(50);

    head->next = secondNode;
    secondNode->prev = head;
    secondNode->next = thirdNode;
    thirdNode->prev = secondNode;
    thirdNode->next = fourthNode;
    fourthNode->prev = thirdNode;
    fourthNode->next = fifthNode;
    fifthNode->prev = fourthNode;

    cout << "\nForward Traversal (Iterative)\n";
    forwardTraversalIterative(head);

    cout << "\nForward Traversal (Recursive)\n";
    forwardTraversalRecursive(head);

    cout << "\nBackward Traversal (Iterative)\n";
    backwardTraversalIterative(fifthNode);

    cout << "\nBackward Traversal (Recursive)\n";
    backwardTraversalRecursive(fifthNode);

    cout << "\nSearch Operation Ahead\n";
    int k = 40;

    if (searchRecursive(head, k))
        cout << k << " is there in the Linked List.\n";
    else
        cout << k << " is not there in the Linked List.\n";

    k = 42;

    if (searchIterative(head, k))
        cout << k << " is there in the Linked List.\n";
    else
        cout << k << " is not there in the Linked List.\n";

    cout << "Length of the Linked List: " << lengthDLL(head);

    cout << "\nInserting a New Node at the Beginning\n";
    head = insertFront(head, 200);
    forwardTraversalIterative(head);

    cout << "\nInserting a New Node at the End\n";
    head = insertLast(head, 300);
    forwardTraversalIterative(head);

    cout << "\nInserting a New Node after a given Node\n";
    insertAfter(head, 150, 40);
    forwardTraversalIterative(head);

    cout << "\nInserting a New Node before a given Node\n";
    insertBefore(head, 160, 30);
    forwardTraversalIterative(head);

    cout << "\nInserting a New Node at a given Position\n";
    insertPos(head, 170, 2);
    forwardTraversalIterative(head);

    cout << "\nDeleting the First Node\n";
    head = deleteFirst(head);
    forwardTraversalIterative(head);

    cout << "\nDeleting the Last Node\n";
    head = deleteLast(head);
    forwardTraversalIterative(head);

    cout << "\nDeleting a New Node after a given Node\n";
    deleteAfter(head, 40);
    forwardTraversalIterative(head);

    cout << "\nDeleting a New Node before a given Node\n";
    deleteBefore(head, 30);
    forwardTraversalIterative(head);

    cout << "\nDeleting a New Node at a given Position\n";
    deletePos(head, 2);
    forwardTraversalIterative(head);

    return 0;
}
