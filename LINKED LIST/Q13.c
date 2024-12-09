// Write a C program to search for an element in a Circular linked list and then delete that element from the list.

#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the circular linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newNode->data = value;
    newNode->next = newNode; // Pointing to itself to make it circular initially
    return newNode;
}

// Function to insert a node at the end of the circular linked list
void insertAtEnd(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
    }
}

// Function to search for a node with a given value
struct Node* searchNode(struct Node* head, int value) {
    if (head == NULL) {
        return NULL;
    }

    struct Node* temp = head;
    do {
        if (temp->data == value) {
            return temp;
        }
        temp = temp->next;
    } while (temp != head);

    return NULL; // Element not found
}

// Function to delete a node from the circular linked list
void deleteNode(struct Node** head, int value) {
    if (*head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* temp = *head;
    struct Node* prev = NULL;

    // If the node to delete is the head node
    if (temp->data == value) {
        if (temp->next == *head) { // Only one node in the list
            free(temp);
            *head = NULL;
        } else {
            // Find the last node to update its next pointer
            while (temp->next != *head) {
                temp = temp->next;
            }
            temp->next = (*head)->next;
            free(*head);
            *head = temp->next;
        }
        printf("Node with value %d deleted successfully.\n", value);
        return;
    }

    // Search for the node to delete
    prev = temp;
    temp = temp->next;
    while (temp != *head) {
        if (temp->data == value) {
            prev->next = temp->next;
            free(temp);
            printf("Node with value %d deleted successfully.\n", value);
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    printf("Node with value %d not found.\n", value); // Element not found
}

// Function to display the circular linked list
void displayCircularList(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* temp = head;
    printf("Circular Linked List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head); // Continue until we reach the head again
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int value, choice;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at End\n");
        printf("2. Search and Delete\n");
        printf("3. Display List\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertAtEnd(&head, value);
                break;

            case 2:
                printf("Enter value to search and delete: ");
                scanf("%d", &value);
                struct Node* result = searchNode(head, value);
                if (result != NULL) {
                    deleteNode(&head, value);
                } else {
                    printf("Element not found in the list.\n");
                }
                break;

            case 3:
                displayCircularList(head);
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}