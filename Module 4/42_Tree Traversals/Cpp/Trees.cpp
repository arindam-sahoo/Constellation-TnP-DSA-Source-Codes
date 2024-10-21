#include <iostream>
using namespace std;

// Defining a Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Function for creating a New Node
Node* create(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

// Function for inserting a Left Child
Node* insL(Node* parent, int data) {
    parent->left = create(data);
    return parent->left;
}

// Function for inserting a Right Child
Node* insR(Node* parent, int data) {
    parent->right = create(data);
    return parent->right;
}

// Preorder Traversal
void PreorderTraversal(Node* root) {
    if (root == nullptr)
        return;
    cout << root->data << " ";     // root
    PreorderTraversal(root->left); // left
    PreorderTraversal(root->right);// right
}

// Inorder Traversal
void InorderTraversal(Node* root) {
    if (root == nullptr)
        return;
    InorderTraversal(root->left);  // left
    cout << root->data << " ";     // root
    InorderTraversal(root->right); // right
}

// Postorder Traversal
void PostorderTraversal(Node* root) {
    if (root == nullptr)
        return;
    PostorderTraversal(root->left);   // left
    PostorderTraversal(root->right);  // right
    cout << root->data << " ";        // root
}

// Searching the Node
Node* search(Node* root, int v) {
    if (root == nullptr || root->data == v) {
        return root;
    }

    Node* leftRes = search(root->left, v);
    if (leftRes != nullptr)
        return leftRes;

    return search(root->right, v);
}

// Searching the Node in Binary Search Tree
Node* Bsearch(Node* root, int v) {
    if (root == nullptr || root->data == v) {
        return root;
    }
    else if (v < root->data) {
        Node* leftRes = search(root->left, v);
        if (leftRes != nullptr)
            return leftRes;
    }
    return search(root->right, v);
}

int main() {
    Node* root = create(40);
    insL(root, 20);
    insR(root, 60);
    insL(root->left, 10);
    insR(root->left, 30);
    insL(root->right, 50);
    insR(root->right, 70);

    cout << "Traversing the Tree";
    cout << "\nPreorder Traversal : ";
    PreorderTraversal(root);
    cout << "\nInorder Traversal : ";
    InorderTraversal(root);
    cout << "\nPostorder Traversal : ";
    PostorderTraversal(root);

    int value = 50;
    // Node* r = search(root, value);
    Node* r = Bsearch(root, value);
    if (r != nullptr)
        cout << "\nThe node value " << value << " is there in the tree.";
    else
        cout << "\nThe node value " << value << " is not there in the tree.";

    return 0;
}
