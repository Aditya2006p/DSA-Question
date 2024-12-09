// Write a C program to create Binary search tree and perform following operations on it. 1) Insert node ii) Delete node iii) Search node.

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
    // If the tree is empty, create a new node
    if (root == NULL) {
        return createNode(value);
    }

    // If the value is smaller than the current node, insert it into the left subtree
    if (value < root->data) {
        root->left = insert(root->left, value);
    }
    // If the value is larger than the current node, insert it into the right subtree
    else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    // Return the (unchanged) node pointer
    return root;
}

// Function to search for a value in the binary search tree
struct Node* search(struct Node* root, int value) {
    // If the tree is empty or the value is found at the root
    if (root == NULL || root->data == value) {
        return root;
    }

    // Otherwise, check the left or right subtree
    if (value < root->data) {
        return search(root->left, value);
    }
    return search(root->right, value);
}

// Function to find the minimum value node in the binary search tree
struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;

    // Traverse to the leftmost node (minimum value)
    while (current && current->left != NULL) {
        current = current->left;
    }

    return current;
}

// Function to delete a node from the binary search tree
struct Node* deleteNode(struct Node* root, int value) {
    // Base case: If the tree is empty
    if (root == NULL) {
        return root;
    }

    // If the value to be deleted is smaller than the root's data, it lies in the left subtree
    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    }
    // If the value to be deleted is larger than the root's data, it lies in the right subtree
    else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    }
    // If the value is the same as the root's data, then this is the node to be deleted
    else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        struct Node* temp = minValueNode(root->right);

        // Copy the inorder successor's content to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

// Function for inorder traversal of the binary search tree
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Function to print the menu and get user choice
void menu() {
    printf("\nMenu:\n");
    printf("1. Insert a node\n");
    printf("2. Search for a node\n");
    printf("3. Delete a node\n");
    printf("4. Inorder Traversal\n");
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
                printf("Enter the value to search: ");
                scanf("%d", &value);
                if (search(root, value) != NULL) {
                    printf("%d found in the binary search tree.\n", value);
                } else {
                    printf("%d not found in the binary search tree.\n", value);
                }
                break;

            case 3:
                printf("Enter the value to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                printf("%d deleted from the binary search tree.\n", value);
                break;

            case 4:
                printf("Inorder Traversal of the binary search tree: ");
                inorder(root);
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