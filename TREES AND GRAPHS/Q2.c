// Write a C program to perform Inorder, Preorder and Postorder traversal on a Binary Search Tree.

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the binary search tree
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

// Inorder Traversal (left, root, right)
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);      // Traverse left subtree
        printf("%d ", root->data); // Print root node
        inorder(root->right);     // Traverse right subtree
    }
}

// Preorder Traversal (root, left, right)
void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data); // Print root node
        preorder(root->left);      // Traverse left subtree
        preorder(root->right);     // Traverse right subtree
    }
}

// Postorder Traversal (left, right, root)
void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);     // Traverse left subtree
        postorder(root->right);    // Traverse right subtree
        printf("%d ", root->data); // Print root node
    }
}

// Function to print the menu and get user choice
void menu() {
    printf("\nMenu:\n");
    printf("1. Insert a node\n");
    printf("2. Inorder Traversal\n");
    printf("3. Preorder Traversal\n");
    printf("4. Postorder Traversal\n");
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
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;

            case 3:
                printf("Preorder Traversal: ");
                preorder(root);
                printf("\n");
                break;

            case 4:
                printf("Postorder Traversal: ");
                postorder(root);
                printf("\n");
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}