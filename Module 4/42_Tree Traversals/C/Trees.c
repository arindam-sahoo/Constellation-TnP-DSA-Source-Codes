#include <stdio.h>
#include <stdlib.h>

// Defining a Tree Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function for creating a New Node
struct Node* create(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> data = data;
    newNode -> left = NULL;
    newNode -> right = NULL;
    return newNode;
}

// Function for inserting a Left Child
struct Node* insL(struct Node* parent, int data) {
    parent -> left = create(data);
    return parent -> left;
}

// Function for inserting a Left Child
struct Node* insR(struct Node* parent, int data) {
    parent -> right = create(data);
    return parent -> right;
}

// Preorder
void PreorderTraversal(struct Node* root) {
    if (root == NULL)
        return;
    printf("%d ", root -> data);        // root
    PreorderTraversal(root -> left);    // left
    PreorderTraversal(root -> right);   // right
}

// Inorder
void InorderTraversal(struct Node* root) {
    if (root == NULL)
        return;
    InorderTraversal(root -> left);     // left
    printf("%d ", root -> data);        // root
    InorderTraversal(root -> right);    // right
}

// Postorder
void PostorderTraversal(struct Node* root) {
    if (root == NULL)
        return;
    PostorderTraversal(root -> left);   // left
    PostorderTraversal(root -> right);  // right
    printf("%d ", root -> data);        // root
}

// Searching the Node
struct Node* search(struct Node* root, int v) {
    if (root == NULL || root -> data == v) {
        return root;
    }

    struct Node* leftRes = search(root->left, v);
    if (leftRes != NULL)
        return leftRes;

    return search(root->right, v);
}

// Searching the Node in Binary Search Tree
struct Node* Bsearch(struct Node* root, int v) {
    if (root == NULL || root -> data == v) {
        return root;
    }
    else if (v < root->data) {
        struct Node* leftRes = search(root->left, v); 
        if (leftRes != NULL)
            return leftRes;
    }
    return search(root->right, v);
}

void main() {
    struct Node* root = create(40);
    insL(root, 20);
    insR(root, 60);
    insL(root -> left, 10);
    insR(root -> left, 30);
    insL(root -> right, 50);
    insR(root -> right, 70);

    printf("Traversing the Tree");
    printf("\nPreorder Traversal : ");
    PreorderTraversal(root);
    printf("\nInorder Traversal : ");
    InorderTraversal(root);
    printf("\nPostorder Traversal : ");
    PostorderTraversal(root);

    int value = 50;
    // struct Node* r = search(root, value);
    struct Node* r = Bsearch(root, value);
    if (r != NULL)
        printf("\nThe node value %d is there in the tree.", value);
    else
        printf("\nThe node value %d is not there in the tree.", value);
}