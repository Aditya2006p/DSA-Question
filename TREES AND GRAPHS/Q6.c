// Write a C program to check if a Binary Search Tree is balanced.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure for a node in the binary search tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the binary search tree
struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}

// Function to find the height of a binary tree
int height(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// Function to check if the tree is balanced
bool isBalanced(struct Node* root) {
    if (root == NULL) {
        return true;
    }

    // Get the height of the left and right subtrees
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    // Check the balance condition for current node
    if (abs(leftHeight - rightHeight) > 1) {
        return false;
    }

    // Recursively check balance for left and right subtrees
    return isBalanced(root->left) && isBalanced(root->right);
}

int main() {
    struct Node* root = NULL;
    int n, value;

    printf("Enter the number of nodes to insert in the BST: ");
    scanf("%d", &n);

    printf("Enter the values to insert:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }

    if (isBalanced(root)) {
        printf("The binary search tree is balanced.\n");
    } else {
        printf("The binary search tree is not balanced.\n");
    }

    return 0;
}