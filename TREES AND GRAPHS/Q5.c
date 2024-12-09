// Write a C program to find the minimum and maximum values and total number of nodes in a Binary Search Tree.

#include <stdio.h>
#include <stdlib.h>

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

// Function to insert a new node into the binary search tree
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

// Function to find the minimum value in the BST
int findMin(struct Node* root) {
    if (root == NULL) {
        return -1;  // Empty tree, return an error value
    }
    while (root->left != NULL) {
        root = root->left;
    }
    return root->data;
}

// Function to find the maximum value in the BST
int findMax(struct Node* root) {
    if (root == NULL) {
        return -1;  // Empty tree, return an error value
    }
    while (root->right != NULL) {
        root = root->right;
    }
    return root->data;
}

// Function to count the total number of nodes in the BST
int countNodes(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    return countNodes(root->left) + countNodes(root->right) + 1;
}

// Function to print the menu and get user choice
void menu() {
    printf("\nMenu:\n");
    printf("1. Insert a node\n");
    printf("2. Find minimum value\n");
    printf("3. Find maximum value\n");
    printf("4. Count total number of nodes\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    struct Node* root = NULL;  // Initially, the tree is empty
    int choice, value;

    while (1) {
        menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("%d inserted into the binary search tree.\n", value);
                break;

            case 2:
                printf("Minimum value in the BST: %d\n", findMin(root));
                break;

            case 3:
                printf("Maximum value in the BST: %d\n", findMax(root));
                break;

            case 4:
                printf("Total number of nodes in the BST: %d\n", countNodes(root));
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}