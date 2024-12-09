// Write a C program to calculate the height of a Binary Search Tree.

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

// Function to calculate the height of the BST
int height(struct Node* root) {
    if (root == NULL) {
        return -1;  // Return -1 for null node to count edges, not nodes
    }

    // Recursively find the height of the left and right subtrees
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    // Return the greater of the two heights plus 1 (to account for the current node)
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// Function to print the menu and get user choice
void menu() {
    printf("\nMenu:\n");
    printf("1. Insert a node\n");
    printf("2. Calculate height of the BST\n");
    printf("3. Exit\n");
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
                printf("Height of the BST: %d\n", height(root));
                break;

            case 3:
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}